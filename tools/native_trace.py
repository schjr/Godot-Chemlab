"""Read exact saved native function exports without rerunning the decompiler."""
from pathlib import Path
import argparse
import re

ROOT=Path(__file__).resolve().parents[1]

def functions(module='main'):
    result={}
    for file in ['decompiled.cpp','published_recovered.cpp']:
        path=ROOT/'recovered/native'/module/file
        content=path.read_text()
        matches=list(re.finditer(r'(?m)^// Entry ([0-9a-fA-F]+), recovered name (.+)\n',content))
        for i,m in enumerate(matches):
            end=matches[i+1].start() if i+1<len(matches) else len(content)
            address=int(m.group(1),16)
            result[address]={'address':address,'name':m.group(2),'file':path,'line':content.count('\n',0,m.start())+1,'body':content[m.start():end]}
    return result

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('selector')
    parser.add_argument('--module',default='main')
    parser.add_argument('--callees',action='store_true')
    parser.add_argument('--callers',action='store_true')
    parser.add_argument('--body',action='store_true')
    args=parser.parse_args();index=functions(args.module)
    selector=args.selector.removeprefix('0x').removeprefix('FUN_')
    if re.fullmatch('[0-9a-fA-F]{6,8}',selector): selected=[index[int(selector,16)]]
    else:selected=[f for f in index.values() if args.selector in f['name']]
    for f in selected:
        print(f"0x{f['address']:08x} {f['name']} {f['file'].relative_to(ROOT)}:{f['line']}")
        if args.body or not(args.callees or args.callers):print(f['body'])
        if args.callees:
            refs=sorted(set(int(a,16) for a in re.findall(r'(?:FUN_|Published_\w+_)([0-9a-fA-F]{8})\s*\(',f['body'])))
            for address in refs:
                x=index.get(address,{})
                print('callee',hex(address),x.get('name','unknown'),f"{x['file'].relative_to(ROOT)}:{x['line']}" if x else '')
        if args.callers:
            for x in index.values():
                if x['address']==f['address']:continue
                if re.search(r'(?:FUN_|Published_\w+_)'+f"{f['address']:08x}"+r'\s*\(',x['body']):
                    print('caller',hex(x['address']),x['name'],f"{x['file'].relative_to(ROOT)}:{x['line']}")

if __name__=='__main__':main()
