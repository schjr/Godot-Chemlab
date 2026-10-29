"""Prepare original ChemLab data and images for the Godot port (Pillow required)."""
from pathlib import Path
from io import BytesIO
from html.parser import HTMLParser
import hashlib
import json
import re
from PIL import Image

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'godot'
def write(name,value):
    path=OUT/name;path.parent.mkdir(parents=True,exist_ok=True)
    path.write_text(json.dumps(value,ensure_ascii=False,indent=2)+'\n')

def preserve_native_rgb(path):
    """Keep source RGB exact: native mask arithmetic also reads alpha-zero pixels."""
    settings=path.with_suffix(path.suffix+'.import')
    text=settings.read_text() if settings.exists() else ('[remap]\nimporter="texture"\ntype="CompressedTexture2D"\n\n[params]\n')
    key='process/fix_alpha_border'
    if re.search(r'^'+re.escape(key)+r'=.*$',text,re.M):
        text=re.sub(r'^'+re.escape(key)+r'=.*$',key+'=false',text,flags=re.M)
    else:
        text=text.rstrip()+'\n'+key+'=false\n'
    settings.write_text(text)

def props(node):
    return {v['name']:v['value'].get('value') for v in node['properties']}

def compact(node,source):
    p=props(node)
    for secret in ['ConnectionString','Password','UserName']:p.pop(secret,None)
    for field in list(p):
        if field.endswith('.Data'):
            raw=bytes.fromhex(p[field]);offset=raw.find(b'BM')
            if offset>=0:
                try:
                    image=Image.open(BytesIO(raw[offset:])).convert('RGBA')
                    count=max(1,int(p.get('NumGlyphs',1)))
                    image=image.crop((0,0,image.width//count,image.height))
                    key=image.getpixel((0,image.height-1))[:3]
                    image.putdata([(r,g,b,0 if (r,g,b)==key else a) for r,g,b,a in image.getdata()])
                    name=source+'_'+node['name']+'_'+field.replace('.','_')+'.png'
                    image.save(OUT/'assets/glyphs'/name)
                    p[field]='res://assets/glyphs/'+name
                except (ValueError,OSError):p.pop(field)
            else:p.pop(field)
    return {'name':node['name'],'class':node['class'],'properties':p,
            'children':[compact(c,source) for c in node['children']]}

class Plain(HTMLParser):
    def __init__(self):super().__init__(convert_charrefs=True);self.parts=[];self.ignore=0
    def handle_starttag(self,tag,attrs):
        if tag in ('style','script'):self.ignore+=1
        if tag in ('p','div','br','tr','h1','h2','h3','li'):self.parts.append('\n')
        if tag=='img':
            alt=dict(attrs).get('alt','')
            if alt:self.parts.append(alt)
    def handle_endtag(self,tag):
        if tag in ('style','script'):self.ignore=max(0,self.ignore-1)
        if tag in ('p','div','tr','li'):self.parts.append('\n')
    def handle_data(self,data):
        if not self.ignore:self.parts.append(data)
def plain(s):
    if not isinstance(s,str):return str(s) if s is not None else ''
    parser=Plain();parser.feed(s)
    return re.sub(r'\n[ \t\r]*\n[ \t\r]*\n','\n\n',''.join(parser.parts)).strip()

def main():
    for name in ['assets/glyphs','assets/apparatus','assets/fills','assets/reference','data']:(OUT/name).mkdir(parents=True,exist_ok=True)
    forms={}
    for module in ['_main','_mol','_ency','avi','gif']:
        for path in sorted((ROOT/'recovered/forms'/module).glob('*.json')):
            data=json.loads(path.read_text())
            forms[module+'/'+path.stem]=compact(data['form'],module+'_'+path.stem)
    write('data/forms.json',forms)
    main_form=forms['_main/TFORM1'];tools=main_form['children'][1]['children']
    write('data/toolbar.json',[{'name':n['name'],**n['properties']} for n in tools])
    reagents=[]
    for record in json.loads((ROOT/'recovered/chemistry/reagents.json').read_text())['records']:
        f=record['lines']
        reagents.append({'id':record['index'],'name':f[0],'species':f[1],'molar_mass':float(f[2] or '0'),
            'charge':float(f[3] or '0'),'category':f[4].strip(),'color_integer':int(f[6] or '0'),
            'solubility_at_20_C':f[11],'density_or_render_parameter':f[7],'raw_fields':f})
    write('data/reagents.json',reagents)
    reactions=[r['fields'] for r in json.loads((ROOT/'recovered/chemistry/reactions.json').read_text())['records']]
    write('data/reactions.json',reactions)
    schema=json.loads((ROOT/'recovered/database/schema.json').read_text())
    tables=[]
    titles={'chemicals':'常见物质','chemics':'化学家','concepts':'化学概念','eleinfo':'元素资料','elements':'元素周期表','idlib':'索引','resdiy':'自定义资源'}
    for table in schema['tables']:
        records=json.loads((ROOT/'recovered/database'/table['data_file']).read_text())
        tables.append({'name':table['name'],'title':titles[table['name']], 'columns':[c['name'] for c in table['columns']],
            'records':[{k:plain(v) for k,v in row.items()} for row in records]})
    write('data/encyclopedia.json',tables)
    help_pages=[]
    for path in sorted((ROOT/'recovered/chemistry/help_text').rglob('*.txt')):
        text=path.read_text();lines=[line.strip() for line in text.splitlines() if line.strip()]
        help_pages.append({'name':path.stem,'title':lines[0] if lines else path.stem,'text':text})
    write('data/help.json',help_pages)
    sprites={}
    for path in sorted((ROOT/'artifacts/ChemLab/res').glob('*')):
        if path.suffix.lower()!='.bmp':continue
        img=Image.open(path).convert('RGBA')
        key=img.getpixel((0,img.height-1))[:3]
        img.putdata([(r,g,b,0 if (r,g,b)==key else a) for r,g,b,a in img.getdata()])
        name=path.stem.lower()+'.png';image_path=OUT/'assets/apparatus'/name;img.save(image_path)
        preserve_native_rgb(image_path)
        sprites[path.stem.lower()]={'texture':'res://assets/apparatus/'+name,'size':[img.width,img.height],
            'source':str(path.relative_to(ROOT)),'sha256':hashlib.sha256(path.read_bytes()).hexdigest()}
        if path.stem.startswith('_') and not path.stem.startswith('_a'):
            original=Image.open(path).convert('RGB')
            mask=Image.new('RGBA',original.size)
            mask.putdata([(255,255,255,255-min(r,g,b)) for r,g,b in original.getdata()])
            mask.save(OUT/'assets/fills'/(path.stem[1:].lower()+'.png'))
    Image.open(ROOT/'artifacts/ChemLab/res/muwen.jpg').resize((70,20)).save(OUT/'assets/apparatus/wood.png')
    write('data/sprites.json',sprites)
    Image.open(ROOT/'artifacts/ChemLab/help/jiemian1.jpg').save(OUT/'assets/reference/original_interface.png')
    Image.open(ROOT/'recovered/chemistry/DEFAULT.embedded.bmp').save(OUT/'assets/reference/default_sheet.png')
    print(f'Prepared {len(forms)} form layouts, {len(reagents)} reagents, {len(reactions)} reactions, {len(sprites)} apparatus sprites, 475 encyclopedia records.')

if __name__=='__main__':main()
