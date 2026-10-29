0047268f and byte ptr [0xc9de0047], ch
00472695 fmul dword ptr [0x472d2c]
0047269b call 0x5394fc
004726a0 mov byte ptr [ebp - 0xa6], al
004726a6 mov edx, dword ptr [ebp + 0xc]
004726a9 mov ecx, dword ptr [edx*4 + 0x585850]
004726b0 mov eax, dword ptr [ebp - 0xa4]
004726b6 mov dword ptr [ecx + 0x3cd0], eax
004726bc mov eax, dword ptr [ebp + 8]
004726bf call 0x4e9448
004726c4 mov eax, dword ptr [eax + 0x14]
004726c7 mov edx, dword ptr [ebp - 0xa4]
004726cd call 0x4e4158
004726d2 mov eax, dword ptr [ebp + 8]
004726d5 call 0x4e9448
004726da mov eax, dword ptr [eax + 0x10]
004726dd mov edx, dword ptr [ebp - 0xa8]
004726e3 call 0x4e3e50
004726e8 mov eax, dword ptr [ebp + 8]
004726eb call 0x4e9448
004726f0 mov eax, dword ptr [eax + 0x14]
004726f3 xor edx, edx
004726f5 call 0x4e4274
004726fa fld qword ptr [ebp - 0x64]
004726fd mov ecx, dword ptr [ebp + 0xc]
00472700 mov eax, dword ptr [ecx*4 + 0x585850]
00472707 fcomp qword ptr [eax + 0x28]
0047270a fnstsw ax
0047270c sahf 
0047270d jbe 0x472725
0047270f mov edx, dword ptr [ebp + 0xc]
00472712 mov ecx, dword ptr [edx*4 + 0x585850]
00472719 mov eax, dword ptr [ecx + 0x28]
0047271c mov dword ptr [ebp - 0x64], eax
0047271f mov eax, dword ptr [ecx + 0x2c]
00472722 mov dword ptr [ebp - 0x60], eax
00472725 mov edx, dword ptr [ebp + 0xc]
00472728 mov ecx, dword ptr [edx*4 + 0x585850]
0047272f mov eax, dword ptr [ecx + 8]
00472732 cmp eax, 0xcc
00472737 jg 0x472774
00472739 je 0x47284e
0047273f cmp eax, 0x6a
00472742 jge 0x47275a
00472744 add eax, -0x65
00472747 sub eax, 2
0047274a jb 0x4727a1
0047274c sub eax, 3
0047274f jb 0x472b90
00472755 jmp 0x472c8e
0047275a add eax, -0x6a
0047275d sub eax, 3
00472760 jb 0x4727a1
00472762 sub eax, 0xc
00472765 je 0x4727a1
00472767 add eax, -0x50
0047276a sub eax, 2
0047276d jb 0x4727a1
0047276f jmp 0x472c8e
00472774 add eax, 0xffffff31
00472779 cmp eax, 5
0047277c ja 0x472c8e
00472782 jmp dword ptr [eax*4 + 0x472789]
00472789 and byte ptr [ecx], ch
0047278b inc edi
0047278c add byte ptr [eax], ah
0047278e sub dword ptr [edi], eax
00472791 cmpsb byte ptr [esi], byte ptr es:[edi]
00472792 sub dword ptr [edi], eax
00472795 jle 0x4727c1
00472797 inc edi
00472798 add byte ptr [edx], cl
0047279a sub eax, dword ptr [edi]
0047279d mov eax, dword ptr [0x8b004727]
004727a2 push ebp
004727a3 or al, 0x8b
004727a5 or al, 0x95
004727a7 push eax
004727a8 pop eax
004727a9 pop eax
004727aa add byte ptr [ebx + 0xfc81], cl
004727b0 add byte ptr [ebx + 0x2052ff10], cl
004727b6 mov dword ptr [ebp - 0xd48], eax
004727bc fild dword ptr [ebp - 0xd48]
004727c2 fld qword ptr [ebp - 0x64]
004727c5 mov ecx, dword ptr [ebp + 0xc]
004727c8 mov eax, dword ptr [ecx*4 + 0x585850]
004727cf fdiv qword ptr [eax + 0x28]
004727d2 fmulp st(1)
004727d4 fadd dword ptr [0x472ce0]
004727da fstp qword ptr [ebp - 0xc4]
004727e0 mov edx, dword ptr [ebp + 0xc]
004727e3 mov ecx, dword ptr [edx*4 + 0x585850]
004727ea mov eax, dword ptr [ecx + 0xfc]
004727f0 mov edx, dword ptr [eax]
004727f2 call dword ptr [edx + 0x2c]
004727f5 push eax
004727f6 mov ecx, dword ptr [ebp + 0xc]
004727f9 mov eax, dword ptr [ecx*4 + 0x585850]
00472800 mov eax, dword ptr [eax + 0xfc]
00472806 mov edx, dword ptr [eax]
00472808 call dword ptr [edx + 0x20]
0047280b push eax
0047280c mov ecx, dword ptr [ebp + 0xc]
0047280f mov eax, dword ptr [ecx*4 + 0x585850]
00472816 mov eax, dword ptr [eax + 0xfc]
0047281c mov edx, dword ptr [eax]
0047281e call dword ptr [edx + 0x20]
00472821 mov dword ptr [ebp - 0xd48], eax
00472827 fild dword ptr [ebp - 0xd48]
0047282d fsub qword ptr [ebp - 0xc4]
00472833 call 0x5394fc
00472838 push eax
00472839 mov eax, dword ptr [ebp + 8]
0047283c call 0x4e9448
00472841 xor edx, edx
00472843 pop ecx
00472844 call 0x4e4744
00472849 jmp 0x472c8e
0047284e mov eax, dword ptr [ebp + 0xc]
00472851 mov edx, dword ptr [eax*4 + 0x585850]
00472858 mov eax, dword ptr [edx + 0xfc]
0047285e mov edx, dword ptr [eax]
00472860 call dword ptr [edx + 0x20]
00472863 mov dword ptr [ebp - 0xd48], eax
00472869 fild dword ptr [ebp - 0xd48]
0047286f fld qword ptr [ebp - 0x64]
00472872 mov ecx, dword ptr [ebp + 0xc]
00472875 mov eax, dword ptr [ecx*4 + 0x585850]
0047287c fdiv qword ptr [eax + 0x28]
0047287f fmulp st(1)
00472881 fadd dword ptr [0x472ce0]
00472887 fstp qword ptr [ebp - 0xc4]
0047288d fld qword ptr [ebp - 0xc4]
00472893 fcomp qword ptr [0x472d30]
00472899 fnstsw ax
0047289b sahf 
0047289c jbe 0x4728b2
0047289e mov dword ptr [ebp - 0xc4], 0x9999999a
004728a8 mov dword ptr [ebp - 0xc0], 0x404ad999
004728b2 mov ecx, dword ptr [ebp + 0xc]
004728b5 mov eax, dword ptr [ecx*4 + 0x585850]
004728bc mov eax, dword ptr [eax + 0xfc]
004728c2 mov edx, dword ptr [eax]
004728c4 call dword ptr [edx + 0x2c]
004728c7 push eax
004728c8 mov ecx, dword ptr [ebp + 0xc]
004728cb mov eax, dword ptr [ecx*4 + 0x585850]
004728d2 mov eax, dword ptr [eax + 0xfc]
004728d8 mov edx, dword ptr [eax]
004728da call dword ptr [edx + 0x20]
004728dd push eax
004728de mov ecx, dword ptr [ebp + 0xc]
004728e1 mov eax, dword ptr [ecx*4 + 0x585850]
004728e8 mov eax, dword ptr [eax + 0xfc]
004728ee mov edx, dword ptr [eax]
004728f0 call dword ptr [edx + 0x20]
004728f3 mov dword ptr [ebp - 0xd48], eax
004728f9 fild dword ptr [ebp - 0xd48]
004728ff fsub qword ptr [ebp - 0xc4]
00472905 call 0x5394fc
0047290a push eax
0047290b mov eax, dword ptr [ebp + 8]
0047290e call 0x4e9448
00472913 xor edx, edx
00472915 pop ecx
00472916 call 0x4e4744
0047291b jmp 0x472c8e
00472920 fld qword ptr [ebp - 0x64]
00472923 fmul dword ptr [0x472d38]
00472929 fadd dword ptr [0x472d3c]
0047292f fstp qword ptr [ebp - 0xc4]
00472935 mov eax, dword ptr [ebp + 0xc]
00472938 mov edx, dword ptr [eax*4 + 0x585850]
0047293f mov eax, dword ptr [edx + 0xfc]
00472945 mov edx, dword ptr [eax]
00472947 call dword ptr [edx + 0x2c]
0047294a push eax
0047294b mov ecx, dword ptr [ebp + 0xc]
0047294e mov eax, dword ptr [ecx*4 + 0x585850]
00472955 mov eax, dword ptr [eax + 0xfc]
0047295b mov edx, dword ptr [eax]
0047295d call dword ptr [edx + 0x20]
00472960 add eax, -0x16
00472963 push eax
00472964 mov ecx, dword ptr [ebp + 0xc]
00472967 mov eax, dword ptr [ecx*4 + 0x585850]
0047296e mov eax, dword ptr [eax + 0xfc]
00472974 mov edx, dword ptr [eax]
00472976 call dword ptr [edx + 0x20]
00472979 mov dword ptr [ebp - 0xd48], eax
0047297f fild dword ptr [ebp - 0xd48]
00472985 fsub qword ptr [ebp - 0xc4]
0047298b call 0x5394fc
00472990 push eax
00472991 mov eax, dword ptr [ebp + 8]
00472994 call 0x4e9448
00472999 xor edx, edx
0047299b pop ecx
0047299c call 0x4e4744
004729a1 jmp 0x472c8e
004729a6 fld qword ptr [ebp - 0x64]
004729a9 fcomp dword ptr [0x472d40]
004729af fnstsw ax
004729b1 sahf 
004729b2 jbe 0x4729c0
004729b4 xor edx, edx
004729b6 mov dword ptr [ebp - 0x64], edx
004729b9 mov dword ptr [ebp - 0x60], 0x40490000
004729c0 push 0x3fd55555
004729c5 push 0x55555555
004729ca fld dword ptr [0x472d40]
004729d0 fsub qword ptr [ebp - 0x64]
004729d3 mov ecx, dword ptr [ebp + 0xc]
004729d6 mov eax, dword ptr [ecx*4 + 0x585850]
004729dd fsubr qword ptr [eax + 0x28]
004729e0 mov edx, dword ptr [ebp + 0xc]
004729e3 mov ecx, dword ptr [edx*4 + 0x585850]
004729ea fdiv qword ptr [ecx + 0x28]
004729ed add esp, -8
004729f0 fstp qword ptr [esp]
004729f3 call 0x5399d8
004729f8 add esp, 0x10
004729fb fmul dword ptr [0x472d44]
00472a01 fadd dword ptr [0x472d48]
00472a07 fstp qword ptr [ebp - 0xc4]
00472a0d mov eax, dword ptr [ebp + 0xc]
00472a10 mov edx, dword ptr [eax*4 + 0x585850]
00472a17 mov eax, dword ptr [edx + 0xfc]
00472a1d mov edx, dword ptr [eax]
00472a1f call dword ptr [edx + 0x2c]
00472a22 push eax
00472a23 mov ecx, dword ptr [ebp + 0xc]
00472a26 mov eax, dword ptr [ecx*4 + 0x585850]
00472a2d mov eax, dword ptr [eax + 0xfc]
00472a33 mov edx, dword ptr [eax]
00472a35 call dword ptr [edx + 0x20]
00472a38 add eax, -0x1e
00472a3b push eax
00472a3c mov ecx, dword ptr [ebp + 0xc]
00472a3f mov eax, dword ptr [ecx*4 + 0x585850]
00472a46 mov eax, dword ptr [eax + 0xfc]
00472a4c mov edx, dword ptr [eax]
00472a4e call dword ptr [edx + 0x20]
00472a51 mov dword ptr [ebp - 0xd48], eax
00472a57 fild dword ptr [ebp - 0xd48]
00472a5d fsub qword ptr [ebp - 0xc4]
00472a63 call 0x5394fc
00472a68 push eax
00472a69 mov eax, dword ptr [ebp + 8]
00472a6c call 0x4e9448
00472a71 xor edx, edx
00472a73 pop ecx
00472a74 call 0x4e4744
00472a79 jmp 0x472c8e
00472a7e fld xword ptr [0x472d4c]
00472a84 fmul qword ptr [ebp - 0x64]
00472a87 fmul dword ptr [0x472ce8]
00472a8d fadd dword ptr [0x472d58]
00472a93 fstp qword ptr [ebp - 0xc4]
00472a99 mov eax, dword ptr [ebp + 0xc]
00472a9c mov edx, dword ptr [eax*4 + 0x585850]
00472aa3 mov eax, dword ptr [edx + 0xfc]
00472aa9 mov edx, dword ptr [eax]
00472aab call dword ptr [edx + 0x2c]
00472aae push eax
00472aaf mov ecx, dword ptr [ebp + 0xc]
00472ab2 mov eax, dword ptr [ecx*4 + 0x585850]
00472ab9 mov eax, dword ptr [eax + 0xfc]
00472abf mov edx, dword ptr [eax]
00472ac1 call dword ptr [edx + 0x20]
00472ac4 add eax, -0x4d
00472ac7 push eax
00472ac8 mov ecx, dword ptr [ebp + 0xc]
00472acb mov eax, dword ptr [ecx*4 + 0x585850]
00472ad2 mov eax, dword ptr [eax + 0xfc]
00472ad8 mov edx, dword ptr [eax]
00472ada call dword ptr [edx + 0x20]
00472add mov dword ptr [ebp - 0xd48], eax
00472ae3 fild dword ptr [ebp - 0xd48]
00472ae9 fsub qword ptr [ebp - 0xc4]
00472aef call 0x5394fc
00472af4 push eax
00472af5 mov eax, dword ptr [ebp + 8]
00472af8 call 0x4e9448
00472afd xor edx, edx
00472aff pop ecx
00472b00 call 0x4e4744
00472b05 jmp 0x472c8e
00472b0a fld qword ptr [ebp - 0x64]
00472b0d fmul dword ptr [0x472ce0]
00472b13 fadd dword ptr [0x472d5c]
00472b19 fstp qword ptr [ebp - 0xc4]
00472b1f mov eax, dword ptr [ebp + 0xc]
00472b22 mov edx, dword ptr [eax*4 + 0x585850]
00472b29 mov eax, dword ptr [edx + 0xfc]
00472b2f mov edx, dword ptr [eax]
00472b31 call dword ptr [edx + 0x2c]
00472b34 push eax
00472b35 mov ecx, dword ptr [ebp + 0xc]
00472b38 mov eax, dword ptr [ecx*4 + 0x585850]
00472b3f mov eax, dword ptr [eax + 0xfc]
00472b45 mov edx, dword ptr [eax]
00472b47 call dword ptr [edx + 0x20]
00472b4a add eax, -0x4d
00472b4d push eax
00472b4e mov ecx, dword ptr [ebp + 0xc]
00472b51 mov eax, dword ptr [ecx*4 + 0x585850]
00472b58 mov eax, dword ptr [eax + 0xfc]
00472b5e mov edx, dword ptr [eax]
00472b60 call dword ptr [edx + 0x20]
00472b63 mov dword ptr [ebp - 0xd48], eax
00472b69 fild dword ptr [ebp - 0xd48]
00472b6f fsub qword ptr [ebp - 0xc4]
00472b75 call 0x5394fc
00472b7a push eax
00472b7b mov eax, dword ptr [ebp + 8]
00472b7e call 0x4e9448
00472b83 xor edx, edx
00472b85 pop ecx
00472b86 call 0x4e4744
00472b8b jmp 0x472c8e
00472b90 push 0x3fd55555
00472b95 push 0x55555555
00472b9a mov eax, dword ptr [ebp + 0xc]
00472b9d mov edx, dword ptr [eax*4 + 0x585850]
00472ba4 fld qword ptr [edx + 0x28]
00472ba7 fsub qword ptr [ebp - 0x64]
00472baa mov ecx, dword ptr [ebp + 0xc]
00472bad mov eax, dword ptr [ecx*4 + 0x585850]
00472bb4 fdiv qword ptr [eax + 0x28]
00472bb7 add esp, -8
00472bba fstp qword ptr [esp]
00472bbd call 0x5399d8
00472bc2 add esp, 0x10
00472bc5 fstp qword ptr [ebp - 0xd4c]
00472bcb mov edx, dword ptr [ebp + 0xc]
00472bce mov ecx, dword ptr [edx*4 + 0x585850]
00472bd5 mov eax, dword ptr [ecx + 0xfc]
00472bdb mov edx, dword ptr [eax]
00472bdd call dword ptr [edx + 0x20]
00472be0 mov dword ptr [ebp - 0xd50], eax
00472be6 fild dword ptr [ebp - 0xd50]
00472bec fmul qword ptr [ebp - 0xd4c]
00472bf2 fstp qword ptr [ebp - 0xd58]
00472bf8 mov ecx, dword ptr [ebp + 0xc]
00472bfb mov eax, dword ptr [ecx*4 + 0x585850]
00472c02 mov eax, dword ptr [eax + 0xfc]
00472c08 mov edx, dword ptr [eax]
00472c0a call dword ptr [edx + 0x20]
00472c0d mov dword ptr [ebp - 0xd5c], eax
00472c13 fild dword ptr [ebp - 0xd5c]
00472c19 fsub qword ptr [ebp - 0xd58]
00472c1f fstp qword ptr [ebp - 0xc4]
00472c25 mov ecx, dword ptr [ebp + 0xc]
00472c28 mov eax, dword ptr [ecx*4 + 0x585850]
00472c2f mov eax, dword ptr [eax + 0xfc]
00472c35 mov edx, dword ptr [eax]
00472c37 call dword ptr [edx + 0x2c]
00472c3a push eax
00472c3b mov ecx, dword ptr [ebp + 0xc]
00472c3e mov eax, dword ptr [ecx*4 + 0x585850]
00472c45 mov eax, dword ptr [eax + 0xfc]
00472c4b mov edx, dword ptr [eax]
00472c4d call dword ptr [edx + 0x20]
00472c50 push eax
00472c51 mov ecx, dword ptr [ebp + 0xc]
00472c54 mov eax, dword ptr [ecx*4 + 0x585850]
00472c5b mov eax, dword ptr [eax + 0xfc]
00472c61 mov edx, dword ptr [eax]
00472c63 call dword ptr [edx + 0x20]
00472c66 mov dword ptr [ebp - 0xd48], eax
00472c6c fild dword ptr [ebp - 0xd48]
00472c72 fsub qword ptr [ebp - 0xc4]
00472c78 call 0x5394fc
00472c7d push eax
00472c7e mov eax, dword ptr [ebp + 8]
00472c81 call 0x4e9448
00472c86 xor edx, edx
00472c88 pop ecx
00472c89 call 0x4e4744
00472c8e mov eax, dword ptr [ebp + 0xc]
00472c91 mov edx, dword ptr [eax*4 + 0x585850]
00472c98 mov ecx, dword ptr [ebp - 0xc4]
00472c9e mov dword ptr [edx + 0x30], ecx
00472ca1 mov ecx, dword ptr [ebp - 0xc0]
00472ca7 mov dword ptr [edx + 0x34], ecx
00472caa mov eax, dword ptr [ebp + 0xc]
00472cad mov edx, dword ptr [eax*4 + 0x585850]
00472cb4 mov ecx, dword ptr [ebp - 0x64]
00472cb7 mov dword ptr [edx + 0x4320], ecx
00472cbd mov ecx, dword ptr [ebp - 0x60]
00472cc0 mov dword ptr [edx + 0x4324], ecx
00472cc6 mov eax, dword ptr [ebp - 0x58]
00472cc9 mov dword ptr fs:[0], eax