/* Published event names recovered from executable metadata.
   Bodies are Ghidra pseudocode, not original/buildable source.
   Class ownership and original signatures are unresolved. */

// Preserved published name: Button1Click
// Entry 0040162c, recovered name Published_Button1Click_0040162c

uint Published_Button1Click_0040162c(int *param_1,undefined4 param_2)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  undefined4 uVar4;
  HWND hWnd;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  HBITMAP pHVar9;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  uint *in_FS_OFFSET;
  LPCSTR lpText;
  LPCSTR lpCaption;
  UINT uType;
  int local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c [3];
  int local_180;
  undefined4 local_17c [11];
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined2 local_140;
  undefined2 local_13e;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  int *local_c4;
  int *local_c0;
  int *local_bc;
  int *local_b8;
  int *local_b4;
  int *local_b0;
  LPVOID local_a8;
  HGLOBAL local_a4;
  undefined4 *local_a0;
  int local_90;
  undefined4 local_8c;
  int *local_88;
  uint local_84;
  undefined2 local_74;
  int local_68;
  int local_60;
  uint *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined *local_40;
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
  
  local_8c = param_2;
  local_88 = param_1;
  FUN_0044effc(0x45a83c);
  local_a0 = local_17c;
  FUN_004023e8(local_18c);
  FUN_004023e8(&local_19c);
  cVar1 = (**(code **)(*(int *)local_88[0xd5] + 0x3c))();
  if (cVar1 == '\0') {
    FUN_00446918((undefined *)local_88[0xe1]);
    *in_FS_OFFSET = local_84;
    return local_84;
  }
  FUN_00446918((undefined *)local_88[0xe1]);
  local_74 = 8;
  piVar3 = FUN_004015e4(&local_8);
  local_68 = local_68 + 1;
  FUN_0042bbb0(local_88[0xd5],piVar3);
  FUN_00458f7c(local_88 + 0xe0,&local_8);
  local_68 = local_68 + -1;
  FUN_00458f4c(&local_8,2);
  uVar4 = FUN_00446748((undefined *)local_88[0xe0]);
  if ((char)uVar4 == '\x01') {
    uType = 1;
    lpCaption = &DAT_0045a3f7;
    lpText = &DAT_0045a3e0;
    hWnd = (HWND)FUN_00437414(local_88);
    iVar5 = MessageBoxA(hWnd,lpText,lpCaption,uType);
    if (iVar5 == 2) {
      *in_FS_OFFSET = local_84;
      return 2;
    }
    bVar2 = thunk_FUN_00446758((undefined *)local_88[0xe0]);
    if (!bVar2) {
      local_74 = 0x14;
      piVar3 = FUN_00458e94(&local_c);
      local_68 = local_68 + 1;
      FUN_0042c5f8((undefined *)*piVar3);
      local_68 = local_68 + -1;
      uVar6 = FUN_00458f4c(&local_c,2);
      *in_FS_OFFSET = local_84;
      return uVar6;
    }
  }
  local_74 = 0x20;
  piVar3 = FUN_004015e4(&local_10);
  local_68 = local_68 + 1;
  FUN_00431324(local_88[0xbe],piVar3);
  iVar5 = FUN_00459094();
  local_88[0xdc] = iVar5;
  local_68 = local_68 + -1;
  FUN_00458f4c(&local_10,2);
  local_74 = 0x2c;
  piVar3 = FUN_004015e4(&local_14);
  local_68 = local_68 + 1;
  FUN_00431324(local_88[0xbf],piVar3);
  iVar5 = FUN_00459094();
  local_88[0xdd] = iVar5;
  local_68 = local_68 + -1;
  FUN_00458f4c(&local_14,2);
  local_74 = 0x38;
  piVar3 = FUN_004015e4(&local_18);
  local_68 = local_68 + 1;
  FUN_00431324(local_88[0xc0],piVar3);
  iVar5 = FUN_00459094();
  local_88[0xde] = iVar5;
  local_68 = local_68 + -1;
  FUN_00458f4c(&local_18,2);
  local_74 = 0x44;
  piVar3 = FUN_004015e4(&local_1c);
  local_68 = local_68 + 1;
  FUN_00431324(local_88[0xc1],piVar3);
  iVar5 = FUN_00459094();
  local_88[0xdf] = iVar5;
  local_68 = local_68 + -1;
  FUN_00458f4c(&local_1c,2);
  local_74 = 0x50;
  piVar3 = FUN_004015e4(&local_20);
  local_68 = local_68 + 1;
  FUN_00431324(local_88[200],piVar3);
  iVar5 = FUN_00459094();
  local_88[0xd9] = iVar5;
  local_68 = local_68 + -1;
  FUN_00458f4c(&local_20,2);
  local_74 = 0x5c;
  piVar3 = FUN_004015e4(&local_24);
  local_68 = local_68 + 1;
  FUN_00431324(local_88[0xc9],piVar3);
  iVar5 = FUN_00459094();
  local_88[0xda] = iVar5;
  local_68 = local_68 + -1;
  FUN_00458f4c(&local_24,2);
  local_19c = local_88[0xdc];
  local_198 = local_88[0xdd];
  local_194 = local_88[0xde];
  local_190 = local_88[0xdf];
  local_18c[0] = 0;
  local_18c[1] = 0;
  local_18c[2] = local_194 - local_19c;
  local_180 = local_190 - local_198;
  local_74 = 0x68;
  piVar3 = FUN_00458e94(&local_28);
  local_68 = local_68 + 1;
  FUN_00418598(*(int **)(local_88[0xb6] + 0x128),(undefined *)*piVar3);
  local_68 = local_68 + -1;
  FUN_00458f4c(&local_28,2);
  local_b0 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
  iVar5 = FUN_0040240c(&local_19c);
  (**(code **)(*local_b0 + 0x40))(local_b0,iVar5);
  local_b4 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
  iVar5 = FUN_0040241c((int)&local_19c);
  (**(code **)(*local_b4 + 0x34))(local_b4,iVar5);
  iVar5 = FUN_0040240c(&local_19c);
  FUN_00430b88((int *)local_88[0xd4],iVar5);
  iVar5 = FUN_0040241c((int)&local_19c);
  FUN_00430ba8((int *)local_88[0xd4],iVar5);
  piVar3 = &local_19c;
  piVar7 = (int *)FUN_0042a1fc(local_88[0xb6],piVar3,local_88);
  piVar8 = (int *)FUN_0042a1fc(local_88[0xd4],local_88,extraout_ECX);
  FUN_004160d0(piVar8,local_18c,piVar7,piVar3);
  cVar1 = (**(code **)(*(int *)local_88[0xc2] + 0xb4))();
  if (cVar1 == '\x01') {
    piVar3 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
    FUN_0041b874(piVar3,3);
  }
  else {
    cVar1 = (**(code **)(*(int *)local_88[0xc4] + 0xb4))();
    if (cVar1 == '\x01') {
      piVar3 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
      FUN_0041b874(piVar3,5);
    }
  }
  iVar5 = FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
  uVar4 = FUN_0041aafc(iVar5);
  if ((char)uVar4 == '\x03') {
    uVar6 = 8;
    local_b8 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
    pHVar9 = (HBITMAP)(**(code **)(*local_b8 + 0x60))();
    local_a4 = FUN_00402430(local_88,pHVar9,uVar6);
  }
  else {
    uVar6 = 0x10;
    local_bc = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
    pHVar9 = (HBITMAP)(**(code **)(*local_bc + 0x60))();
    local_a4 = FUN_00402430(local_88,pHVar9,uVar6);
  }
  local_a8 = GlobalLock(local_a4);
  AVIFileInit();
  FUN_00402580(local_88 + 0xe0);
  iVar5 = AVIFileOpenA();
  if (iVar5 != 0) {
    local_74 = 0x74;
    piVar3 = FUN_00458e94(&local_2c);
    local_68 = local_68 + 1;
    FUN_0042c5f8((undefined *)*piVar3);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_2c,2);
  }
  local_150 = 0x73646976;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_140 = 0;
  local_13e = 0;
  local_13c = 1;
  local_138 = *(undefined4 *)(local_88[0xc5] + 500);
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  local_128 = *(undefined4 *)((int)local_a8 + 0x14);
  local_124 = 0xffffffff;
  local_120 = 0;
  local_114 = *(undefined4 *)(local_88[0xd4] + 0x38);
  local_110 = *(undefined4 *)(local_88[0xd4] + 0x3c);
  local_10c = 0;
  local_108 = 0;
  cVar1 = (**(code **)(*(int *)local_88[0xd7] + 0xb4))();
  if (cVar1 == '\0') {
    AVIFileCreateStreamA();
  }
  else {
    AVIFileCreateStreamA();
    FUN_0044ece0(local_17c,0,0x2c);
    FUN_00437414(local_88);
    iVar5 = AVISaveOptions();
    if (iVar5 == 0) {
      AVISaveOptionsFree();
      AVIStreamRelease();
      AVIFileRelease();
      AVIFileExit();
      bVar2 = thunk_FUN_00446758((undefined *)local_88[0xe0]);
      *in_FS_OFFSET = local_84;
      return CONCAT31(extraout_var,bVar2);
    }
    iVar5 = AVIMakeCompressedStream();
    if (iVar5 != 0) {
      local_74 = 0x80;
      piVar3 = FUN_00458e94(&local_30);
      local_68 = local_68 + 1;
      FUN_0042c5f8((undefined *)*piVar3);
      local_68 = local_68 + -1;
      FUN_00458f4c(&local_30,2);
      AVISaveOptionsFree();
      AVIStreamRelease();
      AVIFileRelease();
      AVIFileExit();
      bVar2 = thunk_FUN_00446758((undefined *)local_88[0xe0]);
      *in_FS_OFFSET = local_84;
      return CONCAT31(extraout_var_00,bVar2);
    }
    AVISaveOptionsFree();
    AVIStreamRelease();
  }
  AVIStreamSetFormat();
  GlobalUnlock(local_a8);
  GlobalFree(local_a4);
  local_90 = local_88[0xd9];
  while( true ) {
    if ((local_88[0xd8] <= local_90) || (local_88[0xda] < local_90)) {
      AVIStreamRelease();
      AVIFileRelease();
      AVIFileExit();
      GlobalUnlock(local_a8);
      GlobalFree(local_a4);
      local_74 = 200;
      piVar3 = FUN_00458e94(&local_60);
      local_68 = local_68 + 1;
      FUN_00431354((int)local_88,(uint *)*piVar3);
      local_68 = local_68 + -1;
      FUN_00458f4c(&local_60,2);
      cVar1 = (**(code **)(*(int *)local_88[0xc2] + 0xb4))();
      if (cVar1 == '\x01') {
        uVar6 = (**(code **)(*(int *)local_88[0xcd] + 0x5c))((int *)local_88[0xcd],1);
      }
      else {
        uVar6 = (**(code **)(*(int *)local_88[0xcd] + 0x5c))((int *)local_88[0xcd],0);
      }
      *in_FS_OFFSET = local_84;
      return uVar6;
    }
    local_74 = 0x8c;
    piVar3 = FUN_004015e4(&local_38);
    local_68 = local_68 + 1;
    piVar7 = FUN_00458f08(&local_34);
    local_68 = local_68 + 1;
    FUN_004590e4(s_picture__0045a446,piVar7,piVar3);
    piVar3 = &local_38;
    piVar7 = FUN_004015e4(&local_40);
    local_68 = local_68 + 1;
    FUN_00458e94(&local_3c);
    local_68 = local_68 + 1;
    FUN_00458f90(piVar3,&local_3c,piVar7);
    FUN_00418598(*(int **)(local_88[0xb6] + 0x128),local_40);
    local_68 = local_68 + -1;
    FUN_00458f4c((int *)&local_40,2);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_3c,2);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_38,2);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_34,2);
    piVar3 = &local_19c;
    piVar7 = (int *)FUN_0042a1fc(local_88[0xb6],extraout_EDX,piVar3);
    piVar8 = (int *)FUN_0042a1fc(local_88[0xd4],local_88,extraout_ECX_00);
    FUN_004160d0(piVar8,local_18c,piVar7,piVar3);
    cVar1 = (**(code **)(*(int *)local_88[0xc2] + 0xb4))();
    if (cVar1 == '\x01') {
      piVar3 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
      FUN_0041b874(piVar3,3);
    }
    else {
      cVar1 = (**(code **)(*(int *)local_88[0xc4] + 0xb4))();
      if (cVar1 == '\x01') {
        piVar3 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
        FUN_0041b874(piVar3,5);
      }
    }
    iVar5 = FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
    uVar4 = FUN_0041aafc(iVar5);
    if ((char)uVar4 == '\x03') {
      uVar6 = 8;
      local_c0 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
      pHVar9 = (HBITMAP)(**(code **)(*local_c0 + 0x60))();
      local_a4 = FUN_00402430(local_88,pHVar9,uVar6);
    }
    else {
      uVar6 = 0x10;
      local_c4 = (int *)FUN_004184b8(*(int **)(local_88[0xd4] + 0x128));
      pHVar9 = (HBITMAP)(**(code **)(*local_c4 + 0x60))();
      local_a4 = FUN_00402430(local_88,pHVar9,uVar6);
    }
    local_a8 = GlobalLock(local_a4);
    iVar5 = AVIStreamWrite();
    if (iVar5 != 0) break;
    local_74 = 0xbc;
    piVar3 = FUN_004015e4(&local_54);
    local_68 = local_68 + 1;
    piVar7 = FUN_00458f08(&local_50);
    local_68 = local_68 + 1;
    FUN_004590e4(&DAT_0045a48f,piVar7,piVar3);
    piVar3 = &local_54;
    piVar7 = FUN_004015e4(&local_5c);
    local_68 = local_68 + 1;
    FUN_00458e94(&local_58);
    local_68 = local_68 + 1;
    FUN_00458f90(piVar3,&local_58,piVar7);
    FUN_00431354((int)local_88,local_5c);
    local_68 = local_68 + -1;
    FUN_00458f4c((int *)&local_5c,2);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_58,2);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_54,2);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_50,2);
    local_90 = local_90 + 1;
  }
  GlobalUnlock(local_a8);
  GlobalFree(local_a4);
  cVar1 = (**(code **)(*(int *)local_88[0xd7] + 0xb4))();
  if (cVar1 == '\x01') {
    local_74 = 0x98;
    piVar3 = FUN_00458e94(&local_44);
    local_68 = local_68 + 1;
    FUN_0042c5f8((undefined *)*piVar3);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_44,2);
  }
  else {
    local_74 = 0xa4;
    piVar3 = FUN_00458e94(&local_48);
    local_68 = local_68 + 1;
    FUN_0042c5f8((undefined *)*piVar3);
    local_68 = local_68 + -1;
    FUN_00458f4c(&local_48,2);
  }
  AVIStreamRelease();
  AVIFileRelease();
  AVIFileExit();
  thunk_FUN_00446758((undefined *)local_88[0xe0]);
  local_74 = 0xb0;
  piVar3 = FUN_00458e94(&local_4c);
  local_68 = local_68 + 1;
  FUN_00431354((int)local_88,(uint *)*piVar3);
  local_68 = local_68 + -1;
  uVar6 = FUN_00458f4c(&local_4c,2);
  *in_FS_OFFSET = local_84;
  return uVar6;
}



// Preserved published name: FormShow
// Entry 004025a0, recovered name Published_FormShow_004025a0

void Published_FormShow_004025a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_50;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined *local_8;
  
  FUN_0044effc(0x45a9a0);
  piVar1 = FUN_004015e4(&local_8);
  FUN_004289a8(*(undefined4 *)PTR_DAT_0045f71c,piVar1);
  piVar1 = FUN_004015e4(&local_c);
  FUN_004467f0(local_8,piVar1);
  FUN_00458f7c((int *)(param_1 + 900),&local_c);
  FUN_00458f4c(&local_c,2);
  FUN_00458f4c((int *)&local_8,2);
  FUN_00446918(*(undefined **)(param_1 + 900));
  *(undefined4 *)(param_1 + 0x360) = 0;
  while( true ) {
    piVar1 = FUN_004015e4(&local_14);
    piVar2 = FUN_00458f08(&local_10);
    FUN_004590e4(s_picture__0045a4ab,piVar2,piVar1);
    piVar1 = FUN_004015e4(&local_1c);
    FUN_00458e94(&local_18);
    FUN_00458f90(&local_14,&local_18,piVar1);
    uVar3 = FUN_00446748(local_1c);
    FUN_00458f4c((int *)&local_1c,2);
    FUN_00458f4c(&local_18,2);
    FUN_00458f4c(&local_14,2);
    FUN_00458f4c(&local_10,2);
    if ((char)uVar3 == '\0') break;
    *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x360) + 1;
  }
  *(undefined4 *)(param_1 + 0x364) = 0;
  *(int *)(param_1 + 0x368) = *(int *)(param_1 + 0x360) + -1;
  piVar1 = FUN_00458f08(&local_20);
  FUN_00431354(*(int *)(param_1 + 0x324),(uint *)*piVar1);
  FUN_00458f4c(&local_20,2);
  *(undefined4 *)(param_1 + 0x36c) = 0;
  piVar1 = FUN_00458e94(&local_24);
  FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),(undefined *)*piVar1);
  FUN_00458f4c(&local_24,2);
  *(undefined4 *)(param_1 + 0x370) = 0;
  *(undefined4 *)(param_1 + 0x374) = 0;
  *(int *)(param_1 + 0x378) = *(int *)(*(int *)(param_1 + 0x2d8) + 0x38) + -1;
  *(int *)(param_1 + 0x37c) = *(int *)(*(int *)(param_1 + 0x2d8) + 0x3c) + -1;
  piVar1 = FUN_00458f08(&local_28);
  FUN_00431354(*(int *)(param_1 + 0x300),(uint *)*piVar1);
  FUN_00458f4c(&local_28,2);
  piVar1 = FUN_00458f08(&local_2c);
  FUN_00431354(*(int *)(param_1 + 0x304),(uint *)*piVar1);
  FUN_00458f4c(&local_2c,2);
  *in_FS_OFFSET = local_50;
  return;
}



// Preserved published name: Button3Click
// Entry 00402860, recovered name Published_Button3Click_00402860

void Published_Button3Click_00402860(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  uint *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45aa58);
  if (0 < *(int *)(param_1 + 0x36c)) {
    *(int *)(param_1 + 0x36c) = *(int *)(param_1 + 0x36c) + -1;
    piVar1 = FUN_004015e4(&local_c);
    piVar2 = FUN_00458f08(&local_8);
    FUN_004590e4(s_picture__0045a4c7,piVar2,piVar1);
    piVar1 = FUN_004015e4(&local_14);
    FUN_00458e94(&local_10);
    FUN_00458f90(&local_c,&local_10,piVar1);
    FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_14);
    FUN_00458f4c((int *)&local_14,2);
    FUN_00458f4c(&local_10,2);
    FUN_00458f4c(&local_c,2);
    FUN_00458f4c(&local_8,2);
    piVar1 = FUN_004015e4(&local_1c);
    piVar2 = FUN_00458f08(&local_18);
    FUN_004590e4(&DAT_0045a4d5,piVar2,piVar1);
    piVar1 = FUN_004015e4(&local_24);
    FUN_00458e94(&local_20);
    FUN_00458f90(&local_1c,&local_20,piVar1);
    FUN_00431354(*(int *)(param_1 + 0x340),local_24);
    FUN_00458f4c((int *)&local_24,2);
    FUN_00458f4c(&local_20,2);
    FUN_00458f4c(&local_1c,2);
    FUN_00458f4c(&local_18,2);
  }
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: Button4Click
// Entry 00402a04, recovered name Published_Button4Click_00402a04

void Published_Button4Click_00402a04(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  uint *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45aae0);
  if (*(int *)(param_1 + 0x36c) < *(int *)(param_1 + 0x360) + -1) {
    *(int *)(param_1 + 0x36c) = *(int *)(param_1 + 0x36c) + 1;
    piVar1 = FUN_004015e4(&local_c);
    piVar2 = FUN_00458f08(&local_8);
    FUN_004590e4(s_picture__0045a4db,piVar2,piVar1);
    piVar1 = FUN_004015e4(&local_14);
    FUN_00458e94(&local_10);
    FUN_00458f90(&local_c,&local_10,piVar1);
    FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_14);
    FUN_00458f4c((int *)&local_14,2);
    FUN_00458f4c(&local_10,2);
    FUN_00458f4c(&local_c,2);
    FUN_00458f4c(&local_8,2);
    piVar1 = FUN_004015e4(&local_1c);
    piVar2 = FUN_00458f08(&local_18);
    FUN_004590e4(&DAT_0045a4e9,piVar2,piVar1);
    piVar1 = FUN_004015e4(&local_24);
    FUN_00458e94(&local_20);
    FUN_00458f90(&local_1c,&local_20,piVar1);
    FUN_00431354(*(int *)(param_1 + 0x340),local_24);
    FUN_00458f4c((int *)&local_24,2);
    FUN_00458f4c(&local_20,2);
    FUN_00458f4c(&local_1c,2);
    FUN_00458f4c(&local_18,2);
  }
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: Button5Click
// Entry 00402bb0, recovered name Published_Button5Click_00402bb0

void Published_Button5Click_00402bb0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  uint *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45ab68);
  *(undefined4 *)(param_1 + 0x36c) = 0;
  piVar1 = FUN_004015e4(&local_c);
  piVar2 = FUN_00458f08(&local_8);
  FUN_004590e4(s_picture__0045a4ef,piVar2,piVar1);
  piVar1 = FUN_004015e4(&local_14);
  FUN_00458e94(&local_10);
  FUN_00458f90(&local_c,&local_10,piVar1);
  FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_14);
  FUN_00458f4c((int *)&local_14,2);
  FUN_00458f4c(&local_10,2);
  FUN_00458f4c(&local_c,2);
  FUN_00458f4c(&local_8,2);
  piVar1 = FUN_004015e4(&local_1c);
  piVar2 = FUN_00458f08(&local_18);
  FUN_004590e4(&DAT_0045a4fd,piVar2,piVar1);
  piVar1 = FUN_004015e4(&local_24);
  FUN_00458e94(&local_20);
  FUN_00458f90(&local_1c,&local_20,piVar1);
  FUN_00431354(*(int *)(param_1 + 0x340),local_24);
  FUN_00458f4c((int *)&local_24,2);
  FUN_00458f4c(&local_20,2);
  FUN_00458f4c(&local_1c,2);
  FUN_00458f4c(&local_18,2);
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: Button6Click
// Entry 00402d48, recovered name Published_Button6Click_00402d48

void Published_Button6Click_00402d48(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  uint *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45abf0);
  *(int *)(param_1 + 0x36c) = *(int *)(param_1 + 0x360) + -1;
  piVar1 = FUN_004015e4(&local_c);
  piVar2 = FUN_00458f08(&local_8);
  FUN_004590e4(s_picture__0045a503,piVar2,piVar1);
  piVar1 = FUN_004015e4(&local_14);
  FUN_00458e94(&local_10);
  FUN_00458f90(&local_c,&local_10,piVar1);
  FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_14);
  FUN_00458f4c((int *)&local_14,2);
  FUN_00458f4c(&local_10,2);
  FUN_00458f4c(&local_c,2);
  FUN_00458f4c(&local_8,2);
  piVar1 = FUN_004015e4(&local_1c);
  piVar2 = FUN_00458f08(&local_18);
  FUN_004590e4(&DAT_0045a511,piVar2,piVar1);
  piVar1 = FUN_004015e4(&local_24);
  FUN_00458e94(&local_20);
  FUN_00458f90(&local_1c,&local_20,piVar1);
  FUN_00431354(*(int *)(param_1 + 0x340),local_24);
  FUN_00458f4c((int *)&local_24,2);
  FUN_00458f4c(&local_20,2);
  FUN_00458f4c(&local_1c,2);
  FUN_00458f4c(&local_18,2);
  *in_FS_OFFSET = local_48;
  return;
}



// Preserved published name: Edit1Exit
// Entry 00402ee8, recovered name Published_Edit1Exit_00402ee8

undefined4 Published_Edit1Exit_00402ee8(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  int iVar5;
  undefined4 local_44;
  undefined *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45ac94);
  piVar1 = FUN_004015e4(&local_8);
  FUN_00431324(*(int *)(param_1 + 0x2f8),piVar1);
  iVar2 = FUN_00459094();
  FUN_00458f4c(&local_8,2);
  if ((iVar2 < 0) || (*(int *)(*(int *)(param_1 + 0x2d8) + 0x38) + -2 < iVar2)) {
    piVar1 = FUN_00458e94(&local_c);
    FUN_0042c5f8((undefined *)*piVar1);
    FUN_00458f4c(&local_c,2);
    (**(code **)(**(int **)(param_1 + 0x2f8) + 0xb0))();
    *in_FS_OFFSET = local_44;
    uVar4 = local_44;
  }
  else {
    *(int *)(param_1 + 0x370) = iVar2;
    piVar1 = FUN_004015e4(&local_14);
    piVar3 = FUN_00458f08(&local_10);
    FUN_004590e4(s_picture__0045a530,piVar3,piVar1);
    piVar1 = &local_14;
    piVar3 = FUN_004015e4(&local_1c);
    FUN_00458e94(&local_18);
    FUN_00458f90(piVar1,&local_18,piVar3);
    FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_1c);
    FUN_00458f4c((int *)&local_1c,2);
    FUN_00458f4c(&local_18,2);
    FUN_00458f4c(&local_14,2);
    FUN_00458f4c(&local_10,2);
    iVar2 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX,param_1);
    FUN_00415f7c(*(int **)(iVar2 + 0x14),'\x01');
    iVar2 = *(int *)(param_1 + 0x378);
    iVar5 = *(int *)(param_1 + 0x37c);
    piVar1 = (int *)FUN_0042a1fc(*(int *)(param_1 + 0x2d8),param_1,param_1);
    uVar4 = FUN_00416304(piVar1,*(int *)(param_1 + 0x370),*(int *)(param_1 + 0x374),iVar5,iVar2);
    *in_FS_OFFSET = local_44;
  }
  return uVar4;
}



// Preserved published name: Edit3Exit
// Entry 00403120, recovered name Published_Edit3Exit_00403120

undefined4 Published_Edit3Exit_00403120(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  undefined *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45ad6c);
  piVar1 = FUN_004015e4(&local_8);
  FUN_00431324(*(int *)(param_1 + 0x300),piVar1);
  iVar2 = FUN_00459094();
  FUN_00458f4c(&local_8,2);
  if (iVar2 <= *(int *)(*(int *)(param_1 + 0x2d8) + 0x38) + -1) {
    piVar1 = FUN_004015e4(&local_c);
    FUN_00431324(*(int *)(param_1 + 0x2f8),piVar1);
    iVar3 = FUN_00459094();
    uVar6 = (uint)(iVar2 <= iVar3);
    FUN_00458f4c(&local_c,2);
    if (uVar6 == 0) {
      *(int *)(param_1 + 0x378) = iVar2;
      piVar1 = FUN_004015e4(&local_18);
      piVar4 = FUN_00458f08(&local_14);
      FUN_004590e4(s_picture__0045a570,piVar4,piVar1);
      piVar1 = &local_18;
      piVar4 = FUN_004015e4(&local_20);
      FUN_00458e94(&local_1c);
      FUN_00458f90(piVar1,&local_1c,piVar4);
      FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_20);
      FUN_00458f4c((int *)&local_20,2);
      FUN_00458f4c(&local_1c,2);
      FUN_00458f4c(&local_18,2);
      FUN_00458f4c(&local_14,2);
      iVar2 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX,param_1);
      FUN_00415f7c(*(int **)(iVar2 + 0x14),'\x01');
      iVar2 = *(int *)(param_1 + 0x378);
      iVar3 = *(int *)(param_1 + 0x37c);
      piVar1 = (int *)FUN_0042a1fc(*(int *)(param_1 + 0x2d8),param_1,param_1);
      uVar5 = FUN_00416304(piVar1,*(int *)(param_1 + 0x370),*(int *)(param_1 + 0x374),iVar3,iVar2);
      *in_FS_OFFSET = local_48;
      return uVar5;
    }
  }
  piVar1 = FUN_00458e94(&local_10);
  FUN_0042c5f8((undefined *)*piVar1);
  FUN_00458f4c(&local_10,2);
  (**(code **)(**(int **)(param_1 + 0x300) + 0xb0))();
  *in_FS_OFFSET = local_48;
  return local_48;
}



// Preserved published name: Edit2Exit
// Entry 00403398, recovered name Published_Edit2Exit_00403398

undefined4 Published_Edit2Exit_00403398(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  int iVar5;
  undefined4 local_44;
  undefined *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45ae40);
  piVar1 = FUN_004015e4(&local_8);
  FUN_00431324(*(int *)(param_1 + 0x2fc),piVar1);
  iVar2 = FUN_00459094();
  FUN_00458f4c(&local_8,2);
  if ((iVar2 < 0) || (*(int *)(*(int *)(param_1 + 0x2d8) + 0x3c) + -2 < iVar2)) {
    piVar1 = FUN_00458e94(&local_c);
    FUN_0042c5f8((undefined *)*piVar1);
    FUN_00458f4c(&local_c,2);
    (**(code **)(**(int **)(param_1 + 0x2fc) + 0xb0))();
    *in_FS_OFFSET = local_44;
    uVar4 = local_44;
  }
  else {
    *(int *)(param_1 + 0x374) = iVar2;
    piVar1 = FUN_004015e4(&local_14);
    piVar3 = FUN_00458f08(&local_10);
    FUN_004590e4(s_picture__0045a5b0,piVar3,piVar1);
    piVar1 = &local_14;
    piVar3 = FUN_004015e4(&local_1c);
    FUN_00458e94(&local_18);
    FUN_00458f90(piVar1,&local_18,piVar3);
    FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_1c);
    FUN_00458f4c((int *)&local_1c,2);
    FUN_00458f4c(&local_18,2);
    FUN_00458f4c(&local_14,2);
    FUN_00458f4c(&local_10,2);
    iVar2 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX,param_1);
    FUN_00415f7c(*(int **)(iVar2 + 0x14),'\x01');
    iVar2 = *(int *)(param_1 + 0x378);
    iVar5 = *(int *)(param_1 + 0x37c);
    piVar1 = (int *)FUN_0042a1fc(*(int *)(param_1 + 0x2d8),param_1,param_1);
    uVar4 = FUN_00416304(piVar1,*(int *)(param_1 + 0x370),*(int *)(param_1 + 0x374),iVar5,iVar2);
    *in_FS_OFFSET = local_44;
  }
  return uVar4;
}



// Preserved published name: Edit4Exit
// Entry 004035d0, recovered name Published_Edit4Exit_004035d0

undefined4 Published_Edit4Exit_004035d0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 local_48;
  undefined *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45af18);
  piVar1 = FUN_004015e4(&local_8);
  FUN_00431324(*(int *)(param_1 + 0x304),piVar1);
  iVar2 = FUN_00459094();
  FUN_00458f4c(&local_8,2);
  if (iVar2 <= *(int *)(*(int *)(param_1 + 0x2d8) + 0x3c) + -1) {
    piVar1 = FUN_004015e4(&local_c);
    FUN_00431324(*(int *)(param_1 + 0x2fc),piVar1);
    iVar3 = FUN_00459094();
    uVar6 = (uint)(iVar2 <= iVar3);
    FUN_00458f4c(&local_c,2);
    if (uVar6 == 0) {
      *(int *)(param_1 + 0x37c) = iVar2;
      piVar1 = FUN_004015e4(&local_18);
      piVar4 = FUN_00458f08(&local_14);
      FUN_004590e4(s_picture__0045a5f0,piVar4,piVar1);
      piVar1 = &local_18;
      piVar4 = FUN_004015e4(&local_20);
      FUN_00458e94(&local_1c);
      FUN_00458f90(piVar1,&local_1c,piVar4);
      FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_20);
      FUN_00458f4c((int *)&local_20,2);
      FUN_00458f4c(&local_1c,2);
      FUN_00458f4c(&local_18,2);
      FUN_00458f4c(&local_14,2);
      iVar2 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX,param_1);
      FUN_00415f7c(*(int **)(iVar2 + 0x14),'\x01');
      iVar2 = *(int *)(param_1 + 0x378);
      iVar3 = *(int *)(param_1 + 0x37c);
      piVar1 = (int *)FUN_0042a1fc(*(int *)(param_1 + 0x2d8),param_1,param_1);
      uVar5 = FUN_00416304(piVar1,*(int *)(param_1 + 0x370),*(int *)(param_1 + 0x374),iVar3,iVar2);
      *in_FS_OFFSET = local_48;
      return uVar5;
    }
  }
  piVar1 = FUN_00458e94(&local_10);
  FUN_0042c5f8((undefined *)*piVar1);
  FUN_00458f4c(&local_10,2);
  (**(code **)(**(int **)(param_1 + 0x304) + 0xb0))();
  *in_FS_OFFSET = local_48;
  return local_48;
}



// Preserved published name: Edit5Exit
// Entry 00403848, recovered name Published_Edit5Exit_00403848

void Published_Edit5Exit_00403848(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_34;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45afb8);
  piVar1 = FUN_004015e4(&local_8);
  FUN_00431324(*(int *)(param_1 + 800),piVar1);
  iVar2 = FUN_00459094();
  FUN_00458f4c(&local_8,2);
  if ((iVar2 < 0) || (*(int *)(param_1 + 0x360) + -2 < iVar2)) {
    piVar1 = FUN_00458e94(&local_c);
    FUN_0042c5f8((undefined *)*piVar1);
    FUN_00458f4c(&local_c,2);
    (**(code **)(**(int **)(param_1 + 800) + 0xb0))();
  }
  *in_FS_OFFSET = local_34;
  return;
}



// Preserved published name: Edit6Exit
// Entry 0040395c, recovered name Published_Edit6Exit_0040395c

void Published_Edit6Exit_0040395c(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_38;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45b050);
  piVar1 = FUN_004015e4(&local_8);
  FUN_00431324(*(int *)(param_1 + 0x324),piVar1);
  iVar2 = FUN_00459094();
  FUN_00458f4c(&local_8,2);
  if (iVar2 <= *(int *)(param_1 + 0x360) + -1) {
    piVar1 = FUN_004015e4(&local_c);
    FUN_00431324(*(int *)(param_1 + 800),piVar1);
    iVar3 = FUN_00459094();
    FUN_00458f4c(&local_c,2);
    if (iVar3 < iVar2) goto LAB_00403a4c;
  }
  piVar1 = FUN_00458e94(&local_10);
  FUN_0042c5f8((undefined *)*piVar1);
  FUN_00458f4c(&local_10,2);
  (**(code **)(**(int **)(param_1 + 0x324) + 0xb0))();
LAB_00403a4c:
  *in_FS_OFFSET = local_38;
  return;
}



// Preserved published name: ScrollBar1Change
// Entry 00403ab0, recovered name Published_ScrollBar1Change_00403ab0

void Published_ScrollBar1Change_00403ab0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_3c;
  uint *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45b0d8);
  piVar1 = FUN_00458f08(&local_8);
  FUN_00458f7c((int *)(*(int *)(param_1 + 0x314) + 0x70),piVar1);
  FUN_00458f4c(&local_8,2);
  piVar1 = FUN_004015e4(&local_10);
  piVar2 = FUN_00458f08(&local_c);
  FUN_004590e4(&DAT_0045a67b,piVar2,piVar1);
  piVar1 = FUN_004015e4(&local_18);
  FUN_00458e94(&local_14);
  FUN_00458f90(&local_10,&local_14,piVar1);
  FUN_00431354(*(int *)(param_1 + 0x318),local_18);
  FUN_00458f4c((int *)&local_18,2);
  FUN_00458f4c(&local_14,2);
  FUN_00458f4c(&local_10,2);
  FUN_00458f4c(&local_c,2);
  *in_FS_OFFSET = local_3c;
  return;
}



// Preserved published name: Button2Click
// Entry 00403bd0, recovered name Published_Button2Click_00403bd0

void Published_Button2Click_00403bd0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_0044effc(0x45b108);
  (**(code **)(**(int **)(*(int *)(param_1 + 0x358) + 0x208) + 0x40))();
  piVar1 = *(int **)(*(int *)(param_1 + 0x358) + 0x208);
  (**(code **)(*piVar1 + 0x20))(piVar1,0,*(undefined4 *)(param_1 + 0x380));
  iVar2 = *(int *)(param_1 + 0x358);
  piVar3 = FUN_00458e94(&local_8);
  piVar1 = *(int **)(iVar2 + 0x208);
  (**(code **)(*piVar1 + 100))(piVar1,*piVar3);
  FUN_00458f4c(&local_8,2);
  WinExec(s_gif_exe_0045a697,1);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: Image1MouseDown
// Entry 00403c88, recovered name Published_Image1MouseDown_00403c88

void Published_Image1MouseDown_00403c88
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 *in_FS_OFFSET;
  undefined4 local_38;
  undefined *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45b150);
  *(undefined4 *)(param_1 + 0x388) = param_5;
  *(undefined4 *)(param_1 + 0x38c) = param_4;
  *(undefined4 *)(param_1 + 0x390) = *(undefined4 *)(param_1 + 0x388);
  *(undefined4 *)(param_1 + 0x394) = *(undefined4 *)(param_1 + 0x38c);
  piVar1 = FUN_004015e4(&local_c);
  piVar2 = FUN_00458f08(&local_8);
  FUN_004590e4(s_picture__0045a69f,piVar2,piVar1);
  piVar1 = FUN_004015e4(&local_14);
  FUN_00458e94(&local_10);
  FUN_00458f90(&local_c,&local_10,piVar1);
  FUN_00418598(*(int **)(*(int *)(param_1 + 0x2d8) + 0x128),local_14);
  FUN_00458f4c((int *)&local_14,2);
  FUN_00458f4c(&local_10,2);
  FUN_00458f4c(&local_c,2);
  FUN_00458f4c(&local_8,2);
  iVar3 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX,param_1);
  FUN_00415c3c(*(int **)(iVar3 + 0x10),CONCAT31((int3)((uint)extraout_EDX_00 >> 8),0xe),extraout_ECX
              );
  iVar3 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX_01,param_1);
  FUN_00415f7c(*(int **)(iVar3 + 0x14),'\x01');
  iVar3 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX_02,param_1);
  FUN_00415b7c(*(int **)(iVar3 + 0x10),0xff);
  *in_FS_OFFSET = local_38;
  return;
}



// Preserved published name: Image1MouseMove
// Entry 00403df0, recovered name Published_Image1MouseMove_00403df0

void Published_Image1MouseMove_00403df0
               (int param_1,undefined4 param_2,undefined1 param_3,int param_4,int param_5)

{
  bool bVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar3;
  int iVar4;
  undefined1 local_d;
  undefined4 local_c;
  int local_8;
  
  local_d = param_3;
  local_c = param_2;
  local_8 = param_1;
  bVar1 = FUN_00403eb0((int)&local_d,'\x03');
  if ((bVar1) && ((param_5 != *(int *)(local_8 + 0x390) || (param_4 != *(int *)(local_8 + 0x394)))))
  {
    iVar4 = *(int *)(local_8 + 0x390);
    iVar3 = *(int *)(local_8 + 0x394);
    piVar2 = (int *)FUN_0042a1fc(*(int *)(local_8 + 0x2d8),local_8,local_8);
    FUN_00416304(piVar2,*(int *)(local_8 + 0x388),*(int *)(local_8 + 0x38c),iVar3,iVar4);
    iVar4 = param_4;
    iVar3 = param_5;
    piVar2 = (int *)FUN_0042a1fc(*(int *)(local_8 + 0x2d8),extraout_EDX,extraout_ECX);
    FUN_00416304(piVar2,*(int *)(local_8 + 0x388),*(int *)(local_8 + 0x38c),iVar4,iVar3);
    *(int *)(local_8 + 0x390) = param_5;
    *(int *)(local_8 + 0x394) = param_4;
  }
  return;
}



// Preserved published name: Image1MouseUp
// Entry 00403f04, recovered name Published_Image1MouseUp_00403f04

void Published_Image1MouseUp_00403f04
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 *in_FS_OFFSET;
  int iVar3;
  undefined4 local_38;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0044effc(0x45b1a4);
  iVar2 = *(int *)(param_1 + 0x390);
  iVar3 = *(int *)(param_1 + 0x394);
  piVar1 = (int *)FUN_0042a1fc(*(int *)(param_1 + 0x2d8),param_1,param_1);
  FUN_00416304(piVar1,*(int *)(param_1 + 0x388),*(int *)(param_1 + 0x38c),iVar3,iVar2);
  iVar2 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX,extraout_ECX);
  FUN_00415c3c(*(int **)(iVar2 + 0x10),CONCAT31((int3)((uint)extraout_EDX_00 >> 8),4),
               extraout_ECX_00);
  iVar2 = FUN_0042a1fc(*(int *)(param_1 + 0x2d8),extraout_EDX_01,param_1);
  FUN_00415b7c(*(int **)(iVar2 + 0x10),0);
  if ((*(int *)(param_1 + 0x388) == param_5) || (*(int *)(param_1 + 0x38c) == param_4)) {
    *in_FS_OFFSET = local_38;
  }
  else {
    iVar2 = param_4;
    iVar3 = param_5;
    piVar1 = (int *)FUN_0042a1fc(*(int *)(param_1 + 0x2d8),param_1,*(int *)(param_1 + 0x38c));
    FUN_00416304(piVar1,*(int *)(param_1 + 0x388),*(int *)(param_1 + 0x38c),iVar2,iVar3);
    if (*(int *)(param_1 + 0x388) < param_5) {
      *(undefined4 *)(param_1 + 0x370) = *(undefined4 *)(param_1 + 0x388);
      *(int *)(param_1 + 0x378) = param_5;
    }
    else {
      *(int *)(param_1 + 0x370) = param_5;
      *(undefined4 *)(param_1 + 0x378) = *(undefined4 *)(param_1 + 0x388);
    }
    if (*(int *)(param_1 + 0x38c) < param_4) {
      *(undefined4 *)(param_1 + 0x374) = *(undefined4 *)(param_1 + 0x38c);
      *(int *)(param_1 + 0x37c) = param_4;
    }
    else {
      *(int *)(param_1 + 0x374) = param_4;
      *(undefined4 *)(param_1 + 0x37c) = *(undefined4 *)(param_1 + 0x38c);
    }
    piVar1 = FUN_00458f08(&local_8);
    FUN_00431354(*(int *)(param_1 + 0x2f8),(uint *)*piVar1);
    FUN_00458f4c(&local_8,2);
    piVar1 = FUN_00458f08(&local_c);
    FUN_00431354(*(int *)(param_1 + 0x2fc),(uint *)*piVar1);
    FUN_00458f4c(&local_c,2);
    piVar1 = FUN_00458f08(&local_10);
    FUN_00431354(*(int *)(param_1 + 0x300),(uint *)*piVar1);
    FUN_00458f4c(&local_10,2);
    piVar1 = FUN_00458f08(&local_14);
    FUN_00431354(*(int *)(param_1 + 0x304),(uint *)*piVar1);
    FUN_00458f4c(&local_14,2);
    *in_FS_OFFSET = local_38;
  }
  return;
}



// Preserved published name: FormClose
// Entry 0040416c, recovered name Published_FormClose_0040416c

void Published_FormClose_0040416c(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_44;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined *local_8;
  
  FUN_0044effc(0x45b248);
  FUN_004015e4(&local_8);
  while( true ) {
    piVar1 = FUN_004015e4(&local_10);
    FUN_00458e94(&local_c);
    FUN_00458f90((undefined4 *)(param_1 + 900),&local_c,piVar1);
    piVar1 = FUN_004015e4(&local_18);
    piVar2 = FUN_00458f08(&local_14);
    FUN_00458f90(&local_10,piVar2,piVar1);
    piVar1 = FUN_004015e4(&local_20);
    FUN_00458e94(&local_1c);
    FUN_00458f90(&local_18,&local_1c,piVar1);
    FUN_00458f7c((int *)&local_8,&local_20);
    FUN_00458f4c(&local_20,2);
    FUN_00458f4c(&local_1c,2);
    FUN_00458f4c(&local_18,2);
    FUN_00458f4c(&local_14,2);
    FUN_00458f4c(&local_10,2);
    FUN_00458f4c(&local_c,2);
    uVar3 = FUN_00446748(local_8);
    if ((char)uVar3 != '\x01') break;
    thunk_FUN_00446758(local_8);
  }
  FUN_00458f4c((int *)&local_8,2);
  *in_FS_OFFSET = local_44;
  return;
}



