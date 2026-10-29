/* GHIDRA PSEUDOCODE FOR PUBLISHED METHOD ENTRIES; NOT ORIGINAL/BUILDABLE SOURCE.
Metadata-seeded entries supplement default analysis. Names preserve published names
with synthetic prefix and address suffix; original class ownership/signatures unknown.
SHA256: 8d7a0b3e7e45e5193b6f40bc4cad05d96b8cfca8d26cf18edd7c77b448d364c3 */

// Entry 0045ace0, recovered name Published_FormCreate_0045ace0

void Published_FormCreate_0045ace0(int param_1)

{
  int iVar1;
  
  *(ushort *)PTR_DAT_0045cec8 = *(ushort *)PTR_DAT_0045cec8 | 0x40;
  iVar1 = *(int *)(param_1 + 0x2c8);
  *(int *)(iVar1 + 0x120) = param_1;
  *(undefined1 **)(iVar1 + 0x11c) = &LAB_0045b744;
  return;
}



// Entry 0045ad04, recovered name Published_FormDestroy_0045ad04

void Published_FormDestroy_0045ad04(int param_1)

{
  FUN_004176e0(*(int **)(*(int *)(param_1 + 0x2c8) + 0x118),(undefined4 *)0x0);
  return;
}



// Entry 0045ad18, recovered name Published_ButtonConvertClick_0045ad18

/* WARNING: Removing unreachable block (ram,0x0045b1a8) */

void Published_ButtonConvertClick_0045ad18(int param_1)

{
  longlong lVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  WPARAM WVar5;
  uint uVar6;
  int iVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar8;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint extraout_ECX_03;
  uint uVar9;
  uint extraout_ECX_04;
  uint extraout_ECX_05;
  uint extraout_EDX;
  int extraout_EDX_00;
  undefined4 extraout_EDX_01;
  uint extraout_EDX_02;
  undefined4 *in_FS_OFFSET;
  bool bVar10;
  undefined4 uStackY_1d4;
  undefined1 *puStackY_1d0;
  undefined1 *puStackY_1cc;
  undefined4 uStackY_1c8;
  undefined1 *puStackY_1c4;
  undefined1 *puStackY_1c0;
  undefined4 uStackY_1bc;
  undefined1 *puStackY_1b8;
  undefined1 *puStackY_1b4;
  undefined4 uStackY_1b0;
  undefined1 *puStackY_1ac;
  undefined1 *puStackY_1a8;
  undefined4 uStackY_1a4;
  undefined1 *puStackY_1a0;
  undefined1 *puStackY_19c;
  undefined4 uStackY_198;
  undefined4 uStackY_194;
  undefined4 uStackY_190;
  undefined1 *puStackY_18c;
  undefined1 *puStackY_188;
  undefined4 uStackY_184;
  undefined4 uStackY_180;
  undefined4 uStackY_17c;
  undefined4 uStackY_178;
  undefined4 uStackY_174;
  undefined4 uStackY_170;
  uint uStackY_16c;
  int *piStackY_168;
  undefined4 uStackY_164;
  undefined1 *puStackY_160;
  undefined1 *puStackY_15c;
  undefined4 uStackY_158;
  undefined4 uVar11;
  undefined4 uStack_13c;
  undefined1 *puStack_138;
  undefined1 *puStack_134;
  undefined4 uStack_130;
  undefined4 *puStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined1 *puStack_11c;
  undefined1 *puStack_118;
  undefined4 *puStack_114;
  undefined *puStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined1 *puStack_100;
  undefined1 *puStack_fc;
  undefined4 uStack_f8;
  undefined1 *puStack_f4;
  undefined1 *puStack_f0;
  undefined4 uStack_ec;
  undefined1 *puStack_e8;
  undefined1 *puStack_e4;
  undefined4 *local_d4;
  undefined1 local_ce [10];
  uint local_c4;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  int local_a0;
  int local_34;
  uint local_30;
  int *local_2c;
  int local_28;
  uint local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  puStack_e4 = &stack0xfffffffc;
  local_d4 = (undefined4 *)0x0;
  puStack_e8 = &LAB_0045b4a8;
  uStack_ec = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_ec;
  piVar3 = *(int **)(*(int *)(param_1 + 0x2e0) + 0x204);
  puStack_f0 = (undefined1 *)0x45ad56;
  local_8 = param_1;
  (**(code **)(*piVar3 + 0x58))(piVar3,s_avifile_txt_0045b4c0);
  piVar3 = *(int **)(*(int *)(local_8 + 0x2e0) + 0x204);
  puStack_f0 = (undefined1 *)0x45ad72;
  (**(code **)(*piVar3 + 0xc))(piVar3,0,&local_d4);
  puStack_f0 = (undefined1 *)0x45ad85;
  FUN_004038c8((int *)(local_8 + 0x2e4),local_d4);
  puStack_f0 = (undefined1 *)0x45ad9b;
  FUN_004176e0(*(int **)(*(int *)(local_8 + 0x2c8) + 0x118),(undefined4 *)0x0);
  *(undefined1 *)(local_8 + 0x2e8) = 0;
  puStack_f0 = (undefined1 *)0x45adb5;
  FUN_0043f640(*(int *)PTR_DAT_0045d020,-0x13);
  puStack_f4 = &LAB_0045b488;
  uStack_f8 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_f8;
  puStack_fc = (undefined1 *)0x45adc8;
  puStack_f0 = &stack0xfffffffc;
  AVIFileInit();
  puStack_100 = &LAB_0045b465;
  uStack_104 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_104;
  uStack_108 = 0;
  uStack_10c = 0x20;
  puStack_110 = (undefined *)0x45ade8;
  puStack_fc = &stack0xfffffffc;
  puStack_110 = FUN_00403cb4(*(undefined **)(local_8 + 0x2e4));
  puStack_114 = &local_c;
  puStack_118 = (undefined1 *)0x45adf2;
  iVar2 = AVIFileOpenA();
  if (iVar2 != 0) {
    puStack_118 = (undefined1 *)0x45ae07;
    piVar3 = FUN_00408b20((int *)PTR_DAT_00406ae4,'\x01',
                          (undefined4 *)s_Failed_to_open_AVI_file_0045b4d4);
    puStack_118 = (undefined1 *)0x45ae0c;
    FUN_004032e8(piVar3);
  }
  puStack_11c = &LAB_0045b44b;
  uStack_120 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_120;
  uStack_124 = 0;
  uStack_128 = 0x73646976;
  puStack_12c = &local_10;
  uStack_130 = local_c;
  puStack_134 = (undefined1 *)0x45ae2e;
  puStack_118 = &stack0xfffffffc;
  iVar2 = AVIFileGetStream();
  if (iVar2 != 0) {
    puStack_134 = (undefined1 *)0x45ae43;
    piVar3 = FUN_00408b20((int *)PTR_DAT_00406ae4,'\x01',
                          (undefined4 *)s_Failed_to_open_AVI_stream_0045b4f4);
    puStack_134 = (undefined1 *)0x45ae48;
    FUN_004032e8(piVar3);
  }
  puStack_138 = &LAB_0045b42d;
  uStack_13c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_13c;
  puStack_134 = &stack0xfffffffc;
  iVar2 = AVIStreamInfo();
  if (iVar2 != 0) {
    piVar3 = FUN_00408b20((int *)PTR_DAT_00406ae4,'\x01',
                          (undefined4 *)s_Failed_to_get_AVI_stream_info_0045b518);
    FUN_004032e8(piVar3);
  }
  if (local_a8 == 0) {
    local_30 = (int)local_ac / 100;
  }
  else {
    if ((int)local_a8 < 0) {
      local_a8 = thunk_FUN_0040271c(local_a8);
    }
    iVar2 = 100;
    if ((int)local_ac < 0) {
      local_ac = thunk_FUN_0040271c(local_ac);
    }
    uStackY_158 = 0x45aeb0;
    local_30 = MulDiv(local_ac,iVar2,local_a8);
  }
  uVar11 = 0;
  uStackY_158 = local_10;
  puStackY_15c = (undefined1 *)0x45aed7;
  iVar2 = AVIStreamReadFormat();
  if (iVar2 != 0) {
    puStackY_15c = (undefined1 *)0x45aeec;
    piVar3 = FUN_00408b20((int *)PTR_DAT_00406ae4,'\x01',
                          (undefined4 *)s_Failed_to_get_AVI_stream_format_s_0045b540);
    puStackY_15c = (undefined1 *)0x45aef1;
    FUN_004032e8(piVar3);
  }
  local_18 = 0;
  if (0 < local_28) {
    puStackY_15c = (undefined1 *)0x45af04;
    local_18 = FUN_00402690(local_28);
  }
  puStackY_160 = &LAB_0045b40f;
  uStackY_164 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_164;
  piStackY_168 = &local_28;
  uStackY_16c = local_18;
  uStackY_170 = 0;
  uStackY_174 = local_10;
  uStackY_178 = 0x45af28;
  puStackY_15c = &stack0xfffffffc;
  iVar2 = AVIStreamReadFormat();
  if (iVar2 != 0) {
    uStackY_178 = 0x45af3d;
    piVar3 = FUN_00408b20((int *)PTR_DAT_00406ae4,'\x01',
                          (undefined4 *)s_Failed_to_get_AVI_stream_format_0045b570);
    uStackY_178 = 0x45af42;
    FUN_004032e8(piVar3);
  }
  uStackY_178 = 1000;
  uStackY_17c = 0;
  uStackY_180 = 0;
  uStackY_184 = local_10;
  puStackY_188 = (undefined1 *)0x45af54;
  iVar2 = AVIStreamBeginStreaming();
  if (iVar2 != 0) {
    puStackY_188 = (undefined1 *)0x45af69;
    piVar3 = FUN_00408b20((int *)PTR_DAT_00406ae4,'\x01',
                          (undefined4 *)s_Failed_to_start_AVI_stream_0045b598);
    puStackY_188 = (undefined1 *)0x45af6e;
    FUN_004032e8(piVar3);
  }
  puStackY_18c = &LAB_0045b3ec;
  uStackY_190 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_190;
  uStackY_194 = 0;
  uStackY_198 = local_10;
  puStackY_19c = (undefined1 *)0x45af87;
  puStackY_188 = &stack0xfffffffc;
  local_14 = AVIStreamGetFrameOpen();
  uVar8 = extraout_ECX;
  if (local_14 == 0) {
    puStackY_19c = (undefined1 *)0x45afa1;
    piVar3 = FUN_00408b20((int *)PTR_DAT_00406ae4,'\x01',
                          (undefined4 *)s_Failed_to_start_AVI_decompressio_0045b5bc);
    puStackY_19c = (undefined1 *)0x45afa6;
    FUN_004032e8(piVar3);
    uVar8 = extraout_ECX_00;
  }
  puStackY_1a0 = &LAB_0045b3ce;
  uStackY_1a4 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_1a4;
  puStackY_1a8 = (undefined1 *)0x45afc0;
  puStackY_19c = &stack0xfffffffc;
  local_1c = (int *)FUN_00402c0c((int *)PTR_PTR_0040becc,'\x01',uVar8);
  puStackY_1ac = &LAB_0045b3b0;
  uStackY_1b0 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_1b0;
  puStackY_1b4 = (undefined1 *)0x45afdd;
  puStackY_1a8 = &stack0xfffffffc;
  local_20 = FUN_0041958c((int *)PTR_PTR_004139cc,'\x01',extraout_ECX_01);
  puStackY_1b8 = &LAB_0045b393;
  uStackY_1bc = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_1bc;
  puStackY_1c0 = (undefined1 *)0x45affa;
  puStackY_1b4 = &stack0xfffffffc;
  local_2c = FUN_00451b50((int *)PTR_PTR_00442fc0,'\x01',extraout_ECX_02);
  puStackY_1c4 = &LAB_0045b376;
  uStackY_1c8 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_1c8;
  *(undefined1 *)((int)local_2c + 0x2e) = 6;
  *(undefined1 *)(local_2c + 0xd) = 1;
  uVar4 = local_a4;
  puStackY_1c0 = &stack0xfffffffc;
  if ((int)local_a4 < 0) {
    puStackY_1cc = (undefined1 *)0x45b028;
    puStackY_1c0 = &stack0xfffffffc;
    thunk_FUN_0040271c((uint)local_2c);
    uVar4 = extraout_EDX;
  }
  puStackY_1cc = (undefined1 *)0x45b036;
  uVar4 = FUN_004587f4(*(int **)(local_8 + 0x2dc),uVar4);
  iVar2 = local_a0;
  if (local_a0 < 0) {
    puStackY_1cc = (undefined1 *)0x45b045;
    thunk_FUN_0040271c(uVar4);
    iVar2 = extraout_EDX_00;
  }
  puStackY_1cc = (undefined1 *)0x45b053;
  FUN_00458800(*(int **)(local_8 + 0x2dc),iVar2);
  piVar3 = *(int **)(local_8 + 0x2dc);
  puStackY_1cc = (undefined1 *)0x45b063;
  WVar5 = FUN_004585f0(piVar3);
  puStackY_1cc = (undefined1 *)0x45b06c;
  uVar4 = FUN_00458810(piVar3,WVar5);
  puStackY_1d0 = &LAB_0045b359;
  uStackY_1d4 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_1d4;
  puStackY_1cc = &stack0xfffffffc;
  if ((int)local_a4 < 0) {
    puStackY_1cc = &stack0xfffffffc;
    thunk_FUN_0040271c(uVar4);
  }
  uVar4 = local_a0 - 1;
  if (local_a0 == 0) {
    uVar4 = thunk_FUN_0040271c(0xffffffff);
  }
  if ((int)uVar4 < 0) {
    uVar4 = thunk_FUN_0040271c(uVar4);
  }
  if ((int)local_a4 <= (int)uVar4) {
    local_34 = (uVar4 - local_a4) + 1;
    uVar4 = local_a4;
    do {
      FUN_00458810(*(int **)(local_8 + 0x2dc),uVar4);
      FUN_00441064(*(int *)PTR_DAT_0045cf08,extraout_EDX_01,extraout_ECX_03);
      if (*(char *)(local_8 + 0x2e8) != '\0') {
        FUN_00403388();
        puStackY_1cc = (undefined1 *)0x45b0e0;
        FUN_00403388();
        puStackY_1c0 = (undefined1 *)0x45b0e5;
        FUN_00403388();
        puStackY_1b4 = (undefined1 *)0x45b0ea;
        FUN_00403388();
        puStackY_1a8 = (undefined1 *)0x45b0ef;
        FUN_00403388();
        puStackY_19c = (undefined1 *)0x45b0f4;
        FUN_00403388();
        uStackY_190 = 0x45b0f9;
        FUN_00403388();
        uStackY_184 = 0x45b0fe;
        FUN_00403388();
        uStackY_178 = 0x45b103;
        FUN_00403388();
        uStackY_16c = 0x45b108;
        FUN_00403388();
        puStackY_160 = (undefined1 *)0x45b10d;
        FUN_00403388();
        *in_FS_OFFSET = uVar11;
        FUN_00403874((int *)&local_d4);
        return;
      }
      iVar2 = AVIStreamGetFrame();
      if (iVar2 == 0) {
        piVar3 = FUN_00408b20((int *)PTR_DAT_00406ae4,'\x01',
                              (undefined4 *)s_Failed_to_decompress_AVI_frame_0045b5e8);
        FUN_004032e8(piVar3);
      }
      lVar1 = (longlong)*(int *)(local_18 + 0x20) * 4;
      uVar9 = (uint)lVar1;
      uVar6 = local_18;
      if ((int)uVar9 != lVar1) {
        uVar6 = thunk_FUN_0040271c(local_18);
        uVar9 = extraout_ECX_04;
      }
      if ((int)uVar9 < 0) {
        thunk_FUN_0040271c(uVar6);
        uVar9 = extraout_ECX_05;
      }
      FUN_004027a8((undefined4 *)(local_18 + 0x28),(undefined4 *)(iVar2 + 0x28),uVar9);
      FUN_00402944((undefined4 *)local_ce,0xe,0);
      local_ce._0_2_ = 0x4d42;
      local_ce._2_4_ = 0;
      local_c4 = 0xe;
      if (*(ushort *)(iVar2 + 0xe) < 9) {
        lVar1 = (longlong)(1 << ((byte)*(ushort *)(iVar2 + 0xe) & 0x1f)) * 4;
        uVar6 = (uint)lVar1;
        if ((int)uVar6 != lVar1) {
          uVar6 = thunk_FUN_0040271c(uVar6);
        }
        bVar10 = CARRY4(local_c4,uVar6);
        local_c4 = local_c4 + uVar6;
        if (bVar10) {
          thunk_FUN_0040271c(uVar6);
        }
      }
      else if ((*(uint *)(iVar2 + 0x10) & 3) == 3) {
        local_c4 = 0x1a;
        local_ce._2_4_ = 0;
        local_ce._0_2_ = 0x4d42;
      }
      uVar6 = *(uint *)(iVar2 + 0x14) + local_c4;
      if (CARRY4(*(uint *)(iVar2 + 0x14),local_c4)) {
        uVar6 = thunk_FUN_0040271c(uVar6);
      }
      if ((int)uVar6 < 0) {
        uVar6 = thunk_FUN_0040271c(uVar6);
      }
      local_24 = uVar6;
      FUN_0040efd0(local_1c);
      uVar6 = (**(code **)(*local_1c + 8))(local_1c,local_ce,0xe);
      if (SCARRY4(local_24,0x1a)) {
        thunk_FUN_0040271c(uVar6);
      }
      (**(code **)(*local_1c + 8))(local_1c,iVar2);
      FUN_0040ec34(local_1c,0);
      (**(code **)(*local_20 + 0x50))(local_20,local_1c);
      iVar2 = FUN_00452d38(local_2c,local_20);
      if (iVar2 == 0) {
        iVar7 = FUN_0044f9ac(local_2c[7],0);
        piVar3 = FUN_0044f7e8((int *)PTR_PTR_00442dfc,'\x01',iVar7);
        *(undefined2 *)(piVar3 + 6) = 0;
        iVar7 = FUN_0044f9ac(local_2c[7],0);
        FUN_0044885c(*(int *)(iVar7 + 0x30),piVar3);
      }
      iVar7 = FUN_0044f9ac(local_2c[7],iVar2);
      piVar3 = FUN_0044ed64((int *)PTR_PTR_0044299c,'\x01',iVar7);
      uVar6 = local_30;
      if (0xffff < local_30) {
        thunk_FUN_0040271c((uint)piVar3);
        uVar6 = extraout_EDX_02;
      }
      FUN_0044eec4((int)piVar3,(short)uVar6);
      iVar2 = FUN_0044f9ac(local_2c[7],iVar2);
      FUN_0044885c(*(int *)(iVar2 + 0x30),piVar3);
      piVar3 = *(int **)(*(int *)(local_8 + 0x2c8) + 0x118);
      (**(code **)(*piVar3 + 8))(piVar3,local_20);
      (**(code **)(**(int **)(local_8 + 0x2c8) + 0x84))();
      uVar4 = uVar4 + 1;
      local_34 = local_34 + -1;
    } while (local_34 != 0);
  }
  piVar3 = *(int **)(*(int *)(local_8 + 0x2c8) + 0x118);
  (**(code **)(*piVar3 + 8))(piVar3,local_2c);
  (**(code **)(**(int **)(local_8 + 0x2d4) + 0x60))(*(int **)(local_8 + 0x2d4),1);
  (**(code **)(**(int **)(local_8 + 0x2d4) + 0xb4))();
  *in_FS_OFFSET = uStackY_1d4;
  puStackY_1cc = &LAB_0045b360;
  piVar3 = *(int **)(local_8 + 0x2dc);
  puStackY_1d0 = (undefined1 *)0x45b34f;
  WVar5 = FUN_004585f0(piVar3);
  puStackY_1d0 = (undefined1 *)0x45b358;
  FUN_00458810(piVar3,WVar5);
  return;
}



// Entry 0045b608, recovered name Published_ButtonSaveClick_0045b608

void Published_ButtonSaveClick_0045b608(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = 0;
  puStack_18 = &LAB_0045b720;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x2c8) + 0x118) + 4);
  if (piVar1 != (int *)0x0) {
    puStack_20 = (undefined1 *)0x45b643;
    uVar3 = FUN_00402db4(piVar1,(int)PTR_PTR_00442fc0);
    if ((char)uVar3 != '\0') {
      puStack_20 = (undefined1 *)0x45b656;
      cVar2 = (**(code **)(**(int **)(param_1 + 0x2d8) + 0x3c))();
      if (cVar2 != '\0') {
        puStack_20 = (undefined1 *)0x45b66e;
        FUN_0043f640(*(int *)PTR_DAT_0045d020,-0xb);
        puStack_24 = &LAB_0045b703;
        uStack_28 = *in_FS_OFFSET;
        *in_FS_OFFSET = &uStack_28;
        puStack_20 = &stack0xfffffffc;
        FUN_00451e98(*(int **)(*(int *)(*(int *)(param_1 + 0x2c8) + 0x118) + 4),DAT_0045b72c,'\0');
        FUN_00451e34(*(int *)(*(int *)(*(int *)(param_1 + 0x2c8) + 0x118) + 4),extraout_EDX,
                     extraout_ECX);
        FUN_00457090(*(int *)(param_1 + 0x2d8),&local_8);
        FUN_00417790(*(int *)(*(int *)(param_1 + 0x2c8) + 0x118));
        (**(code **)(**(int **)(param_1 + 0x2c8) + 0x78))();
        *in_FS_OFFSET = 8;
        uStack_28 = 0x45b70a;
        FUN_0043f640(*(int *)PTR_DAT_0045d020,0);
        FUN_00457aac((uint *)&DAT_0045b738);
        return;
      }
    }
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0045b727;
  puStack_18 = (undefined1 *)0x45b71f;
  FUN_00403874(&local_8);
  return;
}



