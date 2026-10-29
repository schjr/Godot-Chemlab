  40c70c: 8b 45 a0                     	movl	-0x60(%ebp), %eax
  40c70f: 8b 14 85 50 58 58 00         	movl	0x585850(,%eax,4), %edx
  40c716: 8b 82 fc 00 00 00            	movl	0xfc(%edx), %eax
  40c71c: e8 27 cd 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c721: 8b 40 14                     	movl	0x14(%eax), %eax
  40c724: ba ff ff ff 00               	movl	$0xffffff, %edx         # imm = 0xFFFFFF
  40c729: e8 2a 7a 0d 00               	calll	0x4e4158 <@Myimage@initialization$qqrv+0x23564>
  40c72e: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c731: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c738: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c73e: e8 05 cd 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c743: 8b 40 10                     	movl	0x10(%eax), %eax
  40c746: ba ff ff ff 00               	movl	$0xffffff, %edx         # imm = 0xFFFFFF
  40c74b: e8 00 77 0d 00               	calll	0x4e3e50 <@Myimage@initialization$qqrv+0x2325c>
  40c750: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c753: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c75a: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c760: e8 e3 cc 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c765: 8b 40 14                     	movl	0x14(%eax), %eax
  40c768: 33 d2                        	xorl	%edx, %edx
  40c76a: e8 05 7b 0d 00               	calll	0x4e4274 <@Myimage@initialization$qqrv+0x23680>
  40c76f: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c772: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c779: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c77f: 8b 10                        	movl	(%eax), %edx
  40c781: ff 52 2c                     	calll	*0x2c(%edx)
  40c784: 50                           	pushl	%eax
  40c785: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c788: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c78f: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c795: 8b 10                        	movl	(%eax), %edx
  40c797: ff 52 20                     	calll	*0x20(%edx)
  40c79a: 50                           	pushl	%eax
  40c79b: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c79e: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c7a5: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c7ab: e8 98 cc 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c7b0: 33 c9                        	xorl	%ecx, %ecx
  40c7b2: 33 d2                        	xorl	%edx, %edx
  40c7b4: e8 8b 7f 0d 00               	calll	0x4e4744 <@Myimage@initialization$qqrv+0x23b50>
  40c7b9: 8d 8d f4 fd ff ff            	leal	-0x20c(%ebp), %ecx
  40c7bf: ba 60 00 00 00               	movl	$0x60, %edx
  40c7c4: b8 02 00 00 00               	movl	$0x2, %eax
  40c7c9: e8 52 27 11 00               	calll	0x51ef20 <@Myimage@initialization$qqrv+0x5e32c>
  40c7ce: 8b 85 f4 fd ff ff            	movl	-0x20c(%ebp), %eax
  40c7d4: 89 85 04 ed ff ff            	movl	%eax, -0x12fc(%ebp)
  40c7da: 8b 85 f8 fd ff ff            	movl	-0x208(%ebp), %eax
  40c7e0: 89 85 08 ed ff ff            	movl	%eax, -0x12f8(%ebp)
  40c7e6: 8d 8d ec fd ff ff            	leal	-0x214(%ebp), %ecx
  40c7ec: ba 60 00 00 00               	movl	$0x60, %edx
  40c7f1: b8 10 00 00 00               	movl	$0x10, %eax
  40c7f6: e8 25 27 11 00               	calll	0x51ef20 <@Myimage@initialization$qqrv+0x5e32c>
  40c7fb: 8b 95 ec fd ff ff            	movl	-0x214(%ebp), %edx
  40c801: 89 95 0c ed ff ff            	movl	%edx, -0x12f4(%ebp)
  40c807: 8b 95 f0 fd ff ff            	movl	-0x210(%ebp), %edx
  40c80d: 89 95 10 ed ff ff            	movl	%edx, -0x12f0(%ebp)
  40c813: d9 05 34 11 41 00            	flds	0x411134
  40c819: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c81c: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c823: dc 88 20 43 00 00            	fmull	0x4320(%eax)
  40c829: db 2d d0 10 41 00            	fldt	0x4110d0
  40c82f: de c9                        	fmulp	%st, %st(1)
  40c831: d8 2d 38 11 41 00            	fsubrs	0x411138
  40c837: e8 c0 cc 12 00               	calll	0x5394fc <@Myimage@initialization$qqrv+0x78908>
  40c83c: 8b d0                        	movl	%eax, %edx
  40c83e: 8d 8d e4 fd ff ff            	leal	-0x21c(%ebp), %ecx
  40c844: b8 10 00 00 00               	movl	$0x10, %eax
  40c849: e8 d2 26 11 00               	calll	0x51ef20 <@Myimage@initialization$qqrv+0x5e32c>
  40c84e: 8b 95 e4 fd ff ff            	movl	-0x21c(%ebp), %edx
  40c854: 89 95 14 ed ff ff            	movl	%edx, -0x12ec(%ebp)
  40c85a: 8b 95 e8 fd ff ff            	movl	-0x218(%ebp), %edx
  40c860: 89 95 18 ed ff ff            	movl	%edx, -0x12e8(%ebp)
  40c866: 6a 01                        	pushl	$0x1
  40c868: ff 75 a0                     	pushl	-0x60(%ebp)
  40c86b: e8 f0 64 06 00               	calll	0x472d60 <@@Unit3@Finalize+0x20650>
  40c870: 83 c4 08                     	addl	$0x8, %esp
  40c873: 50                           	pushl	%eax
  40c874: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c877: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c87e: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c884: e8 bf cb 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c889: 8b 40 14                     	movl	0x14(%eax), %eax
  40c88c: 5a                           	popl	%edx
  40c88d: e8 c6 78 0d 00               	calll	0x4e4158 <@Myimage@initialization$qqrv+0x23564>
  40c892: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c895: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c89c: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c8a2: e8 a1 cb 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c8a7: 8d 95 04 ed ff ff            	leal	-0x12fc(%ebp), %edx
  40c8ad: b9 02 00 00 00               	movl	$0x2, %ecx
  40c8b2: e8 1d 7e 0d 00               	calll	0x4e46d4 <@Myimage@initialization$qqrv+0x23ae0>
  40c8b7: 6a 02                        	pushl	$0x2
  40c8b9: ff 75 a0                     	pushl	-0x60(%ebp)
  40c8bc: e8 9f 64 06 00               	calll	0x472d60 <@@Unit3@Finalize+0x20650>
  40c8c1: 83 c4 08                     	addl	$0x8, %esp
  40c8c4: 50                           	pushl	%eax
  40c8c5: 8b 45 a0                     	movl	-0x60(%ebp), %eax
  40c8c8: 8b 14 85 50 58 58 00         	movl	0x585850(,%eax,4), %edx
  40c8cf: 8b 82 fc 00 00 00            	movl	0xfc(%edx), %eax
  40c8d5: e8 6e cb 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c8da: 8b 40 10                     	movl	0x10(%eax), %eax
  40c8dd: 5a                           	popl	%edx
  40c8de: e8 6d 75 0d 00               	calll	0x4e3e50 <@Myimage@initialization$qqrv+0x2325c>
  40c8e3: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c8e6: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c8ed: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c8f3: e8 50 cb 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c8f8: b9 60 00 00 00               	movl	$0x60, %ecx
  40c8fd: ba 02 00 00 00               	movl	$0x2, %edx
  40c902: e8 a1 7d 0d 00               	calll	0x4e46a8 <@Myimage@initialization$qqrv+0x23ab4>
  40c907: 8b 45 a0                     	movl	-0x60(%ebp), %eax
  40c90a: 8b 14 85 50 58 58 00         	movl	0x585850(,%eax,4), %edx
  40c911: 8b 82 fc 00 00 00            	movl	0xfc(%edx), %eax
  40c917: e8 2c cb 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c91c: 50                           	pushl	%eax
  40c91d: d9 05 34 11 41 00            	flds	0x411134
  40c923: 8b 55 a0                     	movl	-0x60(%ebp), %edx
  40c926: 8b 0c 95 50 58 58 00         	movl	0x585850(,%edx,4), %ecx
  40c92d: dc 89 20 43 00 00            	fmull	0x4320(%ecx)
  40c933: db 2d d0 10 41 00            	fldt	0x4110d0
  40c939: de c9                        	fmulp	%st, %st(1)
  40c93b: d8 2d 38 11 41 00            	fsubrs	0x411138
  40c941: e8 b6 cb 12 00               	calll	0x5394fc <@Myimage@initialization$qqrv+0x78908>
  40c946: 8b c8                        	movl	%eax, %ecx
  40c948: ba 10 00 00 00               	movl	$0x10, %edx
  40c94d: 58                           	popl	%eax
  40c94e: e8 f5 7c 0d 00               	calll	0x4e4648 <@Myimage@initialization$qqrv+0x23a54>
  40c953: 6a 01                        	pushl	$0x1
  40c955: ff 75 a0                     	pushl	-0x60(%ebp)
  40c958: e8 6f 76 06 00               	calll	0x473fcc <@@Unit3@Finalize+0x218bc>
  40c95d: 83 c4 08                     	addl	$0x8, %esp
  40c960: 50                           	pushl	%eax
  40c961: 8b 55 a0                     	movl	-0x60(%ebp), %edx
  40c964: 8b 0c 95 50 58 58 00         	movl	0x585850(,%edx,4), %ecx
  40c96b: 8b 81 fc 00 00 00            	movl	0xfc(%ecx), %eax
  40c971: e8 d2 ca 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c976: 8b 40 14                     	movl	0x14(%eax), %eax
  40c979: 5a                           	popl	%edx
  40c97a: e8 d9 77 0d 00               	calll	0x4e4158 <@Myimage@initialization$qqrv+0x23564>
  40c97f: 6a 02                        	pushl	$0x2
  40c981: ff 75 a0                     	pushl	-0x60(%ebp)
  40c984: e8 43 76 06 00               	calll	0x473fcc <@@Unit3@Finalize+0x218bc>
  40c989: 83 c4 08                     	addl	$0x8, %esp
  40c98c: 50                           	pushl	%eax
  40c98d: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c990: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c997: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c99d: e8 a6 ca 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40c9a2: 8b 40 10                     	movl	0x10(%eax), %eax
  40c9a5: 5a                           	popl	%edx
  40c9a6: e8 a5 74 0d 00               	calll	0x4e3e50 <@Myimage@initialization$qqrv+0x2325c>
  40c9ab: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c9ae: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c9b5: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40c9bb: 8b 10                        	movl	(%eax), %edx
  40c9bd: ff 52 20                     	calll	*0x20(%edx)
  40c9c0: 89 85 10 ec ff ff            	movl	%eax, -0x13f0(%ebp)
  40c9c6: db 85 10 ec ff ff            	fildl	-0x13f0(%ebp)
  40c9cc: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40c9cf: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40c9d6: dd 80 38 43 00 00            	fldl	0x4338(%eax)
  40c9dc: 8b 55 a0                     	movl	-0x60(%ebp), %edx
  40c9df: 8b 0c 95 50 58 58 00         	movl	0x585850(,%edx,4), %ecx
  40c9e6: dc 71 28                     	fdivl	0x28(%ecx)
  40c9e9: de c9                        	fmulp	%st, %st(1)
  40c9eb: dd 9d dc fd ff ff            	fstpl	-0x224(%ebp)
  40c9f1: 8b 45 a0                     	movl	-0x60(%ebp), %eax
  40c9f4: 8b 14 85 50 58 58 00         	movl	0x585850(,%eax,4), %edx
  40c9fb: 8b 82 fc 00 00 00            	movl	0xfc(%edx), %eax
  40ca01: 8b 10                        	movl	(%eax), %edx
  40ca03: ff 52 2c                     	calll	*0x2c(%edx)
  40ca06: 83 c0 fd                     	addl	$-0x3, %eax
  40ca09: 89 85 10 ec ff ff            	movl	%eax, -0x13f0(%ebp)
  40ca0f: db 85 10 ec ff ff            	fildl	-0x13f0(%ebp)
  40ca15: dd 85 dc fd ff ff            	fldl	-0x224(%ebp)
  40ca1b: d8 0d 3c 11 41 00            	fmuls	0x41113c
  40ca21: d8 0d 40 11 41 00            	fmuls	0x411140
  40ca27: de c1                        	faddp	%st, %st(1)
  40ca29: e8 ce ca 12 00               	calll	0x5394fc <@Myimage@initialization$qqrv+0x78908>
  40ca2e: 50                           	pushl	%eax
  40ca2f: 8b 55 a0                     	movl	-0x60(%ebp), %edx
  40ca32: 8b 0c 95 50 58 58 00         	movl	0x585850(,%edx,4), %ecx
  40ca39: 8b 81 fc 00 00 00            	movl	0xfc(%ecx), %eax
  40ca3f: 8b 10                        	movl	(%eax), %edx
  40ca41: ff 52 20                     	calll	*0x20(%edx)
  40ca44: d1 f8                        	sarl	%eax
  40ca46: 79 03                        	jns	0x40ca4b <__GetExceptDLLinfo+0xb9f2>
  40ca48: 83 d0 00                     	adcl	$0x0, %eax
  40ca4b: 89 85 0c ec ff ff            	movl	%eax, -0x13f4(%ebp)
  40ca51: db 85 0c ec ff ff            	fildl	-0x13f4(%ebp)
  40ca57: dc 85 dc fd ff ff            	faddl	-0x224(%ebp)
  40ca5d: e8 9a ca 12 00               	calll	0x5394fc <@Myimage@initialization$qqrv+0x78908>
  40ca62: 50                           	pushl	%eax
  40ca63: 8b 55 a0                     	movl	-0x60(%ebp), %edx
  40ca66: 8b 0c 95 50 58 58 00         	movl	0x585850(,%edx,4), %ecx
  40ca6d: 8b 81 fc 00 00 00            	movl	0xfc(%ecx), %eax
  40ca73: 8b 10                        	movl	(%eax), %edx
  40ca75: ff 52 20                     	calll	*0x20(%edx)
  40ca78: d1 f8                        	sarl	%eax
  40ca7a: 79 03                        	jns	0x40ca7f <__GetExceptDLLinfo+0xba26>
  40ca7c: 83 d0 00                     	adcl	$0x0, %eax
  40ca7f: 89 85 08 ec ff ff            	movl	%eax, -0x13f8(%ebp)
  40ca85: db 85 08 ec ff ff            	fildl	-0x13f8(%ebp)
  40ca8b: dc a5 dc fd ff ff            	fsubl	-0x224(%ebp)
  40ca91: e8 66 ca 12 00               	calll	0x5394fc <@Myimage@initialization$qqrv+0x78908>
  40ca96: 50                           	pushl	%eax
  40ca97: 8b 55 a0                     	movl	-0x60(%ebp), %edx
  40ca9a: 8b 0c 95 50 58 58 00         	movl	0x585850(,%edx,4), %ecx
  40caa1: 8b 81 fc 00 00 00            	movl	0xfc(%ecx), %eax
  40caa7: 8b 10                        	movl	(%eax), %edx
  40caa9: ff 52 2c                     	calll	*0x2c(%edx)
  40caac: 83 c0 fc                     	addl	$-0x4, %eax
  40caaf: 89 85 04 ec ff ff            	movl	%eax, -0x13fc(%ebp)
  40cab5: db 85 04 ec ff ff            	fildl	-0x13fc(%ebp)
  40cabb: dd 85 dc fd ff ff            	fldl	-0x224(%ebp)
  40cac1: d8 0d 3c 11 41 00            	fmuls	0x41113c
  40cac7: de e9                        	fsubrp	%st, %st(1)
  40cac9: e8 2e ca 12 00               	calll	0x5394fc <@Myimage@initialization$qqrv+0x78908>
  40cace: 50                           	pushl	%eax
  40cacf: 8b 55 a0                     	movl	-0x60(%ebp), %edx
  40cad2: 8b 0c 95 50 58 58 00         	movl	0x585850(,%edx,4), %ecx
  40cad9: 8b 81 fc 00 00 00            	movl	0xfc(%ecx), %eax
  40cadf: e8 64 c9 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
  40cae4: 5a                           	popl	%edx
  40cae5: 59                           	popl	%ecx
  40cae6: e8 9d 7a 0d 00               	calll	0x4e4588 <@Myimage@initialization$qqrv+0x23994>
  40caeb: e9 06 0c 00 00               	jmp	0x40d6f6 <__GetExceptDLLinfo+0xc69d>
  40caf0: 8b 45 a0                     	movl	-0x60(%ebp), %eax
  40caf3: 8b 14 85 50 58 58 00         	movl	0x585850(,%eax,4), %edx
  40cafa: 83 7a 0c 32                  	cmpl	$0x32, 0xc(%edx)
  40cafe: 0f 85 f2 0b 00 00            	jne	0x40d6f6 <__GetExceptDLLinfo+0xc69d>
  40cb04: 8b 4d a0                     	movl	-0x60(%ebp), %ecx
  40cb07: 8b 04 8d 50 58 58 00         	movl	0x585850(,%ecx,4), %eax
  40cb0e: 8b 80 fc 00 00 00            	movl	0xfc(%eax), %eax
  40cb14: b2 01                        	movb	$0x1, %dl
  40cb16: 8b 08                        	movl	(%eax), %ecx
  40cb18: ff 51 3c                     	calll	*0x3c(%ecx)
  40cb1b: 8b 45 a0                     	movl	-0x60(%ebp), %eax
  40cb1e: 8b 14 85 50 58 58 00         	movl	0x585850(,%eax,4), %edx
  40cb25: 8b 82 fc 00 00 00            	movl	0xfc(%edx), %eax
  40cb2b: e8 18 c9 0d 00               	calll	0x4e9448 <@Myimage@initialization$qqrv+0x28854>
