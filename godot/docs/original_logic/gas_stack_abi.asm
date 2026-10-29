; Original PE SHA256 7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c
; Source ABI fragments; omitted ranges are not represented as executed.
; Fragment 0x4018b0
004018b0: 55                       push ebp
004018b1: 8bec                     mov ebp, esp
004018b3: 81c40cffffff             add esp, 0xffffff0c
004018b9: 898d3cffffff             mov dword ptr [ebp - 0xc4], ecx
004018bf: 899540ffffff             mov dword ptr [ebp - 0xc0], edx
004018c5: 898544ffffff             mov dword ptr [ebp - 0xbc], eax
004018cb: b82c7e5500               mov eax, 0x557e2c
004018d0: e80b331300               call 0x534be0
; Fragment 0x4019d6
004019d6: e8fd0a0600               call 0x4624d8
004019db: e870d20600               call 0x46ec50
004019e0: e82fba0600               call 0x46d414
004019e5: e81add0600               call 0x46f704
004019ea: e8e90a0600               call 0x4624d8
; Fragment 0x46f704
0046f704: 55                       push ebp
0046f705: 8bec                     mov ebp, esp
0046f707: 81c44cffffff             add esp, 0xffffff4c
0046f70d: 53                       push ebx
0046f70e: b8c4665600               mov eax, 0x5666c4
0046f713: e8c8540c00               call 0x534be0
; Fragment 0x46fac9
0046fac9: dd458c                   fld qword ptr [ebp - 0x74]
0046facc: dc5d9c                   fcomp qword ptr [ebp - 0x64]
0046facf: dfe0                     fnstsw ax
0046fad1: 9e                       sahf 
0046fad2: 7609                     jbe 0x46fadd
0046fad4: dd458c                   fld qword ptr [ebp - 0x74]
0046fad7: dc659c                   fsub qword ptr [ebp - 0x64]
0046fada: dd5d84                   fstp qword ptr [ebp - 0x7c]
0046fadd: dd458c                   fld qword ptr [ebp - 0x74]
0046fae0: dc1d54004700             fcomp qword ptr [0x470054]
0046fae6: dfe0                     fnstsw ax
0046fae8: 9e                       sahf 
0046fae9: 7310                     jae 0x46fafb
0046faeb: 33d2                     xor edx, edx
0046faed: 899574ffffff             mov dword ptr [ebp - 0x8c], edx
0046faf3: 899578ffffff             mov dword ptr [ebp - 0x88], edx
0046faf9: eb29                     jmp 0x46fb24
0046fafb: ff75fc                   push dword ptr [ebp - 4]
0046fafe: e89544feff               call 0x453f98
0046fb03: 59                       pop ecx
0046fb04: 8b0c8550585800           mov ecx, dword ptr [eax*4 + 0x585850]
0046fb0b: 8b8570ffffff             mov eax, dword ptr [ebp - 0x90]
0046fb11: dd84c1d8080000           fld qword ptr [ecx + eax*8 + 0x8d8]
0046fb18: dc4d84                   fmul qword ptr [ebp - 0x7c]
0046fb1b: dc758c                   fdiv qword ptr [ebp - 0x74]
0046fb1e: dd9d74ffffff             fstp qword ptr [ebp - 0x8c]
0046fb24: dd8574ffffff             fld qword ptr [ebp - 0x8c]
0046fb2a: d81d3c004700             fcomp dword ptr [0x47003c]
0046fb30: dfe0                     fnstsw ax
0046fb32: 9e                       sahf 
0046fb33: 730e                     jae 0x46fb43
0046fb35: 33d2                     xor edx, edx
