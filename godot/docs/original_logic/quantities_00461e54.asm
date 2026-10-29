; Actual main.exe instructions, SHA256 7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c
; Capstone 5.0.7 offline decoding, no execution.
00461E54  55                        push ebp
00461E55  8bec                      mov ebp, esp
00461E57  83c48c                    add esp, -0x74
00461E5A  b8784a5600                mov eax, 0x564a78
00461E5F  e87c2d0d00                call 0x534be0
00461E64  8b5508                    mov edx, dword ptr [ebp + 8]
00461E67  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
00461E6E  33c0                      xor eax, eax
00461E70  898120430000              mov dword ptr [ecx + 0x4320], eax
00461E76  898124430000              mov dword ptr [ecx + 0x4324], eax
00461E7C  8b5508                    mov edx, dword ptr [ebp + 8]
00461E7F  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
00461E86  33c0                      xor eax, eax
00461E88  898128430000              mov dword ptr [ecx + 0x4328], eax
00461E8E  89812c430000              mov dword ptr [ecx + 0x432c], eax
00461E94  8b5508                    mov edx, dword ptr [ebp + 8]
00461E97  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
00461E9E  33c0                      xor eax, eax
00461EA0  898130430000              mov dword ptr [ecx + 0x4330], eax
00461EA6  898134430000              mov dword ptr [ecx + 0x4334], eax
00461EAC  8b5508                    mov edx, dword ptr [ebp + 8]
00461EAF  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
00461EB6  33c0                      xor eax, eax
00461EB8  898138430000              mov dword ptr [ecx + 0x4338], eax
00461EBE  89813c430000              mov dword ptr [ecx + 0x433c], eax
00461EC4  33d2                      xor edx, edx
00461EC6  89559c                    mov dword ptr [ebp - 0x64], edx
00461EC9  e9e2040000                jmp 0x4623b0
00461ECE  8b4d08                    mov ecx, dword ptr [ebp + 8]
00461ED1  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
00461ED8  8b559c                    mov edx, dword ptr [ebp - 0x64]
00461EDB  ffb49008010000            push dword ptr [eax + edx*4 + 0x108]
00461EE2  e8b50effff                call 0x452d9c
00461EE7  59                        pop ecx
00461EE8  8b0c8508bc5700            mov ecx, dword ptr [eax*4 + 0x57bc08]
00461EEF  dd4110                    fld qword ptr [ecx + 0x10]
00461EF2  8b4508                    mov eax, dword ptr [ebp + 8]
00461EF5  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00461EFC  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
00461EFF  dc8ccad8080000            fmul qword ptr [edx + ecx*8 + 0x8d8]
00461F06  8b4508                    mov eax, dword ptr [ebp + 8]
00461F09  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00461F10  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
00461F13  dd9cca98020000            fstp qword ptr [edx + ecx*8 + 0x298]
00461F1A  8b4508                    mov eax, dword ptr [ebp + 8]
00461F1D  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00461F24  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
00461F27  dd84cad8080000            fld qword ptr [edx + ecx*8 + 0x8d8]
00461F2E  dc1da8244600              fcomp qword ptr [0x4624a8]
00461F34  dfe0                      fnstsw ax
00461F36  9e                        sahf 
00461F37  7344                      jae 0x461f7d
00461F39  33d2                      xor edx, edx
00461F3B  8915f8a65700              mov dword ptr [0x57a6f8], edx
00461F41  66c745b00800              mov word ptr [ebp - 0x50], 8
00461F47  ba9e375600                mov edx, 0x56379e
00461F4C  8d45fc                    lea eax, [ebp - 4]
00461F4F  e870ef0d00                call 0x540ec4
00461F54  ff45bc                    inc dword ptr [ebp - 0x44]
00461F57  8b00                      mov eax, dword ptr [eax]
00461F59  e8f2e30900                call 0x500350
00461F5E  ff4dbc                    dec dword ptr [ebp - 0x44]
00461F61  8d45fc                    lea eax, [ebp - 4]
00461F64  ba02000000                mov edx, 2
00461F69  e87af00d00                call 0x540fe8
00461F6E  8b4da0                    mov ecx, dword ptr [ebp - 0x60]
00461F71  64890d00000000            mov dword ptr fs:[0], ecx
00461F78  e924050000                jmp 0x4624a1
00461F7D  66c745b01400              mov word ptr [ebp - 0x50], 0x14
00461F83  8b4508                    mov eax, dword ptr [ebp + 8]
00461F86  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00461F8D  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
00461F90  ffb48a08010000            push dword ptr [edx + ecx*4 + 0x108]
00461F97  8d45f8                    lea eax, [ebp - 8]
00461F9A  e849f7f9ff                call 0x4016e8
00461F9F  50                        push eax
00461FA0  ff45bc                    inc dword ptr [ebp - 0x44]
00461FA3  e8240bffff                call 0x452acc
00461FA8  83c408                    add esp, 8
00461FAB  8d55f8                    lea edx, [ebp - 8]
00461FAE  52                        push edx
00461FAF  bab2375600                mov edx, 0x5637b2
00461FB4  8d45f4                    lea eax, [ebp - 0xc]
00461FB7  e808ef0d00                call 0x540ec4
00461FBC  ff45bc                    inc dword ptr [ebp - 0x44]
00461FBF  8d55f4                    lea edx, [ebp - 0xc]
00461FC2  58                        pop eax
00461FC3  e804f10d00                call 0x5410cc
00461FC8  84c0                      test al, al
00461FCA  0f85ea000000              jne 0x4620ba
00461FD0  8b4d08                    mov ecx, dword ptr [ebp + 8]
00461FD3  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
00461FDA  8b559c                    mov edx, dword ptr [ebp - 0x64]
00461FDD  ffb49008010000            push dword ptr [eax + edx*4 + 0x108]
00461FE4  8d45f0                    lea eax, [ebp - 0x10]
00461FE7  e8fcf6f9ff                call 0x4016e8
00461FEC  50                        push eax
00461FED  ff45bc                    inc dword ptr [ebp - 0x44]
00461FF0  e8d70affff                call 0x452acc
00461FF5  83c408                    add esp, 8
00461FF8  8d55f0                    lea edx, [ebp - 0x10]
00461FFB  52                        push edx
00461FFC  bab9375600                mov edx, 0x5637b9
00462001  8d45ec                    lea eax, [ebp - 0x14]
00462004  e8bbee0d00                call 0x540ec4
00462009  ff45bc                    inc dword ptr [ebp - 0x44]
0046200C  8d55ec                    lea edx, [ebp - 0x14]
0046200F  58                        pop eax
00462010  e8b7f00d00                call 0x5410cc
00462015  84c0                      test al, al
00462017  0f95c1                    setne cl
0046201A  83e101                    and ecx, 1
0046201D  51                        push ecx
0046201E  ff4dbc                    dec dword ptr [ebp - 0x44]
00462021  8d45ec                    lea eax, [ebp - 0x14]
00462024  ba02000000                mov edx, 2
00462029  e8baef0d00                call 0x540fe8
0046202E  ff4dbc                    dec dword ptr [ebp - 0x44]
00462031  8d45f0                    lea eax, [ebp - 0x10]
00462034  ba02000000                mov edx, 2
00462039  e8aaef0d00                call 0x540fe8
0046203E  59                        pop ecx
0046203F  85c9                      test ecx, ecx
00462041  7577                      jne 0x4620ba
00462043  8b4508                    mov eax, dword ptr [ebp + 8]
00462046  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0046204D  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
00462050  ffb48a08010000            push dword ptr [edx + ecx*4 + 0x108]
00462057  8d45e8                    lea eax, [ebp - 0x18]
0046205A  e889f6f9ff                call 0x4016e8
0046205F  50                        push eax
00462060  ff45bc                    inc dword ptr [ebp - 0x44]
00462063  e8640affff                call 0x452acc
00462068  83c408                    add esp, 8
0046206B  8d55e8                    lea edx, [ebp - 0x18]
0046206E  52                        push edx
0046206F  bac0375600                mov edx, 0x5637c0
00462074  8d45e4                    lea eax, [ebp - 0x1c]
00462077  e848ee0d00                call 0x540ec4
0046207C  ff45bc                    inc dword ptr [ebp - 0x44]
0046207F  8d55e4                    lea edx, [ebp - 0x1c]
00462082  58                        pop eax
00462083  e844f00d00                call 0x5410cc
00462088  84c0                      test al, al
0046208A  0f95c1                    setne cl
0046208D  83e101                    and ecx, 1
00462090  51                        push ecx
00462091  ff4dbc                    dec dword ptr [ebp - 0x44]
00462094  8d45e4                    lea eax, [ebp - 0x1c]
00462097  ba02000000                mov edx, 2
0046209C  e847ef0d00                call 0x540fe8
004620A1  ff4dbc                    dec dword ptr [ebp - 0x44]
004620A4  8d45e8                    lea eax, [ebp - 0x18]
004620A7  ba02000000                mov edx, 2
004620AC  e837ef0d00                call 0x540fe8
004620B1  59                        pop ecx
004620B2  85c9                      test ecx, ecx
004620B4  7504                      jne 0x4620ba
004620B6  33c0                      xor eax, eax
004620B8  eb05                      jmp 0x4620bf
004620BA  b801000000                mov eax, 1
004620BF  50                        push eax
004620C0  ff4dbc                    dec dword ptr [ebp - 0x44]
004620C3  8d45f4                    lea eax, [ebp - 0xc]
004620C6  ba02000000                mov edx, 2
004620CB  e818ef0d00                call 0x540fe8
004620D0  ff4dbc                    dec dword ptr [ebp - 0x44]
004620D3  8d45f8                    lea eax, [ebp - 8]
004620D6  ba02000000                mov edx, 2
004620DB  e808ef0d00                call 0x540fe8
004620E0  59                        pop ecx
004620E1  84c9                      test cl, cl
004620E3  0f84f3000000              je 0x4621dc
004620E9  66c745b02000              mov word ptr [ebp - 0x50], 0x20
004620EF  8b4508                    mov eax, dword ptr [ebp + 8]
004620F2  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
004620F9  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
004620FC  ffb48a08010000            push dword ptr [edx + ecx*4 + 0x108]
00462103  8d45e0                    lea eax, [ebp - 0x20]
00462106  e8ddf5f9ff                call 0x4016e8
0046210B  50                        push eax
0046210C  ff45bc                    inc dword ptr [ebp - 0x44]
0046210F  e8b809ffff                call 0x452acc
00462114  83c408                    add esp, 8
00462117  8d55e0                    lea edx, [ebp - 0x20]
0046211A  52                        push edx
0046211B  bac7375600                mov edx, 0x5637c7
00462120  8d45dc                    lea eax, [ebp - 0x24]
00462123  e89ced0d00                call 0x540ec4
00462128  ff45bc                    inc dword ptr [ebp - 0x44]
0046212B  8d55dc                    lea edx, [ebp - 0x24]
0046212E  58                        pop eax
0046212F  e898ef0d00                call 0x5410cc
00462134  50                        push eax
00462135  ff4dbc                    dec dword ptr [ebp - 0x44]
00462138  8d45dc                    lea eax, [ebp - 0x24]
0046213B  ba02000000                mov edx, 2
00462140  e8a3ee0d00                call 0x540fe8
00462145  ff4dbc                    dec dword ptr [ebp - 0x44]
00462148  8d45e0                    lea eax, [ebp - 0x20]
0046214B  ba02000000                mov edx, 2
00462150  e893ee0d00                call 0x540fe8
00462155  59                        pop ecx
00462156  84c9                      test cl, cl
00462158  7436                      je 0x462190
0046215A  8b4508                    mov eax, dword ptr [ebp + 8]
0046215D  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00462164  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
00462167  dd84cad8080000            fld qword ptr [edx + ecx*8 + 0x8d8]
0046216E  dc0db0244600              fmul qword ptr [0x4624b0]
00462174  d80db8244600              fmul dword ptr [0x4624b8]
0046217A  8b4508                    mov eax, dword ptr [ebp + 8]
0046217D  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00462184  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
00462187  dd9ccab8050000            fstp qword ptr [edx + ecx*8 + 0x5b8]
0046218E  eb4c                      jmp 0x4621dc
00462190  8b4508                    mov eax, dword ptr [ebp + 8]
00462193  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0046219A  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
0046219D  ffb48a08010000            push dword ptr [edx + ecx*4 + 0x108]
004621A4  e8f30bffff                call 0x452d9c
004621A9  59                        pop ecx
004621AA  8b048508bc5700            mov eax, dword ptr [eax*4 + 0x57bc08]
004621B1  dd4030                    fld qword ptr [eax + 0x30]
004621B4  8b5508                    mov edx, dword ptr [ebp + 8]
004621B7  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
004621BE  8b459c                    mov eax, dword ptr [ebp - 0x64]
004621C1  dcbcc198020000            fdivr qword ptr [ecx + eax*8 + 0x298]
004621C8  8b5508                    mov edx, dword ptr [ebp + 8]
004621CB  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
004621D2  8b459c                    mov eax, dword ptr [ebp - 0x64]
004621D5  dd9cc1b8050000            fstp qword ptr [ecx + eax*8 + 0x5b8]
004621DC  66c745b02c00              mov word ptr [ebp - 0x50], 0x2c
004621E2  8b5508                    mov edx, dword ptr [ebp + 8]
004621E5  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
004621EC  8b459c                    mov eax, dword ptr [ebp - 0x64]
004621EF  ffb48108010000            push dword ptr [ecx + eax*4 + 0x108]
004621F6  8d45d8                    lea eax, [ebp - 0x28]
004621F9  e8eaf4f9ff                call 0x4016e8
004621FE  50                        push eax
004621FF  ff45bc                    inc dword ptr [ebp - 0x44]
00462202  e8c508ffff                call 0x452acc
00462207  83c408                    add esp, 8
0046220A  8d55d8                    lea edx, [ebp - 0x28]
0046220D  52                        push edx
0046220E  bace375600                mov edx, 0x5637ce
00462213  8d45d4                    lea eax, [ebp - 0x2c]
00462216  e8a9ec0d00                call 0x540ec4
0046221B  ff45bc                    inc dword ptr [ebp - 0x44]
0046221E  8d55d4                    lea edx, [ebp - 0x2c]
00462221  58                        pop eax
00462222  e8a5ee0d00                call 0x5410cc
00462227  50                        push eax
00462228  ff4dbc                    dec dword ptr [ebp - 0x44]
0046222B  8d45d4                    lea eax, [ebp - 0x2c]
0046222E  ba02000000                mov edx, 2
00462233  e8b0ed0d00                call 0x540fe8
00462238  ff4dbc                    dec dword ptr [ebp - 0x44]
0046223B  8d45d8                    lea eax, [ebp - 0x28]
0046223E  ba02000000                mov edx, 2
00462243  e8a0ed0d00                call 0x540fe8
00462248  59                        pop ecx
00462249  84c9                      test cl, cl
0046224B  742a                      je 0x462277
0046224D  8b4508                    mov eax, dword ptr [ebp + 8]
00462250  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00462257  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
0046225A  dd84cab8050000            fld qword ptr [edx + ecx*8 + 0x5b8]
00462261  8b4508                    mov eax, dword ptr [ebp + 8]
00462264  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0046226B  dc8238430000              fadd qword ptr [edx + 0x4338]
00462271  dd9a38430000              fstp qword ptr [edx + 0x4338]
00462277  66c745b03800              mov word ptr [ebp - 0x50], 0x38
0046227D  8b4d08                    mov ecx, dword ptr [ebp + 8]
00462280  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
00462287  8b559c                    mov edx, dword ptr [ebp - 0x64]
0046228A  ffb49008010000            push dword ptr [eax + edx*4 + 0x108]
00462291  8d45d0                    lea eax, [ebp - 0x30]
00462294  e84ff4f9ff                call 0x4016e8
00462299  50                        push eax
0046229A  ff45bc                    inc dword ptr [ebp - 0x44]
0046229D  e82a08ffff                call 0x452acc
004622A2  83c408                    add esp, 8
004622A5  8d55d0                    lea edx, [ebp - 0x30]
004622A8  52                        push edx
004622A9  bad5375600                mov edx, 0x5637d5
004622AE  8d45cc                    lea eax, [ebp - 0x34]
004622B1  e80eec0d00                call 0x540ec4
004622B6  ff45bc                    inc dword ptr [ebp - 0x44]
004622B9  8d55cc                    lea edx, [ebp - 0x34]
004622BC  58                        pop eax
004622BD  e80aee0d00                call 0x5410cc
004622C2  50                        push eax
004622C3  ff4dbc                    dec dword ptr [ebp - 0x44]
004622C6  8d45cc                    lea eax, [ebp - 0x34]
004622C9  ba02000000                mov edx, 2
004622CE  e815ed0d00                call 0x540fe8
004622D3  ff4dbc                    dec dword ptr [ebp - 0x44]
004622D6  8d45d0                    lea eax, [ebp - 0x30]
004622D9  ba02000000                mov edx, 2
004622DE  e805ed0d00                call 0x540fe8
004622E3  59                        pop ecx
004622E4  84c9                      test cl, cl
004622E6  742a                      je 0x462312
004622E8  8b4508                    mov eax, dword ptr [ebp + 8]
004622EB  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
004622F2  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
004622F5  dd84cab8050000            fld qword ptr [edx + ecx*8 + 0x5b8]
004622FC  8b4508                    mov eax, dword ptr [ebp + 8]
004622FF  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00462306  dc8220430000              fadd qword ptr [edx + 0x4320]
0046230C  dd9a20430000              fstp qword ptr [edx + 0x4320]
00462312  66c745b04400              mov word ptr [ebp - 0x50], 0x44
00462318  8b4d08                    mov ecx, dword ptr [ebp + 8]
0046231B  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
00462322  8b559c                    mov edx, dword ptr [ebp - 0x64]
00462325  ffb49008010000            push dword ptr [eax + edx*4 + 0x108]
0046232C  8d45c8                    lea eax, [ebp - 0x38]
0046232F  e8b4f3f9ff                call 0x4016e8
00462334  50                        push eax
00462335  ff45bc                    inc dword ptr [ebp - 0x44]
00462338  e88f07ffff                call 0x452acc
0046233D  83c408                    add esp, 8
00462340  8d55c8                    lea edx, [ebp - 0x38]
00462343  52                        push edx
00462344  badc375600                mov edx, 0x5637dc
00462349  8d45c4                    lea eax, [ebp - 0x3c]
0046234C  e873eb0d00                call 0x540ec4
00462351  ff45bc                    inc dword ptr [ebp - 0x44]
00462354  8d55c4                    lea edx, [ebp - 0x3c]
00462357  58                        pop eax
00462358  e86fed0d00                call 0x5410cc
0046235D  50                        push eax
0046235E  ff4dbc                    dec dword ptr [ebp - 0x44]
00462361  8d45c4                    lea eax, [ebp - 0x3c]
00462364  ba02000000                mov edx, 2
00462369  e87aec0d00                call 0x540fe8
0046236E  ff4dbc                    dec dword ptr [ebp - 0x44]
00462371  8d45c8                    lea eax, [ebp - 0x38]
00462374  ba02000000                mov edx, 2
00462379  e86aec0d00                call 0x540fe8
0046237E  59                        pop ecx
0046237F  84c9                      test cl, cl
00462381  742a                      je 0x4623ad
00462383  8b4508                    mov eax, dword ptr [ebp + 8]
00462386  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0046238D  8b4d9c                    mov ecx, dword ptr [ebp - 0x64]
00462390  dd84cad8080000            fld qword ptr [edx + ecx*8 + 0x8d8]
00462397  8b4508                    mov eax, dword ptr [ebp + 8]
0046239A  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
004623A1  dc8228430000              fadd qword ptr [edx + 0x4328]
004623A7  dd9a28430000              fstp qword ptr [edx + 0x4328]
004623AD  ff459c                    inc dword ptr [ebp - 0x64]
004623B0  8b4d08                    mov ecx, dword ptr [ebp + 8]
004623B3  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
004623BA  8b9004010000              mov edx, dword ptr [eax + 0x104]
004623C0  3b559c                    cmp edx, dword ptr [ebp - 0x64]
004623C3  0f8f05fbffff              jg 0x461ece
004623C9  8b4d08                    mov ecx, dword ptr [ebp + 8]
004623CC  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
004623D3  dd8028430000              fld qword ptr [eax + 0x4328]
004623D9  dc0db0244600              fmul qword ptr [0x4624b0]
004623DF  d80db8244600              fmul dword ptr [0x4624b8]
004623E5  8b5508                    mov edx, dword ptr [ebp + 8]
004623E8  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
004623EF  dd9930430000              fstp qword ptr [ecx + 0x4330]
004623F5  8b4508                    mov eax, dword ptr [ebp + 8]
004623F8  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
004623FF  33c9                      xor ecx, ecx
00462401  898aa8000000              mov dword ptr [edx + 0xa8], ecx
00462407  898aac000000              mov dword ptr [edx + 0xac], ecx
0046240D  8b4508                    mov eax, dword ptr [ebp + 8]
00462410  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
00462417  dd4228                    fld qword ptr [edx + 0x28]
0046241A  8b4d08                    mov ecx, dword ptr [ebp + 8]
0046241D  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
00462424  dca020430000              fsub qword ptr [eax + 0x4320]
0046242A  dd5d94                    fstp qword ptr [ebp - 0x6c]
0046242D  8b5508                    mov edx, dword ptr [ebp + 8]
00462430  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
00462437  dd8130430000              fld qword ptr [ecx + 0x4330]
0046243D  dc6594                    fsub qword ptr [ebp - 0x6c]
00462440  dd5d8c                    fstp qword ptr [ebp - 0x74]
00462443  db2dbc244600              fld xword ptr [0x4624bc]
00462449  dc4d8c                    fmul qword ptr [ebp - 0x74]
0046244C  db2dc8244600              fld xword ptr [0x4624c8]
00462452  dec9                      fmulp st(1)
00462454  8b4508                    mov eax, dword ptr [ebp + 8]
00462457  8b148550585800            mov edx, dword ptr [eax*4 + 0x585850]
0046245E  dd9aa8000000              fstp qword ptr [edx + 0xa8]
00462464  8b4d08                    mov ecx, dword ptr [ebp + 8]
00462467  8b048d50585800            mov eax, dword ptr [ecx*4 + 0x585850]
0046246E  dd80a8000000              fld qword ptr [eax + 0xa8]
00462474  d81dd4244600              fcomp dword ptr [0x4624d4]
0046247A  dfe0                      fnstsw ax
0046247C  9e                        sahf 
0046247D  7318                      jae 0x462497
0046247F  8b5508                    mov edx, dword ptr [ebp + 8]
00462482  8b0c9550585800            mov ecx, dword ptr [edx*4 + 0x585850]
00462489  33c0                      xor eax, eax
0046248B  8981a8000000              mov dword ptr [ecx + 0xa8], eax
00462491  8981ac000000              mov dword ptr [ecx + 0xac], eax
00462497  8b55a0                    mov edx, dword ptr [ebp - 0x60]
0046249A  64891500000000            mov dword ptr fs:[0], edx
004624A1  8be5                      mov esp, ebp
004624A3  5d                        pop ebp
004624A4  c3                        ret 
