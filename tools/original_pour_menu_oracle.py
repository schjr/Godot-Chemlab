"""Original PopupMenu1Popup43F008 N18 visibility/checked references."""
import json
from original_selection_oracle import SelectionOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX
class PopupOracle(SelectionOracle):
 def menu(self,selected,closed,orientation):
  p=self.vessels[selected];self.u32(p+0x38,closed);self.u32(p+0x18,orientation);self.u32(0x57a730,self.u32(p+8));self.u32(0x57a734,selected);self.u32(0x57a73c,0)
  target=self.u32(self.form+0x448);flags={'visible':False,'checked':None}
  def visible():
   if self.uc.reg_read(UC_X86_REG_EAX)==target:flags['visible']=bool(self.uc.reg_read(UC_X86_REG_EDX)&255)
   self.ret()
  def checked():
   if self.uc.reg_read(UC_X86_REG_EAX)==target:flags['checked']=bool(self.uc.reg_read(UC_X86_REG_EDX)&255)
   self.ret()
  self.hooks.update({0x4d39d4:visible,0x4d3864:checked,0x4d37f4:lambda:self.ret(),0x4d38b8:lambda:self.ret()})
  self.uc.reg_write(UC_X86_REG_EAX,self.form);self.uc.reg_write(UC_X86_REG_EDX,0);self.uc.reg_write(UC_X86_REG_ECX,0);self.call(0x43f008,b'');return flags
def main():
 cases=[];errors=[]
 for doc in json.loads((ROOT/'godot/data/examples.json').read_text()):
  o=PopupOracle();scene=o.setup_scene(doc)
  for off in range(0x3a8,0x500,4):o.u32(o.form+off,o.alloc(0x80))
  for i,a in enumerate(doc['apparatus']):
   for closed in [0,1]:
    for orientation in [0,1,2]:
     try:cases.append(dict(name=doc['name'],index=i,type=a['type_id'],size=int(a['native_fields']['0x0c']),closed=closed,orientation=orientation,expected=o.menu(i,closed,orientation)))
     except Exception as e:errors.append(str(e))
 metadata_oracle=PopupOracle();pointer=metadata_oracle.u32(0x561a2c-56);raw=bytes(metadata_oracle.uc.mem_read(pointer,4096));import struct
 count=struct.unpack_from('<H',raw)[0];offset=6;fields={}
 for i in range(count):
  field_offset,type_index=struct.unpack_from('<IH',raw,offset);length=raw[offset+6];name=raw[offset+7:offset+7+length].decode('ascii');offset+=7+length;fields[name]=field_offset
 assert fields['N18']==0x448 and fields['Menu_property']==0x370
 out=dict(field_metadata={'vmt':'0x00561A2C','field_table':hex(pointer),'count':count,'raw_hex':raw[:offset].hex(),'N18_offset':fields['N18'],'Menu_property_offset':fields['Menu_property']},source_sha256=EXPECTED,entry='0043F008',field_table='TFORM1 VMT561A2C fieldtable561B0C contains N18 offset448; Menu_property offset370 is not pouring',cases=cases,errors=errors)
 (ROOT/'godot/tests/fixtures/original_pour_menu.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(len(cases),'cases',len(errors),errors[:2])
if __name__=='__main__':main()
