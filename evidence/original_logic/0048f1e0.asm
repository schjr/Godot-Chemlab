0048f1e0 push ebp
0048f1e1 mov ebp, esp
0048f1e3 add esp, 0xfffff164
0048f1e9 fld dword ptr [ebp + 0x10]
0048f1ec fcomp qword ptr [0x48f5f4]
0048f1f2 fnstsw ax
0048f1f4 sahf 
0048f1f5 jbe 0x48f205
0048f1f7 fld dword ptr [ebp + 0x10]
0048f1fa fcomp dword ptr [0x48f5fc]
0048f200 fnstsw ax
0048f202 sahf 
0048f203 jbe 0x48f20f
0048f205 mov eax, 1
0048f20a jmp 0x48f5ee
0048f20f mov eax, dword ptr [ebp + 8]
0048f212 mov edx, dword ptr [eax]
0048f214 call dword ptr [edx + 0x20]
0048f217 cmp eax, 0x12c
0048f21c jle 0x48f228
0048f21e mov eax, 1
0048f223 jmp 0x48f5ee
0048f228 mov dl, 7
0048f22a mov eax, dword ptr [ebp + 8]
0048f22d call 0x4ea36c
0048f232 mov dl, 7
0048f234 mov eax, dword ptr [ebp + 0xc]
0048f237 call 0x4ea36c
0048f23c mov eax, dword ptr [ebp + 8]
0048f23f mov edx, dword ptr [eax]
0048f241 call dword ptr [edx + 0x20]
0048f244 mov dword ptr [ebp - 0xe90], eax
0048f24a fild dword ptr [ebp - 0xe90]
0048f250 fmul dword ptr [ebp + 0x10]
0048f253 call 0x5394fc
0048f258 mov edx, eax
0048f25a mov eax, dword ptr [ebp + 0xc]
0048f25d mov ecx, dword ptr [eax]
0048f25f call dword ptr [ecx + 0x34]
0048f262 mov eax, dword ptr [ebp + 8]
0048f265 mov edx, dword ptr [eax]
0048f267 call dword ptr [edx + 0x2c]
0048f26a mov dword ptr [ebp - 0xe90], eax
0048f270 fild dword ptr [ebp - 0xe90]
0048f276 fmul dword ptr [ebp + 0x10]
0048f279 call 0x5394fc
0048f27e mov edx, eax
0048f280 mov eax, dword ptr [ebp + 0xc]
0048f283 mov ecx, dword ptr [eax]
0048f285 call dword ptr [ecx + 0x40]
0048f288 mov eax, dword ptr [ebp + 0xc]
0048f28b call 0x4e9448
0048f290 mov eax, dword ptr [eax + 0x10]
0048f293 mov edx, 0xffffff
0048f298 call 0x4e3e50
0048f29d mov eax, dword ptr [ebp + 0xc]
0048f2a0 call 0x4e9448
0048f2a5 mov eax, dword ptr [eax + 0x14]
0048f2a8 mov edx, 0xffffff
0048f2ad call 0x4e4158
0048f2b2 mov eax, dword ptr [ebp + 0xc]
0048f2b5 call 0x4e9448
0048f2ba mov eax, dword ptr [eax + 0x14]
0048f2bd xor edx, edx
0048f2bf call 0x4e4274
0048f2c4 mov eax, dword ptr [ebp + 0xc]
0048f2c7 mov edx, dword ptr [eax]
0048f2c9 call dword ptr [edx + 0x2c]
0048f2cc push eax
0048f2cd mov eax, dword ptr [ebp + 0xc]
0048f2d0 mov edx, dword ptr [eax]
0048f2d2 call dword ptr [edx + 0x20]
0048f2d5 push eax
0048f2d6 mov eax, dword ptr [ebp + 0xc]
0048f2d9 call 0x4e9448
0048f2de xor ecx, ecx
0048f2e0 xor edx, edx
0048f2e2 call 0x4e4744
0048f2e7 xor eax, eax
0048f2e9 mov dword ptr [ebp - 0x70], eax
0048f2ec jmp 0x48f306
0048f2ee mov edx, dword ptr [ebp - 0x70]
0048f2f1 mov eax, dword ptr [ebp + 8]
0048f2f4 call 0x4e95b0
0048f2f9 mov edx, dword ptr [ebp - 0x70]
0048f2fc mov dword ptr [ebp + edx*4 - 0x52c], eax
0048f303 inc dword ptr [ebp - 0x70]
0048f306 mov eax, dword ptr [ebp + 8]
0048f309 mov edx, dword ptr [eax]
0048f30b call dword ptr [edx + 0x20]
0048f30e cmp eax, dword ptr [ebp - 0x70]
0048f311 jg 0x48f2ee
0048f313 xor ecx, ecx
0048f315 mov dword ptr [ebp - 0x74], ecx
0048f318 jmp 0x48f332
0048f31a mov edx, dword ptr [ebp - 0x74]
0048f31d mov eax, dword ptr [ebp + 0xc]
0048f320 call 0x4e95b0
0048f325 mov ecx, dword ptr [ebp - 0x74]
0048f328 mov dword ptr [ebp + ecx*4 - 0xe8c], eax
0048f32f inc dword ptr [ebp - 0x74]
0048f332 mov eax, dword ptr [ebp + 0xc]
0048f335 mov edx, dword ptr [eax]
0048f337 call dword ptr [edx + 0x20]
0048f33a cmp eax, dword ptr [ebp - 0x74]
0048f33d jg 0x48f31a
0048f33f xor ecx, ecx
0048f341 mov dword ptr [ebp - 0x78], ecx
0048f344 jmp 0x48f5db
0048f349 xor eax, eax
0048f34b mov dword ptr [ebp - 0x7c], eax
0048f34e jmp 0x48f5c7
0048f353 fild dword ptr [ebp - 0x7c]
0048f356 fdiv dword ptr [ebp + 0x10]
0048f359 fstp dword ptr [ebp - 0x58]
0048f35c fild dword ptr [ebp - 0x78]
0048f35f fdiv dword ptr [ebp + 0x10]
0048f362 fstp dword ptr [ebp - 0x5c]
0048f365 fld dword ptr [ebp - 0x58]
0048f368 call 0x5394fc
0048f36d mov dword ptr [ebp - 0x60], eax
0048f370 fld dword ptr [ebp - 0x58]
0048f373 fadd dword ptr [0x48f600]
0048f379 call 0x5394fc
0048f37e mov dword ptr [ebp - 0x68], eax
0048f381 fld dword ptr [ebp - 0x5c]
0048f384 call 0x5394fc
0048f389 mov dword ptr [ebp - 0x64], eax
0048f38c fld dword ptr [ebp - 0x5c]
0048f38f fadd dword ptr [0x48f600]
0048f395 call 0x5394fc
0048f39a mov dword ptr [ebp - 0x6c], eax
0048f39d fild dword ptr [ebp - 0x6c]
0048f3a0 fsub dword ptr [ebp - 0x5c]
0048f3a3 fstp qword ptr [ebp - 0x1c]
0048f3a6 fild dword ptr [ebp - 0x68]
0048f3a9 fsub dword ptr [ebp - 0x58]
0048f3ac fstp qword ptr [ebp - 0x24]
0048f3af fild dword ptr [ebp - 0x60]
0048f3b2 fsubr dword ptr [ebp - 0x58]
0048f3b5 fstp qword ptr [ebp - 0x2c]
0048f3b8 fild dword ptr [ebp - 0x64]
0048f3bb fsubr dword ptr [ebp - 0x5c]
0048f3be fstp qword ptr [ebp - 0x34]
0048f3c1 fld qword ptr [ebp - 0x1c]
0048f3c4 fmul qword ptr [ebp - 0x24]
0048f3c7 fstp qword ptr [ebp - 0x3c]
0048f3ca fld qword ptr [ebp - 0x1c]
0048f3cd fmul qword ptr [ebp - 0x2c]
0048f3d0 fstp qword ptr [ebp - 0x44]
0048f3d3 fld qword ptr [ebp - 0x34]
0048f3d6 fmul qword ptr [ebp - 0x24]
0048f3d9 fstp qword ptr [ebp - 0x4c]
0048f3dc fld qword ptr [ebp - 0x34]
0048f3df fmul qword ptr [ebp - 0x2c]
0048f3e2 fstp qword ptr [ebp - 0x54]
0048f3e5 mov eax, dword ptr [ebp + 8]
0048f3e8 mov edx, dword ptr [eax]
0048f3ea call dword ptr [edx + 0x20]
0048f3ed dec eax
0048f3ee cmp eax, dword ptr [ebp - 0x6c]
0048f3f1 jge 0x48f418
0048f3f3 mov ecx, dword ptr [ebp - 0x64]
0048f3f6 mov eax, dword ptr [ebp + ecx*4 - 0x52c]
0048f3fd mov edx, dword ptr [ebp - 0x60]
0048f400 mov ecx, dword ptr [eax + edx*4]
0048f403 mov eax, dword ptr [ebp - 0x78]
0048f406 mov edx, dword ptr [ebp + eax*4 - 0xe8c]
0048f40d mov eax, dword ptr [ebp - 0x7c]
0048f410 mov dword ptr [edx + eax*4], ecx
0048f413 jmp 0x48f5c4
0048f418 mov eax, dword ptr [ebp + 8]
0048f41b mov edx, dword ptr [eax]
0048f41d call dword ptr [edx + 0x2c]
0048f420 dec eax
0048f421 cmp eax, dword ptr [ebp - 0x68]
0048f424 jge 0x48f44b
0048f426 mov ecx, dword ptr [ebp - 0x64]
0048f429 mov eax, dword ptr [ebp + ecx*4 - 0x52c]
0048f430 mov edx, dword ptr [ebp - 0x60]
0048f433 mov ecx, dword ptr [eax + edx*4]
0048f436 mov eax, dword ptr [ebp - 0x78]
0048f439 mov edx, dword ptr [ebp + eax*4 - 0xe8c]
0048f440 mov eax, dword ptr [ebp - 0x7c]
0048f443 mov dword ptr [edx + eax*4], ecx
0048f446 jmp 0x48f5c4
0048f44b mov edx, dword ptr [ebp - 0x64]
0048f44e mov ecx, dword ptr [ebp + edx*4 - 0x52c]
0048f455 mov eax, dword ptr [ebp - 0x60]
0048f458 mov edx, dword ptr [ecx + eax*4]
0048f45b mov dword ptr [ebp - 4], edx
0048f45e mov ecx, dword ptr [ebp - 0x64]
0048f461 mov eax, dword ptr [ebp + ecx*4 - 0x52c]
0048f468 mov edx, dword ptr [ebp - 0x68]
0048f46b mov ecx, dword ptr [eax + edx*4]
0048f46e mov dword ptr [ebp - 8], ecx
0048f471 mov eax, dword ptr [ebp - 0x6c]
0048f474 mov edx, dword ptr [ebp + eax*4 - 0x52c]
0048f47b mov ecx, dword ptr [ebp - 0x60]
0048f47e mov eax, dword ptr [edx + ecx*4]
0048f481 mov dword ptr [ebp - 0xc], eax
0048f484 mov edx, dword ptr [ebp - 0x6c]
0048f487 mov ecx, dword ptr [ebp + edx*4 - 0x52c]
0048f48e mov eax, dword ptr [ebp - 0x68]
0048f491 mov edx, dword ptr [ecx + eax*4]
0048f494 mov dword ptr [ebp - 0x10], edx
0048f497 xor ecx, ecx
0048f499 mov cl, byte ptr [ebp - 4]
0048f49c mov dword ptr [ebp - 0xe90], ecx
0048f4a2 fild dword ptr [ebp - 0xe90]
0048f4a8 fmul qword ptr [ebp - 0x3c]
0048f4ab xor eax, eax
0048f4ad mov al, byte ptr [ebp - 8]
0048f4b0 mov dword ptr [ebp - 0xe94], eax
0048f4b6 fild dword ptr [ebp - 0xe94]
0048f4bc fmul qword ptr [ebp - 0x44]
0048f4bf faddp st(1)
0048f4c1 xor edx, edx
0048f4c3 mov dl, byte ptr [ebp - 0xc]
0048f4c6 mov dword ptr [ebp - 0xe98], edx
0048f4cc fild dword ptr [ebp - 0xe98]
0048f4d2 fmul qword ptr [ebp - 0x4c]
0048f4d5 faddp st(1)
0048f4d7 xor ecx, ecx
0048f4d9 mov cl, byte ptr [ebp - 0x10]
0048f4dc mov dword ptr [ebp - 0xe9c], ecx
0048f4e2 fild dword ptr [ebp - 0xe9c]
0048f4e8 fmul qword ptr [ebp - 0x54]
0048f4eb faddp st(1)
0048f4ed call 0x5394fc
0048f4f2 mov byte ptr [ebp - 0x14], al
0048f4f5 xor edx, edx
0048f4f7 mov dl, byte ptr [ebp - 3]
0048f4fa mov dword ptr [ebp - 0xe90], edx
0048f500 fild dword ptr [ebp - 0xe90]
0048f506 fmul qword ptr [ebp - 0x3c]
0048f509 xor ecx, ecx
0048f50b mov cl, byte ptr [ebp - 7]
0048f50e mov dword ptr [ebp - 0xe94], ecx
0048f514 fild dword ptr [ebp - 0xe94]
0048f51a fmul qword ptr [ebp - 0x44]
0048f51d faddp st(1)
0048f51f xor eax, eax
0048f521 mov al, byte ptr [ebp - 0xb]
0048f524 mov dword ptr [ebp - 0xe98], eax
0048f52a fild dword ptr [ebp - 0xe98]
0048f530 fmul qword ptr [ebp - 0x4c]
0048f533 faddp st(1)
0048f535 xor edx, edx
0048f537 mov dl, byte ptr [ebp - 0xf]
0048f53a mov dword ptr [ebp - 0xe9c], edx
0048f540 fild dword ptr [ebp - 0xe9c]
0048f546 fmul qword ptr [ebp - 0x54]
0048f549 faddp st(1)
0048f54b call 0x5394fc
0048f550 mov byte ptr [ebp - 0x13], al
0048f553 xor edx, edx
0048f555 mov dl, byte ptr [ebp - 2]
0048f558 mov dword ptr [ebp - 0xe90], edx
0048f55e fild dword ptr [ebp - 0xe90]
0048f564 fmul qword ptr [ebp - 0x3c]
0048f567 xor ecx, ecx
0048f569 mov cl, byte ptr [ebp - 6]
0048f56c mov dword ptr [ebp - 0xe94], ecx
0048f572 fild dword ptr [ebp - 0xe94]
0048f578 fmul qword ptr [ebp - 0x44]
0048f57b faddp st(1)
0048f57d xor eax, eax
0048f57f mov al, byte ptr [ebp - 0xa]
0048f582 mov dword ptr [ebp - 0xe98], eax
0048f588 fild dword ptr [ebp - 0xe98]
0048f58e fmul qword ptr [ebp - 0x4c]
0048f591 faddp st(1)
0048f593 xor edx, edx
0048f595 mov dl, byte ptr [ebp - 0xe]
0048f598 mov dword ptr [ebp - 0xe9c], edx
0048f59e fild dword ptr [ebp - 0xe9c]
0048f5a4 fmul qword ptr [ebp - 0x54]
0048f5a7 faddp st(1)
0048f5a9 call 0x5394fc
0048f5ae mov byte ptr [ebp - 0x12], al
0048f5b1 mov edx, dword ptr [ebp - 0x78]
0048f5b4 mov ecx, dword ptr [ebp + edx*4 - 0xe8c]
0048f5bb mov eax, dword ptr [ebp - 0x7c]
0048f5be mov edx, dword ptr [ebp - 0x14]
0048f5c1 mov dword ptr [ecx + eax*4], edx
0048f5c4 inc dword ptr [ebp - 0x7c]
0048f5c7 mov eax, dword ptr [ebp + 0xc]
0048f5ca mov edx, dword ptr [eax]
0048f5cc call dword ptr [edx + 0x2c]
0048f5cf cmp eax, dword ptr [ebp - 0x7c]
0048f5d2 jg 0x48f353
0048f5d8 inc dword ptr [ebp - 0x78]
0048f5db mov eax, dword ptr [ebp + 0xc]
0048f5de mov edx, dword ptr [eax]
0048f5e0 call dword ptr [edx + 0x20]
0048f5e3 cmp eax, dword ptr [ebp - 0x78]
0048f5e6 jg 0x48f349
0048f5ec xor eax, eax
0048f5ee mov esp, ebp
0048f5f0 pop ebp
0048f5f1 ret 
0048f5f2 add byte ptr [eax], al
0048f5f4 lcall 0xb999, 0x99999999
0048f5fb aas 
0048f5fc add byte ptr [eax], al
0048f5fe add byte ptr [eax], 0
