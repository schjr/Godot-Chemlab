0049cdd8 push ebp
0049cdd9 mov ebp, esp
0049cddb add esp, -0x3c
0049cdde mov dword ptr [ebp - 8], edx
0049cde1 mov dword ptr [ebp - 4], eax
0049cde4 fld dword ptr [0x49cf54]
0049cdea fsub qword ptr [ebp + 8]
0049cded fstp qword ptr [ebp - 0x18]
0049cdf0 mov dword ptr [ebp - 0x30], 1
0049cdf7 jmp 0x49cf36
0049cdfc mov dword ptr [ebp - 0x34], 1
0049ce03 jmp 0x49cf1b
0049ce08 mov eax, dword ptr [ebp - 0x30]
0049ce0b mov edx, dword ptr [ebp - 4]
0049ce0e mov ecx, dword ptr [edx + eax*4 + 0x339e8]
0049ce15 mov eax, dword ptr [ebp - 0x34]
0049ce18 mov edx, dword ptr [ecx + eax*4]
0049ce1b mov dword ptr [ebp - 0xc], edx
0049ce1e mov ecx, dword ptr [ebp - 4]
0049ce21 mov eax, dword ptr [ecx + 0x32d50]
0049ce27 mov dword ptr [ebp - 0x10], eax
0049ce2a xor edx, edx
0049ce2c mov dl, byte ptr [ebp - 0xc]
0049ce2f mov dword ptr [ebp - 0x38], edx
0049ce32 fild dword ptr [ebp - 0x38]
0049ce35 fmul qword ptr [ebp + 8]
0049ce38 fadd dword ptr [0x49cf58]
0049ce3e xor ecx, ecx
0049ce40 mov cl, byte ptr [ebp - 0xe]
0049ce43 mov dword ptr [ebp - 0x3c], ecx
0049ce46 fild dword ptr [ebp - 0x3c]
0049ce49 fmul qword ptr [ebp - 0x18]
0049ce4c fadd dword ptr [0x49cf58]
0049ce52 faddp st(1)
0049ce54 call 0x5394fc
0049ce59 mov dword ptr [ebp - 0x1c], eax
0049ce5c xor edx, edx
0049ce5e mov dl, byte ptr [ebp - 0xb]
0049ce61 mov dword ptr [ebp - 0x38], edx
0049ce64 fild dword ptr [ebp - 0x38]
0049ce67 fmul qword ptr [ebp + 8]
0049ce6a fadd dword ptr [0x49cf58]
0049ce70 xor ecx, ecx
0049ce72 mov cl, byte ptr [ebp - 0xf]
0049ce75 mov dword ptr [ebp - 0x3c], ecx
0049ce78 fild dword ptr [ebp - 0x3c]
0049ce7b fmul qword ptr [ebp - 0x18]
0049ce7e fadd dword ptr [0x49cf58]
0049ce84 faddp st(1)
0049ce86 call 0x5394fc
0049ce8b mov dword ptr [ebp - 0x20], eax
0049ce8e xor edx, edx
0049ce90 mov dl, byte ptr [ebp - 0xa]
0049ce93 mov dword ptr [ebp - 0x38], edx
0049ce96 fild dword ptr [ebp - 0x38]
0049ce99 fmul qword ptr [ebp + 8]
0049ce9c fadd dword ptr [0x49cf58]
0049cea2 xor ecx, ecx
0049cea4 mov cl, byte ptr [ebp - 0x10]
0049cea7 mov dword ptr [ebp - 0x3c], ecx
0049ceaa fild dword ptr [ebp - 0x3c]
0049cead fmul qword ptr [ebp - 0x18]
0049ceb0 fadd dword ptr [0x49cf58]
0049ceb6 faddp st(1)
0049ceb8 call 0x5394fc
0049cebd mov dword ptr [ebp - 0x24], eax
0049cec0 cmp dword ptr [ebp - 0x1c], 0xff
0049cec7 jle 0x49ced0
0049cec9 mov dword ptr [ebp - 0x1c], 0xff
0049ced0 cmp dword ptr [ebp - 0x20], 0xff
0049ced7 jle 0x49cee0
0049ced9 mov dword ptr [ebp - 0x20], 0xff
0049cee0 cmp dword ptr [ebp - 0x24], 0xff
0049cee7 jle 0x49cef0
0049cee9 mov dword ptr [ebp - 0x24], 0xff
0049cef0 mov dl, byte ptr [ebp - 0x1c]
0049cef3 mov byte ptr [ebp - 0xc], dl
0049cef6 mov cl, byte ptr [ebp - 0x20]
0049cef9 mov byte ptr [ebp - 0xb], cl
0049cefc mov al, byte ptr [ebp - 0x24]
0049ceff mov byte ptr [ebp - 0xa], al
0049cf02 mov edx, dword ptr [ebp - 0x30]
0049cf05 mov ecx, dword ptr [ebp - 4]
0049cf08 mov eax, dword ptr [ecx + edx*4 + 0x339e8]
0049cf0f mov edx, dword ptr [ebp - 0x34]
0049cf12 mov ecx, dword ptr [ebp - 0xc]
0049cf15 mov dword ptr [eax + edx*4], ecx
0049cf18 inc dword ptr [ebp - 0x34]
0049cf1b mov eax, dword ptr [ebp - 4]
0049cf1e mov eax, dword ptr [eax + 0x34678]
0049cf24 mov edx, dword ptr [eax]
0049cf26 call dword ptr [edx + 0x2c]
0049cf29 dec eax
0049cf2a cmp eax, dword ptr [ebp - 0x34]
0049cf2d jg 0x49ce08
0049cf33 inc dword ptr [ebp - 0x30]
0049cf36 mov ecx, dword ptr [ebp - 4]
0049cf39 mov eax, dword ptr [ecx + 0x34678]
0049cf3f mov edx, dword ptr [eax]
0049cf41 call dword ptr [edx + 0x20]
0049cf44 dec eax
0049cf45 cmp eax, dword ptr [ebp - 0x30]
0049cf48 jg 0x49cdfc
0049cf4e mov esp, ebp
0049cf50 pop ebp
0049cf51 ret 8
0049cf54 add byte ptr [eax], al
0049cf56 cmp byte ptr [edi], 0
0049cf59 add byte ptr [eax], al
0049cf5b aas 
0049cf5c pushal 
0049cf5d iretd 
0049cf5e dec ecx
0049cf5f add byte ptr [edi], al
0049cf61 or byte ptr [esp + eax*2 + 0x65], dl
0049cf65 jo 0x49cfd6
0049cf67 jae 0x49cfd2
0049cf69 je 0x49cf4f
0049cf6b je 0x49cfc3
0049cf6d add byte ptr [eax], dh
0049cf6f clc 
0049cf70 push edx
0049cf71 add byte ptr [eax], al
0049cf73 add byte ptr [ebx], al
0049cf75 jo 0x49cfe0
0049cf77 arpl word ptr [eax], ax
0049cf79 add byte ptr [eax + 0x49cf8090], dl
0049cf7f add byte ptr [edi], al
0049cf81 push es
0049cf82 push esp
0049cf83 inc edx
0049cf84 jne 0x49cfe8
0049cf86 insb byte ptr es:[edi], dx
0049cf87 cmp al, 0x75
0049cf8a push esi
0049cf8b add byte ptr [eax], dh
0049cf8d clc 
0049cf8e push edx
0049cf8f add byte ptr [eax], al
0049cf91 add byte ptr [ebx], al
0049cf93 jo 0x49cffe
0049cf95 arpl word ptr [eax], ax
