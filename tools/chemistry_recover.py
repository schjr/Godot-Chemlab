#!/usr/bin/env python3
"""Evidence-preserving ChemLab data recovery, not original application source.

The reaction layout is supplied by res/allfcs说明.txt. Reagent positions are
inferred from repeated records; named guesses live in `inferred`, never `fields`.
No simulation, reaction selection, equilibrium, or model geometry is invented.
"""
from __future__ import annotations
import argparse
from collections import Counter
from decimal import Decimal
import hashlib
from html.parser import HTMLParser
import json
from pathlib import Path
import re
import shutil
import struct

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_SOURCE = ROOT / 'artifacts/ChemLab'
DEFAULT_OUTPUT = ROOT / 'recovered/chemistry'


def decode(path: Path) -> tuple[bytes, str, str]:
    data = path.read_bytes()
    # Do not guess UTF-8 for legacy files that happen to contain ASCII prefixes.
    if path.name == 'allfcs说明.txt':
        encoding = 'utf-8'
    else:
        encoding = 'gb18030'
    text = data.decode(encoding, errors='strict')
    if text.encode(encoding) != data:
        raise ValueError(f'Non-lossless decoding: {path}')
    return data, text, encoding


def provenance(path: Path, data: bytes, encoding: str | None = None) -> dict:
    return {'source': str(path.relative_to(ROOT)) if path.is_relative_to(ROOT) else str(path),
            'byte_count': len(data), 'sha256': hashlib.sha256(data).hexdigest(),
            'encoding': encoding}


def read_library(path: Path) -> dict:
    """Return exact text fragments plus line-numbered, unmodified record lines."""
    data, text, encoding = decode(path)
    separators = list(re.finditer(r'^</(?:next|over)>\r?$', text, re.MULTILINE))
    nexts = [m for m in separators if m.group().rstrip('\r') == '</next>']
    overs = [m for m in separators if m.group().rstrip('\r') == '</over>']
    if len(overs) != 1 or not nexts or overs[0].start() <= nexts[-1].start():
        raise ValueError(f'Invalid library delimiters: {path}')
    records = []
    for index, start in enumerate(nexts):
        end = nexts[index + 1].start() if index + 1 < len(nexts) else overs[0].start()
        raw = text[start.end():end]
        # The delimiter itself excludes LF, so consume precisely that one LF.
        if not raw.startswith('\n'):
            raise ValueError('Expected newline after delimiter')
        body = raw[1:]
        line_number = text.count('\n', 0, start.end()) + 2
        records.append({'index': index, 'source_line': line_number,
                        'raw_text': body, 'lines': body.splitlines()})
    return {'provenance': provenance(path, data, encoding), 'text': text,
            'preamble': text[:nexts[0].start()], 'records': records}


def read_reactions(path: Path) -> dict:
    library = read_library(path)
    for record in library['records']:
        lines = record['lines']
        r, p = int(lines[1]), int(lines[2])
        if r < 0 or p < 0:
            raise ValueError('Negative species count')
        n = r + p
        if len(lines) < 9 + 2 * n:
            raise ValueError('Short reaction record')
        species = lines[3:3+n]
        coefficients = lines[3+n:3+2*n]
        for value in coefficients:
            Decimal(value)  # Validate without losing original decimal spelling.
        tail = lines[3+2*n:]
        record['fields'] = {'id': lines[0], 'reactant_count': r, 'product_count': p,
            'reactants': [{'species': a, 'coefficient': b} for a, b in zip(species[:r], coefficients[:r])],
            'products': [{'species': a, 'coefficient': b} for a, b in zip(species[r:], coefficients[r:])],
            'reaction_heat': tail[0], 'condition': tail[1], 'reaction_rate': tail[2],
            'equilibrium_degree_or_constant': tail[3], 'equilibrium_mode': tail[4],
            'equation_type': tail[5], 'optional_note_lines': tail[6:]}
        record['schema_evidence'] = 'artifacts/ChemLab/res/allfcs说明.txt'
    return library


def read_reagents(path: Path) -> dict:
    library = read_library(path)
    for record in library['records']:
        lines = record['lines']
        if len(lines) != 12:
            raise ValueError(f'Reagent {record["index"]}: expected 12 lines, got {len(lines)}')
        record['positional_fields'] = {str(i+1): value for i, value in enumerate(lines)}
        record['inferred'] = {'library_key': lines[0], 'species_name': lines[1],
            'molar_mass': lines[2], 'charge_or_valence': lines[3],
            'category_a': lines[4], 'category_b': lines[5], 'color_integer': lines[6],
            'density_or_solid_render_parameter': lines[7],
            'unknown_constant_100': lines[8], 'unknown_constant_1000': lines[9],
            'solubility_temperature_expression': lines[10], 'solubility_at_20_C': lines[11]}
        record['schema_evidence'] = ('Positional names inferred from data patterns; help/yp_edit.htm '
                                    'documents the editor properties but does not give serialized order.')
    return library


class PlainHTML(HTMLParser):
    def __init__(self):
        super().__init__(convert_charrefs=True)
        self.parts = []
    def handle_data(self, data):
        self.parts.append(data)
    def handle_starttag(self, tag, attrs):
        if tag in {'p', 'br', 'h1', 'h2', 'h3', 'tr', 'li'}:
            self.parts.append('\n')
    def handle_endtag(self, tag):
        if tag in {'p', 'h1', 'h2', 'h3', 'tr', 'li'}:
            self.parts.append('\n')


def write_json(path: Path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')


def export_text(path: Path, source: Path, output: Path, manifest: list) -> tuple[str, Path]:
    data, text, encoding = decode(path)
    rel = path.relative_to(source)
    original = output / 'original' / rel
    original.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(path, original)
    target = output / 'utf8' / rel
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_bytes(text.encode('utf-8'))  # Keep CRLF and every blank line.
    manifest.append(provenance(path, data, encoding) | {'original_copy': str(original.relative_to(output)),
                                                    'utf8_export': str(target.relative_to(output))})
    return text, target


def recover(source: Path, output: Path) -> dict:
    output.mkdir(parents=True, exist_ok=True)
    manifest = []
    reactions = read_reactions(source / 'res/allfcs.txt')
    reagents = read_reagents(source / 'res/allyp.txt')
    write_json(output / 'reactions.json', reactions)
    write_json(output / 'reagents.json', reagents)
    text_paths = [source / 'res/allfcs.txt', source / 'res/allyp.txt', source / 'res/allfcs说明.txt']
    text_paths += sorted(source.rglob('*.htm'))
    text_paths += sorted(source.rglob('*.cem')) + sorted(source.rglob('*.cl3'))
    model_index = []
    for path in text_paths:
        text, target = export_text(path, source, output, manifest)
        if path.suffix == '.htm':
            parser = PlainHTML(); parser.feed(text)
            plain = re.sub(r'[ \t]+', ' ', ''.join(parser.parts))
            dest = output / 'help_text' / path.relative_to(source).with_suffix('.txt')
            dest.parent.mkdir(parents=True, exist_ok=True)
            dest.write_text(plain, encoding='utf-8')
        if path.suffix in {'.cem', '.cl3'}:
            lines = text.splitlines()
            record = {'provenance': manifest[-1], 'format': path.suffix[1:],
                      'header_lines': lines[:3], 'line_count': len(lines),
                      'lines': [{'number': i+1, 'text': line} for i, line in enumerate(lines)],
                      'status': 'Exact decoded lines; serialized field meanings are unresolved.'}
            dest = output / 'models' / path.relative_to(source).with_suffix(path.suffix + '.json')
            write_json(dest, record)
            model_index.append({'source': manifest[-1]['source'], 'line_count': len(lines), 'format': path.suffix[1:]})
    # DEFAULT.ETS contains seven DWORDs followed by a complete, standard BMP.
    path = source / 'DEFAULT.ETS'; data = path.read_bytes()
    if data[28:30] != b'BM':
        raise ValueError('Unexpected DEFAULT.ETS layout')
    bmp_size = struct.unpack_from('<I', data, 30)[0]
    if 28 + bmp_size != len(data):
        raise ValueError('BMP length does not consume DEFAULT.ETS tail')
    width, height = struct.unpack_from('<ii', data, 46)
    original = output / 'original/DEFAULT.ETS'; shutil.copyfile(path, original)
    (output / 'DEFAULT.embedded.bmp').write_bytes(data[28:])
    ets = provenance(path, data) | {'prefix_dwords_little_endian': list(struct.unpack('<7I', data[:28])),
        'prefix_field_meanings': 'Unresolved', 'bmp_offset': 28, 'bmp_length': bmp_size,
        'bmp_width': width, 'bmp_height': height, 'bmp_bits_per_pixel': struct.unpack_from('<H', data, 56)[0]}
    manifest.append(ets)
    write_json(output / 'DEFAULT.ETS.json', ets)
    write_json(output / 'models/index.json', model_index)
    write_json(output / 'manifest.json', manifest)
    summary = {'reactions': len(reactions['records']), 'reagents': len(reagents['records']),
        'cem_files': sum(m['format']=='cem' for m in model_index),
        'cl3_files': sum(m['format']=='cl3' for m in model_index),
        'reaction_types': dict(Counter(r['fields']['equation_type'] for r in reactions['records'])),
        'equilibrium_modes': dict(Counter(r['fields']['equilibrium_mode'] for r in reactions['records'])),
        'reagent_categories_inferred': dict(Counter(r['inferred']['category_a'] for r in reagents['records'])),
        'help_html_files': sum(p.suffix=='.htm' for p in text_paths), 'ets': ets}
    write_json(output / 'summary.json', summary)
    return summary


def self_test(source: Path, output: Path):
    reactions, reagents = read_reactions(source/'res/allfcs.txt'), read_reagents(source/'res/allyp.txt')
    assert len(reactions['records']) == 599 and len(reagents['records']) == 499
    assert [r['fields']['id'] for r in reactions['records']] == [f'方程式{i}' for i in range(599)]
    water = reactions['records'][197]['fields']
    assert water['optional_note_lines'] == ['', '', '水的电离']
    assert water['equilibrium_mode'] == '可逆'
    assert reactions['records'][0]['fields']['reactants'][0] == {'species':'Ag(固体)', 'coefficient':'2'}
    for library in [reactions, reagents]:
        rebuilt = library['preamble'] + ''.join('</next>\r\n' + r['raw_text'] for r in library['records']) + '</over>\r\n'
        assert rebuilt == library['text'], 'All record separators and blank lines must round-trip'
    for entry in json.loads((output/'manifest.json').read_text(encoding='utf-8')):
        original = output / entry.get('original_copy', 'original/DEFAULT.ETS')
        assert hashlib.sha256(original.read_bytes()).hexdigest() == entry['sha256']
        if entry.get('utf8_export'):
            text = (output/entry['utf8_export']).read_bytes().decode('utf-8')
            assert text.encode(entry['encoding']) == original.read_bytes()
    ets = json.loads((output/'DEFAULT.ETS.json').read_text(encoding='utf-8'))
    assert (output/'DEFAULT.embedded.bmp').read_bytes() == (source/'DEFAULT.ETS').read_bytes()[ets['bmp_offset']:]
    print('PASS: 599 reactions, 499 reagents, exact line/separator round-trip, all text and original hashes, embedded BMP.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, default=DEFAULT_SOURCE)
    parser.add_argument('--output', type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    summary = recover(args.source.resolve(), args.output.resolve())
    print(json.dumps({key:value for key,value in summary.items() if key!='ets'}, ensure_ascii=False))
    if args.check:
        self_test(args.source.resolve(), args.output.resolve())

if __name__ == '__main__':
    main()
