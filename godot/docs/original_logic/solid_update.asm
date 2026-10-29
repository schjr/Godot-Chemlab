0049c298 push ebp
0049c299 mov ebp, esp
0049c29b add esp, -0x24
0049c29e push ebx
0049c29f push esi
0049c2a0 push edi
0049c2a1 mov dword ptr [ebp - 4], eax
0049c2a4 mov eax, dword ptr [ebp - 4]
0049c2a7 cmp byte ptr [eax + 0x34680], 0
0049c2ae jne 0x49c5de
0049c2b4 xor edx, edx
0049c2b6 mov dword ptr [ebp - 8], edx
0049c2b9 jmp 0x49c314
0049c2bb imul ecx, dword ptr [ebp - 8], 0xd
0049c2bf mov eax, dword ptr [ebp - 4]
0049c2c2 fld dword ptr [eax + ecx*4 + 0x18]
0049c2c6 fcomp dword ptr [0x49c5e8]
0049c2cc fnstsw ax
0049c2ce sahf 
0049c2cf ja 0x49c311
0049c2d1 mov edx, dword ptr [ebp - 8]
0049c2d4 mov dword ptr [ebp - 0xc], edx
0049c2d7 jmp 0x49c2f9
0049c2d9 imul ecx, dword ptr [ebp - 0xc], 0xd
0049c2dd mov eax, dword ptr [ebp - 4]
0049c2e0 imul edx, dword ptr [ebp - 0xc], 0xd
0049c2e4 mov ebx, dword ptr [ebp - 4]
0049c2e7 lea esi, [eax + ecx*4 + 0x38]
0049c2eb lea edi, [ebx + edx*4 + 4]
0049c2ef mov ecx, 0xd
0049c2f4 rep movsd dword ptr es:[edi], dword ptr [esi]
0049c2f6 inc dword ptr [ebp - 0xc]
0049c2f9 mov eax, dword ptr [ebp - 4]
0049c2fc mov edx, dword ptr [eax + 0x34684]
0049c302 dec edx
0049c303 cmp edx, dword ptr [ebp - 0xc]
0049c306 jg 0x49c2d9
0049c308 mov ecx, dword ptr [ebp - 4]
0049c30b dec dword ptr [ecx + 0x34684]
0049c311 inc dword ptr [ebp - 8]
0049c314 mov eax, dword ptr [ebp - 8]
0049c317 mov edx, dword ptr [ebp - 4]
0049c31a cmp eax, dword ptr [edx + 0x34684]
0049c320 jl 0x49c2bb
0049c322 xor ecx, ecx
0049c324 mov dword ptr [ebp - 0x10], ecx
0049c327 jmp 0x49c5cc
0049c32c imul eax, dword ptr [ebp - 0x10], 0xd
0049c330 mov edx, dword ptr [ebp - 4]
0049c333 fld dword ptr [edx + eax*4 + 0xc]
0049c337 add esp, -8
0049c33a fstp qword ptr [esp]
0049c33d call 0x539238
0049c342 add esp, 8
0049c345 imul ecx, dword ptr [ebp - 0x10], 0xd
0049c349 mov eax, dword ptr [ebp - 4]
0049c34c fmul dword ptr [eax + ecx*4 + 0x10]
0049c350 imul edx, dword ptr [ebp - 0x10], 0xd
0049c354 mov ecx, dword ptr [ebp - 4]
0049c357 fadd dword ptr [ecx + edx*4 + 4]
0049c35b fstp dword ptr [ecx + edx*4 + 4]
0049c35f imul eax, dword ptr [ebp - 0x10], 0xd
0049c363 mov edx, dword ptr [ebp - 4]
0049c366 fld dword ptr [edx + eax*4 + 0xc]
0049c36a add esp, -8
0049c36d fstp qword ptr [esp]
0049c370 call 0x53aca8
0049c375 add esp, 8
0049c378 imul ecx, dword ptr [ebp - 0x10], 0xd
0049c37c mov eax, dword ptr [ebp - 4]
0049c37f fmul dword ptr [eax + ecx*4 + 0x10]
0049c383 imul edx, dword ptr [ebp - 0x10], 0xd
0049c387 mov ecx, dword ptr [ebp - 4]
0049c38a fsubr dword ptr [ecx + edx*4 + 8]
0049c38e fstp dword ptr [ecx + edx*4 + 8]
0049c392 imul eax, dword ptr [ebp - 0x10], 0xd
0049c396 mov edx, dword ptr [ebp - 4]
0049c399 fld dword ptr [edx + eax*4 + 0x14]
0049c39d imul ecx, dword ptr [ebp - 0x10], 0xd
0049c3a1 mov eax, dword ptr [ebp - 4]
0049c3a4 fadd dword ptr [eax + ecx*4 + 0xc]
0049c3a8 fstp dword ptr [eax + ecx*4 + 0xc]
0049c3ac imul edx, dword ptr [ebp - 0x10], 0xd
0049c3b0 mov ecx, dword ptr [ebp - 4]
0049c3b3 fld dword ptr [ecx + edx*4 + 0x1c]
0049c3b7 imul eax, dword ptr [ebp - 0x10], 0xd
0049c3bb mov edx, dword ptr [ebp - 4]
0049c3be fsubr dword ptr [edx + eax*4 + 0x18]
0049c3c2 fstp dword ptr [edx + eax*4 + 0x18]
0049c3c6 push 5
0049c3c8 call 0x4028ec
0049c3cd pop ecx
0049c3ce mov dword ptr [ebp - 0x20], eax
0049c3d1 fild dword ptr [ebp - 0x20]
0049c3d4 fld xword ptr [0x49c5ec]
0049c3da fmulp st(1)
0049c3dc imul ecx, dword ptr [ebp - 0x10], 0xd
0049c3e0 mov eax, dword ptr [ebp - 4]
0049c3e3 fadd dword ptr [eax + ecx*4 + 8]
0049c3e7 imul edx, dword ptr [ebp - 0x10], 0xd
0049c3eb mov ecx, dword ptr [ebp - 4]
0049c3ee fstp dword ptr [ecx + edx*4 + 8]
0049c3f2 imul eax, dword ptr [ebp - 0x10], 0xd
0049c3f6 mov edx, dword ptr [ebp - 4]
0049c3f9 fld dword ptr [edx + eax*4 + 4]
0049c3fd fsub dword ptr [0x49c5f8]
0049c403 fcomp dword ptr [0x49c5e8]
0049c409 fnstsw ax
0049c40b sahf 
0049c40c jae 0x49c42a
0049c40e fld qword ptr [0x49c5fc]
0049c414 imul edx, dword ptr [ebp - 0x10], 0xd
0049c418 mov ecx, dword ptr [ebp - 4]
0049c41b fsub dword ptr [ecx + edx*4 + 0xc]
0049c41f imul eax, dword ptr [ebp - 0x10], 0xd
0049c423 mov edx, dword ptr [ebp - 4]
0049c426 fstp dword ptr [edx + eax*4 + 0xc]
0049c42a mov ecx, dword ptr [ebp - 4]
0049c42d mov eax, dword ptr [ecx + 0x34678]
0049c433 mov edx, dword ptr [eax]
0049c435 call dword ptr [edx + 0x20]
0049c438 dec eax
0049c439 mov dword ptr [ebp - 0x20], eax
0049c43c fild dword ptr [ebp - 0x20]
0049c43f imul ecx, dword ptr [ebp - 0x10], 0xd
0049c443 mov eax, dword ptr [ebp - 4]
0049c446 fcomp dword ptr [eax + ecx*4 + 8]
0049c44a fnstsw ax
0049c44c sahf 
0049c44d jae 0x49c46b
0049c44f fld qword ptr [0x49c604]
0049c455 imul edx, dword ptr [ebp - 0x10], 0xd
0049c459 mov ecx, dword ptr [ebp - 4]
0049c45c fadd dword ptr [ecx + edx*4 + 0xc]
0049c460 imul eax, dword ptr [ebp - 0x10], 0xd
0049c464 mov edx, dword ptr [ebp - 4]
0049c467 fstp dword ptr [edx + eax*4 + 0xc]
0049c46b mov ecx, dword ptr [ebp - 4]
0049c46e mov eax, dword ptr [ecx + 0x34678]
0049c474 mov edx, dword ptr [eax]
0049c476 call dword ptr [edx + 0x2c]
0049c479 mov dword ptr [ebp - 0x20], eax
0049c47c fild dword ptr [ebp - 0x20]
0049c47f imul ecx, dword ptr [ebp - 0x10], 0xd
0049c483 mov eax, dword ptr [ebp - 4]
0049c486 fld dword ptr [eax + ecx*4 + 4]
0049c48a fadd dword ptr [0x49c5f8]
0049c490 fcompp 
0049c492 fnstsw ax
0049c494 sahf 
0049c495 jbe 0x49c4b3
0049c497 fld qword ptr [0x49c5fc]
0049c49d imul edx, dword ptr [ebp - 0x10], 0xd
0049c4a1 mov ecx, dword ptr [ebp - 4]
0049c4a4 fsub dword ptr [ecx + edx*4 + 0xc]
0049c4a8 imul eax, dword ptr [ebp - 0x10], 0xd
0049c4ac mov edx, dword ptr [ebp - 4]
0049c4af fstp dword ptr [edx + eax*4 + 0xc]
0049c4b3 imul ecx, dword ptr [ebp - 0x10], 0xd
0049c4b7 mov eax, dword ptr [ebp - 4]
0049c4ba fld dword ptr [eax + ecx*4 + 8]
0049c4be fcomp dword ptr [0x49c5f8]
0049c4c4 fnstsw ax
0049c4c6 sahf 
0049c4c7 jae 0x49c4e5
0049c4c9 fld qword ptr [0x49c604]
0049c4cf imul edx, dword ptr [ebp - 0x10], 0xd
0049c4d3 mov ecx, dword ptr [ebp - 4]
0049c4d6 fadd dword ptr [ecx + edx*4 + 0xc]
0049c4da imul eax, dword ptr [ebp - 0x10], 0xd
0049c4de mov edx, dword ptr [ebp - 4]
0049c4e1 fstp dword ptr [edx + eax*4 + 0xc]
0049c4e5 mov dword ptr [ebp - 0x14], 1
0049c4ec imul ecx, dword ptr [ebp - 0x10], 0xd
0049c4f0 mov eax, dword ptr [ebp - 4]
0049c4f3 mov edx, dword ptr [eax + ecx*4 + 0x20]
0049c4f7 mov dword ptr [ebp - 0x18], edx
0049c4fa mov ecx, dword ptr [ebp - 4]
0049c4fd mov eax, dword ptr [ecx + 0x32d50]
0049c503 mov dword ptr [ebp - 0x1c], eax
0049c506 xor edx, edx
0049c508 mov dl, byte ptr [ebp - 0x18]
0049c50b mov dword ptr [ebp - 0x20], edx
0049c50e fild dword ptr [ebp - 0x20]
0049c511 xor ecx, ecx
0049c513 mov cl, byte ptr [ebp - 0x1c]
0049c516 xor eax, eax
0049c518 mov al, byte ptr [ebp - 0x18]
0049c51b sub ecx, eax
0049c51d imul ecx, dword ptr [ebp - 0x14]
0049c521 mov dword ptr [ebp - 0x24], ecx
0049c524 fild dword ptr [ebp - 0x24]
0049c527 fld xword ptr [0x49c60c]
0049c52d fmulp st(1)
0049c52f faddp st(1)
0049c531 call 0x5394fc
0049c536 mov byte ptr [ebp - 0x18], al
0049c539 xor edx, edx
0049c53b mov dl, byte ptr [ebp - 0x17]
0049c53e mov dword ptr [ebp - 0x20], edx
0049c541 fild dword ptr [ebp - 0x20]
0049c544 xor ecx, ecx
0049c546 mov cl, byte ptr [ebp - 0x1b]
0049c549 xor eax, eax
0049c54b mov al, byte ptr [ebp - 0x17]
0049c54e sub ecx, eax
0049c550 imul ecx, dword ptr [ebp - 0x14]
0049c554 mov dword ptr [ebp - 0x24], ecx
0049c557 fild dword ptr [ebp - 0x24]
0049c55a fld xword ptr [0x49c60c]
0049c560 fmulp st(1)
0049c562 faddp st(1)
0049c564 call 0x5394fc
0049c569 mov byte ptr [ebp - 0x17], al
0049c56c xor edx, edx
0049c56e mov dl, byte ptr [ebp - 0x16]
0049c571 mov dword ptr [ebp - 0x20], edx
0049c574 fild dword ptr [ebp - 0x20]
0049c577 xor ecx, ecx
0049c579 mov cl, byte ptr [ebp - 0x1a]
0049c57c xor eax, eax
0049c57e mov al, byte ptr [ebp - 0x16]
0049c581 sub ecx, eax
0049c583 imul ecx, dword ptr [ebp - 0x14]
0049c587 mov dword ptr [ebp - 0x24], ecx
0049c58a fild dword ptr [ebp - 0x24]
0049c58d fld xword ptr [0x49c60c]
0049c593 fmulp st(1)
0049c595 faddp st(1)
0049c597 call 0x5394fc
0049c59c mov byte ptr [ebp - 0x16], al
0049c59f imul edx, dword ptr [ebp - 0x10], 0xd
0049c5a3 mov ecx, dword ptr [ebp - 4]
0049c5a6 mov eax, dword ptr [ebp - 0x18]
0049c5a9 mov dword ptr [ecx + edx*4 + 0x20], eax
0049c5ad imul edx, dword ptr [ebp - 0x10], 0xd
0049c5b1 mov ecx, dword ptr [ebp - 4]
0049c5b4 fld dword ptr [ecx + edx*4 + 0x30]
0049c5b8 fadd qword ptr [0x49c618]
0049c5be imul eax, dword ptr [ebp - 0x10], 0xd
0049c5c2 mov edx, dword ptr [ebp - 4]
0049c5c5 fstp dword ptr [edx + eax*4 + 0x30]
0049c5c9 inc dword ptr [ebp - 0x10]
0049c5cc mov ecx, dword ptr [ebp - 0x10]
0049c5cf mov eax, dword ptr [ebp - 4]
0049c5d2 cmp ecx, dword ptr [eax + 0x34684]
0049c5d8 jl 0x49c32c
0049c5de pop edi
0049c5df pop esi
0049c5e0 pop ebx
0049c5e1 mov esp, ebp
0049c5e3 pop ebp
0049c5e4 ret 
0049c5e5 add byte ptr [eax], al
0049c5e7 add byte ptr [eax], al
0049c5e9 add byte ptr [eax], al
