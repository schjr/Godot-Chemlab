"""Actual native no-op branches before random access; explicit diagnostic TLS."""
import json
from original_particles_oracle import ParticleOracle
from original_x86_oracle import ROOT,EXPECTED
class AccessOracle(ParticleOracle):
 def __init__(self):
  super().__init__(0x12345678,0x9abcdef0);self.tls_access_count=0
  self.hooks[0x53ca64]=self.tls_access
 def tls_access(self):self.tls_access_count+=1;self.ret(self.tls)
def run(name,setup,operation):
 o=AccessOracle();setup(o);before=o.rng();operation(o)
 return {'name':name,'tls_access_count':o.tls_access_count,'before':before,'after':o.rng()}
def main():
 cases=[run('solid_cap2000',lambda o:o.u32(o.pool+0x34684,2000),lambda o:o.emit_solid([],[],0,0)),
 run('solid_empty_emit',lambda o:None,lambda o:o.emit_solid([],[],0,0)),
 run('solid_fractional_no_emit',lambda o:None,lambda o:o.emit_solid([0x112233],[0.99],0,0)),
 run('solid_empty_update',lambda o:None,lambda o:o.update_solid()),
 run('solid_frozen_update',lambda o:(o.u32(o.pool+0x34684,1),o.uc.mem_write(o.pool+0x34680,b'\1')),lambda o:o.update_solid()),
 run('solid_delete_only_update',lambda o:o.u32(o.pool+0x34684,1),lambda o:o.update_solid()),
 run('bubble_throttle',lambda o:o.create_bubble(),lambda o:o.emit_bubbles([10,40,0,0,0,3,8,1,5])),
 run('bubble_zero_requested',lambda o:(o.create_bubble(),o.u32(o.bubble+0xfc10,2)),lambda o:o.emit_bubbles([10,40,0,0,0,3,8,0,5])),
 run('bubble_empty_update',lambda o:o.create_bubble(),lambda o:o.update_bubbles())]
 assert all(c['tls_access_count']==0 and c['before']==c['after'] for c in cases)
 result={'source_sha256':EXPECTED,'scope':'Actual native49BF44/49C298/49A61C/49AA88 no-op branches; explicit TLS diagnostic bytes, not startup inference','cases':cases}
 (ROOT/'godot/docs/original_logic/particle_noop_rng_evidence.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(cases))
if __name__=='__main__':main()
