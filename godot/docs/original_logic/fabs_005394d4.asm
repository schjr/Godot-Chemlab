; Actual main.exe instructions, SHA256 7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c
; Capstone 5.0.7 offline decoding, no execution.
005394D4  55                        push ebp
005394D5  8bec                      mov ebp, esp
005394D7  9b                        wait 
005394D8  80650f7f                  and byte ptr [ebp + 0xf], 0x7f
005394DC  dd4508                    fld qword ptr [ebp + 8]
005394DF  5d                        pop ebp
005394E0  c3                        ret 
