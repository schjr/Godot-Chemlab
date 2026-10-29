0049aa88 push ebp
0049aa89 mov ebp, esp
0049aa8b add esp, -0x48
0049aa8e push ebx
0049aa8f push esi
0049aa90 push edi
0049aa91 mov dword ptr [ebp - 4], eax
0049aa94 xor eax, eax
0049aa96 mov dword ptr [ebp - 8], eax
0049aa99 jmp 0x49aaf4
0049aa9b imul edx, dword ptr [ebp - 8], 0xd
0049aa9f mov ecx, dword ptr [ebp - 4]
0049aaa2 fld dword ptr [ecx + edx*4 + 0x24]
0049aaa6 fcomp dword ptr [0x49b368]
0049aaac fnstsw ax
0049aaae sahf 
0049aaaf ja 0x49aaf1
0049aab1 mov edx, dword ptr [ebp - 8]
0049aab4 mov dword ptr [ebp - 0xc], edx
0049aab7 jmp 0x49aad9
0049aab9 imul ecx, dword ptr [ebp - 0xc], 0xd
0049aabd mov eax, dword ptr [ebp - 4]
0049aac0 imul edx, dword ptr [ebp - 0xc], 0xd
0049aac4 mov ebx, dword ptr [ebp - 4]
0049aac7 lea esi, [eax + ecx*4 + 0x44]
0049aacb lea edi, [ebx + edx*4 + 0x10]
0049aacf mov ecx, 0xd
0049aad4 rep movsd dword ptr es:[edi], dword ptr [esi]
0049aad6 inc dword ptr [ebp - 0xc]
0049aad9 mov eax, dword ptr [ebp - 4]
0049aadc mov edx, dword ptr [eax + 0x5150]
0049aae2 dec edx
0049aae3 cmp edx, dword ptr [ebp - 0xc]
0049aae6 jg 0x49aab9
0049aae8 mov ecx, dword ptr [ebp - 4]
0049aaeb dec dword ptr [ecx + 0x5150]
0049aaf1 inc dword ptr [ebp - 8]
0049aaf4 mov eax, dword ptr [ebp - 8]
0049aaf7 mov edx, dword ptr [ebp - 4]
0049aafa cmp eax, dword ptr [edx + 0x5150]
0049ab00 jl 0x49aa9b
0049ab02 mov ecx, dword ptr [ebp - 4]
0049ab05 cmp dword ptr [ecx + 0x7ef8], 0
0049ab0c jne 0x49ad15
0049ab12 xor eax, eax
0049ab14 mov dword ptr [ebp - 0x10], eax
0049ab17 jmp 0x49ad03
0049ab1c imul edx, dword ptr [ebp - 0x10], 0xd
0049ab20 mov ecx, dword ptr [ebp - 4]
0049ab23 fld dword ptr [ecx + edx*4 + 0x18]
0049ab27 add esp, -8
0049ab2a fstp qword ptr [esp]
0049ab2d call 0x539238
0049ab32 add esp, 8
0049ab35 imul eax, dword ptr [ebp - 0x10], 0xd
0049ab39 mov edx, dword ptr [ebp - 4]
0049ab3c fmul dword ptr [edx + eax*4 + 0x1c]
0049ab40 imul ecx, dword ptr [ebp - 0x10], 0xd
0049ab44 mov eax, dword ptr [ebp - 4]
0049ab47 fadd dword ptr [eax + ecx*4 + 0x10]
0049ab4b fstp dword ptr [eax + ecx*4 + 0x10]
0049ab4f imul edx, dword ptr [ebp - 0x10], 0xd
0049ab53 mov ecx, dword ptr [ebp - 4]
0049ab56 cmp byte ptr [ecx + edx*4 + 0x38], 0
0049ab5b jne 0x49ab77
0049ab5d imul eax, dword ptr [ebp - 0x10], 0xd
0049ab61 mov edx, dword ptr [ebp - 4]
0049ab64 fld dword ptr [edx + eax*4 + 0x1c]
0049ab68 imul ecx, dword ptr [ebp - 0x10], 0xd
0049ab6c mov eax, dword ptr [ebp - 4]
0049ab6f fsubr dword ptr [eax + ecx*4 + 0x14]
0049ab73 fstp dword ptr [eax + ecx*4 + 0x14]
0049ab77 imul edx, dword ptr [ebp - 0x10], 0xd
0049ab7b mov ecx, dword ptr [ebp - 4]
0049ab7e cmp byte ptr [ecx + edx*4 + 0x38], 1
0049ab83 jne 0x49ac0d
0049ab89 mov eax, dword ptr [ebp - 4]
0049ab8c mov edx, dword ptr [eax + 0xfc1c]
0049ab92 dec edx
0049ab93 mov dword ptr [ebp - 0x3c], edx
0049ab96 fild dword ptr [ebp - 0x3c]
0049ab99 imul ecx, dword ptr [ebp - 0x10], 0xd
0049ab9d mov eax, dword ptr [ebp - 4]
0049aba0 fcomp dword ptr [eax + ecx*4 + 0x14]
0049aba4 fnstsw ax
0049aba6 sahf 
0049aba7 jae 0x49abe7
0049aba9 mov edx, dword ptr [ebp - 4]
0049abac mov ecx, dword ptr [edx + 0xfc1c]
0049abb2 add ecx, 0xc
0049abb5 mov dword ptr [ebp - 0x40], ecx
0049abb8 fild dword ptr [ebp - 0x40]
0049abbb imul eax, dword ptr [ebp - 0x10], 0xd
0049abbf mov edx, dword ptr [ebp - 4]
0049abc2 fcomp dword ptr [edx + eax*4 + 0x14]
0049abc6 fnstsw ax
0049abc8 sahf 
0049abc9 jbe 0x49abe7
0049abcb imul edx, dword ptr [ebp - 0x10], 0xd
0049abcf mov ecx, dword ptr [ebp - 4]
0049abd2 fld dword ptr [ecx + edx*4 + 0x1c]
0049abd6 imul eax, dword ptr [ebp - 0x10], 0xd
0049abda mov edx, dword ptr [ebp - 4]
0049abdd fadd dword ptr [edx + eax*4 + 0x14]
0049abe1 fstp dword ptr [edx + eax*4 + 0x14]
0049abe5 jmp 0x49ac0d
0049abe7 imul ecx, dword ptr [ebp - 0x10], 0xd
0049abeb mov eax, dword ptr [ebp - 4]
0049abee fld dword ptr [eax + ecx*4 + 0x1c]
0049abf2 imul edx, dword ptr [ebp - 0x10], 0xd
0049abf6 mov ecx, dword ptr [ebp - 4]
0049abf9 fsubr dword ptr [ecx + edx*4 + 0x14]
0049abfd fstp dword ptr [ecx + edx*4 + 0x14]
0049ac01 imul eax, dword ptr [ebp - 0x10], 0xd
0049ac05 mov edx, dword ptr [ebp - 4]
0049ac08 mov byte ptr [edx + eax*4 + 0x38], 0
0049ac0d push 2
0049ac0f call 0x4028ec
0049ac14 pop ecx
0049ac15 mov dword ptr [ebp - 0x3c], eax
0049ac18 fild dword ptr [ebp - 0x3c]
0049ac1b imul ecx, dword ptr [ebp - 0x10], 0xd
0049ac1f mov eax, dword ptr [ebp - 4]
0049ac22 fmul dword ptr [eax + ecx*4 + 0x20]
0049ac26 imul edx, dword ptr [ebp - 0x10], 0xd
0049ac2a mov ecx, dword ptr [ebp - 4]
0049ac2d fadd dword ptr [ecx + edx*4 + 0x18]
0049ac31 fstp dword ptr [ecx + edx*4 + 0x18]
0049ac35 imul eax, dword ptr [ebp - 0x10], 0xd
0049ac39 mov edx, dword ptr [ebp - 4]
0049ac3c fld dword ptr [edx + eax*4 + 0x14]
0049ac40 fsub dword ptr [0x49b36c]
0049ac46 mov ecx, dword ptr [ebp - 4]
0049ac49 fild dword ptr [ecx + 0x7f00]
0049ac4f fcompp 
0049ac51 fnstsw ax
0049ac53 sahf 
0049ac54 jb 0x49ac65
0049ac56 imul edx, dword ptr [ebp - 0x10], 0xd
0049ac5a mov ecx, dword ptr [ebp - 4]
0049ac5d mov dword ptr [ecx + edx*4 + 0x24], 0xbf800000
0049ac65 imul edx, dword ptr [ebp - 0x10], 0xd
0049ac69 mov ecx, dword ptr [ebp - 4]
0049ac6c mov eax, dword ptr [ecx + edx*4 + 0x34]
0049ac70 sar eax, 1
0049ac72 jns 0x49ac77
0049ac74 adc eax, 0
0049ac77 mov dword ptr [ebp - 0x3c], eax
0049ac7a fild dword ptr [ebp - 0x3c]
0049ac7d imul edx, dword ptr [ebp - 0x10], 0xd
0049ac81 mov ecx, dword ptr [ebp - 4]
0049ac84 fsubr dword ptr [ecx + edx*4 + 0x10]
0049ac88 fcomp dword ptr [0x49b368]
0049ac8e fnstsw ax
0049ac90 sahf 
0049ac91 jae 0x49acaf
0049ac93 fld qword ptr [0x49b370]
0049ac99 imul edx, dword ptr [ebp - 0x10], 0xd
0049ac9d mov ecx, dword ptr [ebp - 4]
0049aca0 fsub dword ptr [ecx + edx*4 + 0x18]
0049aca4 imul eax, dword ptr [ebp - 0x10], 0xd
0049aca8 mov edx, dword ptr [ebp - 4]
0049acab fstp dword ptr [edx + eax*4 + 0x18]
0049acaf imul ecx, dword ptr [ebp - 0x10], 0xd
0049acb3 mov eax, dword ptr [ebp - 4]
0049acb6 fild dword ptr [eax + ecx*4 + 0x34]
0049acba imul edx, dword ptr [ebp - 0x10], 0xd
0049acbe mov ecx, dword ptr [ebp - 4]
0049acc1 fadd dword ptr [ecx + edx*4 + 0x10]
0049acc5 mov eax, dword ptr [ebp - 4]
0049acc8 mov edx, dword ptr [eax + 0x5164]
0049acce mov ecx, dword ptr [ebp - 4]
0049acd1 sub edx, dword ptr [ecx + 0x515c]
0049acd7 mov dword ptr [ebp - 0x3c], edx
0049acda fild dword ptr [ebp - 0x3c]
0049acdd fcompp 
0049acdf fnstsw ax
0049ace1 sahf 
0049ace2 jae 0x49ad00
0049ace4 fld qword ptr [0x49b370]
0049acea imul edx, dword ptr [ebp - 0x10], 0xd
0049acee mov ecx, dword ptr [ebp - 4]
0049acf1 fsub dword ptr [ecx + edx*4 + 0x18]
0049acf5 imul eax, dword ptr [ebp - 0x10], 0xd
0049acf9 mov edx, dword ptr [ebp - 4]
0049acfc fstp dword ptr [edx + eax*4 + 0x18]
0049ad00 inc dword ptr [ebp - 0x10]
0049ad03 mov ecx, dword ptr [ebp - 0x10]
0049ad06 mov eax, dword ptr [ebp - 4]
0049ad09 cmp ecx, dword ptr [eax + 0x5150]
0049ad0f jl 0x49ab1c
0049ad15 mov edx, dword ptr [ebp - 4]
0049ad18 cmp dword ptr [edx + 0x7ef8], 0
0049ad1f je 0x49b360
0049ad25 xor ecx, ecx
0049ad27 mov dword ptr [ebp - 0x14], ecx
0049ad2a jmp 0x49b34e
0049ad2f imul eax, dword ptr [ebp - 0x14], 0xd
0049ad33 mov edx, dword ptr [ebp - 4]
0049ad36 fld dword ptr [edx + eax*4 + 0x14]
0049ad3a fsub dword ptr [0x49b378]
0049ad40 mov ecx, dword ptr [ebp - 4]
0049ad43 fild dword ptr [ecx + 0x7f00]
0049ad49 fcompp 
0049ad4b fnstsw ax
0049ad4d sahf 
0049ad4e jb 0x49ad64
0049ad50 imul edx, dword ptr [ebp - 0x14], 0xd
0049ad54 mov ecx, dword ptr [ebp - 4]
0049ad57 mov dword ptr [ecx + edx*4 + 0x24], 0xbf800000
0049ad5f jmp 0x49b34b
0049ad64 push 2
0049ad66 call 0x4028ec
0049ad6b pop ecx
0049ad6c mov dword ptr [ebp - 0x18], eax
0049ad6f fild dword ptr [ebp - 0x18]
0049ad72 imul edx, dword ptr [ebp - 0x14], 0xd
0049ad76 mov ecx, dword ptr [ebp - 4]
0049ad79 fmul dword ptr [ecx + edx*4 + 0x20]
0049ad7d imul eax, dword ptr [ebp - 0x14], 0xd
0049ad81 mov edx, dword ptr [ebp - 4]
0049ad84 fadd dword ptr [edx + eax*4 + 0x18]
0049ad88 fstp dword ptr [ebp - 0x1c]
0049ad8b fld dword ptr [ebp - 0x1c]
0049ad8e add esp, -8
0049ad91 fstp qword ptr [esp]
0049ad94 call 0x539238
0049ad99 add esp, 8
0049ad9c imul ecx, dword ptr [ebp - 0x14], 0xd
0049ada0 mov eax, dword ptr [ebp - 4]
0049ada3 fmul dword ptr [eax + ecx*4 + 0x1c]
0049ada7 imul edx, dword ptr [ebp - 0x14], 0xd
0049adab mov ecx, dword ptr [ebp - 4]
0049adae fsubr dword ptr [ecx + edx*4 + 0x10]
0049adb2 fstp dword ptr [ebp - 0x20]
0049adb5 fld dword ptr [ebp - 0x1c]
0049adb8 add esp, -8
0049adbb fstp qword ptr [esp]
0049adbe call 0x53aca8
0049adc3 add esp, 8
0049adc6 imul eax, dword ptr [ebp - 0x14], 0xd
0049adca mov edx, dword ptr [ebp - 4]
0049adcd fmul dword ptr [edx + eax*4 + 0x1c]
0049add1 imul ecx, dword ptr [ebp - 0x14], 0xd
0049add5 mov eax, dword ptr [ebp - 4]
0049add8 fsubr dword ptr [eax + ecx*4 + 0x14]
0049addc fstp dword ptr [ebp - 0x24]
0049addf imul edx, dword ptr [ebp - 0x14], 0xd
0049ade3 mov ecx, dword ptr [ebp - 4]
0049ade6 mov eax, dword ptr [ecx + edx*4 + 0x1c]
0049adea mov dword ptr [ebp - 0x28], eax
0049aded mov byte ptr [ebp - 0x29], 1
0049adf1 xor edx, edx
0049adf3 mov dword ptr [ebp - 0x38], edx
0049adf6 jmp 0x49af61
0049adfb mov ecx, dword ptr [ebp - 0x38]
0049adfe mov eax, dword ptr [ebp - 4]
0049ae01 fild dword ptr [eax + ecx*8 + 0x7f08]
0049ae08 fsubr dword ptr [ebp - 0x20]
0049ae0b fld dword ptr [ebp - 0x28]
0049ae0e fadd dword ptr [0x49b378]
0049ae14 fcompp 
0049ae16 fnstsw ax
0049ae18 sahf 
0049ae19 seta dl
0049ae1c and edx, 1
0049ae1f mov dword ptr [ebp - 0x3c], edx
0049ae22 fild dword ptr [ebp - 0x3c]
0049ae25 add esp, -8
0049ae28 fstp qword ptr [esp]
0049ae2b call 0x5394d4
0049ae30 add esp, 8
0049ae33 fcomp dword ptr [0x49b368]
0049ae39 fnstsw ax
0049ae3b sahf 
0049ae3c je 0x49af5e
0049ae42 mov edx, dword ptr [ebp - 0x38]
0049ae45 mov ecx, dword ptr [ebp - 4]
0049ae48 fild dword ptr [ecx + edx*8 + 0x7f08]
0049ae4f fsubr dword ptr [ebp - 0x20]
0049ae52 fcomp dword ptr [0x49b368]
0049ae58 fnstsw ax
0049ae5a sahf 
0049ae5b seta dl
0049ae5e and edx, 1
0049ae61 mov dword ptr [ebp - 0x40], edx
0049ae64 fild dword ptr [ebp - 0x40]
0049ae67 add esp, -8
0049ae6a fstp qword ptr [esp]
0049ae6d call 0x5394d4
0049ae72 add esp, 8
0049ae75 fcomp dword ptr [0x49b368]
0049ae7b fnstsw ax
0049ae7d sahf 
0049ae7e je 0x49af5e
0049ae84 mov edx, dword ptr [ebp - 0x38]
0049ae87 mov ecx, dword ptr [ebp - 4]
0049ae8a fild dword ptr [ecx + edx*8 + 0x7f0c]
0049ae91 fsubr dword ptr [ebp - 0x24]
0049ae94 fld dword ptr [ebp - 0x28]
0049ae97 fadd dword ptr [0x49b378]
0049ae9d fcompp 
0049ae9f fnstsw ax
0049aea1 sahf 
0049aea2 seta dl
0049aea5 and edx, 1
0049aea8 mov dword ptr [ebp - 0x44], edx
0049aeab fild dword ptr [ebp - 0x44]
0049aeae add esp, -8
0049aeb1 fstp qword ptr [esp]
0049aeb4 call 0x5394d4
0049aeb9 add esp, 8
0049aebc fcomp dword ptr [0x49b368]
0049aec2 fnstsw ax
0049aec4 sahf 
0049aec5 je 0x49af5e
0049aecb mov edx, dword ptr [ebp - 0x38]
0049aece mov ecx, dword ptr [ebp - 4]
0049aed1 fild dword ptr [ecx + edx*8 + 0x7f0c]
0049aed8 fsubr dword ptr [ebp - 0x24]
0049aedb fcomp dword ptr [0x49b368]
0049aee1 fnstsw ax
0049aee3 sahf 
0049aee4 seta dl
0049aee7 and edx, 1
0049aeea mov dword ptr [ebp - 0x48], edx
0049aeed fild dword ptr [ebp - 0x48]
0049aef0 add esp, -8
0049aef3 fstp qword ptr [esp]
0049aef6 call 0x5394d4
0049aefb add esp, 8
0049aefe fcomp dword ptr [0x49b368]
0049af04 fnstsw ax
0049af06 sahf 
0049af07 je 0x49af5e
0049af09 fld dword ptr [0x49b37c]
0049af0f mov edx, dword ptr [ebp - 0x38]
0049af12 mov ecx, dword ptr [ebp - 4]
0049af15 fmul dword ptr [ecx + edx*4 + 0xdccc]
0049af1c fadd qword ptr [0x49b370]
0049af22 imul eax, dword ptr [ebp - 0x14], 0xd
0049af26 mov edx, dword ptr [ebp - 4]
0049af29 fsub dword ptr [edx + eax*4 + 0x18]
0049af2d imul ecx, dword ptr [ebp - 0x14], 0xd
0049af31 mov eax, dword ptr [ebp - 4]
0049af34 fstp dword ptr [eax + ecx*4 + 0x18]
0049af38 mov edx, dword ptr [ebp - 0x38]
0049af3b mov ecx, dword ptr [ebp - 4]
0049af3e mov eax, dword ptr [ecx + edx*4 + 0xdccc]
0049af45 mov dword ptr [ebp - 0x30], eax
0049af48 mov edx, dword ptr [ebp - 0x38]
0049af4b mov ecx, dword ptr [ebp - 4]
0049af4e mov eax, dword ptr [ecx + edx*8 + 0x7f0c]
0049af55 mov dword ptr [ebp - 0x34], eax
0049af58 mov byte ptr [ebp - 0x29], 0
0049af5c jmp 0x49af73
0049af5e inc dword ptr [ebp - 0x38]
0049af61 mov edx, dword ptr [ebp - 0x38]
0049af64 mov ecx, dword ptr [ebp - 4]
0049af67 cmp edx, dword ptr [ecx + 0xfc0c]
0049af6d jl 0x49adfb
0049af73 cmp byte ptr [ebp - 0x29], 1
0049af77 jne 0x49afac
0049af79 imul eax, dword ptr [ebp - 0x14], 0xd
0049af7d mov edx, dword ptr [ebp - 4]
0049af80 fld dword ptr [edx + eax*4 + 0x18]
0049af84 add esp, -8
0049af87 fstp qword ptr [esp]
0049af8a call 0x539238
0049af8f add esp, 8
0049af92 imul ecx, dword ptr [ebp - 0x14], 0xd
0049af96 mov eax, dword ptr [ebp - 4]
0049af99 fmul dword ptr [eax + ecx*4 + 0x1c]
0049af9d imul edx, dword ptr [ebp - 0x14], 0xd
0049afa1 mov ecx, dword ptr [ebp - 4]
0049afa4 fsubr dword ptr [ecx + edx*4 + 0x10]
0049afa8 fstp dword ptr [ecx + edx*4 + 0x10]
0049afac cmp byte ptr [ebp - 0x29], 0
0049afb0 jne 0x49b2a6
0049afb6 fld dword ptr [ebp - 0x30]
0049afb9 fcomp qword ptr [0x49b380]
0049afbf fnstsw ax
0049afc1 sahf 
0049afc2 jbe 0x49b072
0049afc8 fld dword ptr [ebp - 0x30]
0049afcb fcomp qword ptr [0x49b388]
0049afd1 fnstsw ax
0049afd3 sahf 
0049afd4 jae 0x49b072
0049afda fild dword ptr [ebp - 0x34]
0049afdd imul edx, dword ptr [ebp - 0x14], 0xd
0049afe1 mov ecx, dword ptr [ebp - 4]
0049afe4 fcomp dword ptr [ecx + edx*4 + 0x14]
0049afe8 fnstsw ax
0049afea sahf 
0049afeb jbe 0x49b026
0049afed imul edx, dword ptr [ebp - 0x14], 0xd
0049aff1 mov ecx, dword ptr [ebp - 4]
0049aff4 fld dword ptr [ecx + edx*4 + 0x18]
0049aff8 add esp, -8
0049affb fstp qword ptr [esp]
0049affe call 0x539238
0049b003 add esp, 8
0049b006 imul eax, dword ptr [ebp - 0x14], 0xd
0049b00a mov edx, dword ptr [ebp - 4]
0049b00d fmul dword ptr [edx + eax*4 + 0x1c]
0049b011 fadd dword ptr [0x49b37c]
0049b017 imul ecx, dword ptr [ebp - 0x14], 0xd
0049b01b mov eax, dword ptr [ebp - 4]
0049b01e fsubr dword ptr [eax + ecx*4 + 0x10]
0049b022 fstp dword ptr [eax + ecx*4 + 0x10]
0049b026 fild dword ptr [ebp - 0x34]
0049b029 imul edx, dword ptr [ebp - 0x14], 0xd
0049b02d mov ecx, dword ptr [ebp - 4]
0049b030 fcomp dword ptr [ecx + edx*4 + 0x14]
0049b034 fnstsw ax
0049b036 sahf 
0049b037 jae 0x49b072
0049b039 imul edx, dword ptr [ebp - 0x14], 0xd
0049b03d mov ecx, dword ptr [ebp - 4]
0049b040 fld dword ptr [ecx + edx*4 + 0x18]
0049b044 add esp, -8
0049b047 fstp qword ptr [esp]
0049b04a call 0x539238
0049b04f add esp, 8
0049b052 imul eax, dword ptr [ebp - 0x14], 0xd
0049b056 mov edx, dword ptr [ebp - 4]
0049b059 fmul dword ptr [edx + eax*4 + 0x1c]
0049b05d fsub dword ptr [0x49b37c]
0049b063 imul ecx, dword ptr [ebp - 0x14], 0xd
0049b067 mov eax, dword ptr [ebp - 4]
0049b06a fsubr dword ptr [eax + ecx*4 + 0x10]
0049b06e fstp dword ptr [eax + ecx*4 + 0x10]
0049b072 fld dword ptr [ebp - 0x30]
0049b075 fcomp qword ptr [0x49b380]
0049b07b fnstsw ax
0049b07d sahf 
0049b07e ja 0x49b12e
0049b084 fld dword ptr [ebp - 0x30]
0049b087 fcomp dword ptr [0x49b368]
0049b08d fnstsw ax
0049b08f sahf 
0049b090 jbe 0x49b12e
0049b096 fild dword ptr [ebp - 0x34]
0049b099 imul edx, dword ptr [ebp - 0x14], 0xd
0049b09d mov ecx, dword ptr [ebp - 4]
0049b0a0 fcomp dword ptr [ecx + edx*4 + 0x14]
0049b0a4 fnstsw ax
0049b0a6 sahf 
0049b0a7 jbe 0x49b0e2
0049b0a9 imul edx, dword ptr [ebp - 0x14], 0xd
0049b0ad mov ecx, dword ptr [ebp - 4]
0049b0b0 fld dword ptr [ecx + edx*4 + 0x18]
0049b0b4 add esp, -8
0049b0b7 fstp qword ptr [esp]
0049b0ba call 0x539238
0049b0bf add esp, 8
0049b0c2 imul eax, dword ptr [ebp - 0x14], 0xd
0049b0c6 mov edx, dword ptr [ebp - 4]
0049b0c9 fmul dword ptr [edx + eax*4 + 0x1c]
0049b0cd fadd dword ptr [0x49b37c]
0049b0d3 imul ecx, dword ptr [ebp - 0x14], 0xd
0049b0d7 mov eax, dword ptr [ebp - 4]
0049b0da fsubr dword ptr [eax + ecx*4 + 0x10]
0049b0de fstp dword ptr [eax + ecx*4 + 0x10]
0049b0e2 fild dword ptr [ebp - 0x34]
0049b0e5 imul edx, dword ptr [ebp - 0x14], 0xd
0049b0e9 mov ecx, dword ptr [ebp - 4]
0049b0ec fcomp dword ptr [ecx + edx*4 + 0x14]
0049b0f0 fnstsw ax
0049b0f2 sahf 
0049b0f3 jae 0x49b12e
0049b0f5 imul edx, dword ptr [ebp - 0x14], 0xd
0049b0f9 mov ecx, dword ptr [ebp - 4]
0049b0fc fld dword ptr [ecx + edx*4 + 0x18]
0049b100 add esp, -8
0049b103 fstp qword ptr [esp]
0049b106 call 0x539238
0049b10b add esp, 8
0049b10e imul eax, dword ptr [ebp - 0x14], 0xd
0049b112 mov edx, dword ptr [ebp - 4]
0049b115 fmul dword ptr [edx + eax*4 + 0x1c]
0049b119 fsub dword ptr [0x49b37c]
0049b11f imul ecx, dword ptr [ebp - 0x14], 0xd
0049b123 mov eax, dword ptr [ebp - 4]
0049b126 fsubr dword ptr [eax + ecx*4 + 0x10]
0049b12a fstp dword ptr [eax + ecx*4 + 0x10]
0049b12e fld dword ptr [ebp - 0x30]
0049b131 fcomp qword ptr [0x49b390]
0049b137 fnstsw ax
0049b139 sahf 
0049b13a jbe 0x49b1ea
0049b140 fld dword ptr [ebp - 0x30]
0049b143 fcomp qword ptr [0x49b398]
0049b149 fnstsw ax
0049b14b sahf 
0049b14c jae 0x49b1ea
0049b152 fild dword ptr [ebp - 0x34]
0049b155 imul edx, dword ptr [ebp - 0x14], 0xd
0049b159 mov ecx, dword ptr [ebp - 4]
0049b15c fcomp dword ptr [ecx + edx*4 + 0x14]
0049b160 fnstsw ax
0049b162 sahf 
0049b163 jbe 0x49b19e
0049b165 imul edx, dword ptr [ebp - 0x14], 0xd
0049b169 mov ecx, dword ptr [ebp - 4]
0049b16c fld dword ptr [ecx + edx*4 + 0x18]
0049b170 add esp, -8
0049b173 fstp qword ptr [esp]
0049b176 call 0x539238
0049b17b add esp, 8
0049b17e imul eax, dword ptr [ebp - 0x14], 0xd
0049b182 mov edx, dword ptr [ebp - 4]
0049b185 fmul dword ptr [edx + eax*4 + 0x1c]
0049b189 fsub dword ptr [0x49b37c]
0049b18f imul ecx, dword ptr [ebp - 0x14], 0xd
0049b193 mov eax, dword ptr [ebp - 4]
0049b196 fsubr dword ptr [eax + ecx*4 + 0x10]
0049b19a fstp dword ptr [eax + ecx*4 + 0x10]
0049b19e fild dword ptr [ebp - 0x34]
0049b1a1 imul edx, dword ptr [ebp - 0x14], 0xd
0049b1a5 mov ecx, dword ptr [ebp - 4]
0049b1a8 fcomp dword ptr [ecx + edx*4 + 0x14]
0049b1ac fnstsw ax
0049b1ae sahf 
0049b1af jae 0x49b1ea
0049b1b1 imul edx, dword ptr [ebp - 0x14], 0xd
0049b1b5 mov ecx, dword ptr [ebp - 4]
0049b1b8 fld dword ptr [ecx + edx*4 + 0x18]
0049b1bc add esp, -8
0049b1bf fstp qword ptr [esp]
0049b1c2 call 0x539238
0049b1c7 add esp, 8
0049b1ca imul eax, dword ptr [ebp - 0x14], 0xd
0049b1ce mov edx, dword ptr [ebp - 4]
0049b1d1 fmul dword ptr [edx + eax*4 + 0x1c]
0049b1d5 fadd dword ptr [0x49b37c]
0049b1db imul ecx, dword ptr [ebp - 0x14], 0xd
0049b1df mov eax, dword ptr [ebp - 4]
0049b1e2 fsubr dword ptr [eax + ecx*4 + 0x10]
0049b1e6 fstp dword ptr [eax + ecx*4 + 0x10]
0049b1ea fld dword ptr [ebp - 0x30]
0049b1ed fcomp qword ptr [0x49b398]
0049b1f3 fnstsw ax
0049b1f5 sahf 
0049b1f6 jbe 0x49b2a6
0049b1fc fld dword ptr [ebp - 0x30]
0049b1ff fcomp qword ptr [0x49b3a0]
0049b205 fnstsw ax
0049b207 sahf 
0049b208 jae 0x49b2a6
0049b20e fild dword ptr [ebp - 0x34]
0049b211 imul edx, dword ptr [ebp - 0x14], 0xd
0049b215 mov ecx, dword ptr [ebp - 4]
0049b218 fcomp dword ptr [ecx + edx*4 + 0x14]
0049b21c fnstsw ax
0049b21e sahf 
0049b21f jbe 0x49b25a
0049b221 imul edx, dword ptr [ebp - 0x14], 0xd
0049b225 mov ecx, dword ptr [ebp - 4]
0049b228 fld dword ptr [ecx + edx*4 + 0x18]
0049b22c add esp, -8
0049b22f fstp qword ptr [esp]
0049b232 call 0x539238
0049b237 add esp, 8
0049b23a imul eax, dword ptr [ebp - 0x14], 0xd
0049b23e mov edx, dword ptr [ebp - 4]
0049b241 fmul dword ptr [edx + eax*4 + 0x1c]
0049b245 fsub dword ptr [0x49b37c]
0049b24b imul ecx, dword ptr [ebp - 0x14], 0xd
0049b24f mov eax, dword ptr [ebp - 4]
0049b252 fsubr dword ptr [eax + ecx*4 + 0x10]
0049b256 fstp dword ptr [eax + ecx*4 + 0x10]
0049b25a fild dword ptr [ebp - 0x34]
0049b25d imul edx, dword ptr [ebp - 0x14], 0xd
0049b261 mov ecx, dword ptr [ebp - 4]
0049b264 fcomp dword ptr [ecx + edx*4 + 0x14]
0049b268 fnstsw ax
0049b26a sahf 
0049b26b jae 0x49b2a6
0049b26d imul edx, dword ptr [ebp - 0x14], 0xd
0049b271 mov ecx, dword ptr [ebp - 4]
0049b274 fld dword ptr [ecx + edx*4 + 0x18]
0049b278 add esp, -8
0049b27b fstp qword ptr [esp]
0049b27e call 0x539238
0049b283 add esp, 8
0049b286 imul eax, dword ptr [ebp - 0x14], 0xd
0049b28a mov edx, dword ptr [ebp - 4]
0049b28d fmul dword ptr [edx + eax*4 + 0x1c]
0049b291 fadd dword ptr [0x49b37c]
0049b297 imul ecx, dword ptr [ebp - 0x14], 0xd
0049b29b mov eax, dword ptr [ebp - 4]
0049b29e fsubr dword ptr [eax + ecx*4 + 0x10]
0049b2a2 fstp dword ptr [eax + ecx*4 + 0x10]
0049b2a6 cmp byte ptr [ebp - 0x29], 0
0049b2aa jne 0x49b30e
0049b2ac imul edx, dword ptr [ebp - 0x14], 0xd
0049b2b0 mov ecx, dword ptr [ebp - 4]
0049b2b3 fld dword ptr [ecx + edx*4 + 0x18]
0049b2b7 add esp, -8
0049b2ba fstp qword ptr [esp]
0049b2bd call 0x53aca8
0049b2c2 add esp, 8
0049b2c5 imul eax, dword ptr [ebp - 0x14], 0xd
0049b2c9 mov edx, dword ptr [ebp - 4]
0049b2cc fmul dword ptr [edx + eax*4 + 0x1c]
0049b2d0 fcomp dword ptr [0x49b368]
0049b2d6 fnstsw ax
0049b2d8 sahf 
0049b2d9 jbe 0x49b30e
0049b2db imul edx, dword ptr [ebp - 0x14], 0xd
0049b2df mov ecx, dword ptr [ebp - 4]
0049b2e2 fld dword ptr [ecx + edx*4 + 0x18]
0049b2e6 add esp, -8
0049b2e9 fstp qword ptr [esp]
0049b2ec call 0x53aca8
0049b2f1 add esp, 8
0049b2f4 imul eax, dword ptr [ebp - 0x14], 0xd
0049b2f8 mov edx, dword ptr [ebp - 4]
0049b2fb fmul dword ptr [edx + eax*4 + 0x1c]
0049b2ff imul ecx, dword ptr [ebp - 0x14], 0xd
0049b303 mov eax, dword ptr [ebp - 4]
0049b306 fsubr dword ptr [eax + ecx*4 + 0x14]
0049b30a fstp dword ptr [eax + ecx*4 + 0x14]
0049b30e cmp byte ptr [ebp - 0x29], 1
0049b312 jne 0x49b32e
0049b314 imul edx, dword ptr [ebp - 0x14], 0xd
0049b318 mov ecx, dword ptr [ebp - 4]
0049b31b fld dword ptr [ecx + edx*4 + 0x1c]
0049b31f imul eax, dword ptr [ebp - 0x14], 0xd
0049b323 mov edx, dword ptr [ebp - 4]
0049b326 fsubr dword ptr [edx + eax*4 + 0x14]
0049b32a fstp dword ptr [edx + eax*4 + 0x14]
0049b32e fild dword ptr [ebp - 0x18]
0049b331 imul ecx, dword ptr [ebp - 0x14], 0xd
0049b335 mov eax, dword ptr [ebp - 4]
0049b338 fmul dword ptr [eax + ecx*4 + 0x20]
0049b33c imul edx, dword ptr [ebp - 0x14], 0xd
0049b340 mov ecx, dword ptr [ebp - 4]
0049b343 fadd dword ptr [ecx + edx*4 + 0x18]
0049b347 fstp dword ptr [ecx + edx*4 + 0x18]
0049b34b inc dword ptr [ebp - 0x14]
0049b34e mov eax, dword ptr [ebp - 0x14]
0049b351 mov edx, dword ptr [ebp - 4]
0049b354 cmp eax, dword ptr [edx + 0x5150]
0049b35a jl 0x49ad2f
0049b360 pop edi
0049b361 pop esi
0049b362 pop ebx
0049b363 mov esp, ebp
0049b365 pop ebp
0049b366 ret 
0049b367 add byte ptr [eax], al
0049b369 add byte ptr [eax], al
0049b36b add byte ptr [eax], al
0049b36d add byte ptr [eax + 0x206ddf40], ah
0049b373 push ebp
0049b374 sti 
0049b375 and dword ptr [ecx], ecx
0049b377 inc eax
0049b378 add byte ptr [eax], al
0049b37a add byte ptr [eax], 0
0049b37e add byte ptr [eax - 0x59], al
0049b381 call 0x2248e1ce
0049b386 stc 
0049b387 aas 
0049b388 cmpsd dword ptr [esi], dword ptr es:[edi]
0049b389 call 0x2248e1d6
0049b38e or dword ptr [eax + 0x6f], eax
0049b391 adc al, byte ptr [ebx + 0x921cac0]
0049b397 inc eax
0049b398 popal 
0049b399 ret 
0049b39a shr dword ptr [ebx], cl
0049b39c fst dword ptr gs:[edx]
0049b39f inc eax
0049b3a0 cmpsd dword ptr [esi], dword ptr es:[edi]
0049b3a1 call 0x2248e1ee
