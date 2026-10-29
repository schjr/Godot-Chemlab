0049a61c push ebp
0049a61d mov ebp, esp
0049a61f add esp, -0x24
0049a622 push ebx
0049a623 mov dword ptr [ebp - 0xc], ecx
0049a626 mov dword ptr [ebp - 8], edx
0049a629 mov dword ptr [ebp - 4], eax
0049a62c mov eax, dword ptr [ebp + 0x10]
0049a62f mov edx, dword ptr [ebp - 4]
0049a632 mov dword ptr [edx + 0xfc18], eax
0049a638 mov ecx, dword ptr [ebp + 0xc]
0049a63b mov eax, dword ptr [ebp - 4]
0049a63e mov dword ptr [eax + 0xfc1c], ecx
0049a644 cmp dword ptr [ebp + 0x14], 4
0049a648 jle 0x49a651
0049a64a mov dword ptr [ebp + 0x14], 4
0049a651 cmp dword ptr [ebp + 0x1c], 0
0049a655 jge 0x49a65e
0049a657 mov dword ptr [ebp + 0x1c], 1
0049a65e mov edx, dword ptr [ebp - 4]
0049a661 inc dword ptr [edx + 0xfc10]
0049a667 mov byte ptr [ebp - 0x11], 1
0049a66b mov ecx, dword ptr [ebp - 4]
0049a66e mov eax, dword ptr [ecx + 0x5150]
0049a674 mov dword ptr [ebp - 0x10], eax
0049a677 mov edx, dword ptr [ebp - 4]
0049a67a mov ecx, dword ptr [edx + 0x5150]
0049a680 add ecx, dword ptr [ebp + 0x1c]
0049a683 mov dword ptr [ebp - 0x18], ecx
0049a686 mov eax, dword ptr [ebp - 4]
0049a689 cmp dword ptr [eax + 0x5150], 0x190
0049a693 jg 0x49aa55
0049a699 mov edx, dword ptr [ebp - 4]
0049a69c mov eax, dword ptr [edx + 0xfc10]
0049a6a2 mov ecx, 3
0049a6a7 cdq 
0049a6a8 idiv ecx
0049a6aa test edx, edx
0049a6ac jne 0x49a6b4
0049a6ae mov byte ptr [ebp - 0x11], 1
0049a6b2 jmp 0x49a6b8
0049a6b4 mov byte ptr [ebp - 0x11], 0
0049a6b8 mov eax, dword ptr [ebp - 4]
0049a6bb cmp byte ptr [eax + 0x7ef4], 0
0049a6c2 je 0x49aa55
0049a6c8 cmp byte ptr [ebp - 0x11], 0
0049a6cc je 0x49aa55
0049a6d2 mov edx, dword ptr [ebp - 0x10]
0049a6d5 cmp edx, dword ptr [ebp - 0x18]
0049a6d8 jge 0x49aa55
0049a6de mov ecx, dword ptr [ebp - 4]
0049a6e1 cmp dword ptr [ecx + 0x7ef8], 0
0049a6e8 je 0x49a776
0049a6ee xor eax, eax
0049a6f0 mov dword ptr [ebp - 0x1c], eax
0049a6f3 mov byte ptr [ebp - 0x1d], 1
0049a6f7 mov edx, dword ptr [ebp - 4]
0049a6fa push dword ptr [edx + 0xdcc8]
0049a700 call 0x4028ec
0049a705 pop ecx
0049a706 mov dword ptr [ebp - 0x1c], eax
0049a709 mov ecx, dword ptr [ebp - 0x1c]
0049a70c mov eax, dword ptr [ebp - 4]
0049a70f mov edx, dword ptr [eax + ecx*8 + 0xbd88]
0049a716 mov ecx, dword ptr [ebp - 8]
0049a719 inc ecx
0049a71a cmp edx, ecx
0049a71c jle 0x49a770
0049a71e mov eax, dword ptr [ebp - 0x1c]
0049a721 mov edx, dword ptr [ebp - 4]
0049a724 mov ecx, dword ptr [edx + eax*8 + 0xbd88]
0049a72b mov eax, dword ptr [ebp - 0xc]
0049a72e dec eax
0049a72f cmp ecx, eax
0049a731 jge 0x49a770
0049a733 mov edx, dword ptr [ebp - 0x1c]
0049a736 mov ecx, dword ptr [ebp - 4]
0049a739 fild dword ptr [ecx + edx*8 + 0xbd88]
0049a740 imul eax, dword ptr [ebp - 0x10], 0xd
0049a744 mov edx, dword ptr [ebp - 4]
0049a747 fstp dword ptr [edx + eax*4 + 0x10]
0049a74b mov ecx, dword ptr [ebp - 0x1c]
0049a74e mov eax, dword ptr [ebp - 4]
0049a751 mov edx, dword ptr [eax + ecx*8 + 0xbd8c]
0049a758 add edx, -5
0049a75b mov dword ptr [ebp - 0x24], edx
0049a75e fild dword ptr [ebp - 0x24]
0049a761 imul ecx, dword ptr [ebp - 0x10], 0xd
0049a765 mov eax, dword ptr [ebp - 4]
0049a768 fstp dword ptr [eax + ecx*4 + 0x14]
0049a76c mov byte ptr [ebp - 0x1d], 0
0049a770 cmp byte ptr [ebp - 0x1d], 0
0049a774 jne 0x49a6f7
0049a776 mov edx, dword ptr [ebp - 4]
0049a779 cmp dword ptr [edx + 0x7ef8], 0
0049a780 jne 0x49a87f
0049a786 mov ecx, dword ptr [ebp - 4]
0049a789 cmp dword ptr [ecx + 0xfc18], 0
0049a790 jne 0x49a805
0049a792 mov eax, dword ptr [ebp - 4]
0049a795 cmp dword ptr [eax + 0xfc1c], 0
0049a79c jne 0x49a805
0049a79e imul edx, dword ptr [ebp - 0x10], 0xd
0049a7a2 mov ecx, dword ptr [ebp - 4]
0049a7a5 mov byte ptr [ecx + edx*4 + 0x38], 0
0049a7aa mov eax, dword ptr [ebp - 4]
0049a7ad mov edx, dword ptr [eax + 0x5164]
0049a7b3 mov ecx, dword ptr [ebp - 4]
0049a7b6 sub edx, dword ptr [ecx + 0x515c]
0049a7bc sub edx, dword ptr [ebp - 8]
0049a7bf add edx, -0xa
0049a7c2 push edx
0049a7c3 call 0x4028ec
0049a7c8 pop ecx
0049a7c9 add eax, dword ptr [ebp - 8]
0049a7cc mov dword ptr [ebp - 0x24], eax
0049a7cf fild dword ptr [ebp - 0x24]
0049a7d2 imul eax, dword ptr [ebp - 0x10], 0xd
0049a7d6 mov edx, dword ptr [ebp - 4]
0049a7d9 fstp dword ptr [edx + eax*4 + 0x10]
0049a7dd mov ecx, dword ptr [ebp - 4]
0049a7e0 mov eax, dword ptr [ecx + 0x5168]
0049a7e6 mov edx, dword ptr [ebp - 4]
0049a7e9 sub eax, dword ptr [edx + 0x5160]
0049a7ef sub eax, dword ptr [ebp + 0x20]
0049a7f2 mov dword ptr [ebp - 0x24], eax
0049a7f5 fild dword ptr [ebp - 0x24]
0049a7f8 imul ecx, dword ptr [ebp - 0x10], 0xd
0049a7fc mov eax, dword ptr [ebp - 4]
0049a7ff fstp dword ptr [eax + ecx*4 + 0x14]
0049a803 jmp 0x49a86d
0049a805 imul edx, dword ptr [ebp - 0x10], 0xd
0049a809 mov ecx, dword ptr [ebp - 4]
0049a80c mov byte ptr [ecx + edx*4 + 0x38], 1
0049a811 push 2
0049a813 call 0x4028ec
0049a818 pop ecx
0049a819 mov ebx, eax
0049a81b mov eax, dword ptr [ebp - 4]
0049a81e add ebx, dword ptr [eax + 0xfc18]
0049a824 push 2
0049a826 call 0x4028ec
0049a82b pop ecx
0049a82c sub ebx, eax
0049a82e mov dword ptr [ebp - 0x24], ebx
0049a831 fild dword ptr [ebp - 0x24]
0049a834 imul edx, dword ptr [ebp - 0x10], 0xd
0049a838 mov ecx, dword ptr [ebp - 4]
0049a83b fstp dword ptr [ecx + edx*4 + 0x10]
0049a83f push 2
0049a841 call 0x4028ec
0049a846 pop ecx
0049a847 mov ebx, eax
0049a849 mov eax, dword ptr [ebp - 4]
0049a84c add ebx, dword ptr [eax + 0xfc1c]
0049a852 push 2
0049a854 call 0x4028ec
0049a859 pop ecx
0049a85a sub ebx, eax
0049a85c mov dword ptr [ebp - 0x24], ebx
0049a85f fild dword ptr [ebp - 0x24]
0049a862 imul edx, dword ptr [ebp - 0x10], 0xd
0049a866 mov ecx, dword ptr [ebp - 4]
0049a869 fstp dword ptr [ecx + edx*4 + 0x14]
0049a86d cmp dword ptr [ebp + 8], 1
0049a871 jne 0x49a87f
0049a873 imul eax, dword ptr [ebp - 0x10], 0xd
0049a877 mov edx, dword ptr [ebp - 4]
0049a87a mov byte ptr [edx + eax*4 + 0x38], 0
0049a87f push 3
0049a881 call 0x4028ec
0049a886 pop ecx
0049a887 mov dword ptr [ebp - 0x24], eax
0049a88a fild dword ptr [ebp - 0x24]
0049a88d fmul qword ptr [0x49aa5c]
0049a893 fmul qword ptr [0x49aa64]
0049a899 fadd qword ptr [0x49aa6c]
0049a89f imul ecx, dword ptr [ebp - 0x10], 0xd
0049a8a3 mov eax, dword ptr [ebp - 4]
0049a8a6 fstp dword ptr [eax + ecx*4 + 0x18]
0049a8aa push 3
0049a8ac call 0x4028ec
0049a8b1 pop ecx
0049a8b2 mov dword ptr [ebp - 0x24], eax
0049a8b5 fild dword ptr [ebp - 0x24]
0049a8b8 fmul qword ptr [0x49aa74]
0049a8be fmul qword ptr [0x49aa64]
0049a8c4 fadd qword ptr [0x49aa7c]
0049a8ca imul edx, dword ptr [ebp - 0x10], 0xd
0049a8ce mov ecx, dword ptr [ebp - 4]
0049a8d1 fstp dword ptr [ecx + edx*4 + 0x20]
0049a8d5 imul eax, dword ptr [ebp - 0x10], 0xd
0049a8d9 mov edx, dword ptr [ebp - 4]
0049a8dc mov dword ptr [edx + eax*4 + 0x24], 0x3f800000
0049a8e4 imul eax, dword ptr [ebp - 0x10], 0xd
0049a8e8 mov edx, dword ptr [ebp - 4]
0049a8eb mov ecx, dword ptr [ebp - 4]
0049a8ee mov ecx, dword ptr [ecx + 0x5154]
0049a8f4 mov dword ptr [edx + eax*4 + 0x2c], ecx
0049a8f8 imul eax, dword ptr [ebp - 0x10], 0xd
0049a8fc mov edx, dword ptr [ebp - 4]
0049a8ff mov eax, dword ptr [edx + eax*4 + 0x24]
0049a903 imul edx, dword ptr [ebp - 0x10], 0xd
0049a907 mov ecx, dword ptr [ebp - 4]
0049a90a mov dword ptr [ecx + edx*4 + 0x30], eax
0049a90e cmp dword ptr [ebp + 0x14], 0
0049a912 jg 0x49a953
0049a914 imul eax, dword ptr [ebp - 0x10], 0xd
0049a918 mov edx, dword ptr [ebp - 4]
0049a91b mov dword ptr [edx + eax*4 + 0x34], 1
0049a923 imul ecx, dword ptr [ebp - 0x10], 0xd
0049a927 mov eax, dword ptr [ebp - 4]
0049a92a push dword ptr [eax + ecx*4 + 0x34]
0049a92e mov eax, dword ptr [ebp + 0x18]
0049a931 pop edx
0049a932 mov ecx, edx
0049a934 cdq 
0049a935 idiv ecx
0049a937 add eax, -5
0049a93a push eax
0049a93b call 0x4028ec
0049a940 pop ecx
0049a941 inc eax
0049a942 mov dword ptr [ebp - 0x24], eax
0049a945 fild dword ptr [ebp - 0x24]
0049a948 imul eax, dword ptr [ebp - 0x10], 0xd
0049a94c mov edx, dword ptr [ebp - 4]
0049a94f fstp dword ptr [edx + eax*4 + 0x1c]
0049a953 cmp dword ptr [ebp + 0x14], 0
0049a957 jle 0x49aa3d
0049a95d cmp dword ptr [ebp + 0x14], 4
0049a961 jge 0x49a96a
0049a963 mov dword ptr [ebp + 0x14], 2
0049a96a push dword ptr [ebp + 0x14]
0049a96d call 0x4028ec
0049a972 pop ecx
0049a973 inc eax
0049a974 imul ecx, dword ptr [ebp - 0x10], 0xd
0049a978 mov edx, dword ptr [ebp - 4]
0049a97b mov dword ptr [edx + ecx*4 + 0x34], eax
0049a97f imul eax, dword ptr [ebp - 0x10], 0xd
0049a983 mov ecx, dword ptr [ebp - 4]
0049a986 cmp dword ptr [ecx + eax*4 + 0x34], 2
0049a98b jne 0x49a9b2
0049a98d imul eax, dword ptr [ebp - 0x10], 0xd
0049a991 mov edx, dword ptr [ebp - 4]
0049a994 push dword ptr [edx + eax*4 + 0x34]
0049a998 mov eax, dword ptr [ebp + 0x18]
0049a99b pop edx
0049a99c mov ecx, edx
0049a99e cdq 
0049a99f idiv ecx
0049a9a1 mov dword ptr [ebp - 0x24], eax
0049a9a4 fild dword ptr [ebp - 0x24]
0049a9a7 imul eax, dword ptr [ebp - 0x10], 0xd
0049a9ab mov edx, dword ptr [ebp - 4]
0049a9ae fstp dword ptr [edx + eax*4 + 0x1c]
0049a9b2 imul eax, dword ptr [ebp - 0x10], 0xd
0049a9b6 mov ecx, dword ptr [ebp - 4]
0049a9b9 cmp dword ptr [ecx + eax*4 + 0x34], 2
0049a9be jle 0x49a9e5
0049a9c0 imul eax, dword ptr [ebp - 0x10], 0xd
0049a9c4 mov edx, dword ptr [ebp - 4]
0049a9c7 push dword ptr [edx + eax*4 + 0x34]
0049a9cb mov eax, dword ptr [ebp + 0x18]
0049a9ce pop edx
0049a9cf mov ecx, edx
0049a9d1 cdq 
0049a9d2 idiv ecx
0049a9d4 mov dword ptr [ebp - 0x24], eax
0049a9d7 fild dword ptr [ebp - 0x24]
0049a9da imul eax, dword ptr [ebp - 0x10], 0xd
0049a9de mov edx, dword ptr [ebp - 4]
0049a9e1 fstp dword ptr [edx + eax*4 + 0x1c]
0049a9e5 imul eax, dword ptr [ebp - 0x10], 0xd
0049a9e9 mov ecx, dword ptr [ebp - 4]
0049a9ec cmp dword ptr [ecx + eax*4 + 0x34], 1
0049a9f1 jne 0x49aa18
0049a9f3 imul eax, dword ptr [ebp - 0x10], 0xd
0049a9f7 mov edx, dword ptr [ebp - 4]
0049a9fa push dword ptr [edx + eax*4 + 0x34]
0049a9fe mov eax, dword ptr [ebp + 0x18]
0049aa01 pop edx
0049aa02 mov ecx, edx
0049aa04 cdq 
0049aa05 idiv ecx
0049aa07 mov dword ptr [ebp - 0x24], eax
0049aa0a fild dword ptr [ebp - 0x24]
0049aa0d imul eax, dword ptr [ebp - 0x10], 0xd
0049aa11 mov edx, dword ptr [ebp - 4]
0049aa14 fstp dword ptr [edx + eax*4 + 0x1c]
0049aa18 imul eax, dword ptr [ebp - 0x10], 0xd
0049aa1c mov ecx, dword ptr [ebp - 4]
0049aa1f fld dword ptr [ecx + eax*4 + 0x1c]
0049aa23 fcomp dword ptr [0x49aa84]
0049aa29 fnstsw ax
0049aa2b sahf 
0049aa2c jne 0x49aa3d
0049aa2e imul edx, dword ptr [ebp - 0x10], 0xd
0049aa32 mov ecx, dword ptr [ebp - 4]
0049aa35 mov dword ptr [ecx + edx*4 + 0x1c], 0x3f800000
0049aa3d mov edx, dword ptr [ebp - 4]
0049aa40 inc dword ptr [edx + 0x5150]
0049aa46 inc dword ptr [ebp - 0x10]
0049aa49 mov ecx, dword ptr [ebp - 0x10]
0049aa4c cmp ecx, dword ptr [ebp - 0x18]
0049aa4f jl 0x49a6de
0049aa55 pop ebx
0049aa56 mov esp, ebp
0049aa58 pop ebp
0049aa59 ret 0x1c
0049aa5c sbb al, 0xc7
0049aa5e jno 0x49aa7c
