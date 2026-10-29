"""Translate shipped ChemLab text formats; no synthetic chemistry or geometry."""
from pathlib import Path
import json, re, hashlib, shutil
ROOT = Path(__file__).resolve().parents[1]


def molecule(lines, name):
    atoms, bonds, lookup = [], [], {}
    def atom(label, coords, scale=10.0):
        if not label:
            return None
        if label not in lookup:
            m = re.match(r'([A-Z][a-z]?)', label)
            lookup[label] = len(atoms)
            atoms.append(dict(element=m.group(1) if m else '?', label=label, position=[float(x)/scale for x in coords], legacy_position=[float(x) for x in coords]))
        return lookup[label]
    p = 61
    for _ in range(int(lines[60])):
        count = int(lines[p]); p += 1
        for r in range(count):
            rec = lines[p:p+46];p+=46
            assert len(rec) == 46
            a = atom(rec[2], rec[3:6])
            for slot_index in range(4):
                slot = rec[6+slot_index*10:16+slot_index*10]
                b = atom(slot[1], slot[2:5])
                if a is not None and b is not None and slot[6]:
                    pair = sorted([a,b])
                    if not any([x['a'],x['b']] == pair for x in bonds):
                        bonds.append(dict(a=pair[0], b=pair[1], order=max(1,int(slot[5])), label=slot[6]))
    free_count=int(lines[p]);p+=1
    for _ in range(free_count):
        title, na, nb=lines[p:p+3];p+=3
        group_atoms=[]
        for _ in range(int(na)):
            rec=lines[p:p+109];p+=109
            idx=atom(rec[0],rec[3:6],1.0);group_atoms.append(idx)
            atoms[idx]['radius']=float(rec[2]);atoms[idx]['color']=[float(x) for x in rec[6:9]]
        for _ in range(int(nb)):
            rec=lines[p:p+111];p+=111
            endpoints=[]
            for xyz in [rec[1:4],rec[4:7]]:
                coords=[float(x) for x in xyz]
                candidates=[i for i in group_atoms if sum((atoms[i]['position'][k]-coords[k])**2 for k in range(3)) < 1e-8]
                endpoints.append(candidates[0] if candidates else None)
            if all(i is not None for i in endpoints):
                bonds.append(dict(a=endpoints[0],b=endpoints[1],order=1,label=rec[0]))
    return dict(name=name, format='cl3', atoms=atoms, bonds=bonds, settings=lines[:61], trailing_lines=lines[p:], raw_lines=lines)



def experiment(lines, name):
    apparatus = []
    # Every vessel starts with 40 metadata fields, followed by a reagent count.
    p = 5
    for _ in range(int(lines[1])):
        meta=lines[p:p+40]
        assert len(meta)==40
        obj=dict(id=int(meta[0]),name=meta[1],type_id=int(meta[2]),x=float(meta[4]),y=float(meta[5]),capacity=float(meta[8]),temperature=float(meta[30]),metadata=meta,chemicals=[],reactions=[])
        offsets=[0,4,8,12,16,20,24,32,40,48,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,144,148,152,156,160,164,168,176,184]
        obj['native_fields']={f'0x{offset:02x}':value for offset,value in zip(offsets,meta)}
        p+=40
        n=int(lines[p]);p+=1
        for _ in range(n):
            obj['chemicals'].append(dict(name=lines[p],mass=float(lines[p+1]),moles=float(lines[p+2]),raw_mass=lines[p+1],raw_moles=lines[p+2]))
            p+=3
        n=int(lines[p]);p+=1
        for _ in range(n):
            ident,title,nr,np=lines[p:p+4];p+=4
            sides=[]
            for count in [int(nr),int(np)]:
                side=[]
                for _ in range(count):
                    side.append(dict(name=lines[p],coefficient=int(lines[p+1])));p+=2
                sides.append(side)
            tail=lines[p:p+5];p+=5
            obj['reactions'].append(dict(id=ident,name=title,reactants=sides[0],products=sides[1],parameters=tail,direction=tail[4]))
        obj['simulation_fields']=lines[p:p+20];p+=20
        apparatus.append(obj)
    connectors=[]
    for _ in range(int(lines[3])):
        rec=lines[p:p+25];p+=25
        connectors.append(dict(id=int(rec[0]),name=rec[1],start=[float(rec[2]),float(rec[3])],end=[float(rec[4]),float(rec[5])],from_vessel=rec[11],to_vessel=rec[14],metadata=rec))
    for vessel in apparatus:
        for chemical in vessel['chemicals']:
            chemical['moles_variable']=lines[p];chemical['mass_variable']=lines[p+1];p+=2
    trailer=lines[p:]
    pos=1;variables=[];annotations=[]
    for _ in range(int(trailer[0])):
        rec=trailer[pos:pos+7];pos+=7
        variables.append(dict(name=rec[3],description=rec[4],value=rec[5],record=rec))
    pos+=1+int(trailer[pos])*55
    count=int(trailer[pos]);pos+=1
    for _ in range(count):
        rec=trailer[pos:pos+16];pos+=16;n=int(rec[15])
        annotations.append(dict(kind='annotation',position=[float(rec[1]),float(rec[2])],size=[float(rec[3]),float(rec[4])],color_integer=int(rec[6]),font_size=abs(int(rec[7])),font=rec[14],text='\n'.join(trailer[pos:pos+n]),metadata=rec));pos+=n
    return dict(name=name,format='cem',apparatus=apparatus,connectors=connectors,variables=variables,annotations=annotations,header=lines[:5],trailing_lines=trailer,raw_lines=lines)


def library_model(lines, name):
    na,nb=int(lines[2]),int(lines[3]);p=7
    atoms=[];bonds=[]
    for _ in range(na):
        rec=lines[p:p+9];p+=9
        m=re.match(r'([A-Z][a-z]?)',rec[0])
        atoms.append(dict(element=m.group(1) if m else '?',label=rec[0],radius=float(rec[2]),color=[float(x) for x in rec[3:6]],position=[float(x) for x in rec[6:9]],legacy_position=[float(x) for x in rec[6:9]]))
    for _ in range(nb):
        rec=lines[p:p+7];p+=7;ends=[]
        for xyz in [rec[1:4],rec[4:7]]:
            coords=[float(x) for x in xyz]
            matches=[i for i,a in enumerate(atoms) if sum((a['position'][k]-coords[k])**2 for k in range(3))<1e-8]
            ends.append(matches[0] if matches else None)
        if all(i is not None for i in ends):bonds.append(dict(a=ends[0],b=ends[1],order=1,label=rec[0]))
    assert p==len(lines), (p,len(lines))
    return dict(name=name,format='model',atoms=atoms,bonds=bonds,background=[float(x) for x in lines[4:7]],raw_lines=lines,trailing_lines=[])


def encoding_map():
    two={}
    for a in range(0x81,0xff):
        for b in range(0x40,0xff):
            if b==0x7f:continue
            raw=bytes([a,b])
            try:two[str((a<<8)|b)]=ord(raw.decode('gb18030'))
            except UnicodeDecodeError:pass
    ranges=[];first=last=unicode_start=previous_unicode=None
    for cp in range(0x110000):
        if 0xd800<=cp<=0xdfff:continue
        raw=chr(cp).encode('gb18030')
        if len(raw)!=4:continue
        a,b,c,d=raw;index=(((a-0x81)*10+(b-0x30))*126+(c-0x81))*10+(d-0x30)
        if last is not None and index==last+1 and cp==previous_unicode+1:
            last=index;previous_unicode=cp
        else:
            if first is not None:ranges.append([first,last,unicode_start])
            first=last=index;unicode_start=previous_unicode=cp
    if first is not None:ranges.append([first,last,unicode_start])
    ranges.sort()
    (ROOT/'godot/data/gb18030.json').write_text(json.dumps(dict(two_byte=two,four_byte_ranges=ranges),separators=(',',':')))


def main():
    encoding_map()
    result={'cem':[],'cl3':[]}
    for path in sorted((ROOT/'recovered/chemistry/utf8').rglob('*')):
        if path.suffix not in ['.cem','.cl3']:continue
        lines=path.read_text().splitlines()
        try:
            model=(experiment if path.suffix=='.cem' else molecule)(lines,path.stem)
        except Exception as e:
            raise ValueError(f'{path}: {e}') from e
        model['raw_text']=path.read_bytes().decode('utf-8')
        model['source']=str(path.relative_to(ROOT))
        model['sha256']=hashlib.sha256((ROOT/'recovered/chemistry/original'/path.relative_to(ROOT/'recovered/chemistry/utf8')).read_bytes()).hexdigest()
        result[path.suffix[1:]].append(model)
    for path in sorted((ROOT/'artifacts/ChemLab/模型').rglob('*')):
        if not path.is_file():continue
        text=path.read_bytes().decode('gb18030')
        model=library_model(text.splitlines(),path.name)
        model['source']=str(path.relative_to(ROOT));model['sha256']=hashlib.sha256(path.read_bytes()).hexdigest();model['raw_text']=text
        result['cl3'].append(model)
    for ext, models in result.items():
        for model in models:
            source=ROOT/model['source']
            if ext=='cem' or model['format']=='cl3':
                source=Path(str(source).replace('chemistry/utf8/','chemistry/original/'))
            category='examples' if ext=='cem' else 'cl3' if model['format']=='cl3' else 'models'
            fixture=ROOT/'godot/tests/fixtures'/category/source.name
            fixture.parent.mkdir(parents=True,exist_ok=True)
            shutil.copyfile(source,fixture)
            model['fixture']='res://'+str(fixture.relative_to(ROOT/'godot'))
    for ext,file in [('cem','examples.json'),('cl3','molecules.json')]:
        (ROOT/'godot/data'/file).write_text(json.dumps(result[ext],ensure_ascii=False,indent=2)+'\n')
    print({k:len(v) for k,v in result.items()})
    print('atoms',sum(len(m['atoms']) for m in result['cl3']),'bonds',sum(len(m['bonds']) for m in result['cl3']))
if __name__=='__main__':main()
