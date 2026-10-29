
artifacts/ChemLab/_main.exe:	file format coff-i386

Disassembly of section .text:

004c0bf4 <@Myimage@initialization$qqrv>:
  4e8610: 55                           	pushl	%ebp
  4e8611: 8b ec                        	movl	%esp, %ebp
  4e8613: 81 c4 68 ff ff ff            	addl	$0xffffff68, %esp       # imm = 0xFFFFFF68
  4e8619: 53                           	pushl	%ebx
  4e861a: 56                           	pushl	%esi
  4e861b: 57                           	pushl	%edi
  4e861c: 89 4d f4                     	movl	%ecx, -0xc(%ebp)
  4e861f: 89 55 f8                     	movl	%edx, -0x8(%ebp)
  4e8622: 89 45 fc                     	movl	%eax, -0x4(%ebp)
  4e8625: 33 c0                        	xorl	%eax, %eax
  4e8627: 89 45 f0                     	movl	%eax, -0x10(%ebp)
  4e862a: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e862d: 83 78 18 00                  	cmpl	$0x0, 0x18(%eax)
  4e8631: 74 1a                        	je	0x4e864d <@Myimage@initialization$qqrv+0x27a59>
  4e8633: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8636: 83 78 1c 00                  	cmpl	$0x0, 0x1c(%eax)
  4e863a: 0f 84 1f 06 00 00            	je	0x4e8c5f <@Myimage@initialization$qqrv+0x2806b>
  4e8640: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8643: 83 78 20 00                  	cmpl	$0x0, 0x20(%eax)
  4e8647: 0f 84 12 06 00 00            	je	0x4e8c5f <@Myimage@initialization$qqrv+0x2806b>
  4e864d: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8650: 83 78 18 00                  	cmpl	$0x0, 0x18(%eax)
  4e8654: 75 1a                        	jne	0x4e8670 <@Myimage@initialization$qqrv+0x27a7c>
  4e8656: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8659: 83 78 04 00                  	cmpl	$0x0, 0x4(%eax)
  4e865d: 0f 84 fc 05 00 00            	je	0x4e8c5f <@Myimage@initialization$qqrv+0x2806b>
  4e8663: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8666: 83 78 08 00                  	cmpl	$0x0, 0x8(%eax)
  4e866a: 0f 84 ef 05 00 00            	je	0x4e8c5f <@Myimage@initialization$qqrv+0x2806b>
  4e8670: 8b 45 fc                     	movl	-0x4(%ebp), %eax
  4e8673: e8 54 fb ff ff               	calll	0x4e81cc <@Myimage@initialization$qqrv+0x275d8>
  4e8678: 33 c0                        	xorl	%eax, %eax
  4e867a: 89 45 90                     	movl	%eax, -0x70(%ebp)
  4e867d: 83 7d fc 00                  	cmpl	$0x0, -0x4(%ebp)
  4e8681: 74 1c                        	je	0x4e869f <@Myimage@initialization$qqrv+0x27aab>
  4e8683: 8d 85 78 ff ff ff            	leal	-0x88(%ebp), %eax
  4e8689: 50                           	pushl	%eax
  4e868a: 6a 54                        	pushl	$0x54
  4e868c: 8b 45 fc                     	movl	-0x4(%ebp), %eax
  4e868f: 50                           	pushl	%eax
  4e8690: e8 c1 cc 06 00               	calll	0x555356 <@Myimage@initialization$qqrv+0x94762>
  4e8695: 83 f8 18                     	cmpl	$0x18, %eax
  4e8698: 7d 05                        	jge	0x4e869f <@Myimage@initialization$qqrv+0x27aab>
  4e869a: e8 bd c7 ff ff               	calll	0x4e4e5c <@Myimage@initialization$qqrv+0x24268>
  4e869f: 6a 00                        	pushl	$0x0
  4e86a1: e8 2a cf 06 00               	calll	0x5555d0 <@Myimage@initialization$qqrv+0x949dc>
  4e86a6: e8 d1 c8 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e86ab: 89 45 e8                     	movl	%eax, -0x18(%ebp)
  4e86ae: 8b 45 e8                     	movl	-0x18(%ebp), %eax
  4e86b1: 50                           	pushl	%eax
  4e86b2: e8 c7 cb 06 00               	calll	0x55527e <@Myimage@initialization$qqrv+0x9468a>
  4e86b7: e8 c0 c8 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e86bc: 89 45 e4                     	movl	%eax, -0x1c(%ebp)
  4e86bf: 33 d2                        	xorl	%edx, %edx
  4e86c1: 55                           	pushl	%ebp
  4e86c2: 68 58 8c 4e 00               	pushl	$0x4e8c58               # imm = 0x4E8C58
  4e86c7: 64 ff 32                     	pushl	%fs:(%edx)
  4e86ca: 64 89 22                     	movl	%esp, %fs:(%edx)
  4e86cd: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e86d0: 83 78 18 28                  	cmpl	$0x28, 0x18(%eax)
  4e86d4: 73 5e                        	jae	0x4e8734 <@Myimage@initialization$qqrv+0x27b40>
  4e86d6: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e86d9: 66 8b 40 10                  	movw	0x10(%eax), %ax
  4e86dd: 8b 55 0c                     	movl	0xc(%ebp), %edx
  4e86e0: 66 0b 42 12                  	orw	0x12(%edx), %ax
  4e86e4: 66 83 f8 01                  	cmpw	$0x1, %ax
  4e86e8: 75 26                        	jne	0x4e8710 <@Myimage@initialization$qqrv+0x27b1c>
  4e86ea: 6a 00                        	pushl	$0x0
  4e86ec: 6a 01                        	pushl	$0x1
  4e86ee: 6a 01                        	pushl	$0x1
  4e86f0: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e86f3: 8b 40 08                     	movl	0x8(%eax), %eax
  4e86f6: 50                           	pushl	%eax
  4e86f7: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e86fa: 8b 40 04                     	movl	0x4(%eax), %eax
  4e86fd: 50                           	pushl	%eax
  4e86fe: e8 69 cb 06 00               	calll	0x55526c <@Myimage@initialization$qqrv+0x94678>
  4e8703: e8 74 c8 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e8708: 89 45 f0                     	movl	%eax, -0x10(%ebp)
  4e870b: e9 59 02 00 00               	jmp	0x4e8969 <@Myimage@initialization$qqrv+0x27d75>
  4e8710: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8713: 8b 40 08                     	movl	0x8(%eax), %eax
  4e8716: 50                           	pushl	%eax
  4e8717: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e871a: 8b 40 04                     	movl	0x4(%eax), %eax
  4e871d: 50                           	pushl	%eax
  4e871e: 8b 45 e8                     	movl	-0x18(%ebp), %eax
  4e8721: 50                           	pushl	%eax
  4e8722: e8 51 cb 06 00               	calll	0x555278 <@Myimage@initialization$qqrv+0x94684>
  4e8727: e8 50 c8 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e872c: 89 45 f0                     	movl	%eax, -0x10(%ebp)
  4e872f: e9 35 02 00 00               	jmp	0x4e8969 <@Myimage@initialization$qqrv+0x27d75>
  4e8734: b8 2c 04 00 00               	movl	$0x42c, %eax            # imm = 0x42C
  4e8739: e8 32 85 04 00               	calll	0x530c70 <@Myimage@initialization$qqrv+0x7007c>
  4e873e: 89 45 dc                     	movl	%eax, -0x24(%ebp)
  4e8741: 33 d2                        	xorl	%edx, %edx
  4e8743: 55                           	pushl	%ebp
  4e8744: 68 62 89 4e 00               	pushl	$0x4e8962               # imm = 0x4E8962
  4e8749: 64 ff 32                     	pushl	%fs:(%edx)
  4e874c: 64 89 22                     	movl	%esp, %fs:(%edx)
  4e874f: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8752: c7 40 18 28 00 00 00         	movl	$0x28, 0x18(%eax)
  4e8759: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e875c: 66 c7 40 24 01 00            	movw	$0x1, 0x24(%eax)
  4e8762: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8765: 66 83 78 26 00               	cmpw	$0x0, 0x26(%eax)
  4e876a: 75 23                        	jne	0x4e878f <@Myimage@initialization$qqrv+0x27b9b>
  4e876c: 6a 0c                        	pushl	$0xc
  4e876e: 8b 45 e8                     	movl	-0x18(%ebp), %eax
  4e8771: 50                           	pushl	%eax
  4e8772: e8 c7 cb 06 00               	calll	0x55533e <@Myimage@initialization$qqrv+0x9474a>
  4e8777: 8b d8                        	movl	%eax, %ebx
  4e8779: 6a 0e                        	pushl	$0xe
  4e877b: 8b 45 e8                     	movl	-0x18(%ebp), %eax
  4e877e: 50                           	pushl	%eax
  4e877f: e8 ba cb 06 00               	calll	0x55533e <@Myimage@initialization$qqrv+0x9474a>
  4e8784: 66 0f af d8                  	imulw	%ax, %bx
  4e8788: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e878b: 66 89 58 26                  	movw	%bx, 0x26(%eax)
  4e878f: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8792: 8b 55 dc                     	movl	-0x24(%ebp), %edx
  4e8795: 8d 70 18                     	leal	0x18(%eax), %esi
  4e8798: 8b fa                        	movl	%edx, %edi
  4e879a: b9 0a 00 00 00               	movl	$0xa, %ecx
  4e879f: f3 a5                        	rep		movsl	(%esi), %es:(%edi)
  4e87a1: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e87a4: 8b 40 1c                     	movl	0x1c(%eax), %eax
  4e87a7: 8b 55 0c                     	movl	0xc(%ebp), %edx
  4e87aa: 89 42 04                     	movl	%eax, 0x4(%edx)
  4e87ad: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e87b0: 8b 40 20                     	movl	0x20(%eax), %eax
  4e87b3: 8b 55 0c                     	movl	0xc(%ebp), %edx
  4e87b6: 89 42 08                     	movl	%eax, 0x8(%edx)
  4e87b9: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e87bc: 66 83 78 26 08               	cmpw	$0x8, 0x26(%eax)
  4e87c1: 0f 87 c1 00 00 00            	ja	0x4e8888 <@Myimage@initialization$qqrv+0x27c94>
  4e87c7: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e87ca: 66 83 78 26 01               	cmpw	$0x1, 0x26(%eax)
  4e87cf: 75 22                        	jne	0x4e87f3 <@Myimage@initialization$qqrv+0x27bff>
  4e87d1: 83 7d 8c 00                  	cmpl	$0x0, -0x74(%ebp)
  4e87d5: 75 1c                        	jne	0x4e87f3 <@Myimage@initialization$qqrv+0x27bff>
  4e87d7: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e87da: 33 d2                        	xorl	%edx, %edx
  4e87dc: 89 50 28                     	movl	%edx, 0x28(%eax)
  4e87df: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e87e2: 83 c0 28                     	addl	$0x28, %eax
  4e87e5: 83 c0 04                     	addl	$0x4, %eax
  4e87e8: c7 00 ff ff ff 00            	movl	$0xffffff, (%eax)       # imm = 0xFFFFFF
  4e87ee: e9 d2 00 00 00               	jmp	0x4e88c5 <@Myimage@initialization$qqrv+0x27cd1>
  4e87f3: 83 7d f4 00                  	cmpl	$0x0, -0xc(%ebp)
  4e87f7: 74 18                        	je	0x4e8811 <@Myimage@initialization$qqrv+0x27c1d>
  4e87f9: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e87fc: 8d 50 28                     	leal	0x28(%eax), %edx
  4e87ff: b9 ff 00 00 00               	movl	$0xff, %ecx
  4e8804: 8b 45 f4                     	movl	-0xc(%ebp), %eax
  4e8807: e8 04 cf ff ff               	calll	0x4e5710 <@Myimage@initialization$qqrv+0x24b1c>
  4e880c: e9 b4 00 00 00               	jmp	0x4e88c5 <@Myimage@initialization$qqrv+0x27cd1>
  4e8811: 83 7d fc 00                  	cmpl	$0x0, -0x4(%ebp)
  4e8815: 0f 84 aa 00 00 00            	je	0x4e88c5 <@Myimage@initialization$qqrv+0x27cd1>
  4e881b: 8b 45 fc                     	movl	-0x4(%ebp), %eax
  4e881e: 50                           	pushl	%eax
  4e881f: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8822: 50                           	pushl	%eax
  4e8823: e8 d0 cb 06 00               	calll	0x5553f8 <@Myimage@initialization$qqrv+0x94804>
  4e8828: 89 45 ec                     	movl	%eax, -0x14(%ebp)
  4e882b: 83 7d 90 00                  	cmpl	$0x0, -0x70(%ebp)
  4e882f: 76 25                        	jbe	0x4e8856 <@Myimage@initialization$qqrv+0x27c62>
  4e8831: 83 7d 8c 00                  	cmpl	$0x0, -0x74(%ebp)
  4e8835: 74 1f                        	je	0x4e8856 <@Myimage@initialization$qqrv+0x27c62>
  4e8837: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e883a: 83 c0 28                     	addl	$0x28, %eax
  4e883d: 50                           	pushl	%eax
  4e883e: 68 00 01 00 00               	pushl	$0x100                  # imm = 0x100
  4e8843: 6a 00                        	pushl	$0x0
  4e8845: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8848: 50                           	pushl	%eax
  4e8849: e8 e4 ca 06 00               	calll	0x555332 <@Myimage@initialization$qqrv+0x9473e>
  4e884e: 8b 55 0c                     	movl	0xc(%ebp), %edx
  4e8851: 89 42 38                     	movl	%eax, 0x38(%edx)
  4e8854: eb 23                        	jmp	0x4e8879 <@Myimage@initialization$qqrv+0x27c85>
  4e8856: 6a 00                        	pushl	$0x0
  4e8858: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e885b: 50                           	pushl	%eax
  4e885c: 6a 00                        	pushl	$0x0
  4e885e: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8861: 8b 40 20                     	movl	0x20(%eax), %eax
  4e8864: 99                           	cltd
  4e8865: 33 c2                        	xorl	%edx, %eax
  4e8867: 2b c2                        	subl	%edx, %eax
  4e8869: 50                           	pushl	%eax
  4e886a: 6a 00                        	pushl	$0x0
  4e886c: 8b 45 fc                     	movl	-0x4(%ebp), %eax
  4e886f: 50                           	pushl	%eax
  4e8870: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8873: 50                           	pushl	%eax
  4e8874: e8 bf ca 06 00               	calll	0x555338 <@Myimage@initialization$qqrv+0x94744>
  4e8879: 8b 45 ec                     	movl	-0x14(%ebp), %eax
  4e887c: 50                           	pushl	%eax
  4e887d: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8880: 50                           	pushl	%eax
  4e8881: e8 72 cb 06 00               	calll	0x5553f8 <@Myimage@initialization$qqrv+0x94804>
  4e8886: eb 3d                        	jmp	0x4e88c5 <@Myimage@initialization$qqrv+0x27cd1>
  4e8888: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e888b: 66 8b 40 26                  	movw	0x26(%eax), %ax
  4e888f: 66 83 f8 10                  	cmpw	$0x10, %ax
  4e8893: 74 09                        	je	0x4e889e <@Myimage@initialization$qqrv+0x27caa>
  4e8895: 8b 55 0c                     	movl	0xc(%ebp), %edx
  4e8898: 66 83 f8 20                  	cmpw	$0x20, %ax
  4e889c: 75 27                        	jne	0x4e88c5 <@Myimage@initialization$qqrv+0x27cd1>
  4e889e: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e88a1: f6 40 28 03                  	testb	$0x3, 0x28(%eax)
  4e88a5: 74 1e                        	je	0x4e88c5 <@Myimage@initialization$qqrv+0x27cd1>
  4e88a7: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e88aa: e8 15 fd ff ff               	calll	0x4e85c4 <@Myimage@initialization$qqrv+0x279d0>
  4e88af: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e88b2: 8d 50 28                     	leal	0x28(%eax), %edx
  4e88b5: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e88b8: 83 c0 40                     	addl	$0x40, %eax
  4e88bb: b9 0c 00 00 00               	movl	$0xc, %ecx
  4e88c0: e8 37 85 04 00               	calll	0x530dfc <@Myimage@initialization$qqrv+0x70208>
  4e88c5: 6a 00                        	pushl	$0x0
  4e88c7: 6a 00                        	pushl	$0x0
  4e88c9: 8d 45 d8                     	leal	-0x28(%ebp), %eax
  4e88cc: 50                           	pushl	%eax
  4e88cd: 6a 00                        	pushl	$0x0
  4e88cf: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e88d2: 50                           	pushl	%eax
  4e88d3: 8b 45 e8                     	movl	-0x18(%ebp), %eax
  4e88d6: 50                           	pushl	%eax
  4e88d7: e8 ae c9 06 00               	calll	0x55528a <@Myimage@initialization$qqrv+0x94696>
  4e88dc: e8 9b c6 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e88e1: 89 45 f0                     	movl	%eax, -0x10(%ebp)
  4e88e4: 83 7d d8 00                  	cmpl	$0x0, -0x28(%ebp)
  4e88e8: 75 05                        	jne	0x4e88ef <@Myimage@initialization$qqrv+0x27cfb>
  4e88ea: e8 e5 c5 ff ff               	calll	0x4e4ed4 <@Myimage@initialization$qqrv+0x242e0>
  4e88ef: 83 7d fc 00                  	cmpl	$0x0, -0x4(%ebp)
  4e88f3: 74 57                        	je	0x4e894c <@Myimage@initialization$qqrv+0x27d58>
  4e88f5: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e88f8: 8b 40 1c                     	movl	0x1c(%eax), %eax
  4e88fb: 3b 85 7c ff ff ff            	cmpl	-0x84(%ebp), %eax
  4e8901: 75 49                        	jne	0x4e894c <@Myimage@initialization$qqrv+0x27d58>
  4e8903: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8906: 8b 40 20                     	movl	0x20(%eax), %eax
  4e8909: 3b 45 80                     	cmpl	-0x80(%ebp), %eax
  4e890c: 75 3e                        	jne	0x4e894c <@Myimage@initialization$qqrv+0x27d58>
  4e890e: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8911: 66 83 78 26 08               	cmpw	$0x8, 0x26(%eax)
  4e8916: 76 34                        	jbe	0x4e894c <@Myimage@initialization$qqrv+0x27d58>
  4e8918: 6a 00                        	pushl	$0x0
  4e891a: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e891d: 50                           	pushl	%eax
  4e891e: 8b 45 d8                     	movl	-0x28(%ebp), %eax
  4e8921: 50                           	pushl	%eax
  4e8922: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8925: 8b 40 20                     	movl	0x20(%eax), %eax
  4e8928: 99                           	cltd
  4e8929: 33 c2                        	xorl	%edx, %eax
  4e892b: 2b c2                        	subl	%edx, %eax
  4e892d: 50                           	pushl	%eax
  4e892e: 6a 00                        	pushl	$0x0
  4e8930: 8b 45 fc                     	movl	-0x4(%ebp), %eax
  4e8933: 50                           	pushl	%eax
  4e8934: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8937: 50                           	pushl	%eax
  4e8938: e8 fb c9 06 00               	calll	0x555338 <@Myimage@initialization$qqrv+0x94744>
  4e893d: e8 9e 92 04 00               	calll	0x531be0 <@Myimage@initialization$qqrv+0x70fec>
  4e8942: e8 99 92 04 00               	calll	0x531be0 <@Myimage@initialization$qqrv+0x70fec>
  4e8947: e9 13 03 00 00               	jmp	0x4e8c5f <@Myimage@initialization$qqrv+0x2806b>
  4e894c: 33 c0                        	xorl	%eax, %eax
  4e894e: 5a                           	popl	%edx
  4e894f: 59                           	popl	%ecx
  4e8950: 59                           	popl	%ecx
  4e8951: 64 89 10                     	movl	%edx, %fs:(%eax)
  4e8954: 68 69 89 4e 00               	pushl	$0x4e8969               # imm = 0x4E8969
  4e8959: 8b 45 dc                     	movl	-0x24(%ebp), %eax
  4e895c: e8 27 83 04 00               	calll	0x530c88 <@Myimage@initialization$qqrv+0x70094>
  4e8961: c3                           	retl
  4e8962: e9 a1 91 04 00               	jmp	0x531b08 <@Myimage@initialization$qqrv+0x70f14>
  4e8967: eb f0                        	jmp	0x4e8959 <@Myimage@initialization$qqrv+0x27d65>
  4e8969: 8b 45 f0                     	movl	-0x10(%ebp), %eax
  4e896c: e8 0b c6 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e8971: 8b 45 f0                     	movl	-0x10(%ebp), %eax
  4e8974: 50                           	pushl	%eax
  4e8975: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8978: 50                           	pushl	%eax
  4e8979: e8 7a ca 06 00               	calll	0x5553f8 <@Myimage@initialization$qqrv+0x94804>
  4e897e: e8 f9 c5 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e8983: 89 45 ec                     	movl	%eax, -0x14(%ebp)
  4e8986: 33 c0                        	xorl	%eax, %eax
  4e8988: 55                           	pushl	%ebp
  4e8989: 68 09 8c 4e 00               	pushl	$0x4e8c09               # imm = 0x4E8C09
  4e898e: 64 ff 30                     	pushl	%fs:(%eax)
  4e8991: 64 89 20                     	movl	%esp, %fs:(%eax)
  4e8994: 33 c0                        	xorl	%eax, %eax
  4e8996: 55                           	pushl	%ebp
  4e8997: 68 f8 8b 4e 00               	pushl	$0x4e8bf8               # imm = 0x4E8BF8
  4e899c: 64 ff 30                     	pushl	%fs:(%eax)
  4e899f: 64 89 20                     	movl	%esp, %fs:(%eax)
  4e89a2: 33 c0                        	xorl	%eax, %eax
  4e89a4: 89 45 cc                     	movl	%eax, -0x34(%ebp)
  4e89a7: 33 db                        	xorl	%ebx, %ebx
  4e89a9: 83 7d f4 00                  	cmpl	$0x0, -0xc(%ebp)
  4e89ad: 74 1b                        	je	0x4e89ca <@Myimage@initialization$qqrv+0x27dd6>
  4e89af: 6a 00                        	pushl	$0x0
  4e89b1: 8b 45 f4                     	movl	-0xc(%ebp), %eax
  4e89b4: 50                           	pushl	%eax
  4e89b5: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e89b8: 50                           	pushl	%eax
  4e89b9: e8 40 ca 06 00               	calll	0x5553fe <@Myimage@initialization$qqrv+0x9480a>
  4e89be: 89 45 cc                     	movl	%eax, -0x34(%ebp)
  4e89c1: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e89c4: 50                           	pushl	%eax
  4e89c5: e8 0a ca 06 00               	calll	0x5553d4 <@Myimage@initialization$qqrv+0x947e0>
  4e89ca: 33 c0                        	xorl	%eax, %eax
  4e89cc: 55                           	pushl	%ebp
  4e89cd: 68 d6 8b 4e 00               	pushl	$0x4e8bd6               # imm = 0x4E8BD6
  4e89d2: 64 ff 30                     	pushl	%fs:(%eax)
  4e89d5: 64 89 20                     	movl	%esp, %fs:(%eax)
  4e89d8: 83 7d 08 00                  	cmpl	$0x0, 0x8(%ebp)
  4e89dc: 0f 84 b5 00 00 00            	je	0x4e8a97 <@Myimage@initialization$qqrv+0x27ea3>
  4e89e2: 8b 45 08                     	movl	0x8(%ebp), %eax
  4e89e5: 8b 40 14                     	movl	0x14(%eax), %eax
  4e89e8: e8 9f b7 ff ff               	calll	0x4e418c <@Myimage@initialization$qqrv+0x23598>
  4e89ed: 50                           	pushl	%eax
  4e89ee: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e89f1: 8b 40 08                     	movl	0x8(%eax), %eax
  4e89f4: 50                           	pushl	%eax
  4e89f5: 8d 85 68 ff ff ff            	leal	-0x98(%ebp), %eax
  4e89fb: 50                           	pushl	%eax
  4e89fc: 8b 4d 0c                     	movl	0xc(%ebp), %ecx
  4e89ff: 8b 49 04                     	movl	0x4(%ecx), %ecx
  4e8a02: 33 d2                        	xorl	%edx, %edx
  4e8a04: 33 c0                        	xorl	%eax, %eax
  4e8a06: e8 2d 65 03 00               	calll	0x51ef38 <@Myimage@initialization$qqrv+0x5e344>
  4e8a0b: 8d 85 68 ff ff ff            	leal	-0x98(%ebp), %eax
  4e8a11: 50                           	pushl	%eax
  4e8a12: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8a15: 50                           	pushl	%eax
  4e8a16: e8 79 cb 06 00               	calll	0x555594 <@Myimage@initialization$qqrv+0x949a0>
  4e8a1b: 8b 45 08                     	movl	0x8(%ebp), %eax
  4e8a1e: 8b 40 0c                     	movl	0xc(%eax), %eax
  4e8a21: 8b 40 18                     	movl	0x18(%eax), %eax
  4e8a24: e8 7b aa ff ff               	calll	0x4e34a4 <@Myimage@initialization$qqrv+0x228b0>
  4e8a29: 50                           	pushl	%eax
  4e8a2a: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8a2d: 50                           	pushl	%eax
  4e8a2e: e8 0d ca 06 00               	calll	0x555440 <@Myimage@initialization$qqrv+0x9484c>
  4e8a33: 8b 45 08                     	movl	0x8(%ebp), %eax
  4e8a36: 8b 40 14                     	movl	0x14(%eax), %eax
  4e8a39: e8 12 b7 ff ff               	calll	0x4e4150 <@Myimage@initialization$qqrv+0x2355c>
  4e8a3e: e8 61 aa ff ff               	calll	0x4e34a4 <@Myimage@initialization$qqrv+0x228b0>
  4e8a43: 50                           	pushl	%eax
  4e8a44: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8a47: 50                           	pushl	%eax
  4e8a48: e8 bd c9 06 00               	calll	0x55540a <@Myimage@initialization$qqrv+0x94816>
  4e8a4d: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8a50: 66 83 78 26 01               	cmpw	$0x1, 0x26(%eax)
  4e8a55: 75 60                        	jne	0x4e8ab7 <@Myimage@initialization$qqrv+0x27ec3>
  4e8a57: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8a5a: 83 78 14 00                  	cmpl	$0x0, 0x14(%eax)
  4e8a5e: 74 57                        	je	0x4e8ab7 <@Myimage@initialization$qqrv+0x27ec3>
  4e8a60: 8b 45 08                     	movl	0x8(%ebp), %eax
  4e8a63: 8b 40 0c                     	movl	0xc(%eax), %eax
  4e8a66: 8b 40 18                     	movl	0x18(%eax), %eax
  4e8a69: e8 36 aa ff ff               	calll	0x4e34a4 <@Myimage@initialization$qqrv+0x228b0>
  4e8a6e: 89 45 d0                     	movl	%eax, -0x30(%ebp)
  4e8a71: 8b 45 08                     	movl	0x8(%ebp), %eax
  4e8a74: 8b 40 14                     	movl	0x14(%eax), %eax
  4e8a77: e8 d4 b6 ff ff               	calll	0x4e4150 <@Myimage@initialization$qqrv+0x2355c>
  4e8a7c: e8 23 aa ff ff               	calll	0x4e34a4 <@Myimage@initialization$qqrv+0x228b0>
  4e8a81: 89 45 d4                     	movl	%eax, -0x2c(%ebp)
  4e8a84: 8d 45 d0                     	leal	-0x30(%ebp), %eax
  4e8a87: 50                           	pushl	%eax
  4e8a88: 6a 02                        	pushl	$0x2
  4e8a8a: 6a 00                        	pushl	$0x0
  4e8a8c: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8a8f: 50                           	pushl	%eax
  4e8a90: e8 87 c9 06 00               	calll	0x55541c <@Myimage@initialization$qqrv+0x94828>
  4e8a95: eb 20                        	jmp	0x4e8ab7 <@Myimage@initialization$qqrv+0x27ec3>
  4e8a97: 68 62 00 ff 00               	pushl	$0xff0062               # imm = 0xFF0062
  4e8a9c: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8a9f: 8b 40 08                     	movl	0x8(%eax), %eax
  4e8aa2: 50                           	pushl	%eax
  4e8aa3: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8aa6: 8b 40 04                     	movl	0x4(%eax), %eax
  4e8aa9: 50                           	pushl	%eax
  4e8aaa: 6a 00                        	pushl	$0x0
  4e8aac: 6a 00                        	pushl	$0x0
  4e8aae: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8ab1: 50                           	pushl	%eax
  4e8ab2: e8 f9 c8 06 00               	calll	0x5553b0 <@Myimage@initialization$qqrv+0x947bc>
  4e8ab7: 83 7d fc 00                  	cmpl	$0x0, -0x4(%ebp)
  4e8abb: 0f 84 f2 00 00 00            	je	0x4e8bb3 <@Myimage@initialization$qqrv+0x27fbf>
  4e8ac1: 8b 45 e8                     	movl	-0x18(%ebp), %eax
  4e8ac4: 50                           	pushl	%eax
  4e8ac5: e8 b4 c7 06 00               	calll	0x55527e <@Myimage@initialization$qqrv+0x9468a>
  4e8aca: e8 ad c4 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e8acf: 89 45 e0                     	movl	%eax, -0x20(%ebp)
  4e8ad2: 33 c0                        	xorl	%eax, %eax
  4e8ad4: 55                           	pushl	%ebp
  4e8ad5: 68 ac 8b 4e 00               	pushl	$0x4e8bac               # imm = 0x4E8BAC
  4e8ada: 64 ff 30                     	pushl	%fs:(%eax)
  4e8add: 64 89 20                     	movl	%esp, %fs:(%eax)
  4e8ae0: 8b 45 fc                     	movl	-0x4(%ebp), %eax
  4e8ae3: 50                           	pushl	%eax
  4e8ae4: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8ae7: 50                           	pushl	%eax
  4e8ae8: e8 0b c9 06 00               	calll	0x5553f8 <@Myimage@initialization$qqrv+0x94804>
  4e8aed: e8 8a c4 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e8af2: 8b f0                        	movl	%eax, %esi
  4e8af4: 83 7d f8 00                  	cmpl	$0x0, -0x8(%ebp)
  4e8af8: 74 1a                        	je	0x4e8b14 <@Myimage@initialization$qqrv+0x27f20>
  4e8afa: 6a 00                        	pushl	$0x0
  4e8afc: 8b 45 f8                     	movl	-0x8(%ebp), %eax
  4e8aff: 50                           	pushl	%eax
  4e8b00: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8b03: 50                           	pushl	%eax
  4e8b04: e8 f5 c8 06 00               	calll	0x5553fe <@Myimage@initialization$qqrv+0x9480a>
  4e8b09: 8b d8                        	movl	%eax, %ebx
  4e8b0b: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8b0e: 50                           	pushl	%eax
  4e8b0f: e8 c0 c8 06 00               	calll	0x5553d4 <@Myimage@initialization$qqrv+0x947e0>
  4e8b14: 83 7d 08 00                  	cmpl	$0x0, 0x8(%ebp)
  4e8b18: 74 32                        	je	0x4e8b4c <@Myimage@initialization$qqrv+0x27f58>
  4e8b1a: 8b 45 08                     	movl	0x8(%ebp), %eax
  4e8b1d: 8b 40 0c                     	movl	0xc(%eax), %eax
  4e8b20: 8b 40 18                     	movl	0x18(%eax), %eax
  4e8b23: e8 7c a9 ff ff               	calll	0x4e34a4 <@Myimage@initialization$qqrv+0x228b0>
  4e8b28: 50                           	pushl	%eax
  4e8b29: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8b2c: 50                           	pushl	%eax
  4e8b2d: e8 0e c9 06 00               	calll	0x555440 <@Myimage@initialization$qqrv+0x9484c>
  4e8b32: 8b 45 08                     	movl	0x8(%ebp), %eax
  4e8b35: 8b 40 14                     	movl	0x14(%eax), %eax
  4e8b38: e8 13 b6 ff ff               	calll	0x4e4150 <@Myimage@initialization$qqrv+0x2355c>
  4e8b3d: e8 62 a9 ff ff               	calll	0x4e34a4 <@Myimage@initialization$qqrv+0x228b0>
  4e8b42: 50                           	pushl	%eax
  4e8b43: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8b46: 50                           	pushl	%eax
  4e8b47: e8 be c8 06 00               	calll	0x55540a <@Myimage@initialization$qqrv+0x94816>
  4e8b4c: 68 20 00 cc 00               	pushl	$0xcc0020               # imm = 0xCC0020
  4e8b51: 6a 00                        	pushl	$0x0
  4e8b53: 6a 00                        	pushl	$0x0
  4e8b55: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8b58: 50                           	pushl	%eax
  4e8b59: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8b5c: 8b 40 08                     	movl	0x8(%eax), %eax
  4e8b5f: 50                           	pushl	%eax
  4e8b60: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8b63: 8b 40 04                     	movl	0x4(%eax), %eax
  4e8b66: 50                           	pushl	%eax
  4e8b67: 6a 00                        	pushl	$0x0
  4e8b69: 6a 00                        	pushl	$0x0
  4e8b6b: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8b6e: 50                           	pushl	%eax
  4e8b6f: e8 e6 c6 06 00               	calll	0x55525a <@Myimage@initialization$qqrv+0x94666>
  4e8b74: 83 7d f8 00                  	cmpl	$0x0, -0x8(%ebp)
  4e8b78: 74 0c                        	je	0x4e8b86 <@Myimage@initialization$qqrv+0x27f92>
  4e8b7a: 6a ff                        	pushl	$-0x1
  4e8b7c: 53                           	pushl	%ebx
  4e8b7d: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8b80: 50                           	pushl	%eax
  4e8b81: e8 78 c8 06 00               	calll	0x5553fe <@Myimage@initialization$qqrv+0x9480a>
  4e8b86: 56                           	pushl	%esi
  4e8b87: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8b8a: 50                           	pushl	%eax
  4e8b8b: e8 68 c8 06 00               	calll	0x5553f8 <@Myimage@initialization$qqrv+0x94804>
  4e8b90: e8 e7 c3 ff ff               	calll	0x4e4f7c <@Myimage@initialization$qqrv+0x24388>
  4e8b95: 33 c0                        	xorl	%eax, %eax
  4e8b97: 5a                           	popl	%edx
  4e8b98: 59                           	popl	%ecx
  4e8b99: 59                           	popl	%ecx
  4e8b9a: 64 89 10                     	movl	%edx, %fs:(%eax)
  4e8b9d: 68 b3 8b 4e 00               	pushl	$0x4e8bb3               # imm = 0x4E8BB3
  4e8ba2: 8b 45 e0                     	movl	-0x20(%ebp), %eax
  4e8ba5: 50                           	pushl	%eax
  4e8ba6: e8 21 c7 06 00               	calll	0x5552cc <@Myimage@initialization$qqrv+0x946d8>
  4e8bab: c3                           	retl
  4e8bac: e9 57 8f 04 00               	jmp	0x531b08 <@Myimage@initialization$qqrv+0x70f14>
  4e8bb1: eb ef                        	jmp	0x4e8ba2 <@Myimage@initialization$qqrv+0x27fae>
  4e8bb3: 33 c0                        	xorl	%eax, %eax
  4e8bb5: 5a                           	popl	%edx
  4e8bb6: 59                           	popl	%ecx
  4e8bb7: 59                           	popl	%ecx
  4e8bb8: 64 89 10                     	movl	%edx, %fs:(%eax)
  4e8bbb: 68 dd 8b 4e 00               	pushl	$0x4e8bdd               # imm = 0x4E8BDD
  4e8bc0: 83 7d f4 00                  	cmpl	$0x0, -0xc(%ebp)
  4e8bc4: 74 0f                        	je	0x4e8bd5 <@Myimage@initialization$qqrv+0x27fe1>
  4e8bc6: 6a ff                        	pushl	$-0x1
  4e8bc8: 8b 45 cc                     	movl	-0x34(%ebp), %eax
  4e8bcb: 50                           	pushl	%eax
  4e8bcc: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8bcf: 50                           	pushl	%eax
  4e8bd0: e8 29 c8 06 00               	calll	0x5553fe <@Myimage@initialization$qqrv+0x9480a>
  4e8bd5: c3                           	retl
  4e8bd6: e9 2d 8f 04 00               	jmp	0x531b08 <@Myimage@initialization$qqrv+0x70f14>
  4e8bdb: eb e3                        	jmp	0x4e8bc0 <@Myimage@initialization$qqrv+0x27fcc>
  4e8bdd: 33 c0                        	xorl	%eax, %eax
  4e8bdf: 5a                           	popl	%edx
  4e8be0: 59                           	popl	%ecx
  4e8be1: 59                           	popl	%ecx
  4e8be2: 64 89 10                     	movl	%edx, %fs:(%eax)
  4e8be5: 68 ff 8b 4e 00               	pushl	$0x4e8bff               # imm = 0x4E8BFF
  4e8bea: 8b 45 ec                     	movl	-0x14(%ebp), %eax
  4e8bed: 50                           	pushl	%eax
  4e8bee: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8bf1: 50                           	pushl	%eax
  4e8bf2: e8 01 c8 06 00               	calll	0x5553f8 <@Myimage@initialization$qqrv+0x94804>
  4e8bf7: c3                           	retl
  4e8bf8: e9 0b 8f 04 00               	jmp	0x531b08 <@Myimage@initialization$qqrv+0x70f14>
  4e8bfd: eb eb                        	jmp	0x4e8bea <@Myimage@initialization$qqrv+0x27ff6>
  4e8bff: 33 c0                        	xorl	%eax, %eax
  4e8c01: 5a                           	popl	%edx
  4e8c02: 59                           	popl	%ecx
  4e8c03: 59                           	popl	%ecx
  4e8c04: 64 89 10                     	movl	%edx, %fs:(%eax)
  4e8c07: eb 18                        	jmp	0x4e8c21 <@Myimage@initialization$qqrv+0x2802d>
  4e8c09: e9 46 8c 04 00               	jmp	0x531854 <@Myimage@initialization$qqrv+0x70c60>
  4e8c0e: 8b 45 f0                     	movl	-0x10(%ebp), %eax
  4e8c11: 50                           	pushl	%eax
  4e8c12: e8 c1 c6 06 00               	calll	0x5552d8 <@Myimage@initialization$qqrv+0x946e4>
  4e8c17: e8 40 8f 04 00               	calll	0x531b5c <@Myimage@initialization$qqrv+0x70f68>
  4e8c1c: e8 8f 8f 04 00               	calll	0x531bb0 <@Myimage@initialization$qqrv+0x70fbc>
  4e8c21: 33 c0                        	xorl	%eax, %eax
  4e8c23: 5a                           	popl	%edx
  4e8c24: 59                           	popl	%ecx
  4e8c25: 59                           	popl	%ecx
  4e8c26: 64 89 10                     	movl	%edx, %fs:(%eax)
  4e8c29: 68 5f 8c 4e 00               	pushl	$0x4e8c5f               # imm = 0x4E8C5F
  4e8c2e: 8b 45 e4                     	movl	-0x1c(%ebp), %eax
  4e8c31: 50                           	pushl	%eax
  4e8c32: e8 95 c6 06 00               	calll	0x5552cc <@Myimage@initialization$qqrv+0x946d8>
  4e8c37: 8b 45 e8                     	movl	-0x18(%ebp), %eax
  4e8c3a: 50                           	pushl	%eax
  4e8c3b: 6a 00                        	pushl	$0x0
  4e8c3d: e8 50 cb 06 00               	calll	0x555792 <@Myimage@initialization$qqrv+0x94b9e>
  4e8c42: 83 7d f0 00                  	cmpl	$0x0, -0x10(%ebp)
  4e8c46: 74 0f                        	je	0x4e8c57 <@Myimage@initialization$qqrv+0x28063>
  4e8c48: 8b 45 0c                     	movl	0xc(%ebp), %eax
  4e8c4b: 50                           	pushl	%eax
  4e8c4c: 6a 54                        	pushl	$0x54
  4e8c4e: 8b 45 f0                     	movl	-0x10(%ebp), %eax
  4e8c51: 50                           	pushl	%eax
  4e8c52: e8 ff c6 06 00               	calll	0x555356 <@Myimage@initialization$qqrv+0x94762>
  4e8c57: c3                           	retl
  4e8c58: e9 ab 8e 04 00               	jmp	0x531b08 <@Myimage@initialization$qqrv+0x70f14>
  4e8c5d: eb cf                        	jmp	0x4e8c2e <@Myimage@initialization$qqrv+0x2803a>
  4e8c5f: 8b 45 f0                     	movl	-0x10(%ebp), %eax
  4e8c62: 5f                           	popl	%edi
  4e8c63: 5e                           	popl	%esi
  4e8c64: 5b                           	popl	%ebx
  4e8c65: 8b e5                        	movl	%ebp, %esp
  4e8c67: 5d                           	popl	%ebp
  4e8c68: c2 08 00                     	retl	$0x8
  4e8c6b: 90                           	nop
