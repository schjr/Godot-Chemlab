; Actual main.exe instructions, SHA256 7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c
; Capstone 5.0.7 offline decoding, no execution.
0048E418  55                        push ebp
0048E419  8bec                      mov ebp, esp
0048E41B  83c4f0                    add esp, -0x10
0048E41E  33c0                      xor eax, eax
0048E420  8945fc                    mov dword ptr [ebp - 4], eax
0048E423  e92d020000                jmp 0x48e655
0048E428  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E42B  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E432  db81783c0000              fild dword ptr [ecx + 0x3c78]
0048E438  dd5df0                    fstp qword ptr [ebp - 0x10]
0048E43B  dd45f0                    fld qword ptr [ebp - 0x10]
0048E43E  d81d68e64800              fcomp dword ptr [0x48e668]
0048E444  dfe0                      fnstsw ax
0048E446  9e                        sahf 
0048E447  730c                      jae 0x48e455
0048E449  33d2                      xor edx, edx
0048E44B  8955f0                    mov dword ptr [ebp - 0x10], edx
0048E44E  c745f40000f03f            mov dword ptr [ebp - 0xc], 0x3ff00000
0048E455  dd45f0                    fld qword ptr [ebp - 0x10]
0048E458  d81d6ce64800              fcomp dword ptr [0x48e66c]
0048E45E  dfe0                      fnstsw ax
0048E460  9e                        sahf 
0048E461  760c                      jbe 0x48e46f
0048E463  33d2                      xor edx, edx
0048E465  8955f0                    mov dword ptr [ebp - 0x10], edx
0048E468  c745f400003340            mov dword ptr [ebp - 0xc], 0x40330000
0048E46F  dd45f0                    fld qword ptr [ebp - 0x10]
0048E472  d82570e64800              fsub dword ptr [0x48e670]
0048E478  83c4f8                    add esp, -8
0048E47B  dd1c24                    fstp qword ptr [esp]
0048E47E  e851b00a00                call 0x5394d4
0048E483  83c408                    add esp, 8
0048E486  dc1d74e64800              fcomp qword ptr [0x48e674]
0048E48C  dfe0                      fnstsw ax
0048E48E  9e                        sahf 
0048E48F  730e                      jae 0x48e49f
0048E491  33d2                      xor edx, edx
0048E493  8955f0                    mov dword ptr [ebp - 0x10], edx
0048E496  c745f40000f03f            mov dword ptr [ebp - 0xc], 0x3ff00000
0048E49D  eb36                      jmp 0x48e4d5
0048E49F  dd45f0                    fld qword ptr [ebp - 0x10]
0048E4A2  d81d70e64800              fcomp dword ptr [0x48e670]
0048E4A8  dfe0                      fnstsw ax
0048E4AA  9e                        sahf 
0048E4AB  760e                      jbe 0x48e4bb
0048E4AD  dd45f0                    fld qword ptr [ebp - 0x10]
0048E4B0  d8257ce64800              fsub dword ptr [0x48e67c]
0048E4B6  dd5df0                    fstp qword ptr [ebp - 0x10]
0048E4B9  eb1a                      jmp 0x48e4d5
0048E4BB  dd45f0                    fld qword ptr [ebp - 0x10]
0048E4BE  d81d70e64800              fcomp dword ptr [0x48e670]
0048E4C4  dfe0                      fnstsw ax
0048E4C6  9e                        sahf 
0048E4C7  730c                      jae 0x48e4d5
0048E4C9  db2d80e64800              fld xword ptr [0x48e680]
0048E4CF  dc4df0                    fmul qword ptr [ebp - 0x10]
0048E4D2  dd5df0                    fstp qword ptr [ebp - 0x10]
0048E4D5  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E4D8  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E4DF  8b4108                    mov eax, dword ptr [ecx + 8]
0048E4E2  83c09b                    add eax, -0x65
0048E4E5  83e806                    sub eax, 6
0048E4E8  720d                      jb 0x48e4f7
0048E4EA  48                        dec eax
0048E4EB  740a                      je 0x48e4f7
0048E4ED  83e80d                    sub eax, 0xd
0048E4F0  7405                      je 0x48e4f7
0048E4F2  e95b010000                jmp 0x48e652
0048E4F7  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E4FA  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E501  83b9a000000001            cmp dword ptr [ecx + 0xa0], 1
0048E508  0f85d5000000              jne 0x48e5e3
0048E50E  8b45fc                    mov eax, dword ptr [ebp - 4]
0048E511  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0048E518  dd8220430000              fld qword ptr [edx + 0x4320]
0048E51E  dc1d8ce64800              fcomp qword ptr [0x48e68c]
0048E524  dfe0                      fnstsw ax
0048E526  9e                        sahf 
0048E527  765e                      jbe 0x48e587
0048E529  d90594e64800              fld dword ptr [0x48e694]
0048E52F  dc0dd4365600              fmul qword ptr [0x5636d4]
0048E535  dc4df0                    fmul qword ptr [ebp - 0x10]
0048E538  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E53B  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E542  dc8188000000              fadd qword ptr [ecx + 0x88]
0048E548  dd9988000000              fstp qword ptr [ecx + 0x88]
0048E54E  8b45fc                    mov eax, dword ptr [ebp - 4]
0048E551  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0048E558  dd8288000000              fld qword ptr [edx + 0x88]
0048E55E  d81d98e64800              fcomp dword ptr [0x48e698]
0048E564  dfe0                      fnstsw ax
0048E566  9e                        sahf 
0048E567  767a                      jbe 0x48e5e3
0048E569  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E56C  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E573  33c0                      xor eax, eax
0048E575  898188000000              mov dword ptr [ecx + 0x88], eax
0048E57B  c7818c00000000005940      mov dword ptr [ecx + 0x8c], 0x40590000
0048E585  eb5c                      jmp 0x48e5e3
0048E587  d9059ce64800              fld dword ptr [0x48e69c]
0048E58D  dc0dd4365600              fmul qword ptr [0x5636d4]
0048E593  dc4df0                    fmul qword ptr [ebp - 0x10]
0048E596  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E599  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E5A0  dc8188000000              fadd qword ptr [ecx + 0x88]
0048E5A6  dd9988000000              fstp qword ptr [ecx + 0x88]
0048E5AC  8b45fc                    mov eax, dword ptr [ebp - 4]
0048E5AF  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0048E5B6  dd8288000000              fld qword ptr [edx + 0x88]
0048E5BC  d81da0e64800              fcomp dword ptr [0x48e6a0]
0048E5C2  dfe0                      fnstsw ax
0048E5C4  9e                        sahf 
0048E5C5  761c                      jbe 0x48e5e3
0048E5C7  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E5CA  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E5D1  33c0                      xor eax, eax
0048E5D3  898188000000              mov dword ptr [ecx + 0x88], eax
0048E5D9  c7818c00000000008940      mov dword ptr [ecx + 0x8c], 0x40890000
0048E5E3  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E5E6  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E5ED  83b9a000000000            cmp dword ptr [ecx + 0xa0], 0
0048E5F4  755c                      jne 0x48e652
0048E5F6  d90594e64800              fld dword ptr [0x48e694]
0048E5FC  dc0dd4365600              fmul qword ptr [0x5636d4]
0048E602  dc4df0                    fmul qword ptr [ebp - 0x10]
0048E605  8b45fc                    mov eax, dword ptr [ebp - 4]
0048E608  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0048E60F  dcaa88000000              fsubr qword ptr [edx + 0x88]
0048E615  dd9a88000000              fstp qword ptr [edx + 0x88]
0048E61B  8b4dfc                    mov ecx, dword ptr [ebp - 4]
0048E61E  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
0048E625  dd8088000000              fld qword ptr [eax + 0x88]
0048E62B  d81da4e64800              fcomp dword ptr [0x48e6a4]
0048E631  dfe0                      fnstsw ax
0048E633  9e                        sahf 
0048E634  731c                      jae 0x48e652
0048E636  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E639  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
0048E640  33c0                      xor eax, eax
0048E642  898188000000              mov dword ptr [ecx + 0x88], eax
0048E648  c7818c00000000003440      mov dword ptr [ecx + 0x8c], 0x40340000
0048E652  ff45fc                    inc dword ptr [ebp - 4]
0048E655  8b55fc                    mov edx, dword ptr [ebp - 4]
0048E658  3b159c775800              cmp edx, dword ptr [0x58779c]
0048E65E  0f8cc4fdffff              jl 0x48e428
0048E664  8be5                      mov esp, ebp
0048E666  5d                        pop ebp
0048E667  c3                        ret 
