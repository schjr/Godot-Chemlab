"""Record native bitmap RGB references before Godot's texture importer runs.

Run with uv in a Python environment containing Pillow. This reads the original
BMP resources, verifies their catalog digests and checks the prepared PNG RGB;
it does not derive expected values from Godot's imported textures.
"""
from pathlib import Path
import hashlib
import json
from PIL import Image

ROOT = Path(__file__).resolve().parents[1]


def main():
    sprites = json.loads((ROOT / 'godot/data/sprites.json').read_text())
    rows = []
    pixels = 0
    for name, record in sorted(sprites.items()):
        original = ROOT / record['source']
        if hashlib.sha256(original.read_bytes()).hexdigest() != record['sha256']:
            raise ValueError(f'Original resource identity changed: {original}')
        image = Image.open(original).convert('RGB')
        prepared = Image.open(ROOT / 'godot/assets/apparatus' / (name + '.png')).convert('RGB')
        if image.size != prepared.size or image.tobytes() != prepared.tobytes():
            raise ValueError(f'Prepared PNG RGB differs from original BMP: {name}')
        rgb = image.tobytes()
        words = bytearray()
        for offset in range(0, len(rgb), 3):
            r, g, b = rgb[offset:offset + 3]
            words.extend((b, g, r, 0))
        pixels += image.width * image.height
        rows.append({'name': name, 'width': image.width, 'height': image.height,
                     'source': record['source'], 'source_sha256': record['sha256'],
                     'native_rgb_words_sha256': hashlib.sha256(words).hexdigest()})
    fixture = {'source': 'Original ChemLab BMP RGB decoded top-down to little-endian0x00RRGGBB words; no alpha-key mutation',
               'images': rows, 'pixels': pixels}
    (ROOT / 'godot/tests/fixtures/original_bitmap_rgb.json').write_text(json.dumps(fixture, indent=2) + '\n')
    print(json.dumps({'images': len(rows), 'pixels': pixels}))


if __name__ == '__main__':
    main()
