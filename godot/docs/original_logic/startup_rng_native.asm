; Original PE SHA256 7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c
; Function 0x413698 bytes SHA256 e3d7abe127f3aa457334a97ae5b9f1951d25faf10682687c0fdf094ac7b9f0e8
00413698: 55                     push ebp
00413699: 8bec                   mov ebp, esp
0041369b: 6a00                   push 0
0041369d: e8f69a1200             call 0x53d198
004136a2: 59                     pop ecx
004136a3: 50                     push eax
004136a4: e863651200             call 0x539c0c
004136a9: 59                     pop ecx
004136aa: 5d                     pop ebp
004136ab: c3                     ret 
; Function 0x53d198 bytes SHA256 57cee47e0ff0080ff460f66449b0387ecc64920f941836a62b190fa15d68be83
0053d198: 55                     push ebp
0053d199: 8bec                   mov ebp, esp
0053d19b: 83c4f0                 add esp, -0x10
0053d19e: 53                     push ebx
0053d19f: 8b5d08                 mov ebx, dword ptr [ebp + 8]
0053d1a2: 8d45f0                 lea eax, [ebp - 0x10]
0053d1a5: 50                     push eax
0053d1a6: e8a97d0100             call 0x554f54
0053d1ab: 6aff                   push -1
0053d1ad: 0fb755fc               movzx edx, word ptr [ebp - 4]
0053d1b1: 52                     push edx
0053d1b2: 0fb74dfa               movzx ecx, word ptr [ebp - 6]
0053d1b6: 51                     push ecx
0053d1b7: 0fb745f8               movzx eax, word ptr [ebp - 8]
0053d1bb: 50                     push eax
0053d1bc: 0fb755f6               movzx edx, word ptr [ebp - 0xa]
0053d1c0: 4a                     dec edx
0053d1c1: 52                     push edx
0053d1c2: 0fb74df2               movzx ecx, word ptr [ebp - 0xe]
0053d1c6: 49                     dec ecx
0053d1c7: 51                     push ecx
0053d1c8: 0fb745f0               movzx eax, word ptr [ebp - 0x10]
0053d1cc: 0594f8ffff             add eax, 0xfffff894
0053d1d1: 50                     push eax
0053d1d2: e841fcffff             call 0x53ce18
0053d1d7: 83c41c                 add esp, 0x1c
0053d1da: 85db                   test ebx, ebx
0053d1dc: 7402                   je 0x53d1e0
0053d1de: 8903                   mov dword ptr [ebx], eax
0053d1e0: 5b                     pop ebx
0053d1e1: 8be5                   mov esp, ebp
0053d1e3: 5d                     pop ebp
0053d1e4: c3                     ret 
; Function 0x53ce18 bytes SHA256 95004d05d2253e1e2df6ae7438bec32c713e3cefaa5505ee6652def91c4e4d48
0053ce18: 55                     push ebp
0053ce19: 8bec                   mov ebp, esp
0053ce1b: 51                     push ecx
0053ce1c: 53                     push ebx
0053ce1d: 56                     push esi
0053ce1e: 57                     push edi
0053ce1f: 8b7510                 mov esi, dword ptr [ebp + 0x10]
0053ce22: 8b5d0c                 mov ebx, dword ptr [ebp + 0xc]
0053ce25: 8b7d08                 mov edi, dword ptr [ebp + 8]
0053ce28: 83ff46                 cmp edi, 0x46
0053ce2b: 7c08                   jl 0x53ce35
0053ce2d: 81ff8a000000           cmp edi, 0x8a
0053ce33: 7e08                   jle 0x53ce3d
0053ce35: 83c8ff                 or eax, 0xffffffff
0053ce38: e965010000             jmp 0x53cfa2
0053ce3d: 8b451c                 mov eax, dword ptr [ebp + 0x1c]
0053ce40: b93c000000             mov ecx, 0x3c
0053ce45: 99                     cdq 
0053ce46: f7f9                   idiv ecx
0053ce48: 014518                 add dword ptr [ebp + 0x18], eax
0053ce4b: b93c000000             mov ecx, 0x3c
0053ce50: 8b451c                 mov eax, dword ptr [ebp + 0x1c]
0053ce53: 99                     cdq 
0053ce54: f7f9                   idiv ecx
0053ce56: 89551c                 mov dword ptr [ebp + 0x1c], edx
0053ce59: 8b4518                 mov eax, dword ptr [ebp + 0x18]
0053ce5c: b93c000000             mov ecx, 0x3c
0053ce61: 99                     cdq 
0053ce62: f7f9                   idiv ecx
0053ce64: 014514                 add dword ptr [ebp + 0x14], eax
0053ce67: b93c000000             mov ecx, 0x3c
0053ce6c: 8b4518                 mov eax, dword ptr [ebp + 0x18]
0053ce6f: 99                     cdq 
0053ce70: f7f9                   idiv ecx
0053ce72: 895518                 mov dword ptr [ebp + 0x18], edx
0053ce75: 8b4514                 mov eax, dword ptr [ebp + 0x14]
0053ce78: b918000000             mov ecx, 0x18
0053ce7d: 99                     cdq 
0053ce7e: f7f9                   idiv ecx
0053ce80: 03f0                   add esi, eax
0053ce82: b918000000             mov ecx, 0x18
0053ce87: 8b4514                 mov eax, dword ptr [ebp + 0x14]
0053ce8a: 99                     cdq 
0053ce8b: f7f9                   idiv ecx
0053ce8d: 895514                 mov dword ptr [ebp + 0x14], edx
0053ce90: 8bc3                   mov eax, ebx
0053ce92: b90c000000             mov ecx, 0xc
0053ce97: 99                     cdq 
0053ce98: f7f9                   idiv ecx
0053ce9a: 03f8                   add edi, eax
0053ce9c: b90c000000             mov ecx, 0xc
0053cea1: 8bc3                   mov eax, ebx
0053cea3: 99                     cdq 
0053cea4: f7f9                   idiv ecx
0053cea6: 89d3                   mov ebx, edx
0053cea8: 8d8350785700           lea eax, [ebx + 0x577850]
0053ceae: eb2c                   jmp 0x53cedc
0053ceb0: f7c703000000           test edi, 3
0053ceb6: 7511                   jne 0x53cec9
0053ceb8: 83fb01                 cmp ebx, 1
0053cebb: 750c                   jne 0x53cec9
0053cebd: 83fe1c                 cmp esi, 0x1c
0053cec0: 7e21                   jle 0x53cee3
0053cec2: 83ee1d                 sub esi, 0x1d
0053cec5: 43                     inc ebx
0053cec6: 40                     inc eax
0053cec7: eb07                   jmp 0x53ced0
0053cec9: 0fbe10                 movsx edx, byte ptr [eax]
0053cecc: 2bf2                   sub esi, edx
0053cece: 43                     inc ebx
0053cecf: 40                     inc eax
0053ced0: 83fb0c                 cmp ebx, 0xc
0053ced3: 7c07                   jl 0x53cedc
0053ced5: 83eb0c                 sub ebx, 0xc
0053ced8: 83c0f4                 add eax, -0xc
0053cedb: 47                     inc edi
0053cedc: 0fbe08                 movsx ecx, byte ptr [eax]
0053cedf: 3bf1                   cmp esi, ecx
0053cee1: 7dcd                   jge 0x53ceb0
0053cee3: 83ef46                 sub edi, 0x46
0053cee6: 8d4702                 lea eax, [edi + 2]
0053cee9: 85c0                   test eax, eax
0053ceeb: 7903                   jns 0x53cef0
0053ceed: 83c003                 add eax, 3
0053cef0: c1f802                 sar eax, 2
0053cef3: 8d5746                 lea edx, [edi + 0x46]
0053cef6: f6c203                 test dl, 3
0053cef9: 7506                   jne 0x53cf01
0053cefb: 83fb02                 cmp ebx, 2
0053cefe: 7d01                   jge 0x53cf01
0053cf00: 48                     dec eax
0053cf01: 8d0c7f                 lea ecx, [edi + edi*2]
0053cf04: 8b5514                 mov edx, dword ptr [ebp + 0x14]
0053cf07: c1e103                 shl ecx, 3
0053cf0a: 2bcf                   sub ecx, edi
0053cf0c: c1e102                 shl ecx, 2
0053cf0f: 2bcf                   sub ecx, edi
0053cf11: c1e204                 shl edx, 4
0053cf14: 8d0c8f                 lea ecx, [edi + ecx*4]
0053cf17: 03c1                   add eax, ecx
0053cf19: 8b4d18                 mov ecx, dword ptr [ebp + 0x18]
0053cf1c: 03049d5c785700         add eax, dword ptr [ebx*4 + 0x57785c]
0053cf23: 8d1492                 lea edx, [edx + edx*4]
0053cf26: 03c6                   add eax, esi
0053cf28: c1e007                 shl eax, 7
0053cf2b: 8d1492                 lea edx, [edx + edx*4]
0053cf2e: c1e102                 shl ecx, 2
0053cf31: 8d0440                 lea eax, [eax + eax*2]
0053cf34: 8d14d2                 lea edx, [edx + edx*8]
0053cf37: 8d0480                 lea eax, [eax + eax*4]
0053cf3a: 8d0c49                 lea ecx, [ecx + ecx*2]
0053cf3d: 8d0480                 lea eax, [eax + eax*4]
0053cf40: 8d04c0                 lea eax, [eax + eax*8]
0053cf43: 8d0c89                 lea ecx, [ecx + ecx*4]
0053cf46: 03c2                   add eax, edx
0053cf48: 03c1                   add eax, ecx
0053cf4a: 03451c                 add eax, dword ptr [ebp + 0x1c]
0053cf4d: 030574795700           add eax, dword ptr [0x577974]
0053cf53: 8945fc                 mov dword ptr [ebp - 4], eax
0053cf56: 837d20ff               cmp dword ptr [ebp + 0x20], -1
0053cf5a: 7526                   jne 0x53cf82
0053cf5c: 833d7879570000         cmp dword ptr [0x577978], 0
0053cf63: 742f                   je 0x53cf94
0053cf65: 57                     push edi
0053cf66: 43                     inc ebx
0053cf67: 53                     push ebx
0053cf68: 56                     push esi
0053cf69: 8b4514                 mov eax, dword ptr [ebp + 0x14]
0053cf6c: 50                     push eax
0053cf6d: e892fdffff             call 0x53cd04
0053cf72: 83c410                 add esp, 0x10
0053cf75: 85c0                   test eax, eax
0053cf77: 741b                   je 0x53cf94
0053cf79: 816dfc100e0000         sub dword ptr [ebp - 4], 0xe10
0053cf80: eb12                   jmp 0x53cf94
0053cf82: 837d2000               cmp dword ptr [ebp + 0x20], 0
0053cf86: 7407                   je 0x53cf8f
0053cf88: ba100e0000             mov edx, 0xe10
0053cf8d: eb02                   jmp 0x53cf91
0053cf8f: 33d2                   xor edx, edx
0053cf91: 2955fc                 sub dword ptr [ebp - 4], edx
0053cf94: 837dfc00               cmp dword ptr [ebp - 4], 0
0053cf98: 7e05                   jle 0x53cf9f
0053cf9a: 8b45fc                 mov eax, dword ptr [ebp - 4]
0053cf9d: eb03                   jmp 0x53cfa2
0053cf9f: 83c8ff                 or eax, 0xffffffff
0053cfa2: 5f                     pop edi
0053cfa3: 5e                     pop esi
0053cfa4: 5b                     pop ebx
0053cfa5: 59                     pop ecx
0053cfa6: 5d                     pop ebp
0053cfa7: c3                     ret 
; Function 0x53cd04 bytes SHA256 a46ed7aaa0811a35df6451b71d82f80e3f3f140550fae49b67c6568645da2ed6
0053cd04: 55                     push ebp
0053cd05: 8bec                   mov ebp, esp
0053cd07: 51                     push ecx
0053cd08: 53                     push ebx
0053cd09: 56                     push esi
0053cd0a: 57                     push edi
0053cd0b: 8b4514                 mov eax, dword ptr [ebp + 0x14]
0053cd0e: 8b4d10                 mov ecx, dword ptr [ebp + 0x10]
0053cd11: 8b750c                 mov esi, dword ptr [ebp + 0xc]
0053cd14: 85c9                   test ecx, ecx
0053cd16: 7529                   jne 0x53cd41
0053cd18: 8975fc                 mov dword ptr [ebp - 4], esi
0053cd1b: 83fe3b                 cmp esi, 0x3b
0053cd1e: 720b                   jb 0x53cd2b
0053cd20: 8d5046                 lea edx, [eax + 0x46]
0053cd23: f6c203                 test dl, 3
0053cd26: 7503                   jne 0x53cd2b
0053cd28: ff4dfc                 dec dword ptr [ebp - 4]
0053cd2b: 33c9                   xor ecx, ecx
0053cd2d: ba5c785700             mov edx, 0x57785c
0053cd32: eb04                   jmp 0x53cd38
0053cd34: 41                     inc ecx
0053cd35: 83c204                 add edx, 4
0053cd38: 8b1a                   mov ebx, dword ptr [edx]
0053cd3a: 3b5dfc                 cmp ebx, dword ptr [ebp - 4]
0053cd3d: 76f5                   jbe 0x53cd34
0053cd3f: eb15                   jmp 0x53cd56
0053cd41: 03348d58785700         add esi, dword ptr [ecx*4 + 0x577858]
0053cd48: 83f902                 cmp ecx, 2
0053cd4b: 7609                   jbe 0x53cd56
0053cd4d: 8d5046                 lea edx, [eax + 0x46]
0053cd50: f6c203                 test dl, 3
0053cd53: 7501                   jne 0x53cd56
0053cd55: 46                     inc esi
0053cd56: 83f904                 cmp ecx, 4
0053cd59: 7205                   jb 0x53cd60
0053cd5b: 83f90a                 cmp ecx, 0xa
0053cd5e: 7607                   jbe 0x53cd67
0053cd60: 33c0                   xor eax, eax
0053cd62: e9ab000000             jmp 0x53ce12
0053cd67: 83f904                 cmp ecx, 4
0053cd6a: 760f                   jbe 0x53cd7b
0053cd6c: 83f90a                 cmp ecx, 0xa
0053cd6f: 730a                   jae 0x53cd7b
0053cd71: b801000000             mov eax, 1
0053cd76: e997000000             jmp 0x53ce12
0053cd7b: 83f810                 cmp eax, 0x10
0053cd7e: 7611                   jbe 0x53cd91
0053cd80: 83f904                 cmp ecx, 4
0053cd83: 750c                   jne 0x53cd91
0053cd85: 8b1c8d58785700         mov ebx, dword ptr [ecx*4 + 0x577858]
0053cd8c: 83c307                 add ebx, 7
0053cd8f: eb07                   jmp 0x53cd98
0053cd91: 8b1c8d5c785700         mov ebx, dword ptr [ecx*4 + 0x57785c]
0053cd98: 8d5046                 lea edx, [eax + 0x46]
0053cd9b: f6c203                 test dl, 3
0053cd9e: 7401                   je 0x53cda1
0053cda0: 4b                     dec ebx
0053cda1: 8bf8                   mov edi, eax
0053cda3: 8d5001                 lea edx, [eax + 1]
0053cda6: c1ea02                 shr edx, 2
0053cda9: 03d3                   add edx, ebx
0053cdab: 8d0447                 lea eax, [edi + eax*2]
0053cdae: c1e003                 shl eax, 3
0053cdb1: 2bc7                   sub eax, edi
0053cdb3: c1e002                 shl eax, 2
0053cdb6: 2bc7                   sub eax, edi
0053cdb8: 8d0487                 lea eax, [edi + eax*4]
0053cdbb: bf07000000             mov edi, 7
0053cdc0: 03d0                   add edx, eax
0053cdc2: 83c204                 add edx, 4
0053cdc5: 8955fc                 mov dword ptr [ebp - 4], edx
0053cdc8: 33d2                   xor edx, edx
0053cdca: 8b45fc                 mov eax, dword ptr [ebp - 4]
0053cdcd: f7f7                   div edi
0053cdcf: 2bda                   sub ebx, edx
0053cdd1: 83f904                 cmp ecx, 4
0053cdd4: 751f                   jne 0x53cdf5
0053cdd6: 3bde                   cmp ebx, esi
0053cdd8: 7307                   jae 0x53cde1
0053cdda: b801000000             mov eax, 1
0053cddf: eb31                   jmp 0x53ce12
0053cde1: 3bde                   cmp ebx, esi
0053cde3: 7604                   jbe 0x53cde9
0053cde5: 33c0                   xor eax, eax
0053cde7: eb29                   jmp 0x53ce12
0053cde9: 837d0802               cmp dword ptr [ebp + 8], 2
0053cded: 0f93c0                 setae al
0053cdf0: 83e001                 and eax, 1
0053cdf3: eb1d                   jmp 0x53ce12
0053cdf5: 3bde                   cmp ebx, esi
0053cdf7: 7607                   jbe 0x53ce00
0053cdf9: b801000000             mov eax, 1
0053cdfe: eb12                   jmp 0x53ce12
0053ce00: 3bde                   cmp ebx, esi
0053ce02: 7304                   jae 0x53ce08
0053ce04: 33c0                   xor eax, eax
0053ce06: eb0a                   jmp 0x53ce12
0053ce08: 837d0801               cmp dword ptr [ebp + 8], 1
0053ce0c: 0f96c0                 setbe al
0053ce0f: 83e001                 and eax, 1
0053ce12: 5f                     pop edi
0053ce13: 5e                     pop esi
0053ce14: 5b                     pop ebx
0053ce15: 59                     pop ecx
0053ce16: 5d                     pop ebp
0053ce17: c3                     ret 
; Function 0x539c0c bytes SHA256 926640bed8597e48c7cefde3262444dda65f833b5779822ddc8615ad6500cf57
00539c0c: 55                     push ebp
00539c0d: 8bec                   mov ebp, esp
00539c0f: e8502e0000             call 0x53ca64
00539c14: 8b5508                 mov edx, dword ptr [ebp + 8]
00539c17: 895044                 mov dword ptr [eax + 0x44], edx
00539c1a: e8452e0000             call 0x53ca64
00539c1f: 33c9                   xor ecx, ecx
00539c21: 894848                 mov dword ptr [eax + 0x48], ecx
00539c24: e80f000000             call 0x539c38
00539c29: 5d                     pop ebp
00539c2a: c3                     ret 
; Function 0x539c38 bytes SHA256 b4052340bb5549dde9ea46ff630a0960f19bbd0e6098c030b86a24692018c80f
00539c38: 53                     push ebx
00539c39: e8262e0000             call 0x53ca64
00539c3e: 695844354e5a01         imul ebx, dword ptr [eax + 0x44], 0x15a4e35
00539c45: 43                     inc ebx
00539c46: e8192e0000             call 0x53ca64
00539c4b: 895844                 mov dword ptr [eax + 0x44], ebx
00539c4e: e8112e0000             call 0x53ca64
00539c53: 8b4044                 mov eax, dword ptr [eax + 0x44]
00539c56: c1e810                 shr eax, 0x10
00539c59: 25ff7f0000             and eax, 0x7fff
00539c5e: 5b                     pop ebx
00539c5f: c3                     ret 
; Function 0x539c60 bytes SHA256 4896f777a1717c6e4ceaba33ba26158d7f18cd14fd161690ec230328a5ab00ee
00539c60: 53                     push ebx
00539c61: 56                     push esi
00539c62: e8fd2d0000             call 0x53ca64
00539c67: 8b5848                 mov ebx, dword ptr [eax + 0x48]
00539c6a: e8f52d0000             call 0x53ca64
00539c6f: 8b7044                 mov esi, dword ptr [eax + 0x44]
00539c72: 8bc3                   mov eax, ebx
00539c74: b95a010000             mov ecx, 0x15a
00539c79: bb354e0000             mov ebx, 0x4e35
00539c7e: 85c0                   test eax, eax
00539c80: 7402                   je 0x539c84
00539c82: f7e3                   mul ebx
00539c84: 91                     xchg ecx, eax
00539c85: f7e6                   mul esi
00539c87: 03c1                   add eax, ecx
00539c89: 96                     xchg esi, eax
00539c8a: f7e3                   mul ebx
00539c8c: 03d6                   add edx, esi
00539c8e: 83c001                 add eax, 1
00539c91: 83d200                 adc edx, 0
00539c94: 8bd8                   mov ebx, eax
00539c96: 8bf2                   mov esi, edx
00539c98: e8c72d0000             call 0x53ca64
00539c9d: 895844                 mov dword ptr [eax + 0x44], ebx
00539ca0: e8bf2d0000             call 0x53ca64
00539ca5: 897048                 mov dword ptr [eax + 0x48], esi
00539ca8: 8bc6                   mov eax, esi
00539caa: 25ffffff7f             and eax, 0x7fffffff
00539caf: 5e                     pop esi
00539cb0: 5b                     pop ebx
