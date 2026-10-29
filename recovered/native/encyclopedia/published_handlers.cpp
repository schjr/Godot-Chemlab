/* Published event names recovered from executable metadata.
   Bodies are Ghidra pseudocode, not original/buildable source.
   Class ownership and original signatures are unresolved. */

// Preserved published name: FormShow
// Entry 004021c4, recovered name Published_FormShow_004021c4

/* WARNING: Removing unreachable block (ram,0x004028d9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormShow_004021c4(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  VARIANTARG *pVVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  uint uVar7;
  undefined4 *in_FS_OFFSET;
  ushort uVar8;
  int local_16c;
  int local_168;
  int local_164;
  undefined1 local_14c [8];
  undefined1 local_144 [8];
  int local_13c;
  int *local_138;
  undefined4 local_134;
  int local_130;
  undefined4 local_12c;
  undefined2 local_11c;
  int local_110;
  int *local_108;
  int local_104;
  int local_a8;
  int local_a4;
  int *local_a0;
  VARIANTARG local_9c;
  VARIANTARG local_8c;
  VARIANTARG local_7c;
  VARIANTARG local_6c;
  VARIANTARG local_5c;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  VARIANTARG local_2c;
  int *local_18;
  int local_14;
  undefined *local_10;
  int local_c;
  int local_8;
  
  local_134 = param_2;
  local_130 = param_1;
  FUN_00502f50(0x5104a0);
  FUN_004037a8(local_144);
  FUN_004037a8(local_14c);
  if (DAT_00533e38 == '\0') {
    local_11c = 0x14;
    uVar8 = 0;
    pcVar1 = (code *)FUN_0050de08(*(int **)PTR_DAT_00533970,0xfffffffe);
    puVar2 = FUN_004016bc(&local_8);
    local_110 = local_110 + 1;
    (*pcVar1)(*(undefined4 *)PTR_DAT_00533970,puVar2);
    piVar6 = &local_8;
    piVar3 = FUN_004016bc(&local_10);
    local_110 = local_110 + 1;
    FUN_0050d87c(&local_c);
    local_110 = local_110 + 1;
    FUN_0050da18(piVar6,&local_c,piVar3);
    local_138 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_10,uVar8);
    local_110 = local_110 + -1;
    FUN_0050d9d4((int *)&local_10,2);
    local_110 = local_110 + -1;
    FUN_0050d9d4(&local_c,2);
    local_110 = local_110 + -1;
    FUN_0050d9d4(&local_8,2);
    local_13c = FUN_005020a8(0x1c);
    (**(code **)(*local_138 + 4))(local_138,local_13c,0x1c);
    (**(code **)(**(int **)PTR__bmp_005337d8 + 0x50))(*(int **)PTR__bmp_005337d8,local_138);
    *(undefined4 *)PTR__rect_w_005337c0 = *(undefined4 *)(local_13c + 4);
    *(undefined4 *)PTR__rect_h_005337c4 = *(undefined4 *)(local_13c + 8);
    *(undefined4 *)PTR__fz_w_005337c8 = *(undefined4 *)(local_13c + 0xc);
    *(undefined4 *)PTR__fz_h_005337cc = *(undefined4 *)(local_13c + 0x10);
    *(undefined4 *)PTR__fb_offx_005337d0 = *(undefined4 *)(local_13c + 0x14);
    *(undefined4 *)PTR__fb_offy_005337d4 = *(undefined4 *)(local_13c + 0x18);
    FUN_004c6438(*(int **)(local_130 + 0x2e0),0x26c);
    piVar6 = *(int **)PTR__bmp_005337d8;
    piVar3 = (int *)FUN_004befe0(*(int *)(*(int *)(local_130 + 0x2f0) + 0x20c),
                                 *(int *)(local_130 + 0x2f0),PTR__bmp_005337d8);
    FUN_004a8a40(piVar3,0,0,piVar6);
    local_18 = local_138;
    if (local_138 != (int *)0x0) {
      local_14 = *local_138;
      local_11c = 0x2c;
      (**(code **)(*local_138 + -4))(local_138,3);
      local_11c = 0x20;
    }
    FUN_00502074();
    DAT_00533e38 = '\x01';
    local_11c = 0;
    FUN_004445e0(*(int *)(local_130 + 0x458));
  }
  else {
    piVar6 = *(int **)PTR__bmp_005337d8;
    piVar3 = (int *)FUN_004befe0(*(int *)(*(int *)(local_130 + 0x2f0) + 0x20c),PTR__bmp_005337d8,
                                 local_130);
    FUN_004a8a40(piVar3,0,0,piVar6);
  }
  iVar4 = FUN_004b9e44();
  FUN_004c63f4(*(int **)PTR__hidelookup_00533804,iVar4 + 1);
  FUN_004b89ec(*(int **)PTR__hidelookup_00533804,PTR__hidelookup_00533804,extraout_ECX);
  FUN_004b8834(*(int **)PTR__hidelookup_00533804,PTR__hidelookup_00533804,extraout_ECX_00);
  pVVar5 = FUN_004037cc(&local_3c);
  local_110 = local_110 + 2;
  FUN_00403810(pVVar5);
  pVVar5 = FUN_004037cc(&local_4c);
  local_110 = local_110 + 2;
  FUN_00403810(pVVar5);
  pVVar5 = FUN_004037cc(&local_5c);
  local_110 = local_110 + 2;
  FUN_00403810(pVVar5);
  local_11c = 0x44;
  pVVar5 = FUN_004037cc(&local_2c);
  local_110 = local_110 + 2;
  FUN_00403810(pVVar5);
  _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
            (*(int **)(*(int *)PTR__hidelookup_00533804 + 0x2d0));
  local_110 = local_110 + -2;
  FUN_004038c8(&local_5c,2);
  local_110 = local_110 + -2;
  FUN_004038c8(&local_4c,2);
  local_110 = local_110 + -2;
  FUN_004038c8(&local_3c,2);
  local_110 = local_110 + -2;
  FUN_004038c8(&local_2c,2);
  pVVar5 = FUN_004037cc(&local_7c);
  local_110 = local_110 + 2;
  FUN_00403810(pVVar5);
  pVVar5 = FUN_004037cc(&local_8c);
  local_110 = local_110 + 2;
  FUN_00403810(pVVar5);
  pVVar5 = FUN_004037cc(&local_9c);
  local_110 = local_110 + 2;
  FUN_00403810(pVVar5);
  local_11c = 0x50;
  pVVar5 = FUN_004037cc(&local_6c);
  local_110 = local_110 + 2;
  FUN_00403810(pVVar5);
  _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
            (*(int **)(*(int *)(local_130 + 0x3d4) + 0x224));
  local_110 = local_110 + -2;
  FUN_004038c8(&local_9c,2);
  local_110 = local_110 + -2;
  FUN_004038c8(&local_8c,2);
  local_110 = local_110 + -2;
  FUN_004038c8(&local_7c,2);
  local_110 = local_110 + -2;
  FUN_004038c8(&local_6c,2);
  *(undefined4 *)(*(int *)(local_130 + 0x458) + 0x268) = *(undefined4 *)PTR__ressetup_00533810;
  *(undefined4 *)(*(int *)(local_130 + 0x458) + 0x26c) = *(undefined4 *)PTR__respsetup_00533814;
  *(undefined4 *)(*(int *)(local_130 + 0x458) + 0x278) = *(undefined4 *)(local_130 + 0x448);
  *(undefined4 *)(*(int *)(local_130 + 0x458) + 0x27c) = *(undefined4 *)(local_130 + 0x44c);
  *(undefined4 *)(*(int *)(local_130 + 0x458) + 0x280) = *(undefined4 *)(local_130 + 0x45c);
  *(undefined4 *)(*(int *)(local_130 + 0x458) + 0x284) = *(undefined4 *)(local_130 + 0x460);
  *(undefined4 *)(*(int *)(local_130 + 0x458) + 0x270) =
       *(undefined4 *)(*(int *)(local_130 + 0x2f4) + 0x208);
  local_a0 = (int *)FUN_005020a8(0x14);
  if (local_a0 != (int *)0x0) {
    local_11c = 0x68;
    FUN_004016bc(local_a0);
    local_110 = local_110 + 1;
    FUN_004016bc(local_a0 + 1);
    local_110 = local_110 + 1;
    FUN_004016bc(local_a0 + 2);
    local_110 = local_110 + 1;
    FUN_004016bc(local_a0 + 3);
    local_110 = local_110 + -3;
  }
  piVar6 = local_a0;
  local_11c = 0x74;
  FUN_0050d87c(&local_a4);
  local_110 = local_110 + 1;
  FUN_0050da04(piVar6,&local_a4);
  local_110 = local_110 + -1;
  FUN_0050d9d4(&local_a4,2);
  local_11c = 0x80;
  FUN_0050d87c(&local_a8);
  local_110 = local_110 + 1;
  FUN_0050da04(piVar6 + 1,&local_a8);
  local_110 = local_110 + -1;
  FUN_0050d9d4(&local_a8,2);
  *(undefined1 *)(piVar6 + 4) = 0;
  iVar4 = FUN_004dcc98(*(int **)(*(int *)(local_130 + 0x458) + 0x214));
  FUN_004dac0c(iVar4,piVar6);
  DAT_00533e64 = 1;
  _DAT_00533e90 = 0x7fef;
  DAT_00533e92 = 0x404f;
  FUN_00447950(1,&DAT_00533e66,&DAT_00533e88,&DAT_00533e8c,&DAT_00533e90,&DAT_00533e92,&DAT_00533e94
               ,&DAT_00533e96,&DAT_00533e98);
  _DAT_00533e88 = *(undefined4 *)(local_130 + 0x46c);
  DAT_00533e64 = 3;
  _DAT_00533e90 = 0x7fef;
  DAT_00533e92 = 0x404f;
  FUN_00447950(3,&DAT_00533e66,&DAT_00533e88,&DAT_00533e8c,&DAT_00533e90,&DAT_00533e92,&DAT_00533e94
               ,&DAT_00533e96,&DAT_00533e98);
  DAT_00533e64 = 5;
  _DAT_00533e90 = 0x10;
  DAT_00533e92 = 7;
  FUN_00447950(5,&DAT_00533e66,&DAT_00533e88,&DAT_00533e8c,&DAT_00533e90,&DAT_00533e92,&DAT_00533e94
               ,&DAT_00533e96,&DAT_00533e98);
  DAT_00533e64 = 0xc;
  _DAT_00533e90 = 8;
  DAT_00533e92 = 0;
  FUN_00447950(0xc,&DAT_00533e66,&DAT_00533e88,&DAT_00533e8c,&DAT_00533e90,&DAT_00533e92,
               &DAT_00533e94,&DAT_00533e96,&DAT_00533e98);
  *(undefined4 *)(local_130 + 0x470) = 1;
  piVar6 = (int *)FUN_004016ec((int *)PTR_PTR_004e6d4c,'\x01');
  if (DAT_005342c4 == '\0') {
    DAT_0053429d = 0x14;
    DAT_0053429e = '\x01';
    FUN_00401c64();
    local_164 = 5;
    do {
      iVar4 = FUN_00401c78(100);
      (&DAT_0053429c)[local_164] = (char)iVar4;
      local_164 = local_164 + 1;
    } while (local_164 < 0x14);
    if (*(char *)(*(int *)(*(int *)(local_130 + 0x400) + 0x80) + 8) == '\x01') {
      DAT_00534298 = 0;
      FUN_00482fb8(*(int **)(*(int *)(local_130 + 0x400) + 0x80),&DAT_0053429c,0x14);
      uVar7 = extraout_ECX_01;
      while (DAT_00534298 == 0) {
        FUN_004bbed4(*(int *)PTR_DAT_00533970,PTR_DAT_00533970,uVar7);
        uVar7 = extraout_ECX_02;
      }
    }
    else {
      DAT_005342c4 = '\x01';
    }
    if (DAT_005342c3 == 100) {
      local_168 = 5;
      do {
        (&DAT_005342b0)[local_168] = (&DAT_005342b0)[local_168] ^ DAT_005342c3;
        local_168 = local_168 + 1;
      } while (local_168 < 0x13);
    }
    local_16c = 5;
    do {
      (&DAT_005342b0)[local_16c] = (&DAT_005342b0)[local_16c] ^ DAT_005342b0;
      *(byte *)(local_16c + 0x5342b1) = *(byte *)(local_16c + 0x5342b1) ^ DAT_005342b3;
      local_16c = local_16c + 2;
    } while (local_16c < 0x13);
    if (DAT_0053429e == '\x01') {
      FUN_00401c94(local_130);
    }
    else if (DAT_0053429e == '\x02') {
      FUN_00401d10(local_130);
    }
    else if (DAT_0053429e == '\x03') {
      FUN_00401d8c(local_130);
    }
    else if (DAT_0053429e == '\x04') {
      FUN_00401e28(local_130);
    }
    else if (DAT_0053429e == '\x05') {
      FUN_00401ea8(local_130);
    }
    FUN_00504820(&DAT_005342a1,&DAT_0050f953);
    _DAT_0050f6f8 = FUN_00502cc8(&DAT_0053429c,(char *)&DAT_005342b0);
    if (_DAT_0050f6f8 != 0) {
      DAT_005342c4 = '\x01';
    }
  }
  if (piVar6 != (int *)0x0) {
    local_104 = *piVar6;
    local_11c = 0x140;
    local_108 = piVar6;
    (**(code **)(*piVar6 + -4))(piVar6,3);
  }
  *in_FS_OFFSET = local_12c;
  return;
}



// Preserved published name: FormCreate
// Entry 004038ec, recovered name Published_FormCreate_004038ec

void Published_FormCreate_004038ec(int *param_1,undefined4 param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined *puVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined1 in_stack_fffffe28;
  undefined4 *puVar9;
  CHAR local_1c0 [256];
  undefined4 local_c0;
  int *local_bc;
  undefined4 local_b0;
  int *local_ac;
  undefined4 local_a8;
  undefined2 local_98;
  int local_8c;
  int local_74;
  int local_70 [4];
  int *local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined *local_28;
  int local_24 [2];
  int local_1c;
  undefined *local_18;
  int local_14;
  int local_10;
  undefined *local_c;
  int local_8;
  
  local_b0 = param_2;
  local_ac = param_1;
  FUN_00502f50(0x5107f4);
  local_98 = 8;
  FUN_004016bc(&local_8);
  local_8c = local_8c + 1;
  local_98 = 0x20;
  FUN_004016bc(&local_c);
  local_8c = local_8c + 1;
  local_98 = 0x2c;
  FUN_004016bc(&local_10);
  local_8c = local_8c + 1;
  local_98 = 0x14;
  DAT_00533e38 = 0;
  OleInitialize((LPVOID)0x0);
  piVar2 = FUN_004ad7f8((int *)PTR_PTR_004a7098,'\x01',extraout_ECX);
  *(int **)PTR__bmp_005337d8 = piVar2;
  (**(code **)(**(int **)PTR__bmp_005337d8 + 0x34))(*(int **)PTR__bmp_005337d8,0x262);
  (**(code **)(**(int **)PTR__bmp_005337d8 + 0x40))(*(int **)PTR__bmp_005337d8,0x262);
  FUN_004aec20(*(int **)PTR__bmp_005337d8,7);
  local_98 = 0x38;
  piVar2 = FUN_0050d87c(&local_14);
  local_8c = local_8c + 1;
  puVar9 = (undefined4 *)*piVar2;
  iVar3 = FUN_004add64(*(int **)PTR__bmp_005337d8);
  FUN_004a817c(*(int **)(iVar3 + 0xc),puVar9);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_14,2);
  uVar4 = FUN_004016ec((int *)PTR_PTR_004e6d4c,'\x01');
  *(undefined4 *)PTR__rectlist_005337dc = uVar4;
  FUN_004107d4();
  *PTR__initbmp_005337e0 = 0;
  local_98 = 0x44;
  piVar2 = FUN_004016bc(&local_30);
  local_8c = local_8c + 1;
  piVar5 = FUN_004016bc(&local_28);
  local_8c = local_8c + 1;
  FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar5);
  piVar5 = FUN_004016bc(&local_2c);
  local_8c = local_8c + 1;
  FUN_004f6cdc(local_28,piVar5);
  uVar8 = 0x403a95;
  FUN_004042d4((undefined4 *)&stack0xfffffe28,local_2c);
  FUN_0040433c((undefined4 *)&stack0xfffffe20,s_i6t3r5o7e7_0050f9f6);
  piVar5 = FUN_00404580(&local_c0);
  iVar3 = FUN_004045b0(piVar5);
  piVar5 = FUN_004016bc(&local_18);
  local_8c = local_8c + 1;
  FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar5);
  uVar4 = 0x403ae2;
  piVar5 = FUN_004016bc(&local_1c);
  local_8c = local_8c + 1;
  FUN_004f6cdc(local_18,piVar5);
  uVar7 = 0xfc;
  FUN_004042d4((undefined4 *)&stack0xfffffe24,local_1c);
  FUN_0040433c((undefined4 *)&stack0xfffffe1c,s_i6t3r5o7e7_0050f9eb);
  piVar5 = FUN_0040446c(local_24,extraout_EDX,extraout_ECX_00,uVar4,uVar7,uVar8,in_stack_fffffe28);
  local_8c = local_8c + 1;
  uVar4 = FUN_004045c0(piVar5);
  FUN_004f7550(*(byte **)PTR__connectstr_005337ec,uVar4,iVar3,piVar2);
  FUN_0050da04(&local_8,&local_30);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_30,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_2c,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4((int *)&local_28,2);
  local_8c = local_8c + -1;
  FUN_00404550((int)local_24,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_1c,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4((int *)&local_18,2);
  FUN_0050da04((int *)PTR__connectstr_005337ec,&local_8);
  *(undefined4 *)PTR__nowelenum_005337e4 = 0;
  GetWindowsDirectoryA(local_1c0,0xff);
  local_98 = 0x50;
  FUN_0050d87c(&local_34);
  local_8c = local_8c + 1;
  FUN_0050da04((int *)&_tempdir,&local_34);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_34,2);
  local_98 = 0x5c;
  piVar2 = FUN_004016bc(&local_3c);
  local_8c = local_8c + 1;
  FUN_0050d87c(&local_38);
  local_8c = local_8c + 1;
  FUN_0050da18(&_tempdir,&local_38,piVar2);
  FUN_0050da04((int *)&_tempdir,&local_3c);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_3c,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_38,2);
  uVar4 = FUN_00447f7c(_tempdir);
  if ((char)uVar4 == '\0') {
    bVar1 = FUN_004f6e04(_tempdir);
    if (!bVar1) {
      local_98 = 0x68;
      piVar2 = FUN_0050d87c(&local_40);
      local_8c = local_8c + 1;
      FUN_004c1c04((undefined *)*piVar2);
      local_8c = local_8c + -1;
      FUN_0050d9d4(&local_40,2);
      FUN_004b8834(local_ac,extraout_EDX_00,extraout_ECX_01);
    }
  }
  local_98 = 0x74;
  piVar2 = FUN_004016bc(&local_48);
  local_8c = local_8c + 1;
  FUN_0050d87c(&local_44);
  local_8c = local_8c + 1;
  FUN_0050da18(&_tempdir,&local_44,piVar2);
  FUN_0050da04((int *)&_tempdir,&local_48);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_48,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_44,2);
  uVar4 = FUN_00447f7c(_tempdir);
  if ((char)uVar4 == '\0') {
    bVar1 = FUN_004f6e04(_tempdir);
    if (!bVar1) {
      local_98 = 0x80;
      piVar2 = FUN_0050d87c(&local_4c);
      local_8c = local_8c + 1;
      FUN_004c1c04((undefined *)*piVar2);
      local_8c = local_8c + -1;
      FUN_0050d9d4(&local_4c,2);
      FUN_004b8834(local_ac,extraout_EDX_01,extraout_ECX_02);
    }
  }
  local_98 = 0x8c;
  piVar2 = FUN_004016bc(&local_54);
  local_8c = local_8c + 1;
  FUN_0050d87c(&local_50);
  local_8c = local_8c + 1;
  FUN_0050da18(&_tempdir,&local_50,piVar2);
  FUN_0050da04((int *)&local_c,&local_54);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_54,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_50,2);
  local_98 = 0x98;
  local_bc = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_c,0xffff);
  local_98 = 0xa4;
  FUN_0050d87c(&local_58);
  local_8c = local_8c + 1;
  FUN_0050da04(&local_10,&local_58);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_58,2);
  uVar4 = FUN_00404394(&local_10);
  puVar6 = FUN_00404374(&local_10);
  (**(code **)(*local_bc + 8))(local_bc,puVar6,uVar4);
  local_60 = local_bc;
  if (local_bc != (int *)0x0) {
    local_5c = *local_bc;
    local_98 = 0xbc;
    (**(code **)(*local_bc + -4))(local_bc,3);
  }
  local_98 = 0x14;
  DAT_00533e58 = (int *)FUN_004043b8((int *)PTR_PTR_0047dc74,'\x01');
  *(undefined1 *)(DAT_00533e58 + 4) = 0;
  FUN_0047df1c(DAT_00533e58,local_ac[0xbc]);
  FUN_0047df1c(DAT_00533e58,local_ac[0xc5]);
  FUN_0047df1c(DAT_00533e58,local_ac[0xcd]);
  FUN_0047df1c(DAT_00533e58,local_ac[0xf6]);
  FUN_0047df1c(DAT_00533e58,local_ac[0xd9]);
  FUN_0047df1c(DAT_00533e58,local_ac[0xf7]);
  FUN_0047df1c(DAT_00533e58,local_ac[0x10a]);
  FUN_0047df1c(DAT_00533e58,local_ac[0x10b]);
  FUN_0047df1c(DAT_00533e58,local_ac[0x116]);
  DAT_00533e5c = (int *)FUN_004043b8((int *)PTR_PTR_0047dc74,'\x01');
  *(undefined1 *)(DAT_00533e5c + 4) = 0;
  FUN_0047df1c(DAT_00533e5c,local_ac[0xbd]);
  FUN_0047df1c(DAT_00533e5c,local_ac[0xf5]);
  FUN_0047df1c(DAT_00533e5c,local_ac[0xf4]);
  FUN_0047df1c(DAT_00533e5c,local_ac[0xfb]);
  FUN_0047df1c(DAT_00533e5c,local_ac[0x10c]);
  local_ac[0x11c] = 0;
  local_ac[0x11b] = 0;
  local_98 = 0xec;
  piVar2 = FUN_0050d87c(local_70);
  local_8c = local_8c + 1;
  FUN_004c6c30((int)local_ac,(uint *)*piVar2);
  local_8c = local_8c + -1;
  FUN_0050d9d4(local_70,2);
  local_98 = 0xf8;
  FUN_0050d87c(&local_74);
  local_8c = local_8c + 1;
  FUN_0050da04((int *)&DAT_00533e60,&local_74);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_74,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_10,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4((int *)&local_c,2);
  local_8c = local_8c + -1;
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_a8;
  return;
}



// Preserved published name: FormDestroy
// Entry 00404838, recovered name Published_FormDestroy_00404838

void Published_FormDestroy_00404838(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  
  FUN_00502f50(0x510a38);
  OleUninitialize();
  if (*(int *)PTR__rectlist_005337dc != 0) {
    iVar2 = (**(code **)(**(int **)PTR__rectlist_005337dc + 0x14))();
    if (0 < iVar2) {
      uVar4 = 0;
      iVar2 = 0;
      while( true ) {
        iVar3 = **(int **)PTR__rectlist_005337dc;
        iVar3 = (**(code **)(iVar3 + 0x14))
                          (*(int **)PTR__rectlist_005337dc,iVar3,uVar4,iVar2,param_2,param_1);
        if (iVar3 <= iVar2) break;
        uVar4 = (**(code **)(**(int **)PTR__rectlist_005337dc + 0x18))
                          (*(int **)PTR__rectlist_005337dc,iVar2);
        FUN_00502074();
        iVar2 = iVar2 + 1;
      }
    }
    (**(code **)(**(int **)PTR__rectlist_005337dc + 0x40))();
    piVar1 = *(int **)PTR__rectlist_005337dc;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + -4))(piVar1,3);
    }
  }
  piVar1 = *(int **)PTR__bmp_005337d8;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + -4))(piVar1,3);
  }
  (**(code **)(*DAT_00533e58 + 8))();
  (**(code **)(*DAT_00533e5c + 8))();
  if (DAT_00533e58 != (int *)0x0) {
    (**(code **)(*DAT_00533e58 + -4))(DAT_00533e58,3);
  }
  if (DAT_00533e5c != (int *)0x0) {
    (**(code **)(*DAT_00533e5c + -4))(DAT_00533e5c,3);
  }
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: SpeedButton1Click
// Entry 004049d8, recovered name Published_SpeedButton1Click_004049d8

void Published_SpeedButton1Click_004049d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  FUN_004c6b18(*(int **)(param_1 + 0x304),CONCAT31((int3)((uint)param_2 >> 8),1),param_3);
  iVar1 = **(int **)(param_1 + 0x304);
  (**(code **)(iVar1 + 0x5c))(*(int **)(param_1 + 0x304),1,iVar1,param_2);
  FUN_004c6b18(*(int **)(param_1 + 0x308),0,extraout_ECX);
  FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
  return;
}



// Preserved published name: SpeedButton2Click
// Entry 00404a2c, recovered name Published_SpeedButton2Click_00404a2c

void Published_SpeedButton2Click_00404a2c(int param_1)

{
  int *piVar1;
  int *piVar2;
  VARIANTARG *pVVar3;
  BSTR pOVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 local_80;
  VARIANTARG local_5c;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  VARIANTARG local_2c;
  OLECHAR local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x510b28);
  FUN_004c6b18(*(int **)(param_1 + 0x304),0,param_1);
  FUN_004c6b18(*(int **)(param_1 + 0x308),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
  if (*(char *)(*(int *)(param_1 + 0x31c) + 0x130) == '\0') {
    FUN_004c6438(*(int **)(param_1 + 0x2e0),0x26c);
    piVar1 = FUN_0050d87c(&local_c);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_c,2);
    piVar1 = FUN_0050d87c(&local_10);
    FUN_00401ff0(param_1,DAT_00533e5c,*piVar1);
    FUN_0050d9d4(&local_10,2);
    piVar1 = (int *)FUN_004ab1b8(*(int **)(*(int *)(*(int *)(param_1 + 0x2f0) + 0x20c) + 0x128));
    (**(code **)(*piVar1 + 0x40))
              (piVar1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2f0) + 0x20c) + 0x38));
    piVar1 = (int *)FUN_004ab1b8(*(int **)(*(int *)(*(int *)(param_1 + 0x2f0) + 0x20c) + 0x128));
    (**(code **)(*piVar1 + 0x34))
              (piVar1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2f0) + 0x20c) + 0x3c));
    piVar1 = *(int **)PTR__bmp_005337d8;
    piVar2 = (int *)FUN_004befe0(*(int *)(*(int *)(param_1 + 0x2f0) + 0x20c),
                                 *(int *)(param_1 + 0x2f0),extraout_ECX);
    FUN_004a8a40(piVar2,0,0,piVar1);
    if (0 < *(int *)PTR__nowelenum_005337e4) {
      FUN_00413674(*(int *)(param_1 + 0x2f0),*(int *)PTR__nowelenum_005337e4);
      pVVar3 = FUN_004037cc(&local_3c);
      FUN_00403810(pVVar3);
      pVVar3 = FUN_004037cc(&local_4c);
      FUN_00403810(pVVar3);
      pVVar3 = FUN_004037cc(&local_5c);
      FUN_00403810(pVVar3);
      piVar1 = FUN_004016bc(&local_18);
      FUN_0050d87c(&local_14);
      FUN_0050da18(&_tempdir,&local_14,piVar1);
      pOVar4 = FUN_0050e2a8(&local_1c);
      FUN_00404d4c(pOVar4);
      pVVar3 = FUN_004037cc(&local_2c);
      FUN_00403810(pVVar3);
      _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
                (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
      FUN_004038c8(&local_5c,2);
      FUN_004038c8(&local_4c,2);
      FUN_004038c8(&local_3c,2);
      FUN_004038c8(&local_2c,2);
      FUN_0050e31c(&local_1c,2);
      FUN_0050d9d4(&local_18,2);
      FUN_0050d9d4(&local_14,2);
    }
  }
  else {
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
    piVar1 = FUN_0050d87c(&local_8);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_80;
  return;
}



// Preserved published name: N5Click
// Entry 00404dc8, recovered name Published_N5Click_00404dc8

void Published_N5Click_00404dc8(int param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 *in_FS_OFFSET;
  ushort uVar7;
  int *local_60;
  undefined4 local_48;
  undefined *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  FUN_00502f50(0x510c0c);
  FUN_00405000(&local_8);
  FUN_004016bc(&local_c);
  piVar3 = FUN_004050a0(&local_10);
  FUN_00492738(*(int **)(*(int *)(param_1 + 0x2f4) + 0x208),0xcb,piVar3);
  iVar4 = FUN_0040512c(&local_10);
  if ((iVar4 == 0) || (cVar2 = (**(code **)(**(int **)(param_1 + 1000) + 0x3c))(), cVar2 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  FUN_004050ec(&local_10,2);
  if (bVar1) {
    piVar3 = FUN_004050a0(&local_14);
    FUN_00492738(*(int **)(*(int *)(param_1 + 0x2f4) + 0x208),0xcb,piVar3);
    piVar3 = (int *)FUN_0040512c(&local_14);
    FUN_004050ec(&local_14,2);
    (**(code **)(*piVar3 + 0x24))();
    if (local_60 != (int *)0x0) {
      FUN_00405030(&local_8);
      (**(code **)(*local_60 + 0xe8))();
      piVar3 = FUN_0050d8f0(&local_18);
      FUN_0050da04(&local_c,piVar3);
      FUN_0050d9d4(&local_18,2);
      uVar7 = 0xffff;
      piVar3 = FUN_004016bc(&local_1c);
      FUN_004c119c(*(int *)(param_1 + 1000),piVar3);
      piVar3 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_1c,uVar7);
      FUN_0050d9d4((int *)&local_1c,2);
      uVar5 = FUN_00404394(&local_c);
      puVar6 = FUN_00404374(&local_c);
      (**(code **)(*piVar3 + 8))(piVar3,puVar6,uVar5);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + -4))(piVar3,3);
      }
    }
  }
  FUN_0050d9d4(&local_c,2);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: PageControl1Change
// Entry 0040513c, recovered name Published_PageControl1Change_0040513c

void Published_PageControl1Change_0040513c(int param_1)

{
  VARIANTARG *pVVar1;
  int iVar2;
  int *piVar3;
  BSTR pOVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_1a0;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  VARIANTARG local_f8;
  VARIANTARG local_e8;
  VARIANTARG local_d8;
  VARIANTARG local_c8;
  OLECHAR local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  VARIANTARG local_9c;
  VARIANTARG local_8c;
  VARIANTARG local_7c;
  VARIANTARG local_6c;
  OLECHAR local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  VARIANTARG local_48;
  VARIANTARG local_38;
  VARIANTARG local_28;
  VARIANTARG local_18;
  int local_8;
  
  FUN_00502f50(0x511024);
  FUN_004016bc(&local_8);
  FUN_00497b1c(*(int *)(param_1 + 0x3e0),0);
  FUN_00497b1c(*(int *)(param_1 + 0x3e4),0);
  FUN_00497b1c(*(int *)(param_1 + 0x3f0),0);
  FUN_00497b1c(*(int *)(param_1 + 0x424),0);
  FUN_00497b1c(*(int *)(param_1 + 0x464),0);
  if (*(char *)(*(int *)(param_1 + 0x2f4) + 0x47) != '\0') {
    pVVar1 = FUN_004037cc(&local_28);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_38);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_48);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_18);
    FUN_00403810(pVVar1);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
    FUN_004038c8(&local_48,2);
    FUN_004038c8(&local_38,2);
    FUN_004038c8(&local_28,2);
    FUN_004038c8(&local_18,2);
  }
  iVar2 = FUN_004d9b90(*(int *)(param_1 + 0x2fc));
  if (iVar2 == 0) {
    FUN_00497b1c(*(int *)(param_1 + 0x368),1);
    if (*(char *)(*(int *)(param_1 + 0x308) + 0x47) == '\0') {
      if (*(char *)(*(int *)(param_1 + 0x398) + 0x130) == '\0') {
        FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
        if (0 < *(int *)PTR__nowelenum_005337e4) {
          pVVar1 = FUN_004037cc(&local_d8);
          FUN_00403810(pVVar1);
          pVVar1 = FUN_004037cc(&local_e8);
          FUN_00403810(pVVar1);
          pVVar1 = FUN_004037cc(&local_f8);
          FUN_00403810(pVVar1);
          piVar3 = FUN_004016bc(&local_b4);
          FUN_0050d87c(&local_b0);
          FUN_0050da18(&_tempdir,&local_b0,piVar3);
          pOVar4 = FUN_0050e2a8(&local_b8);
          FUN_00404d4c(pOVar4);
          pVVar1 = FUN_004037cc(&local_c8);
          FUN_00403810(pVVar1);
          _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
                    (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
          FUN_004038c8(&local_f8,2);
          FUN_004038c8(&local_e8,2);
          FUN_004038c8(&local_d8,2);
          FUN_004038c8(&local_c8,2);
          FUN_0050e31c(&local_b8,2);
          FUN_0050d9d4(&local_b4,2);
          FUN_0050d9d4(&local_b0,2);
        }
        piVar3 = FUN_0050d87c(&local_fc);
        FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
        FUN_0050d9d4(&local_fc,2);
      }
      else {
        FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
        piVar3 = FUN_0050d87c(&local_a8);
        FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
        FUN_0050d9d4(&local_a8,2);
        piVar3 = FUN_0050d87c(&local_ac);
        FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
        FUN_0050d9d4(&local_ac,2);
      }
    }
    else if (*(char *)(*(int *)(param_1 + 0x31c) + 0x130) == '\0') {
      FUN_004c6438(*(int **)(param_1 + 0x2e0),0x26c);
      if (0 < *(int *)PTR__nowelenum_005337e4) {
        pVVar1 = FUN_004037cc(&local_7c);
        FUN_00403810(pVVar1);
        pVVar1 = FUN_004037cc(&local_8c);
        FUN_00403810(pVVar1);
        pVVar1 = FUN_004037cc(&local_9c);
        FUN_00403810(pVVar1);
        piVar3 = FUN_004016bc(&local_58);
        FUN_0050d87c(&local_54);
        FUN_0050da18(&_tempdir,&local_54,piVar3);
        pOVar4 = FUN_0050e2a8(&local_5c);
        FUN_00404d4c(pOVar4);
        pVVar1 = FUN_004037cc(&local_6c);
        FUN_00403810(pVVar1);
        _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
                  (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
        FUN_004038c8(&local_9c,2);
        FUN_004038c8(&local_8c,2);
        FUN_004038c8(&local_7c,2);
        FUN_004038c8(&local_6c,2);
        FUN_0050e31c(&local_5c,2);
        FUN_0050d9d4(&local_58,2);
        FUN_0050d9d4(&local_54,2);
      }
      piVar3 = FUN_0050d87c(&local_a0);
      FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
      FUN_0050d9d4(&local_a0,2);
      piVar3 = FUN_0050d87c(&local_a4);
      FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
      FUN_0050d9d4(&local_a4,2);
    }
    else {
      FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
      piVar3 = FUN_0050d87c(&local_4c);
      FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
      FUN_0050d9d4(&local_4c,2);
      piVar3 = FUN_0050d87c(&local_50);
      FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
      FUN_0050d9d4(&local_50,2);
    }
  }
  else {
    iVar2 = FUN_004d9b90(*(int *)(param_1 + 0x2fc));
    if (iVar2 == 1) {
      FUN_00497b1c(*(int *)(param_1 + 0x36c),1);
      if (*(char *)(*(int *)(param_1 + 0x324) + 0x47) == '\0') {
        if (*(char *)(*(int *)(param_1 + 0x39c) + 0x130) == '\0') {
          FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
          piVar3 = FUN_0050d87c(&local_120);
          FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
          FUN_0050d9d4(&local_120,2);
        }
        else {
          FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
          piVar3 = FUN_0050d87c(&local_118);
          FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
          FUN_0050d9d4(&local_118,2);
          piVar3 = FUN_0050d87c(&local_11c);
          FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
          FUN_0050d9d4(&local_11c,2);
        }
      }
      else if (*(char *)(*(int *)(param_1 + 0x330) + 0x130) == '\0') {
        FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
        piVar3 = FUN_0050d87c(&local_108);
        FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
        FUN_0050d9d4(&local_108,2);
        piVar3 = FUN_0050d87c(&local_10c);
        FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
        FUN_0050d9d4(&local_10c,2);
        *(undefined1 *)(*(int *)(param_1 + 0x334) + 0x225) = 0;
        piVar3 = FUN_0050d87c(&local_110);
        FUN_004c6c30(*(int *)(*(int *)(param_1 + 0x334) + 0x214),(uint *)*piVar3);
        FUN_0050d9d4(&local_110,2);
        *(undefined1 *)(*(int *)(param_1 + 0x334) + 0x225) = 1;
        piVar3 = FUN_0050d87c(&local_114);
        FUN_0042ca5c(*(int *)(param_1 + 0x334),*piVar3);
        FUN_0050d9d4(&local_114,2);
      }
      else {
        FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
        piVar3 = FUN_0050d87c(&local_100);
        FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
        FUN_0050d9d4(&local_100,2);
        piVar3 = FUN_0050d87c(&local_104);
        FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
        FUN_0050d9d4(&local_104,2);
      }
    }
    else {
      iVar2 = FUN_004d9b90(*(int *)(param_1 + 0x2fc));
      if (iVar2 == 3) {
        FUN_00497b1c(*(int *)(param_1 + 0x420),1);
        if (*(char *)(*(int *)(param_1 + 0x40c) + 0x47) == '\0') {
          if (*(char *)(*(int *)(param_1 + 0x41c) + 0x130) == '\0') {
            FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
            piVar3 = FUN_0050d87c(&local_144);
            FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
            FUN_0050d9d4(&local_144,2);
          }
          else {
            FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
            piVar3 = FUN_0050d87c(&local_13c);
            FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
            FUN_0050d9d4(&local_13c,2);
            piVar3 = FUN_0050d87c(&local_140);
            FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
            FUN_0050d9d4(&local_140,2);
          }
        }
        else if (*(char *)(*(int *)(param_1 + 0x418) + 0x130) == '\0') {
          FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
          piVar3 = FUN_0050d87c(&local_12c);
          FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
          FUN_0050d9d4(&local_12c,2);
          piVar3 = FUN_0050d87c(&local_130);
          FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
          FUN_0050d9d4(&local_130,2);
          *(undefined1 *)(*(int *)(param_1 + 0x428) + 0x225) = 0;
          piVar3 = FUN_0050d87c(&local_134);
          FUN_004c6c30(*(int *)(*(int *)(param_1 + 0x428) + 0x214),(uint *)*piVar3);
          FUN_0050d9d4(&local_134,2);
          *(undefined1 *)(*(int *)(param_1 + 0x428) + 0x225) = 1;
          piVar3 = FUN_0050d87c(&local_138);
          FUN_0043aa44(*(int *)(param_1 + 0x428),*piVar3);
          FUN_0050d9d4(&local_138,2);
        }
        else {
          FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
          piVar3 = FUN_0050d87c(&local_124);
          FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
          FUN_0050d9d4(&local_124,2);
          piVar3 = FUN_0050d87c(&local_128);
          FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
          FUN_0050d9d4(&local_128,2);
        }
      }
      else {
        iVar2 = FUN_004d9b90(*(int *)(param_1 + 0x2fc));
        if (iVar2 == 2) {
          FUN_00497b1c(*(int *)(param_1 + 0x370),1);
          if (*(char *)(*(int *)(param_1 + 0x354) + 0x47) == '\0') {
            if (*(char *)(*(int *)(param_1 + 0x3a0) + 0x130) == '\0') {
              FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
              piVar3 = FUN_0050d87c(&local_168);
              FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
              FUN_0050d9d4(&local_168,2);
            }
            else {
              FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
              piVar3 = FUN_0050d87c(&local_160);
              FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
              FUN_0050d9d4(&local_160,2);
              piVar3 = FUN_0050d87c(&local_164);
              FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
              FUN_0050d9d4(&local_164,2);
            }
          }
          else if (*(char *)(*(int *)(param_1 + 0x360) + 0x130) == '\0') {
            FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
            piVar3 = FUN_0050d87c(&local_150);
            FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
            FUN_0050d9d4(&local_150,2);
            piVar3 = FUN_0050d87c(&local_154);
            FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
            FUN_0050d9d4(&local_154,2);
            *(undefined1 *)(*(int *)(param_1 + 0x3d8) + 0x225) = 0;
            piVar3 = FUN_0050d87c(&local_158);
            FUN_004c6c30(*(int *)(*(int *)(param_1 + 0x3d8) + 0x214),(uint *)*piVar3);
            FUN_0050d9d4(&local_158,2);
            *(undefined1 *)(*(int *)(param_1 + 0x3d8) + 0x225) = 1;
            piVar3 = FUN_0050d87c(&local_15c);
            FUN_004387ac(*(int *)(param_1 + 0x3d8),*piVar3);
            FUN_0050d9d4(&local_15c,2);
          }
          else {
            FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
            piVar3 = FUN_0050d87c(&local_148);
            FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
            FUN_0050d9d4(&local_148,2);
            piVar3 = FUN_0050d87c(&local_14c);
            FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
            FUN_0050d9d4(&local_14c,2);
          }
        }
        else {
          iVar2 = FUN_004d9b90(*(int *)(param_1 + 0x2fc));
          if (iVar2 == 4) {
            FUN_00497b1c(*(int *)(param_1 + 0x468),1);
            if (*(char *)(*(int *)(param_1 + 0x444) + 0x47) == '\0') {
              FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
              piVar3 = FUN_0050d87c(&local_17c);
              FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
              FUN_0050d9d4(&local_17c,2);
            }
            else if (*(char *)(*(int *)(param_1 + 0x450) + 0x130) == '\0') {
              FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
              piVar3 = FUN_0050d87c(&local_174);
              FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
              FUN_0050d9d4(&local_174,2);
              piVar3 = FUN_0050d87c(&local_178);
              FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
              FUN_0050d9d4(&local_178,2);
              FUN_004d9ba8(*(int **)(*(int *)(param_1 + 0x458) + 0x208),0);
            }
            else {
              FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
              piVar3 = FUN_0050d87c(&local_16c);
              FUN_00401ff0(param_1,DAT_00533e58,*piVar3);
              FUN_0050d9d4(&local_16c,2);
              piVar3 = FUN_0050d87c(&local_170);
              FUN_00401ff0(param_1,DAT_00533e5c,*piVar3);
              FUN_0050d9d4(&local_170,2);
              FUN_004d9ba8(*(int **)(*(int *)(param_1 + 0x458) + 0x208),1);
            }
          }
          else {
            FUN_004d9b90(*(int *)(param_1 + 0x2fc));
          }
        }
      }
    }
  }
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_1a0;
  return;
}



// Preserved published name: SpeedButton5Click
// Entry 00406624, recovered name Published_SpeedButton5Click_00406624

void Published_SpeedButton5Click_00406624(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((0 < *(int *)PTR__nowelenum_005337e4) && (DAT_0050f6ec == '\0')) {
    DAT_0050f6ec = 1;
    uVar1 = FUN_00413674(*(int *)(param_1 + 0x2f0),*(int *)PTR__nowelenum_005337e4 + -1);
    if ((char)uVar1 != '\0') {
      uVar1 = *(undefined4 *)PTR__nowelenum_005337e4;
      uVar2 = FUN_004171fc(*(int *)(param_1 + 0x2f4),*(undefined4 *)PTR__nowelenum_005337e4);
      if ((char)uVar2 != '\0') {
        *(undefined4 *)PTR__nowelenum_005337e4 = uVar1;
      }
    }
    DAT_0050f6ec = '\0';
    if (*(char *)(*(int *)(param_1 + 0x398) + 0x130) != '\0') {
      FUN_00431094(*(int *)(param_1 + 0x3d0),*(int *)PTR__nowelenum_005337e4);
    }
  }
  return;
}



// Preserved published name: SpeedButton6Click
// Entry 004066d0, recovered name Published_SpeedButton6Click_004066d0

void Published_SpeedButton6Click_004066d0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (((0 < *(int *)PTR__nowelenum_005337e4) && (*(int *)PTR__nowelenum_005337e4 < 0x67)) &&
     (DAT_0050f6ec == '\0')) {
    DAT_0050f6ec = 1;
    uVar1 = FUN_00413674(*(int *)(param_1 + 0x2f0),*(int *)PTR__nowelenum_005337e4 + 1);
    if ((char)uVar1 != '\0') {
      uVar1 = *(undefined4 *)PTR__nowelenum_005337e4;
      uVar2 = FUN_004171fc(*(int *)(param_1 + 0x2f4),*(undefined4 *)PTR__nowelenum_005337e4);
      if ((char)uVar2 != '\0') {
        *(undefined4 *)PTR__nowelenum_005337e4 = uVar1;
      }
    }
    DAT_0050f6ec = '\0';
    if (*(char *)(*(int *)(param_1 + 0x398) + 0x130) != '\0') {
      FUN_00431094(*(int *)(param_1 + 0x3d0),*(int *)PTR__nowelenum_005337e4);
    }
  }
  return;
}



// Preserved published name: Frame61ListBox1Click
// Entry 0040678c, recovered name Published_Frame61ListBox1Click_0040678c

void Published_Frame61ListBox1Click_0040678c(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  byte *local_c;
  undefined *local_8;
  
  FUN_00502f50(0x511258);
  Published_ListBox1Click_004271cc();
  iVar5 = *(int *)(*(int *)(param_1 + 0x314) + 0x218);
  puVar2 = FUN_004016bc(&local_8);
  uVar3 = FUN_0048fcc0(*(int **)(*(int *)(param_1 + 0x314) + 0x218));
  piVar4 = *(int **)(iVar5 + 0x1f0);
  (**(code **)(*piVar4 + 0xc))(piVar4,uVar3,puVar2);
  piVar4 = FUN_004016bc(&local_c);
  FUN_00427050(*(undefined4 *)(param_1 + 0x314),local_8,piVar4);
  iVar5 = FUN_004f6a40(local_c);
  FUN_0050d9d4((int *)&local_c,2);
  FUN_0050d9d4((int *)&local_8,2);
  cVar1 = FUN_00426e88(*(int *)(param_1 + 0x314));
  if (cVar1 == '\0') {
    FUN_00426e9c(*(int *)(param_1 + 0x314),'\x01');
    uVar3 = FUN_00413674(*(int *)(param_1 + 0x2f0),iVar5);
    if ((char)uVar3 != '\0') {
      uVar3 = *(undefined4 *)PTR__nowelenum_005337e4;
      uVar6 = FUN_004171fc(*(int *)(param_1 + 0x2f4),*(undefined4 *)PTR__nowelenum_005337e4);
      if ((char)uVar6 != '\0') {
        *(undefined4 *)PTR__nowelenum_005337e4 = uVar3;
      }
    }
    FUN_00426e9c(*(int *)(param_1 + 0x314),'\0');
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: SpeedButton7Click
// Entry 004068d4, recovered name Published_SpeedButton7Click_004068d4

void Published_SpeedButton7Click_004068d4(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 local_38;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x5112ac);
  FUN_004c6b18(*(int **)(param_1 + 0x308),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
  FUN_004c6b18(*(int **)(param_1 + 0x304),0,param_1);
  iVar1 = *(int *)(param_1 + 0x31c);
  if (*(char *)(iVar1 + 0x130) == '\0') {
    FUN_004c6b18(*(int **)(param_1 + 0x2f0),CONCAT31((int3)((uint)param_1 >> 8),1),iVar1);
    FUN_004c6b18(*(int **)(param_1 + 0x314),0,param_1);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),0x26c);
    piVar2 = FUN_0050d87c(&local_10);
    FUN_0050da04((int *)(*(int *)(param_1 + 0x308) + 0x70),piVar2);
    FUN_0050d9d4(&local_10,2);
    piVar2 = FUN_0050d87c(&local_14);
    FUN_0050da04((int *)(*(int *)(param_1 + 0x304) + 0x70),piVar2);
    FUN_0050d9d4(&local_14,2);
  }
  else {
    FUN_004c6b18(*(int **)(param_1 + 0x2f0),0,iVar1);
    FUN_004c6b18(*(int **)(param_1 + 0x314),CONCAT31((int3)((uint)extraout_EDX_00 >> 8),1),param_1);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
    piVar2 = FUN_0050d87c(&local_8);
    FUN_0050da04((int *)(*(int *)(param_1 + 0x308) + 0x70),piVar2);
    FUN_0050d9d4(&local_8,2);
    piVar2 = FUN_0050d87c(&local_c);
    FUN_0050da04((int *)(*(int *)(param_1 + 0x304) + 0x70),piVar2);
    FUN_0050d9d4(&local_c,2);
  }
  *in_FS_OFFSET = local_38;
  return;
}



// Preserved published name: Frame31Image1MouseDown
// Entry 00406a80, recovered name Published_Frame31Image1MouseDown_00406a80

void Published_Frame31Image1MouseDown_00406a80
               (int param_1,undefined4 param_2,undefined1 param_3,int param_4,int param_5)

{
  VARIANTARG *pVVar1;
  int *piVar2;
  BSTR pOVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_74;
  VARIANTARG local_50;
  VARIANTARG local_40;
  VARIANTARG local_30;
  VARIANTARG local_20;
  OLECHAR local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51133c);
  Published_Image1MouseDown_00410ed4(*(int *)(param_1 + 0x2f0),param_2,param_3,param_4,param_5);
  if (0 < *(int *)PTR__nowelenum_005337e4) {
    pVVar1 = FUN_004037cc(&local_30);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_40);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_50);
    FUN_00403810(pVVar1);
    piVar2 = FUN_004016bc(&local_c);
    FUN_0050d87c(&local_8);
    FUN_0050da18(&_tempdir,&local_8,piVar2);
    pOVar3 = FUN_0050e2a8(&local_10);
    FUN_00404d4c(pOVar3);
    pVVar1 = FUN_004037cc(&local_20);
    FUN_00403810(pVVar1);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
    FUN_004038c8(&local_50,2);
    FUN_004038c8(&local_40,2);
    FUN_004038c8(&local_30,2);
    FUN_004038c8(&local_20,2);
    FUN_0050e31c(&local_10,2);
    FUN_0050d9d4(&local_c,2);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_74;
  return;
}



// Preserved published name: SpeedButton10Click
// Entry 00406c0c, recovered name Published_SpeedButton10Click_00406c0c

void Published_SpeedButton10Click_00406c0c(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 local_38;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x511390);
  FUN_004c6b18(*(int **)(param_1 + 0x324),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
  FUN_004c6b18(*(int **)(param_1 + 800),0,param_1);
  iVar1 = *(int *)(param_1 + 0x330);
  if (*(char *)(iVar1 + 0x130) == '\0') {
    FUN_004c6b18(*(int **)(param_1 + 0x334),CONCAT31((int3)((uint)param_1 >> 8),1),iVar1);
    FUN_004c6b18(*(int **)(param_1 + 0x364),0,param_1);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
    piVar2 = FUN_0050d87c(&local_10);
    FUN_0050da04((int *)(*(int *)(param_1 + 0x324) + 0x70),piVar2);
    FUN_0050d9d4(&local_10,2);
    piVar2 = FUN_0050d87c(&local_14);
    FUN_0050da04((int *)(*(int *)(param_1 + 800) + 0x70),piVar2);
    FUN_0050d9d4(&local_14,2);
  }
  else {
    FUN_004c6b18(*(int **)(param_1 + 0x334),0,iVar1);
    FUN_004c6b18(*(int **)(param_1 + 0x364),CONCAT31((int3)((uint)extraout_EDX_00 >> 8),1),param_1);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
    piVar2 = FUN_0050d87c(&local_8);
    FUN_0050da04((int *)(*(int *)(param_1 + 0x324) + 0x70),piVar2);
    FUN_0050d9d4(&local_8,2);
    piVar2 = FUN_0050d87c(&local_c);
    FUN_0050da04((int *)(*(int *)(param_1 + 800) + 0x70),piVar2);
    FUN_0050d9d4(&local_c,2);
  }
  *in_FS_OFFSET = local_38;
  return;
}



// Preserved published name: SpeedButton4Click
// Entry 00406db8, recovered name Published_SpeedButton4Click_00406db8

void Published_SpeedButton4Click_00406db8(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004c6b18(*(int **)(param_1 + 800),CONCAT31((int3)((uint)param_2 >> 8),1),param_3);
  FUN_004c6b18(*(int **)(param_1 + 0x324),0,param_1);
  FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
  return;
}



// Preserved published name: SpeedButton3Click
// Entry 00406dfc, recovered name Published_SpeedButton3Click_00406dfc

void Published_SpeedButton3Click_00406dfc(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 extraout_EDX;
  
  FUN_004c6b18(*(int **)(param_1 + 800),0,param_3);
  FUN_004c6b18(*(int **)(param_1 + 0x324),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
  if (*(char *)(*(int *)(param_1 + 0x330) + 0x130) == '\0') {
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  else {
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  return;
}



// Preserved published name: lookupChemicals1ListBox1Click
// Entry 00406e68, recovered name Published_lookupChemicals1ListBox1Click_00406e68

void Published_lookupChemicals1ListBox1Click_00406e68(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  BSTR pOVar6;
  int iVar7;
  VARIANTARG *pVVar8;
  int *piVar9;
  undefined *puVar10;
  undefined4 *in_FS_OFFSET;
  LPCWSTR pWVar11;
  undefined4 local_158;
  VARIANTARG local_134;
  VARIANTARG local_124;
  VARIANTARG local_114;
  VARIANTARG local_104;
  OLECHAR local_f4;
  int *local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined *local_44;
  int local_40;
  int local_3c;
  int local_38;
  VARIANTARG local_34;
  OLECHAR local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  int local_10;
  undefined *local_c;
  int local_8;
  
  FUN_00502f50(0x51174c);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_004016bc(&local_10);
  FUN_004016bc(&local_14);
  cVar1 = FUN_0042f338(*(int *)(param_1 + 0x364));
  if (cVar1 == '\0') {
    FUN_0042f34c(*(int *)(param_1 + 0x364),'\x01');
    iVar7 = *(int *)(*(int *)(param_1 + 0x364) + 0x22c);
    puVar2 = FUN_004016bc(&local_18);
    uVar3 = FUN_0048fcc0(*(int **)(*(int *)(param_1 + 0x364) + 0x22c));
    piVar4 = *(int **)(iVar7 + 0x1f0);
    (**(code **)(*piVar4 + 0xc))(piVar4,uVar3,puVar2);
    FUN_0050da04((int *)&local_c,&local_18);
    FUN_0050d9d4(&local_18,2);
    piVar4 = FUN_004016bc(&local_1c);
    FUN_0042f378(*(undefined4 *)(param_1 + 0x364),local_c,piVar4);
    FUN_0050da04(&local_8,&local_1c);
    FUN_0050d9d4(&local_1c,2);
    FUN_0047a9e4(*(int **)(*(int *)(param_1 + 0x364) + 0x230));
    piVar4 = (int *)FUN_0045cef8(*(int *)(*(int *)(param_1 + 0x364) + 0x230));
    (**(code **)(*piVar4 + 0x40))();
    piVar4 = (int *)FUN_0045cef8(*(int *)(*(int *)(param_1 + 0x364) + 0x230));
    piVar5 = FUN_0050d87c(&local_20);
    (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
    FUN_0050d9d4(&local_20,2);
    pOVar6 = FUN_0050e234(&local_24);
    pWVar11 = (LPCWSTR)*pOVar6;
    iVar7 = FUN_0045b63c(*(int *)(*(int *)(param_1 + 0x364) + 0x230));
    iVar7 = FUN_00453fcc(iVar7,pWVar11);
    pVVar8 = FUN_0050df38(&local_34,&local_8);
    FUN_00455258(iVar7,pVVar8);
    FUN_0050e004(&local_34,2);
    FUN_0050e31c(&local_24,2);
    FUN_0047a9d8(*(int **)(*(int *)(param_1 + 0x364) + 0x230));
    iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0x364) + 0x230) + 0x14c))();
    if (0 < iVar7) {
      FUN_0047c964(*(int **)(*(int *)(param_1 + 0x364) + 0x230));
      FUN_0050d87c(&local_38);
      FUN_0050da04(&local_10,&local_38);
      FUN_0050d9d4(&local_38,2);
      piVar4 = FUN_004016bc(&local_44);
      FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar4);
      piVar4 = FUN_004016bc(&local_48);
      FUN_004f6cdc(local_44,piVar4);
      piVar4 = &local_48;
      piVar5 = FUN_004016bc(&local_40);
      FUN_0050d87c(&local_3c);
      FUN_0050da18(&local_10,&local_3c,piVar5);
      piVar5 = &local_40;
      piVar9 = FUN_004016bc(&local_4c);
      FUN_0050da18(piVar5,piVar4,piVar9);
      piVar4 = &local_4c;
      piVar5 = FUN_004016bc(&local_54);
      FUN_0050d87c(&local_50);
      FUN_0050da18(piVar4,&local_50,piVar5);
      FUN_0050da04(&local_10,&local_54);
      FUN_0050d9d4(&local_54,2);
      FUN_0050d9d4(&local_50,2);
      FUN_0050d9d4(&local_4c,2);
      FUN_0050d9d4(&local_48,2);
      FUN_0050d9d4((int *)&local_44,2);
      FUN_0050d9d4(&local_40,2);
      FUN_0050d9d4(&local_3c,2);
      piVar4 = FUN_004016bc(&local_5c);
      FUN_0050d87c(&local_58);
      FUN_0050da18(&local_10,&local_58,piVar4);
      FUN_0050da04(&local_10,&local_5c);
      FUN_0050d9d4(&local_5c,2);
      FUN_0050d9d4(&local_58,2);
      piVar4 = FUN_004016bc(&local_64);
      FUN_0050d87c(&local_60);
      FUN_0050da18(&local_10,&local_60,piVar4);
      piVar4 = &local_64;
      piVar5 = FUN_004016bc(&local_68);
      FUN_0050da18(piVar4,&local_8,piVar5);
      FUN_0050da04(&local_10,&local_68);
      FUN_0050d9d4(&local_68,2);
      FUN_0050d9d4(&local_64,2);
      FUN_0050d9d4(&local_60,2);
      piVar4 = FUN_0050d87c(&local_74);
      piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x364) + 0x230),(undefined *)*piVar4)
      ;
      puVar2 = FUN_004016bc(&local_78);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
      piVar4 = &local_78;
      piVar5 = FUN_004016bc(&local_70);
      FUN_0050d87c(&local_6c);
      FUN_0050da18(&local_10,&local_6c,piVar5);
      piVar5 = &local_70;
      piVar9 = FUN_004016bc(&local_7c);
      FUN_0050da18(piVar5,piVar4,piVar9);
      piVar4 = &local_7c;
      piVar5 = FUN_004016bc(&local_84);
      FUN_0050d87c(&local_80);
      FUN_0050da18(piVar4,&local_80,piVar5);
      FUN_0050da04(&local_10,&local_84);
      FUN_0050d9d4(&local_84,2);
      FUN_0050d9d4(&local_80,2);
      FUN_0050d9d4(&local_7c,2);
      FUN_0050d9d4(&local_78,2);
      FUN_0050d9d4(&local_74,2);
      FUN_0050d9d4(&local_70,2);
      FUN_0050d9d4(&local_6c,2);
      piVar4 = FUN_004016bc(&local_8c);
      FUN_0050d87c(&local_88);
      FUN_0050da18(&local_10,&local_88,piVar4);
      FUN_0050da04(&local_10,&local_8c);
      FUN_0050d9d4(&local_8c,2);
      FUN_0050d9d4(&local_88,2);
      piVar4 = FUN_0050d87c(&local_90);
      piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x364) + 0x230),(undefined *)*piVar4)
      ;
      puVar2 = FUN_004016bc(&local_94);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
      piVar4 = &local_94;
      FUN_0050d87c(&local_98);
      cVar1 = FUN_0050dabc(piVar4,&local_98);
      FUN_0050d9d4(&local_98,2);
      FUN_0050d9d4(&local_94,2);
      FUN_0050d9d4(&local_90,2);
      if (cVar1 != '\0') {
        piVar4 = FUN_0050d87c(&local_a4);
        piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x364) + 0x230),
                                     (undefined *)*piVar4);
        puVar2 = FUN_004016bc(&local_a8);
        (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
        piVar4 = &local_a8;
        piVar5 = FUN_004016bc(&local_a0);
        FUN_0050d87c(&local_9c);
        FUN_0050da18(&local_10,&local_9c,piVar5);
        piVar5 = &local_a0;
        piVar9 = FUN_004016bc(&local_ac);
        FUN_0050da18(piVar5,piVar4,piVar9);
        FUN_0050da04(&local_10,&local_ac);
        FUN_0050d9d4(&local_ac,2);
        FUN_0050d9d4(&local_a8,2);
        FUN_0050d9d4(&local_a4,2);
        FUN_0050d9d4(&local_a0,2);
        FUN_0050d9d4(&local_9c,2);
        piVar4 = FUN_004016bc(&local_b4);
        FUN_0050d87c(&local_b0);
        FUN_0050da18(&local_10,&local_b0,piVar4);
        FUN_0050da04(&local_10,&local_b4);
        FUN_0050d9d4(&local_b4,2);
        FUN_0050d9d4(&local_b0,2);
      }
      piVar4 = FUN_0050d87c(&local_c0);
      piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x364) + 0x230),(undefined *)*piVar4)
      ;
      puVar2 = FUN_004016bc(&local_c4);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
      piVar4 = &local_c4;
      piVar5 = FUN_004016bc(&local_bc);
      FUN_0050d87c(&local_b8);
      FUN_0050da18(&local_10,&local_b8,piVar5);
      piVar5 = &local_bc;
      piVar9 = FUN_004016bc(&local_c8);
      FUN_0050da18(piVar5,piVar4,piVar9);
      FUN_0050da04(&local_10,&local_c8);
      FUN_0050d9d4(&local_c8,2);
      FUN_0050d9d4(&local_c4,2);
      FUN_0050d9d4(&local_c0,2);
      FUN_0050d9d4(&local_bc,2);
      FUN_0050d9d4(&local_b8,2);
      piVar4 = FUN_004016bc(&local_d0);
      FUN_0050d87c(&local_cc);
      FUN_0050da18(&local_10,&local_cc,piVar4);
      FUN_0050da04(&local_10,&local_d0);
      FUN_0050d9d4(&local_d0,2);
      FUN_0050d9d4(&local_cc,2);
      piVar4 = FUN_004016bc(&local_d8);
      FUN_0050d87c(&local_d4);
      FUN_0050da18(&local_10,&local_d4,piVar4);
      FUN_0050da04(&local_10,&local_d8);
      FUN_0050d9d4(&local_d8,2);
      FUN_0050d9d4(&local_d4,2);
      piVar4 = FUN_004016bc(&local_e0);
      FUN_0050d87c(&local_dc);
      FUN_0050da18(&local_10,&local_dc,piVar4);
      FUN_0050da04(&local_10,&local_e0);
      FUN_0050d9d4(&local_e0,2);
      FUN_0050d9d4(&local_dc,2);
      piVar4 = FUN_004016bc(&local_e8);
      FUN_0050d87c(&local_e4);
      FUN_0050da18(&_tempdir,&local_e4,piVar4);
      FUN_0050da04((int *)&local_14,&local_e8);
      FUN_0050d9d4(&local_e8,2);
      FUN_0050d9d4(&local_e4,2);
      piVar4 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_14,0xffff);
      uVar3 = FUN_00404394(&local_10);
      puVar10 = FUN_00404374(&local_10);
      (**(code **)(*piVar4 + 8))(piVar4,puVar10,uVar3);
      local_f0 = piVar4;
      if (piVar4 != (int *)0x0) {
        local_ec = *piVar4;
        (**(code **)(*piVar4 + -4))(piVar4,3);
      }
    }
    pVVar8 = FUN_004037cc(&local_114);
    FUN_00403810(pVVar8);
    pVVar8 = FUN_004037cc(&local_124);
    FUN_00403810(pVVar8);
    pVVar8 = FUN_004037cc(&local_134);
    FUN_00403810(pVVar8);
    pVVar8 = FUN_004037cc(&local_104);
    FUN_00403810(pVVar8);
    pOVar6 = FUN_0050e2a8(&local_f4);
    FUN_00404d4c(pOVar6);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
    FUN_004038c8(&local_134,2);
    FUN_004038c8(&local_124,2);
    FUN_004038c8(&local_114,2);
    FUN_004038c8(&local_104,2);
    FUN_0050e31c(&local_f4,2);
    FUN_0042f34c(*(int *)(param_1 + 0x364),'\0');
  }
  FUN_0050d9d4((int *)&local_14,2);
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4((int *)&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_158;
  return;
}



// Preserved published name: N13Click
// Entry 00407e0c, recovered name Published_N13Click_00407e0c

void Published_N13Click_00407e0c(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x368) + 0x2c) == '\0') {
    FUN_004020b0(param_1);
    FUN_00497b1c(*(int *)(param_1 + 0x368),*(char *)(*(int *)(param_1 + 0x368) + 0x2c) == '\0');
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),0);
    Published_PageControl1Change_0040513c(param_1);
  }
  return;
}



// Preserved published name: N14Click
// Entry 00407e74, recovered name Published_N14Click_00407e74

void Published_N14Click_00407e74(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x36c) + 0x2c) == '\0') {
    FUN_004020b0(param_1);
    FUN_00497b1c(*(int *)(param_1 + 0x36c),*(char *)(*(int *)(param_1 + 0x36c) + 0x2c) == '\0');
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),1);
    Published_PageControl1Change_0040513c(param_1);
  }
  return;
}



// Preserved published name: N16Click
// Entry 00407edc, recovered name Published_N16Click_00407edc

void Published_N16Click_00407edc(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x370) + 0x2c) == '\0') {
    FUN_004020b0(param_1);
    FUN_00497b1c(*(int *)(param_1 + 0x370),*(char *)(*(int *)(param_1 + 0x370) + 0x2c) == '\0');
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),2);
    Published_PageControl1Change_0040513c(param_1);
  }
  return;
}



// Preserved published name: N18Click
// Entry 00407fb4, recovered name Published_N18Click_00407fb4

void Published_N18Click_00407fb4(int *param_1,undefined4 param_2,int param_3)

{
  FUN_004b8834(param_1,param_2,param_3);
  return;
}



// Preserved published name: N12Click
// Entry 00407fcc, recovered name Published_N12Click_00407fcc

void Published_N12Click_00407fcc(int param_1)

{
  VARIANTARG *pVVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  VARIANTARG local_24;
  VARIANTARG local_14;
  
  FUN_00502f50(0x5118b4);
  pVVar1 = FUN_004037cc(&local_14);
  FUN_00403810(pVVar1);
  pVVar1 = FUN_004037cc(&local_24);
  FUN_00403810(pVVar1);
  _Shdocvw_tlb_TCppWebBrowser_ExecWB_qqr20Shdocvw_tlb_OLECMDID25Shdocvw_tlb_OLECMDEXECOPTp24_TVariantT_10tagVARIANT_t3
            (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
  FUN_004038c8(&local_24,2);
  FUN_004038c8(&local_14,2);
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: N11Click
// Entry 00408068, recovered name Published_N11Click_00408068

void Published_N11Click_00408068(int param_1)

{
  VARIANTARG *pVVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  VARIANTARG local_24;
  VARIANTARG local_14;
  
  FUN_00502f50(0x5118e4);
  pVVar1 = FUN_004037cc(&local_14);
  FUN_00403810(pVVar1);
  pVVar1 = FUN_004037cc(&local_24);
  FUN_00403810(pVVar1);
  _Shdocvw_tlb_TCppWebBrowser_ExecWB_qqr20Shdocvw_tlb_OLECMDID25Shdocvw_tlb_OLECMDEXECOPTp24_TVariantT_10tagVARIANT_t3
            (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
  FUN_004038c8(&local_24,2);
  FUN_004038c8(&local_14,2);
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: sbDIY1Click
// Entry 00408104, recovered name Published_sbDIY1Click_00408104

void Published_sbDIY1Click_00408104(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  VARIANTARG *pVVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar5;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 *in_FS_OFFSET;
  char cVar6;
  undefined4 local_70;
  int local_4c;
  VARIANTARG local_48;
  VARIANTARG local_38;
  VARIANTARG local_28;
  VARIANTARG local_18;
  int local_8;
  
  FUN_00502f50(0x51194c);
  if (*(char *)(*(int *)(param_1 + 0x398) + 0x130) == '\0') {
    FUN_00497b1c(*(int *)(param_1 + 0x3e0),0);
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x304),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x304));
    FUN_004c6b18(*(int **)(param_1 + 0x308),CONCAT31((int3)((uint)extraout_EDX_01 >> 8),1),param_1);
    FUN_004c6b18(*(int **)(param_1 + 0x304),0,param_1);
    (**(code **)(**(int **)(param_1 + 0x308) + 0x5c))(*(int **)(param_1 + 0x308),1);
    (**(code **)(**(int **)(param_1 + 0x304) + 0x5c))(*(int **)(param_1 + 0x304),0);
    (**(code **)(**(int **)(param_1 + 0x31c) + 0x5c))(*(int **)(param_1 + 0x31c),1);
    FUN_004c6b18(*(int **)(param_1 + 0x2f4),CONCAT31((int3)((uint)extraout_EDX_02 >> 8),1),
                 extraout_ECX_00);
    FUN_004c6b18(*(int **)(param_1 + 0x3d0),0,param_1);
  }
  else {
    FUN_00497b1c(*(int *)(param_1 + 0x3e0),1);
    if (*(int *)PTR__nowelenum_005337e4 < 1) {
      FUN_004f1978(*(int **)(param_1 + 0x398),'\0');
      if (*(char *)(*(int *)(param_1 + 0x314) + 0x47) != '\0') {
        FUN_004f1978(*(int **)(param_1 + 0x31c),'\x01');
      }
    }
    else {
      pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x308),0xffffffec);
      (*pcVar1)(*(undefined4 *)(param_1 + 0x308));
      (**(code **)(**(int **)(param_1 + 0x308) + 0x5c))(*(int **)(param_1 + 0x308),0);
      (**(code **)(**(int **)(param_1 + 0x304) + 0x5c))(*(int **)(param_1 + 0x304),0);
      (**(code **)(**(int **)(param_1 + 0x31c) + 0x5c))(*(int **)(param_1 + 0x31c),0);
      FUN_004c6b18(*(int **)(param_1 + 0x2f4),0,extraout_ECX);
      FUN_00431094(*(int *)(param_1 + 0x3d0),*(int *)PTR__nowelenum_005337e4);
      piVar2 = FUN_004050a0(&local_8);
      FUN_00492738(*(int **)(*(int *)(param_1 + 0x3d0) + 0x234),0xcb,piVar2);
      iVar3 = FUN_0040512c(&local_8);
      cVar6 = iVar3 == 0;
      FUN_004050ec(&local_8,2);
      if (cVar6 != '\0') {
        pVVar4 = FUN_004037cc(&local_28);
        FUN_00403810(pVVar4);
        pVVar4 = FUN_004037cc(&local_38);
        FUN_00403810(pVVar4);
        pVVar4 = FUN_004037cc(&local_48);
        FUN_00403810(pVVar4);
        pVVar4 = FUN_004037cc(&local_18);
        FUN_00403810(pVVar4);
        _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
                  (*(int **)(*(int *)(param_1 + 0x3d0) + 0x234));
        FUN_004038c8(&local_48,2);
        FUN_004038c8(&local_38,2);
        FUN_004038c8(&local_28,2);
        FUN_004038c8(&local_18,2);
      }
      piVar2 = FUN_004050a0(&local_4c);
      FUN_00492738(*(int **)(*(int *)(param_1 + 0x3d0) + 0x234),0xcb,piVar2);
      piVar2 = (int *)FUN_0040512c(&local_4c);
      cVar6 = piVar2 != (int *)0x0;
      FUN_004050ec(&local_4c,2);
      uVar5 = extraout_EDX;
      if (cVar6 != '\0') {
        (**(code **)(*piVar2 + 0x4c))();
        (**(code **)(*piVar2 + 0x158))();
        (**(code **)(*piVar2 + 0x154))();
        (**(code **)(*piVar2 + 300))();
        (**(code **)(*piVar2 + 0x15c))();
        uVar5 = extraout_EDX_00;
      }
      FUN_004c6b18(*(int **)(param_1 + 0x3d0),CONCAT31((int3)((uint)uVar5 >> 8),1),param_1);
    }
  }
  *in_FS_OFFSET = local_70;
  return;
}



// Preserved published name: sbDIY2Click
// Entry 004084d0, recovered name Published_sbDIY2Click_004084d0

void Published_sbDIY2Click_004084d0(int param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  int local_c;
  uint *local_8;
  
  FUN_00502f50(0x511998);
  if (*(char *)(*(int *)(param_1 + 0x39c) + 0x130) == '\0') {
    FUN_00497b1c(*(int *)(param_1 + 0x3e4),0);
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 800),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 800));
    FUN_004c6b18(*(int **)(param_1 + 800),0,param_1);
    FUN_004c6b18(*(int **)(param_1 + 0x324),CONCAT31((int3)((uint)extraout_EDX_00 >> 8),1),param_1);
    (**(code **)(**(int **)(param_1 + 0x324) + 0x5c))(*(int **)(param_1 + 0x324),1);
    (**(code **)(**(int **)(param_1 + 800) + 0x5c))(*(int **)(param_1 + 800),1);
    (**(code **)(**(int **)(param_1 + 0x330) + 0x5c))(*(int **)(param_1 + 0x330),1);
    FUN_004c6b18(*(int **)(param_1 + 0x2f4),CONCAT31((int3)((uint)extraout_EDX_01 >> 8),1),
                 extraout_ECX_00);
    FUN_004c6b18(*(int **)(param_1 + 0x3d0),0,param_1);
    FUN_004c6b18(*(int **)(param_1 + 0x3d4),0,param_1);
  }
  else {
    FUN_00497b1c(*(int *)(param_1 + 0x3e4),1);
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x324),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x324));
    (**(code **)(**(int **)(param_1 + 0x324) + 0x5c))(*(int **)(param_1 + 0x324),0);
    (**(code **)(**(int **)(param_1 + 800) + 0x5c))(*(int **)(param_1 + 800),0);
    (**(code **)(**(int **)(param_1 + 0x330) + 0x5c))(*(int **)(param_1 + 0x330),0);
    FUN_004c6b18(*(int **)(param_1 + 0x2f4),0,extraout_ECX);
    FUN_004c6b18(*(int **)(param_1 + 0x3d0),0,param_1);
    FUN_004c6b18(*(int **)(param_1 + 0x3d4),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
    FUN_00436564(*(int *)(param_1 + 0x3d4));
    piVar2 = FUN_004016bc(&local_8);
    FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x334) + 0x214),piVar2);
    FUN_004c6c30(*(int *)(*(int *)(param_1 + 0x3d4) + 0x22c),local_8);
    FUN_0050d9d4((int *)&local_8,2);
    piVar2 = FUN_0050d87c(&local_c);
    FUN_00436240(*(int *)(param_1 + 0x3d4),*piVar2);
    FUN_0050d9d4(&local_c,2);
    FUN_0043662c(*(int *)(param_1 + 0x3d4));
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: PageControl1Changing
// Entry 004086f4, recovered name Published_PageControl1Changing_004086f4

void Published_PageControl1Changing_004086f4(int param_1)

{
  FUN_004020b0(param_1);
  return;
}



// Preserved published name: ChemicalSort1ListBox1Click
// Entry 00408710, recovered name Published_ChemicalSort1ListBox1Click_00408710

void Published_ChemicalSort1ListBox1Click_00408710(int param_1)

{
  VARIANTARG *pVVar1;
  int *piVar2;
  BSTR pOVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_74;
  VARIANTARG local_50;
  VARIANTARG local_40;
  VARIANTARG local_30;
  VARIANTARG local_20;
  OLECHAR local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x511a10);
  Published_ListBox1Click_0042cd84(*(int *)(param_1 + 0x334));
  if (*(char *)(*(int *)(param_1 + 0x334) + 0x224) != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0x334) + 0x224) = 0;
    pVVar1 = FUN_004037cc(&local_30);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_40);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_50);
    FUN_00403810(pVVar1);
    piVar2 = FUN_004016bc(&local_c);
    FUN_0050d87c(&local_8);
    FUN_0050da18(&_tempdir,&local_8,piVar2);
    pOVar3 = FUN_0050e2a8(&local_10);
    FUN_00404d4c(pOVar3);
    pVVar1 = FUN_004037cc(&local_20);
    FUN_00403810(pVVar1);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
    FUN_004038c8(&local_50,2);
    FUN_004038c8(&local_40,2);
    FUN_004038c8(&local_30,2);
    FUN_004038c8(&local_20,2);
    FUN_0050e31c(&local_10,2);
    FUN_0050d9d4(&local_c,2);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_74;
  return;
}



// Preserved published name: conceptsort1ListBox1Click
// Entry 004088a0, recovered name Published_conceptsort1ListBox1Click_004088a0

void Published_conceptsort1ListBox1Click_004088a0(int param_1)

{
  VARIANTARG *pVVar1;
  int *piVar2;
  BSTR pOVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_74;
  VARIANTARG local_50;
  VARIANTARG local_40;
  VARIANTARG local_30;
  VARIANTARG local_20;
  OLECHAR local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x511a7c);
  Published_ListBox1Click_00438ad4(*(int *)(param_1 + 0x3d8));
  if (*(char *)(*(int *)(param_1 + 0x3d8) + 0x224) != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0x3d8) + 0x224) = 0;
    pVVar1 = FUN_004037cc(&local_30);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_40);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_50);
    FUN_00403810(pVVar1);
    piVar2 = FUN_004016bc(&local_c);
    FUN_0050d87c(&local_8);
    FUN_0050da18(&_tempdir,&local_8,piVar2);
    pOVar3 = FUN_0050e2a8(&local_10);
    FUN_00404d4c(pOVar3);
    pVVar1 = FUN_004037cc(&local_20);
    FUN_00403810(pVVar1);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
    FUN_004038c8(&local_50,2);
    FUN_004038c8(&local_40,2);
    FUN_004038c8(&local_30,2);
    FUN_004038c8(&local_20,2);
    FUN_0050e31c(&local_10,2);
    FUN_0050d9d4(&local_c,2);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_74;
  return;
}



// Preserved published name: lookupChemicals1Button1Click
// Entry 00408a30, recovered name Published_lookupChemicals1Button1Click_00408a30

void Published_lookupChemicals1Button1Click_00408a30(int param_1)

{
  Published_Button1Click_0042f0ec(*(int *)(param_1 + 0x364));
  return;
}



// Preserved published name: SpeedButton20Click
// Entry 00408a54, recovered name Published_SpeedButton20Click_00408a54

void Published_SpeedButton20Click_00408a54(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x511ab0);
  if (*(char *)(*(int *)(param_1 + 0x360) + 0x130) == '\0') {
    piVar1 = FUN_0050d87c(&local_c);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_c,2);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  else {
    piVar1 = FUN_0050d87c(&local_8);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_8,2);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: lookupConcepts1ListBox1Click
// Entry 00408b20, recovered name Published_lookupConcepts1ListBox1Click_00408b20

void Published_lookupConcepts1ListBox1Click_00408b20(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  BSTR pOVar6;
  int iVar7;
  VARIANTARG *pVVar8;
  int *piVar9;
  undefined *puVar10;
  undefined4 *in_FS_OFFSET;
  LPCWSTR pWVar11;
  undefined4 local_11c;
  VARIANTARG local_f8;
  VARIANTARG local_e8;
  VARIANTARG local_d8;
  VARIANTARG local_c8;
  OLECHAR local_b8;
  int local_b4;
  int local_b0;
  int *local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined *local_44;
  int local_40;
  int local_3c;
  int local_38;
  VARIANTARG local_34;
  OLECHAR local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  int local_10;
  undefined *local_c;
  int local_8;
  
  FUN_00502f50(0x511d90);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_004016bc(&local_10);
  FUN_004016bc(&local_14);
  cVar1 = FUN_0043d348(*(int *)(param_1 + 0x3dc));
  if (cVar1 == '\0') {
    FUN_0043d35c(*(int *)(param_1 + 0x3dc),'\x01');
    iVar7 = *(int *)(*(int *)(param_1 + 0x3dc) + 0x22c);
    puVar2 = FUN_004016bc(&local_18);
    uVar3 = FUN_0048fcc0(*(int **)(*(int *)(param_1 + 0x3dc) + 0x22c));
    piVar4 = *(int **)(iVar7 + 0x1f0);
    (**(code **)(*piVar4 + 0xc))(piVar4,uVar3,puVar2);
    FUN_0050da04((int *)&local_c,&local_18);
    FUN_0050d9d4(&local_18,2);
    piVar4 = FUN_004016bc(&local_1c);
    FUN_0043d388(*(undefined4 *)(param_1 + 0x3dc),local_c,piVar4);
    FUN_0050da04(&local_8,&local_1c);
    FUN_0050d9d4(&local_1c,2);
    FUN_0047a9e4(*(int **)(*(int *)(param_1 + 0x3dc) + 0x230));
    piVar4 = (int *)FUN_0045cef8(*(int *)(*(int *)(param_1 + 0x3dc) + 0x230));
    (**(code **)(*piVar4 + 0x40))();
    piVar4 = (int *)FUN_0045cef8(*(int *)(*(int *)(param_1 + 0x3dc) + 0x230));
    piVar5 = FUN_0050d87c(&local_20);
    (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
    FUN_0050d9d4(&local_20,2);
    pOVar6 = FUN_0050e234(&local_24);
    pWVar11 = (LPCWSTR)*pOVar6;
    iVar7 = FUN_0045b63c(*(int *)(*(int *)(param_1 + 0x3dc) + 0x230));
    iVar7 = FUN_00453fcc(iVar7,pWVar11);
    pVVar8 = FUN_0050df38(&local_34,&local_8);
    FUN_00455258(iVar7,pVVar8);
    FUN_0050e004(&local_34,2);
    FUN_0050e31c(&local_24,2);
    FUN_0047a9d8(*(int **)(*(int *)(param_1 + 0x3dc) + 0x230));
    iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0x3dc) + 0x230) + 0x14c))();
    if (0 < iVar7) {
      FUN_0047c964(*(int **)(*(int *)(param_1 + 0x3dc) + 0x230));
      FUN_0050d87c(&local_38);
      FUN_0050da04(&local_10,&local_38);
      FUN_0050d9d4(&local_38,2);
      piVar4 = FUN_004016bc(&local_44);
      FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar4);
      piVar4 = FUN_004016bc(&local_48);
      FUN_004f6cdc(local_44,piVar4);
      piVar4 = &local_48;
      piVar5 = FUN_004016bc(&local_40);
      FUN_0050d87c(&local_3c);
      FUN_0050da18(&local_10,&local_3c,piVar5);
      piVar5 = &local_40;
      piVar9 = FUN_004016bc(&local_4c);
      FUN_0050da18(piVar5,piVar4,piVar9);
      piVar4 = &local_4c;
      piVar5 = FUN_004016bc(&local_54);
      FUN_0050d87c(&local_50);
      FUN_0050da18(piVar4,&local_50,piVar5);
      FUN_0050da04(&local_10,&local_54);
      FUN_0050d9d4(&local_54,2);
      FUN_0050d9d4(&local_50,2);
      FUN_0050d9d4(&local_4c,2);
      FUN_0050d9d4(&local_48,2);
      FUN_0050d9d4((int *)&local_44,2);
      FUN_0050d9d4(&local_40,2);
      FUN_0050d9d4(&local_3c,2);
      piVar4 = FUN_004016bc(&local_5c);
      FUN_0050d87c(&local_58);
      FUN_0050da18(&local_10,&local_58,piVar4);
      FUN_0050da04(&local_10,&local_5c);
      FUN_0050d9d4(&local_5c,2);
      FUN_0050d9d4(&local_58,2);
      piVar4 = FUN_004016bc(&local_64);
      FUN_0050d87c(&local_60);
      FUN_0050da18(&local_10,&local_60,piVar4);
      piVar4 = &local_64;
      piVar5 = FUN_004016bc(&local_68);
      FUN_0050da18(piVar4,&local_8,piVar5);
      FUN_0050da04(&local_10,&local_68);
      FUN_0050d9d4(&local_68,2);
      FUN_0050d9d4(&local_64,2);
      FUN_0050d9d4(&local_60,2);
      piVar4 = FUN_004016bc(&local_70);
      FUN_0050d87c(&local_6c);
      FUN_0050da18(&local_10,&local_6c,piVar4);
      FUN_0050da04(&local_10,&local_70);
      FUN_0050d9d4(&local_70,2);
      FUN_0050d9d4(&local_6c,2);
      piVar4 = FUN_0050d87c(&local_7c);
      piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x3dc) + 0x230),(undefined *)*piVar4)
      ;
      puVar2 = FUN_004016bc(&local_80);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
      piVar4 = &local_80;
      piVar5 = FUN_004016bc(&local_78);
      FUN_0050d87c(&local_74);
      FUN_0050da18(&local_10,&local_74,piVar5);
      piVar5 = &local_78;
      piVar9 = FUN_004016bc(&local_84);
      FUN_0050da18(piVar5,piVar4,piVar9);
      FUN_0050da04(&local_10,&local_84);
      FUN_0050d9d4(&local_84,2);
      FUN_0050d9d4(&local_80,2);
      FUN_0050d9d4(&local_7c,2);
      FUN_0050d9d4(&local_78,2);
      FUN_0050d9d4(&local_74,2);
      piVar4 = FUN_004016bc(&local_8c);
      FUN_0050d87c(&local_88);
      FUN_0050da18(&local_10,&local_88,piVar4);
      FUN_0050da04(&local_10,&local_8c);
      FUN_0050d9d4(&local_8c,2);
      FUN_0050d9d4(&local_88,2);
      piVar4 = FUN_004016bc(&local_94);
      FUN_0050d87c(&local_90);
      FUN_0050da18(&local_10,&local_90,piVar4);
      FUN_0050da04(&local_10,&local_94);
      FUN_0050d9d4(&local_94,2);
      FUN_0050d9d4(&local_90,2);
      piVar4 = FUN_004016bc(&local_9c);
      FUN_0050d87c(&local_98);
      FUN_0050da18(&local_10,&local_98,piVar4);
      FUN_0050da04(&local_10,&local_9c);
      FUN_0050d9d4(&local_9c,2);
      FUN_0050d9d4(&local_98,2);
      piVar4 = FUN_004016bc(&local_a4);
      FUN_0050d87c(&local_a0);
      FUN_0050da18(&_tempdir,&local_a0,piVar4);
      FUN_0050da04((int *)&local_14,&local_a4);
      FUN_0050d9d4(&local_a4,2);
      FUN_0050d9d4(&local_a0,2);
      piVar4 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_14,0xffff);
      uVar3 = FUN_00404394(&local_10);
      puVar10 = FUN_00404374(&local_10);
      (**(code **)(*piVar4 + 8))(piVar4,puVar10,uVar3);
      local_ac = piVar4;
      if (piVar4 != (int *)0x0) {
        local_a8 = *piVar4;
        (**(code **)(*piVar4 + -4))(piVar4,3);
      }
    }
    pVVar8 = FUN_004037cc(&local_d8);
    FUN_00403810(pVVar8);
    pVVar8 = FUN_004037cc(&local_e8);
    FUN_00403810(pVVar8);
    pVVar8 = FUN_004037cc(&local_f8);
    FUN_00403810(pVVar8);
    piVar4 = FUN_004016bc(&local_b4);
    FUN_0050d87c(&local_b0);
    FUN_0050da18(&_tempdir,&local_b0,piVar4);
    pOVar6 = FUN_0050e2a8(&local_b8);
    FUN_00404d4c(pOVar6);
    pVVar8 = FUN_004037cc(&local_c8);
    FUN_00403810(pVVar8);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
    FUN_004038c8(&local_f8,2);
    FUN_004038c8(&local_e8,2);
    FUN_004038c8(&local_d8,2);
    FUN_004038c8(&local_c8,2);
    FUN_0050e31c(&local_b8,2);
    FUN_0050d9d4(&local_b4,2);
    FUN_0050d9d4(&local_b0,2);
    FUN_0043d35c(*(int *)(param_1 + 0x3dc),'\0');
  }
  FUN_0050d9d4((int *)&local_14,2);
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4((int *)&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_11c;
  return;
}



// Preserved published name: Ndm1Click
// Entry 004096b4, recovered name Published_Ndm1Click_004096b4

void Published_Ndm1Click_004096b4(int param_1)

{
  code *pcVar1;
  
  FUN_00497b1c(*(int *)(param_1 + 0x3e0),*(char *)(*(int *)(param_1 + 0x3e0) + 0x2c) == '\0');
  if (*(char *)(*(int *)(param_1 + 0x3e0) + 0x2c) == '\0') {
    FUN_004f1978(*(int **)(param_1 + 0x398),'\0');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x398),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x398));
  }
  else {
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),0);
    Published_PageControl1Change_0040513c(param_1);
    FUN_004f1978(*(int **)(param_1 + 0x398),'\x01');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x398),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x398));
    if (*(char *)(*(int *)(param_1 + 0x398) + 0x130) == '\0') {
      FUN_00497b1c(*(int *)(param_1 + 0x3e0),0);
    }
  }
  return;
}



// Preserved published name: Ndm2Click
// Entry 00409798, recovered name Published_Ndm2Click_00409798

void Published_Ndm2Click_00409798(int param_1)

{
  code *pcVar1;
  
  FUN_00497b1c(*(int *)(param_1 + 0x3e4),*(char *)(*(int *)(param_1 + 0x3e4) + 0x2c) == '\0');
  if (*(char *)(*(int *)(param_1 + 0x3e4) + 0x2c) == '\0') {
    FUN_004f1978(*(int **)(param_1 + 0x39c),'\0');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x39c),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x39c));
  }
  else {
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),1);
    Published_PageControl1Change_0040513c(param_1);
    FUN_004f1978(*(int **)(param_1 + 0x39c),'\x01');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x39c),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x39c));
    if (*(char *)(*(int *)(param_1 + 0x39c) + 0x130) == '\0') {
      FUN_00497b1c(*(int *)(param_1 + 0x3e4),0);
    }
  }
  return;
}



// Preserved published name: SpeedButton17Click
// Entry 00409880, recovered name Published_SpeedButton17Click_00409880

void Published_SpeedButton17Click_00409880(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  FUN_004c6b18(*(int **)(param_1 + 0x350),CONCAT31((int3)((uint)param_2 >> 8),1),param_3);
  iVar1 = **(int **)(param_1 + 0x350);
  (**(code **)(iVar1 + 0x5c))(*(int **)(param_1 + 0x350),1,iVar1,param_2);
  FUN_004c6b18(*(int **)(param_1 + 0x354),0,extraout_ECX);
  FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
  return;
}



// Preserved published name: SpeedButton16Click
// Entry 004098d4, recovered name Published_SpeedButton16Click_004098d4

void Published_SpeedButton16Click_004098d4(int param_1)

{
  int *piVar1;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 local_34;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x511edc);
  FUN_004c6b18(*(int **)(param_1 + 0x350),0,param_1);
  FUN_004c6b18(*(int **)(param_1 + 0x354),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
  FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  if (*(char *)(*(int *)(param_1 + 0x360) + 0x130) == '\0') {
    if (*(char *)(*(int *)(param_1 + 0x3a0) + 0x130) == '\0') {
      piVar1 = FUN_0050d87c(&local_10);
      FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
      FUN_0050d9d4(&local_10,2);
    }
    else {
      piVar1 = FUN_0050d87c(&local_c);
      FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
      FUN_0050d9d4(&local_c,2);
    }
  }
  else {
    piVar1 = FUN_0050d87c(&local_8);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_34;
  return;
}



// Preserved published name: sbDIY3Click
// Entry 004099f8, recovered name Published_sbDIY3Click_004099f8

void Published_sbDIY3Click_004099f8(int param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_3c;
  int local_18;
  int local_14;
  int local_10;
  uint *local_c;
  int local_8;
  
  FUN_00502f50(0x511f58);
  if (*(char *)(*(int *)(param_1 + 0x3a0) + 0x130) == '\0') {
    FUN_00497b1c(*(int *)(param_1 + 0x3f0),0);
    (**(code **)(**(int **)(param_1 + 0x350) + 0x5c))(*(int **)(param_1 + 0x350),1);
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x350),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x350));
    (**(code **)(**(int **)(param_1 + 0x360) + 0x5c))(*(int **)(param_1 + 0x360),1);
    piVar2 = FUN_0050d87c(&local_14);
    FUN_00401ff0(param_1,DAT_00533e5c,*piVar2);
    FUN_0050d9d4(&local_14,2);
    piVar2 = FUN_0050d87c(&local_18);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar2);
    FUN_0050d9d4(&local_18,2);
  }
  else {
    FUN_00497b1c(*(int *)(param_1 + 0x3f0),1);
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x354),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x354));
    (**(code **)(**(int **)(param_1 + 0x350) + 0x5c))(*(int **)(param_1 + 0x350),0);
    (**(code **)(**(int **)(param_1 + 0x360) + 0x5c))(*(int **)(param_1 + 0x360),0);
    piVar2 = FUN_0050d87c(&local_8);
    FUN_00401ff0(param_1,DAT_00533e5c,*piVar2);
    FUN_0050d9d4(&local_8,2);
    FUN_0043d5e4(*(int *)(param_1 + 0x3ec));
    piVar2 = FUN_004016bc(&local_c);
    FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x3d8) + 0x214),piVar2);
    FUN_004c6c30(*(int *)(*(int *)(param_1 + 0x3ec) + 0x214),local_c);
    FUN_0050d9d4((int *)&local_c,2);
    piVar2 = FUN_0050d87c(&local_10);
    FUN_0043d600(*(int *)(param_1 + 0x3ec),*piVar2);
    FUN_0050d9d4(&local_10,2);
    FUN_0043d8b8(*(int *)(param_1 + 0x3ec));
  }
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: Ndm3Click
// Entry 00409c20, recovered name Published_Ndm3Click_00409c20

void Published_Ndm3Click_00409c20(int param_1)

{
  code *pcVar1;
  
  FUN_00497b1c(*(int *)(param_1 + 0x3f0),*(char *)(*(int *)(param_1 + 0x3f0) + 0x2c) == '\0');
  if (*(char *)(*(int *)(param_1 + 0x3f0) + 0x2c) == '\0') {
    FUN_004f1978(*(int **)(param_1 + 0x3a0),'\0');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x3a0),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x3a0));
  }
  else {
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),2);
    Published_PageControl1Change_0040513c(param_1);
    FUN_004f1978(*(int **)(param_1 + 0x3a0),'\x01');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x3a0),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x3a0));
    if (*(char *)(*(int *)(param_1 + 0x3a0) + 0x130) == '\0') {
      FUN_00497b1c(*(int *)(param_1 + 0x3f0),0);
    }
  }
  return;
}



// Preserved published name: N8Click
// Entry 00409d08, recovered name Published_N8Click_00409d08

void __stdcall Published_N8Click_00409d08(void)

{
  ShellExecuteA(*(HWND *)(*(int *)PTR_DAT_00533970 + 0x24),&DAT_0050ff97,
                s_http___www_eedduu_com_0050ff9c,(LPCSTR)0x0,(LPCSTR)0x0,5);
  return;
}



// Preserved published name: N15Click
// Entry 00409d38, recovered name Published_N15Click_00409d38

void __stdcall Published_N15Click_00409d38(void)

{
  ShellExecuteA(*(HWND *)(*(int *)PTR_DAT_00533970 + 0x24),&DAT_0050ffb2,
                s_mailto_chem_jhksoft_com_0050ffb7,(LPCSTR)0x0,(LPCSTR)0x0,5);
  return;
}



// Preserved published name: ClientSocket1Connect
// Entry 00409d68, recovered name Published_ClientSocket1Connect_00409d68

void __stdcall Published_ClientSocket1Connect_00409d68(void)

{
  return;
}



// Preserved published name: ClientSocket1Error
// Entry 00409d88, recovered name Published_ClientSocket1Error_00409d88

void __stdcall Published_ClientSocket1Error_00409d88(void)

{
  return;
}



// Preserved published name: ClientSocket1Read
// Entry 00409db0, recovered name Published_ClientSocket1Read_00409db0

void __stdcall Published_ClientSocket1Read_00409db0(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  
  FUN_00502f50(0x511fbc);
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: Ndm4Click
// Entry 00409eb4, recovered name Published_Ndm4Click_00409eb4

void Published_Ndm4Click_00409eb4(int param_1)

{
  code *pcVar1;
  
  FUN_00497b1c(*(int *)(param_1 + 0x424),*(char *)(*(int *)(param_1 + 0x424) + 0x2c) == '\0');
  if (*(char *)(*(int *)(param_1 + 0x424) + 0x2c) == '\0') {
    FUN_004f1978(*(int **)(param_1 + 0x41c),'\0');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x41c),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x41c));
  }
  else {
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),3);
    Published_PageControl1Change_0040513c(param_1);
    FUN_004f1978(*(int **)(param_1 + 0x41c),'\x01');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x41c),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x41c));
    if (*(char *)(*(int *)(param_1 + 0x41c) + 0x130) == '\0') {
      FUN_00497b1c(*(int *)(param_1 + 0x424),0);
    }
  }
  return;
}



// Preserved published name: N17Click
// Entry 00409f9c, recovered name Published_N17Click_00409f9c

void Published_N17Click_00409f9c(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x420) + 0x2c) == '\0') {
    FUN_004020b0(param_1);
    FUN_00497b1c(*(int *)(param_1 + 0x420),*(char *)(*(int *)(param_1 + 0x420) + 0x2c) == '\0');
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),3);
    Published_PageControl1Change_0040513c(param_1);
  }
  return;
}



// Preserved published name: SpeedButton15Click
// Entry 0040a004, recovered name Published_SpeedButton15Click_0040a004

void Published_SpeedButton15Click_0040a004(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x511ffc);
  if (*(char *)(*(int *)(param_1 + 0x418) + 0x130) == '\0') {
    piVar1 = FUN_0050d87c(&local_c);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_c,2);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  else {
    piVar1 = FUN_0050d87c(&local_8);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_8,2);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: chemicsort1ListBox1Click
// Entry 0040a0d0, recovered name Published_chemicsort1ListBox1Click_0040a0d0

void Published_chemicsort1ListBox1Click_0040a0d0(int param_1)

{
  VARIANTARG *pVVar1;
  int *piVar2;
  BSTR pOVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_74;
  VARIANTARG local_50;
  VARIANTARG local_40;
  VARIANTARG local_30;
  VARIANTARG local_20;
  OLECHAR local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x512074);
  Published_ListBox1Click_0043ad6c(*(int *)(param_1 + 0x428));
  if (*(char *)(*(int *)(param_1 + 0x428) + 0x224) != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0x428) + 0x224) = 0;
    pVVar1 = FUN_004037cc(&local_30);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_40);
    FUN_00403810(pVVar1);
    pVVar1 = FUN_004037cc(&local_50);
    FUN_00403810(pVVar1);
    piVar2 = FUN_004016bc(&local_c);
    FUN_0050d87c(&local_8);
    FUN_0050da18(&_tempdir,&local_8,piVar2);
    pOVar3 = FUN_0050e2a8(&local_10);
    FUN_00404d4c(pOVar3);
    pVVar1 = FUN_004037cc(&local_20);
    FUN_00403810(pVVar1);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
    FUN_004038c8(&local_50,2);
    FUN_004038c8(&local_40,2);
    FUN_004038c8(&local_30,2);
    FUN_004038c8(&local_20,2);
    FUN_0050e31c(&local_10,2);
    FUN_0050d9d4(&local_c,2);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_74;
  return;
}



// Preserved published name: lookupchemics1ListBox1Click
// Entry 0040a260, recovered name Published_lookupchemics1ListBox1Click_0040a260

void Published_lookupchemics1ListBox1Click_0040a260(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  BSTR pOVar6;
  int iVar7;
  VARIANTARG *pVVar8;
  int *piVar9;
  undefined *puVar10;
  undefined4 *in_FS_OFFSET;
  LPCWSTR pWVar11;
  undefined4 local_158;
  VARIANTARG local_134;
  VARIANTARG local_124;
  VARIANTARG local_114;
  VARIANTARG local_104;
  OLECHAR local_f4;
  int *local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined *local_44;
  int local_40;
  int local_3c;
  int local_38;
  VARIANTARG local_34;
  OLECHAR local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  int local_10;
  undefined *local_c;
  int local_8;
  
  FUN_00502f50(0x51240c);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_004016bc(&local_10);
  FUN_004016bc(&local_14);
  cVar1 = FUN_0043fff0(*(int *)(param_1 + 0x42c));
  if (cVar1 == '\0') {
    FUN_00440004(*(int *)(param_1 + 0x42c),'\x01');
    iVar7 = *(int *)(*(int *)(param_1 + 0x42c) + 0x22c);
    puVar2 = FUN_004016bc(&local_18);
    uVar3 = FUN_0048fcc0(*(int **)(*(int *)(param_1 + 0x42c) + 0x22c));
    piVar4 = *(int **)(iVar7 + 0x1f0);
    (**(code **)(*piVar4 + 0xc))(piVar4,uVar3,puVar2);
    FUN_0050da04((int *)&local_c,&local_18);
    FUN_0050d9d4(&local_18,2);
    piVar4 = FUN_004016bc(&local_1c);
    FUN_00440030(*(undefined4 *)(param_1 + 0x42c),local_c,piVar4);
    FUN_0050da04(&local_8,&local_1c);
    FUN_0050d9d4(&local_1c,2);
    FUN_0047a9e4(*(int **)(*(int *)(param_1 + 0x42c) + 0x230));
    piVar4 = (int *)FUN_0045cef8(*(int *)(*(int *)(param_1 + 0x42c) + 0x230));
    (**(code **)(*piVar4 + 0x40))();
    piVar4 = (int *)FUN_0045cef8(*(int *)(*(int *)(param_1 + 0x42c) + 0x230));
    piVar5 = FUN_0050d87c(&local_20);
    (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
    FUN_0050d9d4(&local_20,2);
    pOVar6 = FUN_0050e234(&local_24);
    pWVar11 = (LPCWSTR)*pOVar6;
    iVar7 = FUN_0045b63c(*(int *)(*(int *)(param_1 + 0x42c) + 0x230));
    iVar7 = FUN_00453fcc(iVar7,pWVar11);
    pVVar8 = FUN_0050df38(&local_34,&local_8);
    FUN_00455258(iVar7,pVVar8);
    FUN_0050e004(&local_34,2);
    FUN_0050e31c(&local_24,2);
    FUN_0047a9d8(*(int **)(*(int *)(param_1 + 0x42c) + 0x230));
    iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0x42c) + 0x230) + 0x14c))();
    if (0 < iVar7) {
      FUN_0047c964(*(int **)(*(int *)(param_1 + 0x42c) + 0x230));
      FUN_0050d87c(&local_38);
      FUN_0050da04(&local_10,&local_38);
      FUN_0050d9d4(&local_38,2);
      piVar4 = FUN_004016bc(&local_44);
      FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar4);
      piVar4 = FUN_004016bc(&local_48);
      FUN_004f6cdc(local_44,piVar4);
      piVar4 = &local_48;
      piVar5 = FUN_004016bc(&local_40);
      FUN_0050d87c(&local_3c);
      FUN_0050da18(&local_10,&local_3c,piVar5);
      piVar5 = &local_40;
      piVar9 = FUN_004016bc(&local_4c);
      FUN_0050da18(piVar5,piVar4,piVar9);
      piVar4 = &local_4c;
      piVar5 = FUN_004016bc(&local_54);
      FUN_0050d87c(&local_50);
      FUN_0050da18(piVar4,&local_50,piVar5);
      FUN_0050da04(&local_10,&local_54);
      FUN_0050d9d4(&local_54,2);
      FUN_0050d9d4(&local_50,2);
      FUN_0050d9d4(&local_4c,2);
      FUN_0050d9d4(&local_48,2);
      FUN_0050d9d4((int *)&local_44,2);
      FUN_0050d9d4(&local_40,2);
      FUN_0050d9d4(&local_3c,2);
      piVar4 = FUN_004016bc(&local_5c);
      FUN_0050d87c(&local_58);
      FUN_0050da18(&local_10,&local_58,piVar4);
      FUN_0050da04(&local_10,&local_5c);
      FUN_0050d9d4(&local_5c,2);
      FUN_0050d9d4(&local_58,2);
      piVar4 = FUN_004016bc(&local_64);
      FUN_0050d87c(&local_60);
      FUN_0050da18(&local_10,&local_60,piVar4);
      piVar4 = &local_64;
      piVar5 = FUN_004016bc(&local_68);
      FUN_0050da18(piVar4,&local_8,piVar5);
      FUN_0050da04(&local_10,&local_68);
      FUN_0050d9d4(&local_68,2);
      FUN_0050d9d4(&local_64,2);
      FUN_0050d9d4(&local_60,2);
      piVar4 = FUN_0050d87c(&local_6c);
      piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x42c) + 0x230),(undefined *)*piVar4)
      ;
      puVar2 = FUN_004016bc(&local_70);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
      piVar4 = &local_70;
      FUN_0050d87c(&local_74);
      cVar1 = FUN_0050dabc(piVar4,&local_74);
      FUN_0050d9d4(&local_74,2);
      FUN_0050d9d4(&local_70,2);
      FUN_0050d9d4(&local_6c,2);
      if (cVar1 != '\0') {
        piVar4 = FUN_0050d87c(&local_80);
        piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x42c) + 0x230),
                                     (undefined *)*piVar4);
        puVar2 = FUN_004016bc(&local_84);
        (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
        piVar4 = &local_84;
        piVar5 = FUN_004016bc(&local_7c);
        FUN_0050d87c(&local_78);
        FUN_0050da18(&local_10,&local_78,piVar5);
        piVar5 = &local_7c;
        piVar9 = FUN_004016bc(&local_88);
        FUN_0050da18(piVar5,piVar4,piVar9);
        piVar4 = &local_88;
        piVar5 = FUN_004016bc(&local_90);
        FUN_0050d87c(&local_8c);
        FUN_0050da18(piVar4,&local_8c,piVar5);
        FUN_0050da04(&local_10,&local_90);
        FUN_0050d9d4(&local_90,2);
        FUN_0050d9d4(&local_8c,2);
        FUN_0050d9d4(&local_88,2);
        FUN_0050d9d4(&local_84,2);
        FUN_0050d9d4(&local_80,2);
        FUN_0050d9d4(&local_7c,2);
        FUN_0050d9d4(&local_78,2);
      }
      piVar4 = FUN_004016bc(&local_98);
      FUN_0050d87c(&local_94);
      FUN_0050da18(&local_10,&local_94,piVar4);
      FUN_0050da04(&local_10,&local_98);
      FUN_0050d9d4(&local_98,2);
      FUN_0050d9d4(&local_94,2);
      piVar4 = FUN_0050d87c(&local_a4);
      piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x42c) + 0x230),(undefined *)*piVar4)
      ;
      puVar2 = FUN_004016bc(&local_a8);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
      piVar4 = &local_a8;
      piVar5 = FUN_004016bc(&local_a0);
      FUN_0050d87c(&local_9c);
      FUN_0050da18(&local_10,&local_9c,piVar5);
      piVar5 = &local_a0;
      piVar9 = FUN_004016bc(&local_ac);
      FUN_0050da18(piVar5,piVar4,piVar9);
      FUN_0050da04(&local_10,&local_ac);
      FUN_0050d9d4(&local_ac,2);
      FUN_0050d9d4(&local_a8,2);
      FUN_0050d9d4(&local_a4,2);
      FUN_0050d9d4(&local_a0,2);
      FUN_0050d9d4(&local_9c,2);
      piVar4 = FUN_004016bc(&local_b4);
      FUN_0050d87c(&local_b0);
      FUN_0050da18(&local_10,&local_b0,piVar4);
      FUN_0050da04(&local_10,&local_b4);
      FUN_0050d9d4(&local_b4,2);
      FUN_0050d9d4(&local_b0,2);
      piVar4 = FUN_0050d87c(&local_c0);
      piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)(param_1 + 0x42c) + 0x230),(undefined *)*piVar4)
      ;
      puVar2 = FUN_004016bc(&local_c4);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar2);
      piVar4 = &local_c4;
      piVar5 = FUN_004016bc(&local_bc);
      FUN_0050d87c(&local_b8);
      FUN_0050da18(&local_10,&local_b8,piVar5);
      piVar5 = &local_bc;
      piVar9 = FUN_004016bc(&local_c8);
      FUN_0050da18(piVar5,piVar4,piVar9);
      FUN_0050da04(&local_10,&local_c8);
      FUN_0050d9d4(&local_c8,2);
      FUN_0050d9d4(&local_c4,2);
      FUN_0050d9d4(&local_c0,2);
      FUN_0050d9d4(&local_bc,2);
      FUN_0050d9d4(&local_b8,2);
      piVar4 = FUN_004016bc(&local_d0);
      FUN_0050d87c(&local_cc);
      FUN_0050da18(&local_10,&local_cc,piVar4);
      FUN_0050da04(&local_10,&local_d0);
      FUN_0050d9d4(&local_d0,2);
      FUN_0050d9d4(&local_cc,2);
      piVar4 = FUN_004016bc(&local_d8);
      FUN_0050d87c(&local_d4);
      FUN_0050da18(&local_10,&local_d4,piVar4);
      FUN_0050da04(&local_10,&local_d8);
      FUN_0050d9d4(&local_d8,2);
      FUN_0050d9d4(&local_d4,2);
      piVar4 = FUN_004016bc(&local_e0);
      FUN_0050d87c(&local_dc);
      FUN_0050da18(&local_10,&local_dc,piVar4);
      FUN_0050da04(&local_10,&local_e0);
      FUN_0050d9d4(&local_e0,2);
      FUN_0050d9d4(&local_dc,2);
      piVar4 = FUN_004016bc(&local_e8);
      FUN_0050d87c(&local_e4);
      FUN_0050da18(&_tempdir,&local_e4,piVar4);
      FUN_0050da04((int *)&local_14,&local_e8);
      FUN_0050d9d4(&local_e8,2);
      FUN_0050d9d4(&local_e4,2);
      piVar4 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_14,0xffff);
      uVar3 = FUN_00404394(&local_10);
      puVar10 = FUN_00404374(&local_10);
      (**(code **)(*piVar4 + 8))(piVar4,puVar10,uVar3);
      local_f0 = piVar4;
      if (piVar4 != (int *)0x0) {
        local_ec = *piVar4;
        (**(code **)(*piVar4 + -4))(piVar4,3);
      }
    }
    pVVar8 = FUN_004037cc(&local_114);
    FUN_00403810(pVVar8);
    pVVar8 = FUN_004037cc(&local_124);
    FUN_00403810(pVVar8);
    pVVar8 = FUN_004037cc(&local_134);
    FUN_00403810(pVVar8);
    pVVar8 = FUN_004037cc(&local_104);
    FUN_00403810(pVVar8);
    pOVar6 = FUN_0050e2a8(&local_f4);
    FUN_00404d4c(pOVar6);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
    FUN_004038c8(&local_134,2);
    FUN_004038c8(&local_124,2);
    FUN_004038c8(&local_114,2);
    FUN_004038c8(&local_104,2);
    FUN_0050e31c(&local_f4,2);
    FUN_00440004(*(int *)(param_1 + 0x42c),'\0');
  }
  FUN_0050d9d4((int *)&local_14,2);
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4((int *)&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_158;
  return;
}



// Preserved published name: SpeedButton12Click
// Entry 0040b1b0, recovered name Published_SpeedButton12Click_0040b1b0

void Published_SpeedButton12Click_0040b1b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004c6b18(*(int **)(param_1 + 0x408),CONCAT31((int3)((uint)param_2 >> 8),1),param_3);
  FUN_004c6b18(*(int **)(param_1 + 0x40c),0,param_1);
  FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
  return;
}



// Preserved published name: SpeedButton11Click
// Entry 0040b1f4, recovered name Published_SpeedButton11Click_0040b1f4

void Published_SpeedButton11Click_0040b1f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 extraout_EDX;
  
  FUN_004c6b18(*(int **)(param_1 + 0x408),0,param_3);
  FUN_004c6b18(*(int **)(param_1 + 0x40c),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
  if (*(char *)(*(int *)(param_1 + 0x418) + 0x130) == '\0') {
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  else {
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  return;
}



// Preserved published name: sbDIY4Click
// Entry 0040b260, recovered name Published_sbDIY4Click_0040b260

void Published_sbDIY4Click_0040b260(int param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 local_38;
  int local_14;
  int local_10;
  uint *local_c;
  int local_8;
  
  FUN_00502f50(0x512598);
  if (*(char *)(*(int *)(param_1 + 0x41c) + 0x130) == '\0') {
    FUN_00497b1c(*(int *)(param_1 + 0x424),0);
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x408),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x408));
    FUN_004c6b18(*(int **)(param_1 + 0x408),0,param_1);
    FUN_004c6b18(*(int **)(param_1 + 0x40c),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
    (**(code **)(**(int **)(param_1 + 0x40c) + 0x5c))(*(int **)(param_1 + 0x40c),1);
    (**(code **)(**(int **)(param_1 + 0x408) + 0x5c))(*(int **)(param_1 + 0x408),0);
    (**(code **)(**(int **)(param_1 + 0x418) + 0x5c))(*(int **)(param_1 + 0x418),1);
    piVar2 = FUN_0050d87c(&local_14);
    FUN_00401ff0(param_1,DAT_00533e5c,*piVar2);
    FUN_0050d9d4(&local_14,2);
  }
  else {
    FUN_00497b1c(*(int *)(param_1 + 0x424),1);
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x40c),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x40c));
    (**(code **)(**(int **)(param_1 + 0x40c) + 0x5c))(*(int **)(param_1 + 0x40c),0);
    (**(code **)(**(int **)(param_1 + 0x408) + 0x5c))(*(int **)(param_1 + 0x408),0);
    (**(code **)(**(int **)(param_1 + 0x418) + 0x5c))(*(int **)(param_1 + 0x418),0);
    FUN_004c6b18(*(int **)(param_1 + 0x2f4),0,extraout_ECX);
    piVar2 = FUN_0050d87c(&local_8);
    FUN_00401ff0(param_1,DAT_00533e5c,*piVar2);
    FUN_0050d9d4(&local_8,2);
    FUN_00440288(*(int *)(param_1 + 0x430));
    piVar2 = FUN_004016bc(&local_c);
    FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x428) + 0x214),piVar2);
    FUN_004c6c30(*(int *)(*(int *)(param_1 + 0x430) + 0x214),local_c);
    FUN_0050d9d4((int *)&local_c,2);
    piVar2 = FUN_0050d87c(&local_10);
    FUN_00440508(*(int *)(param_1 + 0x430),*piVar2);
    FUN_0050d9d4(&local_10,2);
    FUN_004407c0(*(int *)(param_1 + 0x430));
  }
  *in_FS_OFFSET = local_38;
  return;
}



// Preserved published name: N25Click
// Entry 0040b4a0, recovered name Published_N25Click_0040b4a0

void __stdcall Published_N25Click_0040b4a0(void)

{
  int *piVar1;
  int *piVar2;
  LPCSTR lpFile;
  undefined4 *in_FS_OFFSET;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  INT nShowCmd;
  undefined4 local_3c;
  int local_18;
  int local_14;
  int local_10;
  undefined *local_c;
  int local_8;
  
  FUN_00502f50(0x512624);
  FUN_004016bc(&local_8);
  piVar1 = FUN_004016bc(&local_c);
  FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar1);
  piVar1 = FUN_004016bc(&local_10);
  FUN_004f6cdc(local_c,piVar1);
  piVar1 = &local_10;
  piVar2 = FUN_004016bc(&local_18);
  FUN_0050d87c(&local_14);
  FUN_0050da18(piVar1,&local_14,piVar2);
  FUN_0050da04(&local_8,&local_18);
  FUN_0050d9d4(&local_18,2);
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4((int *)&local_c,2);
  nShowCmd = 5;
  lpDirectory = (LPCSTR)0x0;
  lpParameters = (LPCSTR)0x0;
  lpFile = FUN_00404374(&local_8);
  ShellExecuteA(*(HWND *)(*(int *)PTR_DAT_00533970 + 0x24),&DAT_0051017a,lpFile,lpParameters,
                lpDirectory,nShowCmd);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: N26Click
// Entry 0040b5bc, recovered name Published_N26Click_0040b5bc

void __stdcall Published_N26Click_0040b5bc(void)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  uint *local_8;
  
  FUN_00502f50(0x512660);
  piVar1 = FUN_004016bc(&local_8);
  FUN_0050dd80(&DAT_0051017f,(undefined4 *)&DAT_00533e60,piVar1);
  FUN_004c6c30(*(int *)(*(int *)PTR__about_0053380c + 0x2e8),local_8);
  FUN_0050d9d4((int *)&local_8,2);
  FUN_004c6c30(*(int *)(*(int *)PTR__about_0053380c + 0x2ec),DAT_0050f6f4);
  (**(code **)(**(int **)PTR__about_0053380c + 0xd8))();
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton26Click
// Entry 0040b654, recovered name Published_SpeedButton26Click_0040b654

void Published_SpeedButton26Click_0040b654(int param_1)

{
  VARIANTARG *pVVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_68;
  VARIANTARG local_44;
  VARIANTARG local_34;
  VARIANTARG local_24;
  VARIANTARG local_14;
  
  FUN_00502f50(0x5126a8);
  pVVar1 = FUN_004037cc(&local_24);
  FUN_00403810(pVVar1);
  pVVar1 = FUN_004037cc(&local_34);
  FUN_00403810(pVVar1);
  pVVar1 = FUN_004037cc(&local_44);
  FUN_00403810(pVVar1);
  pVVar1 = FUN_004037cc(&local_14);
  FUN_00403810(pVVar1);
  _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
            (*(int **)(*(int *)(param_1 + 0x2f4) + 0x208));
  FUN_004038c8(&local_44,2);
  FUN_004038c8(&local_34,2);
  FUN_004038c8(&local_24,2);
  FUN_004038c8(&local_14,2);
  *in_FS_OFFSET = local_68;
  return;
}



// Preserved published name: userdiy1TreeView1Change
// Entry 0040b740, recovered name Published_userdiy1TreeView1Change_0040b740

void Published_userdiy1TreeView1Change_0040b740(int param_1,undefined4 param_2,int param_3)

{
  Published_TreeView1Change_00444acc(*(int *)(param_1 + 0x458),param_2,param_3);
  return;
}



// Preserved published name: SpeedButton23Click
// Entry 0040b768, recovered name Published_SpeedButton23Click_0040b768

void Published_SpeedButton23Click_0040b768(int param_1)

{
  (**(code **)(**(int **)(*(int *)(param_1 + 0x458) + 0x220) + 0x40))();
  return;
}



// Preserved published name: SpeedButton24Click
// Entry 0040b78c, recovered name Published_SpeedButton24Click_0040b78c

void Published_SpeedButton24Click_0040b78c(int param_1)

{
  (**(code **)(**(int **)(*(int *)(param_1 + 0x458) + 0x224) + 0x40))();
  return;
}



// Preserved published name: SpeedButton27Click
// Entry 0040b7b0, recovered name Published_SpeedButton27Click_0040b7b0

void Published_SpeedButton27Click_0040b7b0(int param_1)

{
  (**(code **)(**(int **)(*(int *)(param_1 + 0x458) + 0x22c) + 0x40))();
  return;
}



// Preserved published name: SpeedButton28Click
// Entry 0040b7d4, recovered name Published_SpeedButton28Click_0040b7d4

void Published_SpeedButton28Click_0040b7d4(int param_1)

{
  (**(code **)(**(int **)(*(int *)(param_1 + 0x458) + 0x230) + 0x40))();
  return;
}



// Preserved published name: SpeedButton22Click
// Entry 0040b7f8, recovered name Published_SpeedButton22Click_0040b7f8

void Published_SpeedButton22Click_0040b7f8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  FUN_004c6b18(*(int **)(param_1 + 0x440),CONCAT31((int3)((uint)param_2 >> 8),1),param_3);
  iVar1 = **(int **)(param_1 + 0x440);
  (**(code **)(iVar1 + 0x5c))(*(int **)(param_1 + 0x440),1,iVar1,param_2);
  FUN_004c6b18(*(int **)(param_1 + 0x444),0,extraout_ECX);
  FUN_004c6438(*(int **)(param_1 + 0x2e0),1);
  return;
}



// Preserved published name: SpeedButton21Click
// Entry 0040b84c, recovered name Published_SpeedButton21Click_0040b84c

void Published_SpeedButton21Click_0040b84c(int param_1)

{
  int *piVar1;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 local_34;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x5126ec);
  FUN_004c6b18(*(int **)(param_1 + 0x440),0,param_1);
  FUN_004c6b18(*(int **)(param_1 + 0x444),CONCAT31((int3)((uint)extraout_EDX >> 8),1),param_1);
  if (*(char *)(*(int *)(param_1 + 0x450) + 0x130) == '\0') {
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
    piVar1 = FUN_0050d87c(&local_c);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_c,2);
    FUN_004d9ba8(*(int **)(*(int *)(param_1 + 0x458) + 0x208),0);
    piVar1 = FUN_0050d87c(&local_10);
    FUN_00401ff0(param_1,DAT_00533e5c,*piVar1);
    FUN_0050d9d4(&local_10,2);
  }
  else {
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
    piVar1 = FUN_0050d87c(&local_8);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_8,2);
    FUN_004d9ba8(*(int **)(*(int *)(param_1 + 0x458) + 0x208),1);
  }
  *in_FS_OFFSET = local_34;
  return;
}



// Preserved published name: SpeedButton25Click
// Entry 0040b9a0, recovered name Published_SpeedButton25Click_0040b9a0

void Published_SpeedButton25Click_0040b9a0(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x512738);
  if (*(char *)(*(int *)(param_1 + 0x450) + 0x130) == '\0') {
    piVar1 = FUN_0050d87c(&local_c);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_c,2);
    FUN_004d9ba8(*(int **)(*(int *)(param_1 + 0x458) + 0x208),0);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  else {
    piVar1 = FUN_0050d87c(&local_8);
    FUN_00401ff0(param_1,DAT_00533e58,*piVar1);
    FUN_0050d9d4(&local_8,2);
    FUN_004d9ba8(*(int **)(*(int *)(param_1 + 0x458) + 0x208),1);
    FUN_004c6438(*(int **)(param_1 + 0x2e0),200);
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: N28Click
// Entry 0040ba9c, recovered name Published_N28Click_0040ba9c

void Published_N28Click_0040ba9c(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x468) + 0x2c) == '\0') {
    FUN_004020b0(param_1);
    FUN_00497b1c(*(int *)(param_1 + 0x468),*(char *)(*(int *)(param_1 + 0x468) + 0x2c) == '\0');
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),4);
    Published_PageControl1Change_0040513c(param_1);
  }
  return;
}



// Preserved published name: Ndm5Click
// Entry 0040bb04, recovered name Published_Ndm5Click_0040bb04

void Published_Ndm5Click_0040bb04(int param_1)

{
  code *pcVar1;
  
  FUN_00497b1c(*(int *)(param_1 + 0x464),*(char *)(*(int *)(param_1 + 0x464) + 0x2c) == '\0');
  if (*(char *)(*(int *)(param_1 + 0x464) + 0x2c) == '\0') {
    FUN_004f1978(*(int **)(param_1 + 0x41c),'\0');
    pcVar1 = (code *)FUN_0050de08(*(int **)(param_1 + 0x41c),0xffffffec);
    (*pcVar1)(*(undefined4 *)(param_1 + 0x41c));
  }
  else {
    FUN_004d9ba8(*(int **)(param_1 + 0x2fc),4);
    Published_PageControl1Change_0040513c(param_1);
  }
  return;
}



// Preserved published name: Image1MouseDown
// Entry 00410ed4, recovered name Published_Image1MouseDown_00410ed4

void Published_Image1MouseDown_00410ed4
               (int param_1,undefined4 param_2,undefined1 param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  LONG LVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  undefined4 extraout_EDX_10;
  undefined4 extraout_EDX_11;
  undefined4 extraout_EDX_12;
  undefined4 extraout_EDX_13;
  undefined4 *in_FS_OFFSET;
  char cVar7;
  undefined *puVar8;
  undefined4 local_c0;
  int local_ac;
  int local_a8;
  undefined1 local_a1;
  undefined4 local_a0;
  int local_9c;
  undefined4 local_98;
  undefined2 local_88;
  int local_7c;
  int local_74;
  int local_70;
  int local_6c;
  undefined *local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined *local_30;
  undefined *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_a1 = param_3;
  local_a0 = param_2;
  local_9c = param_1;
  FUN_00502f50(0x514b3c);
  local_88 = 8;
  FUN_004016bc(&local_8);
  local_7c = local_7c + 1;
  local_88 = 0x20;
  FUN_004016bc(&local_34);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_30);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_2c);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_28);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_24);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_20);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_1c);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_18);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_14);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_10);
  local_7c = local_7c + 1;
  FUN_004016bc(&local_c);
  local_7c = local_7c + 2;
  local_88 = 0x14;
  local_a8 = (param_5 - _fz_w) / (_rect_w + -1);
  iVar1 = (param_4 - _fz_h) + -1;
  local_ac = iVar1 / (_rect_h + -1);
  iVar1 = iVar1 % (_rect_h + -1);
  if (param_5 - _fz_w < 0) {
    local_a8 = -1;
  }
  if ((param_4 - _fz_h) + -1 < 0) {
    local_ac = -1;
  }
  if (6 < local_ac) {
    local_a8 = ((param_5 - _fz_w) - _fb_offx) / (_rect_w + -1);
    iVar1 = ((param_4 - _fz_h) + -1) - _fb_offy;
    local_ac = iVar1 / (_rect_h + -1);
    iVar1 = iVar1 % (_rect_h + -1);
  }
  piVar3 = _bmp;
  piVar2 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),iVar1,_rect_h + -1);
  FUN_004a8a40(piVar2,0,0,piVar3);
  iVar1 = _nowelenum;
  _nowelenum = 0;
  local_88 = 0x2c;
  piVar3 = FUN_004016bc(&local_48);
  local_7c = local_7c + 1;
  FUN_004f6a10(local_ac,piVar3);
  piVar3 = &local_48;
  piVar2 = FUN_004016bc(&local_3c);
  local_7c = local_7c + 1;
  FUN_004f6a10(local_a8,piVar2);
  piVar2 = &local_3c;
  piVar4 = FUN_004016bc(&local_44);
  local_7c = local_7c + 1;
  FUN_0050d87c(&local_40);
  local_7c = local_7c + 1;
  FUN_0050da18(piVar2,&local_40,piVar4);
  piVar2 = &local_44;
  piVar4 = FUN_004016bc(&local_4c);
  local_7c = local_7c + 1;
  FUN_0050da18(piVar2,piVar3,piVar4);
  iVar5 = (**(code **)(*_rectlist + 0x50))(_rectlist,local_4c);
  cVar7 = -1 < iVar5;
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_4c,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_48,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_44,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_40,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_3c,2);
  if (cVar7 != '\0') {
    iVar5 = FUN_004100a0(local_a8,local_ac);
    _nowelenum = iVar5;
    if (0 < iVar5) {
      if (iVar5 < 200) {
        local_88 = 0x38;
        piVar3 = FUN_004016bc(&local_50);
        local_7c = local_7c + 1;
        FUN_004f6a10(iVar5,piVar3);
        piVar3 = &local_50;
        piVar2 = FUN_004016bc(&local_54);
        local_7c = local_7c + 1;
        FUN_0050dd80(&DAT_0051418c,piVar3,piVar2);
        piVar3 = &local_54;
        piVar2 = FUN_004016bc(&local_5c);
        local_7c = local_7c + 1;
        FUN_0050d87c(&local_58);
        local_7c = local_7c + 1;
        FUN_0050da18(piVar3,&local_58,piVar2);
        FUN_0050da04(&local_8,&local_5c);
        local_7c = local_7c + -1;
        FUN_0050d9d4(&local_5c,2);
        local_7c = local_7c + -1;
        FUN_0050d9d4(&local_58,2);
        local_7c = local_7c + -1;
        FUN_0050d9d4(&local_54,2);
        local_7c = local_7c + -1;
        FUN_0050d9d4(&local_50,2);
      }
      else if (iVar5 == 200) {
        local_88 = 0x44;
        FUN_0050d87c(&local_60);
        local_7c = local_7c + 1;
        FUN_0050da04(&local_8,&local_60);
        local_7c = local_7c + -1;
        FUN_0050d9d4(&local_60,2);
      }
      else if (iVar5 == 300) {
        local_88 = 0x50;
        FUN_0050d87c(&local_64);
        local_7c = local_7c + 1;
        FUN_0050da04(&local_8,&local_64);
        local_7c = local_7c + -1;
        FUN_0050d9d4(&local_64,2);
      }
      if (_nowelenum == 200) {
        _nowelenum = 0x39;
      }
      else if (_nowelenum == 300) {
        _nowelenum = 0x59;
      }
      else if (0x67 < _nowelenum) {
        _nowelenum = iVar1;
      }
    }
    FUN_00410294(_nowelenum,&local_a8,&local_ac);
    if (_nowelenum == 0) {
      local_7c = local_7c + -2;
      FUN_0050d9d4(&local_c,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4(&local_10,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4(&local_14,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4(&local_18,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4(&local_1c,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4(&local_20,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4(&local_24,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4(&local_28,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4((int *)&local_2c,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4((int *)&local_30,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4((int *)&local_34,2);
      local_7c = local_7c + -1;
      FUN_0050d9d4(&local_8,2);
      *in_FS_OFFSET = local_98;
      return;
    }
    piVar3 = _bmp;
    piVar2 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX,extraout_ECX);
    FUN_004a8a40(piVar2,0,0,piVar3);
    iVar1 = FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_00,extraout_ECX_00);
    FUN_004a8440(*(int **)(iVar1 + 0x10),0xff);
    iVar1 = FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_01,local_9c);
    FUN_004a8864(*(int **)(iVar1 + 0x14),'\x01');
    if (local_ac < 7) {
      iVar5 = ((local_a8 + 1) * _rect_w + _fz_w) - local_a8;
      iVar1 = ((local_ac + 1) * _rect_h + _fz_h + -1) - local_ac;
      piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),local_9c,iVar5);
      FUN_004a8c5c(piVar3,(local_a8 * _rect_w + _fz_w) - local_a8,
                   (local_ac * _rect_h + _fz_h + -1) - local_ac,iVar1,iVar5);
      piVar3 = (int *)FUN_004add64(_bmp);
      local_c0 = FUN_004a8fac(piVar3,(((local_a8 + 1) * _rect_w + _fz_w) - local_a8) + -3,
                              (((local_ac + 1) * _rect_h + _fz_h) - local_ac) + -3);
    }
    else {
      iVar1 = (((local_a8 + 1) * _rect_w + _fz_w) - local_a8) + _fb_offx;
      iVar5 = (((local_ac + 1) * _rect_h + _fz_h + -1) - local_ac) + _fb_offy;
      piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),iVar5,local_9c);
      FUN_004a8c5c(piVar3,((local_a8 * _rect_w + _fz_w) - local_a8) + _fb_offx,
                   ((local_ac * _rect_h + _fz_h + -1) - local_ac) + _fb_offy,iVar5,iVar1);
      piVar3 = (int *)FUN_004add64(_bmp);
      local_c0 = FUN_004a8fac(piVar3,(((local_a8 + 1) * _rect_w + _fz_w) - local_a8) + _fb_offx + -3
                              ,(((local_ac + 1) * _rect_h + _fz_h) - local_ac) + _fb_offy + -3);
    }
    FUN_00410478(local_9c,_nowelenum,&local_38);
    iVar1 = FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_02,extraout_ECX_01);
    FUN_004a8864(*(int **)(iVar1 + 0x14),'\0');
    iVar1 = FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_03,local_9c);
    FUN_004a8748(*(int **)(iVar1 + 0x14),local_c0);
    iVar1 = FUN_00506284();
    iVar1 = iVar1 + _rect_w * 3;
    iVar5 = FUN_00506284();
    iVar5 = iVar5 + 10;
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),local_9c,extraout_ECX_02);
    FUN_004a8c5c(piVar3,_rect_w * 3,10,iVar5,iVar1);
    iVar1 = FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_04,extraout_ECX_03);
    FUN_004a8864(*(int **)(iVar1 + 0x14),'\x01');
    iVar1 = FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_05,local_9c);
    FUN_004a8440(*(int **)(iVar1 + 0x10),0);
    iVar1 = FUN_00506284();
    iVar1 = iVar1 + _rect_w * 3;
    iVar5 = FUN_00506284();
    iVar5 = iVar5 + 10;
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),local_9c,extraout_ECX_04);
    FUN_004a8c5c(piVar3,_rect_w * 3,10,iVar5,iVar1);
    iVar1 = FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_06,extraout_ECX_05);
    FUN_004a81f4(*(int **)(iVar1 + 0xc),0xc);
    local_88 = 0x5c;
    piVar3 = FUN_004016bc(&local_68);
    local_7c = local_7c + 1;
    FUN_004f6a10(local_38,piVar3);
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),&local_68,local_9c);
    thunk_FUN_004a8d0c(piVar3,_rect_w * 3 + 1,0xb,local_68);
    local_7c = local_7c + -1;
    FUN_0050d9d4((int *)&local_68,2);
    local_88 = 0x68;
    piVar3 = FUN_0050d87c(&local_6c);
    local_7c = local_7c + 1;
    puVar8 = (undefined *)*piVar3;
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_07,local_9c);
    LVar6 = FUN_004a8e80(piVar3,puVar8);
    iVar1 = FUN_00506284();
    local_7c = local_7c + -1;
    FUN_0050d9d4(&local_6c,2);
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_08,local_9c);
    thunk_FUN_004a8d0c(piVar3,_rect_w * 3 + (iVar1 - LVar6),0xb,local_34);
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_09,extraout_ECX_06);
    FUN_004a8e80(piVar3,local_30);
    iVar1 = FUN_00506284();
    local_88 = 0x74;
    piVar3 = FUN_0050d87c(&local_70);
    local_7c = local_7c + 1;
    puVar8 = (undefined *)*piVar3;
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),local_9c,extraout_ECX_07);
    FUN_004a8e9c(piVar3,puVar8);
    iVar5 = FUN_00506284();
    local_7c = local_7c + -1;
    FUN_0050d9d4(&local_70,2);
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_10,local_9c);
    thunk_FUN_004a8d0c(piVar3,_rect_w * 3 + iVar1,iVar5 + 10,local_30);
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_11,extraout_ECX_08);
    FUN_004a8e80(piVar3,local_2c);
    iVar1 = FUN_00506284();
    local_88 = 0x80;
    piVar3 = FUN_0050d87c(&local_74);
    local_7c = local_7c + 1;
    puVar8 = (undefined *)*piVar3;
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),local_9c,extraout_ECX_09);
    FUN_004a8e9c(piVar3,puVar8);
    iVar5 = FUN_00506284();
    local_7c = local_7c + -1;
    FUN_0050d9d4(&local_74,2);
    piVar3 = (int *)FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_12,local_9c);
    thunk_FUN_004a8d0c(piVar3,_rect_w * 3 + iVar1,iVar5 + 10,local_2c);
    iVar1 = FUN_004befe0(*(int *)(local_9c + 0x20c),extraout_EDX_13,extraout_ECX_10);
    FUN_004a8864(*(int **)(iVar1 + 0x14),'\0');
  }
  FUN_00410ea0(local_9c);
  local_7c = local_7c + -2;
  FUN_0050d9d4(&local_c,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_10,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_14,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_18,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_1c,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_20,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_24,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_28,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4((int *)&local_2c,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4((int *)&local_30,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4((int *)&local_34,2);
  local_7c = local_7c + -1;
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_98;
  return;
}



// Preserved published name: Button1Click
// Entry 0041408c, recovered name Published_Button1Click_0041408c

void Published_Button1Click_0041408c(int param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 *in_FS_OFFSET;
  int iStack_1d8;
  undefined4 uStack_1c4;
  int iStack_194;
  int iStack_190;
  int iStack_18c;
  int iStack_188;
  int iStack_184;
  int iStack_180;
  int iStack_17c;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  int iStack_164;
  int iStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  int iStack_150;
  int iStack_14c;
  int iStack_148;
  int iStack_144;
  int iStack_140;
  int iStack_13c;
  int iStack_138;
  int iStack_134;
  int iStack_130;
  int iStack_12c;
  int iStack_128;
  int iStack_124;
  int iStack_120;
  int iStack_11c;
  int iStack_118;
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  int iStack_108;
  int iStack_104;
  int iStack_100;
  int iStack_fc;
  int iStack_f8;
  int iStack_f4;
  int iStack_f0;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  int iStack_e0;
  int iStack_dc;
  int iStack_d8;
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  int iStack_b4;
  int iStack_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined *puStack_28;
  int aiStack_24 [2];
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 *puStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  FUN_00502f50(0x515a10);
  FUN_004016bc(&iStack_8);
  FUN_004016bc(&puStack_c);
  iStack_1d8 = 1;
  do {
    puStack_10 = (undefined4 *)FUN_005020a8(0x30);
    if (puStack_10 != (undefined4 *)0x0) {
      FUN_004016bc(puStack_10 + 1);
      FUN_004016bc(puStack_10 + 2);
      FUN_004016bc(puStack_10 + 3);
      FUN_004016bc(puStack_10 + 4);
      FUN_004016bc(puStack_10 + 5);
      FUN_004016bc(puStack_10 + 6);
      FUN_004016bc(puStack_10 + 7);
      FUN_004016bc(puStack_10 + 8);
      FUN_004016bc(puStack_10 + 9);
      FUN_004016bc(puStack_10 + 10);
      FUN_004016bc(puStack_10 + 0xb);
    }
    puVar1 = puStack_10;
    bVar2 = _GetEleInfo_qqrp15Adodb_TADOQueryip7eleinfo
                      (*(int **)(param_1 + 0x210),iStack_1d8,puStack_10);
    if (bVar2) {
      piVar3 = FUN_004016bc(&iStack_14);
      FUN_004f6a10(iStack_1d8,piVar3);
      piVar3 = &iStack_14;
      piVar4 = FUN_004016bc(&iStack_1c);
      FUN_0050d87c(&iStack_18);
      FUN_0050da18(piVar3,&iStack_18,piVar4);
      FUN_0050da04((int *)&puStack_c,&iStack_1c);
      FUN_0050d9d4(&iStack_1c,2);
      FUN_0050d9d4(&iStack_18,2);
      FUN_0050d9d4(&iStack_14,2);
      piVar4 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',puStack_c,0xffff);
      FUN_0050d87c(aiStack_24);
      FUN_0050da04(&iStack_8,aiStack_24);
      FUN_0050d9d4(aiStack_24,2);
      piVar3 = FUN_004016bc(&puStack_28);
      FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar3);
      puVar7 = puStack_28;
      piVar3 = FUN_004016bc(&iStack_2c);
      FUN_004f6cdc(puVar7,piVar3);
      piVar3 = &iStack_2c;
      piVar5 = FUN_004016bc(&iStack_30);
      FUN_0050dd80(s_<body_background___005143de,piVar3,piVar5);
      piVar3 = &iStack_30;
      piVar5 = FUN_004016bc(&iStack_38);
      FUN_0050d87c(&iStack_34);
      FUN_0050da18(piVar3,&iStack_34,piVar5);
      FUN_0050da04(&iStack_8,&iStack_38);
      FUN_0050d9d4(&iStack_38,2);
      FUN_0050d9d4(&iStack_34,2);
      FUN_0050d9d4(&iStack_30,2);
      FUN_0050d9d4(&iStack_2c,2);
      FUN_0050d9d4((int *)&puStack_28,2);
      piVar3 = FUN_004016bc(&iStack_40);
      FUN_0050d87c(&iStack_3c);
      FUN_0050da18(&iStack_8,&iStack_3c,piVar3);
      FUN_0050da04(&iStack_8,&iStack_40);
      FUN_0050d9d4(&iStack_40,2);
      FUN_0050d9d4(&iStack_3c,2);
      piVar3 = FUN_004016bc(&iStack_4c);
      FUN_004f6a10(*puVar1,piVar3);
      piVar3 = &iStack_4c;
      piVar5 = FUN_004016bc(&iStack_48);
      FUN_0050d87c(&iStack_44);
      FUN_0050da18(&iStack_8,&iStack_44,piVar5);
      piVar5 = FUN_004016bc(&iStack_50);
      FUN_0050da18(&iStack_48,piVar3,piVar5);
      FUN_0050da04(&iStack_8,&iStack_50);
      FUN_0050d9d4(&iStack_50,2);
      FUN_0050d9d4(&iStack_4c,2);
      FUN_0050d9d4(&iStack_48,2);
      FUN_0050d9d4(&iStack_44,2);
      piVar3 = FUN_004016bc(&iStack_58);
      FUN_0050d87c(&iStack_54);
      FUN_0050da18(&iStack_8,&iStack_54,piVar3);
      FUN_0050da04(&iStack_8,&iStack_58);
      FUN_0050d9d4(&iStack_58,2);
      FUN_0050d9d4(&iStack_54,2);
      piVar3 = FUN_004016bc(&iStack_60);
      FUN_0050d87c(&iStack_5c);
      FUN_0050da18(&iStack_8,&iStack_5c,piVar3);
      piVar3 = &iStack_60;
      piVar5 = FUN_004016bc(&iStack_64);
      FUN_0050da18(piVar3,puVar1 + 1,piVar5);
      FUN_0050da04(&iStack_8,&iStack_64);
      FUN_0050d9d4(&iStack_64,2);
      FUN_0050d9d4(&iStack_60,2);
      FUN_0050d9d4(&iStack_5c,2);
      piVar3 = FUN_004016bc(&iStack_6c);
      FUN_0050d87c(&iStack_68);
      FUN_0050da18(&iStack_8,&iStack_68,piVar3);
      FUN_0050da04(&iStack_8,&iStack_6c);
      FUN_0050d9d4(&iStack_6c,2);
      FUN_0050d9d4(&iStack_68,2);
      piVar3 = FUN_004016bc(&iStack_74);
      FUN_0050d87c(&iStack_70);
      FUN_0050da18(&iStack_8,&iStack_70,piVar3);
      piVar3 = &iStack_74;
      piVar5 = FUN_004016bc(&iStack_78);
      FUN_0050da18(piVar3,puVar1 + 2,piVar5);
      FUN_0050da04(&iStack_8,&iStack_78);
      FUN_0050d9d4(&iStack_78,2);
      FUN_0050d9d4(&iStack_74,2);
      FUN_0050d9d4(&iStack_70,2);
      piVar3 = FUN_004016bc(&iStack_80);
      FUN_0050d87c(&iStack_7c);
      FUN_0050da18(&iStack_8,&iStack_7c,piVar3);
      FUN_0050da04(&iStack_8,&iStack_80);
      FUN_0050d9d4(&iStack_80,2);
      FUN_0050d9d4(&iStack_7c,2);
      piVar3 = FUN_004016bc(&iStack_88);
      FUN_0050d87c(&iStack_84);
      FUN_0050da18(&iStack_8,&iStack_84,piVar3);
      piVar3 = &iStack_88;
      piVar5 = FUN_004016bc(&iStack_8c);
      FUN_0050da18(piVar3,puVar1 + 3,piVar5);
      FUN_0050da04(&iStack_8,&iStack_8c);
      FUN_0050d9d4(&iStack_8c,2);
      FUN_0050d9d4(&iStack_88,2);
      FUN_0050d9d4(&iStack_84,2);
      piVar3 = FUN_004016bc(&iStack_94);
      FUN_0050d87c(&iStack_90);
      FUN_0050da18(&iStack_8,&iStack_90,piVar3);
      FUN_0050da04(&iStack_8,&iStack_94);
      FUN_0050d9d4(&iStack_94,2);
      FUN_0050d9d4(&iStack_90,2);
      piVar3 = FUN_004016bc(&iStack_9c);
      FUN_0050d87c(&iStack_98);
      FUN_0050da18(&iStack_8,&iStack_98,piVar3);
      piVar3 = &iStack_9c;
      piVar5 = FUN_004016bc(&iStack_a0);
      FUN_0050da18(piVar3,puVar1 + 4,piVar5);
      FUN_0050da04(&iStack_8,&iStack_a0);
      FUN_0050d9d4(&iStack_a0,2);
      FUN_0050d9d4(&iStack_9c,2);
      FUN_0050d9d4(&iStack_98,2);
      piVar3 = FUN_004016bc(&iStack_a8);
      FUN_0050d87c(&iStack_a4);
      FUN_0050da18(&iStack_8,&iStack_a4,piVar3);
      FUN_0050da04(&iStack_8,&iStack_a8);
      FUN_0050d9d4(&iStack_a8,2);
      FUN_0050d9d4(&iStack_a4,2);
      piVar3 = FUN_004016bc(&iStack_b8);
      _GetNEmpty_qqrxi(4,piVar3);
      piVar3 = &iStack_b8;
      piVar5 = FUN_004016bc(&iStack_b0);
      FUN_0050d87c(&iStack_ac);
      FUN_0050da18(&iStack_8,&iStack_ac,piVar5);
      piVar5 = FUN_004016bc(&iStack_b4);
      FUN_0050da18(&iStack_b0,puVar1 + 5,piVar5);
      piVar5 = FUN_004016bc(&iStack_bc);
      FUN_0050da18(&iStack_b4,piVar3,piVar5);
      piVar3 = &iStack_bc;
      piVar5 = FUN_004016bc(&iStack_c4);
      FUN_0050d87c(&iStack_c0);
      FUN_0050da18(piVar3,&iStack_c0,piVar5);
      piVar3 = &iStack_c4;
      piVar5 = FUN_004016bc(&iStack_c8);
      FUN_0050da18(piVar3,puVar1 + 6,piVar5);
      piVar3 = &iStack_c8;
      piVar5 = FUN_004016bc(&iStack_d0);
      FUN_0050d87c(&iStack_cc);
      FUN_0050da18(piVar3,&iStack_cc,piVar5);
      FUN_0050da04(&iStack_8,&iStack_d0);
      FUN_0050d9d4(&iStack_d0,2);
      FUN_0050d9d4(&iStack_cc,2);
      FUN_0050d9d4(&iStack_c8,2);
      FUN_0050d9d4(&iStack_c4,2);
      FUN_0050d9d4(&iStack_c0,2);
      FUN_0050d9d4(&iStack_bc,2);
      FUN_0050d9d4(&iStack_b8,2);
      FUN_0050d9d4(&iStack_b4,2);
      FUN_0050d9d4(&iStack_b0,2);
      FUN_0050d9d4(&iStack_ac,2);
      piVar3 = FUN_004016bc(&iStack_dc);
      _GetNEmpty_qqrxi(4,piVar3);
      piVar3 = &iStack_dc;
      piVar5 = FUN_004016bc(&iStack_d8);
      FUN_0050d87c(&iStack_d4);
      FUN_0050da18(&iStack_8,&iStack_d4,piVar5);
      piVar5 = FUN_004016bc(&iStack_e0);
      FUN_0050da18(&iStack_d8,piVar3,piVar5);
      piVar3 = &iStack_e0;
      piVar5 = FUN_004016bc(&iStack_e4);
      FUN_0050da18(piVar3,puVar1 + 7,piVar5);
      piVar3 = &iStack_e4;
      piVar5 = FUN_004016bc(&iStack_ec);
      FUN_0050d87c(&iStack_e8);
      FUN_0050da18(piVar3,&iStack_e8,piVar5);
      FUN_0050da04(&iStack_8,&iStack_ec);
      FUN_0050d9d4(&iStack_ec,2);
      FUN_0050d9d4(&iStack_e8,2);
      FUN_0050d9d4(&iStack_e4,2);
      FUN_0050d9d4(&iStack_e0,2);
      FUN_0050d9d4(&iStack_dc,2);
      FUN_0050d9d4(&iStack_d8,2);
      FUN_0050d9d4(&iStack_d4,2);
      piVar3 = FUN_004016bc(&iStack_f4);
      FUN_0050d87c(&iStack_f0);
      FUN_0050da18(&iStack_8,&iStack_f0,piVar3);
      FUN_0050da04(&iStack_8,&iStack_f4);
      FUN_0050d9d4(&iStack_f4,2);
      FUN_0050d9d4(&iStack_f0,2);
      piVar3 = FUN_004016bc(&iStack_100);
      _GetNEmpty_qqrxi(4,piVar3);
      piVar3 = &iStack_100;
      piVar5 = FUN_004016bc(&iStack_fc);
      FUN_0050d87c(&iStack_f8);
      FUN_0050da18(&iStack_8,&iStack_f8,piVar5);
      piVar5 = FUN_004016bc(&iStack_104);
      FUN_0050da18(&iStack_fc,piVar3,piVar5);
      piVar3 = &iStack_104;
      piVar5 = FUN_004016bc(&iStack_108);
      FUN_0050da18(piVar3,puVar1 + 8,piVar5);
      piVar3 = &iStack_108;
      piVar5 = FUN_004016bc(&iStack_110);
      FUN_0050d87c(&iStack_10c);
      FUN_0050da18(piVar3,&iStack_10c,piVar5);
      FUN_0050da04(&iStack_8,&iStack_110);
      FUN_0050d9d4(&iStack_110,2);
      FUN_0050d9d4(&iStack_10c,2);
      FUN_0050d9d4(&iStack_108,2);
      FUN_0050d9d4(&iStack_104,2);
      FUN_0050d9d4(&iStack_100,2);
      FUN_0050d9d4(&iStack_fc,2);
      FUN_0050d9d4(&iStack_f8,2);
      piVar3 = FUN_004016bc(&iStack_118);
      FUN_0050d87c(&iStack_114);
      FUN_0050da18(&iStack_8,&iStack_114,piVar3);
      FUN_0050da04(&iStack_8,&iStack_118);
      FUN_0050d9d4(&iStack_118,2);
      FUN_0050d9d4(&iStack_114,2);
      piVar3 = FUN_004016bc(&iStack_124);
      _GetNEmpty_qqrxi(4,piVar3);
      piVar3 = &iStack_124;
      piVar5 = FUN_004016bc(&iStack_120);
      FUN_0050d87c(&iStack_11c);
      FUN_0050da18(&iStack_8,&iStack_11c,piVar5);
      piVar5 = FUN_004016bc(&iStack_128);
      FUN_0050da18(&iStack_120,piVar3,piVar5);
      piVar3 = &iStack_128;
      piVar5 = FUN_004016bc(&iStack_12c);
      FUN_0050da18(piVar3,puVar1 + 9,piVar5);
      piVar3 = &iStack_12c;
      piVar5 = FUN_004016bc(&iStack_134);
      FUN_0050d87c(&iStack_130);
      FUN_0050da18(piVar3,&iStack_130,piVar5);
      FUN_0050da04(&iStack_8,&iStack_134);
      FUN_0050d9d4(&iStack_134,2);
      FUN_0050d9d4(&iStack_130,2);
      FUN_0050d9d4(&iStack_12c,2);
      FUN_0050d9d4(&iStack_128,2);
      FUN_0050d9d4(&iStack_124,2);
      FUN_0050d9d4(&iStack_120,2);
      FUN_0050d9d4(&iStack_11c,2);
      piVar3 = FUN_004016bc(&iStack_13c);
      FUN_0050d87c(&iStack_138);
      FUN_0050da18(&iStack_8,&iStack_138,piVar3);
      FUN_0050da04(&iStack_8,&iStack_13c);
      FUN_0050d9d4(&iStack_13c,2);
      FUN_0050d9d4(&iStack_138,2);
      piVar3 = FUN_004016bc(&iStack_148);
      _GetNEmpty_qqrxi(4,piVar3);
      piVar3 = &iStack_148;
      piVar5 = FUN_004016bc(&iStack_144);
      FUN_0050d87c(&iStack_140);
      FUN_0050da18(&iStack_8,&iStack_140,piVar5);
      piVar5 = FUN_004016bc(&iStack_14c);
      FUN_0050da18(&iStack_144,piVar3,piVar5);
      piVar3 = &iStack_14c;
      piVar5 = FUN_004016bc(&iStack_150);
      FUN_0050da18(piVar3,puVar1 + 10,piVar5);
      piVar3 = &iStack_150;
      piVar5 = FUN_004016bc(&iStack_158);
      FUN_0050d87c(&iStack_154);
      FUN_0050da18(piVar3,&iStack_154,piVar5);
      FUN_0050da04(&iStack_8,&iStack_158);
      FUN_0050d9d4(&iStack_158,2);
      FUN_0050d9d4(&iStack_154,2);
      FUN_0050d9d4(&iStack_150,2);
      FUN_0050d9d4(&iStack_14c,2);
      FUN_0050d9d4(&iStack_148,2);
      FUN_0050d9d4(&iStack_144,2);
      FUN_0050d9d4(&iStack_140,2);
      piVar3 = FUN_004016bc(&iStack_160);
      FUN_0050d87c(&iStack_15c);
      FUN_0050da18(&iStack_8,&iStack_15c,piVar3);
      FUN_0050da04(&iStack_8,&iStack_160);
      FUN_0050d9d4(&iStack_160,2);
      FUN_0050d9d4(&iStack_15c,2);
      piVar3 = FUN_004016bc(&iStack_16c);
      _GetNEmpty_qqrxi(4,piVar3);
      piVar3 = &iStack_16c;
      piVar5 = FUN_004016bc(&iStack_168);
      FUN_0050d87c(&iStack_164);
      FUN_0050da18(&iStack_8,&iStack_164,piVar5);
      piVar5 = FUN_004016bc(&iStack_170);
      FUN_0050da18(&iStack_168,piVar3,piVar5);
      piVar3 = &iStack_170;
      piVar5 = FUN_004016bc(&iStack_174);
      FUN_0050da18(piVar3,puVar1 + 0xb,piVar5);
      piVar3 = &iStack_174;
      piVar5 = FUN_004016bc(&iStack_17c);
      FUN_0050d87c(&iStack_178);
      FUN_0050da18(piVar3,&iStack_178,piVar5);
      FUN_0050da04(&iStack_8,&iStack_17c);
      FUN_0050d9d4(&iStack_17c,2);
      FUN_0050d9d4(&iStack_178,2);
      FUN_0050d9d4(&iStack_174,2);
      FUN_0050d9d4(&iStack_170,2);
      FUN_0050d9d4(&iStack_16c,2);
      FUN_0050d9d4(&iStack_168,2);
      FUN_0050d9d4(&iStack_164,2);
      piVar3 = FUN_004016bc(&iStack_184);
      FUN_0050d87c(&iStack_180);
      FUN_0050da18(&iStack_8,&iStack_180,piVar3);
      FUN_0050da04(&iStack_8,&iStack_184);
      FUN_0050d9d4(&iStack_184,2);
      FUN_0050d9d4(&iStack_180,2);
      piVar3 = FUN_004016bc(&iStack_18c);
      FUN_0050d87c(&iStack_188);
      FUN_0050da18(&iStack_8,&iStack_188,piVar3);
      FUN_0050da04(&iStack_8,&iStack_18c);
      FUN_0050d9d4(&iStack_18c,2);
      FUN_0050d9d4(&iStack_188,2);
      piVar3 = FUN_004016bc(&iStack_194);
      FUN_0050d87c(&iStack_190);
      FUN_0050da18(&iStack_8,&iStack_190,piVar3);
      FUN_0050da04(&iStack_8,&iStack_194);
      FUN_0050d9d4(&iStack_194,2);
      FUN_0050d9d4(&iStack_190,2);
      uVar6 = FUN_00404394(&iStack_8);
      puVar7 = FUN_00404374(&iStack_8);
      (**(code **)(*piVar4 + 8))(piVar4,puVar7,uVar6);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + -4))(piVar4,3);
      }
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0050d9d4(puVar1 + 0xb,2);
      FUN_0050d9d4(puVar1 + 10,2);
      FUN_0050d9d4(puVar1 + 9,2);
      FUN_0050d9d4(puVar1 + 8,2);
      FUN_0050d9d4(puVar1 + 7,2);
      FUN_0050d9d4(puVar1 + 6,2);
      FUN_0050d9d4(puVar1 + 5,2);
      FUN_0050d9d4(puVar1 + 4,2);
      FUN_0050d9d4(puVar1 + 3,2);
      FUN_0050d9d4(puVar1 + 2,2);
      FUN_0050d9d4(puVar1 + 1,2);
      FUN_00502074();
    }
    iStack_1d8 = iStack_1d8 + 1;
  } while (iStack_1d8 < 0x68);
  FUN_0050d9d4((int *)&puStack_c,2);
  FUN_0050d9d4(&iStack_8,2);
  *in_FS_OFFSET = uStack_1c4;
  return;
}



// Preserved published name: CppWebBrowser1BeforeNavigate2
// Entry 0041a440, recovered name Published_CppWebBrowser1BeforeNavigate2_0041a440

void Published_CppWebBrowser1BeforeNavigate2_0041a440
               (int param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  undefined2 *puVar4;
  VARIANTARG *pVVar5;
  BSTR pOVar6;
  undefined4 *in_FS_OFFSET;
  VARIANTARG *in_stack_00000018;
  undefined2 local_fc [4];
  undefined2 local_f4 [4];
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  int local_e0;
  undefined4 local_dc;
  undefined2 local_cc;
  int local_c0;
  VARIANTARG local_b8;
  VARIANTARG local_a8;
  VARIANTARG local_98;
  VARIANTARG local_88;
  OLECHAR local_78;
  int local_74;
  int local_70;
  VARIANTARG local_6c;
  VARIANTARG local_5c;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  OLECHAR local_2c;
  int local_28;
  int local_24;
  int local_20;
  VARIANTARG local_1c;
  int local_c;
  undefined *local_8;
  
  local_e8 = param_3;
  local_e4 = param_2;
  local_e0 = param_1;
  FUN_00502f50(0x517a74);
  local_cc = 8;
  FUN_004016bc(&local_8);
  local_c0 = local_c0 + 1;
  local_cc = 0x20;
  FUN_004016bc(&local_c);
  local_c0 = local_c0 + 1;
  local_cc = 0x2c;
  piVar2 = FUN_004016bc(&local_20);
  local_c0 = local_c0 + 1;
  FUN_0050def8(&local_1c,in_stack_00000018);
  local_c0 = local_c0 + 1;
  FUN_00500df0(&local_1c,piVar2);
  FUN_0050da04((int *)&local_8,&local_20);
  local_c0 = local_c0 + -1;
  FUN_0050d9d4(&local_20,2);
  local_c0 = local_c0 + -1;
  FUN_0050e004(&local_1c,2);
  bVar1 = FUN_00418e14(local_e0,local_8);
  if (bVar1) {
    local_ec = FUN_00418ec8(local_e0,local_8);
    uVar3 = FUN_004195fc(local_e0,local_ec);
    if ((char)uVar3 != '\0') {
      puVar4 = FUN_0041a8e4(local_f4,'\x01');
      FUN_0041a914(param_4,puVar4);
      pVVar5 = FUN_004037cc(&local_4c);
      local_c0 = local_c0 + 2;
      FUN_00403810(pVVar5);
      pVVar5 = FUN_004037cc(&local_5c);
      local_c0 = local_c0 + 2;
      FUN_00403810(pVVar5);
      pVVar5 = FUN_004037cc(&local_6c);
      local_c0 = local_c0 + 2;
      FUN_00403810(pVVar5);
      local_cc = 0x38;
      piVar2 = FUN_004016bc(&local_28);
      local_c0 = local_c0 + 1;
      FUN_0050d87c(&local_24);
      local_c0 = local_c0 + 1;
      FUN_0050da18((undefined4 *)PTR__tempdir_005337e8,&local_24,piVar2);
      pOVar6 = FUN_0050e2a8(&local_2c);
      local_c0 = local_c0 + 1;
      FUN_00404d4c(pOVar6);
      pVVar5 = FUN_004037cc(&local_3c);
      local_c0 = local_c0 + 2;
      FUN_00403810(pVVar5);
      _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
                (*(int **)(local_e0 + 0x208));
      local_c0 = local_c0 + -2;
      FUN_004038c8(&local_6c,2);
      local_c0 = local_c0 + -2;
      FUN_004038c8(&local_5c,2);
      local_c0 = local_c0 + -2;
      FUN_004038c8(&local_4c,2);
      local_c0 = local_c0 + -2;
      FUN_004038c8(&local_3c,2);
      local_c0 = local_c0 + -1;
      FUN_0050e31c(&local_2c,2);
      local_c0 = local_c0 + -1;
      FUN_0050d9d4(&local_28,2);
      local_c0 = local_c0 + -1;
      FUN_0050d9d4(&local_24,2);
    }
  }
  else {
    bVar1 = FUN_00418fc8(local_e0,local_8);
    if (bVar1) {
      local_cc = 0x44;
      piVar2 = FUN_004016bc(&local_70);
      local_c0 = local_c0 + 1;
      FUN_0041907c(local_e0,local_8,piVar2);
      FUN_0050da04(&local_c,&local_70);
      local_c0 = local_c0 + -1;
      FUN_0050d9d4(&local_70,2);
      puVar4 = FUN_0041a8e4(local_fc,'\x01');
      FUN_0041a914(param_4,puVar4);
      pVVar5 = FUN_004037cc(&local_98);
      local_c0 = local_c0 + 2;
      FUN_00403810(pVVar5);
      pVVar5 = FUN_004037cc(&local_a8);
      local_c0 = local_c0 + 2;
      FUN_00403810(pVVar5);
      pVVar5 = FUN_004037cc(&local_b8);
      local_c0 = local_c0 + 2;
      FUN_00403810(pVVar5);
      local_cc = 0x50;
      piVar2 = FUN_004016bc(&local_74);
      local_c0 = local_c0 + 1;
      FUN_0050da18((undefined4 *)PTR__tempdir_005337e8,&local_c,piVar2);
      pOVar6 = FUN_0050e2a8(&local_78);
      local_c0 = local_c0 + 1;
      FUN_00404d4c(pOVar6);
      pVVar5 = FUN_004037cc(&local_88);
      local_c0 = local_c0 + 2;
      FUN_00403810(pVVar5);
      _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
                (*(int **)(local_e0 + 0x208));
      local_c0 = local_c0 + -2;
      FUN_004038c8(&local_b8,2);
      local_c0 = local_c0 + -2;
      FUN_004038c8(&local_a8,2);
      local_c0 = local_c0 + -2;
      FUN_004038c8(&local_98,2);
      local_c0 = local_c0 + -2;
      FUN_004038c8(&local_88,2);
      local_c0 = local_c0 + -1;
      FUN_0050e31c(&local_78,2);
      local_c0 = local_c0 + -1;
      FUN_0050d9d4(&local_74,2);
    }
  }
  local_c0 = local_c0 + -1;
  FUN_0050d9d4(&local_c,2);
  local_c0 = local_c0 + -1;
  FUN_0050d9d4((int *)&local_8,2);
  *in_FS_OFFSET = local_dc;
  return;
}



// Preserved published name: ADOQuery1elenumGetText
// Entry 0041ec28, recovered name Published_ADOQuery1elenumGetText_0041ec28

void Published_ADOQuery1elenumGetText_0041ec28(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_3c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x5197a0);
  piVar1 = FUN_0050d87c(&local_8);
  piVar1 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x54),(undefined *)*piVar1);
  puVar2 = FUN_004016bc(&local_c);
  (**(code **)(*piVar1 + 0x58))(piVar1,puVar2);
  piVar1 = FUN_004016bc(&local_10);
  FUN_0050dd80(&DAT_005192cb,&local_c,piVar1);
  piVar1 = FUN_004016bc(&local_18);
  FUN_0050d87c(&local_14);
  FUN_0050da18(&local_10,&local_14,piVar1);
  FUN_0050da04(param_3,&local_18);
  FUN_0050d9d4(&local_18,2);
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: linksmastervalueGetText
// Entry 0042155c, recovered name Published_linksmastervalueGetText_0042155c

void Published_linksmastervalueGetText_0042155c(int param_1,int *param_2,int *param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  PCNZCH pCVar4;
  int iVar5;
  int *piVar6;
  undefined4 *in_FS_OFFSET;
  undefined1 uStack00000004;
  undefined4 local_50;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined *local_8;
  
  FUN_00502f50(0x51a3e0);
  FUN_004016bc(&local_8);
  puVar2 = FUN_004016bc(&local_c);
  (**(code **)(*param_2 + 0x58))(param_2,puVar2);
  FUN_0050da04((int *)&local_8,&local_c);
  FUN_0050d9d4(&local_c,2);
  piVar3 = FUN_0050d988(&local_10);
  pCVar4 = FUN_004fa560((undefined *)*piVar3,local_8);
  FUN_0050d9d4(&local_10,2);
  piVar3 = FUN_004016bc(&local_14);
  iVar5 = FUN_00404394((int *)&local_8);
  FUN_0050dbd8((int *)&local_8,(int)(pCVar4 + 1),(iVar5 - (int)pCVar4) - 1,piVar3);
  FUN_0050da04(param_3,&local_14);
  FUN_0050d9d4(&local_14,2);
  piVar3 = FUN_0050d87c(&local_18);
  piVar3 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x88),(undefined *)*piVar3);
  puVar2 = FUN_004016bc(&local_1c);
  (**(code **)(*piVar3 + 0x58))(piVar3,puVar2);
  piVar3 = &local_1c;
  FUN_0050d87c(&local_20);
  bVar1 = FUN_0050daa4(piVar3,&local_20);
  FUN_0050d9d4(&local_20,2);
  FUN_0050d9d4(&local_1c,2);
  FUN_0050d9d4(&local_18,2);
  if (bVar1 != 0) {
    piVar3 = FUN_004016bc(&local_24);
    FUN_0050dd80(&DAT_005196f7,param_3,piVar3);
    piVar3 = &local_24;
    piVar6 = FUN_004016bc(&local_2c);
    FUN_0050d87c(&local_28);
    FUN_0050da18(piVar3,&local_28,piVar6);
    FUN_0050da04(param_3,&local_2c);
    FUN_0050d9d4(&local_2c,2);
    FUN_0050d9d4(&local_28,2);
    FUN_0050d9d4(&local_24,2);
  }
  uStack00000004 = 1;
  FUN_0050d9d4((int *)&local_8,2);
  *in_FS_OFFSET = local_50;
  return;
}



// Preserved published name: linksslavervalueGetText
// Entry 00421778, recovered name Published_linksslavervalueGetText_00421778

void Published_linksslavervalueGetText_00421778(int param_1,int *param_2,int *param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  PCNZCH pCVar4;
  int iVar5;
  int *piVar6;
  undefined4 *in_FS_OFFSET;
  undefined1 uStack00000004;
  undefined4 local_50;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined *local_8;
  
  FUN_00502f50(0x51a4dc);
  FUN_004016bc(&local_8);
  puVar2 = FUN_004016bc(&local_c);
  (**(code **)(*param_2 + 0x58))(param_2,puVar2);
  FUN_0050da04((int *)&local_8,&local_c);
  FUN_0050d9d4(&local_c,2);
  piVar3 = FUN_0050d988(&local_10);
  pCVar4 = FUN_004fa560((undefined *)*piVar3,local_8);
  FUN_0050d9d4(&local_10,2);
  piVar3 = FUN_004016bc(&local_14);
  iVar5 = FUN_00404394((int *)&local_8);
  FUN_0050dbd8((int *)&local_8,(int)(pCVar4 + 1),(iVar5 - (int)pCVar4) - 1,piVar3);
  FUN_0050da04(param_3,&local_14);
  FUN_0050d9d4(&local_14,2);
  piVar3 = FUN_0050d87c(&local_18);
  piVar3 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x88),(undefined *)*piVar3);
  puVar2 = FUN_004016bc(&local_1c);
  (**(code **)(*piVar3 + 0x58))(piVar3,puVar2);
  piVar3 = &local_1c;
  FUN_0050d87c(&local_20);
  bVar1 = FUN_0050daa4(piVar3,&local_20);
  FUN_0050d9d4(&local_20,2);
  FUN_0050d9d4(&local_1c,2);
  FUN_0050d9d4(&local_18,2);
  if (bVar1 != 0) {
    piVar3 = FUN_004016bc(&local_24);
    FUN_0050dd80(&DAT_00519716,param_3,piVar3);
    piVar3 = &local_24;
    piVar6 = FUN_004016bc(&local_2c);
    FUN_0050d87c(&local_28);
    FUN_0050da18(piVar3,&local_28,piVar6);
    FUN_0050da04(param_3,&local_2c);
    FUN_0050d9d4(&local_2c,2);
    FUN_0050d9d4(&local_28,2);
    FUN_0050d9d4(&local_24,2);
  }
  uStack00000004 = 1;
  FUN_0050d9d4((int *)&local_8,2);
  *in_FS_OFFSET = local_50;
  return;
}



// Preserved published name: DataModuleCreate
// Entry 00421994, recovered name Published_DataModuleCreate_00421994

void __stdcall Published_DataModuleCreate_00421994(void)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  OLECHAR OStack_8;
  
  FUN_00502f50(0x51a578);
  pOVar1 = FUN_0050e2a8(&OStack_8);
  FUN_00452b80(*(int **)(_DataModule1 + 0x50),(int *)*pOVar1);
  FUN_0050e31c(&OStack_8,2);
  (**(code **)(**(int **)(_DataModule1 + 0x50) + 0x48))(*(int **)(_DataModule1 + 0x50),1);
  *in_FS_OFFSET = uStack_30;
  return;
}



// Preserved published name: ComboBox1Change
// Entry 00423510, recovered name Published_ComboBox1Change_00423510

void Published_ComboBox1Change_00423510(int param_1)

{
  LPCWSTR pWVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  BSTR pOVar6;
  int iVar7;
  VARIANTARG *pVVar8;
  undefined4 *puVar9;
  undefined4 *in_FS_OFFSET;
  undefined4 local_98;
  int local_74;
  uint *local_70;
  int local_6c;
  int local_68;
  int local_64;
  uint *local_60;
  int local_5c;
  uint *local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  VARIANTARG local_34;
  OLECHAR local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51b4c8);
  FUN_004016bc(&local_8);
  piVar3 = FUN_004016bc(&local_c);
  FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar3);
  FUN_0050d87c(&local_10);
  bVar2 = FUN_0050dabc(&local_c,&local_10);
  if (bVar2) {
    piVar3 = FUN_004016bc(&local_14);
    FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar3);
    piVar3 = FUN_004016bc(&local_18);
    FUN_004233c8(param_1,local_14,piVar3);
    piVar3 = FUN_0050da04(&local_8,&local_18);
    FUN_0050d87c(&local_1c);
    bVar2 = FUN_0050dabc(piVar3,&local_1c);
    FUN_0050d9d4(&local_1c,2);
    FUN_0050d9d4(&local_18,2);
    FUN_0050d9d4(&local_14,2);
    if (bVar2) {
      bVar2 = true;
      goto LAB_00423640;
    }
  }
  bVar2 = false;
LAB_00423640:
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4(&local_c,2);
  if (bVar2) {
    piVar3 = FUN_0045cd80((int *)PTR_PTR_00450fc0,'\x01',(int *)0x0);
    (**(code **)(*piVar3 + 0x260))(piVar3,*(undefined4 *)(*(int *)PTR__DataModule1_005337f0 + 0x50))
    ;
    piVar4 = (int *)FUN_0045cef8((int)piVar3);
    (**(code **)(*piVar4 + 0x40))();
    piVar4 = (int *)FUN_0045cef8((int)piVar3);
    piVar5 = FUN_0050d87c(&local_20);
    (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
    FUN_0050d9d4(&local_20,2);
    pOVar6 = FUN_0050e234(&local_24);
    pWVar1 = (LPCWSTR)*pOVar6;
    iVar7 = FUN_0045b63c((int)piVar3);
    iVar7 = FUN_00453fcc(iVar7,pWVar1);
    pVVar8 = FUN_0050df38(&local_34,&local_8);
    FUN_00455258(iVar7,pVVar8);
    FUN_0050e004(&local_34,2);
    FUN_0050e31c(&local_24,2);
    FUN_0047a9d8(piVar3);
    iVar7 = (**(code **)(*piVar3 + 0x14c))();
    if (iVar7 < 1) {
      piVar3 = FUN_0050d87c(&local_74);
      FUN_004c6c30(*(int *)(param_1 + 0x24c),(uint *)*piVar3);
      FUN_0050d9d4(&local_74,2);
    }
    else {
      piVar4 = FUN_0050d87c(&local_38);
      FUN_004c6c30(*(int *)(param_1 + 0x24c),(uint *)*piVar4);
      FUN_0050d9d4(&local_38,2);
      (**(code **)(**(int **)(param_1 + 0x250) + 0xcc))();
      iVar7 = *(int *)(param_1 + 0x250);
      piVar4 = FUN_0050d87c(&local_3c);
      piVar4 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_40);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar9);
      piVar4 = *(int **)(iVar7 + 0x208);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_40);
      FUN_0050d9d4(&local_40,2);
      FUN_0050d9d4(&local_3c,2);
      (**(code **)(**(int **)(param_1 + 0x234) + 0xcc))();
      iVar7 = *(int *)(param_1 + 0x234);
      piVar4 = FUN_0050d87c(&local_44);
      piVar4 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_48);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar9);
      piVar4 = *(int **)(iVar7 + 0x208);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_48);
      FUN_0050d9d4(&local_48,2);
      FUN_0050d9d4(&local_44,2);
      (**(code **)(**(int **)(param_1 + 0x23c) + 0xcc))();
      iVar7 = *(int *)(param_1 + 0x23c);
      piVar4 = FUN_0050d87c(&local_4c);
      piVar4 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_50);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar9);
      piVar4 = *(int **)(iVar7 + 0x208);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_50);
      FUN_0050d9d4(&local_50,2);
      FUN_0050d9d4(&local_4c,2);
      piVar4 = FUN_0050d87c(&local_54);
      piVar4 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_58);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar9);
      FUN_004c6c30(*(int *)(param_1 + 0x220),local_58);
      FUN_0050d9d4((int *)&local_58,2);
      FUN_0050d9d4(&local_54,2);
      piVar4 = FUN_0050d87c(&local_5c);
      piVar4 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_60);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar9);
      FUN_004c6c30(*(int *)(param_1 + 0x224),local_60);
      FUN_0050d9d4((int *)&local_60,2);
      FUN_0050d9d4(&local_5c,2);
      (**(code **)(**(int **)(param_1 + 0x240) + 0xcc))();
      iVar7 = *(int *)(param_1 + 0x240);
      piVar4 = FUN_0050d87c(&local_64);
      piVar4 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_68);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar9);
      piVar4 = *(int **)(iVar7 + 0x208);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_68);
      FUN_0050d9d4(&local_68,2);
      FUN_0050d9d4(&local_64,2);
      piVar4 = FUN_0050d87c(&local_6c);
      piVar3 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_70);
      (**(code **)(*piVar3 + 0x58))(piVar3,puVar9);
      FUN_004c6c30(*(int *)(param_1 + 0x248),local_70);
      FUN_0050d9d4((int *)&local_70,2);
      FUN_0050d9d4(&local_6c,2);
    }
  }
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_98;
  return;
}



// Preserved published name: Button1Click
// Entry 00423c0c, recovered name Published_Button1Click_00423c0c

void Published_Button1Click_00423c0c(int param_1)

{
  LPCWSTR pWVar1;
  bool bVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  VARIANTARG *pVVar8;
  BSTR pOVar9;
  int iVar10;
  undefined4 *in_FS_OFFSET;
  undefined4 local_1ec;
  int local_1c8;
  int *local_1c4;
  int local_1c0;
  int local_1bc;
  VARIANTARG local_1b8;
  int local_1a8;
  int local_1a4;
  OLECHAR local_1a0;
  VARIANTARG local_19c;
  int local_18c;
  OLECHAR local_188;
  VARIANTARG local_184;
  int local_174;
  OLECHAR local_170;
  VARIANTARG local_16c;
  int local_15c;
  OLECHAR local_158;
  VARIANTARG local_154;
  int local_144;
  OLECHAR local_140;
  VARIANTARG local_13c;
  int local_12c;
  OLECHAR local_128;
  VARIANTARG local_124;
  int local_114;
  OLECHAR local_110;
  VARIANTARG local_10c;
  int local_fc;
  OLECHAR local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  VARIANTARG local_e4;
  int local_d4;
  OLECHAR local_d0;
  VARIANTARG local_cc;
  int local_bc;
  OLECHAR local_b8;
  VARIANTARG local_b4;
  int local_a4;
  OLECHAR local_a0;
  VARIANTARG local_9c;
  int local_8c;
  OLECHAR local_88;
  VARIANTARG local_84;
  int local_74;
  OLECHAR local_70;
  VARIANTARG local_6c;
  int local_5c;
  OLECHAR local_58;
  VARIANTARG local_54;
  int local_44;
  OLECHAR local_40;
  VARIANTARG local_3c;
  int local_2c;
  int local_28;
  OLECHAR local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51b8e8);
  piVar4 = FUN_004016bc(&local_8);
  FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar4);
  FUN_0050d87c(&local_c);
  bVar2 = FUN_0050dabc(&local_8,&local_c);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  if (bVar2) {
    iVar5 = *(int *)(param_1 + 0x21c);
    piVar4 = FUN_004016bc(&local_10);
    FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar4);
    piVar4 = *(int **)(iVar5 + 0x1f0);
    iVar5 = (**(code **)(*piVar4 + 0x50))(piVar4,local_10);
    FUN_0050d9d4(&local_10,2);
    piVar4 = FUN_0045cd80((int *)PTR_PTR_00450fc0,'\x01',(int *)0x0);
    (**(code **)(*piVar4 + 0x260))(piVar4,*(undefined4 *)(*(int *)PTR__DataModule1_005337f0 + 0x50))
    ;
    piVar6 = (int *)FUN_0045cef8((int)piVar4);
    (**(code **)(*piVar6 + 0x40))();
    piVar6 = FUN_004016bc(&local_14);
    FUN_004c6c00(*(int *)(param_1 + 0x24c),piVar6);
    FUN_0050d87c(&local_18);
    bVar3 = FUN_0050daa4(&local_14,&local_18);
    FUN_0050d9d4(&local_18,2);
    FUN_0050d9d4(&local_14,2);
    if (bVar3 == 0) {
      piVar6 = (int *)FUN_0045cef8((int)piVar4);
      piVar7 = FUN_0050d87c(&local_e8);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_e8,2);
      piVar6 = (int *)FUN_0045cef8((int)piVar4);
      piVar7 = FUN_0050d87c(&local_ec);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_ec,2);
      piVar6 = (int *)FUN_0045cef8((int)piVar4);
      piVar7 = FUN_0050d87c(&local_f0);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_f0,2);
      piVar6 = (int *)FUN_0045cef8((int)piVar4);
      piVar7 = FUN_0050d87c(&local_f4);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_f4,2);
      piVar6 = FUN_004016bc(&local_fc);
      FUN_004c6c00(*(int *)(param_1 + 0x220),piVar6);
      pVVar8 = FUN_0050df38(&local_10c,&local_fc);
      pOVar9 = FUN_0050e234(&local_f8);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_10c,2);
      FUN_0050d9d4(&local_fc,2);
      FUN_0050e31c(&local_f8,2);
      piVar6 = FUN_004016bc(&local_114);
      FUN_004c6c00(*(int *)(param_1 + 0x224),piVar6);
      pVVar8 = FUN_0050df38(&local_124,&local_114);
      pOVar9 = FUN_0050e234(&local_110);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_124,2);
      FUN_0050d9d4(&local_114,2);
      FUN_0050e31c(&local_110,2);
      piVar6 = FUN_004016bc(&local_12c);
      FUN_004c6c00(*(int *)(param_1 + 0x240),piVar6);
      pVVar8 = FUN_0050df38(&local_13c,&local_12c);
      pOVar9 = FUN_0050e234(&local_128);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_13c,2);
      FUN_0050d9d4(&local_12c,2);
      FUN_0050e31c(&local_128,2);
      piVar6 = FUN_004016bc(&local_144);
      FUN_004c6c00(*(int *)(param_1 + 0x248),piVar6);
      pVVar8 = FUN_0050df38(&local_154,&local_144);
      pOVar9 = FUN_0050e234(&local_140);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_154,2);
      FUN_0050d9d4(&local_144,2);
      FUN_0050e31c(&local_140,2);
      piVar6 = FUN_004016bc(&local_15c);
      FUN_004c6c00(*(int *)(param_1 + 0x250),piVar6);
      pVVar8 = FUN_0050df38(&local_16c,&local_15c);
      pOVar9 = FUN_0050e234(&local_158);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_16c,2);
      FUN_0050d9d4(&local_15c,2);
      FUN_0050e31c(&local_158,2);
      piVar6 = FUN_004016bc(&local_174);
      FUN_004c6c00(*(int *)(param_1 + 0x234),piVar6);
      pVVar8 = FUN_0050df38(&local_184,&local_174);
      pOVar9 = FUN_0050e234(&local_170);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_184,2);
      FUN_0050d9d4(&local_174,2);
      FUN_0050e31c(&local_170,2);
      piVar6 = FUN_004016bc(&local_18c);
      FUN_004c6c00(*(int *)(param_1 + 0x23c),piVar6);
      pVVar8 = FUN_0050df38(&local_19c,&local_18c);
      pOVar9 = FUN_0050e234(&local_188);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_19c,2);
      FUN_0050d9d4(&local_18c,2);
      FUN_0050e31c(&local_188,2);
      piVar6 = FUN_004016bc(&local_1a4);
      FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar6);
      piVar6 = FUN_004016bc(&local_1a8);
      FUN_004233c8(param_1,local_1a4,piVar6);
      pVVar8 = FUN_0050df38(&local_1b8,&local_1a8);
      pOVar9 = FUN_0050e234(&local_1a0);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_1b8,2);
      FUN_0050d9d4(&local_1a8,2);
      FUN_0050d9d4(&local_1a4,2);
      FUN_0050e31c(&local_1a0,2);
      FUN_0045ce2c((int)piVar4);
      piVar6 = FUN_0050d87c(&local_1bc);
      FUN_004c6c30(*(int *)(param_1 + 0x24c),(uint *)*piVar6);
      FUN_0050d9d4(&local_1bc,2);
    }
    else {
      piVar6 = (int *)FUN_0045cef8((int)piVar4);
      piVar7 = FUN_0050d87c(&local_1c);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_1c,2);
      piVar6 = (int *)FUN_0045cef8((int)piVar4);
      piVar7 = FUN_0050d87c(&local_20);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_20,2);
      piVar6 = FUN_004016bc(&local_28);
      FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar6);
      piVar6 = FUN_004016bc(&local_2c);
      FUN_004233c8(param_1,local_28,piVar6);
      pVVar8 = FUN_0050df38(&local_3c,&local_2c);
      pOVar9 = FUN_0050e234(&local_24);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_3c,2);
      FUN_0050d9d4(&local_2c,2);
      FUN_0050d9d4(&local_28,2);
      FUN_0050e31c(&local_24,2);
      piVar6 = FUN_004016bc(&local_44);
      FUN_004c6c00(*(int *)(param_1 + 0x220),piVar6);
      pVVar8 = FUN_0050df38(&local_54,&local_44);
      pOVar9 = FUN_0050e234(&local_40);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_54,2);
      FUN_0050d9d4(&local_44,2);
      FUN_0050e31c(&local_40,2);
      piVar6 = FUN_004016bc(&local_5c);
      FUN_004c6c00(*(int *)(param_1 + 0x224),piVar6);
      pVVar8 = FUN_0050df38(&local_6c,&local_5c);
      pOVar9 = FUN_0050e234(&local_58);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_6c,2);
      FUN_0050d9d4(&local_5c,2);
      FUN_0050e31c(&local_58,2);
      piVar6 = FUN_004016bc(&local_74);
      FUN_004c6c00(*(int *)(param_1 + 0x240),piVar6);
      pVVar8 = FUN_0050df38(&local_84,&local_74);
      pOVar9 = FUN_0050e234(&local_70);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_84,2);
      FUN_0050d9d4(&local_74,2);
      FUN_0050e31c(&local_70,2);
      piVar6 = FUN_004016bc(&local_8c);
      FUN_004c6c00(*(int *)(param_1 + 0x248),piVar6);
      pVVar8 = FUN_0050df38(&local_9c,&local_8c);
      pOVar9 = FUN_0050e234(&local_88);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_9c,2);
      FUN_0050d9d4(&local_8c,2);
      FUN_0050e31c(&local_88,2);
      piVar6 = FUN_004016bc(&local_a4);
      FUN_004c6c00(*(int *)(param_1 + 0x250),piVar6);
      pVVar8 = FUN_0050df38(&local_b4,&local_a4);
      pOVar9 = FUN_0050e234(&local_a0);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_b4,2);
      FUN_0050d9d4(&local_a4,2);
      FUN_0050e31c(&local_a0,2);
      piVar6 = FUN_004016bc(&local_bc);
      FUN_004c6c00(*(int *)(param_1 + 0x234),piVar6);
      pVVar8 = FUN_0050df38(&local_cc,&local_bc);
      pOVar9 = FUN_0050e234(&local_b8);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_cc,2);
      FUN_0050d9d4(&local_bc,2);
      FUN_0050e31c(&local_b8,2);
      piVar6 = FUN_004016bc(&local_d4);
      FUN_004c6c00(*(int *)(param_1 + 0x23c),piVar6);
      pVVar8 = FUN_0050df38(&local_e4,&local_d4);
      pOVar9 = FUN_0050e234(&local_d0);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_e4,2);
      FUN_0050d9d4(&local_d4,2);
      FUN_0050e31c(&local_d0,2);
      FUN_0045ce2c((int)piVar4);
    }
    FUN_0042329c(param_1);
    FUN_0048df0c(*(int **)(param_1 + 0x21c),iVar5 + 1);
    (**(code **)(*(int *)(param_1 + 0x21c) + 0x230))
              (*(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x234),0);
    if (piVar4 != (int *)0x0) {
      local_1c0 = *piVar4;
      local_1c4 = piVar4;
      (**(code **)(*piVar4 + -4))(piVar4,3);
    }
  }
  else {
    piVar4 = FUN_0050d87c(&local_1c8);
    FUN_004c1c04((undefined *)*piVar4);
    FUN_0050d9d4(&local_1c8,2);
    (**(code **)(**(int **)(param_1 + 0x21c) + 0xb0))();
  }
  *in_FS_OFFSET = local_1ec;
  return;
}



// Preserved published name: MySpeedButtonClick
// Entry 00424c98, recovered name Published_MySpeedButtonClick_00424c98

void Published_MySpeedButtonClick_00424c98(undefined4 param_1,int *param_2)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 local_3d;
  undefined4 *local_3c;
  int *local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_1c;
  int local_10;
  int local_8;
  
  local_34 = param_2;
  local_30 = param_1;
  FUN_00502f50(0x51ba5c);
  local_38 = FUN_005038a4(local_34,(int)PTR_PTR_004efd4c);
  if ((local_38 != (int *)0x0) && (DAT_005342fc != 0)) {
    local_1c = 8;
    piVar1 = FUN_004016bc(&local_8);
    local_10 = local_10 + 1;
    FUN_004c6c00((int)local_38,piVar1);
    FUN_0050da04((int *)&DAT_0051aecc,&local_8);
    local_10 = local_10 + -1;
    FUN_0050d9d4(&local_8,2);
    local_3c = (undefined4 *)(DAT_005342fc + 0x1b8);
    local_3d = 0;
    (*(code *)*local_3c)(*(undefined4 *)(DAT_005342fc + 0x1bc),DAT_005342fc,&local_3d);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: MyMemoKeyPress
// Entry 00424d40, recovered name Published_MyMemoKeyPress_00424d40

void Published_MyMemoKeyPress_00424d40(undefined4 param_1,int *param_2,undefined1 *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51ba90);
  FUN_0050d87c(&local_8);
  bVar1 = FUN_0050dabc((undefined4 *)&DAT_0051aecc,&local_8);
  FUN_0050d9d4(&local_8,2);
  if (bVar1) {
    piVar2 = FUN_005038a4(param_2,(int)PTR_PTR_00488d54);
    if (piVar2 != (int *)0x0) {
      puVar3 = FUN_00404374((int *)&DAT_0051aecc);
      FUN_0048cdd0(piVar2,(LPARAM)puVar3);
      *param_3 = 0;
    }
    FUN_0050d87c(&local_c);
    FUN_0050da04((int *)&DAT_0051aecc,&local_c);
    FUN_0050d9d4(&local_c,2);
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: ComboBox1Enter
// Entry 00424e04, recovered name Published_ComboBox1Enter_00424e04

void __stdcall Published_ComboBox1Enter_00424e04(void)

{
  DAT_005342fc = 0;
  return;
}



// Preserved published name: Memo4Enter
// Entry 00424e1c, recovered name Published_Memo4Enter_00424e1c

void Published_Memo4Enter_00424e1c(undefined4 param_1,int *param_2)

{
  DAT_005342fc = FUN_005038a4(param_2,(int)PTR_PTR_00488d54);
  return;
}



// Preserved published name: FormCreate
// Entry 0042636c, recovered name Published_FormCreate_0042636c

void Published_FormCreate_0042636c(int param_1)

{
  FUN_004233a4(*(int *)(param_1 + 0x2f8));
  FUN_00428438(*(int *)(param_1 + 0x2f0));
  return;
}



// Preserved published name: PageControl2Change
// Entry 00426398, recovered name Published_PageControl2Change_00426398

void Published_PageControl2Change_00426398(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004d9b90(*(int *)(param_1 + 0x2d0));
  if (iVar1 == 1) {
    FUN_0047a9e4(*(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88));
    FUN_0047a9d8(*(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88));
  }
  return;
}



// Preserved published name: FormShow
// Entry 004263e0, recovered name Published_FormShow_004263e0

void Published_FormShow_004263e0(int param_1)

{
  FUN_004233a4(*(int *)(param_1 + 0x2f8));
  FUN_00428438(*(int *)(param_1 + 0x2f0));
  return;
}



// Preserved published name: Button2Click
// Entry 00426564, recovered name Published_Button2Click_00426564

void Published_Button2Click_00426564(int param_1)

{
  char cVar1;
  int *piVar2;
  PCNZCH pCVar3;
  int *piVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51c81c);
  FUN_004016bc(&local_8);
  cVar1 = (**(code **)(**(int **)(param_1 + 0x2ec) + 0x3c))();
  if (cVar1 != '\0') {
    piVar2 = FUN_004016bc(&local_c);
    FUN_004c119c(*(int *)(param_1 + 0x2ec),piVar2);
    FUN_0050d87c(&local_10);
    pCVar3 = FUN_0050dd0c();
    cVar1 = 0 < (int)pCVar3;
    FUN_0050d9d4(&local_10,2);
    FUN_0050d9d4(&local_c,2);
    if (cVar1 == '\0') {
      piVar2 = FUN_004016bc(&local_1c);
      FUN_004c119c(*(int *)(param_1 + 0x2ec),piVar2);
      FUN_0050da04(&local_8,&local_1c);
      FUN_0050d9d4(&local_1c,2);
    }
    else {
      piVar2 = FUN_004016bc(&local_18);
      piVar4 = FUN_004016bc(&local_14);
      FUN_004c119c(*(int *)(param_1 + 0x2ec),piVar4);
      FUN_0050dbd8(&local_14,0,(uint)(pCVar3 + -1),piVar2);
      FUN_0050da04(&local_8,&local_18);
      FUN_0050d9d4(&local_18,2);
      FUN_0050d9d4(&local_14,2);
    }
    piVar2 = FUN_004016bc(&local_24);
    FUN_0050d87c(&local_20);
    FUN_0050da18(&local_8,&local_20,piVar2);
    FUN_0050da04(&local_8,&local_24);
    FUN_0050d9d4(&local_24,2);
    FUN_0050d9d4(&local_20,2);
    piVar2 = *(int **)(*(int *)(param_1 + 0x2d0) + 0x208);
    (**(code **)(*piVar2 + 100))(piVar2,local_8);
  }
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: Button3Click
// Entry 00426750, recovered name Published_Button3Click_00426750

void Published_Button3Click_00426750(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x51c87c);
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2e8) + 0x3c))();
  if (cVar2 != '\0') {
    (**(code **)(**(int **)(param_1 + 0x2d0) + 0xcc))();
    iVar1 = *(int *)(param_1 + 0x2d0);
    piVar3 = FUN_004016bc(&local_8);
    FUN_004c119c(*(int *)(param_1 + 0x2e8),piVar3);
    piVar3 = *(int **)(iVar1 + 0x208);
    (**(code **)(*piVar3 + 0x58))(piVar3,local_8);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: Button1Click
// Entry 004267e8, recovered name Published_Button1Click_004267e8

void Published_Button1Click_004267e8(int param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  PCNZCH pCVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_4c;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51c94c);
  FUN_0047a9e4(*(int **)(param_1 + 0x2f0));
  piVar2 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x2f0));
  (**(code **)(*piVar2 + 0x40))();
  piVar2 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x2f0));
  piVar3 = FUN_004016bc(&local_8);
  FUN_004c6c00(*(int *)(param_1 + 0x2d0),piVar3);
  (**(code **)(*piVar2 + 0x34))(piVar2,local_8);
  FUN_0050d9d4(&local_8,2);
  piVar2 = FUN_004016bc(&local_c);
  FUN_004c6c00(*(int *)(param_1 + 0x2d0),piVar2);
  FUN_0050d87c(&local_10);
  pCVar4 = FUN_0050dd0c();
  if ((int)pCVar4 < 1) {
    piVar2 = FUN_004016bc(&local_14);
    FUN_004c6c00(*(int *)(param_1 + 0x2d0),piVar2);
    FUN_0050d87c(&local_18);
    pCVar4 = FUN_0050dd0c();
    FUN_0050d9d4(&local_18,2);
    FUN_0050d9d4(&local_14,2);
    if ((int)pCVar4 < 1) {
      piVar2 = FUN_004016bc(&local_1c);
      FUN_004c6c00(*(int *)(param_1 + 0x2d0),piVar2);
      FUN_0050d87c(&local_20);
      pCVar4 = FUN_0050dd0c();
      FUN_0050d9d4(&local_20,2);
      FUN_0050d9d4(&local_1c,2);
      if ((int)pCVar4 < 1) {
        bVar1 = false;
        goto LAB_00426992;
      }
    }
  }
  bVar1 = true;
LAB_00426992:
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4(&local_c,2);
  if (bVar1) {
    FUN_0045ce2c(*(int *)(param_1 + 0x2f0));
  }
  else {
    FUN_0047a9d8(*(int **)(param_1 + 0x2f0));
  }
  *in_FS_OFFSET = local_4c;
  return;
}



// Preserved published name: Button4Click
// Entry 00426a78, recovered name Published_Button4Click_00426a78

void Published_Button4Click_00426a78(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  undefined *local_c;
  int local_8;
  
  FUN_00502f50(0x51c9b8);
  piVar1 = FUN_0050d87c(&local_8);
  piVar1 = (int *)FUN_0047b6a8(*(int *)(*(int *)PTR__DataModule1_005337f0 + 0x54),
                               (undefined *)*piVar1);
  puVar2 = FUN_004016bc(&local_c);
  (**(code **)(*piVar1 + 0x58))(piVar1,puVar2,*piVar1,piVar1,param_2,param_1);
  FUN_004c1c04(local_c);
  FUN_0050d9d4((int *)&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: Button5Click
// Entry 00426b08, recovered name Published_Button5Click_00426b08

void Published_Button5Click_00426b08(int param_1)

{
  LPCWSTR pWVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  VARIANTARG *pVVar8;
  BSTR pOVar9;
  int iVar10;
  undefined4 *in_FS_OFFSET;
  int local_6c;
  undefined4 local_58;
  VARIANTARG local_24;
  int local_14;
  OLECHAR local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51ca54);
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2e8) + 0x3c))();
  if (cVar2 != '\0') {
    piVar3 = (int *)FUN_004016ec((int *)PTR_PTR_004e6d4c,'\x01');
    piVar4 = FUN_004016bc(&local_8);
    FUN_004c119c(*(int *)(param_1 + 0x2e8),piVar4);
    (**(code **)(*piVar3 + 0x58))(piVar3,local_8);
    FUN_0050d9d4(&local_8,2);
    piVar4 = FUN_0045cd80((int *)PTR_PTR_00450fc0,'\x01',(int *)0x0);
    (**(code **)(*piVar4 + 0x260))(piVar4,*(undefined4 *)(*(int *)PTR__DataModule1_005337f0 + 0x50))
    ;
    piVar5 = (int *)FUN_0045cef8((int)piVar4);
    piVar6 = FUN_0050d87c(&local_c);
    (**(code **)(*piVar5 + 0x34))(piVar5,*piVar6);
    FUN_0050d9d4(&local_c,2);
    local_6c = 0;
    while( true ) {
      iVar10 = (**(code **)(*piVar3 + 0x14))();
      if (iVar10 <= local_6c) break;
      FUN_0047a9e4(piVar4);
      puVar7 = FUN_004016bc(&local_14);
      (**(code **)(*piVar3 + 0xc))(piVar3,local_6c,puVar7);
      pVVar8 = FUN_0050df38(&local_24,&local_14);
      pOVar9 = FUN_0050e234(&local_10);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar10 = FUN_0045b63c((int)piVar4);
      iVar10 = FUN_00453fcc(iVar10,pWVar1);
      FUN_00455258(iVar10,pVVar8);
      FUN_0050e004(&local_24,2);
      FUN_0050d9d4(&local_14,2);
      FUN_0050e31c(&local_10,2);
      FUN_0045ce2c((int)piVar4);
      local_6c = local_6c + 1;
    }
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + -4))(piVar3,3);
    }
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + -4))(piVar4,3);
    }
  }
  *in_FS_OFFSET = local_58;
  return;
}



// Preserved published name: ListBox1MouseMove
// Entry 00426ec8, recovered name Published_ListBox1MouseMove_00426ec8

void Published_ListBox1MouseMove_00426ec8
               (int param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  char *pcVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *in_FS_OFFSET;
  POINT local_4c;
  int local_44;
  undefined1 local_3d;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined2 local_24;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  local_3d = param_3;
  local_3c = param_2;
  local_38 = param_1;
  FUN_00502f50(0x51cdc4);
  local_24 = 8;
  FUN_004016bc(&local_8);
  local_18 = local_18 + 1;
  local_24 = 0x14;
  FUN_004e76b0(param_5,param_4,&local_4c.x);
  local_44 = FUN_0048fef4(*(int **)(local_38 + 0x218),&local_4c,'\x01');
  if (local_44 != -1) {
    local_24 = 0x20;
    iVar1 = *(int *)(local_38 + 0x218);
    puVar3 = FUN_004016bc(&local_c);
    local_18 = local_18 + 1;
    piVar6 = *(int **)(iVar1 + 0x1f0);
    (**(code **)(*piVar6 + 0xc))(piVar6,local_44,puVar3);
    FUN_0050da04(&local_8,&local_c);
    local_18 = local_18 + -1;
    FUN_0050d9d4(&local_c,2);
    bVar2 = FUN_0050dabc(&local_8,(undefined4 *)(*(int *)(local_38 + 0x218) + 0x70));
    if (bVar2) {
      pcVar4 = FUN_00404374(&local_8);
      uVar5 = FUN_004f6e20(pcVar4);
      if (uVar5 < 0x2a) {
        local_24 = 0x2c;
        piVar6 = FUN_0050d87c(&local_10);
        local_18 = local_18 + 1;
        FUN_0050da04((int *)(*(int *)(local_38 + 0x218) + 0x70),piVar6);
        local_18 = local_18 + -1;
        FUN_0050d9d4(&local_10,2);
      }
      else {
        FUN_0050da04((int *)(*(int *)(local_38 + 0x218) + 0x70),&local_8);
      }
    }
  }
  local_18 = local_18 + -1;
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_34;
  return;
}



// Preserved published name: ListBox1Click
// Entry 004271cc, recovered name Published_ListBox1Click_004271cc

void __stdcall Published_ListBox1Click_004271cc(void)

{
  return;
}



// Preserved published name: Button1Click
// Entry 004271dc, recovered name Published_Button1Click_004271dc

void Published_Button1Click_004271dc(int param_1)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_4c;
  uint *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined *local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51cf58);
  piVar2 = FUN_0050d87c(&local_8);
  FUN_004da1a8(*(int **)(param_1 + 0x230),(uint *)*piVar2);
  FUN_0050d9d4(&local_8,2);
  (**(code **)(*DAT_0051cd24 + 0x40))();
  FUN_00427010(param_1,DAT_0051cd24);
  piVar2 = FUN_004016bc(&local_14);
  FUN_004c6c00(*(int *)(param_1 + 0x220),piVar2);
  piVar2 = &local_14;
  FUN_0050d87c(&local_18);
  bVar1 = FUN_0050daa4(piVar2,&local_18);
  piVar2 = DAT_0051cd24;
  piVar3 = FUN_004016bc(&local_10);
  FUN_004c6c00(*(int *)(param_1 + 0x228),piVar3);
  piVar3 = FUN_004016bc(&local_c);
  FUN_004c6c00(*(int *)(param_1 + 0x210),piVar3);
  _FindStr_qqri17System_AnsiStringt2op19Classes_TStringList(0,local_c,local_10,piVar2,bVar1);
  FUN_0050d9d4(&local_18,2);
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4((int *)&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_00427010(param_1,DAT_0051cd24);
  piVar2 = FUN_004016bc(&local_1c);
  uVar4 = (**(code **)(*DAT_0051cd24 + 0x14))();
  FUN_004f6a10(uVar4,piVar2);
  piVar2 = &local_1c;
  piVar3 = FUN_004016bc(&local_20);
  FUN_0050dd80(&DAT_0051cd50,piVar2,piVar3);
  piVar2 = &local_20;
  piVar3 = FUN_004016bc(&local_28);
  FUN_0050d87c(&local_24);
  FUN_0050da18(piVar2,&local_24,piVar3);
  FUN_004da1a8(*(int **)(param_1 + 0x230),local_28);
  FUN_0050d9d4((int *)&local_28,2);
  FUN_0050d9d4(&local_24,2);
  FUN_0050d9d4(&local_20,2);
  FUN_0050d9d4(&local_1c,2);
  *in_FS_OFFSET = local_4c;
  return;
}



// Preserved published name: Edit1Exit
// Entry 004275a8, recovered name Published_Edit1Exit_004275a8

void Published_Edit1Exit_004275a8(int param_1)

{
  LPCWSTR pWVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  VARIANTARG *pVVar6;
  BSTR pOVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *in_FS_OFFSET;
  undefined4 local_68;
  int local_44;
  int local_40;
  uint *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  VARIANTARG local_28;
  int local_18;
  OLECHAR local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51d3f8);
  piVar3 = FUN_004016bc(&local_8);
  FUN_004c6c00(*(int *)(param_1 + 0x20c),piVar3);
  FUN_0050d87c(&local_c);
  bVar2 = FUN_0050dabc(&local_8,&local_c);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  if (bVar2) {
    piVar3 = FUN_0045cd80((int *)PTR_PTR_00450fc0,'\x01',(int *)0x0);
    (**(code **)(*piVar3 + 0x260))(piVar3,*(undefined4 *)(*(int *)PTR__DataModule1_005337f0 + 0x50))
    ;
    piVar4 = (int *)FUN_0045cef8((int)piVar3);
    (**(code **)(*piVar4 + 0x40))();
    piVar4 = (int *)FUN_0045cef8((int)piVar3);
    piVar5 = FUN_0050d87c(&local_10);
    (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
    FUN_0050d9d4(&local_10,2);
    piVar4 = FUN_004016bc(&local_18);
    FUN_004c6c00(*(int *)(param_1 + 0x20c),piVar4);
    pVVar6 = FUN_0050df38(&local_28,&local_18);
    pOVar7 = FUN_0050e234(&local_14);
    pWVar1 = (LPCWSTR)*pOVar7;
    iVar8 = FUN_0045b63c((int)piVar3);
    iVar8 = FUN_00453fcc(iVar8,pWVar1);
    FUN_00455258(iVar8,pVVar6);
    FUN_0050e004(&local_28,2);
    FUN_0050d9d4(&local_18,2);
    FUN_0050e31c(&local_14,2);
    FUN_0047a9d8(piVar3);
    iVar8 = (**(code **)(*piVar3 + 0x14c))();
    if (iVar8 < 1) {
      piVar3 = FUN_0050d87c(&local_40);
      FUN_004c6c30(*(int *)(param_1 + 0x24c),(uint *)*piVar3);
      FUN_0050d9d4(&local_40,2);
    }
    else {
      piVar4 = FUN_0050d87c(&local_2c);
      FUN_004c6c30(*(int *)(param_1 + 0x24c),(uint *)*piVar4);
      FUN_0050d9d4(&local_2c,2);
      (**(code **)(**(int **)(param_1 + 0x21c) + 0xcc))();
      iVar8 = *(int *)(param_1 + 0x21c);
      piVar4 = FUN_0050d87c(&local_30);
      piVar4 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_34);
      (**(code **)(*piVar4 + 0x58))(piVar4,puVar9);
      piVar4 = *(int **)(iVar8 + 0x208);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_34);
      FUN_0050d9d4(&local_34,2);
      FUN_0050d9d4(&local_30,2);
      piVar4 = FUN_0050d87c(&local_38);
      piVar3 = (int *)FUN_0047b6a8((int)piVar3,(undefined *)*piVar4);
      puVar9 = FUN_004016bc(&local_3c);
      (**(code **)(*piVar3 + 0x58))(piVar3,puVar9);
      FUN_004c6c30(*(int *)(param_1 + 0x214),local_3c);
      FUN_0050d9d4((int *)&local_3c,2);
      FUN_0050d9d4(&local_38,2);
    }
  }
  else {
    FUN_00428224(param_1);
    piVar3 = FUN_0050d87c(&local_44);
    FUN_004c6c30(*(int *)(param_1 + 0x24c),(uint *)*piVar3);
    FUN_0050d9d4(&local_44,2);
  }
  *in_FS_OFFSET = local_68;
  return;
}



// Preserved published name: MySpeedButtonClick
// Entry 004278f4, recovered name Published_MySpeedButtonClick_004278f4

void Published_MySpeedButtonClick_004278f4(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51d480);
  piVar1 = FUN_005038a4(param_2,(int)PTR_PTR_004efd4c);
  if (piVar1 != (int *)0x0) {
    if ((char)piVar1[0x4c] == '\0') {
      FUN_0050d87c(&local_c);
      FUN_0050da04((int *)&DAT_0051d1a0,&local_c);
      FUN_0050d9d4(&local_c,2);
    }
    else {
      piVar2 = FUN_004016bc(&local_8);
      FUN_004c6c00((int)piVar1,piVar2);
      FUN_0050da04((int *)&DAT_0051d1a0,&local_8);
      FUN_0050d9d4(&local_8,2);
    }
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: MyMemoKeyPress
// Entry 004279a8, recovered name Published_MyMemoKeyPress_004279a8

void Published_MyMemoKeyPress_004279a8(undefined4 param_1,int *param_2,undefined1 *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x51d4b0);
  FUN_0050d87c(&local_8);
  bVar1 = FUN_0050dabc((undefined4 *)&DAT_0051d1a0,&local_8);
  FUN_0050d9d4(&local_8,2);
  if (bVar1) {
    piVar2 = FUN_005038a4(param_2,(int)PTR_PTR_00488d54);
    if (piVar2 != (int *)0x0) {
      puVar3 = FUN_00404374((int *)&DAT_0051d1a0);
      FUN_0048cdd0(piVar2,(LPARAM)puVar3);
      *param_3 = 0;
    }
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: Button1Click
// Entry 00427a38, recovered name Published_Button1Click_00427a38

void Published_Button1Click_00427a38(int param_1)

{
  LPCWSTR pWVar1;
  bool bVar2;
  byte bVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  VARIANTARG *pVVar7;
  BSTR pOVar8;
  int iVar9;
  undefined4 *in_FS_OFFSET;
  undefined4 local_ec;
  int local_c8;
  int *local_c4;
  int local_c0;
  int local_bc;
  VARIANTARG local_b8;
  int local_a8;
  OLECHAR local_a4;
  VARIANTARG local_a0;
  int local_90;
  OLECHAR local_8c;
  VARIANTARG local_88;
  int local_78;
  OLECHAR local_74;
  int local_70;
  int local_6c;
  int local_68;
  VARIANTARG local_64;
  int local_54;
  OLECHAR local_50;
  VARIANTARG local_4c;
  int local_3c;
  OLECHAR local_38;
  VARIANTARG local_34;
  int local_24;
  OLECHAR local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51d66c);
  piVar4 = FUN_004016bc(&local_8);
  FUN_004c6c00(*(int *)(param_1 + 0x20c),piVar4);
  FUN_0050d87c(&local_c);
  bVar2 = FUN_0050dabc(&local_8,&local_c);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  if (bVar2) {
    piVar4 = FUN_0045cd80((int *)PTR_PTR_00450fc0,'\x01',(int *)0x0);
    (**(code **)(*piVar4 + 0x260))(piVar4,*(undefined4 *)(*(int *)PTR__DataModule1_005337f0 + 0x50))
    ;
    piVar5 = (int *)FUN_0045cef8((int)piVar4);
    (**(code **)(*piVar5 + 0x40))();
    piVar5 = FUN_004016bc(&local_10);
    FUN_004c6c00(*(int *)(param_1 + 0x24c),piVar5);
    FUN_0050d87c(&local_14);
    bVar3 = FUN_0050daa4(&local_10,&local_14);
    FUN_0050d9d4(&local_14,2);
    FUN_0050d9d4(&local_10,2);
    if (bVar3 == 0) {
      piVar5 = (int *)FUN_0045cef8((int)piVar4);
      piVar6 = FUN_0050d87c(&local_68);
      (**(code **)(*piVar5 + 0x34))(piVar5,*piVar6);
      FUN_0050d9d4(&local_68,2);
      piVar5 = (int *)FUN_0045cef8((int)piVar4);
      piVar6 = FUN_0050d87c(&local_6c);
      (**(code **)(*piVar5 + 0x34))(piVar5,*piVar6);
      FUN_0050d9d4(&local_6c,2);
      piVar5 = (int *)FUN_0045cef8((int)piVar4);
      piVar6 = FUN_0050d87c(&local_70);
      (**(code **)(*piVar5 + 0x34))(piVar5,*piVar6);
      FUN_0050d9d4(&local_70,2);
      piVar5 = FUN_004016bc(&local_78);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar5);
      pVVar7 = FUN_0050df38(&local_88,&local_78);
      pOVar8 = FUN_0050e234(&local_74);
      pWVar1 = (LPCWSTR)*pOVar8;
      iVar9 = FUN_0045b63c((int)piVar4);
      iVar9 = FUN_00453fcc(iVar9,pWVar1);
      FUN_00455258(iVar9,pVVar7);
      FUN_0050e004(&local_88,2);
      FUN_0050d9d4(&local_78,2);
      FUN_0050e31c(&local_74,2);
      piVar5 = FUN_004016bc(&local_90);
      FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar5);
      pVVar7 = FUN_0050df38(&local_a0,&local_90);
      pOVar8 = FUN_0050e234(&local_8c);
      pWVar1 = (LPCWSTR)*pOVar8;
      iVar9 = FUN_0045b63c((int)piVar4);
      iVar9 = FUN_00453fcc(iVar9,pWVar1);
      FUN_00455258(iVar9,pVVar7);
      FUN_0050e004(&local_a0,2);
      FUN_0050d9d4(&local_90,2);
      FUN_0050e31c(&local_8c,2);
      piVar5 = FUN_004016bc(&local_a8);
      FUN_004c6c00(*(int *)(param_1 + 0x20c),piVar5);
      pVVar7 = FUN_0050df38(&local_b8,&local_a8);
      pOVar8 = FUN_0050e234(&local_a4);
      pWVar1 = (LPCWSTR)*pOVar8;
      iVar9 = FUN_0045b63c((int)piVar4);
      iVar9 = FUN_00453fcc(iVar9,pWVar1);
      FUN_00455258(iVar9,pVVar7);
      FUN_0050e004(&local_b8,2);
      FUN_0050d9d4(&local_a8,2);
      FUN_0050e31c(&local_a4,2);
      FUN_0045ce2c((int)piVar4);
      piVar5 = FUN_0050d87c(&local_bc);
      FUN_004c6c30(*(int *)(param_1 + 0x24c),(uint *)*piVar5);
      FUN_0050d9d4(&local_bc,2);
    }
    else {
      piVar5 = (int *)FUN_0045cef8((int)piVar4);
      piVar6 = FUN_0050d87c(&local_18);
      (**(code **)(*piVar5 + 0x34))(piVar5,*piVar6);
      FUN_0050d9d4(&local_18,2);
      piVar5 = (int *)FUN_0045cef8((int)piVar4);
      piVar6 = FUN_0050d87c(&local_1c);
      (**(code **)(*piVar5 + 0x34))(piVar5,*piVar6);
      FUN_0050d9d4(&local_1c,2);
      piVar5 = FUN_004016bc(&local_24);
      FUN_004c6c00(*(int *)(param_1 + 0x20c),piVar5);
      pVVar7 = FUN_0050df38(&local_34,&local_24);
      pOVar8 = FUN_0050e234(&local_20);
      pWVar1 = (LPCWSTR)*pOVar8;
      iVar9 = FUN_0045b63c((int)piVar4);
      iVar9 = FUN_00453fcc(iVar9,pWVar1);
      FUN_00455258(iVar9,pVVar7);
      FUN_0050e004(&local_34,2);
      FUN_0050d9d4(&local_24,2);
      FUN_0050e31c(&local_20,2);
      piVar5 = FUN_004016bc(&local_3c);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar5);
      pVVar7 = FUN_0050df38(&local_4c,&local_3c);
      pOVar8 = FUN_0050e234(&local_38);
      pWVar1 = (LPCWSTR)*pOVar8;
      iVar9 = FUN_0045b63c((int)piVar4);
      iVar9 = FUN_00453fcc(iVar9,pWVar1);
      FUN_00455258(iVar9,pVVar7);
      FUN_0050e004(&local_4c,2);
      FUN_0050d9d4(&local_3c,2);
      FUN_0050e31c(&local_38,2);
      piVar5 = FUN_004016bc(&local_54);
      FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar5);
      pVVar7 = FUN_0050df38(&local_64,&local_54);
      pOVar8 = FUN_0050e234(&local_50);
      pWVar1 = (LPCWSTR)*pOVar8;
      iVar9 = FUN_0045b63c((int)piVar4);
      iVar9 = FUN_00453fcc(iVar9,pWVar1);
      FUN_00455258(iVar9,pVVar7);
      FUN_0050e004(&local_64,2);
      FUN_0050d9d4(&local_54,2);
      FUN_0050e31c(&local_50,2);
      FUN_0045ce2c((int)piVar4);
    }
    FUN_00428224(param_1);
    if (piVar4 != (int *)0x0) {
      local_c0 = *piVar4;
      local_c4 = piVar4;
      (**(code **)(*piVar4 + -4))(piVar4,3);
    }
  }
  else {
    piVar4 = FUN_0050d87c(&local_c8);
    FUN_004c1c04((undefined *)*piVar4);
    FUN_0050d9d4(&local_c8,2);
    (**(code **)(**(int **)(param_1 + 0x20c) + 0xb0))();
  }
  *in_FS_OFFSET = local_ec;
  return;
}



// Preserved published name: ComboBox2Change
// Entry 00428a7c, recovered name Published_ComboBox2Change_00428a7c

void Published_ComboBox2Change_00428a7c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0048def0(*(int **)(param_1 + 0x21c));
  if (iVar1 == 0) {
    FUN_004284b4(param_1,*(int **)(param_1 + 0x20c));
  }
  else {
    FUN_00428798(param_1,*(int **)(param_1 + 0x20c));
  }
  FUN_0042b298(param_1);
  return;
}



// Preserved published name: ComboBox3Change
// Entry 00428acc, recovered name Published_ComboBox3Change_00428acc

void Published_ComboBox3Change_00428acc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0048def0(*(int **)(param_1 + 0x220));
  if (iVar1 == 0) {
    FUN_004284b4(param_1,*(int **)(param_1 + 0x210));
  }
  else {
    FUN_00428798(param_1,*(int **)(param_1 + 0x210));
  }
  FUN_0042b298(param_1);
  return;
}



// Preserved published name: SpeedButton1Click
// Entry 00428b1c, recovered name Published_SpeedButton1Click_00428b1c

void Published_SpeedButton1Click_00428b1c(int param_1)

{
  bool bVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 local_ec;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  undefined *local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51e524);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_004016bc(&local_10);
  FUN_004016bc(&local_14);
  FUN_004016bc(&local_18);
  FUN_004016bc(&local_1c);
  FUN_004016bc(&local_20);
  if (DAT_00534328 == '\0') {
    piVar3 = FUN_004016bc(&local_24);
    FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar3);
    piVar3 = &local_24;
    FUN_0050d87c(&local_28);
    bVar1 = FUN_0050dabc(piVar3,&local_28);
    uVar5 = (uint)bVar1;
    FUN_0050d9d4(&local_28,2);
    FUN_0050d9d4(&local_24,2);
    if (uVar5 != 0) {
      piVar3 = FUN_004016bc(&local_2c);
      FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
      piVar3 = &local_2c;
      FUN_0050d87c(&local_30);
      bVar1 = FUN_0050dabc(piVar3,&local_30);
      uVar5 = (uint)bVar1;
      FUN_0050d9d4(&local_30,2);
      FUN_0050d9d4(&local_2c,2);
      if (uVar5 != 0) {
        piVar3 = FUN_004016bc(&local_34);
        FUN_004c6c00(*(int *)(param_1 + 0x218),piVar3);
        piVar3 = &local_34;
        FUN_0050d87c(&local_38);
        bVar1 = FUN_0050dabc(piVar3,&local_38);
        uVar5 = (uint)bVar1;
        FUN_0050d9d4(&local_38,2);
        FUN_0050d9d4(&local_34,2);
        if (uVar5 != 0) {
          DAT_00534328 = 1;
          piVar3 = FUN_004016bc(&local_3c);
          FUN_004c6c00(*(int *)(param_1 + 0x218),piVar3);
          FUN_0050da04(&local_8,&local_3c);
          FUN_0050d9d4(&local_3c,2);
          piVar3 = FUN_004016bc(&local_40);
          FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar3);
          piVar3 = &local_40;
          FUN_0050d87c(&local_44);
          bVar2 = FUN_0050daa4(piVar3,&local_44);
          FUN_0050d9d4(&local_44,2);
          FUN_0050d9d4(&local_40,2);
          if (bVar2 == 0) {
            piVar3 = FUN_004016bc(&local_64);
            FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar3);
            piVar3 = &local_64;
            FUN_0050d87c(&local_68);
            bVar2 = FUN_0050daa4(piVar3,&local_68);
            FUN_0050d9d4(&local_68,2);
            FUN_0050d9d4(&local_64,2);
            if (bVar2 != 0) {
              FUN_0050d87c(&local_6c);
              FUN_0050da04(&local_c,&local_6c);
              FUN_0050d9d4(&local_6c,2);
              FUN_0050d87c(&local_70);
              FUN_0050da04(&local_10,&local_70);
              FUN_0050d9d4(&local_70,2);
              piVar3 = FUN_004016bc(&local_74);
              FUN_004a61d4(*(int *)(param_1 + 0x20c),0,*(uint *)(*(int *)(param_1 + 0x20c) + 0x214),
                           piVar3);
              piVar3 = &local_74;
              piVar4 = FUN_004016bc(&local_78);
              FUN_0050dd80(s_<String__0051db07,piVar3,piVar4);
              piVar3 = &local_78;
              piVar4 = FUN_004016bc(&local_80);
              FUN_0050d87c(&local_7c);
              FUN_0050da18(piVar3,&local_7c,piVar4);
              FUN_0050da04(&local_14,&local_80);
              FUN_0050d9d4(&local_80,2);
              FUN_0050d9d4(&local_7c,2);
              FUN_0050d9d4(&local_78,2);
              FUN_0050d9d4(&local_74,2);
            }
          }
          else {
            FUN_0050d87c(&local_48);
            FUN_0050da04(&local_c,&local_48);
            FUN_0050d9d4(&local_48,2);
            FUN_0050d87c(&local_4c);
            FUN_0050da04(&local_10,&local_4c);
            FUN_0050d9d4(&local_4c,2);
            piVar3 = FUN_004016bc(&local_50);
            FUN_004a61d4(*(int *)(param_1 + 0x20c),0,*(uint *)(*(int *)(param_1 + 0x20c) + 0x214),
                         piVar3);
            piVar3 = FUN_004016bc(&local_54);
            FUN_00429738(param_1,local_50,piVar3);
            piVar3 = &local_54;
            piVar4 = FUN_004016bc(&local_58);
            FUN_0050dd80(s_<Int__0051dadf,piVar3,piVar4);
            piVar3 = &local_58;
            piVar4 = FUN_004016bc(&local_60);
            FUN_0050d87c(&local_5c);
            FUN_0050da18(piVar3,&local_5c,piVar4);
            FUN_0050da04(&local_14,&local_60);
            FUN_0050d9d4(&local_60,2);
            FUN_0050d9d4(&local_5c,2);
            FUN_0050d9d4(&local_58,2);
            FUN_0050d9d4(&local_54,2);
            FUN_0050d9d4((int *)&local_50,2);
          }
          piVar3 = FUN_004016bc(&local_84);
          FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
          piVar3 = &local_84;
          FUN_0050d87c(&local_88);
          bVar2 = FUN_0050daa4(piVar3,&local_88);
          FUN_0050d9d4(&local_88,2);
          FUN_0050d9d4(&local_84,2);
          if (bVar2 == 0) {
            piVar3 = FUN_004016bc(&local_a8);
            FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
            piVar3 = &local_a8;
            FUN_0050d87c(&local_ac);
            bVar2 = FUN_0050daa4(piVar3,&local_ac);
            FUN_0050d9d4(&local_ac,2);
            FUN_0050d9d4(&local_a8,2);
            if (bVar2 != 0) {
              FUN_0050d87c(&local_b0);
              FUN_0050da04(&local_18,&local_b0);
              FUN_0050d9d4(&local_b0,2);
              FUN_0050d87c(&local_b4);
              FUN_0050da04(&local_1c,&local_b4);
              FUN_0050d9d4(&local_b4,2);
              piVar3 = FUN_004016bc(&local_b8);
              FUN_004a61d4(*(int *)(param_1 + 0x210),0,*(uint *)(*(int *)(param_1 + 0x210) + 0x214),
                           piVar3);
              piVar3 = &local_b8;
              piVar4 = FUN_004016bc(&local_bc);
              FUN_0050dd80(s_<String__0051db57,piVar3,piVar4);
              piVar3 = &local_bc;
              piVar4 = FUN_004016bc(&local_c4);
              FUN_0050d87c(&local_c0);
              FUN_0050da18(piVar3,&local_c0,piVar4);
              FUN_0050da04(&local_20,&local_c4);
              FUN_0050d9d4(&local_c4,2);
              FUN_0050d9d4(&local_c0,2);
              FUN_0050d9d4(&local_bc,2);
              FUN_0050d9d4(&local_b8,2);
            }
          }
          else {
            FUN_0050d87c(&local_8c);
            FUN_0050da04(&local_18,&local_8c);
            FUN_0050d9d4(&local_8c,2);
            FUN_0050d87c(&local_90);
            FUN_0050da04(&local_1c,&local_90);
            FUN_0050d9d4(&local_90,2);
            piVar3 = FUN_004016bc(&local_94);
            FUN_004a61d4(*(int *)(param_1 + 0x210),0,*(uint *)(*(int *)(param_1 + 0x210) + 0x214),
                         piVar3);
            piVar3 = FUN_004016bc(&local_98);
            FUN_00429738(param_1,local_94,piVar3);
            piVar3 = &local_98;
            piVar4 = FUN_004016bc(&local_9c);
            FUN_0050dd80(s_<Int__0051db2f,piVar3,piVar4);
            piVar3 = &local_9c;
            piVar4 = FUN_004016bc(&local_a4);
            FUN_0050d87c(&local_a0);
            FUN_0050da18(piVar3,&local_a0,piVar4);
            FUN_0050da04(&local_20,&local_a4);
            FUN_0050d9d4(&local_a4,2);
            FUN_0050d9d4(&local_a0,2);
            FUN_0050d9d4(&local_9c,2);
            FUN_0050d9d4(&local_98,2);
            FUN_0050d9d4((int *)&local_94,2);
          }
          FUN_00429e60(param_1,local_8,local_c);
          DAT_00534328 = '\0';
          piVar3 = FUN_0050d87c(&local_c8);
          FUN_004c6c30(*(int *)(param_1 + 0x218),(uint *)*piVar3);
          FUN_0050d9d4(&local_c8,2);
        }
      }
    }
  }
  FUN_0050d9d4(&local_20,2);
  FUN_0050d9d4(&local_1c,2);
  FUN_0050d9d4(&local_18,2);
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_ec;
  return;
}



// Preserved published name: SpeedButton2Click
// Entry 0042a440, recovered name Published_SpeedButton2Click_0042a440

void Published_SpeedButton2Click_0042a440(int param_1)

{
  bool bVar1;
  byte bVar2;
  int *piVar3;
  PCNZCH pCVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 local_10c;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  undefined *local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined *local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51eea8);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_004016bc(&local_10);
  FUN_004016bc(&local_14);
  FUN_004016bc(&local_18);
  FUN_004016bc(&local_1c);
  FUN_004016bc(&local_20);
  FUN_004016bc(&local_24);
  FUN_004016bc(&local_28);
  if (DAT_00534328 == '\0') {
    piVar3 = FUN_004016bc(&local_2c);
    FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar3);
    piVar3 = &local_2c;
    FUN_0050d87c(&local_30);
    bVar1 = FUN_0050dabc(piVar3,&local_30);
    uVar7 = (uint)bVar1;
    FUN_0050d9d4(&local_30,2);
    FUN_0050d9d4(&local_2c,2);
    if (uVar7 != 0) {
      piVar3 = FUN_004016bc(&local_34);
      FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
      piVar3 = &local_34;
      FUN_0050d87c(&local_38);
      bVar1 = FUN_0050dabc(piVar3,&local_38);
      uVar7 = (uint)bVar1;
      FUN_0050d9d4(&local_38,2);
      FUN_0050d9d4(&local_34,2);
      if (uVar7 != 0) {
        piVar3 = FUN_004016bc(&local_3c);
        FUN_004c6c00(*(int *)(param_1 + 0x218),piVar3);
        piVar3 = &local_3c;
        FUN_0050d87c(&local_40);
        bVar1 = FUN_0050dabc(piVar3,&local_40);
        uVar7 = (uint)bVar1;
        FUN_0050d9d4(&local_40,2);
        FUN_0050d9d4(&local_3c,2);
        if (uVar7 != 0) {
          piVar3 = FUN_004016bc(&local_48);
          FUN_004c6c00(*(int *)(param_1 + 0x218),piVar3);
          piVar3 = FUN_0050d988(&local_44);
          pCVar4 = FUN_004fa560((undefined *)*piVar3,local_48);
          uVar7 = (uint)(0 < (int)pCVar4);
          FUN_0050d9d4((int *)&local_48,2);
          FUN_0050d9d4(&local_44,2);
          if (uVar7 != 0) {
            DAT_00534328 = 1;
            piVar3 = FUN_004016bc(&local_50);
            piVar5 = FUN_004016bc(&local_4c);
            FUN_004c6c00(*(int *)(param_1 + 0x218),piVar5);
            FUN_0050dbd8(&local_4c,1,(uint)(pCVar4 + -1),piVar3);
            FUN_0050da04(&local_8,&local_50);
            FUN_0050d9d4(&local_50,2);
            FUN_0050d9d4(&local_4c,2);
            piVar3 = FUN_004016bc(&local_5c);
            piVar5 = FUN_004016bc(&local_58);
            FUN_004c6c00(*(int *)(param_1 + 0x218),piVar5);
            iVar6 = FUN_00404394(&local_58);
            piVar5 = FUN_004016bc(&local_54);
            FUN_004c6c00(*(int *)(param_1 + 0x218),piVar5);
            FUN_0050dbd8(&local_54,(int)(pCVar4 + 1),iVar6 - (int)pCVar4,piVar3);
            FUN_0050da04(&local_c,&local_5c);
            FUN_0050d9d4(&local_5c,2);
            FUN_0050d9d4(&local_58,2);
            FUN_0050d9d4(&local_54,2);
            piVar3 = FUN_004016bc(&local_60);
            FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar3);
            piVar3 = &local_60;
            FUN_0050d87c(&local_64);
            bVar2 = FUN_0050daa4(piVar3,&local_64);
            FUN_0050d9d4(&local_64,2);
            FUN_0050d9d4(&local_60,2);
            if (bVar2 == 0) {
              piVar3 = FUN_004016bc(&local_84);
              FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar3);
              piVar3 = &local_84;
              FUN_0050d87c(&local_88);
              bVar2 = FUN_0050daa4(piVar3,&local_88);
              FUN_0050d9d4(&local_88,2);
              FUN_0050d9d4(&local_84,2);
              if (bVar2 != 0) {
                FUN_0050d87c(&local_8c);
                FUN_0050da04(&local_10,&local_8c);
                FUN_0050d9d4(&local_8c,2);
                FUN_0050d87c(&local_90);
                FUN_0050da04(&local_14,&local_90);
                FUN_0050d9d4(&local_90,2);
                piVar3 = FUN_004016bc(&local_94);
                FUN_004a61d4(*(int *)(param_1 + 0x20c),0,
                             *(uint *)(*(int *)(param_1 + 0x20c) + 0x214),piVar3);
                piVar3 = &local_94;
                piVar5 = FUN_004016bc(&local_98);
                FUN_0050dd80(s_<String__0051df0f,piVar3,piVar5);
                piVar3 = &local_98;
                piVar5 = FUN_004016bc(&local_a0);
                FUN_0050d87c(&local_9c);
                FUN_0050da18(piVar3,&local_9c,piVar5);
                FUN_0050da04(&local_18,&local_a0);
                FUN_0050d9d4(&local_a0,2);
                FUN_0050d9d4(&local_9c,2);
                FUN_0050d9d4(&local_98,2);
                FUN_0050d9d4(&local_94,2);
              }
            }
            else {
              FUN_0050d87c(&local_68);
              FUN_0050da04(&local_10,&local_68);
              FUN_0050d9d4(&local_68,2);
              FUN_0050d87c(&local_6c);
              FUN_0050da04(&local_14,&local_6c);
              FUN_0050d9d4(&local_6c,2);
              piVar3 = FUN_004016bc(&local_70);
              FUN_004a61d4(*(int *)(param_1 + 0x20c),0,*(uint *)(*(int *)(param_1 + 0x20c) + 0x214),
                           piVar3);
              piVar3 = FUN_004016bc(&local_74);
              FUN_00429738(param_1,local_70,piVar3);
              piVar3 = &local_74;
              piVar5 = FUN_004016bc(&local_78);
              FUN_0050dd80(s_<Int__0051dee7,piVar3,piVar5);
              piVar3 = &local_78;
              piVar5 = FUN_004016bc(&local_80);
              FUN_0050d87c(&local_7c);
              FUN_0050da18(piVar3,&local_7c,piVar5);
              FUN_0050da04(&local_18,&local_80);
              FUN_0050d9d4(&local_80,2);
              FUN_0050d9d4(&local_7c,2);
              FUN_0050d9d4(&local_78,2);
              FUN_0050d9d4(&local_74,2);
              FUN_0050d9d4((int *)&local_70,2);
            }
            piVar3 = FUN_004016bc(&local_a4);
            FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
            piVar3 = &local_a4;
            FUN_0050d87c(&local_a8);
            bVar2 = FUN_0050daa4(piVar3,&local_a8);
            FUN_0050d9d4(&local_a8,2);
            FUN_0050d9d4(&local_a4,2);
            if (bVar2 == 0) {
              piVar3 = FUN_004016bc(&local_c8);
              FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
              piVar3 = &local_c8;
              FUN_0050d87c(&local_cc);
              bVar2 = FUN_0050daa4(piVar3,&local_cc);
              FUN_0050d9d4(&local_cc,2);
              FUN_0050d9d4(&local_c8,2);
              if (bVar2 != 0) {
                FUN_0050d87c(&local_d0);
                FUN_0050da04(&local_1c,&local_d0);
                FUN_0050d9d4(&local_d0,2);
                FUN_0050d87c(&local_d4);
                FUN_0050da04(&local_20,&local_d4);
                FUN_0050d9d4(&local_d4,2);
                piVar3 = FUN_004016bc(&local_d8);
                FUN_004a61d4(*(int *)(param_1 + 0x210),0,
                             *(uint *)(*(int *)(param_1 + 0x20c) + 0x214),piVar3);
                piVar3 = &local_d8;
                piVar5 = FUN_004016bc(&local_dc);
                FUN_0050dd80(s_<String__0051df5f,piVar3,piVar5);
                piVar3 = &local_dc;
                piVar5 = FUN_004016bc(&local_e4);
                FUN_0050d87c(&local_e0);
                FUN_0050da18(piVar3,&local_e0,piVar5);
                FUN_0050da04(&local_24,&local_e4);
                FUN_0050d9d4(&local_e4,2);
                FUN_0050d9d4(&local_e0,2);
                FUN_0050d9d4(&local_dc,2);
                FUN_0050d9d4(&local_d8,2);
              }
            }
            else {
              FUN_0050d87c(&local_ac);
              FUN_0050da04(&local_1c,&local_ac);
              FUN_0050d9d4(&local_ac,2);
              FUN_0050d87c(&local_b0);
              FUN_0050da04(&local_20,&local_b0);
              FUN_0050d9d4(&local_b0,2);
              piVar3 = FUN_004016bc(&local_b4);
              FUN_004a61d4(*(int *)(param_1 + 0x210),0,*(uint *)(*(int *)(param_1 + 0x20c) + 0x214),
                           piVar3);
              piVar3 = FUN_004016bc(&local_b8);
              FUN_00429738(param_1,local_b4,piVar3);
              piVar3 = &local_b8;
              piVar5 = FUN_004016bc(&local_bc);
              FUN_0050dd80(s_<Int__0051df37,piVar3,piVar5);
              piVar3 = &local_bc;
              piVar5 = FUN_004016bc(&local_c4);
              FUN_0050d87c(&local_c0);
              FUN_0050da18(piVar3,&local_c0,piVar5);
              FUN_0050da04(&local_24,&local_c4);
              FUN_0050d9d4(&local_c4,2);
              FUN_0050d9d4(&local_c0,2);
              FUN_0050d9d4(&local_bc,2);
              FUN_0050d9d4(&local_b8,2);
              FUN_0050d9d4((int *)&local_b4,2);
            }
            FUN_00429e60(param_1,local_8,local_10);
            FUN_00429e60(param_1,local_c,local_1c);
            DAT_00534328 = '\0';
            piVar3 = FUN_0050d87c(&local_e8);
            FUN_004c6c30(*(int *)(param_1 + 0x218),(uint *)*piVar3);
            FUN_0050d9d4(&local_e8,2);
          }
        }
      }
    }
  }
  FUN_0050d9d4(&local_28,2);
  FUN_0050d9d4(&local_24,2);
  FUN_0050d9d4(&local_20,2);
  FUN_0050d9d4(&local_1c,2);
  FUN_0050d9d4(&local_18,2);
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4(&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_10c;
  return;
}



// Preserved published name: StringGrid1Click
// Entry 0042bdb0, recovered name Published_StringGrid1Click_0042bdb0

void Published_StringGrid1Click_0042bdb0(int param_1)

{
  FUN_0042b298(param_1);
  return;
}



// Preserved published name: StringGrid2Click
// Entry 0042bdc8, recovered name Published_StringGrid2Click_0042bdc8

void Published_StringGrid2Click_0042bdc8(int param_1)

{
  FUN_0042b298(param_1);
  return;
}



// Preserved published name: SpeedButton3Click
// Entry 0042bde0, recovered name Published_SpeedButton3Click_0042bde0

void Published_SpeedButton3Click_0042bde0(int param_1)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *in_FS_OFFSET;
  int local_40;
  undefined4 local_34;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51f468);
  FUN_0048d964(*(int *)(*(int *)PTR__linksname_005337fc + 0x2d0));
  iVar4 = (**(code **)(**(int **)PTR__linksname_005337fc + 0xd8))();
  if (iVar4 == 1) {
    FUN_0048de58(*(int *)(param_1 + 0x218));
    local_40 = 0;
    while( true ) {
      iVar4 = (**(code **)(**(int **)(*(int *)(*(int *)PTR__linksname_005337fc + 0x2d0) + 0x208) +
                          0x14))();
      if (iVar4 <= local_40) break;
      iVar4 = *(int *)(*(int *)PTR__linksname_005337fc + 0x2d0);
      puVar5 = FUN_004016bc(&local_8);
      piVar1 = *(int **)(iVar4 + 0x208);
      (**(code **)(*piVar1 + 0xc))(piVar1,local_40,puVar5);
      FUN_0050d87c(&local_c);
      bVar3 = FUN_0050dabc(&local_8,&local_c);
      FUN_0050d9d4(&local_c,2);
      FUN_0050d9d4(&local_8,2);
      if (bVar3) {
        iVar4 = *(int *)(param_1 + 0x218);
        iVar2 = *(int *)(*(int *)PTR__linksname_005337fc + 0x2d0);
        puVar5 = FUN_004016bc(&local_10);
        piVar1 = *(int **)(iVar2 + 0x208);
        (**(code **)(*piVar1 + 0xc))(piVar1,local_40,puVar5);
        piVar1 = *(int **)(iVar4 + 0x1f0);
        (**(code **)(*piVar1 + 0x34))(piVar1,local_10);
        FUN_0050d9d4(&local_10,2);
      }
      local_40 = local_40 + 1;
    }
  }
  *in_FS_OFFSET = local_34;
  return;
}



// Preserved published name: Button1Click
// Entry 0042c0c8, recovered name Published_Button1Click_0042c0c8

void Published_Button1Click_0042c0c8(int param_1)

{
  *(undefined4 *)(param_1 + 0x234) = 1;
  return;
}



// Preserved published name: Button2Click
// Entry 0042c0e8, recovered name Published_Button2Click_0042c0e8

void Published_Button2Click_0042c0e8(int param_1)

{
  *(undefined4 *)(param_1 + 0x234) = 2;
  return;
}



// Preserved published name: DBGrid1DblClick
// Entry 0042c26c, recovered name Published_DBGrid1DblClick_0042c26c

void Published_DBGrid1DblClick_0042c26c(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  uint *local_c;
  int local_8;
  
  FUN_00502f50(0x51f9fc);
  piVar1 = FUN_0050d87c(&local_8);
  piVar1 = (int *)FUN_0047b6a8(*(int *)(*(int *)PTR__DataModule1_005337f0 + 0x88),
                               (undefined *)*piVar1);
  puVar2 = FUN_004016bc(&local_c);
  (**(code **)(*piVar1 + 0x58))(piVar1,puVar2,*piVar1,piVar1,param_2);
  FUN_004c6c30(*(int *)(param_1 + 0x210),local_c);
  FUN_0050d9d4((int *)&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: Button1Click
// Entry 0042c308, recovered name Published_Button1Click_0042c308

void Published_Button1Click_0042c308(int param_1)

{
  LPCWSTR pWVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  VARIANTARG *pVVar6;
  BSTR pOVar7;
  undefined4 uVar8;
  undefined4 *in_FS_OFFSET;
  undefined4 local_64;
  VARIANTARG local_38;
  int local_28;
  OLECHAR local_24;
  VARIANTARG local_20;
  int local_10;
  OLECHAR local_c;
  int local_8;
  
  FUN_00502f50(0x51fa80);
  iVar2 = (**(code **)(**(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88) + 0x14c))();
  if (0 < iVar2) {
    piVar3 = FUN_0045cd80((int *)PTR_PTR_00450fc0,'\x01',(int *)0x0);
    (**(code **)(*piVar3 + 0x260))(piVar3,*(undefined4 *)(*(int *)PTR__DataModule1_005337f0 + 0x50))
    ;
    piVar4 = (int *)FUN_0045cef8((int)piVar3);
    (**(code **)(*piVar4 + 0x40))();
    piVar4 = (int *)FUN_0045cef8((int)piVar3);
    piVar5 = FUN_0050d87c(&local_8);
    (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
    FUN_0050d9d4(&local_8,2);
    piVar4 = FUN_004016bc(&local_10);
    FUN_004c6c00(*(int *)(param_1 + 0x210),piVar4);
    pVVar6 = FUN_0050df38(&local_20,&local_10);
    pOVar7 = FUN_0050e234(&local_c);
    pWVar1 = (LPCWSTR)*pOVar7;
    iVar2 = FUN_0045b63c((int)piVar3);
    iVar2 = FUN_00453fcc(iVar2,pWVar1);
    FUN_00455258(iVar2,pVVar6);
    FUN_0050e004(&local_20,2);
    FUN_0050d9d4(&local_10,2);
    FUN_0050e31c(&local_c,2);
    piVar4 = FUN_0050d87c(&local_28);
    piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)PTR__DataModule1_005337f0 + 0x88),
                                 (undefined *)*piVar4);
    uVar8 = (**(code **)(*piVar4 + 0x54))();
    pVVar6 = FUN_0050deb4(&local_38,uVar8);
    pOVar7 = FUN_0050e234(&local_24);
    pWVar1 = (LPCWSTR)*pOVar7;
    iVar2 = FUN_0045b63c((int)piVar3);
    iVar2 = FUN_00453fcc(iVar2,pWVar1);
    FUN_00455258(iVar2,pVVar6);
    FUN_0050e004(&local_38,2);
    FUN_0050d9d4(&local_28,2);
    FUN_0050e31c(&local_24,2);
    FUN_0045ce2c((int)piVar3);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + -4))(piVar3,3);
    }
    FUN_0047a9e4(*(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88));
    FUN_0047a9d8(*(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88));
  }
  *in_FS_OFFSET = local_64;
  return;
}



// Preserved published name: Button2Click
// Entry 0042c540, recovered name Published_Button2Click_0042c540

void __stdcall Published_Button2Click_0042c540(void)

{
  LPCWSTR pWVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  VARIANTARG *pVVar7;
  BSTR pOVar8;
  undefined4 *in_FS_OFFSET;
  undefined4 local_4c;
  VARIANTARG local_20;
  int local_10;
  OLECHAR local_c;
  int local_8;
  
  FUN_00502f50(0x51fb0c);
  iVar2 = (**(code **)(**(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88) + 0x14c))();
  if (0 < iVar2) {
    piVar3 = FUN_0045cd80((int *)PTR_PTR_00450fc0,'\x01',(int *)0x0);
    (**(code **)(*piVar3 + 0x260))(piVar3,*(undefined4 *)(*(int *)PTR__DataModule1_005337f0 + 0x50))
    ;
    piVar4 = (int *)FUN_0045cef8((int)piVar3);
    (**(code **)(*piVar4 + 0x40))();
    piVar4 = (int *)FUN_0045cef8((int)piVar3);
    piVar5 = FUN_0050d87c(&local_8);
    (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
    FUN_0050d9d4(&local_8,2);
    piVar4 = FUN_0050d87c(&local_10);
    piVar4 = (int *)FUN_0047b6a8(*(int *)(*(int *)PTR__DataModule1_005337f0 + 0x88),
                                 (undefined *)*piVar4);
    uVar6 = (**(code **)(*piVar4 + 0x54))();
    pVVar7 = FUN_0050deb4(&local_20,uVar6);
    pOVar8 = FUN_0050e234(&local_c);
    pWVar1 = (LPCWSTR)*pOVar8;
    iVar2 = FUN_0045b63c((int)piVar3);
    iVar2 = FUN_00453fcc(iVar2,pWVar1);
    FUN_00455258(iVar2,pVVar7);
    FUN_0050e004(&local_20,2);
    FUN_0050d9d4(&local_10,2);
    FUN_0050e31c(&local_c,2);
    FUN_0045ce2c((int)piVar3);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + -4))(piVar3,3);
    }
    FUN_0047a9e4(*(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88));
    FUN_0047a9d8(*(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88));
  }
  *in_FS_OFFSET = local_4c;
  return;
}



// Preserved published name: Button3Click
// Entry 0042c6f0, recovered name Published_Button3Click_0042c6f0

void Published_Button3Click_0042c6f0(int param_1)

{
  LPCWSTR pWVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  VARIANTARG *pVVar5;
  BSTR pOVar6;
  int iVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 local_50;
  VARIANTARG local_2c;
  int local_1c;
  OLECHAR local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x51fba8);
  FUN_0047a9e4(*(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88));
  piVar3 = (int *)FUN_0045cef8(*(int *)(*(int *)PTR__DataModule1_005337f0 + 0x88));
  (**(code **)(*piVar3 + 0x40))();
  piVar3 = FUN_004016bc(&local_8);
  FUN_004c6c00(*(int *)(param_1 + 0x210),piVar3);
  FUN_0050d87c(&local_c);
  bVar2 = FUN_0050daa4(&local_8,&local_c);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  if (bVar2 == 0) {
    piVar3 = (int *)FUN_0045cef8(*(int *)(*(int *)PTR__DataModule1_005337f0 + 0x88));
    piVar4 = FUN_0050d87c(&local_14);
    (**(code **)(*piVar3 + 0x34))(piVar3,*piVar4);
    FUN_0050d9d4(&local_14,2);
    piVar3 = FUN_004016bc(&local_1c);
    FUN_004c6c00(*(int *)(param_1 + 0x210),piVar3);
    pVVar5 = FUN_0050df38(&local_2c,&local_1c);
    pOVar6 = FUN_0050e234(&local_18);
    pWVar1 = (LPCWSTR)*pOVar6;
    iVar7 = FUN_0045b63c(*(int *)(*(int *)PTR__DataModule1_005337f0 + 0x88));
    iVar7 = FUN_00453fcc(iVar7,pWVar1);
    FUN_00455258(iVar7,pVVar5);
    FUN_0050e004(&local_2c,2);
    FUN_0050d9d4(&local_1c,2);
    FUN_0050e31c(&local_18,2);
  }
  else {
    piVar3 = (int *)FUN_0045cef8(*(int *)(*(int *)PTR__DataModule1_005337f0 + 0x88));
    piVar4 = FUN_0050d87c(&local_10);
    (**(code **)(*piVar3 + 0x34))(piVar3,*piVar4);
    FUN_0050d9d4(&local_10,2);
  }
  FUN_0047a9d8(*(int **)(*(int *)PTR__DataModule1_005337f0 + 0x88));
  *in_FS_OFFSET = local_50;
  return;
}



// Preserved published name: Edit1Change
// Entry 0042cd14, recovered name Published_Edit1Change_0042cd14

void Published_Edit1Change_0042cd14(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x52005c);
  if (*(char *)(param_1 + 0x225) != '\0') {
    piVar1 = FUN_004016bc(&local_8);
    FUN_004c6c00(*(int *)(param_1 + 0x214),piVar1);
    FUN_0042ca5c(param_1,local_8);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: ListBox1Click
// Entry 0042cd84, recovered name Published_ListBox1Click_0042cd84

void Published_ListBox1Click_0042cd84(int param_1)

{
  LPCWSTR pWVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  VARIANTARG *pVVar8;
  BSTR pOVar9;
  undefined *puVar10;
  undefined4 *in_FS_OFFSET;
  undefined4 local_118;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined *local_44;
  int local_40;
  int local_3c;
  int local_38;
  VARIANTARG local_34;
  int local_24;
  OLECHAR local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined *local_10;
  int local_c;
  uint *local_8;
  
  FUN_00502f50(0x5203b0);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_004016bc(&local_10);
  *(undefined1 *)(param_1 + 0x224) = 0;
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x218) + 0x1f0) + 0x14))();
  if (0 < iVar3) {
    iVar3 = *(int *)(param_1 + 0x218);
    puVar4 = FUN_004016bc(&local_14);
    uVar5 = FUN_0048fcc0(*(int **)(param_1 + 0x218));
    piVar6 = *(int **)(iVar3 + 0x1f0);
    (**(code **)(*piVar6 + 0xc))(piVar6,uVar5,puVar4);
    FUN_0050da04((int *)&local_8,&local_14);
    FUN_0050d9d4(&local_14,2);
    FUN_0050d87c(&local_18);
    cVar2 = FUN_0050dabc(&local_8,&local_18);
    FUN_0050d9d4(&local_18,2);
    if (cVar2 != '\0') {
      *(undefined1 *)(param_1 + 0x225) = 0;
      FUN_004c6c30(*(int *)(param_1 + 0x214),local_8);
      *(undefined1 *)(param_1 + 0x225) = 1;
      FUN_0047a9e4(*(int **)(param_1 + 0x220));
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x220));
      (**(code **)(*piVar6 + 0x40))();
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x220));
      piVar7 = FUN_0050d87c(&local_1c);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_1c,2);
      piVar6 = FUN_004016bc(&local_24);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar6);
      pVVar8 = FUN_0050df38(&local_34,&local_24);
      pOVar9 = FUN_0050e234(&local_20);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x220));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      FUN_00455258(iVar3,pVVar8);
      FUN_0050e004(&local_34,2);
      FUN_0050d9d4(&local_24,2);
      FUN_0050e31c(&local_20,2);
      FUN_0047a9d8(*(int **)(param_1 + 0x220));
      iVar3 = (**(code **)(**(int **)(param_1 + 0x220) + 0x14c))();
      if (0 < iVar3) {
        FUN_0047c964(*(int **)(param_1 + 0x220));
        FUN_0050d87c(&local_38);
        FUN_0050da04(&local_c,&local_38);
        FUN_0050d9d4(&local_38,2);
        piVar6 = FUN_004016bc(&local_44);
        FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar6);
        piVar6 = FUN_004016bc(&local_48);
        FUN_004f6cdc(local_44,piVar6);
        piVar6 = &local_48;
        piVar7 = FUN_004016bc(&local_40);
        FUN_0050d87c(&local_3c);
        FUN_0050da18(&local_c,&local_3c,piVar7);
        piVar7 = FUN_004016bc(&local_4c);
        FUN_0050da18(&local_40,piVar6,piVar7);
        piVar6 = &local_4c;
        piVar7 = FUN_004016bc(&local_54);
        FUN_0050d87c(&local_50);
        FUN_0050da18(piVar6,&local_50,piVar7);
        FUN_0050da04(&local_c,&local_54);
        FUN_0050d9d4(&local_54,2);
        FUN_0050d9d4(&local_50,2);
        FUN_0050d9d4(&local_4c,2);
        FUN_0050d9d4(&local_48,2);
        FUN_0050d9d4((int *)&local_44,2);
        FUN_0050d9d4(&local_40,2);
        FUN_0050d9d4(&local_3c,2);
        piVar6 = FUN_004016bc(&local_5c);
        FUN_0050d87c(&local_58);
        FUN_0050da18(&local_c,&local_58,piVar6);
        FUN_0050da04(&local_c,&local_5c);
        FUN_0050d9d4(&local_5c,2);
        FUN_0050d9d4(&local_58,2);
        piVar6 = FUN_004016bc(&local_68);
        FUN_004c6c00(*(int *)(param_1 + 0x214),piVar6);
        piVar6 = &local_68;
        piVar7 = FUN_004016bc(&local_64);
        FUN_0050d87c(&local_60);
        FUN_0050da18(&local_c,&local_60,piVar7);
        piVar7 = FUN_004016bc(&local_6c);
        FUN_0050da18(&local_64,piVar6,piVar7);
        FUN_0050da04(&local_c,&local_6c);
        FUN_0050d9d4(&local_6c,2);
        FUN_0050d9d4(&local_68,2);
        FUN_0050d9d4(&local_64,2);
        FUN_0050d9d4(&local_60,2);
        piVar6 = FUN_0050d87c(&local_78);
        piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
        puVar4 = FUN_004016bc(&local_7c);
        (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
        piVar6 = &local_7c;
        piVar7 = FUN_004016bc(&local_74);
        FUN_0050d87c(&local_70);
        FUN_0050da18(&local_c,&local_70,piVar7);
        piVar7 = FUN_004016bc(&local_80);
        FUN_0050da18(&local_74,piVar6,piVar7);
        piVar6 = &local_80;
        piVar7 = FUN_004016bc(&local_88);
        FUN_0050d87c(&local_84);
        FUN_0050da18(piVar6,&local_84,piVar7);
        FUN_0050da04(&local_c,&local_88);
        FUN_0050d9d4(&local_88,2);
        FUN_0050d9d4(&local_84,2);
        FUN_0050d9d4(&local_80,2);
        FUN_0050d9d4(&local_7c,2);
        FUN_0050d9d4(&local_78,2);
        FUN_0050d9d4(&local_74,2);
        FUN_0050d9d4(&local_70,2);
        piVar6 = FUN_004016bc(&local_90);
        FUN_0050d87c(&local_8c);
        FUN_0050da18(&local_c,&local_8c,piVar6);
        FUN_0050da04(&local_c,&local_90);
        FUN_0050d9d4(&local_90,2);
        FUN_0050d9d4(&local_8c,2);
        piVar6 = FUN_0050d87c(&local_94);
        piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
        puVar4 = FUN_004016bc(&local_98);
        (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
        piVar6 = &local_98;
        FUN_0050d87c(&local_9c);
        cVar2 = FUN_0050dabc(piVar6,&local_9c);
        FUN_0050d9d4(&local_9c,2);
        FUN_0050d9d4(&local_98,2);
        FUN_0050d9d4(&local_94,2);
        if (cVar2 != '\0') {
          piVar6 = FUN_0050d87c(&local_a8);
          piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
          puVar4 = FUN_004016bc(&local_ac);
          (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
          piVar6 = &local_ac;
          piVar7 = FUN_004016bc(&local_a4);
          FUN_0050d87c(&local_a0);
          FUN_0050da18(&local_c,&local_a0,piVar7);
          piVar7 = FUN_004016bc(&local_b0);
          FUN_0050da18(&local_a4,piVar6,piVar7);
          FUN_0050da04(&local_c,&local_b0);
          FUN_0050d9d4(&local_b0,2);
          FUN_0050d9d4(&local_ac,2);
          FUN_0050d9d4(&local_a8,2);
          FUN_0050d9d4(&local_a4,2);
          FUN_0050d9d4(&local_a0,2);
          piVar6 = FUN_004016bc(&local_b8);
          FUN_0050d87c(&local_b4);
          FUN_0050da18(&local_c,&local_b4,piVar6);
          FUN_0050da04(&local_c,&local_b8);
          FUN_0050d9d4(&local_b8,2);
          FUN_0050d9d4(&local_b4,2);
        }
        piVar6 = FUN_0050d87c(&local_c4);
        piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
        puVar4 = FUN_004016bc(&local_c8);
        (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
        piVar6 = &local_c8;
        piVar7 = FUN_004016bc(&local_c0);
        FUN_0050d87c(&local_bc);
        FUN_0050da18(&local_c,&local_bc,piVar7);
        piVar7 = FUN_004016bc(&local_cc);
        FUN_0050da18(&local_c0,piVar6,piVar7);
        FUN_0050da04(&local_c,&local_cc);
        FUN_0050d9d4(&local_cc,2);
        FUN_0050d9d4(&local_c8,2);
        FUN_0050d9d4(&local_c4,2);
        FUN_0050d9d4(&local_c0,2);
        FUN_0050d9d4(&local_bc,2);
        piVar6 = FUN_004016bc(&local_d4);
        FUN_0050d87c(&local_d0);
        FUN_0050da18(&local_c,&local_d0,piVar6);
        FUN_0050da04(&local_c,&local_d4);
        FUN_0050d9d4(&local_d4,2);
        FUN_0050d9d4(&local_d0,2);
        piVar6 = FUN_004016bc(&local_dc);
        FUN_0050d87c(&local_d8);
        FUN_0050da18(&local_c,&local_d8,piVar6);
        FUN_0050da04(&local_c,&local_dc);
        FUN_0050d9d4(&local_dc,2);
        FUN_0050d9d4(&local_d8,2);
        piVar6 = FUN_004016bc(&local_e4);
        FUN_0050d87c(&local_e0);
        FUN_0050da18(&local_c,&local_e0,piVar6);
        FUN_0050da04(&local_c,&local_e4);
        FUN_0050d9d4(&local_e4,2);
        FUN_0050d9d4(&local_e0,2);
        piVar6 = FUN_004016bc(&local_ec);
        FUN_0050d87c(&local_e8);
        FUN_0050da18((undefined4 *)PTR__tempdir_005337e8,&local_e8,piVar6);
        FUN_0050da04((int *)&local_10,&local_ec);
        FUN_0050d9d4(&local_ec,2);
        FUN_0050d9d4(&local_e8,2);
        piVar6 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_10,0xffff);
        uVar5 = FUN_00404394(&local_c);
        puVar10 = FUN_00404374(&local_c);
        (**(code **)(*piVar6 + 8))(piVar6,puVar10,uVar5);
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + -4))(piVar6,3);
        }
        *(undefined1 *)(param_1 + 0x224) = 1;
      }
    }
  }
  FUN_0050d9d4((int *)&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4((int *)&local_8,2);
  *in_FS_OFFSET = local_118;
  return;
}



// Preserved published name: Button1Click
// Entry 0042f0ec, recovered name Published_Button1Click_0042f0ec

void Published_Button1Click_0042f0ec(int param_1)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_4c;
  uint *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined *local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x520d8c);
  piVar2 = FUN_0050d87c(&local_8);
  FUN_004da1a8(*(int **)(param_1 + 0x228),(uint *)*piVar2);
  FUN_0050d9d4(&local_8,2);
  (**(code **)(*DAT_00520cb4 + 0x40))();
  FUN_0042f2f8(param_1,DAT_00520cb4);
  piVar2 = FUN_004016bc(&local_14);
  FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar2);
  piVar2 = &local_14;
  FUN_0050d87c(&local_18);
  bVar1 = FUN_0050daa4(piVar2,&local_18);
  piVar2 = DAT_00520cb4;
  piVar3 = FUN_004016bc(&local_10);
  FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
  piVar3 = FUN_004016bc(&local_c);
  FUN_004c6c00(*(int *)(param_1 + 0x218),piVar3);
  _FindStr_qqri17System_AnsiStringt2op19Classes_TStringList(1,local_c,local_10,piVar2,bVar1);
  FUN_0050d9d4(&local_18,2);
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4((int *)&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0042f2f8(param_1,DAT_00520cb4);
  piVar2 = FUN_004016bc(&local_1c);
  uVar4 = (**(code **)(*DAT_00520cb4 + 0x14))();
  FUN_004f6a10(uVar4,piVar2);
  piVar2 = &local_1c;
  piVar3 = FUN_004016bc(&local_20);
  FUN_0050dd80(&DAT_00520cd8,piVar2,piVar3);
  piVar2 = &local_20;
  piVar3 = FUN_004016bc(&local_28);
  FUN_0050d87c(&local_24);
  FUN_0050da18(piVar2,&local_24,piVar3);
  FUN_004da1a8(*(int **)(param_1 + 0x228),local_28);
  FUN_0050d9d4((int *)&local_28,2);
  FUN_0050d9d4(&local_24,2);
  FUN_0050d9d4(&local_20,2);
  FUN_0050d9d4(&local_1c,2);
  *in_FS_OFFSET = local_4c;
  return;
}



// Preserved published name: SpeedButton1Click
// Entry 004317d4, recovered name Published_SpeedButton1Click_004317d4

void Published_SpeedButton1Click_004317d4(int param_1,undefined4 param_2)

{
  int *piVar1;
  VARIANTARG *pVVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar4;
  undefined1 local_4e [2];
  int *local_4c;
  int *local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined2 local_2c;
  int local_20;
  VARIANTARG local_18;
  int local_8;
  
  local_44 = param_2;
  local_40 = param_1;
  FUN_00502f50(0x522064);
  local_2c = 8;
  piVar1 = FUN_004050a0(&local_8);
  local_20 = local_20 + 1;
  FUN_00492738(*(int **)(local_40 + 0x234),0xcb,piVar1);
  local_48 = (int *)FUN_0040512c(&local_8);
  local_20 = local_20 + -1;
  FUN_004050ec(&local_8,2);
  if ((local_48 != (int *)0x0) && (local_4c = local_48, local_48 != (int *)0x0)) {
    puVar4 = local_4e;
    local_2c = 0x2c;
    pVVar2 = FUN_004037cc(&local_18);
    local_20 = local_20 + 2;
    puVar3 = (undefined4 *)FUN_0041d664(pVVar2);
    local_2c = 0x20;
    local_20 = local_20 + -2;
    (**(code **)(*local_4c + 0x118))
              (local_4c,*local_4c,pVVar2,local_4c,u_Bold_00521a20,0,*puVar3,puVar3[1],puVar3[2],
               puVar3[3],puVar4);
    local_20 = local_20 + -2;
    FUN_004038c8(&local_18,2);
  }
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: SpeedButton2Click
// Entry 004318cc, recovered name Published_SpeedButton2Click_004318cc

void Published_SpeedButton2Click_004318cc(int param_1,undefined4 param_2)

{
  int *piVar1;
  VARIANTARG *pVVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar4;
  undefined1 local_4e [2];
  int *local_4c;
  int *local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined2 local_2c;
  int local_20;
  VARIANTARG local_18;
  int local_8;
  
  local_44 = param_2;
  local_40 = param_1;
  FUN_00502f50(0x5220ec);
  local_2c = 8;
  piVar1 = FUN_004050a0(&local_8);
  local_20 = local_20 + 1;
  FUN_00492738(*(int **)(local_40 + 0x234),0xcb,piVar1);
  local_48 = (int *)FUN_0040512c(&local_8);
  local_20 = local_20 + -1;
  FUN_004050ec(&local_8,2);
  if ((local_48 != (int *)0x0) && (local_4c = local_48, local_48 != (int *)0x0)) {
    puVar4 = local_4e;
    local_2c = 0x2c;
    pVVar2 = FUN_004037cc(&local_18);
    local_20 = local_20 + 2;
    puVar3 = (undefined4 *)FUN_0041d664(pVVar2);
    local_2c = 0x20;
    local_20 = local_20 + -2;
    (**(code **)(*local_4c + 0x118))
              (local_4c,*local_4c,pVVar2,local_4c,u_Italic_00521a2a,0,*puVar3,puVar3[1],puVar3[2],
               puVar3[3],puVar4);
    local_20 = local_20 + -2;
    FUN_004038c8(&local_18,2);
  }
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: SpeedButton3Click
// Entry 004319c4, recovered name Published_SpeedButton3Click_004319c4

void Published_SpeedButton3Click_004319c4(int param_1,undefined4 param_2)

{
  int *piVar1;
  VARIANTARG *pVVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar4;
  undefined1 local_4e [2];
  int *local_4c;
  int *local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined2 local_2c;
  int local_20;
  VARIANTARG local_18;
  int local_8;
  
  local_44 = param_2;
  local_40 = param_1;
  FUN_00502f50(0x522174);
  local_2c = 8;
  piVar1 = FUN_004050a0(&local_8);
  local_20 = local_20 + 1;
  FUN_00492738(*(int **)(local_40 + 0x234),0xcb,piVar1);
  local_48 = (int *)FUN_0040512c(&local_8);
  local_20 = local_20 + -1;
  FUN_004050ec(&local_8,2);
  if ((local_48 != (int *)0x0) && (local_4c = local_48, local_48 != (int *)0x0)) {
    puVar4 = local_4e;
    local_2c = 0x2c;
    pVVar2 = FUN_004037cc(&local_18);
    local_20 = local_20 + 2;
    puVar3 = (undefined4 *)FUN_0041d664(pVVar2);
    local_2c = 0x20;
    local_20 = local_20 + -2;
    (**(code **)(*local_4c + 0x118))
              (local_4c,*local_4c,pVVar2,local_4c,u_Underline_00521a38,0,*puVar3,puVar3[1],puVar3[2]
               ,puVar3[3],puVar4);
    local_20 = local_20 + -2;
    FUN_004038c8(&local_18,2);
  }
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: ListBox1Click
// Entry 00431abc, recovered name Published_ListBox1Click_00431abc

void Published_ListBox1Click_00431abc(int param_1)

{
  FUN_00431310(param_1);
  return;
}



// Preserved published name: SpeedButton4Click
// Entry 00431ad4, recovered name Published_SpeedButton4Click_00431ad4

void Published_SpeedButton4Click_00431ad4(int param_1)

{
  LPCWSTR pWVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  BSTR pOVar8;
  VARIANTARG *pVVar9;
  undefined4 *in_FS_OFFSET;
  int *local_dc;
  undefined4 local_c8;
  int local_a4;
  VARIANTARG local_a0;
  int local_90;
  OLECHAR local_8c;
  VARIANTARG local_88;
  OLECHAR local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x5223dc);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_00405000(&local_10);
  iVar3 = FUN_00401740(*(int *)PTR__MainForm_005337bc);
  if (iVar3 == -1) {
    piVar6 = FUN_0050d87c(&local_a4);
    FUN_004c1c04((undefined *)*piVar6);
    FUN_0050d9d4(&local_a4,2);
  }
  else if (DAT_00521924 != 0) {
    iVar3 = FUN_0048fcc0(*(int **)(param_1 + 0x224));
    if (-1 < iVar3) {
      iVar3 = *(int *)(param_1 + 0x224);
      puVar4 = FUN_004016bc(&local_14);
      uVar5 = FUN_0048fcc0(*(int **)(param_1 + 0x224));
      piVar6 = *(int **)(iVar3 + 0x1f0);
      (**(code **)(*piVar6 + 0xc))(piVar6,uVar5,puVar4);
      FUN_0050da04(&local_8,&local_14);
      FUN_0050d9d4(&local_14,2);
      FUN_0050d87c(&local_18);
      FUN_0050da04(&local_c,&local_18);
      FUN_0050d9d4(&local_18,2);
      FUN_0050d87c(&local_1c);
      bVar2 = FUN_0050daa4(&local_8,&local_1c);
      FUN_0050d9d4(&local_1c,2);
      if (bVar2 == 0) {
        FUN_0050d87c(&local_24);
        bVar2 = FUN_0050daa4(&local_8,&local_24);
        FUN_0050d9d4(&local_24,2);
        if (bVar2 == 0) {
          FUN_0050d87c(&local_2c);
          bVar2 = FUN_0050daa4(&local_8,&local_2c);
          FUN_0050d9d4(&local_2c,2);
          if (bVar2 == 0) {
            FUN_0050d87c(&local_34);
            bVar2 = FUN_0050daa4(&local_8,&local_34);
            FUN_0050d9d4(&local_34,2);
            if (bVar2 == 0) {
              FUN_0050d87c(&local_3c);
              bVar2 = FUN_0050daa4(&local_8,&local_3c);
              FUN_0050d9d4(&local_3c,2);
              if (bVar2 == 0) {
                FUN_0050d87c(&local_44);
                bVar2 = FUN_0050daa4(&local_8,&local_44);
                FUN_0050d9d4(&local_44,2);
                if (bVar2 == 0) {
                  FUN_0050d87c(&local_4c);
                  bVar2 = FUN_0050daa4(&local_8,&local_4c);
                  FUN_0050d9d4(&local_4c,2);
                  if (bVar2 == 0) {
                    FUN_0050d87c(&local_54);
                    bVar2 = FUN_0050daa4(&local_8,&local_54);
                    FUN_0050d9d4(&local_54,2);
                    if (bVar2 != 0) {
                      FUN_0050d87c(&local_58);
                      FUN_0050da04(&local_c,&local_58);
                      FUN_0050d9d4(&local_58,2);
                    }
                  }
                  else {
                    FUN_0050d87c(&local_50);
                    FUN_0050da04(&local_c,&local_50);
                    FUN_0050d9d4(&local_50,2);
                  }
                }
                else {
                  FUN_0050d87c(&local_48);
                  FUN_0050da04(&local_c,&local_48);
                  FUN_0050d9d4(&local_48,2);
                }
              }
              else {
                FUN_0050d87c(&local_40);
                FUN_0050da04(&local_c,&local_40);
                FUN_0050d9d4(&local_40,2);
              }
            }
            else {
              FUN_0050d87c(&local_38);
              FUN_0050da04(&local_c,&local_38);
              FUN_0050d9d4(&local_38,2);
            }
          }
          else {
            FUN_0050d87c(&local_30);
            FUN_0050da04(&local_c,&local_30);
            FUN_0050d9d4(&local_30,2);
          }
        }
        else {
          FUN_0050d87c(&local_28);
          FUN_0050da04(&local_c,&local_28);
          FUN_0050d9d4(&local_28,2);
        }
      }
      else {
        FUN_0050d87c(&local_20);
        FUN_0050da04(&local_c,&local_20);
        FUN_0050d9d4(&local_20,2);
      }
      piVar6 = FUN_004050a0(&local_5c);
      FUN_00492738(*(int **)(param_1 + 0x234),0xcb,piVar6);
      piVar6 = (int *)FUN_0040512c(&local_5c);
      FUN_004050ec(&local_5c,2);
      if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0x0)) {
        (**(code **)(*piVar6 + 0x24))();
        FUN_00405030(&local_10);
        (**(code **)(*local_dc + 0xe8))();
      }
      FUN_0047a9e4(*(int **)(param_1 + 0x24c));
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x24c));
      (**(code **)(*piVar6 + 0x40))();
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x24c));
      piVar7 = FUN_0050d87c(&local_60);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_60,2);
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x24c));
      piVar7 = FUN_004016bc(&local_64);
      FUN_0050dd80(s_set_00521af6,&local_c,piVar7);
      piVar7 = FUN_004016bc(&local_6c);
      FUN_0050d87c(&local_68);
      FUN_0050da18(&local_64,&local_68,piVar7);
      piVar7 = FUN_004016bc(&local_70);
      FUN_0050da18(&local_6c,&local_c,piVar7);
      (**(code **)(*piVar6 + 0x34))(piVar6,local_70);
      FUN_0050d9d4(&local_70,2);
      FUN_0050d9d4(&local_6c,2);
      FUN_0050d9d4(&local_68,2);
      FUN_0050d9d4(&local_64,2);
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x24c));
      piVar7 = FUN_0050d87c(&local_74);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_74,2);
      pOVar8 = FUN_0050e234(&local_78);
      pWVar1 = (LPCWSTR)*pOVar8;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x24c));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      pVVar9 = FUN_0050deb4(&local_88,DAT_00521924);
      FUN_00455258(iVar3,pVVar9);
      FUN_0050e004(&local_88,2);
      FUN_0050e31c(&local_78,2);
      pOVar8 = FUN_0050e2a8(&local_8c);
      pWVar1 = (LPCWSTR)*pOVar8;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x24c));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      piVar6 = FUN_0050d8f0(&local_90);
      pVVar9 = FUN_0050df38(&local_a0,piVar6);
      FUN_00455258(iVar3,pVVar9);
      FUN_0050e004(&local_a0,2);
      FUN_0050d9d4(&local_90,2);
      FUN_0050e31c(&local_8c,2);
      FUN_0045ce2c(*(int *)(param_1 + 0x24c));
    }
  }
  FUN_0050e31c(&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_c8;
  return;
}



// Preserved published name: SpeedButton5Click
// Entry 00432498, recovered name Published_SpeedButton5Click_00432498

void Published_SpeedButton5Click_00432498(int param_1,undefined4 param_2)

{
  int *piVar1;
  VARIANTARG *pVVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar4;
  undefined1 local_4e [2];
  int *local_4c;
  int *local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined2 local_2c;
  int local_20;
  VARIANTARG local_18;
  int local_8;
  
  local_44 = param_2;
  local_40 = param_1;
  FUN_00502f50(0x5225b4);
  local_2c = 8;
  piVar1 = FUN_004050a0(&local_8);
  local_20 = local_20 + 1;
  FUN_00492738(*(int **)(local_40 + 0x234),0xcb,piVar1);
  local_48 = (int *)FUN_0040512c(&local_8);
  local_20 = local_20 + -1;
  FUN_004050ec(&local_8,2);
  if ((local_48 != (int *)0x0) && (local_4c = local_48, local_48 != (int *)0x0)) {
    puVar4 = local_4e;
    local_2c = 0x2c;
    pVVar2 = FUN_004037cc(&local_18);
    local_20 = local_20 + 2;
    puVar3 = (undefined4 *)FUN_0041d664(pVVar2);
    local_2c = 0x20;
    local_20 = local_20 + -2;
    (**(code **)(*local_4c + 0x118))
              (local_4c,*local_4c,pVVar2,local_4c,u_SuperScript_00521b5e,0,*puVar3,puVar3[1],
               puVar3[2],puVar3[3],puVar4);
    local_20 = local_20 + -2;
    FUN_004038c8(&local_18,2);
  }
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: SpeedButton6Click
// Entry 00432590, recovered name Published_SpeedButton6Click_00432590

void Published_SpeedButton6Click_00432590(int param_1,undefined4 param_2)

{
  int *piVar1;
  VARIANTARG *pVVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar4;
  undefined1 local_4e [2];
  int *local_4c;
  int *local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined2 local_2c;
  int local_20;
  VARIANTARG local_18;
  int local_8;
  
  local_44 = param_2;
  local_40 = param_1;
  FUN_00502f50(0x52263c);
  local_2c = 8;
  piVar1 = FUN_004050a0(&local_8);
  local_20 = local_20 + 1;
  FUN_00492738(*(int **)(local_40 + 0x234),0xcb,piVar1);
  local_48 = (int *)FUN_0040512c(&local_8);
  local_20 = local_20 + -1;
  FUN_004050ec(&local_8,2);
  if ((local_48 != (int *)0x0) && (local_4c = local_48, local_48 != (int *)0x0)) {
    puVar4 = local_4e;
    local_2c = 0x2c;
    pVVar2 = FUN_004037cc(&local_18);
    local_20 = local_20 + 2;
    puVar3 = (undefined4 *)FUN_0041d664(pVVar2);
    local_2c = 0x20;
    local_20 = local_20 + -2;
    (**(code **)(*local_4c + 0x118))
              (local_4c,*local_4c,pVVar2,local_4c,u_SubScript_00521b76,0,*puVar3,puVar3[1],puVar3[2]
               ,puVar3[3],puVar4);
    local_20 = local_20 + -2;
    FUN_004038c8(&local_18,2);
  }
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: SpeedButton7Click
// Entry 00432688, recovered name Published_SpeedButton7Click_00432688

void Published_SpeedButton7Click_00432688(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x522684);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x234),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton8Click
// Entry 004326e4, recovered name Published_SpeedButton8Click_004326e4

void Published_SpeedButton8Click_004326e4(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x5226a8);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x234),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton1Click
// Entry 0043609c, recovered name Published_SpeedButton1Click_0043609c

void Published_SpeedButton1Click_0043609c(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x524018);
  pOVar1 = FUN_0050e2e4(&local_8);
  FUN_00435b38(param_1,(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton2Click
// Entry 004360f0, recovered name Published_SpeedButton2Click_004360f0

void Published_SpeedButton2Click_004360f0(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x52403c);
  pOVar1 = FUN_0050e2e4(&local_8);
  FUN_00435b38(param_1,(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton3Click
// Entry 00436144, recovered name Published_SpeedButton3Click_00436144

void Published_SpeedButton3Click_00436144(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x524060);
  pOVar1 = FUN_0050e2e4(&local_8);
  FUN_00435b38(param_1,(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton5Click
// Entry 00436198, recovered name Published_SpeedButton5Click_00436198

void Published_SpeedButton5Click_00436198(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x524084);
  pOVar1 = FUN_0050e2e4(&local_8);
  FUN_00435b38(param_1,(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton6Click
// Entry 004361ec, recovered name Published_SpeedButton6Click_004361ec

void Published_SpeedButton6Click_004361ec(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x5240a8);
  pOVar1 = FUN_0050e2e4(&local_8);
  FUN_00435b38(param_1,(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: Edit1Change
// Entry 004364f8, recovered name Published_Edit1Change_004364f8

void Published_Edit1Change_004364f8(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x5241b8);
  if (DAT_00523ad5 != '\0') {
    piVar1 = FUN_004016bc(&local_8);
    FUN_004c6c00(*(int *)(param_1 + 0x22c),piVar1);
    FUN_00436240(param_1,local_8);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: ListBox1Click
// Entry 00436994, recovered name Published_ListBox1Click_00436994

void Published_ListBox1Click_00436994(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  uint *local_8;
  
  FUN_00502f50(0x52435c);
  DAT_00523ad5 = 0;
  iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x234) + 0x1f0) + 0x14))();
  if (0 < iVar2) {
    iVar2 = *(int *)(param_1 + 0x234);
    puVar3 = FUN_004016bc(&local_8);
    uVar4 = FUN_0048fcc0(*(int **)(param_1 + 0x234));
    piVar1 = *(int **)(iVar2 + 0x1f0);
    (**(code **)(*piVar1 + 0xc))(piVar1,uVar4,puVar3);
    FUN_004c6c30(*(int *)(param_1 + 0x22c),local_8);
    FUN_0050d9d4((int *)&local_8,2);
  }
  FUN_0043662c(param_1);
  DAT_00523ad5 = 1;
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: ListBox2Click
// Entry 00436a54, recovered name Published_ListBox2Click_00436a54

void Published_ListBox2Click_00436a54(int param_1)

{
  FUN_0043662c(param_1);
  return;
}



// Preserved published name: SpeedButton4Click
// Entry 00436a6c, recovered name Published_SpeedButton4Click_00436a6c

void Published_SpeedButton4Click_00436a6c(int param_1)

{
  LPCWSTR pWVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  VARIANTARG *pVVar6;
  BSTR pOVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 local_bc;
  int local_98;
  VARIANTARG local_94;
  int local_84;
  OLECHAR local_80;
  VARIANTARG local_7c;
  OLECHAR local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  VARIANTARG local_58;
  OLECHAR local_48;
  VARIANTARG local_44;
  int local_34;
  OLECHAR local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x5244f0);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  iVar3 = FUN_00401740(*(int *)PTR__MainForm_005337bc);
  if (iVar3 == -1) {
    piVar4 = FUN_0050d87c(&local_98);
    FUN_004c1c04((undefined *)*piVar4);
    FUN_0050d9d4(&local_98,2);
    goto LAB_00437167;
  }
  piVar4 = FUN_004016bc(&local_10);
  FUN_004c6c00(*(int *)(param_1 + 0x22c),piVar4);
  FUN_0050d87c(&local_14);
  bVar2 = FUN_0050dabc(&local_10,&local_14);
  if (bVar2) {
    iVar3 = FUN_0048fcc0(*(int **)(param_1 + 0x23c));
    if (iVar3 < 0) goto LAB_00436b42;
    bVar2 = true;
  }
  else {
LAB_00436b42:
    bVar2 = false;
  }
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4(&local_10,2);
  if (bVar2) {
    piVar4 = FUN_004016bc(&local_18);
    FUN_00435c60(param_1,piVar4);
    FUN_0050da04(&local_c,&local_18);
    FUN_0050d9d4(&local_18,2);
    iVar3 = *(int *)(param_1 + 0x234);
    piVar4 = FUN_004016bc(&local_1c);
    FUN_004c6c00(*(int *)(param_1 + 0x22c),piVar4);
    piVar4 = *(int **)(iVar3 + 0x1f0);
    iVar3 = (**(code **)(*piVar4 + 0x50))(piVar4,local_1c);
    FUN_0050d9d4(&local_1c,2);
    if (iVar3 < 0) {
      FUN_00435fac(param_1,&local_8);
      FUN_0047a9e4(*(int **)(param_1 + 0x250));
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
      (**(code **)(*piVar4 + 0x40))();
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
      piVar5 = FUN_004016bc(&local_20);
      FUN_0050dd80(s_insert_into_chemicals__chemname__00523c02,&local_c,piVar5);
      piVar5 = FUN_004016bc(&local_28);
      FUN_0050d87c(&local_24);
      FUN_0050da18(&local_20,&local_24,piVar5);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_28);
      FUN_0050d9d4(&local_28,2);
      FUN_0050d9d4(&local_24,2);
      FUN_0050d9d4(&local_20,2);
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
      piVar5 = FUN_0050d87c(&local_2c);
      (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
      FUN_0050d9d4(&local_2c,2);
      piVar4 = FUN_004016bc(&local_34);
      FUN_004c6c00(*(int *)(param_1 + 0x22c),piVar4);
      pVVar6 = FUN_0050df38(&local_44,&local_34);
      pOVar7 = FUN_0050e234(&local_30);
      pWVar1 = (LPCWSTR)*pOVar7;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x250));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      FUN_00455258(iVar3,pVVar6);
      FUN_0050e004(&local_44,2);
      FUN_0050d9d4(&local_34,2);
      FUN_0050e31c(&local_30,2);
      pOVar7 = FUN_0050e234(&local_48);
      pWVar1 = (LPCWSTR)*pOVar7;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x250));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      pVVar6 = FUN_0050df38(&local_58,&local_8);
      FUN_00455258(iVar3,pVVar6);
      FUN_0050e004(&local_58,2);
      FUN_0050e31c(&local_48,2);
      FUN_0045ce2c(*(int *)(param_1 + 0x250));
      piVar4 = FUN_004016bc(&local_5c);
      FUN_004c6c00(*(int *)(param_1 + 0x22c),piVar4);
      FUN_00436240(param_1,local_5c);
      FUN_0050d9d4(&local_5c,2);
    }
    else {
      FUN_00435fac(param_1,&local_8);
      FUN_0047a9e4(*(int **)(param_1 + 0x250));
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
      (**(code **)(*piVar4 + 0x40))();
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
      piVar5 = FUN_004016bc(&local_60);
      FUN_0050dd80(s_update_chemicals_set_00523c4f,&local_c,piVar5);
      piVar5 = FUN_004016bc(&local_68);
      FUN_0050d87c(&local_64);
      FUN_0050da18(&local_60,&local_64,piVar5);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_68);
      FUN_0050d9d4(&local_68,2);
      FUN_0050d9d4(&local_64,2);
      FUN_0050d9d4(&local_60,2);
      pOVar7 = FUN_0050e234(&local_6c);
      pWVar1 = (LPCWSTR)*pOVar7;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x250));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      pVVar6 = FUN_0050df38(&local_7c,&local_8);
      FUN_00455258(iVar3,pVVar6);
      FUN_0050e004(&local_7c,2);
      FUN_0050e31c(&local_6c,2);
      piVar4 = FUN_004016bc(&local_84);
      FUN_004c6c00(*(int *)(param_1 + 0x22c),piVar4);
      pVVar6 = FUN_0050df38(&local_94,&local_84);
      pOVar7 = FUN_0050e234(&local_80);
      pWVar1 = (LPCWSTR)*pOVar7;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x250));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      FUN_00455258(iVar3,pVVar6);
      FUN_0050e004(&local_94,2);
      FUN_0050d9d4(&local_84,2);
      FUN_0050e31c(&local_80,2);
      FUN_0045ce2c(*(int *)(param_1 + 0x250));
    }
  }
LAB_00437167:
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_bc;
  return;
}



// Preserved published name: SpeedButton7Click
// Entry 004371a0, recovered name Published_SpeedButton7Click_004371a0

void Published_SpeedButton7Click_004371a0(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x5245bc);
  pOVar1 = FUN_0050e2e4(&local_8);
  FUN_00435b38(param_1,(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton8Click
// Entry 004371f4, recovered name Published_SpeedButton8Click_004371f4

void Published_SpeedButton8Click_004371f4(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x5245e0);
  pOVar1 = FUN_0050e2e4(&local_8);
  FUN_00435b38(param_1,(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: Edit1Change
// Entry 00438a64, recovered name Published_Edit1Change_00438a64

void Published_Edit1Change_00438a64(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x525204);
  if (*(char *)(param_1 + 0x225) != '\0') {
    piVar1 = FUN_004016bc(&local_8);
    FUN_004c6c00(*(int *)(param_1 + 0x214),piVar1);
    FUN_004387ac(param_1,local_8);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: ListBox1Click
// Entry 00438ad4, recovered name Published_ListBox1Click_00438ad4

void Published_ListBox1Click_00438ad4(int param_1)

{
  LPCWSTR pWVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  VARIANTARG *pVVar8;
  BSTR pOVar9;
  undefined *puVar10;
  undefined4 *in_FS_OFFSET;
  undefined4 local_d4;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined *local_44;
  int local_40;
  int local_3c;
  int local_38;
  VARIANTARG local_34;
  int local_24;
  OLECHAR local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined *local_10;
  int local_c;
  uint *local_8;
  
  FUN_00502f50(0x52547c);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_004016bc(&local_10);
  *(undefined1 *)(param_1 + 0x224) = 0;
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x218) + 0x1f0) + 0x14))();
  if (0 < iVar3) {
    iVar3 = *(int *)(param_1 + 0x218);
    puVar4 = FUN_004016bc(&local_14);
    uVar5 = FUN_0048fcc0(*(int **)(param_1 + 0x218));
    piVar6 = *(int **)(iVar3 + 0x1f0);
    (**(code **)(*piVar6 + 0xc))(piVar6,uVar5,puVar4);
    FUN_0050da04((int *)&local_8,&local_14);
    FUN_0050d9d4(&local_14,2);
    FUN_0050d87c(&local_18);
    cVar2 = FUN_0050dabc(&local_8,&local_18);
    FUN_0050d9d4(&local_18,2);
    if (cVar2 != '\0') {
      *(undefined1 *)(param_1 + 0x225) = 0;
      FUN_004c6c30(*(int *)(param_1 + 0x214),local_8);
      *(undefined1 *)(param_1 + 0x225) = 1;
      FUN_0047a9e4(*(int **)(param_1 + 0x220));
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x220));
      (**(code **)(*piVar6 + 0x40))();
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x220));
      piVar7 = FUN_0050d87c(&local_1c);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_1c,2);
      piVar6 = FUN_004016bc(&local_24);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar6);
      pVVar8 = FUN_0050df38(&local_34,&local_24);
      pOVar9 = FUN_0050e234(&local_20);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x220));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      FUN_00455258(iVar3,pVVar8);
      FUN_0050e004(&local_34,2);
      FUN_0050d9d4(&local_24,2);
      FUN_0050e31c(&local_20,2);
      FUN_0047a9d8(*(int **)(param_1 + 0x220));
      iVar3 = (**(code **)(**(int **)(param_1 + 0x220) + 0x14c))();
      if (0 < iVar3) {
        FUN_0047c964(*(int **)(param_1 + 0x220));
        FUN_0050d87c(&local_38);
        FUN_0050da04(&local_c,&local_38);
        FUN_0050d9d4(&local_38,2);
        piVar6 = FUN_004016bc(&local_44);
        FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar6);
        piVar6 = FUN_004016bc(&local_48);
        FUN_004f6cdc(local_44,piVar6);
        piVar6 = &local_48;
        piVar7 = FUN_004016bc(&local_40);
        FUN_0050d87c(&local_3c);
        FUN_0050da18(&local_c,&local_3c,piVar7);
        piVar7 = FUN_004016bc(&local_4c);
        FUN_0050da18(&local_40,piVar6,piVar7);
        piVar6 = &local_4c;
        piVar7 = FUN_004016bc(&local_54);
        FUN_0050d87c(&local_50);
        FUN_0050da18(piVar6,&local_50,piVar7);
        FUN_0050da04(&local_c,&local_54);
        FUN_0050d9d4(&local_54,2);
        FUN_0050d9d4(&local_50,2);
        FUN_0050d9d4(&local_4c,2);
        FUN_0050d9d4(&local_48,2);
        FUN_0050d9d4((int *)&local_44,2);
        FUN_0050d9d4(&local_40,2);
        FUN_0050d9d4(&local_3c,2);
        piVar6 = FUN_004016bc(&local_5c);
        FUN_0050d87c(&local_58);
        FUN_0050da18(&local_c,&local_58,piVar6);
        FUN_0050da04(&local_c,&local_5c);
        FUN_0050d9d4(&local_5c,2);
        FUN_0050d9d4(&local_58,2);
        piVar6 = FUN_004016bc(&local_68);
        FUN_004c6c00(*(int *)(param_1 + 0x214),piVar6);
        piVar6 = &local_68;
        piVar7 = FUN_004016bc(&local_64);
        FUN_0050d87c(&local_60);
        FUN_0050da18(&local_c,&local_60,piVar7);
        piVar7 = FUN_004016bc(&local_6c);
        FUN_0050da18(&local_64,piVar6,piVar7);
        FUN_0050da04(&local_c,&local_6c);
        FUN_0050d9d4(&local_6c,2);
        FUN_0050d9d4(&local_68,2);
        FUN_0050d9d4(&local_64,2);
        FUN_0050d9d4(&local_60,2);
        piVar6 = FUN_004016bc(&local_74);
        FUN_0050d87c(&local_70);
        FUN_0050da18(&local_c,&local_70,piVar6);
        FUN_0050da04(&local_c,&local_74);
        FUN_0050d9d4(&local_74,2);
        FUN_0050d9d4(&local_70,2);
        piVar6 = FUN_0050d87c(&local_80);
        piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
        puVar4 = FUN_004016bc(&local_84);
        (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
        piVar6 = &local_84;
        piVar7 = FUN_004016bc(&local_7c);
        FUN_0050d87c(&local_78);
        FUN_0050da18(&local_c,&local_78,piVar7);
        piVar7 = FUN_004016bc(&local_88);
        FUN_0050da18(&local_7c,piVar6,piVar7);
        FUN_0050da04(&local_c,&local_88);
        FUN_0050d9d4(&local_88,2);
        FUN_0050d9d4(&local_84,2);
        FUN_0050d9d4(&local_80,2);
        FUN_0050d9d4(&local_7c,2);
        FUN_0050d9d4(&local_78,2);
        piVar6 = FUN_004016bc(&local_90);
        FUN_0050d87c(&local_8c);
        FUN_0050da18(&local_c,&local_8c,piVar6);
        FUN_0050da04(&local_c,&local_90);
        FUN_0050d9d4(&local_90,2);
        FUN_0050d9d4(&local_8c,2);
        piVar6 = FUN_004016bc(&local_98);
        FUN_0050d87c(&local_94);
        FUN_0050da18(&local_c,&local_94,piVar6);
        FUN_0050da04(&local_c,&local_98);
        FUN_0050d9d4(&local_98,2);
        FUN_0050d9d4(&local_94,2);
        piVar6 = FUN_004016bc(&local_a0);
        FUN_0050d87c(&local_9c);
        FUN_0050da18(&local_c,&local_9c,piVar6);
        FUN_0050da04(&local_c,&local_a0);
        FUN_0050d9d4(&local_a0,2);
        FUN_0050d9d4(&local_9c,2);
        piVar6 = FUN_004016bc(&local_a8);
        FUN_0050d87c(&local_a4);
        FUN_0050da18((undefined4 *)PTR__tempdir_005337e8,&local_a4,piVar6);
        FUN_0050da04((int *)&local_10,&local_a8);
        FUN_0050d9d4(&local_a8,2);
        FUN_0050d9d4(&local_a4,2);
        piVar6 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_10,0xffff);
        uVar5 = FUN_00404394(&local_c);
        puVar10 = FUN_00404374(&local_c);
        (**(code **)(*piVar6 + 8))(piVar6,puVar10,uVar5);
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + -4))(piVar6,3);
        }
        *(undefined1 *)(param_1 + 0x224) = 1;
      }
    }
  }
  FUN_0050d9d4((int *)&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4((int *)&local_8,2);
  *in_FS_OFFSET = local_d4;
  return;
}



// Preserved published name: Edit1Change
// Entry 0043acfc, recovered name Published_Edit1Change_0043acfc

void Published_Edit1Change_0043acfc(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x525ed8);
  if (*(char *)(param_1 + 0x225) != '\0') {
    piVar1 = FUN_004016bc(&local_8);
    FUN_004c6c00(*(int *)(param_1 + 0x214),piVar1);
    FUN_0043aa44(param_1,local_8);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: ListBox1Click
// Entry 0043ad6c, recovered name Published_ListBox1Click_0043ad6c

void Published_ListBox1Click_0043ad6c(int param_1)

{
  LPCWSTR pWVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  VARIANTARG *pVVar8;
  BSTR pOVar9;
  undefined *puVar10;
  undefined4 *in_FS_OFFSET;
  undefined4 local_118;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined *local_44;
  int local_40;
  int local_3c;
  int local_38;
  VARIANTARG local_34;
  int local_24;
  OLECHAR local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined *local_10;
  int local_c;
  uint *local_8;
  
  FUN_00502f50(0x52622c);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  FUN_004016bc(&local_10);
  *(undefined1 *)(param_1 + 0x224) = 0;
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x218) + 0x1f0) + 0x14))();
  if (0 < iVar3) {
    iVar3 = *(int *)(param_1 + 0x218);
    puVar4 = FUN_004016bc(&local_14);
    uVar5 = FUN_0048fcc0(*(int **)(param_1 + 0x218));
    piVar6 = *(int **)(iVar3 + 0x1f0);
    (**(code **)(*piVar6 + 0xc))(piVar6,uVar5,puVar4);
    FUN_0050da04((int *)&local_8,&local_14);
    FUN_0050d9d4(&local_14,2);
    FUN_0050d87c(&local_18);
    cVar2 = FUN_0050dabc(&local_8,&local_18);
    FUN_0050d9d4(&local_18,2);
    if (cVar2 != '\0') {
      *(undefined1 *)(param_1 + 0x225) = 0;
      FUN_004c6c30(*(int *)(param_1 + 0x214),local_8);
      *(undefined1 *)(param_1 + 0x225) = 1;
      FUN_0047a9e4(*(int **)(param_1 + 0x220));
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x220));
      (**(code **)(*piVar6 + 0x40))();
      piVar6 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x220));
      piVar7 = FUN_0050d87c(&local_1c);
      (**(code **)(*piVar6 + 0x34))(piVar6,*piVar7);
      FUN_0050d9d4(&local_1c,2);
      piVar6 = FUN_004016bc(&local_24);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar6);
      pVVar8 = FUN_0050df38(&local_34,&local_24);
      pOVar9 = FUN_0050e234(&local_20);
      pWVar1 = (LPCWSTR)*pOVar9;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x220));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      FUN_00455258(iVar3,pVVar8);
      FUN_0050e004(&local_34,2);
      FUN_0050d9d4(&local_24,2);
      FUN_0050e31c(&local_20,2);
      FUN_0047a9d8(*(int **)(param_1 + 0x220));
      iVar3 = (**(code **)(**(int **)(param_1 + 0x220) + 0x14c))();
      if (0 < iVar3) {
        FUN_0047c964(*(int **)(param_1 + 0x220));
        FUN_0050d87c(&local_38);
        FUN_0050da04(&local_c,&local_38);
        FUN_0050d9d4(&local_38,2);
        piVar6 = FUN_004016bc(&local_44);
        FUN_004bc548(*(undefined4 *)PTR_DAT_00533970,piVar6);
        piVar6 = FUN_004016bc(&local_48);
        FUN_004f6cdc(local_44,piVar6);
        piVar6 = &local_48;
        piVar7 = FUN_004016bc(&local_40);
        FUN_0050d87c(&local_3c);
        FUN_0050da18(&local_c,&local_3c,piVar7);
        piVar7 = FUN_004016bc(&local_4c);
        FUN_0050da18(&local_40,piVar6,piVar7);
        piVar6 = &local_4c;
        piVar7 = FUN_004016bc(&local_54);
        FUN_0050d87c(&local_50);
        FUN_0050da18(piVar6,&local_50,piVar7);
        FUN_0050da04(&local_c,&local_54);
        FUN_0050d9d4(&local_54,2);
        FUN_0050d9d4(&local_50,2);
        FUN_0050d9d4(&local_4c,2);
        FUN_0050d9d4(&local_48,2);
        FUN_0050d9d4((int *)&local_44,2);
        FUN_0050d9d4(&local_40,2);
        FUN_0050d9d4(&local_3c,2);
        piVar6 = FUN_004016bc(&local_5c);
        FUN_0050d87c(&local_58);
        FUN_0050da18(&local_c,&local_58,piVar6);
        FUN_0050da04(&local_c,&local_5c);
        FUN_0050d9d4(&local_5c,2);
        FUN_0050d9d4(&local_58,2);
        piVar6 = FUN_004016bc(&local_68);
        FUN_004c6c00(*(int *)(param_1 + 0x214),piVar6);
        piVar6 = &local_68;
        piVar7 = FUN_004016bc(&local_64);
        FUN_0050d87c(&local_60);
        FUN_0050da18(&local_c,&local_60,piVar7);
        piVar7 = FUN_004016bc(&local_6c);
        FUN_0050da18(&local_64,piVar6,piVar7);
        FUN_0050da04(&local_c,&local_6c);
        FUN_0050d9d4(&local_6c,2);
        FUN_0050d9d4(&local_68,2);
        FUN_0050d9d4(&local_64,2);
        FUN_0050d9d4(&local_60,2);
        piVar6 = FUN_0050d87c(&local_70);
        piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
        puVar4 = FUN_004016bc(&local_74);
        (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
        piVar6 = &local_74;
        FUN_0050d87c(&local_78);
        cVar2 = FUN_0050dabc(piVar6,&local_78);
        FUN_0050d9d4(&local_78,2);
        FUN_0050d9d4(&local_74,2);
        FUN_0050d9d4(&local_70,2);
        if (cVar2 != '\0') {
          piVar6 = FUN_0050d87c(&local_84);
          piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
          puVar4 = FUN_004016bc(&local_88);
          (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
          piVar6 = &local_88;
          piVar7 = FUN_004016bc(&local_80);
          FUN_0050d87c(&local_7c);
          FUN_0050da18(&local_c,&local_7c,piVar7);
          piVar7 = FUN_004016bc(&local_8c);
          FUN_0050da18(&local_80,piVar6,piVar7);
          piVar6 = &local_8c;
          piVar7 = FUN_004016bc(&local_94);
          FUN_0050d87c(&local_90);
          FUN_0050da18(piVar6,&local_90,piVar7);
          FUN_0050da04(&local_c,&local_94);
          FUN_0050d9d4(&local_94,2);
          FUN_0050d9d4(&local_90,2);
          FUN_0050d9d4(&local_8c,2);
          FUN_0050d9d4(&local_88,2);
          FUN_0050d9d4(&local_84,2);
          FUN_0050d9d4(&local_80,2);
          FUN_0050d9d4(&local_7c,2);
        }
        piVar6 = FUN_004016bc(&local_9c);
        FUN_0050d87c(&local_98);
        FUN_0050da18(&local_c,&local_98,piVar6);
        FUN_0050da04(&local_c,&local_9c);
        FUN_0050d9d4(&local_9c,2);
        FUN_0050d9d4(&local_98,2);
        piVar6 = FUN_0050d87c(&local_a8);
        piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
        puVar4 = FUN_004016bc(&local_ac);
        (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
        piVar6 = &local_ac;
        piVar7 = FUN_004016bc(&local_a4);
        FUN_0050d87c(&local_a0);
        FUN_0050da18(&local_c,&local_a0,piVar7);
        piVar7 = FUN_004016bc(&local_b0);
        FUN_0050da18(&local_a4,piVar6,piVar7);
        FUN_0050da04(&local_c,&local_b0);
        FUN_0050d9d4(&local_b0,2);
        FUN_0050d9d4(&local_ac,2);
        FUN_0050d9d4(&local_a8,2);
        FUN_0050d9d4(&local_a4,2);
        FUN_0050d9d4(&local_a0,2);
        piVar6 = FUN_004016bc(&local_b8);
        FUN_0050d87c(&local_b4);
        FUN_0050da18(&local_c,&local_b4,piVar6);
        FUN_0050da04(&local_c,&local_b8);
        FUN_0050d9d4(&local_b8,2);
        FUN_0050d9d4(&local_b4,2);
        piVar6 = FUN_0050d87c(&local_c4);
        piVar6 = (int *)FUN_0047b6a8(*(int *)(param_1 + 0x220),(undefined *)*piVar6);
        puVar4 = FUN_004016bc(&local_c8);
        (**(code **)(*piVar6 + 0x58))(piVar6,puVar4);
        piVar6 = &local_c8;
        piVar7 = FUN_004016bc(&local_c0);
        FUN_0050d87c(&local_bc);
        FUN_0050da18(&local_c,&local_bc,piVar7);
        piVar7 = FUN_004016bc(&local_cc);
        FUN_0050da18(&local_c0,piVar6,piVar7);
        FUN_0050da04(&local_c,&local_cc);
        FUN_0050d9d4(&local_cc,2);
        FUN_0050d9d4(&local_c8,2);
        FUN_0050d9d4(&local_c4,2);
        FUN_0050d9d4(&local_c0,2);
        FUN_0050d9d4(&local_bc,2);
        piVar6 = FUN_004016bc(&local_d4);
        FUN_0050d87c(&local_d0);
        FUN_0050da18(&local_c,&local_d0,piVar6);
        FUN_0050da04(&local_c,&local_d4);
        FUN_0050d9d4(&local_d4,2);
        FUN_0050d9d4(&local_d0,2);
        piVar6 = FUN_004016bc(&local_dc);
        FUN_0050d87c(&local_d8);
        FUN_0050da18(&local_c,&local_d8,piVar6);
        FUN_0050da04(&local_c,&local_dc);
        FUN_0050d9d4(&local_dc,2);
        FUN_0050d9d4(&local_d8,2);
        piVar6 = FUN_004016bc(&local_e4);
        FUN_0050d87c(&local_e0);
        FUN_0050da18(&local_c,&local_e0,piVar6);
        FUN_0050da04(&local_c,&local_e4);
        FUN_0050d9d4(&local_e4,2);
        FUN_0050d9d4(&local_e0,2);
        piVar6 = FUN_004016bc(&local_ec);
        FUN_0050d87c(&local_e8);
        FUN_0050da18((undefined4 *)PTR__tempdir_005337e8,&local_e8,piVar6);
        FUN_0050da04((int *)&local_10,&local_ec);
        FUN_0050d9d4(&local_ec,2);
        FUN_0050d9d4(&local_e8,2);
        piVar6 = FUN_004ea6cc((int *)PTR_PTR_004e6f20,'\x01',local_10,0xffff);
        uVar5 = FUN_00404394(&local_c);
        puVar10 = FUN_00404374(&local_c);
        (**(code **)(*piVar6 + 8))(piVar6,puVar10,uVar5);
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + -4))(piVar6,3);
        }
        *(undefined1 *)(param_1 + 0x224) = 1;
      }
    }
  }
  FUN_0050d9d4((int *)&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4((int *)&local_8,2);
  *in_FS_OFFSET = local_118;
  return;
}



// Preserved published name: Button1Click
// Entry 0043d0fc, recovered name Published_Button1Click_0043d0fc

void Published_Button1Click_0043d0fc(int param_1)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_4c;
  uint *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined *local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x526ae8);
  piVar2 = FUN_0050d87c(&local_8);
  FUN_004da1a8(*(int **)(param_1 + 0x228),(uint *)*piVar2);
  FUN_0050d9d4(&local_8,2);
  (**(code **)(*DAT_00526a10 + 0x40))();
  FUN_0043d308(param_1,DAT_00526a10);
  piVar2 = FUN_004016bc(&local_14);
  FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar2);
  piVar2 = &local_14;
  FUN_0050d87c(&local_18);
  bVar1 = FUN_0050daa4(piVar2,&local_18);
  piVar2 = DAT_00526a10;
  piVar3 = FUN_004016bc(&local_10);
  FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
  piVar3 = FUN_004016bc(&local_c);
  FUN_004c6c00(*(int *)(param_1 + 0x218),piVar3);
  _FindStr_qqri17System_AnsiStringt2op19Classes_TStringList(2,local_c,local_10,piVar2,bVar1);
  FUN_0050d9d4(&local_18,2);
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4((int *)&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0043d308(param_1,DAT_00526a10);
  piVar2 = FUN_004016bc(&local_1c);
  uVar4 = (**(code **)(*DAT_00526a10 + 0x14))();
  FUN_004f6a10(uVar4,piVar2);
  piVar2 = &local_1c;
  piVar3 = FUN_004016bc(&local_20);
  FUN_0050dd80(&DAT_00526a34,piVar2,piVar3);
  piVar2 = &local_20;
  piVar3 = FUN_004016bc(&local_28);
  FUN_0050d87c(&local_24);
  FUN_0050da18(piVar2,&local_24,piVar3);
  FUN_004da1a8(*(int **)(param_1 + 0x228),local_28);
  FUN_0050d9d4((int *)&local_28,2);
  FUN_0050d9d4(&local_24,2);
  FUN_0050d9d4(&local_20,2);
  FUN_0050d9d4(&local_1c,2);
  *in_FS_OFFSET = local_4c;
  return;
}



// Preserved published name: Edit1Change
// Entry 0043dbac, recovered name Published_Edit1Change_0043dbac

void Published_Edit1Change_0043dbac(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x5271d0);
  if (DAT_00526d99 != '\0') {
    piVar1 = FUN_004016bc(&local_8);
    FUN_004c6c00(*(int *)(param_1 + 0x214),piVar1);
    FUN_0043d600(param_1,local_8);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton1Click
// Entry 0043dc18, recovered name Published_SpeedButton1Click_0043dc18

void Published_SpeedButton1Click_0043dc18(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x5271f4);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton2Click
// Entry 0043dc74, recovered name Published_SpeedButton2Click_0043dc74

void Published_SpeedButton2Click_0043dc74(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x527218);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton3Click
// Entry 0043dcd0, recovered name Published_SpeedButton3Click_0043dcd0

void Published_SpeedButton3Click_0043dcd0(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x52723c);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton5Click
// Entry 0043dd2c, recovered name Published_SpeedButton5Click_0043dd2c

void Published_SpeedButton5Click_0043dd2c(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x527260);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton6Click
// Entry 0043dd88, recovered name Published_SpeedButton6Click_0043dd88

void Published_SpeedButton6Click_0043dd88(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x527284);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton7Click
// Entry 0043dde4, recovered name Published_SpeedButton7Click_0043dde4

void Published_SpeedButton7Click_0043dde4(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x5272a8);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton8Click
// Entry 0043de40, recovered name Published_SpeedButton8Click_0043de40

void Published_SpeedButton8Click_0043de40(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x5272cc);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton4Click
// Entry 0043de9c, recovered name Published_SpeedButton4Click_0043de9c

void Published_SpeedButton4Click_0043de9c(int param_1)

{
  LPCWSTR pWVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  VARIANTARG *pVVar6;
  BSTR pOVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 local_a8;
  int local_84;
  VARIANTARG local_80;
  int local_70;
  OLECHAR local_6c;
  VARIANTARG local_68;
  OLECHAR local_58;
  int local_54;
  int local_50;
  VARIANTARG local_4c;
  OLECHAR local_3c;
  VARIANTARG local_38;
  int local_28;
  OLECHAR local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x527420);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  iVar3 = FUN_00401740(*(int *)PTR__MainForm_005337bc);
  if (iVar3 == -1) {
    piVar4 = FUN_0050d87c(&local_84);
    FUN_004c1c04((undefined *)*piVar4);
    FUN_0050d9d4(&local_84,2);
  }
  else {
    piVar4 = FUN_004016bc(&local_10);
    FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
    FUN_0050d87c(&local_14);
    bVar2 = FUN_0050dabc(&local_10,&local_14);
    FUN_0050d9d4(&local_14,2);
    FUN_0050d9d4(&local_10,2);
    if (bVar2) {
      iVar3 = *(int *)(param_1 + 0x218);
      piVar4 = FUN_004016bc(&local_18);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
      piVar4 = *(int **)(iVar3 + 0x1f0);
      iVar3 = (**(code **)(*piVar4 + 0x50))(piVar4,local_18);
      FUN_0050d9d4(&local_18,2);
      if (iVar3 < 0) {
        _WebBGetBodyInnerHtml_qqrp26Shdocvw_tlb_TCppWebBrowserp17System_AnsiString
                  (*(int **)(param_1 + 0x244),&local_8);
        FUN_0047a9e4(*(int **)(param_1 + 0x250));
        piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
        (**(code **)(*piVar4 + 0x40))();
        piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
        piVar5 = FUN_0050d87c(&local_1c);
        (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
        FUN_0050d9d4(&local_1c,2);
        piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
        piVar5 = FUN_0050d87c(&local_20);
        (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
        FUN_0050d9d4(&local_20,2);
        piVar4 = FUN_004016bc(&local_28);
        FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
        pVVar6 = FUN_0050df38(&local_38,&local_28);
        pOVar7 = FUN_0050e234(&local_24);
        pWVar1 = (LPCWSTR)*pOVar7;
        iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x250));
        iVar3 = FUN_00453fcc(iVar3,pWVar1);
        FUN_00455258(iVar3,pVVar6);
        FUN_0050e004(&local_38,2);
        FUN_0050d9d4(&local_28,2);
        FUN_0050e31c(&local_24,2);
        pOVar7 = FUN_0050e234(&local_3c);
        pWVar1 = (LPCWSTR)*pOVar7;
        iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x250));
        iVar3 = FUN_00453fcc(iVar3,pWVar1);
        pVVar6 = FUN_0050df38(&local_4c,&local_8);
        FUN_00455258(iVar3,pVVar6);
        FUN_0050e004(&local_4c,2);
        FUN_0050e31c(&local_3c,2);
        FUN_0045ce2c(*(int *)(param_1 + 0x250));
        piVar4 = FUN_004016bc(&local_50);
        FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
        FUN_0043d600(param_1,local_50);
        FUN_0050d9d4(&local_50,2);
      }
      else {
        _WebBGetBodyInnerHtml_qqrp26Shdocvw_tlb_TCppWebBrowserp17System_AnsiString
                  (*(int **)(param_1 + 0x244),&local_8);
        FUN_0047a9e4(*(int **)(param_1 + 0x250));
        piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
        (**(code **)(*piVar4 + 0x40))();
        piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 0x250));
        piVar5 = FUN_0050d87c(&local_54);
        (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
        FUN_0050d9d4(&local_54,2);
        pOVar7 = FUN_0050e234(&local_58);
        pWVar1 = (LPCWSTR)*pOVar7;
        iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x250));
        iVar3 = FUN_00453fcc(iVar3,pWVar1);
        pVVar6 = FUN_0050df38(&local_68,&local_8);
        FUN_00455258(iVar3,pVVar6);
        FUN_0050e004(&local_68,2);
        FUN_0050e31c(&local_58,2);
        piVar4 = FUN_004016bc(&local_70);
        FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
        pVVar6 = FUN_0050df38(&local_80,&local_70);
        pOVar7 = FUN_0050e234(&local_6c);
        pWVar1 = (LPCWSTR)*pOVar7;
        iVar3 = FUN_0045b63c(*(int *)(param_1 + 0x250));
        iVar3 = FUN_00453fcc(iVar3,pWVar1);
        FUN_00455258(iVar3,pVVar6);
        FUN_0050e004(&local_80,2);
        FUN_0050d9d4(&local_70,2);
        FUN_0050e31c(&local_6c,2);
        FUN_0045ce2c(*(int *)(param_1 + 0x250));
      }
    }
  }
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_a8;
  return;
}



// Preserved published name: ListBox1Click
// Entry 0043e4a8, recovered name Published_ListBox1Click_0043e4a8

void Published_ListBox1Click_0043e4a8(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  uint *local_8;
  
  FUN_00502f50(0x5274e0);
  DAT_00526d99 = 0;
  iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x218) + 0x1f0) + 0x14))();
  if (0 < iVar2) {
    iVar2 = *(int *)(param_1 + 0x218);
    puVar3 = FUN_004016bc(&local_8);
    uVar4 = FUN_0048fcc0(*(int **)(param_1 + 0x218));
    piVar1 = *(int **)(iVar2 + 0x1f0);
    (**(code **)(*piVar1 + 0xc))(piVar1,uVar4,puVar3);
    FUN_004c6c30(*(int *)(param_1 + 0x214),local_8);
    FUN_0050d9d4((int *)&local_8,2);
  }
  FUN_0043d8b8(param_1);
  DAT_00526d99 = 1;
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: Button1Click
// Entry 0043fae0, recovered name Published_Button1Click_0043fae0

void Published_Button1Click_0043fae0(int *param_1)

{
  byte bVar1;
  int *piVar2;
  undefined3 extraout_var;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 local_34;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x527ecc);
  piVar2 = FUN_004016bc(&local_8);
  FUN_004c6c00(param_1[0xb6],piVar2);
  FUN_0050d87c(&local_c);
  bVar1 = FUN_0050daa4(&local_8,&local_c);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  if (bVar1 == 0) {
    *(undefined1 *)(param_1 + 0xb9) = 1;
    FUN_004b8834(param_1,extraout_EDX,CONCAT31(extraout_var,bVar1));
    *in_FS_OFFSET = local_34;
  }
  else {
    piVar2 = FUN_0050d87c(&local_10);
    FUN_004c1c04((undefined *)*piVar2);
    FUN_0050d9d4(&local_10,2);
    (**(code **)(*(int *)param_1[0xb6] + 0xb0))();
    *in_FS_OFFSET = local_34;
  }
  return;
}



// Preserved published name: Button2Click
// Entry 0043fbc4, recovered name Published_Button2Click_0043fbc4

void Published_Button2Click_0043fbc4(int *param_1,undefined4 param_2,int param_3)

{
  FUN_004b8834(param_1,param_2,param_3);
  return;
}



// Preserved published name: FormShow
// Entry 0043fbdc, recovered name Published_FormShow_0043fbdc

void Published_FormShow_0043fbdc(int param_1)

{
  *(undefined1 *)(param_1 + 0x2e4) = 0;
  return;
}



// Preserved published name: Edit1KeyPress
// Entry 0043fbf8, recovered name Published_Edit1KeyPress_0043fbf8

void Published_Edit1KeyPress_0043fbf8(int *param_1,undefined4 param_2,char *param_3)

{
  if (*param_3 == '\r') {
    Published_Button1Click_0043fae0(param_1);
  }
  return;
}



// Preserved published name: Button1Click
// Entry 0043fda4, recovered name Published_Button1Click_0043fda4

void Published_Button1Click_0043fda4(int param_1)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_4c;
  uint *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined *local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x5281ac);
  piVar2 = FUN_0050d87c(&local_8);
  FUN_004da1a8(*(int **)(param_1 + 0x228),(uint *)*piVar2);
  FUN_0050d9d4(&local_8,2);
  (**(code **)(*DAT_005280d0 + 0x40))();
  FUN_0043ffb0(param_1,DAT_005280d0);
  piVar2 = FUN_004016bc(&local_14);
  FUN_004c6c00(*(int *)(param_1 + 0x21c),piVar2);
  piVar2 = &local_14;
  FUN_0050d87c(&local_18);
  bVar1 = FUN_0050daa4(piVar2,&local_18);
  piVar2 = DAT_005280d0;
  piVar3 = FUN_004016bc(&local_10);
  FUN_004c6c00(*(int *)(param_1 + 0x220),piVar3);
  piVar3 = FUN_004016bc(&local_c);
  FUN_004c6c00(*(int *)(param_1 + 0x218),piVar3);
  _FindStr_qqri17System_AnsiStringt2op19Classes_TStringList(3,local_c,local_10,piVar2,bVar1);
  FUN_0050d9d4(&local_18,2);
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4((int *)&local_10,2);
  FUN_0050d9d4(&local_c,2);
  FUN_0043ffb0(param_1,DAT_005280d0);
  piVar2 = FUN_004016bc(&local_1c);
  uVar4 = (**(code **)(*DAT_005280d0 + 0x14))();
  FUN_004f6a10(uVar4,piVar2);
  piVar2 = &local_1c;
  piVar3 = FUN_004016bc(&local_20);
  FUN_0050dd80(&DAT_005280f4,piVar2,piVar3);
  piVar2 = &local_20;
  piVar3 = FUN_004016bc(&local_28);
  FUN_0050d87c(&local_24);
  FUN_0050da18(piVar2,&local_24,piVar3);
  FUN_004da1a8(*(int **)(param_1 + 0x228),local_28);
  FUN_0050d9d4((int *)&local_28,2);
  FUN_0050d9d4(&local_24,2);
  FUN_0050d9d4(&local_20,2);
  FUN_0050d9d4(&local_1c,2);
  *in_FS_OFFSET = local_4c;
  return;
}



// Preserved published name: SpeedButton1Click
// Entry 00440b34, recovered name Published_SpeedButton1Click_00440b34

void Published_SpeedButton1Click_00440b34(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x528a64);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton2Click
// Entry 00440b90, recovered name Published_SpeedButton2Click_00440b90

void Published_SpeedButton2Click_00440b90(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x528a88);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton3Click
// Entry 00440bec, recovered name Published_SpeedButton3Click_00440bec

void Published_SpeedButton3Click_00440bec(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x528aac);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton5Click
// Entry 00440c48, recovered name Published_SpeedButton5Click_00440c48

void Published_SpeedButton5Click_00440c48(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x528ad0);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton6Click
// Entry 00440ca4, recovered name Published_SpeedButton6Click_00440ca4

void Published_SpeedButton6Click_00440ca4(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x528af4);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton7Click
// Entry 00440d00, recovered name Published_SpeedButton7Click_00440d00

void Published_SpeedButton7Click_00440d00(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x528b18);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton8Click
// Entry 00440d5c, recovered name Published_SpeedButton8Click_00440d5c

void Published_SpeedButton8Click_00440d5c(int param_1)

{
  BSTR pOVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  OLECHAR local_8;
  
  FUN_00502f50(0x528b3c);
  pOVar1 = FUN_0050e2e4(&local_8);
  _WebBExecCommand_qqrp26Shdocvw_tlb_TCppWebBrowser17System_WideString
            (*(int **)(param_1 + 0x244),(BSTR)*pOVar1);
  FUN_0050e31c(&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: SpeedButton4Click
// Entry 00440db8, recovered name Published_SpeedButton4Click_00440db8

void Published_SpeedButton4Click_00440db8(int param_1)

{
  LPCWSTR pWVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  VARIANTARG *pVVar6;
  BSTR pOVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 local_bc;
  int local_98;
  VARIANTARG local_94;
  int local_84;
  OLECHAR local_80;
  VARIANTARG local_7c;
  OLECHAR local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  VARIANTARG local_58;
  OLECHAR local_48;
  VARIANTARG local_44;
  int local_34;
  OLECHAR local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x528cd0);
  FUN_004016bc(&local_8);
  FUN_004016bc(&local_c);
  iVar3 = FUN_00401740(*(int *)PTR__MainForm_005337bc);
  if (iVar3 == -1) {
    piVar4 = FUN_0050d87c(&local_98);
    FUN_004c1c04((undefined *)*piVar4);
    FUN_0050d9d4(&local_98,2);
    goto LAB_004414bf;
  }
  piVar4 = FUN_004016bc(&local_10);
  FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
  FUN_0050d87c(&local_14);
  bVar2 = FUN_0050dabc(&local_10,&local_14);
  if (bVar2) {
    iVar3 = FUN_0048fcc0(*(int **)(param_1 + 0x24c));
    if (iVar3 < 0) goto LAB_00440e8e;
    bVar2 = true;
  }
  else {
LAB_00440e8e:
    bVar2 = false;
  }
  FUN_0050d9d4(&local_14,2);
  FUN_0050d9d4(&local_10,2);
  if (bVar2) {
    piVar4 = FUN_004016bc(&local_18);
    FUN_004402a4(param_1,piVar4);
    FUN_0050da04(&local_c,&local_18);
    FUN_0050d9d4(&local_18,2);
    iVar3 = *(int *)(param_1 + 0x218);
    piVar4 = FUN_004016bc(&local_1c);
    FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
    piVar4 = *(int **)(iVar3 + 0x1f0);
    iVar3 = (**(code **)(*piVar4 + 0x50))(piVar4,local_1c);
    FUN_0050d9d4(&local_1c,2);
    if (iVar3 < 0) {
      _WebBGetBodyInnerHtml_qqrp26Shdocvw_tlb_TCppWebBrowserp17System_AnsiString
                (*(int **)(param_1 + 0x244),&local_8);
      FUN_0047a9e4(*(int **)(param_1 + 600));
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 600));
      (**(code **)(*piVar4 + 0x40))();
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 600));
      piVar5 = FUN_004016bc(&local_20);
      FUN_0050dd80(s_insert_into_chemics__chemicname__005285b1,&local_c,piVar5);
      piVar5 = FUN_004016bc(&local_28);
      FUN_0050d87c(&local_24);
      FUN_0050da18(&local_20,&local_24,piVar5);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_28);
      FUN_0050d9d4(&local_28,2);
      FUN_0050d9d4(&local_24,2);
      FUN_0050d9d4(&local_20,2);
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 600));
      piVar5 = FUN_0050d87c(&local_2c);
      (**(code **)(*piVar4 + 0x34))(piVar4,*piVar5);
      FUN_0050d9d4(&local_2c,2);
      piVar4 = FUN_004016bc(&local_34);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
      pVVar6 = FUN_0050df38(&local_44,&local_34);
      pOVar7 = FUN_0050e234(&local_30);
      pWVar1 = (LPCWSTR)*pOVar7;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 600));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      FUN_00455258(iVar3,pVVar6);
      FUN_0050e004(&local_44,2);
      FUN_0050d9d4(&local_34,2);
      FUN_0050e31c(&local_30,2);
      pOVar7 = FUN_0050e234(&local_48);
      pWVar1 = (LPCWSTR)*pOVar7;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 600));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      pVVar6 = FUN_0050df38(&local_58,&local_8);
      FUN_00455258(iVar3,pVVar6);
      FUN_0050e004(&local_58,2);
      FUN_0050e31c(&local_48,2);
      FUN_0045ce2c(*(int *)(param_1 + 600));
      piVar4 = FUN_004016bc(&local_5c);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
      FUN_00440508(param_1,local_5c);
      FUN_0050d9d4(&local_5c,2);
    }
    else {
      _WebBGetBodyInnerHtml_qqrp26Shdocvw_tlb_TCppWebBrowserp17System_AnsiString
                (*(int **)(param_1 + 0x244),&local_8);
      FUN_0047a9e4(*(int **)(param_1 + 600));
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 600));
      (**(code **)(*piVar4 + 0x40))();
      piVar4 = (int *)FUN_0045cef8(*(int *)(param_1 + 600));
      piVar5 = FUN_004016bc(&local_60);
      FUN_0050dd80(s_update_chemics_set_005285fe,&local_c,piVar5);
      piVar5 = FUN_004016bc(&local_68);
      FUN_0050d87c(&local_64);
      FUN_0050da18(&local_60,&local_64,piVar5);
      (**(code **)(*piVar4 + 0x34))(piVar4,local_68);
      FUN_0050d9d4(&local_68,2);
      FUN_0050d9d4(&local_64,2);
      FUN_0050d9d4(&local_60,2);
      pOVar7 = FUN_0050e234(&local_6c);
      pWVar1 = (LPCWSTR)*pOVar7;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 600));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      pVVar6 = FUN_0050df38(&local_7c,&local_8);
      FUN_00455258(iVar3,pVVar6);
      FUN_0050e004(&local_7c,2);
      FUN_0050e31c(&local_6c,2);
      piVar4 = FUN_004016bc(&local_84);
      FUN_004c6c00(*(int *)(param_1 + 0x214),piVar4);
      pVVar6 = FUN_0050df38(&local_94,&local_84);
      pOVar7 = FUN_0050e234(&local_80);
      pWVar1 = (LPCWSTR)*pOVar7;
      iVar3 = FUN_0045b63c(*(int *)(param_1 + 600));
      iVar3 = FUN_00453fcc(iVar3,pWVar1);
      FUN_00455258(iVar3,pVVar6);
      FUN_0050e004(&local_94,2);
      FUN_0050d9d4(&local_84,2);
      FUN_0050e31c(&local_80,2);
      FUN_0045ce2c(*(int *)(param_1 + 600));
    }
  }
LAB_004414bf:
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_bc;
  return;
}



// Preserved published name: ListBox2Click
// Entry 004414f8, recovered name Published_ListBox2Click_004414f8

void Published_ListBox2Click_004414f8(int param_1)

{
  FUN_004407c0(param_1);
  return;
}



// Preserved published name: ListBox1Click
// Entry 00441510, recovered name Published_ListBox1Click_00441510

void Published_ListBox1Click_00441510(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  uint *local_8;
  
  FUN_00502f50(0x528d9c);
  DAT_0052845d = 0;
  iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x218) + 0x1f0) + 0x14))();
  if (0 < iVar2) {
    iVar2 = *(int *)(param_1 + 0x218);
    puVar3 = FUN_004016bc(&local_8);
    uVar4 = FUN_0048fcc0(*(int **)(param_1 + 0x218));
    piVar1 = *(int **)(iVar2 + 0x1f0);
    (**(code **)(*piVar1 + 0xc))(piVar1,uVar4,puVar3);
    FUN_004c6c30(*(int *)(param_1 + 0x214),local_8);
    FUN_0050d9d4((int *)&local_8,2);
  }
  FUN_004407c0(param_1);
  DAT_0052845d = 1;
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: Edit1Change
// Entry 004415d0, recovered name Published_Edit1Change_004415d0

void Published_Edit1Change_004415d0(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x528dc0);
  if (DAT_0052845d != '\0') {
    piVar1 = FUN_004016bc(&local_8);
    FUN_004c6c00(*(int *)(param_1 + 0x214),piVar1);
    FUN_00440508(param_1,local_8);
    FUN_0050d9d4(&local_8,2);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: Button1Click
// Entry 00442ba0, recovered name Published_Button1Click_00442ba0

void Published_Button1Click_00442ba0(int param_1)

{
  *(undefined4 *)(param_1 + 0x234) = 1;
  return;
}



// Preserved published name: mi_newpkgClick
// Entry 00443d18, recovered name Published_mi_newpkgClick_00443d18

void Published_mi_newpkgClick_00443d18(int param_1)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 local_40;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  FUN_00502f50(0x52a2a4);
  iVar4 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  if (iVar4 == 0) goto LAB_00443f8a;
  iVar4 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  uVar5 = FUN_00442d0c(param_1,iVar4);
  if (((char)uVar5 == '\0') ||
     (iVar4 = (**(code **)(**(int **)(param_1 + 0x26c) + 0xd8))(), iVar4 != 1)) goto LAB_00443f8a;
  local_8 = (int *)FUN_005020a8(0x14);
  if (local_8 != (int *)0x0) {
    FUN_004016bc(local_8);
    FUN_004016bc(local_8 + 1);
    FUN_004016bc(local_8 + 2);
    FUN_004016bc(local_8 + 3);
  }
  piVar1 = local_8;
  piVar6 = FUN_004016bc(&local_c);
  FUN_00442f24(param_1,piVar6);
  FUN_0050da04(piVar1,&local_c);
  FUN_0050d9d4(&local_c,2);
  *(undefined1 *)(piVar1 + 4) = 0;
  cVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x26c) + 0x2d8) + 0xb4))();
  if (cVar2 == '\0') {
    piVar6 = FUN_004016bc(&local_10);
    FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x26c) + 0x2d4),piVar6);
    piVar6 = &local_10;
    FUN_0050d87c(&local_14);
    bVar3 = FUN_0050daa4(piVar6,&local_14);
    uVar7 = (uint)(bVar3 != 0);
    FUN_0050d9d4(&local_14,2);
    FUN_0050d9d4(&local_10,2);
    if (uVar7 != 0) goto LAB_00443eb3;
    piVar6 = FUN_004016bc(&local_1c);
    FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x26c) + 0x2d4),piVar6);
    FUN_0050da04(piVar1 + 2,&local_1c);
    FUN_0050d9d4(&local_1c,2);
  }
  else {
LAB_00443eb3:
    piVar6 = FUN_004016bc(&local_18);
    iVar4 = FUN_004dcd18(*(int **)(param_1 + 0x214));
    FUN_004430a0(param_1,iVar4,'\0',piVar6);
    FUN_0050da04(piVar1 + 2,&local_18);
    FUN_0050d9d4(&local_18,2);
  }
  iVar4 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  FUN_0050da04(piVar1 + 1,*(undefined4 **)(iVar4 + 0xc));
  uVar5 = FUN_00442d48(param_1,(int)piVar1);
  if ((char)uVar5 != '\0') {
    FUN_004432d4(param_1,piVar1);
  }
LAB_00443f8a:
  *in_FS_OFFSET = local_40;
  return;
}



// Preserved published name: mi_addfileClick
// Entry 00443f98, recovered name Published_mi_addfileClick_00443f98

void Published_mi_addfileClick_00443f98(int param_1)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 local_44;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  FUN_00502f50(0x52a360);
  iVar4 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  if (iVar4 == 0) goto LAB_004442b6;
  iVar4 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  uVar5 = FUN_00442d0c(param_1,iVar4);
  if ((char)uVar5 == '\0') goto LAB_004442b6;
  piVar1 = *(int **)(*(int *)(param_1 + 0x268) + 0x2d8);
  (**(code **)(*piVar1 + 0x5c))(piVar1,1);
  iVar4 = *(int *)(param_1 + 0x268);
  cVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x268) + 0x2d8) + 0xb4))();
  piVar1 = *(int **)(iVar4 + 0x2d4);
  (**(code **)(*piVar1 + 0x5c))(piVar1,cVar2 == '\0');
  iVar4 = (**(code **)(**(int **)(param_1 + 0x268) + 0xd8))();
  if (iVar4 != 1) goto LAB_004442b6;
  local_8 = (int *)FUN_005020a8(0x14);
  if (local_8 != (int *)0x0) {
    FUN_004016bc(local_8);
    FUN_004016bc(local_8 + 1);
    FUN_004016bc(local_8 + 2);
    FUN_004016bc(local_8 + 3);
  }
  piVar1 = local_8;
  piVar6 = FUN_004016bc(&local_c);
  FUN_00442f24(param_1,piVar6);
  FUN_0050da04(piVar1,&local_c);
  FUN_0050d9d4(&local_c,2);
  *(undefined1 *)(piVar1 + 4) = 1;
  cVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x268) + 0x2d8) + 0xb4))();
  if (cVar2 == '\0') {
    piVar6 = FUN_004016bc(&local_10);
    FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x268) + 0x2d4),piVar6);
    piVar6 = &local_10;
    FUN_0050d87c(&local_14);
    bVar3 = FUN_0050daa4(piVar6,&local_14);
    uVar7 = (uint)(bVar3 != 0);
    FUN_0050d9d4(&local_14,2);
    FUN_0050d9d4(&local_10,2);
    if (uVar7 != 0) goto LAB_0044419a;
    piVar6 = FUN_004016bc(&local_1c);
    FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x268) + 0x2d4),piVar6);
    FUN_0050da04(piVar1 + 2,&local_1c);
    FUN_0050d9d4(&local_1c,2);
  }
  else {
LAB_0044419a:
    piVar6 = FUN_004016bc(&local_18);
    iVar4 = FUN_004dcd18(*(int **)(param_1 + 0x214));
    FUN_004430a0(param_1,iVar4,'\x01',piVar6);
    FUN_0050da04(piVar1 + 2,&local_18);
    FUN_0050d9d4(&local_18,2);
  }
  piVar6 = FUN_004016bc(&local_20);
  FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x268) + 0x2e0),piVar6);
  FUN_0050da04(piVar1 + 3,&local_20);
  FUN_0050d9d4(&local_20,2);
  iVar4 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  FUN_0050da04(piVar1 + 1,*(undefined4 **)(iVar4 + 0xc));
  uVar5 = FUN_00442d48(param_1,(int)piVar1);
  if ((char)uVar5 != '\0') {
    FUN_004432d4(param_1,piVar1);
  }
LAB_004442b6:
  *in_FS_OFFSET = local_44;
  return;
}



// Preserved published name: TreeView1Collapsed
// Entry 004442c4, recovered name Published_TreeView1Collapsed_004442c4

void __stdcall Published_TreeView1Collapsed_004442c4(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) == 1) {
    cVar1 = FUN_004dafd4(in_ECX);
    if (cVar1 == '\0') {
      FUN_004dacf8(in_ECX,0);
      FUN_004dad44(in_ECX,0);
    }
  }
  return;
}



// Preserved published name: TreeView1Expanded
// Entry 00444300, recovered name Published_TreeView1Expanded_00444300

void __stdcall Published_TreeView1Expanded_00444300(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    cVar1 = FUN_004dafd4(in_ECX);
    if (cVar1 != '\0') {
      FUN_004dacf8(in_ECX,1);
      FUN_004dad44(in_ECX,1);
    }
  }
  return;
}



// Preserved published name: TreeView1MouseDown
// Entry 00444344, recovered name Published_TreeView1MouseDown_00444344

void Published_TreeView1MouseDown_00444344
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004dcbd0(*(int **)(param_1 + 0x214),param_5,param_4);
  if (iVar1 != 0) {
    iVar2 = FUN_004dcd18(*(int **)(param_1 + 0x214));
    if (iVar2 != iVar1) {
      FUN_004dcd60(*(int **)(param_1 + 0x214),iVar1);
    }
  }
  return;
}



// Preserved published name: mi_delfileClick
// Entry 004449c8, recovered name Published_mi_delfileClick_004449c8

void Published_mi_delfileClick_004449c8(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_004dcd18(*(int **)(param_1 + 0x214));
  iVar2 = FUN_004db168((int)piVar1);
  if (iVar2 != 0) {
    iVar2 = FUN_004db168((int)piVar1);
    FUN_00443858(param_1,(int)piVar1);
    iVar3 = FUN_004db380(iVar2);
    if (iVar3 == 1) {
      FUN_004dafdc(iVar2,'\0');
      FUN_004dafc8(iVar2,'\x01');
      FUN_00443ba8(param_1,'\0');
    }
    FUN_004db750(piVar1);
  }
  return;
}



// Preserved published name: mi_delpkgClick
// Entry 00444a48, recovered name Published_mi_delpkgClick_00444a48

void Published_mi_delpkgClick_00444a48(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_004dcd18(*(int **)(param_1 + 0x214));
  iVar2 = FUN_004db168((int)piVar1);
  if (iVar2 != 0) {
    iVar2 = FUN_004db168((int)piVar1);
    FUN_00443858(param_1,(int)piVar1);
    iVar3 = FUN_004db380(iVar2);
    if (iVar3 == 1) {
      FUN_004dafdc(iVar2,'\0');
      FUN_004dafc8(iVar2,'\x01');
    }
    FUN_004db750(piVar1);
  }
  return;
}



// Preserved published name: TreeView1DblClick
// Entry 00444abc, recovered name Published_TreeView1DblClick_00444abc

void __stdcall Published_TreeView1DblClick_00444abc(void)

{
  return;
}



// Preserved published name: TreeView1Change
// Entry 00444acc, recovered name Published_TreeView1Change_00444acc

void Published_TreeView1Change_00444acc(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((*(char *)(param_1 + 0x274) == '\0') && (param_3 != 0)) {
    uVar1 = FUN_00442d0c(param_1,param_3);
    if ((char)uVar1 == '\0') {
      FUN_00443ba8(param_1,'\x01');
    }
    else {
      FUN_00443ba8(param_1,'\0');
    }
  }
  return;
}



// Preserved published name: mi_modifileClick
// Entry 00444b18, recovered name Published_mi_modifileClick_00444b18

void Published_mi_modifileClick_00444b18(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_00502f50(0x52a4f8);
  piVar2 = *(int **)(*(int *)(param_1 + 0x268) + 0x2d8);
  (**(code **)(*piVar2 + 0x5c))(piVar2,0);
  piVar2 = *(int **)(*(int *)(param_1 + 0x268) + 0x2d4);
  (**(code **)(*piVar2 + 0x5c))(piVar2,0);
  iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  FUN_004c6c30(*(int *)(*(int *)(param_1 + 0x268) + 0x2d4),*(uint **)(iVar1 + 8));
  iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  FUN_004c6c30(*(int *)(*(int *)(param_1 + 0x268) + 0x2e0),*(uint **)(*(int *)(iVar1 + 0xc) + 0xc));
  iVar1 = (**(code **)(**(int **)(param_1 + 0x268) + 0xd8))();
  if (iVar1 == 1) {
    piVar2 = FUN_004016bc(&local_8);
    FUN_004c6c00(*(int *)(*(int *)(param_1 + 0x268) + 0x2e0),piVar2);
    iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
    FUN_0050da04((int *)(*(int *)(iVar1 + 0xc) + 0xc),&local_8);
    FUN_0050d9d4(&local_8,2);
    iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
    FUN_004439b4(param_1,iVar1);
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: TreeView1Edited
// Entry 00444c4c, recovered name Published_TreeView1Edited_00444c4c

void Published_TreeView1Edited_00444c4c
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  FUN_0050da04((int *)(*(int *)(iVar1 + 0xc) + 8),param_4);
  iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  FUN_004439b4(param_1,iVar1);
  return;
}



// Preserved published name: Button1Click
// Entry 004459fc, recovered name Published_Button1Click_004459fc

void Published_Button1Click_004459fc(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  int iVar4;
  undefined2 local_36;
  undefined4 local_2c;
  undefined *local_8;
  
  FUN_00502f50(0x52a87c);
  FUN_00444c98(param_1);
  uVar1 = (**(code **)(**(int **)(param_1 + 0x254) + 0xb4))();
  uVar2 = (**(code **)(**(int **)(param_1 + 600) + 0xb4))();
  local_36 = CONCAT11(uVar2,uVar1);
  iVar4 = *(int *)(param_1 + 0x264);
  piVar3 = FUN_004016bc(&local_8);
  FUN_004c6c00(*(int *)(param_1 + 0x250),piVar3);
  FUN_00444de4(param_1,local_8,local_36,iVar4);
  FUN_0050d9d4((int *)&local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: MyListBox1Click
// Entry 00445a9c, recovered name Published_MyListBox1Click_00445a9c

void Published_MyListBox1Click_00445a9c(int param_1)

{
  int *piVar1;
  int iVar2;
  VARIANTARG *pVVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  BSTR pOVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 local_6c;
  VARIANTARG local_48;
  VARIANTARG local_38;
  VARIANTARG local_28;
  VARIANTARG local_18;
  OLECHAR local_8;
  
  FUN_00502f50(0x52a8d0);
  iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x264) + 0x1f0) + 0x14))();
  if (0 < iVar2) {
    pVVar3 = FUN_004037cc(&local_28);
    FUN_00403810(pVVar3);
    pVVar3 = FUN_004037cc(&local_38);
    uVar4 = FUN_00403810(pVVar3);
    pVVar3 = FUN_004037cc(&local_48);
    uVar5 = FUN_00403810(pVVar3);
    iVar2 = *(int *)(param_1 + 0x264);
    uVar6 = FUN_0048fcc0(*(int **)(param_1 + 0x264));
    piVar1 = *(int **)(iVar2 + 0x1f0);
    iVar2 = *piVar1;
    (**(code **)(iVar2 + 0x18))(piVar1,uVar6,iVar2,uVar5,uVar4);
    pOVar7 = FUN_0050e2a8(&local_8);
    FUN_00404d4c(pOVar7);
    pVVar3 = FUN_004037cc(&local_18);
    FUN_00403810(pVVar3);
    _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
              (*(int **)(param_1 + 0x270));
    FUN_004038c8(&local_48,2);
    FUN_004038c8(&local_38,2);
    FUN_004038c8(&local_28,2);
    FUN_004038c8(&local_18,2);
    FUN_0050e31c(&local_8,2);
  }
  *in_FS_OFFSET = local_6c;
  return;
}



// Preserved published name: TreeView1Click
// Entry 00445bf8, recovered name Published_TreeView1Click_00445bf8

void Published_TreeView1Click_00445bf8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  VARIANTARG *pVVar3;
  BSTR pOVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_70;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  VARIANTARG local_2c;
  VARIANTARG local_1c;
  OLECHAR local_c;
  int local_8;
  
  FUN_00502f50(0x52a944);
  FUN_004016bc(&local_8);
  iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
  if (iVar1 != 0) {
    iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
    uVar2 = FUN_00442d0c(param_1,iVar1);
    if ((char)uVar2 == '\0') {
      iVar1 = FUN_004dcd18(*(int **)(param_1 + 0x214));
      FUN_0050da04(&local_8,(undefined4 *)(*(int *)(iVar1 + 0xc) + 0xc));
      pVVar3 = FUN_004037cc(&local_2c);
      FUN_00403810(pVVar3);
      pVVar3 = FUN_004037cc(&local_3c);
      FUN_00403810(pVVar3);
      pVVar3 = FUN_004037cc(&local_4c);
      FUN_00403810(pVVar3);
      pVVar3 = FUN_004037cc(&local_1c);
      FUN_00403810(pVVar3);
      pOVar4 = FUN_0050e2a8(&local_c);
      FUN_00404d4c(pOVar4);
      _Shdocvw_tlb_TCppWebBrowser_Navigate_qqrpbp24_TVariantT_10tagVARIANT_t2t2t2
                (*(int **)(param_1 + 0x270));
      FUN_004038c8(&local_4c,2);
      FUN_004038c8(&local_3c,2);
      FUN_004038c8(&local_2c,2);
      FUN_004038c8(&local_1c,2);
      FUN_0050e31c(&local_c,2);
    }
  }
  FUN_0050d9d4(&local_8,2);
  *in_FS_OFFSET = local_70;
  return;
}



// Preserved published name: TreeView1KeyUp
// Entry 00445d7c, recovered name Published_TreeView1KeyUp_00445d7c

void Published_TreeView1KeyUp_00445d7c(int param_1,undefined4 param_2,short *param_3)

{
  if ((((*param_3 == 0x26) || (*param_3 == 0x28)) || (*param_3 == 0x27)) || (*param_3 == 0x25)) {
    Published_TreeView1Click_00445bf8(param_1);
  }
  return;
}



// Preserved published name: SpeedButton1Click
// Entry 004472dc, recovered name Published_SpeedButton1Click_004472dc

void Published_SpeedButton1Click_004472dc(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  uint *puStack_8;
  
  FUN_00502f50(0x52b3d4);
  cVar1 = (**(code **)(**(int **)(param_1 + 0x2f0) + 0x3c))();
  if (cVar1 != '\0') {
    piVar2 = FUN_004016bc(&puStack_8);
    FUN_004c119c(*(int *)(param_1 + 0x2f0),piVar2);
    FUN_004c6c30(*(int *)(param_1 + 0x2e0),puStack_8);
    FUN_0050d9d4((int *)&puStack_8,2);
  }
  *in_FS_OFFSET = uStack_2c;
  return;
}



// Preserved published name: CheckBox1Click
// Entry 00447358, recovered name Published_CheckBox1Click_00447358

void Published_CheckBox1Click_00447358(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d8) + 0xb4))();
  iVar1 = **(int **)(param_1 + 0x2d4);
  (**(code **)(iVar1 + 0x5c))(*(int **)(param_1 + 0x2d4),cVar2 == '\0',iVar1,param_2);
  return;
}



// Preserved published name: Button1Click
// Entry 00447394, recovered name Published_Button1Click_00447394

void Published_Button1Click_00447394(int param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_34;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00502f50(0x52b414);
  piVar2 = FUN_004016bc(&local_8);
  FUN_004c6c00(*(int *)(param_1 + 0x2e0),piVar2);
  FUN_0050d87c(&local_c);
  bVar1 = FUN_0050dabc(&local_8,&local_c);
  FUN_0050d9d4(&local_c,2);
  FUN_0050d9d4(&local_8,2);
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x234) = 1;
  }
  else {
    piVar2 = FUN_0050d87c(&local_10);
    FUN_004c1c04((undefined *)*piVar2);
    FUN_0050d9d4(&local_10,2);
    (**(code **)(**(int **)(param_1 + 0x2e0) + 0xb0))();
  }
  *in_FS_OFFSET = local_34;
  return;
}



// Preserved published name: Button2Click
// Entry 0044746c, recovered name Published_Button2Click_0044746c

void Published_Button2Click_0044746c(int param_1)

{
  *(undefined4 *)(param_1 + 0x234) = 2;
  return;
}



// Preserved published name: Button1Click
// Entry 004475e8, recovered name Published_Button1Click_004475e8

void Published_Button1Click_004475e8(int param_1)

{
  *(undefined4 *)(param_1 + 0x234) = 1;
  return;
}



// Preserved published name: Button2Click
// Entry 00447608, recovered name Published_Button2Click_00447608

void Published_Button2Click_00447608(int param_1)

{
  *(undefined4 *)(param_1 + 0x234) = 2;
  return;
}



// Preserved published name: FormShow
// Entry 0045dab0, recovered name Published_FormShow_0045dab0

void Published_FormShow_0045dab0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004c6664(*(int **)(param_1 + 0x2d0));
  if (iVar1 <= *(int *)(*(int *)(param_1 + 0x2d8) + 0x38) +
               *(int *)(*(int *)(param_1 + 0x2d8) + 0x30)) {
    iVar1 = FUN_004c6664(*(int **)(param_1 + 0x2d0));
    FUN_004c6438(*(int **)(param_1 + 0x2d8),
                 (iVar1 - *(int *)(*(int *)(param_1 + 0x2d8) + 0x30)) + -5);
  }
  return;
}



