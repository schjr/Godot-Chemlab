/* GHIDRA PSEUDOCODE FOR PUBLISHED METHOD ENTRIES; NOT ORIGINAL/BUILDABLE SOURCE.
Metadata-seeded entries supplement default analysis. Names preserve published names
with synthetic prefix and address suffix; original class ownership/signatures unknown.
SHA256: 4070a4e5f7f7575bae6fb7a04500a06eb3c3906ff43930782aef3fdb3c2416a0 */

// Entry 004032f0, recovered name Published_FormCreate_004032f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormCreate_004032f0(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  float fVar4;
  float fVar5;
  int iStack_bc;
  undefined4 uStack_a8;
  undefined1 auStack_84 [4];
  undefined1 auStack_80 [4];
  int *piStack_7c;
  int iStack_78;
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  int *piStack_64;
  int iStack_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  int *piStack_4c;
  int iStack_48;
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [32];
  undefined1 auStack_20 [8];
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  
  FUN_00596a18(0x5b9d54);
  *(undefined4 *)(param_1 + 0xaec) = 0x41c80000;
  *(undefined4 *)(param_1 + 0xaf0) = 0x41700000;
  *(undefined4 *)(param_1 + 0xb54) = 0;
  *(undefined4 *)(param_1 + 0xb58) = 0;
  *(undefined4 *)(param_1 + 0xb5c) = 0;
  *(undefined4 *)(param_1 + 0xb24) = 0x3f0ccccd;
  *(undefined4 *)(param_1 + 0xb28) = 0x3f3ae148;
  *(undefined4 *)(param_1 + 0xb2c) = 0x3e19999a;
  *(undefined4 *)(param_1 + 0xb30) = 0x3da3d70a;
  *(undefined4 *)(param_1 + 0xb34) = 0x3f11eb85;
  *(undefined4 *)(param_1 + 0xb38) = 0x3f51eb85;
  *(undefined4 *)(param_1 + 0xb3c) = 0x3f63d70a;
  *(undefined4 *)(param_1 + 0xb40) = 0x3eb33333;
  *(undefined4 *)(param_1 + 0xb44) = 0x3db851ec;
  *(undefined4 *)(param_1 + 0xaf4) = 0x3e800000;
  *(undefined4 *)(param_1 + 0xaf8) = 0x3e570a3d;
  *(undefined4 *)(param_1 + 0xafc) = 0x3e19999a;
  *(undefined4 *)(param_1 + 0xb00) = 0x3e8a3d71;
  *(undefined4 *)(param_1 + 0xb04) = 0x3f5eb852;
  *(undefined4 *)(param_1 + 0xb08) = 0x3f2e147b;
  *(undefined4 *)(param_1 + 0xb0c) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0xb10) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0xb14) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb18) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb1c) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0xb20) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0xb48) = 0x3f3fbe77;
  *(undefined4 *)(param_1 + 0xb4c) = 0x3ec49ba6;
  *(undefined4 *)(param_1 + 0xb50) = 0x3d50e560;
  *(undefined4 *)(param_1 + 0xb60) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0xb64) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0xb68) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0xb6c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xbb0) = 0x3f800000;
  FUN_005a2750(auStack_8,0x5b86ec);
  FUN_005a28f0(param_1 + 0xba0,auStack_8);
  FUN_005a28c0(auStack_8,2);
  FUN_005a2750(auStack_c,0x5b86ed);
  FUN_005a28f0(param_1 + 0xba4,auStack_c);
  FUN_005a28c0(auStack_c,2);
  FUN_005a2750(auStack_10,0x5b86ee);
  FUN_005a28f0(param_1 + 0xba8,auStack_10);
  FUN_005a28c0(auStack_10,2);
  fVar5 = (float)*(int *)(_Form1 + 0x38);
  fVar4 = (float)(*(int *)(_Form1 + 0x3c) - *(int *)(*(int *)(param_1 + 0x43c) + 0x3c));
  uVar2 = FUN_0056f494(param_1);
  DAT_005c98d0 = FUN_004d74c4(_DAT_005c3e88,1,uVar2,fVar4,fVar5);
  FUN_004d7fdc(DAT_005c98d0);
  FUN_004d7ffc(DAT_005c98d0,0);
  *(undefined4 *)(DAT_005c98d0 + 0x88c) = *(undefined4 *)(param_1 + 0xb54);
  *(undefined4 *)(DAT_005c98d0 + 0x890) = *(undefined4 *)(param_1 + 0xb58);
  *(undefined4 *)(DAT_005c98d0 + 0x894) = *(undefined4 *)(param_1 + 0xb5c);
  DAT_005c98d4 = func_0x004d6554(_DAT_005c3f84,1,0);
  *(undefined4 *)(DAT_005c98d4 + 0x38) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x3c) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x40) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x44) = 0;
  *(undefined4 *)(DAT_005c98d4 + 0x18) = 0x3f666666;
  *(undefined4 *)(DAT_005c98d4 + 0x1c) = 0x3f666666;
  *(undefined4 *)(DAT_005c98d4 + 0x20) = 0x3f666666;
  *(undefined4 *)(DAT_005c98d4 + 0x24) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x28) = 0x3f666666;
  *(undefined4 *)(DAT_005c98d4 + 0x2c) = 0x3f666666;
  *(undefined4 *)(DAT_005c98d4 + 0x30) = 0x3f666666;
  *(undefined4 *)(DAT_005c98d4 + 0x34) = 0x3f800000;
  FUN_004d6758(DAT_005c98d4);
  FUN_004d80c0(DAT_005c98d0,DAT_005c98d4);
  *(undefined4 *)(param_1 + 0xb70) = *(undefined4 *)(DAT_005c98d4 + 0x38);
  *(undefined4 *)(param_1 + 0xb74) = *(undefined4 *)(DAT_005c98d4 + 0x3c);
  *(undefined4 *)(param_1 + 0xb78) = *(undefined4 *)(DAT_005c98d4 + 0x40);
  *(undefined4 *)(param_1 + 0xb7c) = *(undefined4 *)(DAT_005c98d4 + 0x44);
  *(undefined4 *)(param_1 + 0xb80) = *(undefined4 *)(DAT_005c98d4 + 0x18);
  *(undefined4 *)(param_1 + 0xb84) = *(undefined4 *)(DAT_005c98d4 + 0x1c);
  *(undefined4 *)(param_1 + 0xb88) = *(undefined4 *)(DAT_005c98d4 + 0x20);
  *(undefined4 *)(param_1 + 0xb8c) = *(undefined4 *)(DAT_005c98d4 + 0x24);
  *(undefined4 *)(param_1 + 0xb90) = *(undefined4 *)(DAT_005c98d4 + 0x28);
  *(undefined4 *)(param_1 + 0xb94) = *(undefined4 *)(DAT_005c98d4 + 0x2c);
  *(undefined4 *)(param_1 + 0xb98) = *(undefined4 *)(DAT_005c98d4 + 0x30);
  *(undefined4 *)(param_1 + 0xb9c) = *(undefined4 *)(DAT_005c98d4 + 0x34);
  FUN_0053b0a4(*(undefined4 *)(param_1 + 0x458),0);
  uVar2 = FUN_0040328c(&uStack_14);
  FUN_0055a58c(*(undefined4 *)PTR_DAT_005c9494,uVar2);
  uVar2 = FUN_0040328c(auStack_18);
  FUN_0058d590(uStack_14,uVar2);
  FUN_005a28f0(param_1 + 0xba4,auStack_18);
  FUN_005a28c0(auStack_18,2);
  FUN_005a28c0(&uStack_14,2);
  *(undefined4 *)(param_1 + 0xa28) = 0;
  *(undefined4 *)(param_1 + 0xa5c) = 0;
  *(undefined4 *)(param_1 + 0xa24) = 0;
  puVar3 = (undefined4 *)FUN_005a2750(auStack_20,0x5b8716);
  FUN_00569318(param_1,*puVar3);
  FUN_005a28c0(auStack_20,2);
  iStack_bc = 0;
  do {
    if (iStack_bc == 0) {
      *(undefined2 *)(param_1 + 0x5f0) = 1;
    }
    else {
      *(undefined2 *)(param_1 + 0x5f0) = 2;
    }
    *(undefined2 *)(param_1 + 0x61c) = 0x7fef;
    *(undefined2 *)(param_1 + 0x61e) = 0x404f;
    sVar1 = FUN_00595634();
    if (((sVar1 == 0x11) && (iStack_bc != 0)) || ((sVar1 != 0 && (iStack_bc == 0)))) break;
    *(undefined2 *)(param_1 + 0x5f0) = 3;
    *(undefined2 *)(param_1 + 0x61c) = 0x7fef;
    *(undefined2 *)(param_1 + 0x61e) = 0x404f;
    sVar1 = FUN_00595634();
    if (sVar1 == 0) {
      *(undefined2 *)(param_1 + 0x5f0) = 0xc;
      *(undefined2 *)(param_1 + 0x61c) = 9;
      *(undefined2 *)(param_1 + 0x61e) = 0;
      FUN_00595634();
      *(undefined4 *)(param_1 + 0xa24) = *(undefined4 *)(param_1 + 0x614);
    }
    *(undefined2 *)(param_1 + 0x5f0) = 4;
    FUN_00595634();
    iStack_bc = iStack_bc + 1;
  } while (iStack_bc < 0x10);
  *(undefined4 *)(param_1 + 0x614) = *(undefined4 *)(param_1 + 0xa24);
  *(undefined2 *)(param_1 + 0x5f0) = 3;
  *(undefined2 *)(param_1 + 0x61c) = 0x7fef;
  *(undefined2 *)(param_1 + 0x61e) = 0x404f;
  sVar1 = FUN_00595634();
  if (sVar1 == 0) {
    *(undefined2 *)(param_1 + 0x5f0) = 5;
    *(undefined2 *)(param_1 + 0x61c) = 0x10;
    *(undefined2 *)(param_1 + 0x61e) = 7;
    sVar1 = FUN_00595634();
    if (sVar1 == 0) {
      if (((((*(char *)(param_1 + 0x624) == '2') && (*(char *)(param_1 + 0x626) == '0')) &&
           (*(char *)(param_1 + 0x627) == '3')) &&
          ((*(char *)(param_1 + 0x628) == '2' && (*(char *)(param_1 + 0x629) == '1')))) &&
         (*(char *)(param_1 + 0x62a) == '8')) {
        *(undefined2 *)(param_1 + 0x5f0) = 0xc;
        *(undefined2 *)(param_1 + 0x61c) = 9;
        *(undefined2 *)(param_1 + 0x61e) = 0;
        FUN_00595634();
        *(undefined4 *)(param_1 + 0xa28) = 1;
      }
      else if (*(int *)PTR__About_005c947c == 0) {
        uVar2 = FUN_004d33a8(PTR_PTR_005c2df4,1,param_1);
        *(undefined4 *)PTR__About_005c947c = uVar2;
        puVar3 = (undefined4 *)FUN_005a2750(auStack_40,0x5b87b0);
        FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
        FUN_005a28c0(auStack_40,2);
        puVar3 = (undefined4 *)FUN_005a2750(auStack_44,0x5b87c5);
        FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
        FUN_005a28c0(auStack_44,2);
        (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
        piStack_4c = *(int **)PTR__About_005c947c;
        if (piStack_4c != (int *)0x0) {
          iStack_48 = *piStack_4c;
          (**(code **)(*piStack_4c + -4))(piStack_4c,3);
        }
        *(undefined4 *)PTR__About_005c947c = 0;
      }
      else {
        puVar3 = (undefined4 *)FUN_005a2750(auStack_50,0x5b87d6);
        FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
        FUN_005a28c0(auStack_50,2);
        puVar3 = (undefined4 *)FUN_005a2750(auStack_54,0x5b87eb);
        FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
        FUN_005a28c0(auStack_54,2);
        (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
      }
    }
    else if (*(int *)PTR__About_005c947c == 0) {
      uVar2 = FUN_004d33a8(PTR_PTR_005c2df4,1,param_1);
      *(undefined4 *)PTR__About_005c947c = uVar2;
      puVar3 = (undefined4 *)FUN_005a2750(auStack_58,0x5b87fc);
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
      FUN_005a28c0(auStack_58,2);
      puVar3 = (undefined4 *)FUN_005a2750(auStack_5c,0x5b8811);
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
      FUN_005a28c0(auStack_5c,2);
      (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
      piStack_64 = *(int **)PTR__About_005c947c;
      if (piStack_64 != (int *)0x0) {
        iStack_60 = *piStack_64;
        (**(code **)(*piStack_64 + -4))(piStack_64,3);
      }
      *(undefined4 *)PTR__About_005c947c = 0;
    }
    else {
      puVar3 = (undefined4 *)FUN_005a2750(auStack_68,0x5b8822);
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
      FUN_005a28c0(auStack_68,2);
      puVar3 = (undefined4 *)FUN_005a2750(auStack_6c,0x5b8837);
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
      FUN_005a28c0(auStack_6c,2);
      (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
    }
  }
  else if (*(int *)PTR__About_005c947c == 0) {
    uVar2 = FUN_004d33a8(PTR_PTR_005c2df4,1,param_1);
    *(undefined4 *)PTR__About_005c947c = uVar2;
    puVar3 = (undefined4 *)FUN_005a2750(auStack_70,0x5b8848);
    FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
    FUN_005a28c0(auStack_70,2);
    puVar3 = (undefined4 *)FUN_005a2750(auStack_74,0x5b885d);
    FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
    FUN_005a28c0(auStack_74,2);
    (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
    piStack_7c = *(int **)PTR__About_005c947c;
    if (piStack_7c != (int *)0x0) {
      iStack_78 = *piStack_7c;
      (**(code **)(*piStack_7c + -4))(piStack_7c,3);
    }
    *(undefined4 *)PTR__About_005c947c = 0;
  }
  else {
    puVar3 = (undefined4 *)FUN_005a2750(auStack_80,0x5b886e);
    FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
    FUN_005a28c0(auStack_80,2);
    puVar3 = (undefined4 *)FUN_005a2750(auStack_84,0x5b8883);
    FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
    FUN_005a28c0(auStack_84,2);
    (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
  }
  uVar2 = FUN_0054bd6c(PTR_PTR_00545a1c,1);
  *(undefined4 *)(param_1 + 0xa68) = uVar2;
  uVar2 = FUN_0054bd6c(PTR_PTR_00545a1c,1);
  *(undefined4 *)(param_1 + 0xa6c) = uVar2;
  *(undefined1 *)(param_1 + 0xa70) = 1;
  *in_FS_OFFSET = uStack_a8;
  return;
}



// Entry 00404a28, recovered name Published_FormPaint_00404a28

void Published_FormPaint_00404a28(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004d8328(DAT_005c98d0,param_2,param_3,param_2,param_1);
  return;
}



// Entry 00404a44, recovered name Published_FormKeyDown_00404a44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormKeyDown_00404a44(int param_1,undefined4 param_2,short *param_3)

{
  float fVar1;
  
  if (*param_3 == 0x41) {
    Published_SpeedButton10Click_0042e0a4(param_1,param_2);
  }
  else if (*param_3 == 0x53) {
    Published_SpeedButton15Click_0042dfd0(param_1,param_2);
  }
  else if (*param_3 == 0x20) {
    if (*(char *)(*(int *)(param_1 + 0x454) + 0x130) == '\0') {
      FUN_00589f34(*(undefined4 *)(param_1 + 0x454),
                   CONCAT31((int3)((uint)*(int *)(param_1 + 0x454) >> 8),1));
    }
    else {
      FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0);
    }
    Published_SpeedButton1Click_0041a07c(param_1,param_2);
  }
  else {
    fVar1 = *(float *)(DAT_005c98d0 + 0x87c);
    *(undefined1 *)(param_1 + 0xad4) = 1;
    if (*param_3 == 0x26) {
      *(float *)(DAT_005c98d0 + 0x86c) = *(float *)(DAT_005c98d0 + 0x86c) - fVar1;
      *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
    }
    if (*param_3 == 0x28) {
      *(float *)(DAT_005c98d0 + 0x86c) = *(float *)(DAT_005c98d0 + 0x86c) + fVar1;
      *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
    }
    if (*param_3 == 0x25) {
      if (((*(float *)(DAT_005c98d0 + 0x86c) < _DAT_00404d6c) &&
          (_DAT_00404d70 <= *(float *)(DAT_005c98d0 + 0x86c))) ||
         ((*(float *)(DAT_005c98d0 + 0x86c) < _DAT_00404d74 &&
          (_DAT_00404d78 < *(float *)(DAT_005c98d0 + 0x86c))))) {
        *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) - fVar1;
      }
      else {
        *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) + fVar1;
      }
      *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
    }
    if (*param_3 == 0x27) {
      if (((*(float *)(DAT_005c98d0 + 0x86c) < _DAT_00404d6c) &&
          (_DAT_00404d70 <= *(float *)(DAT_005c98d0 + 0x86c))) ||
         ((*(float *)(DAT_005c98d0 + 0x86c) < _DAT_00404d74 &&
          (_DAT_00404d78 < *(float *)(DAT_005c98d0 + 0x86c))))) {
        *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) + fVar1;
      }
      else {
        *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) - fVar1;
      }
      *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
    }
    if (_DAT_00404d74 < *(float *)(DAT_005c98d0 + 0x870)) {
      *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) - _DAT_00404d74;
    }
    if (*(float *)(DAT_005c98d0 + 0x870) < _DAT_00404d70) {
      *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) + _DAT_00404d74;
    }
    if (_DAT_00404d74 < *(float *)(DAT_005c98d0 + 0x86c)) {
      *(float *)(DAT_005c98d0 + 0x86c) = *(float *)(DAT_005c98d0 + 0x86c) - _DAT_00404d74;
    }
    if (*(float *)(DAT_005c98d0 + 0x86c) < _DAT_00404d70) {
      *(float *)(DAT_005c98d0 + 0x86c) = *(float *)(DAT_005c98d0 + 0x86c) + _DAT_00404d74;
    }
  }
  return;
}



// Entry 00404d7c, recovered name Published_FormResize_00404d7c

void Published_FormResize_00404d7c(int param_1)

{
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  if (DAT_005c98d0 != 0) {
    if (*(char *)(*(int *)(param_1 + 0x338) + 0x2c) == '\0') {
      FUN_004d7e2c(DAT_005c98d0,*(int *)(param_1 + 0x338),param_1,(float)*(int *)(param_1 + 0x3c),
                   (float)*(int *)(param_1 + 0x38));
    }
    else {
      FUN_004d7e2c(DAT_005c98d0,param_1,*(int *)(param_1 + 0x43c),
                   (float)(*(int *)(param_1 + 0x3c) - *(int *)(*(int *)(param_1 + 0x43c) + 0x3c)),
                   (float)*(int *)(param_1 + 0x38));
    }
    for (iStack_10 = 0; iStack_10 < DAT_005b8554; iStack_10 = iStack_10 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + iStack_10 * 4));
    }
    DAT_005b8554 = 0;
    for (iStack_14 = 0; iStack_14 < DAT_005b8558; iStack_14 = iStack_14 + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + iStack_14 * 4));
    }
    DAT_005b8558 = 0;
    for (iStack_18 = 0; iStack_18 < DAT_005b855c; iStack_18 = iStack_18 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + iStack_18 * 4));
    }
    DAT_005b855c = 0;
    for (iStack_1c = 0; iStack_1c < DAT_005b8550; iStack_1c = iStack_1c + 1) {
      for (iStack_20 = 0; iStack_20 < *(int *)(&DAT_005c98dc + iStack_1c * 0x6bd4);
          iStack_20 = iStack_20 + 1) {
        (&DAT_005c9900)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c993d)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c9979)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c99b5)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c99f1)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c9901)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c993e)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c997a)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c99b6)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
        (&DAT_005c99f2)[iStack_20 * 0x114 + iStack_1c * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
  }
  return;
}



// Entry 00404fd0, recovered name Published_FormMouseDown_00404fd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormMouseDown_00404fd0
               (int param_1,undefined4 param_2,char param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 uVar3;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  undefined4 local_54;
  undefined4 *local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined1 local_40 [11];
  char local_35;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined2 local_1c;
  int local_10;
  undefined1 local_8 [4];
  
  local_35 = param_3;
  local_34 = param_2;
  local_30 = param_1;
  FUN_00596a18(&DAT_005b9ee0);
  if ((DAT_005b8554 < 1) && (DAT_005b855c < 1)) {
    DAT_005b856e = '\0';
  }
  else {
    DAT_005b856e = '\x01';
  }
  if (local_35 == '\x01') {
    (**(code **)(**(int **)(local_30 + 0x394) + 0x40))(*(int **)(local_30 + 0x394),param_5,param_4);
    *in_FS_OFFSET = local_2c;
    return;
  }
  if (local_35 == '\0') {
    FUN_0059b09c();
    uVar3 = extraout_var;
    if (((in_ST0 < (longdouble)_DAT_004054a8) &&
        (FUN_0059b09c(), uVar3 = extraout_var_00, in_ST1 < (longdouble)_DAT_004054a8)) &&
       (FUN_0059b09c(), uVar3 = extraout_var_01, in_ST2 < (longdouble)_DAT_004054a8)) {
      (**(code **)(**(int **)(local_30 + 0x540) + 0x5c))(*(int **)(local_30 + 0x540),0);
      FUN_00569200(*(undefined4 *)(local_30 + 0x540),0);
      local_1c = 8;
      puVar1 = (undefined4 *)FUN_005a2750(local_8,&DAT_005b8894);
      local_10 = local_10 + 1;
      FUN_00569318(*(undefined4 *)(local_30 + 0x5e0),*puVar1);
      local_10 = local_10 + -1;
      FUN_005a28c0(local_8,2);
      FUN_00569200(*(undefined4 *)(local_30 + 0x5e0),0);
      uVar3 = extraout_var_02;
    }
    if (DAT_005b856d == '\0') {
      FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,CONCAT22(uVar3,2));
    }
    if (DAT_005b856e != '\0') {
      DAT_005b856f = 1;
      _DAT_005b8578 = param_5;
      DAT_005b857c = param_4;
    }
    if (DAT_005b856d != '\0') {
      FUN_004d873c(DAT_005c98d0,param_5,param_4);
      local_44 = 0;
      while( true ) {
        if (DAT_005b8554 <= local_44) goto LAB_004051c6;
        if (*(char *)(*(int *)(&DAT_0060cf24 + local_44 * 4) + 0x339) != '\0') break;
        local_44 = local_44 + 1;
      }
      local_48 = 0;
      do {
        local_40[local_48] =
             *(undefined1 *)(*(int *)(&DAT_0060cf24 + local_44 * 4) + 0x300 + local_48);
        local_48 = local_48 + 1;
      } while (local_48 < 10);
LAB_004051c6:
      for (local_4c = 0; local_4c < DAT_005b8554; local_4c = local_4c + 1) {
        iVar2 = FUN_00596728();
        if (iVar2 == 0) {
          *(undefined1 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x339) = 1;
        }
      }
      local_54 = 1;
      local_50 = &local_54;
      DAT_005b8548 = FUN_004054b4(local_30,local_50);
      DAT_005b8544 = *local_50;
      *in_FS_OFFSET = local_2c;
      return;
    }
    if (DAT_005b8573 != '\0') {
      if (9 < DAT_005b8550) {
        *in_FS_OFFSET = local_2c;
        return;
      }
      DAT_005b8550 = DAT_005b8550 + 1;
      *(int *)(local_30 + 0xae4) = *(int *)(local_30 + 0xae4) + 1;
      (&DAT_005c2d08)[DAT_005b8550 * 0x1af5] = 6;
      FUN_00518c90();
      FUN_00406b0c(local_30);
      DAT_005b8573 = 0;
      *in_FS_OFFSET = local_2c;
      return;
    }
    if (DAT_005b856c != '\0') {
      if (9 < DAT_005b8550) {
        *in_FS_OFFSET = local_2c;
        return;
      }
      DAT_005b8550 = DAT_005b8550 + 1;
      *(int *)(local_30 + 0xae4) = *(int *)(local_30 + 0xae4) + 1;
      (&DAT_005c2d08)[DAT_005b8550 * 0x1af5] = 1;
      FUN_004d8920();
      if (DAT_005b8541 == '\x02') {
        FUN_0041a4cc(local_30);
        DAT_005b856c = 0;
        *in_FS_OFFSET = local_2c;
        return;
      }
      FUN_00406b0c(local_30);
    }
    DAT_005b856c = '\0';
  }
  *in_FS_OFFSET = local_2c;
  return;
}



// Entry 00406454, recovered name Published_FormMouseMove_00406454

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormMouseMove_00406454
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  int local_1c;
  
  if (param_4 < *(int *)(*(int *)(param_1 + 0x43c) + 0x3c) + 0x19) {
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0);
  }
  if (*(char *)(param_1 + 0xad5) != '\0') {
    fVar1 = (float)(_DAT_00406834 * (longdouble)(param_5 - _DAT_005b8578));
    fVar2 = (float)(_DAT_00406834 * (longdouble)(DAT_005b857c - param_4));
    DAT_005b856f = '\0';
    for (local_1c = 0; local_1c < DAT_005b8554; local_1c = local_1c + 1) {
      if ((*(char *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x9dc) == '\x03') &&
         ((int)*(char *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x301) ==
          *(int *)(param_1 + 0xad8))) {
        *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x398) =
             *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x398) + fVar1;
        *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x39c) =
             *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x39c) + fVar2;
      }
      if ((*(char *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x9dc) == '\x04') &&
         ((int)*(char *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x305) ==
          *(int *)(param_1 + 0xad8))) {
        *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x398) =
             *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x398) + fVar1;
        *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x39c) =
             *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x39c) + fVar2;
        *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x3a8) =
             *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x3a8) + fVar1;
        *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x3ac) =
             *(float *)(*(int *)(&DAT_0060cf24 + local_1c * 4) + 0x3ac) + fVar2;
      }
    }
    *(undefined1 *)(param_1 + 0xad4) = 1;
    _DAT_005b8578 = param_5;
    DAT_005b857c = param_4;
    *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  }
  if (DAT_005b856f != '\0') {
    *(undefined1 *)(param_1 + 0xad4) = 1;
    fVar1 = (float)(_DAT_00406840 * (longdouble)(param_5 - _DAT_005b8578));
    lVar3 = _DAT_00406840 * (longdouble)(param_4 - DAT_005b857c);
    if (((*(float *)(DAT_005c98d0 + 0x86c) < _DAT_0040684c) &&
        (_DAT_00406850 < *(float *)(DAT_005c98d0 + 0x86c))) ||
       ((*(float *)(DAT_005c98d0 + 0x86c) < _DAT_00406854 &&
        (_DAT_00406858 < *(float *)(DAT_005c98d0 + 0x86c))))) {
      *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) + fVar1;
    }
    else {
      *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) - fVar1;
    }
    *(float *)(DAT_005c98d0 + 0x86c) = *(float *)(DAT_005c98d0 + 0x86c) + (float)lVar3;
    if (_DAT_00406854 < *(float *)(DAT_005c98d0 + 0x870)) {
      *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) - _DAT_00406854;
    }
    if (*(float *)(DAT_005c98d0 + 0x870) < _DAT_00406850) {
      *(float *)(DAT_005c98d0 + 0x870) = *(float *)(DAT_005c98d0 + 0x870) + _DAT_00406854;
    }
    if (_DAT_00406854 < *(float *)(DAT_005c98d0 + 0x86c)) {
      *(float *)(DAT_005c98d0 + 0x86c) = *(float *)(DAT_005c98d0 + 0x86c) - _DAT_00406854;
    }
    if (*(float *)(DAT_005c98d0 + 0x86c) < _DAT_00406850) {
      *(float *)(DAT_005c98d0 + 0x86c) = *(float *)(DAT_005c98d0 + 0x86c) + _DAT_00406854;
    }
    _DAT_005b8578 = param_5;
    DAT_005b857c = param_4;
    *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  }
  return;
}



// Entry 0040685c, recovered name Published_FormMouseUp_0040685c

void Published_FormMouseUp_0040685c(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined1 uStack_d;
  undefined4 uStack_c;
  int iStack_8;
  
  uStack_d = param_3;
  uStack_c = param_2;
  iStack_8 = param_1;
  if (DAT_005b856d == '\0') {
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,1);
  }
  else {
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0);
  }
  DAT_005b856e = 1;
  DAT_005b856f = 0;
  uStack_18 = 0xffffffff;
  puStack_14 = &uStack_18;
  for (iStack_20 = 0; iStack_20 < DAT_005b8550; iStack_20 = iStack_20 + 1) {
    for (iStack_24 = 0; iStack_24 < *(int *)(&DAT_005c98dc + iStack_20 * 0x6bd4);
        iStack_24 = iStack_24 + 1) {
      (&DAT_005c993c)[iStack_24 * 0x114 + iStack_20 * 0x6bd4] = 0;
      (&DAT_005c9978)[iStack_24 * 0x114 + iStack_20 * 0x6bd4] = 0;
      (&DAT_005c99b4)[iStack_24 * 0x114 + iStack_20 * 0x6bd4] = 0;
      (&DAT_005c99f0)[iStack_24 * 0x114 + iStack_20 * 0x6bd4] = 0;
    }
  }
  if ((DAT_005b856d != '\0') && (*(char *)(*(int *)(iStack_8 + 0x53c) + 0x130) == '\0')) {
    DAT_005b8548 = FUN_004054b4(iStack_8,puStack_14);
    DAT_005b8544 = *puStack_14;
  }
  if (*(char *)(iStack_8 + 0xad5) == '\0') {
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x414),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x418),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x41c),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x420),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x424),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x428),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x42c),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x49c),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x4a0),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x4dc),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x4e0),0);
    FUN_00589f34(*(undefined4 *)(iStack_8 + 0x504),0);
  }
  else {
    DAT_005b8548 = 0xffffffff;
    DAT_005b8544 = 0xffffffff;
    *(undefined1 *)(iStack_8 + 0xad5) = 0;
    FUN_004362d8(iStack_8);
    for (iStack_28 = 0; iStack_28 < DAT_005b8550; iStack_28 = iStack_28 + 1) {
      for (iStack_2c = 0; iStack_2c < *(int *)(&DAT_005c98dc + iStack_28 * 0x6bd4);
          iStack_2c = iStack_2c + 1) {
        (&DAT_005c993c)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
        (&DAT_005c9978)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
        (&DAT_005c99b4)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
        (&DAT_005c99f0)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
      }
    }
  }
  return;
}



// Entry 00419910, recovered name Published_N2Click_00419910

undefined4 Published_N2Click_00419910(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_38;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  FUN_00596a18(&DAT_005b9f8c);
  if (((1 < DAT_005b8554) || (1 < DAT_005b855c)) && (0 < *(int *)(param_1 + 0xae4))) {
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) = 0;
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fd) = 0;
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fe) = 0;
    (**(code **)(**(int **)PTR__SaveFileForm_005c9474 + 0xd8))();
    if (*(char *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) != '\0') {
      *in_FS_OFFSET = local_38;
      return local_38;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x414) + 0x5c))(*(int **)(param_1 + 0x414),1);
  (**(code **)(**(int **)(param_1 + 0x418) + 0x5c))(*(int **)(param_1 + 0x418),1);
  (**(code **)(**(int **)(param_1 + 0x41c) + 0x5c))(*(int **)(param_1 + 0x41c),1);
  (**(code **)(**(int **)(param_1 + 0x420) + 0x5c))(*(int **)(param_1 + 0x420),1);
  (**(code **)(**(int **)(param_1 + 0x424) + 0x5c))(*(int **)(param_1 + 0x424),1);
  (**(code **)(**(int **)(param_1 + 0x428) + 0x5c))(*(int **)(param_1 + 0x428),1);
  (**(code **)(**(int **)(param_1 + 0x42c) + 0x5c))(*(int **)(param_1 + 0x42c),1);
  (**(code **)(**(int **)(param_1 + 0x49c) + 0x5c))(*(int **)(param_1 + 0x49c),1);
  (**(code **)(**(int **)(param_1 + 0x4a0) + 0x5c))(*(int **)(param_1 + 0x4a0),1);
  (**(code **)(**(int **)(param_1 + 0x480) + 0x5c))(*(int **)(param_1 + 0x480),1);
  (**(code **)(**(int **)(param_1 + 0x4dc) + 0x5c))(*(int **)(param_1 + 0x4dc),1);
  (**(code **)(**(int **)(param_1 + 0x4e0) + 0x5c))(*(int **)(param_1 + 0x4e0),1);
  (**(code **)(**(int **)(param_1 + 0x504) + 0x5c))(*(int **)(param_1 + 0x504),1);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x414),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x418),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x41c),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x420),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x424),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x428),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x42c),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x49c),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x4a0),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x4dc),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x4e0),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x504),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x33c),1);
  FUN_00569200(*(undefined4 *)(param_1 + 0x410),1);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x338),1);
  FUN_00569200(*(undefined4 *)(param_1 + 0x43c),1);
  iVar2 = *(int *)(param_1 + 0x3c) - *(int *)(*(int *)(param_1 + 0x43c) + 0x3c);
  FUN_004d7e2c(DAT_005c98d0,param_1,iVar2,(float)iVar2,(float)*(int *)(param_1 + 0x38));
  *(undefined4 *)(DAT_005c98d0 + 0x8bc) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d0 + 0x8c0) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d0 + 0x8c4) = 0x3f800000;
  (**(code **)(**(int **)(param_1 + 0x464) + 0x5c))(*(int **)(param_1 + 0x464),1);
  (**(code **)(**(int **)(param_1 + 0x468) + 0x5c))(*(int **)(param_1 + 0x468),1);
  *(undefined4 *)(param_1 + 0xb54) = 0;
  *(undefined4 *)(param_1 + 0xb58) = 0;
  *(undefined4 *)(param_1 + 0xb5c) = 0;
  *(undefined4 *)(param_1 + 0xb24) = 0x3f0ccccd;
  *(undefined4 *)(param_1 + 0xb28) = 0x3f3ae148;
  *(undefined4 *)(param_1 + 0xb2c) = 0x3e19999a;
  *(undefined4 *)(param_1 + 0xb30) = 0x3da3d70a;
  *(undefined4 *)(param_1 + 0xb34) = 0x3f11eb85;
  *(undefined4 *)(param_1 + 0xb38) = 0x3f51eb85;
  *(undefined4 *)(param_1 + 0xb3c) = 0x3f63d70a;
  *(undefined4 *)(param_1 + 0xb40) = 0x3eb33333;
  *(undefined4 *)(param_1 + 0xb44) = 0x3db851ec;
  *(undefined4 *)(param_1 + 0xaf4) = 0x3e800000;
  *(undefined4 *)(param_1 + 0xaf8) = 0x3e570a3d;
  *(undefined4 *)(param_1 + 0xafc) = 0x3e19999a;
  *(undefined4 *)(param_1 + 0xb00) = 0x3e8a3d71;
  *(undefined4 *)(param_1 + 0xb04) = 0x3f5eb852;
  *(undefined4 *)(param_1 + 0xb08) = 0x3f2e147b;
  *(undefined4 *)(param_1 + 0xb0c) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0xb10) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0xb14) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb18) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb1c) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0xb20) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0xb48) = 0x3f3fbe77;
  *(undefined4 *)(param_1 + 0xb4c) = 0x3ec49ba6;
  *(undefined4 *)(param_1 + 0xb50) = 0x3d50e560;
  *(undefined4 *)(DAT_005c98d0 + 0x89c) = 0x3e99999a;
  *(undefined4 *)(DAT_005c98d0 + 0x8a0) = 0x3e99999a;
  *(undefined4 *)(DAT_005c98d0 + 0x8a4) = 0x3e99999a;
  *(undefined4 *)(DAT_005c98d0 + 0x8a8) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x38) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x3c) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x40) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x44) = 0;
  *(undefined4 *)(DAT_005c98d4 + 0x18) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x1c) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x20) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x24) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x28) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x2c) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x30) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d4 + 0x34) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb60) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0xb64) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0xb68) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0xb6c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb70) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb74) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb78) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb7c) = 0;
  *(undefined4 *)(param_1 + 0xb80) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb84) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb88) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb8c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb90) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb94) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb98) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb9c) = 0x3f800000;
  FUN_004d7fdc(DAT_005c98d0);
  FUN_004d7ffc(DAT_005c98d0,0);
  *(undefined4 *)(DAT_005c98d0 + 0x88c) = *(undefined4 *)(param_1 + 0xb54);
  *(undefined4 *)(DAT_005c98d0 + 0x890) = *(undefined4 *)(param_1 + 0xb58);
  *(undefined4 *)(DAT_005c98d0 + 0x894) = *(undefined4 *)(param_1 + 0xb5c);
  FUN_004d6758(DAT_005c98d4);
  FUN_005a2750(local_c,&DAT_005b89a4);
  FUN_005a28f0(param_1 + 0xba0,local_c);
  FUN_005a28c0(local_c,2);
  FUN_005a2750(local_10,&DAT_005b89a5);
  FUN_005a28f0(param_1 + 0xba8,local_10);
  FUN_005a28c0(local_10,2);
  FUN_00418eb4(param_1);
  FUN_004d7928(DAT_005c98d0,param_1,*(int *)(param_1 + 0x43c),
               (float)(*(int *)(_Form1 + 0x3c) - *(int *)(*(int *)(param_1 + 0x43c) + 0x3c)),
               (float)*(int *)(_Form1 + 0x38));
  FUN_004d8328(DAT_005c98d0);
  FUN_0040328c(&local_8);
  FUN_005a2750(local_14,&DAT_005b89a6);
  FUN_005a28f0(&local_8,local_14);
  FUN_005a28c0(local_14,2);
  FUN_00569318(param_1,local_8);
  uVar1 = FUN_005a28c0(&local_8,2);
  *in_FS_OFFSET = local_38;
  return uVar1;
}



// Entry 0041a07c, recovered name Published_SpeedButton1Click_0041a07c

int Published_SpeedButton1Click_0041a07c(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_FS_OFFSET;
  int local_40;
  int local_3c;
  int local_38;
  int local_2c;
  undefined1 local_8 [4];
  
  iVar1 = FUN_00596a18(&DAT_005b9fe0);
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if (DAT_005b856d == '\0') {
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0);
    DAT_005b856d = '\x01';
    FUN_00589fb4(*(undefined4 *)(param_1 + 0x454),1);
    DAT_005b8571 = 0;
    DAT_005b8570 = 0;
    DAT_005b8572 = 0;
    if (*(char *)(*(int *)(param_1 + 0x36c) + 0x38) != '\0') {
      FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
      *(undefined4 *)(DAT_005c98d0 + 0x86c) = DAT_00618aa4;
      *(undefined4 *)(DAT_005c98d0 + 0x870) = DAT_00618aa8;
      *(undefined4 *)(DAT_005c98d0 + 0x874) = DAT_00618aac;
    }
    *in_FS_OFFSET = local_2c;
    iVar1 = local_2c;
  }
  else {
    if (DAT_005b856d == '\x01') {
      DAT_005b856d = '\0';
      for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
        *(undefined1 *)(*(int *)(&DAT_0060cf24 + local_38 * 4) + 0x339) = 0;
      }
      for (local_3c = 0; local_3c < DAT_005b8550; local_3c = local_3c + 1) {
        for (local_40 = 0; local_40 < *(int *)(&DAT_005c98dc + local_3c * 0x6bd4);
            local_40 = local_40 + 1) {
          (&DAT_005c993c)[local_40 * 0x114 + local_3c * 0x6bd4] = 0;
          (&DAT_005c9978)[local_40 * 0x114 + local_3c * 0x6bd4] = 0;
          (&DAT_005c99b4)[local_40 * 0x114 + local_3c * 0x6bd4] = 0;
          (&DAT_005c99f0)[local_40 * 0x114 + local_3c * 0x6bd4] = 0;
        }
      }
      iVar1 = *(int *)(param_1 + 0x540);
      if (*(char *)(iVar1 + 0x47) == '\x01') {
        FUN_00569200(*(undefined4 *)(param_1 + 0x540),0);
        (**(code **)(**(int **)(param_1 + 0x540) + 0x5c))(*(int **)(param_1 + 0x540),0);
        puVar2 = (undefined4 *)FUN_005a2750(local_8,&DAT_005b89cc);
        FUN_00569318(*(undefined4 *)(param_1 + 0x5e0),*puVar2);
        FUN_005a28c0(local_8,2);
        FUN_00569200(*(undefined4 *)(param_1 + 0x5e0),0);
        FUN_0053d8a0(*(undefined4 *)(param_1 + 0x540),0);
        iVar1 = FUN_004362d8(param_1);
      }
    }
    *in_FS_OFFSET = local_2c;
  }
  return iVar1;
}



// Entry 0041a4b4, recovered name Published_Timer1Timer_0041a4b4

void Published_Timer1Timer_0041a4b4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0041a2b4(param_1,param_2,param_3,param_2);
  return;
}



// Entry 0041f8f4, recovered name Published_N37Click_0041f8f4

void Published_N37Click_0041f8f4(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005ba31c);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  DAT_005b8541 = 1;
  FUN_0053b0a4(*(undefined4 *)(param_1 + 0x458),2);
  FUN_00555574(param_1,*(undefined4 *)(param_1 + 0x498));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 0041fb94, recovered name Published_N25Click_0041fb94

void Published_N25Click_0041fb94(int param_1)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 extraout_var;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005ba330);
  FUN_00563364(*(undefined4 *)(param_1 + 0x378),*(undefined4 *)(*(int *)(param_1 + 0x374) + 0x58));
  cVar2 = (**(code **)(**(int **)(param_1 + 0x378) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,CONCAT22(extraout_var,0xfff5));
    FUN_005693d4(*(undefined4 *)(param_1 + 0x374),*(undefined4 *)(*(int *)(param_1 + 0x378) + 0x50))
    ;
    for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
    }
    DAT_005b8554 = 0;
    for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
    }
    DAT_005b8558 = 0;
    for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
    }
    DAT_005b855c = 0;
    for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
      for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
          local_48 = local_48 + 1) {
        (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    FUN_004d8328(DAT_005c98d0);
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
    if (local_16 != 0) {
      return;
    }
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00427b70, recovered name Published_N4Click_00427b70

void Published_N4Click_00427b70(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar4;
  undefined4 *in_FS_OFFSET;
  char acStack_4dc [1028];
  int iStack_d8;
  int iStack_d4;
  undefined2 uStack_ce;
  undefined4 uStack_b4;
  int iStack_b0;
  undefined4 uStack_ac;
  undefined2 uStack_9c;
  short sStack_9a;
  int iStack_90;
  undefined1 auStack_88 [4];
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 auStack_7c [4];
  undefined1 auStack_78 [4];
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [60];
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  int *piStack_28;
  int iStack_24;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [20];
  
  uStack_b4 = param_2;
  iStack_b0 = param_1;
  FUN_00596a18(0x5bc714);
  *(undefined2 *)(iStack_b0 + 0x5f0) = 5;
  *(undefined2 *)(iStack_b0 + 0x61c) = 0x10;
  *(undefined2 *)(iStack_b0 + 0x61e) = 7;
  if ((((*(char *)(iStack_b0 + 0x624) == '2') && (*(char *)(iStack_b0 + 0x626) == '0')) &&
      (*(char *)(iStack_b0 + 0x627) == '3')) &&
     (((*(char *)(iStack_b0 + 0x628) == '2' && (*(char *)(iStack_b0 + 0x629) == '1')) &&
      (*(char *)(iStack_b0 + 0x62a) == '8')))) {
    *(undefined2 *)(iStack_b0 + 0x5f0) = 0xc;
    *(undefined2 *)(iStack_b0 + 0x61c) = 9;
    *(undefined2 *)(iStack_b0 + 0x61e) = 0;
    uStack_ce = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,
                 CONCAT22((short)((uint)*(int *)PTR_DAT_005c9498 >> 0x10),0xfff5));
    uStack_9c = 0x140;
    FUN_005a2750(auStack_6c,0x5b8bf3);
    iStack_90 = iStack_90 + 1;
    cVar1 = FUN_005a29a8(iStack_b0 + 0xba0,auStack_6c);
    iStack_90 = iStack_90 + -1;
    FUN_005a28c0(auStack_6c,2);
    if (cVar1 == '\0') {
      uStack_9c = 0x14c;
      FUN_0040328c(auStack_70);
      iStack_90 = iStack_90 + 1;
      uStack_9c = 0x164;
      uVar2 = FUN_0040328c(auStack_74);
      iStack_90 = iStack_90 + 1;
      FUN_0055a58c(*(undefined4 *)PTR_DAT_005c9494,uVar2);
      FUN_00423b60(auStack_74);
      FUN_00596774();
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(auStack_74,2);
      iStack_d8 = FUN_005967a4();
      for (iStack_d4 = iStack_d8; acStack_4dc[iStack_d4] != '\\'; iStack_d4 = iStack_d4 + -1) {
      }
      acStack_4dc[iStack_d4] = '\0';
      uStack_9c = 0x170;
      uVar2 = FUN_005a2750(auStack_78,acStack_4dc);
      iStack_90 = iStack_90 + 1;
      FUN_005a28f0(auStack_70,uVar2);
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(auStack_78,2);
      uStack_9c = 0x17c;
      uVar2 = FUN_0040328c(&uStack_80);
      iStack_90 = iStack_90 + 1;
      FUN_005a2750(auStack_7c,0x5b8bf4);
      iStack_90 = iStack_90 + 1;
      FUN_005a2904(auStack_70,auStack_7c,uVar2);
      FUN_00562c84(*(undefined4 *)(iStack_b0 + 900),uStack_80);
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(&uStack_80,2);
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(auStack_7c,2);
      cVar1 = (**(code **)(**(int **)(iStack_b0 + 900) + 0x3c))();
      if (cVar1 == '\0') {
        *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) = 1;
      }
      else {
        uStack_9c = 0x188;
        uVar2 = FUN_0040328c(&uStack_84);
        iStack_90 = iStack_90 + 1;
        FUN_00562c1c(*(undefined4 *)(iStack_b0 + 900),uVar2);
        FUN_0041fe4c(iStack_b0,uStack_84);
        iStack_90 = iStack_90 + -1;
        FUN_005a28c0(&uStack_84,2);
        uStack_9c = 0x194;
        uVar2 = FUN_0040328c(auStack_88);
        iStack_90 = iStack_90 + 1;
        FUN_00562c1c(*(undefined4 *)(iStack_b0 + 900),uVar2);
        FUN_005a28f0(iStack_b0 + 0xba0,auStack_88);
        iStack_90 = iStack_90 + -1;
        FUN_005a28c0(auStack_88,2);
      }
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(auStack_70,2);
      uVar4 = extraout_var_00;
    }
    else {
      FUN_0041fe4c(iStack_b0,*(undefined4 *)(iStack_b0 + 0xba0));
      uVar4 = extraout_var;
    }
    uStack_9c = 0;
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,CONCAT22(uVar4,uStack_ce));
    if (sStack_9a != 0) {
      return;
    }
    *in_FS_OFFSET = uStack_ac;
  }
  else {
    uStack_9c = 0x38;
    FUN_005a2750(auStack_18,0x5b8b14);
    iStack_90 = iStack_90 + 1;
    FUN_005a28f0(iStack_b0 + 0xba0,auStack_18);
    iStack_90 = iStack_90 + -1;
    FUN_005a28c0(auStack_18,2);
    if (*(int *)PTR__About_005c947c == 0) {
      uVar2 = FUN_004d33a8(PTR_PTR_005c2df4,1,iStack_b0);
      *(undefined4 *)PTR__About_005c947c = uVar2;
      uStack_9c = 0x44;
      puVar3 = (undefined4 *)FUN_005a2750(auStack_1c,0x5b8b15);
      iStack_90 = iStack_90 + 1;
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(auStack_1c,2);
      uStack_9c = 0x50;
      puVar3 = (undefined4 *)FUN_005a2750(auStack_20,0x5b8b2a);
      iStack_90 = iStack_90 + 1;
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(auStack_20,2);
      (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
      piStack_28 = *(int **)PTR__About_005c947c;
      if (piStack_28 != (int *)0x0) {
        iStack_24 = *piStack_28;
        uStack_9c = 0x68;
        (**(code **)(*piStack_28 + -4))(piStack_28,3);
      }
      *(undefined4 *)PTR__About_005c947c = 0;
    }
    else {
      uStack_9c = 0x74;
      puVar3 = (undefined4 *)FUN_005a2750(auStack_2c,0x5b8b3b);
      iStack_90 = iStack_90 + 1;
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(auStack_2c,2);
      uStack_9c = 0x80;
      puVar3 = (undefined4 *)FUN_005a2750(auStack_30,0x5b8b50);
      iStack_90 = iStack_90 + 1;
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
      iStack_90 = iStack_90 + -1;
      FUN_005a28c0(auStack_30,2);
      (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
    }
    *in_FS_OFFSET = uStack_ac;
  }
  return;
}



// Entry 00428ac0, recovered name Published_N3Click_00428ac0

undefined4 Published_N3Click_00428ac0(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 extraout_var;
  undefined4 *in_FS_OFFSET;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bc8b4);
  if (((1 < DAT_005b8554) || (1 < DAT_005b855c)) && (0 < *(int *)(param_1 + 0xae4))) {
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) = 0;
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fd) = 0;
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fe) = 0;
    (**(code **)(**(int **)PTR__SaveFileForm_005c9474 + 0xd8))();
    if (*(char *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) != '\0') {
      *in_FS_OFFSET = local_28;
      return local_28;
    }
  }
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  FUN_00423ba4(param_1);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0);
  DAT_005b856d = 0;
  (**(code **)(**(int **)(param_1 + 0x414) + 0x5c))(*(int **)(param_1 + 0x414),1);
  (**(code **)(**(int **)(param_1 + 0x418) + 0x5c))(*(int **)(param_1 + 0x418),1);
  (**(code **)(**(int **)(param_1 + 0x41c) + 0x5c))(*(int **)(param_1 + 0x41c),1);
  (**(code **)(**(int **)(param_1 + 0x420) + 0x5c))(*(int **)(param_1 + 0x420),1);
  (**(code **)(**(int **)(param_1 + 0x424) + 0x5c))(*(int **)(param_1 + 0x424),1);
  (**(code **)(**(int **)(param_1 + 0x428) + 0x5c))(*(int **)(param_1 + 0x428),1);
  (**(code **)(**(int **)(param_1 + 0x42c) + 0x5c))(*(int **)(param_1 + 0x42c),1);
  (**(code **)(**(int **)(param_1 + 0x49c) + 0x5c))(*(int **)(param_1 + 0x49c),1);
  (**(code **)(**(int **)(param_1 + 0x4a0) + 0x5c))(*(int **)(param_1 + 0x4a0),1);
  (**(code **)(**(int **)(param_1 + 0x480) + 0x5c))(*(int **)(param_1 + 0x480),1);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x414),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x418),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x41c),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x420),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x424),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x428),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x42c),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x49c),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x4a0),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x4dc),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x4e0),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x504),0);
  uVar2 = FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,CONCAT22(extraout_var,uVar1));
  if (local_16 == 0) {
    *in_FS_OFFSET = local_28;
    return uVar2;
  }
  return uVar2;
}



// Entry 00428d34, recovered name Published_N34Click_00428d34

void Published_N34Click_00428d34(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bc8c8);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  DAT_005b8574 = 1;
  DAT_005b8575 = 0;
  DAT_005b8541 = 2;
  FUN_0053b0a4(*(undefined4 *)(param_1 + 0x458),3);
  FUN_00555574(param_1,*(undefined4 *)(param_1 + 0x498));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00428fe4, recovered name Published_N39Click_00428fe4

void Published_N39Click_00428fe4(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bc8dc);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  DAT_005b8574 = 0;
  DAT_005b8575 = 1;
  DAT_005b8541 = 2;
  FUN_0053b0a4(*(undefined4 *)(param_1 + 0x458),4);
  FUN_00555574(param_1,*(undefined4 *)(param_1 + 0x498));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00429284, recovered name Published_N5Click_00429284

void Published_N5Click_00429284(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  char local_4d4 [1036];
  int local_c8;
  int local_c4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined2 local_98;
  int local_8c;
  undefined4 local_64 [8];
  undefined4 local_44;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  int *local_2c;
  int local_28;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [20];
  
  local_b0 = param_2;
  local_ac = param_1;
  FUN_00596a18(&DAT_005bcabc);
  *(undefined2 *)(local_ac + 0x5f0) = 5;
  *(undefined2 *)(local_ac + 0x61c) = 0x10;
  *(undefined2 *)(local_ac + 0x61e) = 7;
  FUN_00595634();
  if ((((*(char *)(local_ac + 0x624) == '2') && (*(char *)(local_ac + 0x626) == '0')) &&
      (*(char *)(local_ac + 0x627) == '3')) &&
     (((*(char *)(local_ac + 0x628) == '2' && (*(char *)(local_ac + 0x629) == '1')) &&
      (*(char *)(local_ac + 0x62a) == '8')))) {
    local_98 = 0x8c;
    FUN_0040328c(local_18);
    local_8c = local_8c + 1;
    local_98 = 0xa4;
    uVar2 = FUN_0040328c(local_38);
    local_8c = local_8c + 1;
    FUN_0055a58c(*(undefined4 *)PTR_DAT_005c9494,uVar2);
    FUN_00423b60(local_38);
    FUN_00596774();
    local_8c = local_8c + -1;
    FUN_005a28c0(local_38,2);
    local_c8 = FUN_005967a4();
    for (local_c4 = local_c8; local_4d4[local_c4] != '\\'; local_c4 = local_c4 + -1) {
    }
    local_4d4[local_c4] = '\0';
    local_98 = 0xb0;
    uVar2 = FUN_005a2750(local_3c,local_4d4);
    local_8c = local_8c + 1;
    FUN_005a28f0(local_18,uVar2);
    local_8c = local_8c + -1;
    FUN_005a28c0(local_3c,2);
    local_98 = 0xbc;
    uVar2 = FUN_0040328c(&local_44);
    local_8c = local_8c + 1;
    FUN_005a2750(local_40,&DAT_005b8c9a);
    local_8c = local_8c + 1;
    FUN_005a2904(local_18,local_40,uVar2);
    FUN_00562c84(*(undefined4 *)(local_ac + 900),local_44);
    local_8c = local_8c + -1;
    FUN_005a28c0(&local_44,2);
    local_8c = local_8c + -1;
    FUN_005a28c0(local_40,2);
    cVar1 = (**(code **)(**(int **)(local_ac + 900) + 0x3c))();
    if (cVar1 == '\0') {
      *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) = 1;
    }
    else {
      *(undefined2 *)(local_ac + 0x5f0) = 0xc;
      *(undefined2 *)(local_ac + 0x61c) = 9;
      *(undefined2 *)(local_ac + 0x61e) = 0;
      FUN_00595634();
      local_98 = 0x11c;
      uVar2 = FUN_0040328c(local_64);
      local_8c = local_8c + 1;
      FUN_00562c1c(*(undefined4 *)(local_ac + 900),uVar2);
      FUN_0041fe4c(local_ac,local_64[0]);
      local_8c = local_8c + -1;
      FUN_005a28c0(local_64,2);
    }
    local_8c = local_8c + -1;
    FUN_005a28c0(local_18,2);
    *in_FS_OFFSET = local_a8;
  }
  else {
    local_98 = 0x38;
    FUN_005a2750(local_1c,&DAT_005b8c4d);
    local_8c = local_8c + 1;
    FUN_005a28f0(local_ac + 0xba0,local_1c);
    local_8c = local_8c + -1;
    FUN_005a28c0(local_1c,2);
    if (*(int *)PTR__About_005c947c == 0) {
      uVar2 = FUN_004d33a8(PTR_PTR_005c2df4,1,local_ac);
      *(undefined4 *)PTR__About_005c947c = uVar2;
      local_98 = 0x44;
      puVar3 = (undefined4 *)FUN_005a2750(local_20,&DAT_005b8c4e);
      local_8c = local_8c + 1;
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
      local_8c = local_8c + -1;
      FUN_005a28c0(local_20,2);
      local_98 = 0x50;
      puVar3 = (undefined4 *)FUN_005a2750(local_24,&DAT_005b8c63);
      local_8c = local_8c + 1;
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
      local_8c = local_8c + -1;
      FUN_005a28c0(local_24,2);
      (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
      local_2c = *(int **)PTR__About_005c947c;
      if (local_2c != (int *)0x0) {
        local_28 = *local_2c;
        local_98 = 0x68;
        (**(code **)(*local_2c + -4))(local_2c,3);
      }
      *(undefined4 *)PTR__About_005c947c = 0;
    }
    else {
      local_98 = 0x74;
      puVar3 = (undefined4 *)FUN_005a2750(local_30,&DAT_005b8c74);
      local_8c = local_8c + 1;
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2dc),*puVar3);
      local_8c = local_8c + -1;
      FUN_005a28c0(local_30,2);
      local_98 = 0x80;
      puVar3 = (undefined4 *)FUN_005a2750(local_34,&DAT_005b8c89);
      local_8c = local_8c + 1;
      FUN_00569318(*(undefined4 *)(*(int *)PTR__About_005c947c + 0x2e0),*puVar3);
      local_8c = local_8c + -1;
      FUN_005a28c0(local_34,2);
      (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
    }
    *in_FS_OFFSET = local_a8;
  }
  return;
}



// Entry 0042a144, recovered name Published_N9Click_0042a144

void Published_N9Click_0042a144(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00556dd8(param_1,param_2,param_3,param_2);
  return;
}



// Entry 0042a15c, recovered name Published_PopupMenu1Popup_0042a15c

void Published_PopupMenu1Popup_0042a15c(void)

{
  return;
}



// Entry 0042b3f4, recovered name Published_N42Click_0042b3f4

void Published_N42Click_0042b3f4(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton31Click_004345ac(param_1,param_2);
  return;
}



// Entry 0042b410, recovered name Published_N62Click_0042b410

void Published_N62Click_0042b410(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(DAT_005c98d0 + 0x86c) = 0;
  *(undefined4 *)(DAT_005c98d0 + 0x870) = 0;
  *(undefined4 *)(DAT_005c98d0 + 0x874) = 0;
  *(undefined4 *)(DAT_005c98d0 + 0x8bc) = 0x3f800000;
  iVar1 = DAT_005c98d0;
  *(undefined4 *)(DAT_005c98d0 + 0x8c0) = 0x3f800000;
  *(undefined4 *)(DAT_005c98d0 + 0x8c4) = 0x3f800000;
  FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0,iVar1,param_2);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x54c),0);
  DAT_005b856d = 0;
  return;
}



// Entry 0042b4a0, recovered name Published_N15Click_0042b4a0

void Published_N15Click_0042b4a0(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x354),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x35c),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x364),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x300),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x304),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x310),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x2e4),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x2e8),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x2ec),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_00578898(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x374),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_00578898(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x378),uVar4);
  uVar4 = FUN_0059b0c4();
  FUN_00578898(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x37c),uVar4);
  uVar1 = FUN_0059b0c4();
  uVar2 = FUN_0059b0c4();
  uVar3 = FUN_0059b0c4();
  FUN_00569474(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x31c),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_0059b0c4();
  uVar2 = FUN_0059b0c4();
  uVar3 = FUN_0059b0c4();
  FUN_00569474(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x32c),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_0059b0c4();
  uVar2 = FUN_0059b0c4();
  uVar3 = FUN_0059b0c4();
  FUN_00569474(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x324),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_0059b0c4();
  uVar2 = FUN_0059b0c4();
  uVar3 = FUN_0059b0c4();
  FUN_00569474(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x334),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_0059b0c4();
  uVar2 = FUN_0059b0c4();
  uVar3 = FUN_0059b0c4();
  FUN_00569474(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x33c),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_0059b0c4();
  uVar2 = FUN_0059b0c4();
  uVar3 = FUN_0059b0c4();
  FUN_00569474(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x344),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_0059b0c4();
  uVar2 = FUN_0059b0c4();
  uVar3 = FUN_0059b0c4();
  FUN_00569474(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x3ac),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_0059b0c4();
  uVar2 = FUN_0059b0c4();
  uVar3 = FUN_0059b0c4();
  FUN_00569474(*(undefined4 *)(*(int *)PTR__Form2_005c9470 + 0x3b0),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  (**(code **)(**(int **)PTR__Form2_005c9470 + 0xd8))();
  *(undefined4 *)(DAT_005c98d4 + 0x38) = *(undefined4 *)(param_1 + 0xb70);
  *(undefined4 *)(DAT_005c98d4 + 0x3c) = *(undefined4 *)(param_1 + 0xb74);
  *(undefined4 *)(DAT_005c98d4 + 0x40) = *(undefined4 *)(param_1 + 0xb78);
  *(undefined4 *)(DAT_005c98d4 + 0x44) = *(undefined4 *)(param_1 + 0xb7c);
  *(undefined4 *)(DAT_005c98d4 + 0x18) = *(undefined4 *)(param_1 + 0xb80);
  *(undefined4 *)(DAT_005c98d4 + 0x1c) = *(undefined4 *)(param_1 + 0xb84);
  *(undefined4 *)(DAT_005c98d4 + 0x20) = *(undefined4 *)(param_1 + 0xb88);
  *(undefined4 *)(DAT_005c98d4 + 0x24) = *(undefined4 *)(param_1 + 0xb8c);
  *(undefined4 *)(DAT_005c98d4 + 0x28) = *(undefined4 *)(param_1 + 0xb90);
  *(undefined4 *)(DAT_005c98d4 + 0x2c) = *(undefined4 *)(param_1 + 0xb94);
  *(undefined4 *)(DAT_005c98d4 + 0x30) = *(undefined4 *)(param_1 + 0xb98);
  *(undefined4 *)(DAT_005c98d4 + 0x34) = *(undefined4 *)(param_1 + 0xb9c);
  FUN_004d6758(DAT_005c98d4);
  *(undefined4 *)(DAT_005c98d0 + 0x89c) = *(undefined4 *)(param_1 + 0xb60);
  *(undefined4 *)(DAT_005c98d0 + 0x8a0) = *(undefined4 *)(param_1 + 0xb64);
  *(undefined4 *)(DAT_005c98d0 + 0x8a4) = *(undefined4 *)(param_1 + 0xb68);
  *(undefined4 *)(DAT_005c98d0 + 0x8a8) = *(undefined4 *)(param_1 + 0xb6c);
  FUN_004d7fdc(DAT_005c98d0);
  for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
  }
  DAT_005b8554 = 0;
  for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
  }
  DAT_005b8558 = 0;
  for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
  }
  DAT_005b855c = 0;
  for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
    for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
        local_20 = local_20 + 1) {
      (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  return;
}



// Entry 0042bd20, recovered name Published_FormClose_0042bd20

int Published_FormClose_0042bd20(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int *piVar1;
  int *in_FS_OFFSET;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_40;
  
  FUN_00596a18(0x5bcc74);
  if (*(char *)(param_1 + 0xa60) == '\x01') {
    *in_FS_OFFSET = iStack_40;
  }
  else {
    if (((1 < DAT_005b8554) || (1 < DAT_005b855c)) && (0 < *(int *)(param_1 + 0xae4))) {
      *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) = 0;
      *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fd) = 0;
      *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fe) = 0;
      *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2ff) = 1;
      (**(code **)(**(int **)PTR__SaveFileForm_005c9474 + 0xd8))();
      if (*(char *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) != '\0') {
        *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2ff) = 0;
        *param_3 = 0;
        *(undefined1 *)(param_1 + 0xa60) = 0;
        *in_FS_OFFSET = iStack_40;
        return iStack_40;
      }
    }
    for (iStack_50 = 0; iStack_50 < DAT_005b8554; iStack_50 = iStack_50 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + iStack_50 * 4));
    }
    DAT_005b8554 = 0;
    for (iStack_54 = 0; iStack_54 < DAT_005b8558; iStack_54 = iStack_54 + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + iStack_54 * 4));
    }
    DAT_005b8558 = 0;
    for (iStack_58 = 0; iStack_58 < DAT_005b855c; iStack_58 = iStack_58 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + iStack_58 * 4));
    }
    DAT_005b855c = 0;
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    FUN_004d826c(DAT_005c98d0,DAT_005c98d4);
    if (DAT_005c98d0 != (int *)0x0) {
      (**(code **)(*DAT_005c98d0 + -4))(DAT_005c98d0,3);
    }
    DAT_005c98d0 = (int *)0x0;
    *(undefined1 *)(param_1 + 0xa60) = 1;
    piVar1 = *(int **)(param_1 + 0xa68);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + -4))(piVar1,3);
    }
    piVar1 = *(int **)(param_1 + 0xa6c);
    if (piVar1 != (int *)0x0) {
      param_1 = (**(code **)(*piVar1 + -4))(piVar1,3);
    }
    *in_FS_OFFSET = iStack_40;
    iStack_40 = param_1;
  }
  return iStack_40;
}



// Entry 0042bfb0, recovered name Published_N27Click_0042bfb0

void Published_N27Click_0042bfb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(*(int *)(param_1 + 0x338) + 0x2c) == '\0') {
    FUN_005420d0(*(undefined4 *)(param_1 + 0x338),
                 CONCAT31((int3)((uint)*(int *)(param_1 + 0x338) >> 8),1),param_3,param_2);
    FUN_00569200(*(undefined4 *)(param_1 + 0x43c),1);
  }
  else {
    FUN_005420d0(*(undefined4 *)(param_1 + 0x338),0,param_1,param_2);
    FUN_00569200(*(undefined4 *)(param_1 + 0x43c),0);
  }
  return;
}



// Entry 0042c014, recovered name Published_N65Click_0042c014

void Published_N65Click_0042c014(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(*(int *)(param_1 + 0x36c) + 0x38) != '\0') {
    FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0,param_3,param_2);
    *(undefined4 *)(DAT_005c98d0 + 0x86c) = DAT_00618aa4;
    *(undefined4 *)(DAT_005c98d0 + 0x870) = DAT_00618aa8;
    *(undefined4 *)(DAT_005c98d0 + 0x874) = DAT_00618aac;
  }
  return;
}



// Entry 0042c078, recovered name Published_N61Click_0042c078

void Published_N61Click_0042c078(undefined4 param_1,undefined4 param_2)

{
  Published_N15Click_0042b4a0(param_1,param_2);
  return;
}



// Entry 0042c094, recovered name Published_N57Click_0042c094

void Published_N57Click_0042c094(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton17Click_0042e174(param_1,param_2);
  return;
}



// Entry 0042c0b0, recovered name Published_N64Click_0042c0b0

void Published_N64Click_0042c0b0(undefined4 param_1,undefined4 param_2)

{
  Published_N62Click_0042b410(param_1,param_2);
  return;
}



// Entry 0042c0cc, recovered name Published_N43Click_0042c0cc

void Published_N43Click_0042c0cc(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton10Click_0042e0a4(param_1,param_2);
  return;
}



// Entry 0042c0e8, recovered name Published_N44Click_0042c0e8

void Published_N44Click_0042c0e8(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton15Click_0042dfd0(param_1,param_2);
  return;
}



// Entry 0042c104, recovered name Published_Y1Click_0042c104

void Published_Y1Click_0042c104(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton18Click_0042e8ac(param_1,param_2);
  return;
}



// Entry 0042c120, recovered name Published_X1Click_0042c120

void Published_X1Click_0042c120(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton16Click_0042e93c(param_1,param_2);
  return;
}



// Entry 0042c13c, recovered name Published_Z2Click_0042c13c

void Published_Z2Click_0042c13c(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton19Click_0042e9cc(param_1,param_2);
  return;
}



// Entry 0042c158, recovered name Published_N51Click_0042c158

void Published_N51Click_0042c158(undefined4 param_1,undefined4 param_2)

{
  Published_N37Click_0041f8f4(param_1,param_2);
  return;
}



// Entry 0042c174, recovered name Published_N48Click_0042c174

void Published_N48Click_0042c174(undefined4 param_1,undefined4 param_2)

{
  Published_N34Click_00428d34(param_1,param_2);
  return;
}



// Entry 0042c190, recovered name Published_N58Click_0042c190

void Published_N58Click_0042c190(undefined4 param_1,undefined4 param_2)

{
  Published_N39Click_00428fe4(param_1,param_2);
  return;
}



// Entry 0042c1ac, recovered name Published_N54Click_0042c1ac

void Published_N54Click_0042c1ac(int param_1,undefined4 param_2)

{
  if (*(char *)(*(int *)(param_1 + 0x454) + 0x130) == '\0') {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x454),
                 CONCAT31((int3)((uint)*(int *)(param_1 + 0x454) >> 8),1));
  }
  else {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0);
  }
  Published_SpeedButton1Click_0041a07c(param_1,param_2);
  return;
}



// Entry 0042c1fc, recovered name Published_CC3Click_0042c1fc

void Published_CC3Click_0042c1fc(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton3Click_0042d788(param_1,param_2);
  return;
}



// Entry 0042c218, recovered name Published_CC4Click_0042c218

void Published_CC4Click_0042c218(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton4Click_0042d9f8(param_1,param_2);
  return;
}



// Entry 0042c234, recovered name Published_CC5Click_0042c234

void Published_CC5Click_0042c234(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton5Click_0042dce4(param_1,param_2);
  return;
}



// Entry 0042c250, recovered name Published_N55Click_0042c250

void Published_N55Click_0042c250(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton20Click_0042e5dc(param_1,param_2);
  return;
}



// Entry 0042c26c, recovered name Published_N16Click_0042c26c

void Published_N16Click_0042c26c(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton15Click_0042dfd0(param_1,param_2);
  return;
}



// Entry 0042c288, recovered name Published_N17Click_0042c288

void Published_N17Click_0042c288(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton10Click_0042e0a4(param_1,param_2);
  return;
}



// Entry 0042c2a4, recovered name Published_N18Click_0042c2a4

void Published_N18Click_0042c2a4(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton18Click_0042e8ac(param_1,param_2);
  return;
}



// Entry 0042c2c0, recovered name Published_N19Click_0042c2c0

void Published_N19Click_0042c2c0(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton16Click_0042e93c(param_1,param_2);
  return;
}



// Entry 0042c2dc, recovered name Published_N13Click_0042c2dc

void Published_N13Click_0042c2dc(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton6Click_0042d504(param_1,param_2);
  return;
}



// Entry 0042c2f8, recovered name Published_CH41Click_0042c2f8

void Published_CH41Click_0042c2f8(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton2Click_0042d490(param_1,param_2);
  return;
}



// Entry 0042c314, recovered name Published_N33Click_0042c314

void Published_N33Click_0042c314(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton20Click_0042e5dc(param_1,param_2);
  return;
}



// Entry 0042c330, recovered name Published_N41Click_0042c330

void Published_N41Click_0042c330(void)

{
  (**(code **)(**(int **)PTR__About_005c947c + 0xd8))();
  return;
}



// Entry 0042d490, recovered name Published_SpeedButton2Click_0042d490

void Published_SpeedButton2Click_0042d490(int param_1)

{
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0);
  DAT_005b856d = 0;
  DAT_005b8573 = 0;
  DAT_005b856e = 0;
  DAT_005b856c = 1;
  for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
    *(undefined1 *)(*(int *)(&DAT_0060cf24 + local_10 * 4) + 0x339) = 0;
  }
  return;
}



// Entry 0042d504, recovered name Published_SpeedButton6Click_0042d504

void Published_SpeedButton6Click_0042d504(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  if (((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) || (DAT_005b856d != '\x01')) {
    DAT_005b856c = 0;
    FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0);
    DAT_005b856d = '\0';
    DAT_005b8573 = 1;
    DAT_005b856e = 0;
  }
  else {
    DAT_005b8540 = 8;
    for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
    }
    DAT_005b8554 = 0;
    for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
    }
    DAT_005b8558 = 0;
    for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
    }
    DAT_005b855c = 0;
    for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
          local_20 = local_20 + 1) {
        (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    DAT_005b8554 = 0;
    FUN_00417668(param_1);
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
    DAT_005b8548 = -1;
    DAT_005b8544 = -1;
    FUN_00589f34(*(undefined4 *)(param_1 + 0x424),0);
  }
  return;
}



// Entry 0042d788, recovered name Published_SpeedButton3Click_0042d788

void Published_SpeedButton3Click_0042d788(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 1;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x418),0);
  }
  else {
    if (DAT_005b856d == '\x01') {
      for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
      }
      DAT_005b8554 = 0;
      for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
      }
      DAT_005b8558 = 0;
      for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
      }
      DAT_005b855c = 0;
      for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
            local_20 = local_20 + 1) {
          (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      FUN_00417668(param_1);
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      DAT_005b8548 = -1;
      DAT_005b8544 = -1;
    }
    FUN_00589f34(*(undefined4 *)(param_1 + 0x418),0);
  }
  return;
}



// Entry 0042d9f8, recovered name Published_SpeedButton4Click_0042d9f8

void Published_SpeedButton4Click_0042d9f8(int param_1)

{
  HWND hWnd;
  LPCSTR lpText;
  LPCSTR lpCaption;
  UINT uType;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_10 = 0;
  while( true ) {
    if (DAT_005b8554 <= local_10) {
      FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
      DAT_005b8540 = 2;
      DAT_005b856c = 0;
      DAT_005b8573 = 0;
      if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
        FUN_00589f34(*(undefined4 *)(param_1 + 0x41c),0);
      }
      else {
        if (DAT_005b856d == '\x01') {
          for (local_14 = 0; local_14 < DAT_005b8554; local_14 = local_14 + 1) {
            FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_14 * 4));
          }
          DAT_005b8554 = 0;
          for (local_18 = 0; local_18 < DAT_005b8558; local_18 = local_18 + 1) {
            FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_18 * 4));
          }
          DAT_005b8558 = 0;
          for (local_1c = 0; local_1c < DAT_005b855c; local_1c = local_1c + 1) {
            FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_1c * 4));
          }
          DAT_005b855c = 0;
          for (local_20 = 0; local_20 < DAT_005b8550; local_20 = local_20 + 1) {
            for (local_24 = 0; local_24 < *(int *)(&DAT_005c98dc + local_20 * 0x6bd4);
                local_24 = local_24 + 1) {
              (&DAT_005c9900)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c993d)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c9979)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c99b5)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c99f1)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c9901)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c993e)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c997a)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c99b6)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c99f2)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
            }
          }
          FUN_004d82f4(DAT_005c98d0);
          FUN_004d7e00(DAT_005c98d0);
          DAT_005b8554 = 0;
          FUN_00417668(param_1);
          FUN_00406b0c(param_1);
          FUN_0042c350(param_1);
          DAT_005b8548 = -1;
          DAT_005b8544 = -1;
        }
        FUN_00589f34(*(undefined4 *)(param_1 + 0x41c),0);
      }
      return;
    }
    if (((*(char *)(*(int *)(&DAT_0060cf24 + local_10 * 4) + 0x339) != '\0') &&
        (*(char *)(*(int *)(&DAT_0060cf24 + local_10 * 4) + 0x9dc) == '\x03')) &&
       (*(char *)(*(int *)(&DAT_0060cf24 + local_10 * 4) + 0x300) == 'X')) break;
    local_10 = local_10 + 1;
  }
  uType = 0;
  lpCaption = (LPCSTR)0x0;
  lpText = &DAT_005b8d2e;
  hWnd = (HWND)FUN_0056f494(param_1);
  MessageBoxA(hWnd,lpText,lpCaption,uType);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x41c),0);
  return;
}



// Entry 0042dce4, recovered name Published_SpeedButton5Click_0042dce4

void Published_SpeedButton5Click_0042dce4(int param_1)

{
  HWND hWnd;
  LPCSTR lpText;
  LPCSTR lpCaption;
  UINT uType;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_10 = 0;
  while( true ) {
    if (DAT_005b8554 <= local_10) {
      FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
      DAT_005b8540 = 3;
      DAT_005b856c = 0;
      DAT_005b8573 = 0;
      if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
        FUN_00589f34(*(undefined4 *)(param_1 + 0x420),0);
      }
      else {
        if (DAT_005b856d == '\x01') {
          for (local_14 = 0; local_14 < DAT_005b8554; local_14 = local_14 + 1) {
            FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_14 * 4));
          }
          DAT_005b8554 = 0;
          for (local_18 = 0; local_18 < DAT_005b8558; local_18 = local_18 + 1) {
            FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_18 * 4));
          }
          DAT_005b8558 = 0;
          for (local_1c = 0; local_1c < DAT_005b855c; local_1c = local_1c + 1) {
            FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_1c * 4));
          }
          DAT_005b855c = 0;
          for (local_20 = 0; local_20 < DAT_005b8550; local_20 = local_20 + 1) {
            for (local_24 = 0; local_24 < *(int *)(&DAT_005c98dc + local_20 * 0x6bd4);
                local_24 = local_24 + 1) {
              (&DAT_005c9900)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c993d)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c9979)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c99b5)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c99f1)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c9901)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c993e)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c997a)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c99b6)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
              (&DAT_005c99f2)[local_24 * 0x114 + local_20 * 0x6bd4] = 0;
            }
          }
          FUN_004d82f4(DAT_005c98d0);
          FUN_004d7e00(DAT_005c98d0);
          DAT_005b8554 = 0;
          FUN_00417668(param_1);
          FUN_00406b0c(param_1);
          FUN_0042c350(param_1);
          DAT_005b8548 = -1;
          DAT_005b8544 = -1;
        }
        FUN_00589f34(*(undefined4 *)(param_1 + 0x420),0);
      }
      return;
    }
    if (((*(char *)(*(int *)(&DAT_0060cf24 + local_10 * 4) + 0x339) != '\0') &&
        (*(char *)(*(int *)(&DAT_0060cf24 + local_10 * 4) + 0x9dc) == '\x03')) &&
       (*(char *)(*(int *)(&DAT_0060cf24 + local_10 * 4) + 0x300) == 'X')) break;
    local_10 = local_10 + 1;
  }
  uType = 0;
  lpCaption = (LPCSTR)0x0;
  lpText = &DAT_005b8d41;
  hWnd = (HWND)FUN_0056f494(param_1);
  MessageBoxA(hWnd,lpText,lpCaption,uType);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x420),0);
  return;
}



// Entry 0042dfd0, recovered name Published_SpeedButton15Click_0042dfd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_SpeedButton15Click_0042dfd0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if (*(float *)(DAT_005c98d0 + 0x8bc) <= (float)_DAT_0042e094) {
    iVar1 = **(int **)(param_1 + 0x468);
    (**(code **)(iVar1 + 0x5c))(*(int **)(param_1 + 0x468),0,iVar1,param_2);
  }
  else {
    *(float *)(DAT_005c98d0 + 0x8bc) = *(float *)(DAT_005c98d0 + 0x8bc) - (float)_DAT_0042e09c;
    iVar1 = DAT_005c98d0;
    *(float *)(DAT_005c98d0 + 0x8c0) = *(float *)(DAT_005c98d0 + 0x8c0) - (float)_DAT_0042e09c;
    *(float *)(DAT_005c98d0 + 0x8c4) = *(float *)(DAT_005c98d0 + 0x8c4) - (float)_DAT_0042e09c;
    (**(code **)(**(int **)(param_1 + 0x464) + 0x5c))
              (*(int **)(param_1 + 0x464),CONCAT31((int3)((uint)iVar1 >> 8),1));
    FUN_004d7fc8(DAT_005c98d0);
  }
  return;
}



// Entry 0042e0a4, recovered name Published_SpeedButton10Click_0042e0a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_SpeedButton10Click_0042e0a4(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if (_DAT_0042e168 <= *(float *)(DAT_005c98d0 + 0x8bc)) {
    iVar1 = **(int **)(param_1 + 0x464);
    (**(code **)(iVar1 + 0x5c))(*(int **)(param_1 + 0x464),0,iVar1,param_2);
  }
  else {
    *(float *)(DAT_005c98d0 + 0x8bc) = *(float *)(DAT_005c98d0 + 0x8bc) + (float)_DAT_0042e16c;
    iVar1 = DAT_005c98d0;
    *(float *)(DAT_005c98d0 + 0x8c0) = *(float *)(DAT_005c98d0 + 0x8c0) + (float)_DAT_0042e16c;
    *(float *)(DAT_005c98d0 + 0x8c4) = *(float *)(DAT_005c98d0 + 0x8c4) + (float)_DAT_0042e16c;
    (**(code **)(**(int **)(param_1 + 0x468) + 0x5c))
              (*(int **)(param_1 + 0x468),CONCAT31((int3)((uint)iVar1 >> 8),1));
    FUN_004d7fc8(DAT_005c98d0);
  }
  return;
}



// Entry 0042e174, recovered name Published_SpeedButton17Click_0042e174

void Published_SpeedButton17Click_0042e174(int param_1,undefined4 param_2)

{
  char cVar1;
  HWND hWnd;
  int iVar2;
  int iVar3;
  HDC hdc;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *in_FS_OFFSET;
  byte bVar8;
  int x;
  int y;
  HDC hdcSrc;
  int x1;
  int y1;
  undefined *rop;
  char local_498 [1000];
  undefined4 local_b0 [4];
  undefined4 local_a0 [4];
  undefined4 local_90 [4];
  undefined4 local_80 [4];
  int *local_70;
  int local_6c;
  int *local_68;
  int *local_64;
  HDC local_60;
  undefined4 local_5c;
  int local_58;
  undefined4 local_54;
  undefined2 local_44;
  int local_38;
  int *local_30;
  int local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  
  bVar8 = 0;
  local_5c = param_2;
  local_58 = param_1;
  FUN_00596a18(&DAT_005bcd48);
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  FUN_0055e53c(*(undefined4 *)(local_58 + 0x36c),0);
  hWnd = (HWND)FUN_0056f494(local_58);
  local_60 = GetWindowDC(hWnd);
  local_64 = (int *)FUN_0054bd6c(PTR_PTR_00545a1c,1);
  local_68 = (int *)FUN_0054bd6c(PTR_PTR_00545a1c,1);
  (**(code **)(*local_64 + 0x40))(local_64,*(undefined4 *)(_Form1 + 0x38));
  (**(code **)(*local_64 + 0x34))(local_64,*(undefined4 *)(_Form1 + 0x3c));
  rop = &DAT_00cc0020;
  y1 = 0;
  x1 = 0;
  hdcSrc = local_60;
  iVar2 = (**(code **)(*local_64 + 0x20))();
  iVar3 = (**(code **)(*local_64 + 0x2c))();
  y = 0;
  x = 0;
  FUN_0054c2d8(local_64);
  hdc = (HDC)FUN_00547b70();
  BitBlt(hdc,x,y,iVar3,iVar2,hdcSrc,x1,y1,(DWORD)rop);
  iVar2 = (**(code **)(*local_64 + 0x2c))();
  (**(code **)(*local_68 + 0x40))
            (local_68,(iVar2 + -0x14) - *(int *)(*(int *)(local_58 + 0x410) + 0x38));
  iVar2 = (**(code **)(*local_64 + 0x20))();
  (**(code **)(*local_68 + 0x34))
            (local_68,(iVar2 - *(int *)(*(int *)(local_58 + 0x43c) + 0x3c)) + -0x30);
  FUN_0042e598();
  puVar6 = local_90;
  FUN_0042e598();
  iVar2 = (**(code **)(*local_64 + 0x20))(local_64,*local_64,puVar6);
  iVar2 = iVar2 + -5;
  puVar6 = local_a0;
  iVar3 = (**(code **)(*local_64 + 0x2c))();
  FUN_005815d4(*(int *)(*(int *)(local_58 + 0x410) + 0x38) + 10,
               *(int *)(*(int *)(local_58 + 0x43c) + 0x3c) + 0x2b,iVar3 + -10,puVar6,iVar2);
  puVar6 = local_a0;
  puVar7 = local_80;
  for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + (uint)bVar8 * -2 + 1;
    puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
  }
  uVar4 = (**(code **)(*local_68 + 0x20))();
  puVar6 = local_b0;
  uVar5 = (**(code **)(*local_68 + 0x2c))();
  FUN_005815d4(0,0,uVar5,puVar6,uVar4);
  puVar6 = local_b0;
  puVar7 = local_90;
  for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + (uint)bVar8 * -2 + 1;
    puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
  }
  puVar6 = local_80;
  uVar4 = FUN_0054c2d8(local_64);
  uVar5 = FUN_0054c2d8(local_68);
  FUN_005475d8(uVar5,local_90,uVar4,puVar6);
  local_44 = 8;
  uVar4 = FUN_0040328c(&local_8);
  local_38 = local_38 + 1;
  FUN_0055a58c(*(undefined4 *)PTR_DAT_005c9494,uVar4);
  uVar4 = FUN_0040328c(&local_c);
  local_38 = local_38 + 1;
  FUN_0058d590(local_8,uVar4);
  FUN_00562c84(*(undefined4 *)(local_58 + 0x2d4),local_c);
  local_38 = local_38 + -1;
  FUN_005a28c0(&local_c,2);
  local_38 = local_38 + -1;
  FUN_005a28c0(&local_8,2);
  cVar1 = (**(code **)(**(int **)(local_58 + 0x2d4) + 0x3c))();
  if (cVar1 != '\0') {
    local_44 = 0x14;
    uVar4 = FUN_0040328c(local_10);
    local_38 = local_38 + 1;
    FUN_00562c1c(*(undefined4 *)(local_58 + 0x2d4),uVar4);
    FUN_00423b60(local_10);
    FUN_00596774();
    local_38 = local_38 + -1;
    FUN_005a28c0(local_10,2);
    local_6c = 0;
    do {
      if (local_498[local_6c] == '\0') break;
      local_6c = local_6c + 1;
    } while (local_6c < 1000);
    if ((local_498[local_6c + -1] == 'p') || (local_498[local_6c + -1] == 0x50)) {
      local_44 = 0x20;
      uVar4 = FUN_0040328c(&local_14);
      local_38 = local_38 + 1;
      FUN_00562c1c(*(undefined4 *)(local_58 + 0x2d4),uVar4);
      (**(code **)(*local_68 + 0x4c))(local_68,local_14);
      local_38 = local_38 + -1;
      FUN_005a28c0(&local_14,2);
    }
    else {
      iVar2 = (int)local_498[local_6c + -1];
      if (local_498[local_6c + -1] != 'g') {
        iVar2 = local_6c;
        if (local_498[local_6c + -1] != 'G') goto LAB_0042e52e;
      }
      local_70 = (int *)FUN_005b38ac(PTR_PTR_005b3620,CONCAT31((int3)((uint)iVar2 >> 8),1));
      (**(code **)(*local_70 + 8))(local_70,local_68);
      local_44 = 0x2c;
      uVar4 = FUN_0040328c(&local_18);
      local_38 = local_38 + 1;
      FUN_00562c1c(*(undefined4 *)(local_58 + 0x2d4),uVar4);
      (**(code **)(*local_70 + 0x4c))(local_70,local_18);
      local_38 = local_38 + -1;
      FUN_005a28c0(&local_18,2);
      local_20 = local_70;
      if (local_70 != (int *)0x0) {
        local_1c = *local_70;
        local_44 = 0x44;
        (**(code **)(*local_70 + -4))(local_70,3);
      }
      local_70 = (int *)0x0;
    }
  }
LAB_0042e52e:
  local_28 = local_64;
  if (local_64 != (int *)0x0) {
    local_24 = *local_64;
    local_44 = 0x5c;
    (**(code **)(*local_64 + -4))(local_64,3);
  }
  local_30 = local_68;
  if (local_68 != (int *)0x0) {
    local_2c = *local_68;
    local_44 = 0x74;
    (**(code **)(*local_68 + -4))(local_68,3);
  }
  *in_FS_OFFSET = local_54;
  return;
}



// Entry 0042e5dc, recovered name Published_SpeedButton20Click_0042e5dc

void Published_SpeedButton20Click_0042e5dc(int param_1)

{
  char cVar1;
  HWND pHVar2;
  LPCSTR pCVar3;
  LPCSTR pCVar4;
  UINT UVar5;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  if (DAT_005b854c == '\0') {
    UVar5 = 0;
    pCVar4 = (LPCSTR)0x0;
    pCVar3 = &DAT_005b8d54;
    pHVar2 = (HWND)FUN_0056f494(param_1);
    MessageBoxA(pHVar2,pCVar3,pCVar4,UVar5);
  }
  else if (((DAT_005b8548 != -1) && (DAT_005b8544 != -1)) && (DAT_005b856d == '\x01')) {
    for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
    }
    DAT_005b8554 = 0;
    for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
    }
    DAT_005b8558 = 0;
    for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
    }
    DAT_005b855c = 0;
    for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
          local_20 = local_20 + 1) {
        (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    DAT_005b8554 = 0;
    if (DAT_005b854c != '\0') {
      cVar1 = FUN_004f4d38();
      if (cVar1 == '\0') {
        UVar5 = 0;
        pCVar4 = (LPCSTR)0x0;
        pCVar3 = &DAT_005b8d63;
        pHVar2 = (HWND)FUN_0056f494(param_1);
        MessageBoxA(pHVar2,pCVar3,pCVar4,UVar5);
      }
      else {
        *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
      }
    }
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
    DAT_005b8548 = -1;
    DAT_005b8544 = -1;
  }
  return;
}



// Entry 0042e8ac, recovered name Published_SpeedButton18Click_0042e8ac

void Published_SpeedButton18Click_0042e8ac(int param_1,undefined4 param_2)

{
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  DAT_00618aa4 = *(undefined4 *)(DAT_005c98d0 + 0x86c);
  DAT_00618aa8 = *(undefined4 *)(DAT_005c98d0 + 0x870);
  DAT_00618aac = *(undefined4 *)(DAT_005c98d0 + 0x874);
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),CONCAT31((int3)((uint)DAT_005c98d0 >> 8),1),
               DAT_00618aac,param_2);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0);
  DAT_005b856d = 0;
  DAT_005b8570 = 1;
  DAT_005b8571 = 0;
  DAT_005b8572 = 0;
  return;
}



// Entry 0042e93c, recovered name Published_SpeedButton16Click_0042e93c

void Published_SpeedButton16Click_0042e93c(int param_1,undefined4 param_2)

{
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  DAT_00618aa4 = *(undefined4 *)(DAT_005c98d0 + 0x86c);
  DAT_00618aa8 = *(undefined4 *)(DAT_005c98d0 + 0x870);
  DAT_00618aac = *(undefined4 *)(DAT_005c98d0 + 0x874);
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),CONCAT31((int3)((uint)DAT_005c98d0 >> 8),1),
               DAT_00618aac,param_2);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0);
  DAT_005b856d = 0;
  DAT_005b8571 = 1;
  DAT_005b8570 = 0;
  DAT_005b8572 = 0;
  return;
}



// Entry 0042e9cc, recovered name Published_SpeedButton19Click_0042e9cc

void Published_SpeedButton19Click_0042e9cc(int param_1,undefined4 param_2)

{
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  DAT_00618aa4 = *(undefined4 *)(DAT_005c98d0 + 0x86c);
  DAT_00618aa8 = *(undefined4 *)(DAT_005c98d0 + 0x870);
  DAT_00618aac = *(undefined4 *)(DAT_005c98d0 + 0x874);
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),CONCAT31((int3)((uint)DAT_005c98d0 >> 8),1),
               DAT_00618aac,param_2);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x454),0);
  DAT_005b856d = 0;
  DAT_005b8572 = 1;
  DAT_005b8571 = 0;
  DAT_005b8570 = 0;
  return;
}



// Entry 0042ea5c, recovered name Published_N28Click_0042ea5c

void Published_N28Click_0042ea5c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(*(int *)(param_1 + 0x33c) + 0x2c) == '\0') {
    FUN_005420d0(*(undefined4 *)(param_1 + 0x33c),
                 CONCAT31((int3)((uint)*(int *)(param_1 + 0x33c) >> 8),1),param_3,param_2);
    FUN_00569200(*(undefined4 *)(param_1 + 0x410),1);
    (**(code **)(**(int **)(param_1 + 0x414) + 0x5c))(*(int **)(param_1 + 0x414),1);
    (**(code **)(**(int **)(param_1 + 0x418) + 0x5c))(*(int **)(param_1 + 0x418),1);
    (**(code **)(**(int **)(param_1 + 0x41c) + 0x5c))(*(int **)(param_1 + 0x41c),1);
    (**(code **)(**(int **)(param_1 + 0x420) + 0x5c))(*(int **)(param_1 + 0x420),1);
    (**(code **)(**(int **)(param_1 + 0x424) + 0x5c))(*(int **)(param_1 + 0x424),1);
    (**(code **)(**(int **)(param_1 + 0x428) + 0x5c))(*(int **)(param_1 + 0x428),1);
    (**(code **)(**(int **)(param_1 + 0x42c) + 0x5c))(*(int **)(param_1 + 0x42c),1);
    (**(code **)(**(int **)(param_1 + 0x49c) + 0x5c))(*(int **)(param_1 + 0x49c),1);
    (**(code **)(**(int **)(param_1 + 0x4a0) + 0x5c))(*(int **)(param_1 + 0x4a0),1);
    (**(code **)(**(int **)(param_1 + 0x480) + 0x5c))(*(int **)(param_1 + 0x480),1);
    (**(code **)(**(int **)(param_1 + 0x4dc) + 0x5c))(*(int **)(param_1 + 0x4dc),1);
    (**(code **)(**(int **)(param_1 + 0x4e0) + 0x5c))(*(int **)(param_1 + 0x4e0),1);
    (**(code **)(**(int **)(param_1 + 0x504) + 0x5c))(*(int **)(param_1 + 0x504),1);
  }
  else {
    FUN_005420d0(*(undefined4 *)(param_1 + 0x33c),0,param_3,param_2);
    FUN_00569200(*(undefined4 *)(param_1 + 0x410),0);
  }
  return;
}



// Entry 0042eb94, recovered name Published_N7Click_0042eb94

void Published_N7Click_0042eb94(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x490) + 0x3c))();
  return;
}



// Entry 0042ebb4, recovered name Published_SpeedButton9Click_0042ebb4

void Published_SpeedButton9Click_0042ebb4(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  HDC pHVar4;
  HWND hWnd;
  int iVar5;
  HDC pHVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *in_FS_OFFSET;
  byte bVar11;
  int xDest;
  int yDest;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined *puVar16;
  undefined4 local_90 [4];
  undefined4 local_80 [4];
  undefined4 local_70 [4];
  undefined4 local_60 [4];
  int *local_50;
  int *local_4c;
  HDC local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined2 local_2c;
  int local_20;
  int *local_18;
  int local_14;
  int *local_10;
  int local_c;
  undefined1 local_8 [4];
  
  bVar11 = 0;
  local_44 = param_2;
  local_40 = param_1;
  FUN_00596a18(&DAT_005bcdf8);
  cVar1 = (**(code **)(**(int **)(local_40 + 0x494) + 0x3c))();
  if (cVar1 != '\0') {
    FUN_0053eb14();
    FUN_0053e1ac();
    local_2c = 8;
    uVar2 = FUN_005a2750(local_8,&DAT_005b8d72);
    local_20 = local_20 + 1;
    iVar3 = FUN_0053eb14();
    FUN_005a28f0(iVar3 + 0x18,uVar2);
    local_20 = local_20 + -1;
    FUN_005a28c0(local_8,2);
    iVar3 = 3;
    FUN_0053eb14();
    FUN_0053e558();
    pHVar4 = (HDC)FUN_00547b70();
    SetStretchBltMode(pHVar4,iVar3);
    DAT_005b856c = 0;
    DAT_005b8573 = 0;
    FUN_0055e53c(*(undefined4 *)(local_40 + 0x36c),0);
    hWnd = (HWND)FUN_0056f494(local_40);
    local_48 = GetWindowDC(hWnd);
    local_4c = (int *)FUN_0054bd6c(PTR_PTR_00545a1c,1);
    local_50 = (int *)FUN_0054bd6c(PTR_PTR_00545a1c,1);
    (**(code **)(*local_4c + 0x40))(local_4c,*(undefined4 *)(_Form1 + 0x38));
    (**(code **)(*local_4c + 0x34))(local_4c,*(undefined4 *)(_Form1 + 0x3c));
    puVar16 = &DAT_00cc0020;
    iVar15 = 0;
    iVar14 = 0;
    pHVar4 = local_48;
    iVar3 = (**(code **)(*local_4c + 0x20))();
    iVar5 = (**(code **)(*local_4c + 0x2c))();
    iVar13 = 0;
    iVar12 = 0;
    FUN_0054c2d8(local_4c);
    pHVar6 = (HDC)FUN_00547b70();
    BitBlt(pHVar6,iVar12,iVar13,iVar5,iVar3,pHVar4,iVar14,iVar15,(DWORD)puVar16);
    iVar3 = (**(code **)(*local_4c + 0x2c))();
    (**(code **)(*local_50 + 0x40))
              (local_50,(iVar3 + -0x14) - *(int *)(*(int *)(local_40 + 0x410) + 0x38));
    iVar3 = (**(code **)(*local_4c + 0x20))();
    (**(code **)(*local_50 + 0x34))
              (local_50,(iVar3 - *(int *)(*(int *)(local_40 + 0x43c) + 0x3c)) + -0x30);
    FUN_0042e598();
    puVar9 = local_70;
    FUN_0042e598();
    iVar3 = (**(code **)(*local_4c + 0x20))(local_4c,*local_4c,puVar9);
    iVar3 = iVar3 + -5;
    puVar9 = local_80;
    iVar5 = (**(code **)(*local_4c + 0x2c))();
    FUN_005815d4(*(int *)(*(int *)(local_40 + 0x410) + 0x38) + 10,
                 *(int *)(*(int *)(local_40 + 0x43c) + 0x3c) + 0x2b,iVar5 + -10,puVar9,iVar3);
    puVar9 = local_80;
    puVar10 = local_60;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + (uint)bVar11 * -2 + 1;
      puVar10 = puVar10 + (uint)bVar11 * -2 + 1;
    }
    uVar2 = (**(code **)(*local_50 + 0x20))();
    puVar9 = local_90;
    uVar7 = (**(code **)(*local_50 + 0x2c))();
    FUN_005815d4(0,0,uVar7,puVar9,uVar2);
    puVar9 = local_90;
    puVar10 = local_70;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + (uint)bVar11 * -2 + 1;
      puVar10 = puVar10 + (uint)bVar11 * -2 + 1;
    }
    puVar9 = local_60;
    uVar2 = FUN_0054c2d8(local_4c);
    uVar7 = FUN_0054c2d8(local_50);
    FUN_005475d8(uVar7,local_70,uVar2,puVar9);
    puVar16 = &DAT_00cc0020;
    iVar3 = (**(code **)(*local_50 + 0x20))();
    iVar5 = (**(code **)(*local_50 + 0x2c))();
    iVar14 = 0;
    iVar13 = 0;
    FUN_0054c2d8(local_50);
    pHVar4 = (HDC)FUN_00547b70();
    FUN_0053eb14();
    uVar8 = FUN_0053e668();
    iVar12 = (int)uVar8 >> 1;
    if (iVar12 < 0) {
      iVar12 = iVar12 + (uint)((uVar8 & 1) != 0);
    }
    FUN_0053eb14();
    iVar15 = FUN_0053e684();
    yDest = 10;
    xDest = 10;
    FUN_0053eb14();
    FUN_0053e558();
    pHVar6 = (HDC)FUN_00547b70();
    StretchBlt(pHVar6,xDest,yDest,iVar15,iVar12,pHVar4,iVar13,iVar14,iVar5,iVar3,(DWORD)puVar16);
    FUN_0053eb14();
    FUN_0053e234();
    local_10 = local_4c;
    if (local_4c != (int *)0x0) {
      local_c = *local_4c;
      local_2c = 0x20;
      (**(code **)(*local_4c + -4))(local_4c,3);
    }
    local_18 = local_50;
    if (local_50 != (int *)0x0) {
      local_14 = *local_50;
      local_2c = 0x38;
      (**(code **)(*local_50 + -4))(local_50,3);
    }
  }
  *in_FS_OFFSET = local_3c;
  return;
}



// Entry 0042eea4, recovered name Published_N8Click_0042eea4

void Published_N8Click_0042eea4(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton9Click_0042ebb4(param_1,param_2);
  return;
}



// Entry 0042eec0, recovered name Published_ComboBox1Change_0042eec0

void Published_ComboBox1Change_0042eec0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0053b088(*(undefined4 *)(param_1 + 0x458));
  if (iVar1 == 0) {
    Published_N89Click_004cc1d8(param_1,param_2);
  }
  iVar1 = FUN_0053b088(*(undefined4 *)(param_1 + 0x458));
  if (iVar1 == 1) {
    Published_N106Click_004cc480(param_1,param_2);
  }
  iVar1 = FUN_0053b088(*(undefined4 *)(param_1 + 0x458));
  if (iVar1 == 2) {
    Published_N37Click_0041f8f4(param_1,param_2);
  }
  iVar1 = FUN_0053b088(*(undefined4 *)(param_1 + 0x458));
  if (iVar1 == 3) {
    Published_N34Click_00428d34(param_1,param_2);
  }
  iVar1 = FUN_0053b088(*(undefined4 *)(param_1 + 0x458));
  if (iVar1 == 4) {
    Published_N39Click_00428fe4(param_1,param_2);
  }
  iVar1 = FUN_0053b088(*(undefined4 *)(param_1 + 0x458));
  if (iVar1 == 5) {
    Published_N75Click_00432008(param_1,param_2);
  }
  FUN_00555574(param_1,*(undefined4 *)(param_1 + 0x498));
  return;
}



// Entry 0042ef94, recovered name Published_Edit1KeyDown_0042ef94

void Published_Edit1KeyDown_0042ef94
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  Published_FormKeyDown_00404a44(param_1,param_2,param_3,param_4);
  return;
}



// Entry 0042efbc, recovered name Published_SpeedButton7Click_0042efbc

void Published_SpeedButton7Click_0042efbc(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 4;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x428),0);
  }
  else {
    if (DAT_005b856d == '\x01') {
      for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
      }
      DAT_005b8554 = 0;
      for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
      }
      DAT_005b8558 = 0;
      for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
      }
      DAT_005b855c = 0;
      for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
            local_20 = local_20 + 1) {
          (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      FUN_00417668(param_1);
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      DAT_005b8548 = -1;
      DAT_005b8544 = -1;
    }
    FUN_00589f34(*(undefined4 *)(param_1 + 0x428),0);
  }
  return;
}



// Entry 0042f248, recovered name Published_SpeedButton8Click_0042f248

void Published_SpeedButton8Click_0042f248(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 5;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x42c),0);
  }
  else {
    if (DAT_005b856d == '\x01') {
      for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
      }
      DAT_005b8554 = 0;
      for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
      }
      DAT_005b8558 = 0;
      for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
      }
      DAT_005b855c = 0;
      for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
            local_20 = local_20 + 1) {
          (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      FUN_00417668(param_1);
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      DAT_005b8548 = -1;
      DAT_005b8544 = -1;
    }
    FUN_00589f34(*(undefined4 *)(param_1 + 0x42c),0);
  }
  return;
}



// Entry 0042f4d4, recovered name Published_SpeedButton21Click_0042f4d4

void Published_SpeedButton21Click_0042f4d4(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 6;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x49c),0);
  }
  else {
    if (DAT_005b856d == '\x01') {
      for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
      }
      DAT_005b8554 = 0;
      for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
      }
      DAT_005b8558 = 0;
      for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
      }
      DAT_005b855c = 0;
      for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
            local_20 = local_20 + 1) {
          (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      FUN_00417668(param_1);
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      DAT_005b8548 = -1;
      DAT_005b8544 = -1;
    }
    FUN_00589f34(*(undefined4 *)(param_1 + 0x49c),0);
  }
  return;
}



// Entry 0042f760, recovered name Published_SpeedButton22Click_0042f760

void Published_SpeedButton22Click_0042f760(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 7;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x4a0),0);
  }
  else {
    if (DAT_005b856d == '\x01') {
      for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
      }
      DAT_005b8554 = 0;
      for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
      }
      DAT_005b8558 = 0;
      for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
      }
      DAT_005b855c = 0;
      for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
            local_20 = local_20 + 1) {
          (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      FUN_00417668(param_1);
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      DAT_005b8548 = -1;
      DAT_005b8544 = -1;
    }
    FUN_00589f34(*(undefined4 *)(param_1 + 0x4a0),0);
  }
  return;
}



// Entry 0042f9ec, recovered name Published_N70Click_0042f9ec

void Published_N70Click_0042f9ec(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton7Click_0042efbc(param_1,param_2);
  return;
}



// Entry 0042fa08, recovered name Published_N71Click_0042fa08

void Published_N71Click_0042fa08(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton8Click_0042f248(param_1,param_2);
  return;
}



// Entry 0042fa24, recovered name Published_N72Click_0042fa24

void Published_N72Click_0042fa24(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton21Click_0042f4d4(param_1,param_2);
  return;
}



// Entry 0042fa40, recovered name Published_N73Click_0042fa40

void Published_N73Click_0042fa40(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton22Click_0042f760(param_1,param_2);
  return;
}



// Entry 0042fa5c, recovered name Published_N110Click_0042fa5c

void Published_N110Click_0042fa5c(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bce3c);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4b8),1);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4bc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c0),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c4),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4cc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4d0),0);
  *(undefined4 *)(param_1 + 0xbb0) = 0x3f800000;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,
               CONCAT22((short)((uint)PTR_DAT_005c9498 >> 0x10),0xfff5));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 0042fd50, recovered name Published_N210Click_0042fd50

void Published_N210Click_0042fd50(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bce50);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4b8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4bc),1);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c0),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c4),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4cc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4d0),0);
  *(undefined4 *)(param_1 + 0xbb0) = 0x40000000;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,
               CONCAT22((short)((uint)PTR_DAT_005c9498 >> 0x10),0xfff5));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00430044, recovered name Published_N310Click_00430044

void Published_N310Click_00430044(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bce64);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4b8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4bc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c0),1);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c4),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4cc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4d0),0);
  *(undefined4 *)(param_1 + 0xbb0) = 0x40400000;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,
               CONCAT22((short)((uint)PTR_DAT_005c9498 >> 0x10),0xfff5));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00430338, recovered name Published_N410Click_00430338

void Published_N410Click_00430338(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bce78);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4b8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4bc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c0),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c4),1);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4cc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4d0),0);
  *(undefined4 *)(param_1 + 0xbb0) = 0x40800000;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,
               CONCAT22((short)((uint)PTR_DAT_005c9498 >> 0x10),0xfff5));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 0043062c, recovered name Published_N510Click_0043062c

void Published_N510Click_0043062c(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bce8c);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4b8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4bc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c0),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c4),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c8),1);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4cc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4d0),0);
  *(undefined4 *)(param_1 + 0xbb0) = 0x40a00000;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,
               CONCAT22((short)((uint)PTR_DAT_005c9498 >> 0x10),0xfff5));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00430920, recovered name Published_N81Click_00430920

void Published_N81Click_00430920(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bcea0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4b8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4bc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c0),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c4),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4cc),1);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4d0),0);
  *(undefined4 *)(param_1 + 0xbb0) = 0x41000000;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,
               CONCAT22((short)((uint)PTR_DAT_005c9498 >> 0x10),0xfff5));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00430c14, recovered name Published_N101Click_00430c14

void Published_N101Click_00430c14(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bceb4);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4b8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4bc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c0),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c4),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4c8),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4cc),0);
  FUN_005420d0(*(undefined4 *)(param_1 + 0x4d0),1);
  *(undefined4 *)(param_1 + 0xbb0) = 0x41200000;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,
               CONCAT22((short)((uint)PTR_DAT_005c9498 >> 0x10),0xfff5));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00432008, recovered name Published_N75Click_00432008

void Published_N75Click_00432008(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bd198);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  DAT_005b8541 = 3;
  FUN_0053b0a4(*(undefined4 *)(param_1 + 0x458),5);
  FUN_00555574(param_1,*(undefined4 *)(param_1 + 0x498));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 004322a8, recovered name Published_N76Click_004322a8

void Published_N76Click_004322a8(undefined4 param_1,undefined4 param_2)

{
  Published_N75Click_00432008(param_1,param_2);
  return;
}



// Entry 004322c4, recovered name Published_N20Click_004322c4

int Published_N20Click_004322c4(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bd1ac);
  if (((1 < DAT_005b8554) || (1 < DAT_005b855c)) && (0 < *(int *)(param_1 + 0xae4))) {
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) = 0;
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fd) = 0;
    *(undefined1 *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fe) = 0;
    (**(code **)(**(int **)PTR__SaveFileForm_005c9474 + 0xd8))();
    if (*(char *)(*(int *)PTR__SaveFileForm_005c9474 + 0x2fc) != '\0') {
      *in_FS_OFFSET = local_28;
      return local_28;
    }
  }
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  DAT_005b8540 = 0;
  (**(code **)(**(int **)PTR__Form8_005c9484 + 0xd8))();
  iVar2 = *(int *)PTR__Form8_005c9484;
  if (*(char *)(iVar2 + 0x300) != '\0') {
    uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
    FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
    (**(code **)(**(int **)(param_1 + 0x414) + 0x5c))(*(int **)(param_1 + 0x414),0);
    (**(code **)(**(int **)(param_1 + 0x418) + 0x5c))(*(int **)(param_1 + 0x418),0);
    (**(code **)(**(int **)(param_1 + 0x41c) + 0x5c))(*(int **)(param_1 + 0x41c),0);
    (**(code **)(**(int **)(param_1 + 0x420) + 0x5c))(*(int **)(param_1 + 0x420),0);
    (**(code **)(**(int **)(param_1 + 0x424) + 0x5c))(*(int **)(param_1 + 0x424),0);
    (**(code **)(**(int **)(param_1 + 0x428) + 0x5c))(*(int **)(param_1 + 0x428),0);
    (**(code **)(**(int **)(param_1 + 0x42c) + 0x5c))(*(int **)(param_1 + 0x42c),0);
    (**(code **)(**(int **)(param_1 + 0x49c) + 0x5c))(*(int **)(param_1 + 0x49c),0);
    (**(code **)(**(int **)(param_1 + 0x4a0) + 0x5c))(*(int **)(param_1 + 0x4a0),0);
    (**(code **)(**(int **)(param_1 + 0x480) + 0x5c))(*(int **)(param_1 + 0x480),0);
    (**(code **)(**(int **)(param_1 + 0x4dc) + 0x5c))(*(int **)(param_1 + 0x4dc),0);
    (**(code **)(**(int **)(param_1 + 0x4e0) + 0x5c))(*(int **)(param_1 + 0x4e0),0);
    (**(code **)(**(int **)(param_1 + 0x504) + 0x5c))(*(int **)(param_1 + 0x504),0);
    FUN_005420d0(*(undefined4 *)(param_1 + 0x33c),0);
    FUN_00569200(*(undefined4 *)(param_1 + 0x410),0);
    FUN_00418eb4(param_1);
    FUN_00430f08(param_1,*(int *)PTR__Form8_005c9484 + 0x2ec,
                 *(undefined4 *)(*(int *)PTR__Form8_005c9484 + 0x2fc));
    for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
    }
    DAT_005b8554 = 0;
    for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
    }
    DAT_005b8558 = 0;
    for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
    }
    DAT_005b855c = 0;
    for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
      for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
          local_48 = local_48 + 1) {
        (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    DAT_005b8554 = 0;
    DAT_005b8558 = 0;
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
    iVar2 = FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
    if (local_16 != 0) {
      return iVar2;
    }
  }
  *in_FS_OFFSET = local_28;
  return iVar2;
}



// Entry 0043270c, recovered name Published_SpeedButton23Click_0043270c

void Published_SpeedButton23Click_0043270c(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 9;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x4dc),0);
  }
  else {
    if (DAT_005b856d == '\x01') {
      for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
      }
      DAT_005b8554 = 0;
      for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
      }
      DAT_005b8558 = 0;
      for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
      }
      DAT_005b855c = 0;
      for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
            local_20 = local_20 + 1) {
          (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      FUN_00417668(param_1);
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      DAT_005b8548 = -1;
      DAT_005b8544 = -1;
    }
    FUN_00589f34(*(undefined4 *)(param_1 + 0x4dc),0);
  }
  return;
}



// Entry 00432998, recovered name Published_SpeedButton24MouseDown_00432998

void Published_SpeedButton24MouseDown_00432998(int param_1)

{
  FUN_00568adc(*(undefined4 *)PTR__Form6_005c9488,
               *(int *)(_Form1 + 0x30) + *(int *)(*(int *)(param_1 + 0x410) + 0x38) + 3);
  FUN_00568afc(*(undefined4 *)PTR__Form6_005c9488,
               *(int *)(*(int *)(param_1 + 0x43c) + 0x3c) +
               *(int *)(*(int *)(param_1 + 0x4e0) + 0x34) + 0x27);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xffeb);
  FUN_00556f90(*(undefined4 *)PTR__Form6_005c9488);
  FUN_00589f34(*(undefined4 *)(param_1 + 0x4e0),0);
  return;
}



// Entry 00432a28, recovered name Published_N84Click_00432a28

void Published_N84Click_00432a28(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 10;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if (((DAT_005b8548 != -1) && (DAT_005b8544 != -1)) && (DAT_005b856d == '\x01')) {
    for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
    }
    DAT_005b8554 = 0;
    for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
    }
    DAT_005b8558 = 0;
    for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
    }
    DAT_005b855c = 0;
    for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
          local_20 = local_20 + 1) {
        (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    DAT_005b8554 = 0;
    FUN_00417668(param_1);
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
    DAT_005b8548 = -1;
    DAT_005b8544 = -1;
  }
  return;
}



// Entry 00432c98, recovered name Published_N85Click_00432c98

void Published_N85Click_00432c98(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 0xb;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if (((DAT_005b8548 != -1) && (DAT_005b8544 != -1)) && (DAT_005b856d == '\x01')) {
    for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
    }
    DAT_005b8554 = 0;
    for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
    }
    DAT_005b8558 = 0;
    for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
    }
    DAT_005b855c = 0;
    for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
          local_20 = local_20 + 1) {
        (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    DAT_005b8554 = 0;
    FUN_00417668(param_1);
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
    DAT_005b8548 = -1;
    DAT_005b8544 = -1;
  }
  return;
}



// Entry 00432f08, recovered name Published_N86Click_00432f08

void Published_N86Click_00432f08(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 0xc;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if (((DAT_005b8548 != -1) && (DAT_005b8544 != -1)) && (DAT_005b856d == '\x01')) {
    for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
    }
    DAT_005b8554 = 0;
    for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
    }
    DAT_005b8558 = 0;
    for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
    }
    DAT_005b855c = 0;
    for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
          local_20 = local_20 + 1) {
        (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    DAT_005b8554 = 0;
    FUN_00417668(param_1);
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
    DAT_005b8548 = -1;
    DAT_005b8544 = -1;
  }
  return;
}



// Entry 00433178, recovered name Published_N87Click_00433178

void Published_N87Click_00433178(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 0xd;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if (((DAT_005b8548 != -1) && (DAT_005b8544 != -1)) && (DAT_005b856d == '\x01')) {
    for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
      FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
    }
    DAT_005b8554 = 0;
    for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
      FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
    }
    DAT_005b8558 = 0;
    for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
      FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
    }
    DAT_005b855c = 0;
    for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
          local_20 = local_20 + 1) {
        (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      }
    }
    FUN_004d82f4(DAT_005c98d0);
    FUN_004d7e00(DAT_005c98d0);
    DAT_005b8554 = 0;
    FUN_00417668(param_1);
    FUN_00406b0c(param_1);
    FUN_0042c350(param_1);
    DAT_005b8548 = -1;
    DAT_005b8544 = -1;
  }
  return;
}



// Entry 004333e8, recovered name Published_N21Click_004333e8

void Published_N21Click_004333e8(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton23Click_0043270c(param_1,param_2);
  return;
}



// Entry 00433404, recovered name Published_N78Click_00433404

void Published_N78Click_00433404(undefined4 param_1,undefined4 param_2)

{
  Published_N84Click_00432a28(param_1,param_2);
  return;
}



// Entry 00433420, recovered name Published_N79Click_00433420

void Published_N79Click_00433420(undefined4 param_1,undefined4 param_2)

{
  Published_N85Click_00432c98(param_1,param_2);
  return;
}



// Entry 0043343c, recovered name Published_N80Click_0043343c

void Published_N80Click_0043343c(undefined4 param_1,undefined4 param_2)

{
  Published_N86Click_00432f08(param_1,param_2);
  return;
}



// Entry 00433458, recovered name Published_N88Click_00433458

void Published_N88Click_00433458(undefined4 param_1,undefined4 param_2)

{
  Published_N87Click_00433178(param_1,param_2);
  return;
}



// Entry 00433474, recovered name Published_SpeedButton25Click_00433474

void Published_SpeedButton25Click_00433474(undefined4 param_1,undefined4 param_2)

{
  Published_N20Click_004322c4(param_1,param_2);
  return;
}



// Entry 00433490, recovered name Published_FormShow_00433490

void Published_FormShow_00433490(int param_1)

{
  byte *pbVar1;
  char cVar2;
  undefined1 uVar3;
  HCURSOR pHVar4;
  int *piVar5;
  int iVar6;
  undefined4 *in_FS_OFFSET;
  int local_a0;
  int local_9c;
  int local_98;
  undefined4 local_84;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bd35c);
  pHVar4 = LoadCursorA(*(HINSTANCE *)PTR_DAT_005c946c,&DAT_005b8efe);
  thunk_FUN_005583a8(*(undefined4 *)PTR_DAT_005c9498,1,pHVar4);
  pHVar4 = LoadCursorA(*(HINSTANCE *)PTR_DAT_005c946c,&DAT_005b8f03);
  thunk_FUN_005583a8(*(undefined4 *)PTR_DAT_005c9498,2,pHVar4);
  FUN_005a2750(local_8,&DAT_00ccf6e4);
  FUN_005a28f0(param_1 + 0xba0,local_8);
  FUN_005a28c0(local_8,2);
  FUN_005a2750(local_c,&DAT_005b8f08);
  cVar2 = FUN_005a29a8(param_1 + 0xba0,local_c);
  FUN_005a28c0(local_c,2);
  if (cVar2 != '\0') {
    FUN_004cc8c0(param_1,*(undefined4 *)(param_1 + 0xba0));
  }
  piVar5 = (int *)FUN_00423848(PTR_PTR_00580cd4,1);
  if (*(char *)(param_1 + 0xa58) == '\0') {
    *(undefined1 *)(param_1 + 0xa31) = 0x14;
    *(undefined1 *)(param_1 + 0xa32) = 1;
    FUN_0042389c();
    local_98 = 5;
    do {
      uVar3 = FUN_004238b0();
      *(undefined1 *)(param_1 + 0xa30 + local_98) = uVar3;
      local_98 = local_98 + 1;
    } while (local_98 < 0x14);
    if (*(char *)(*(int *)(*(int *)(param_1 + 0x5e8) + 0x80) + 8) == '\x01') {
      *(undefined4 *)(param_1 + 0xa2c) = 0;
      FUN_00532790(*(undefined4 *)(*(int *)(param_1 + 0x5e8) + 0x80),param_1 + 0xa30,0x14);
      while (*(int *)(param_1 + 0xa2c) == 0) {
        FUN_00559f18(*(undefined4 *)PTR_DAT_005c9494);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xa58) = 1;
    }
    if (*(char *)(param_1 + 0xa57) == 'd') {
      local_9c = 5;
      do {
        pbVar1 = (byte *)(param_1 + 0xa44 + local_9c);
        *pbVar1 = *pbVar1 ^ *(byte *)(param_1 + 0xa57);
        local_9c = local_9c + 1;
      } while (local_9c < 0x13);
    }
    local_a0 = 5;
    do {
      pbVar1 = (byte *)(param_1 + 0xa44 + local_a0);
      *pbVar1 = *pbVar1 ^ *(byte *)(param_1 + 0xa44);
      pbVar1 = (byte *)(param_1 + local_a0 + 0xa45);
      *pbVar1 = *pbVar1 ^ *(byte *)(param_1 + 0xa47);
      local_a0 = local_a0 + 2;
    } while (local_a0 < 0x13);
    if (*(char *)(param_1 + 0xa32) == '\x01') {
      FUN_004238cc();
    }
    else if (*(char *)(param_1 + 0xa32) == '\x02') {
      FUN_00423948();
    }
    else if (*(char *)(param_1 + 0xa32) == '\x03') {
      FUN_004239c4();
    }
    else if (*(char *)(param_1 + 0xa32) == '\x04') {
      FUN_00423a60();
    }
    else if (*(char *)(param_1 + 0xa32) == '\x05') {
      FUN_00423ae0();
    }
    FUN_005994b8();
    iVar6 = FUN_00596728();
    *(int *)(param_1 + 0xa5c) = iVar6;
    if (iVar6 != 0) {
      *(undefined1 *)(param_1 + 0xa58) = 1;
    }
  }
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + -4))(piVar5,3);
  }
  *in_FS_OFFSET = local_84;
  return;
}



// Entry 00434058, recovered name Published_ControlBar1MouseMove_00434058

void Published_ControlBar1MouseMove_00434058(void)

{
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0);
  return;
}



// Entry 0043407c, recovered name Published_ToolBar1MouseMove_0043407c

void Published_ToolBar1MouseMove_0043407c(void)

{
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0);
  return;
}



// Entry 004340a0, recovered name Published_ToolBar2MouseMove_004340a0

void Published_ToolBar2MouseMove_004340a0(void)

{
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0);
  return;
}



// Entry 004340c4, recovered name Published_ToolBar4MouseMove_004340c4

void Published_ToolBar4MouseMove_004340c4(void)

{
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0);
  return;
}



// Entry 004340e8, recovered name Published_SpeedButton29Click_004340e8

void Published_SpeedButton29Click_004340e8(undefined4 param_1)

{
  undefined2 uVar1;
  LPCSTR lpFile;
  HWND hwnd;
  undefined4 *in_FS_OFFSET;
  LPCSTR lpOperation;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  INT nShowCmd;
  undefined4 local_30;
  short local_1e;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bd490);
  FUN_0040328c(local_8);
  FUN_005a2750(local_c,s_http___www_eedduu_com_005b9024);
  FUN_005a28f0(local_8,local_c);
  FUN_005a28c0(local_c,2);
  lpFile = (LPCSTR)FUN_00423b60(local_8);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  nShowCmd = 1;
  lpDirectory = &DAT_005b9040;
  lpParameters = &DAT_005b903f;
  lpOperation = &DAT_005b903a;
  hwnd = (HWND)FUN_0056f494(param_1);
  ShellExecuteA(hwnd,lpOperation,lpFile,lpParameters,lpDirectory,nShowCmd);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_1e != 0) {
    return;
  }
  FUN_005a28c0(local_8,2);
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 004341e4, recovered name Published_SpeedButton30Click_004341e4

void Published_SpeedButton30Click_004341e4(undefined4 param_1)

{
  undefined2 uVar1;
  LPCSTR lpFile;
  HWND hwnd;
  undefined4 *in_FS_OFFSET;
  LPCSTR lpOperation;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  INT nShowCmd;
  undefined4 local_30;
  short local_1e;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bd4f8);
  FUN_0040328c(local_8);
  FUN_005a2750(local_c,s_mailto_chem_jhksoft_com_005b9041);
  FUN_005a28f0(local_8,local_c);
  FUN_005a28c0(local_c,2);
  lpFile = (LPCSTR)FUN_00423b60(local_8);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  nShowCmd = 1;
  lpDirectory = &DAT_005b905f;
  lpParameters = &DAT_005b905e;
  lpOperation = &DAT_005b9059;
  hwnd = (HWND)FUN_0056f494(param_1);
  ShellExecuteA(hwnd,lpOperation,lpFile,lpParameters,lpDirectory,nShowCmd);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_1e != 0) {
    return;
  }
  FUN_005a28c0(local_8,2);
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 004342e0, recovered name Published_SpeedButton26Click_004342e0

void Published_SpeedButton26Click_004342e0(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
  DAT_005b8540 = 0xe;
  DAT_005b856c = 0;
  DAT_005b8573 = 0;
  if ((DAT_005b8548 == -1) || (DAT_005b8544 == -1)) {
    FUN_00589f34(*(undefined4 *)(param_1 + 0x504),0);
  }
  else {
    if (DAT_005b856d == '\x01') {
      for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
      }
      DAT_005b8554 = 0;
      for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
      }
      DAT_005b8558 = 0;
      for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
      }
      DAT_005b855c = 0;
      for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
            local_20 = local_20 + 1) {
          (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      FUN_00417668(param_1);
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      DAT_005b8548 = -1;
      DAT_005b8544 = -1;
    }
    FUN_00589f34(*(undefined4 *)(param_1 + 0x504),0);
  }
  return;
}



// Entry 0043456c, recovered name Published_N90Click_0043456c

void Published_N90Click_0043456c(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton26Click_004342e0(param_1,param_2);
  return;
}



// Entry 00434588, recovered name Published_ComboBox1ContextPopup_00434588

void Published_ComboBox1ContextPopup_00434588
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0,param_3,param_3,param_2,param_1);
  return;
}



// Entry 004345ac, recovered name Published_SpeedButton31Click_004345ac

void Published_SpeedButton31Click_004345ac(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  LPCSTR lpFile;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 *in_FS_OFFSET;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  INT nShowCmd;
  undefined4 local_3c;
  short local_2a;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bd588);
  FUN_0040328c(local_8);
  uVar2 = FUN_0040328c(&local_c);
  FUN_0055a58c(*(undefined4 *)PTR_DAT_005c9494,uVar2);
  uVar2 = FUN_0040328c(local_10);
  FUN_0058d590(local_c,uVar2);
  FUN_005a28f0(local_8,local_10);
  FUN_005a28c0(local_10,2);
  FUN_005a28c0(&local_c,2);
  uVar2 = FUN_0040328c(local_18);
  FUN_005a2750(local_14,&DAT_005b9086);
  FUN_005a2904(local_8,local_14,uVar2);
  FUN_005a28f0(local_8,local_18);
  FUN_005a28c0(local_18,2);
  FUN_005a28c0(local_14,2);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,CONCAT22(extraout_var,0xfff5));
  nShowCmd = 5;
  lpDirectory = (LPCSTR)0x0;
  lpParameters = (LPCSTR)0x0;
  lpFile = (LPCSTR)FUN_00423b60(local_8);
  ShellExecuteA(*(HWND *)(*(int *)PTR_DAT_005c9494 + 0x24),&DAT_005b9095,lpFile,lpParameters,
                lpDirectory,nShowCmd);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,CONCAT22(extraout_var_00,uVar1));
  if (local_2a != 0) {
    return;
  }
  FUN_005a28c0(local_8,2);
  *in_FS_OFFSET = local_3c;
  return;
}



// Entry 00434728, recovered name Published_N92Click_00434728

void Published_N92Click_00434728(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton29Click_004340e8(param_1,param_2);
  return;
}



// Entry 00434744, recovered name Published_N93Click_00434744

void Published_N93Click_00434744(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton30Click_004341e4(param_1,param_2);
  return;
}



// Entry 00434760, recovered name Published_FormMouseWheelUp_00434760

void Published_FormMouseWheelUp_00434760(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton10Click_0042e0a4(param_1,param_2);
  return;
}



// Entry 00434780, recovered name Published_FormMouseWheelDown_00434780

void Published_FormMouseWheelDown_00434780(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton15Click_0042dfd0(param_1,param_2);
  return;
}



// Entry 004347a0, recovered name Published_N94Click_004347a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_N94Click_004347a0(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  (**(code **)(**(int **)PTR__Form9_005c948c + 0xd8))();
  for (local_10 = 0; local_10 < DAT_005b8554; local_10 = local_10 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_10 * 4));
  }
  DAT_005b8554 = 0;
  for (local_14 = 0; local_14 < DAT_005b8558; local_14 = local_14 + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_14 * 4));
  }
  DAT_005b8558 = 0;
  for (local_18 = 0; local_18 < DAT_005b855c; local_18 = local_18 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_18 * 4));
  }
  DAT_005b855c = 0;
  for (local_1c = 0; local_1c < DAT_005b8550; local_1c = local_1c + 1) {
    for (local_20 = 0; local_20 < *(int *)(&DAT_005c98dc + local_1c * 0x6bd4);
        local_20 = local_20 + 1) {
      (&DAT_005c9900)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c993d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c9979)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c9901)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c993e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c997a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  *(float *)(param_1 + 0xaf0) = *(float *)(param_1 + 0xaec) - _DAT_004349b8;
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  return;
}



// Entry 004349bc, recovered name Published_ComboBox1Exit_004349bc

void Published_ComboBox1Exit_004349bc(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00555574(param_1,*(undefined4 *)(param_1 + 0x498),param_3,param_2);
  return;
}



// Entry 004349e0, recovered name Published_C1Click_004349e0

void Published_C1Click_004349e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  LPCSTR lpText;
  LPCSTR lpCaption;
  UINT uType;
  
  if (*(int *)(param_1 + 0xa28) == 0) {
    uType = 0;
    lpCaption = &DAT_005b90bf;
    lpText = &DAT_005b909a;
    hWnd = (HWND)FUN_0056f494(param_1);
    MessageBoxA(hWnd,lpText,lpCaption,uType);
  }
  else {
    FUN_00434a20(param_1,param_2,param_3,param_2);
  }
  return;
}



// Entry 004361a8, recovered name Published_SpeedButtonTurnClick_004361a8

void Published_SpeedButtonTurnClick_004361a8(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bd7dc);
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  if (*(char *)(*(int *)(param_1 + 0x53c) + 0x130) == '\0') {
    FUN_004362d8(param_1);
    Published_ScrollBar1Change_00436da8(param_1,param_2);
    FUN_00569200(*(undefined4 *)(param_1 + 0x540),0);
    (**(code **)(**(int **)(param_1 + 0x540) + 0x5c))(*(int **)(param_1 + 0x540),0);
    FUN_0053d8a0(*(undefined4 *)(param_1 + 0x540),0);
    puVar1 = (undefined4 *)FUN_005a2750(local_8,&DAT_005b9142);
    FUN_00569318(*(undefined4 *)(param_1 + 0x5e0),*puVar1);
    FUN_005a28c0(local_8,2);
    FUN_00569200(*(undefined4 *)(param_1 + 0x5e0),0);
    FUN_00589f34(*(undefined4 *)(param_1 + 0x53c),0);
    *(undefined4 *)(DAT_005c98d0 + 0x860) = 0;
    *(undefined4 *)(DAT_005c98d0 + 0x864) = 0;
    *(undefined4 *)(DAT_005c98d0 + 0x868) = 0;
    Published_ScrollBar1Change_00436da8(param_1,param_2);
    *in_FS_OFFSET = local_2c;
  }
  else {
    FUN_00589fb4(*(undefined4 *)(param_1 + 0x53c),3);
    *in_FS_OFFSET = local_2c;
  }
  return;
}



// Entry 00436da8, recovered name Published_ScrollBar1Change_00436da8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar1Change_00436da8(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_50;
  int local_4c;
  undefined4 local_3c;
  undefined4 local_18;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bd838);
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  FUN_0059b09c();
  if (((in_ST0 < (longdouble)_DAT_004374c8) && (FUN_0059b09c(), in_ST1 < (longdouble)_DAT_004374c8))
     && (FUN_0059b09c(), in_ST2 < (longdouble)_DAT_004374c8)) {
    FUN_00569200(*(undefined4 *)(param_1 + 0x540),0);
    (**(code **)(**(int **)(param_1 + 0x540) + 0x5c))(*(int **)(param_1 + 0x540),0);
    puVar2 = (undefined4 *)FUN_005a2750(local_8,&DAT_005b9148);
    FUN_00569318(*(undefined4 *)(param_1 + 0x5e0),*puVar2);
    FUN_005a28c0(local_8,2);
    FUN_00569200(*(undefined4 *)(param_1 + 0x5e0),0);
    FUN_0053d8a0(*(undefined4 *)(param_1 + 0x540),0);
    *(undefined4 *)(param_1 + 0xadc) = 0;
    FUN_004362d8(param_1);
    *in_FS_OFFSET = local_3c;
    return;
  }
  puVar2 = (undefined4 *)FUN_005a2750(local_c,&DAT_005b914e);
  FUN_00569318(*(undefined4 *)(param_1 + 0x5e0),*puVar2);
  FUN_005a28c0(local_c,2);
  FUN_00569200(*(undefined4 *)(param_1 + 0x5e0),1);
  if ((*(int *)(param_1 + 0xadc) - *(int *)(*(int *)(param_1 + 0x540) + 500) < 0) &&
     (*(int *)(*(int *)(param_1 + 0x540) + 500) == 0x168)) {
    FUN_0053d8a0(*(undefined4 *)(param_1 + 0x540),1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x540) + 500);
  if ((*(int *)(param_1 + 0xadc) != iVar1 && -1 < *(int *)(param_1 + 0xadc) - iVar1) &&
     (*(int *)(*(int *)(param_1 + 0x540) + 500) == 0)) {
    FUN_0053d8a0(*(undefined4 *)(param_1 + 0x540),0x167);
  }
  uVar3 = FUN_0040328c(&local_18);
  FUN_005a2750(local_14,&DAT_005b9154);
  uVar4 = FUN_005a2810(local_10,*(undefined4 *)(*(int *)(param_1 + 0x540) + 500));
  FUN_005a2904(uVar4,local_14,uVar3);
  FUN_00569318(*(undefined4 *)(param_1 + 0x5e0),local_18);
  FUN_005a28c0(&local_18,2);
  FUN_005a28c0(local_14,2);
  FUN_005a28c0(local_10,2);
  for (local_4c = 0; local_4c < DAT_005b8554; local_4c = local_4c + 1) {
    if (*(char *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 4) != '\0') {
      if (*(char *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x9dc) == '\x03') {
        FUN_00402814();
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x398) = local_74;
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x39c) = local_70;
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x3a0) = local_6c;
      }
      if (*(char *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x9dc) == '\x04') {
        FUN_00402814();
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x398) = local_74;
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x39c) = local_70;
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x3a0) = local_6c;
        FUN_00402814();
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x3a8) = local_74;
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x3ac) = local_70;
        *(undefined4 *)(*(int *)(&DAT_0060cf24 + local_4c * 4) + 0x3b0) = local_6c;
      }
    }
  }
  for (local_50 = 0; local_50 < DAT_005b8554; local_50 = local_50 + 1) {
    if ((*(char *)(*(int *)(&DAT_0060cf24 + local_50 * 4) + 4) != '\0') &&
       (*(char *)(*(int *)(&DAT_0060cf24 + local_50 * 4) + 0x9dc) == '\x04')) {
      FUN_0059c5f8();
      FUN_0059c5f8();
      FUN_0059c5f8();
      FUN_0059af25();
      FUN_0059af25();
      FUN_0059af25();
      FUN_004d64b0(*(undefined4 *)(&DAT_0060cf24 + local_50 * 4));
    }
  }
  *(undefined4 *)(param_1 + 0xadc) = *(undefined4 *)(*(int *)(param_1 + 0x540) + 500);
  *in_FS_OFFSET = local_3c;
  return;
}



// Entry 004374f4, recovered name Published_VRML1Click_004374f4

void Published_VRML1Click_004374f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  LPCSTR lpText;
  LPCSTR lpCaption;
  UINT uType;
  
  if (*(int *)(param_1 + 0xa28) == 0) {
    uType = 0;
    lpCaption = (LPCSTR)0x5b917e;
    lpText = (LPCSTR)0x5b9159;
    hWnd = (HWND)FUN_0056f494(param_1);
    MessageBoxA(hWnd,lpText,lpCaption,uType);
  }
  else {
    FUN_00437534(param_1,param_2,param_3,param_2);
  }
  return;
}



// Entry 0043d7ac, recovered name Published_SpeedButton14Click_0043d7ac

void Published_SpeedButton14Click_0043d7ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00589fb4(*(undefined4 *)(param_1 + 0x54c),2,param_3,param_2);
  return;
}



// Entry 0048f8b8, recovered name Published_N96Click_0048f8b8

void Published_N96Click_0048f8b8(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton3Click_0042d788(param_1,param_2);
  return;
}



// Entry 0048f8d4, recovered name Published_N97Click_0048f8d4

void Published_N97Click_0048f8d4(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton4Click_0042d9f8(param_1,param_2);
  return;
}



// Entry 0048f8f0, recovered name Published_N98Click_0048f8f0

void Published_N98Click_0048f8f0(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton5Click_0042dce4(param_1,param_2);
  return;
}



// Entry 0048f90c, recovered name Published_N99Click_0048f90c

void Published_N99Click_0048f90c(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton7Click_0042efbc(param_1,param_2);
  return;
}



// Entry 0048f928, recovered name Published_N100Click_0048f928

void Published_N100Click_0048f928(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton8Click_0042f248(param_1,param_2);
  return;
}



// Entry 0048f944, recovered name Published_N102Click_0048f944

void Published_N102Click_0048f944(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton26Click_004342e0(param_1,param_2);
  return;
}



// Entry 0048f960, recovered name Published_N103Click_0048f960

void Published_N103Click_0048f960(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton21Click_0042f4d4(param_1,param_2);
  return;
}



// Entry 0048f97c, recovered name Published_N104Click_0048f97c

void Published_N104Click_0048f97c(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton22Click_0042f760(param_1,param_2);
  return;
}



// Entry 0048f998, recovered name Published_N105Click_0048f998

void Published_N105Click_0048f998(undefined4 param_1,undefined4 param_2)

{
  Published_SpeedButton23Click_0043270c(param_1,param_2);
  return;
}



// Entry 0048f9b4, recovered name Published_HH1Click_0048f9b4

void Published_HH1Click_0048f9b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b8542 = 1;
  FUN_0048c070(param_1,param_1,param_3,param_2);
  DAT_005b8542 = 0;
  return;
}



// Entry 0048fa00, recovered name Published_HH2Click_0048fa00

void Published_HH2Click_0048fa00(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b8542 = 2;
  FUN_0048c070(param_1,param_1,param_3,param_2);
  DAT_005b8542 = 0;
  return;
}



// Entry 0048fa4c, recovered name Published_HBr1Click_0048fa4c

void Published_HBr1Click_0048fa4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b8542 = 3;
  FUN_0048c070(param_1,param_1,param_3,param_2);
  DAT_005b8542 = 0;
  return;
}



// Entry 0048fa98, recovered name Published_ClCl1Click_0048fa98

void Published_ClCl1Click_0048fa98(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b8542 = 4;
  FUN_0048c070(param_1,param_1,param_3,param_2);
  DAT_005b8542 = 0;
  return;
}



// Entry 0048fae4, recovered name Published_BrBr1Click_0048fae4

void Published_BrBr1Click_0048fae4(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b8542 = 5;
  FUN_0048c070(param_1,param_1,param_3,param_2);
  DAT_005b8542 = 0;
  return;
}



// Entry 0048fb30, recovered name Published_HOH1Click_0048fb30

void Published_HOH1Click_0048fb30(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  DAT_005b8542 = 6;
  FUN_0048c070(param_1,param_1,param_3,param_2);
  DAT_005b8542 = 0;
  return;
}



// Entry 0048fb7c, recovered name Published_N32Click_0048fb7c

void Published_N32Click_0048fb7c(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  FUN_0048c070(param_1,param_1,param_3,param_2);
  return;
}



// Entry 004c21f4, recovered name Published_N67Click_004c21f4

void Published_N67Click_004c21f4(int param_1)

{
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  for (iStack_10 = 0; iStack_10 < DAT_005b8550; iStack_10 = iStack_10 + 1) {
    for (iStack_14 = 0; iStack_14 < *(int *)(&DAT_005c98dc + iStack_10 * 0x6bd4);
        iStack_14 = iStack_14 + 1) {
      (&DAT_005c993c)[iStack_14 * 0x114 + iStack_10 * 0x6bd4] = 0;
      (&DAT_005c9978)[iStack_14 * 0x114 + iStack_10 * 0x6bd4] = 0;
      (&DAT_005c99b4)[iStack_14 * 0x114 + iStack_10 * 0x6bd4] = 0;
      (&DAT_005c99f0)[iStack_14 * 0x114 + iStack_10 * 0x6bd4] = 0;
    }
  }
  DAT_005b8543 = 4;
  iStack_18 = 0;
  do {
    if (DAT_005b8554 <= iStack_18) {
LAB_004c230f:
      DAT_005b8543 = 0;
      for (iStack_1c = 0; iStack_1c < DAT_005b8554; iStack_1c = iStack_1c + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + iStack_1c * 4));
      }
      DAT_005b8554 = 0;
      for (iStack_20 = 0; iStack_20 < DAT_005b8558; iStack_20 = iStack_20 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + iStack_20 * 4));
      }
      DAT_005b8558 = 0;
      for (iStack_24 = 0; iStack_24 < DAT_005b855c; iStack_24 = iStack_24 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + iStack_24 * 4));
      }
      DAT_005b855c = 0;
      for (iStack_28 = 0; iStack_28 < DAT_005b8550; iStack_28 = iStack_28 + 1) {
        for (iStack_2c = 0; iStack_2c < *(int *)(&DAT_005c98dc + iStack_28 * 0x6bd4);
            iStack_2c = iStack_2c + 1) {
          (&DAT_005c9900)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c993d)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c9979)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c99b5)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c99f1)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c9901)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c993e)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c997a)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c99b6)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c99f2)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      DAT_005b8558 = 0;
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      return;
    }
    if ((*(char *)(*(int *)(&DAT_0060cf24 + iStack_18 * 4) + 0x339) != '\0') &&
       (*(char *)(*(int *)(&DAT_0060cf24 + iStack_18 * 4) + 0x9dc) == '\x04')) {
      FUN_0048fbbc(param_1,*(int *)(&DAT_0060cf24 + iStack_18 * 4) + 0x300);
      goto LAB_004c230f;
    }
    iStack_18 = iStack_18 + 1;
  } while( true );
}



// Entry 004c64b8, recovered name Published_N69Click_004c64b8

void Published_N69Click_004c64b8(int param_1)

{
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  for (iStack_10 = 0; iStack_10 < DAT_005b8550; iStack_10 = iStack_10 + 1) {
    for (iStack_14 = 0; iStack_14 < *(int *)(&DAT_005c98dc + iStack_10 * 0x6bd4);
        iStack_14 = iStack_14 + 1) {
      (&DAT_005c993c)[iStack_14 * 0x114 + iStack_10 * 0x6bd4] = 0;
      (&DAT_005c9978)[iStack_14 * 0x114 + iStack_10 * 0x6bd4] = 0;
      (&DAT_005c99b4)[iStack_14 * 0x114 + iStack_10 * 0x6bd4] = 0;
      (&DAT_005c99f0)[iStack_14 * 0x114 + iStack_10 * 0x6bd4] = 0;
    }
  }
  DAT_005b8543 = 2;
  iStack_18 = 0;
  do {
    if (DAT_005b8554 <= iStack_18) {
LAB_004c65d3:
      DAT_005b8543 = 0;
      for (iStack_1c = 0; iStack_1c < DAT_005b8554; iStack_1c = iStack_1c + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + iStack_1c * 4));
      }
      DAT_005b8554 = 0;
      for (iStack_20 = 0; iStack_20 < DAT_005b8558; iStack_20 = iStack_20 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + iStack_20 * 4));
      }
      DAT_005b8558 = 0;
      for (iStack_24 = 0; iStack_24 < DAT_005b855c; iStack_24 = iStack_24 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + iStack_24 * 4));
      }
      DAT_005b855c = 0;
      for (iStack_28 = 0; iStack_28 < DAT_005b8550; iStack_28 = iStack_28 + 1) {
        for (iStack_2c = 0; iStack_2c < *(int *)(&DAT_005c98dc + iStack_28 * 0x6bd4);
            iStack_2c = iStack_2c + 1) {
          (&DAT_005c9900)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c993d)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c9979)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c99b5)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c99f1)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c9901)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c993e)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c997a)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c99b6)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
          (&DAT_005c99f2)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      DAT_005b8558 = 0;
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      FUN_004362d8(param_1);
      return;
    }
    if ((*(char *)(*(int *)(&DAT_0060cf24 + iStack_18 * 4) + 0x339) != '\0') &&
       (*(char *)(*(int *)(&DAT_0060cf24 + iStack_18 * 4) + 0x9dc) == '\x04')) {
      FUN_0048fbbc(param_1,*(int *)(&DAT_0060cf24 + iStack_18 * 4) + 0x300);
      goto LAB_004c65d3;
    }
    iStack_18 = iStack_18 + 1;
  } while( true );
}



// Entry 004c67c8, recovered name Published_N82Click_004c67c8

void Published_N82Click_004c67c8(int param_1)

{
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  for (local_10 = 0; local_10 < DAT_005b8550; local_10 = local_10 + 1) {
    for (local_14 = 0; local_14 < *(int *)(&DAT_005c98dc + local_10 * 0x6bd4);
        local_14 = local_14 + 1) {
      (&DAT_005c993c)[local_14 * 0x114 + local_10 * 0x6bd4] = 0;
      (&DAT_005c9978)[local_14 * 0x114 + local_10 * 0x6bd4] = 0;
      (&DAT_005c99b4)[local_14 * 0x114 + local_10 * 0x6bd4] = 0;
      (&DAT_005c99f0)[local_14 * 0x114 + local_10 * 0x6bd4] = 0;
    }
  }
  DAT_005b8543 = 3;
  local_18 = 0;
  do {
    if (DAT_005b8554 <= local_18) {
LAB_004c68e3:
      DAT_005b8543 = 0;
      for (local_1c = 0; local_1c < DAT_005b8554; local_1c = local_1c + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_1c * 4));
      }
      DAT_005b8554 = 0;
      for (local_20 = 0; local_20 < DAT_005b8558; local_20 = local_20 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_20 * 4));
      }
      DAT_005b8558 = 0;
      for (local_24 = 0; local_24 < DAT_005b855c; local_24 = local_24 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_24 * 4));
      }
      DAT_005b855c = 0;
      for (local_28 = 0; local_28 < DAT_005b8550; local_28 = local_28 + 1) {
        for (local_2c = 0; local_2c < *(int *)(&DAT_005c98dc + local_28 * 0x6bd4);
            local_2c = local_2c + 1) {
          (&DAT_005c9900)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c993d)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c9979)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c9901)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c993e)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c997a)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      DAT_005b8558 = 0;
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      FUN_004362d8(param_1);
      return;
    }
    if ((*(char *)(*(int *)(&DAT_0060cf24 + local_18 * 4) + 0x339) != '\0') &&
       (*(char *)(*(int *)(&DAT_0060cf24 + local_18 * 4) + 0x9dc) == '\x04')) {
      FUN_0048fbbc(param_1,*(int *)(&DAT_0060cf24 + local_18 * 4) + 0x300);
      goto LAB_004c68e3;
    }
    local_18 = local_18 + 1;
  } while( true );
}



// Entry 004c6ad8, recovered name Published_HH3Click_004c6ad8

void Published_HH3Click_004c6ad8(int param_1)

{
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  *(int *)(param_1 + 0xae4) = *(int *)(param_1 + 0xae4) + 1;
  for (local_10 = 0; local_10 < DAT_005b8550; local_10 = local_10 + 1) {
    for (local_14 = 0; local_14 < *(int *)(&DAT_005c98dc + local_10 * 0x6bd4);
        local_14 = local_14 + 1) {
      (&DAT_005c993c)[local_14 * 0x114 + local_10 * 0x6bd4] = 0;
      (&DAT_005c9978)[local_14 * 0x114 + local_10 * 0x6bd4] = 0;
      (&DAT_005c99b4)[local_14 * 0x114 + local_10 * 0x6bd4] = 0;
      (&DAT_005c99f0)[local_14 * 0x114 + local_10 * 0x6bd4] = 0;
    }
  }
  DAT_005b8543 = 1;
  local_18 = 0;
  do {
    if (DAT_005b8554 <= local_18) {
LAB_004c6bf3:
      DAT_005b8543 = 0;
      for (local_1c = 0; local_1c < DAT_005b8554; local_1c = local_1c + 1) {
        FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_1c * 4));
      }
      DAT_005b8554 = 0;
      for (local_20 = 0; local_20 < DAT_005b8558; local_20 = local_20 + 1) {
        FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_20 * 4));
      }
      DAT_005b8558 = 0;
      for (local_24 = 0; local_24 < DAT_005b855c; local_24 = local_24 + 1) {
        FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_24 * 4));
      }
      DAT_005b855c = 0;
      for (local_28 = 0; local_28 < DAT_005b8550; local_28 = local_28 + 1) {
        for (local_2c = 0; local_2c < *(int *)(&DAT_005c98dc + local_28 * 0x6bd4);
            local_2c = local_2c + 1) {
          (&DAT_005c9900)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c993d)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c9979)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c99b5)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c99f1)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c9901)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c993e)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c997a)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c99b6)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
          (&DAT_005c99f2)[local_2c * 0x114 + local_28 * 0x6bd4] = 0;
        }
      }
      FUN_004d82f4(DAT_005c98d0);
      FUN_004d7e00(DAT_005c98d0);
      DAT_005b8554 = 0;
      DAT_005b8558 = 0;
      FUN_00406b0c(param_1);
      FUN_0042c350(param_1);
      FUN_004362d8(param_1);
      return;
    }
    if ((*(char *)(*(int *)(&DAT_0060cf24 + local_18 * 4) + 0x339) != '\0') &&
       (*(char *)(*(int *)(&DAT_0060cf24 + local_18 * 4) + 0x9dc) == '\x04')) {
      FUN_0048fbbc(param_1,*(int *)(&DAT_0060cf24 + local_18 * 4) + 0x300);
      goto LAB_004c6bf3;
    }
    local_18 = local_18 + 1;
  } while( true );
}



// Entry 004cb030, recovered name Published_Timer2Timer_004cb030

void Published_Timer2Timer_004cb030(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(*(int *)(param_1 + 0x36c) + 0x38) == '\0') {
    FUN_004cb094(param_1,*(int *)(param_1 + 0x36c),param_3,param_2);
  }
  else {
    FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),0);
    FUN_0041a2b4(param_1);
    FUN_004d8640(DAT_005c98d0);
    FUN_004cb094(param_1);
    FUN_0055e53c(*(undefined4 *)(param_1 + 0x36c),1);
  }
  return;
}



// Entry 004cb3b0, recovered name Published_SpeedButton28Click_004cb3b0

void Published_SpeedButton28Click_004cb3b0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  int local_4c;
  undefined4 local_40;
  undefined4 local_1c;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bf62c);
  (**(code **)(**(int **)(param_1 + 0x5c4) + 0x5c))(*(int **)(param_1 + 0x5c4),1);
  (**(code **)(**(int **)(param_1 + 0x5c8) + 0x5c))(*(int **)(param_1 + 0x5c8),0);
  local_4c = 0;
  while( true ) {
    uVar2 = FUN_0040328c(local_c);
    FUN_005a2750(local_8,s_picture__005b9ab1);
    FUN_005a2904(param_1 + 0xba4,local_8,uVar2);
    uVar2 = FUN_0040328c(local_14);
    FUN_005a2810(local_10,local_4c);
    FUN_005a2904(local_c,local_10,uVar2);
    uVar2 = FUN_0040328c(&local_1c);
    FUN_005a2750(local_18,&DAT_005b9aba);
    FUN_005a2904(local_14,local_18,uVar2);
    cVar1 = thunk_FUN_0058d4f8(local_1c);
    FUN_005a28c0(&local_1c,2);
    FUN_005a28c0(local_18,2);
    FUN_005a28c0(local_14,2);
    FUN_005a28c0(local_10,2);
    FUN_005a28c0(local_c,2);
    FUN_005a28c0(local_8,2);
    if (cVar1 == '\0') break;
    local_4c = local_4c + 1;
  }
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x5c0),1);
  *(undefined4 *)(param_1 + 0xa64) = 0;
  *in_FS_OFFSET = local_40;
  return;
}



// Entry 004cb51c, recovered name Published_SpeedButton27Click_004cb51c

void Published_SpeedButton27Click_004cb51c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  LPCSTR lpFile;
  undefined4 *in_FS_OFFSET;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  INT nShowCmd;
  undefined4 local_34;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bf67c,param_2,param_3,param_2);
  (**(code **)(**(int **)(param_1 + 0x5c4) + 0x5c))(*(int **)(param_1 + 0x5c4),0);
  (**(code **)(**(int **)(param_1 + 0x5c8) + 0x5c))(*(int **)(param_1 + 0x5c8),1);
  FUN_0055e53c(*(undefined4 *)(param_1 + 0x5c0),0);
  *(undefined4 *)(param_1 + 0xa64) = 0;
  FUN_0040328c(local_8);
  uVar1 = FUN_0040328c(local_10);
  FUN_005a2750(local_c,s_avi_exe_005b9abf);
  FUN_005a2904(param_1 + 0xba4,local_c,uVar1);
  FUN_005a28f0(local_8,local_10);
  FUN_005a28c0(local_10,2);
  FUN_005a28c0(local_c,2);
  nShowCmd = 1;
  lpDirectory = &DAT_005b9acd;
  lpParameters = &DAT_005b9acc;
  lpFile = (LPCSTR)FUN_00423b60(local_8);
  ShellExecuteA(*(HWND *)(*(int *)PTR_DAT_005c9494 + 0x24),&DAT_005b9ac7,lpFile,lpParameters,
                lpDirectory,nShowCmd);
  FUN_005a28c0(local_8,2);
  *in_FS_OFFSET = local_34;
  return;
}



// Entry 004cc1d8, recovered name Published_N89Click_004cc1d8

void Published_N89Click_004cc1d8(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bf6a8);
  *(undefined1 *)(param_1 + 0xa70) = 1;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  DAT_005b8541 = 0;
  FUN_0053b0a4(*(undefined4 *)(param_1 + 0x458),0);
  FUN_00555574(param_1,*(undefined4 *)(param_1 + 0x498));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 004cc480, recovered name Published_N106Click_004cc480

void Published_N106Click_004cc480(int param_1)

{
  undefined2 uVar1;
  undefined4 *in_FS_OFFSET;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_28;
  short local_16;
  
  FUN_00596a18(&DAT_005bf6bc);
  *(undefined1 *)(param_1 + 0xa70) = 0;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  DAT_005b8541 = 0;
  FUN_0053b0a4(*(undefined4 *)(param_1 + 0x458),1);
  FUN_00555574(param_1,*(undefined4 *)(param_1 + 0x498));
  for (local_38 = 0; local_38 < DAT_005b8554; local_38 = local_38 + 1) {
    FUN_004d80e4(DAT_005c98d0,*(undefined4 *)(&DAT_0060cf24 + local_38 * 4));
  }
  DAT_005b8554 = 0;
  for (local_3c = 0; local_3c < DAT_005b8558; local_3c = local_3c + 1) {
    FUN_004d8170(DAT_005c98d0,*(undefined4 *)(&DAT_00610da4 + local_3c * 4));
  }
  DAT_005b8558 = 0;
  for (local_40 = 0; local_40 < DAT_005b855c; local_40 = local_40 + 1) {
    FUN_004d81fc(DAT_005c98d0,*(undefined4 *)(&DAT_00614c24 + local_40 * 4));
  }
  DAT_005b855c = 0;
  for (local_44 = 0; local_44 < DAT_005b8550; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_005c98dc + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_005c9900)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9979)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c9901)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c993e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c997a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99b6)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_005c99f2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_004d82f4(DAT_005c98d0);
  FUN_004d7e00(DAT_005c98d0);
  DAT_005b8554 = 0;
  DAT_005b8558 = 0;
  FUN_00406b0c(param_1);
  FUN_0042c350(param_1);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 004cc72c, recovered name Published_N107Click_004cc72c

void Published_N107Click_004cc72c(undefined4 param_1,undefined4 param_2)

{
  Published_N89Click_004cc1d8(param_1,param_2);
  return;
}



// Entry 004cc748, recovered name Published_N108Click_004cc748

void Published_N108Click_004cc748(undefined4 param_1,undefined4 param_2)

{
  Published_N106Click_004cc480(param_1,param_2);
  return;
}



// Entry 004cc764, recovered name Published_ClientSocket1Connect_004cc764

void Published_ClientSocket1Connect_004cc764(int param_1)

{
  *(undefined4 *)(param_1 + 0xa2c) = 1;
  return;
}



// Entry 004cc784, recovered name Published_ClientSocket1Error_004cc784

void Published_ClientSocket1Error_004cc784
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  *(undefined4 *)(param_1 + 0xa2c) = 0xffffffff;
  *param_4 = 0;
  return;
}



// Entry 004cc7b0, recovered name Published_ClientSocket1Read_004cc7b0

void Published_ClientSocket1Read_004cc7b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005bf6f0);
  iVar1 = FUN_00532a84(*(undefined4 *)(*(int *)(param_1 + 0x5e8) + 0x80));
  if (0 < iVar1) {
    FUN_00532918(*(undefined4 *)(*(int *)(param_1 + 0x5e8) + 0x80),param_1 + 0xa44,0x14,0x14,param_3
                 ,param_2);
    iVar1 = FUN_00596728();
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)FUN_005a2750(local_8,&DAT_005b9ad3);
      FUN_005641c8(*puVar2);
      FUN_005a28c0(local_8,2);
    }
    else {
      iVar1 = FUN_00596728();
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)FUN_005a2750(local_c,&DAT_005b9af3);
        FUN_005641c8(*puVar2);
        FUN_005a28c0(local_c,2);
      }
    }
    *(undefined4 *)(param_1 + 0xa2c) = 1;
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 004d1374, recovered name Published_FormCreate_004d1374

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormCreate_004d1374(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  char local_458 [1028];
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined2 local_30;
  int local_24;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  local_48 = param_2;
  local_44 = param_1;
  FUN_00596a18(&DAT_005c1ff4);
  DAT_005c1f00 = (int *)FUN_0054bd6c(PTR_PTR_00545a1c,1);
  local_30 = 8;
  FUN_0040328c(&local_8);
  local_24 = local_24 + 1;
  local_30 = 0x14;
  (**(code **)(*DAT_005c1f00 + 0x40))
            (DAT_005c1f00,*(undefined4 *)(*(int *)(local_44 + 0x350) + 0x38));
  (**(code **)(*DAT_005c1f00 + 0x34))
            (DAT_005c1f00,*(undefined4 *)(*(int *)(local_44 + 0x350) + 0x3c));
  uVar1 = (**(code **)(*DAT_005c1f00 + 0x2c))();
  uVar2 = (**(code **)(*DAT_005c1f00 + 0x20))();
  uVar3 = FUN_0054c2d8(DAT_005c1f00);
  FUN_00547848(uVar3,0,0,uVar2,uVar1);
  local_30 = 0x2c;
  uVar1 = FUN_0040328c(local_c);
  local_24 = local_24 + 1;
  FUN_0055a58c(*(undefined4 *)PTR_DAT_005c9494,uVar1);
  FUN_00423b60(local_c);
  FUN_00596774();
  local_24 = local_24 + -1;
  FUN_005a28c0(local_c,2);
  local_4c = FUN_005967a4();
  local_30 = 0x20;
  for (local_54 = local_4c; local_458[local_54] != '\\'; local_54 = local_54 + -1) {
    local_50 = local_54;
  }
  local_458[local_50] = '\0';
  local_30 = 0x38;
  uVar1 = FUN_005a2750(local_10,local_458);
  local_24 = local_24 + 1;
  FUN_005a28f0(&local_8,uVar1);
  local_24 = local_24 + -1;
  FUN_005a28c0(local_10,2);
  local_30 = 0x44;
  uVar1 = FUN_0040328c(local_18);
  local_24 = local_24 + 1;
  FUN_005a2750(local_14,s_myres_chem_bmp_005c1f04);
  local_24 = local_24 + 1;
  FUN_005a2904(&local_8,local_14,uVar1);
  FUN_005a28f0(&local_8,local_18);
  local_24 = local_24 + -1;
  FUN_005a28c0(local_18,2);
  local_24 = local_24 + -1;
  FUN_005a28c0(local_14,2);
  (**(code **)(*DAT_005c1f00 + 0x48))(DAT_005c1f00,local_8);
  (**(code **)(*DAT_005c1f00 + 0x3c))(DAT_005c1f00,1);
  FUN_0054d444(DAT_005c1f00,0);
  local_30 = 0x14;
  _DAT_00ccfc80 = 0;
  FUN_004d1690(local_44);
  *(undefined4 *)(local_44 + 0x3f8) = 0x3f800000;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb6c) = 0x3f800000;
  *(undefined4 *)(local_44 + 0x408) = 0;
  *(undefined4 *)(local_44 + 0x418) = 0x3f800000;
  *(undefined4 *)(local_44 + 0x428) = 0x3f800000;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb7c) = 0;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb8c) = 0x3f800000;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb9c) = 0x3f800000;
  local_24 = local_24 + -1;
  FUN_005a28c0(&local_8,2);
  *in_FS_OFFSET = local_40;
  return;
}



// Entry 004d1634, recovered name Published_FormDestroy_004d1634

void Published_FormDestroy_004d1634(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  
  FUN_00596a18(&DAT_005c2060,param_2,param_3,param_2,param_1);
  if (DAT_005c1f00 != (int *)0x0) {
    (**(code **)(*DAT_005c1f00 + -4))(DAT_005c1f00,3);
  }
  DAT_005c1f00 = (int *)0x0;
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 004d1738, recovered name Published_ScrollBar1Change_004d1738

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar1Change_004d1738(int param_1)

{
  DAT_00ccfc80 = *(byte *)(*(int *)(param_1 + 0x354) + 500);
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb54) =
       (float)(_DAT_004d17d8 * (longdouble)DAT_00ccfc80);
  if (_DAT_004d17e4 < *(float *)(*(int *)PTR__Form1_005c9468 + 0xb54)) {
    *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb54) = 0x437f0000;
  }
  FUN_004d1690(param_1);
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb60) =
       (float)(_DAT_004d17e8 * (longdouble)*(int *)(*(int *)(param_1 + 0x300) + 500));
  return;
}



// Entry 004d17f4, recovered name Published_ScrollBar2Change_004d17f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar2Change_004d17f4(int param_1)

{
  DAT_00ccfc81 = *(byte *)(*(int *)(param_1 + 0x35c) + 500);
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb58) =
       (float)(_DAT_004d1894 * (longdouble)DAT_00ccfc81);
  if (_DAT_004d18a0 < *(float *)(*(int *)PTR__Form1_005c9468 + 0xb58)) {
    *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb58) = 0x437f0000;
  }
  FUN_004d1690(param_1);
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb64) =
       (float)(_DAT_004d18a4 * (longdouble)*(int *)(*(int *)(param_1 + 0x304) + 500));
  return;
}



// Entry 004d18b0, recovered name Published_ScrollBar3Change_004d18b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar3Change_004d18b0(int param_1)

{
  DAT_00ccfc82 = *(byte *)(*(int *)(param_1 + 0x364) + 500);
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb5c) =
       (float)(_DAT_004d1950 * (longdouble)DAT_00ccfc82);
  if (_DAT_004d195c < *(float *)(*(int *)PTR__Form1_005c9468 + 0xb5c)) {
    *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb5c) = 0x437f0000;
  }
  FUN_004d1690(param_1);
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb68) =
       (float)(_DAT_004d1960 * (longdouble)*(int *)(*(int *)(param_1 + 0x310) + 500));
  return;
}



// Entry 004d196c, recovered name Published_Label5Click_004d196c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label5Click_004d196c(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00569474(*(undefined4 *)(param_1 + 0x31c),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xaf4) =
         (float)(_DAT_004d1a20 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xaf8) =
         (float)(_DAT_004d1a20 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xafc) =
         (float)(_DAT_004d1a20 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004d1a2c, recovered name Published_Label7Click_004d1a2c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label7Click_004d1a2c(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00569474(*(undefined4 *)(param_1 + 0x324),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb00) =
         (float)(_DAT_004d1ae0 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb04) =
         (float)(_DAT_004d1ae0 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb08) =
         (float)(_DAT_004d1ae0 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004d1aec, recovered name Published_Label8Click_004d1aec

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label8Click_004d1aec(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00569474(*(undefined4 *)(param_1 + 0x334),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb24) =
         (float)(_DAT_004d1ba0 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb28) =
         (float)(_DAT_004d1ba0 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb2c) =
         (float)(_DAT_004d1ba0 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004d1bac, recovered name Published_Label9Click_004d1bac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label9Click_004d1bac(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00569474(*(undefined4 *)(param_1 + 0x33c),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb30) =
         (float)(_DAT_004d1c60 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb34) =
         (float)(_DAT_004d1c60 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb38) =
         (float)(_DAT_004d1c60 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004d1c6c, recovered name Published_Label6Click_004d1c6c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label6Click_004d1c6c(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00569474(*(undefined4 *)(param_1 + 0x32c),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb3c) =
         (float)(_DAT_004d1d20 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb40) =
         (float)(_DAT_004d1d20 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb44) =
         (float)(_DAT_004d1d20 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004d1d2c, recovered name Published_Label10Click_004d1d2c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label10Click_004d1d2c(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00569474(*(undefined4 *)(param_1 + 0x344),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb48) =
         (float)(_DAT_004d1de0 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb4c) =
         (float)(_DAT_004d1de0 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb50) =
         (float)(_DAT_004d1de0 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004d1dec, recovered name Published_SpeedButton1Click_004d1dec

void Published_SpeedButton1Click_004d1dec(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)PTR__Form1_005c9468;
  piVar1 = (int *)(iVar2 + 0xae4);
  *piVar1 = *piVar1 + 1;
  FUN_00556dd8(param_1,iVar2,param_3,param_2);
  return;
}



// Entry 004d1e14, recovered name Published_SpeedButton2Click_004d1e14

void Published_SpeedButton2Click_004d1e14(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x354),DAT_00ccfcf0,param_3,param_2);
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x35c),DAT_00ccfcf4);
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x364),DAT_00ccfcf8);
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x300),DAT_00ccfcfc);
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x304),DAT_00ccfd00);
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x310),DAT_00ccfd04);
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x2e4),DAT_00ccfd08);
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x2e8),DAT_00ccfd0c);
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x2ec),DAT_00ccfd10);
  FUN_00578898(*(undefined4 *)(param_1 + 0x374),DAT_00ccfd14);
  FUN_00578898(*(undefined4 *)(param_1 + 0x378),DAT_00ccfd18);
  FUN_00578898(*(undefined4 *)(param_1 + 0x37c),DAT_00ccfd1c);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb0c) = DAT_00ccfc9c;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb10) = DAT_00ccfca0;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb14) = DAT_00ccfca4;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb18) = DAT_00ccfca8;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb1c) = DAT_00ccfcac;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb20) = DAT_00ccfcb0;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xaf4) = DAT_00ccfc84;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xaf8) = DAT_00ccfc88;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xafc) = DAT_00ccfc8c;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb00) = DAT_00ccfc90;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb04) = DAT_00ccfc94;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb08) = DAT_00ccfc98;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb24) = DAT_00ccfcb4;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb28) = DAT_00ccfcb8;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb2c) = DAT_00ccfcbc;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb30) = DAT_00ccfcc0;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb34) = DAT_00ccfcc4;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb38) = DAT_00ccfcc8;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb3c) = DAT_00ccfccc;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb40) = DAT_00ccfcd0;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb44) = DAT_00ccfcd4;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb48) = DAT_00ccfcd8;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb4c) = DAT_00ccfcdc;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb50) = DAT_00ccfce0;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb54) = DAT_00ccfce4;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb58) = DAT_00ccfce8;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb5c) = DAT_00ccfcec;
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb60) = *(undefined4 *)(param_1 + 0x3ec);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb64) = *(undefined4 *)(param_1 + 0x3f0);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb68) = *(undefined4 *)(param_1 + 0x3f4);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb6c) = *(undefined4 *)(param_1 + 0x3f8);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb70) = *(undefined4 *)(param_1 + 0x3fc);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb74) = *(undefined4 *)(param_1 + 0x400);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb78) = *(undefined4 *)(param_1 + 0x404);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb7c) = *(undefined4 *)(param_1 + 0x408);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb80) = *(undefined4 *)(param_1 + 0x40c);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb84) = *(undefined4 *)(param_1 + 0x410);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb88) = *(undefined4 *)(param_1 + 0x414);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb8c) = *(undefined4 *)(param_1 + 0x418);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb90) = *(undefined4 *)(param_1 + 0x41c);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb94) = *(undefined4 *)(param_1 + 0x420);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb98) = *(undefined4 *)(param_1 + 0x424);
  *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xb9c) = *(undefined4 *)(param_1 + 0x428);
  FUN_00556dd8(param_1);
  return;
}



// Entry 004d2288, recovered name Published_FormShow_004d2288

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormShow_004d2288(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined2 local_10;
  
  DAT_00ccfcf0 = *(undefined4 *)(*(int *)(param_1 + 0x354) + 500);
  DAT_00ccfcf4 = *(undefined4 *)(*(int *)(param_1 + 0x35c) + 500);
  DAT_00ccfcf8 = *(undefined4 *)(*(int *)(param_1 + 0x364) + 500);
  DAT_00ccfcfc = *(undefined4 *)(*(int *)(param_1 + 0x300) + 500);
  DAT_00ccfd00 = *(undefined4 *)(*(int *)(param_1 + 0x304) + 500);
  DAT_00ccfd04 = *(undefined4 *)(*(int *)(param_1 + 0x310) + 500);
  DAT_00ccfd08 = *(undefined4 *)(*(int *)(param_1 + 0x2e4) + 500);
  DAT_00ccfd0c = *(undefined4 *)(*(int *)(param_1 + 0x2e8) + 500);
  DAT_00ccfd10 = *(undefined4 *)(*(int *)(param_1 + 0x2ec) + 500);
  DAT_00ccfd14 = *(undefined4 *)(*(int *)(param_1 + 0x374) + 0x210);
  DAT_00ccfd18 = *(undefined4 *)(*(int *)(param_1 + 0x378) + 0x210);
  DAT_00ccfd1c = *(undefined4 *)(*(int *)(param_1 + 0x37c) + 0x210);
  bVar1 = *(byte *)(*(int *)(param_1 + 0x35c) + 500);
  local_10 = CONCAT11(bVar1,*(undefined1 *)(*(int *)(param_1 + 0x354) + 500));
  DAT_00ccfce4 = (float)(_DAT_004d2a14 * (longdouble)(local_10 & 0xff));
  DAT_00ccfce8 = (float)(_DAT_004d2a14 * (longdouble)bVar1);
  DAT_00ccfcec = (float)(_DAT_004d2a14 * (longdouble)*(byte *)(*(int *)(param_1 + 0x364) + 500));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x3ac) + 0x60);
  DAT_00ccfc9c = (float)(_DAT_004d2a14 * (longdouble)(uVar2 & 0xff));
  DAT_00ccfca0 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00ccfca4 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x3b0) + 0x60);
  DAT_00ccfca8 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 & 0xff));
  DAT_00ccfcac = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00ccfcb0 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x31c) + 0x60);
  DAT_00ccfc84 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 & 0xff));
  DAT_00ccfc88 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00ccfc8c = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x324) + 0x60);
  DAT_00ccfc90 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 & 0xff));
  DAT_00ccfc94 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00ccfc98 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x334) + 0x60);
  DAT_00ccfcb4 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 & 0xff));
  DAT_00ccfcb8 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00ccfcbc = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x33c) + 0x60);
  DAT_00ccfcc0 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 & 0xff));
  DAT_00ccfcc4 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00ccfcc8 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x32c) + 0x60);
  DAT_00ccfccc = (float)(_DAT_004d2a14 * (longdouble)(uVar2 & 0xff));
  DAT_00ccfcd0 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00ccfcd4 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x344) + 0x60);
  DAT_00ccfcd8 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 & 0xff));
  DAT_00ccfcdc = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00ccfce0 = (float)(_DAT_004d2a14 * (longdouble)(uVar2 >> 0x10 & 0xff));
  *(float *)(param_1 + 0x3ec) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x300) + 500));
  *(float *)(param_1 + 0x3f0) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x304) + 500));
  *(float *)(param_1 + 0x3f4) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x310) + 500));
  *(float *)(param_1 + 0x40c) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(param_1 + 0x410) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(param_1 + 0x414) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(param_1 + 0x41c) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(param_1 + 0x420) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(param_1 + 0x424) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(param_1 + 0x3fc) = (float)*(int *)(*(int *)(param_1 + 0x374) + 0x210) - _DAT_004d2a2c;
  *(float *)(param_1 + 0x400) = (float)*(int *)(*(int *)(param_1 + 0x378) + 0x210) - _DAT_004d2a2c;
  *(float *)(param_1 + 0x404) = (float)*(int *)(*(int *)(param_1 + 0x37c) + 0x210) - _DAT_004d2a2c;
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb60) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x300) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb64) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x304) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb68) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x310) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb80) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb84) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb88) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb90) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb94) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb98) =
       (float)(_DAT_004d2a20 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb70) =
       (float)*(int *)(*(int *)(param_1 + 0x374) + 0x210) - _DAT_004d2a2c;
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb74) =
       (float)*(int *)(*(int *)(param_1 + 0x378) + 0x210) - _DAT_004d2a2c;
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb78) =
       (float)*(int *)(*(int *)(param_1 + 0x37c) + 0x210) - _DAT_004d2a2c;
  return;
}



// Entry 004d2a30, recovered name Published_ScrollBar7Change_004d2a30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar7Change_004d2a30(int param_1)

{
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb80) =
       (float)(_DAT_004d2a8c * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb90) =
       (float)(_DAT_004d2a8c * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  return;
}



// Entry 004d2a98, recovered name Published_ScrollBar8Change_004d2a98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar8Change_004d2a98(int param_1)

{
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb84) =
       (float)(_DAT_004d2af4 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb94) =
       (float)(_DAT_004d2af4 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  return;
}



// Entry 004d2b00, recovered name Published_ScrollBar9Change_004d2b00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar9Change_004d2b00(int param_1)

{
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb88) =
       (float)(_DAT_004d2b5c * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb98) =
       (float)(_DAT_004d2b5c * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  return;
}



// Entry 004d2b68, recovered name Published_TrackBar1Change_004d2b68

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_TrackBar1Change_004d2b68(int param_1)

{
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb70) =
       (float)*(int *)(*(int *)(param_1 + 0x374) + 0x210) - _DAT_004d2b9c;
  return;
}



// Entry 004d2ba0, recovered name Published_TrackBar2Change_004d2ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_TrackBar2Change_004d2ba0(int param_1)

{
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb74) =
       (float)*(int *)(*(int *)(param_1 + 0x378) + 0x210) - _DAT_004d2bd4;
  return;
}



// Entry 004d2bd8, recovered name Published_TrackBar3Change_004d2bd8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_TrackBar3Change_004d2bd8(int param_1)

{
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xb78) =
       (float)*(int *)(*(int *)(param_1 + 0x37c) + 0x210) - _DAT_004d2c0c;
  return;
}



// Entry 004d2c10, recovered name Published_Label32Click_004d2c10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label32Click_004d2c10(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00569474(*(undefined4 *)(param_1 + 0x3ac),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb0c) =
         (float)(_DAT_004d2cc4 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb10) =
         (float)(_DAT_004d2cc4 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb14) =
         (float)(_DAT_004d2cc4 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004d2cd0, recovered name Published_Label33Click_004d2cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label33Click_004d2cd0(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00569474(*(undefined4 *)(param_1 + 0x3b0),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb18) =
         (float)(_DAT_004d2d84 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb1c) =
         (float)(_DAT_004d2d84 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_005c9468 + 0xb20) =
         (float)(_DAT_004d2d84 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004d2ee0, recovered name Published_SpeedButton1Click_004d2ee0

void Published_SpeedButton1Click_004d2ee0(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar3;
  undefined4 *in_FS_OFFSET;
  char acStack_45c [1028];
  int iStack_58;
  int iStack_54;
  undefined2 uStack_4e;
  undefined4 uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined2 uStack_34;
  short sStack_32;
  int iStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  
  uStack_4c = param_2;
  iStack_48 = param_1;
  FUN_00596a18(0x5c2880);
  *(undefined1 *)(iStack_48 + 0x2fd) = 1;
  uStack_4e = *(undefined2 *)(*(int *)PTR_DAT_005c9498 + 0x38);
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xfff5);
  uStack_34 = 0x14;
  FUN_005a2810(auStack_8,0);
  iStack_28 = iStack_28 + 1;
  cVar1 = FUN_005a29a8(*(int *)PTR__Form1_005c9468 + 0xba0,auStack_8);
  iStack_28 = iStack_28 + -1;
  FUN_005a28c0(auStack_8,2);
  if (cVar1 == '\0') {
    uStack_34 = 0x20;
    FUN_0040328c(auStack_c);
    iStack_28 = iStack_28 + 1;
    uStack_34 = 0x38;
    uVar2 = FUN_0040328c(auStack_10);
    iStack_28 = iStack_28 + 1;
    FUN_0055a58c(*(undefined4 *)PTR_DAT_005c9494,uVar2);
    FUN_00423b60(auStack_10);
    FUN_00596774();
    iStack_28 = iStack_28 + -1;
    FUN_005a28c0(auStack_10,2);
    iStack_58 = FUN_005967a4();
    for (iStack_54 = iStack_58; acStack_45c[iStack_54] != '\\'; iStack_54 = iStack_54 + -1) {
    }
    acStack_45c[iStack_54] = '\0';
    uStack_34 = 0x44;
    uVar2 = FUN_005a2750(auStack_14,acStack_45c);
    iStack_28 = iStack_28 + 1;
    FUN_005a28f0(auStack_c,uVar2);
    iStack_28 = iStack_28 + -1;
    FUN_005a28c0(auStack_14,2);
    uStack_34 = 0x50;
    uVar2 = FUN_0040328c(&uStack_1c);
    iStack_28 = iStack_28 + 1;
    FUN_005a2750(auStack_18,0x5c27d4);
    iStack_28 = iStack_28 + 1;
    FUN_005a2904(auStack_c,auStack_18,uVar2);
    FUN_00562c84(*(undefined4 *)(*(int *)PTR__Form1_005c9468 + 900),uStack_1c);
    iStack_28 = iStack_28 + -1;
    FUN_005a28c0(&uStack_1c,2);
    iStack_28 = iStack_28 + -1;
    FUN_005a28c0(auStack_18,2);
    cVar1 = (**(code **)(**(int **)(*(int *)PTR__Form1_005c9468 + 900) + 0x3c))();
    if (cVar1 == '\0') {
      *(undefined1 *)(_SaveFileForm + 0x2fc) = 1;
    }
    else {
      uStack_34 = 0x5c;
      uVar2 = FUN_0040328c(&uStack_20);
      iStack_28 = iStack_28 + 1;
      FUN_00562c1c(*(undefined4 *)(*(int *)PTR__Form1_005c9468 + 900),uVar2);
      FUN_0041fe4c(*(undefined4 *)PTR__Form1_005c9468,uStack_20);
      iStack_28 = iStack_28 + -1;
      FUN_005a28c0(&uStack_20,2);
    }
    iStack_28 = iStack_28 + -1;
    FUN_005a28c0(auStack_c,2);
    uVar3 = extraout_var_00;
  }
  else {
    FUN_0041fe4c(*(undefined4 *)PTR__Form1_005c9468,
                 *(undefined4 *)(*(int *)PTR__Form1_005c9468 + 0xba0));
    uVar3 = extraout_var;
  }
  uStack_34 = 0;
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,CONCAT22(uVar3,uStack_4e));
  if (sStack_32 != 0) {
    return;
  }
  FUN_00556dd8(iStack_48);
  *in_FS_OFFSET = uStack_44;
  return;
}



// Entry 004d3180, recovered name Published_SpeedButton2Click_004d3180

void Published_SpeedButton2Click_004d3180(int param_1,undefined4 param_2)

{
  *(undefined1 *)(param_1 + 0x2fe) = 1;
  *(undefined1 *)(param_1 + 0x2fc) = 0;
  *(undefined1 *)(param_1 + 0x2fd) = 0;
  FUN_00556dd8(param_1,param_1,param_1,param_2);
  return;
}



// Entry 004d31b8, recovered name Published_SpeedButton3Click_004d31b8

void Published_SpeedButton3Click_004d31b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined1 *)(param_1 + 0x2fc) = 1;
  FUN_00556dd8(param_1,param_2,param_3,param_2);
  return;
}



// Entry 004d31dc, recovered name Published_FormClose_004d31dc

void Published_FormClose_004d31dc(int param_1,undefined4 param_2,undefined1 *param_3)

{
  if (((*(char *)(param_1 + 0x2fd) == '\0') && (*(char *)(param_1 + 0x2fc) == '\0')) &&
     (*(char *)(param_1 + 0x2fe) == '\0')) {
    *(undefined1 *)(param_1 + 0x2fc) = 1;
    *param_3 = 1;
  }
  return;
}



// Entry 004d3400, recovered name Published_SpeedButton1Click_004d3400

void Published_SpeedButton1Click_004d3400(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005c2d54,param_2,param_3,param_2);
  puVar1 = (undefined4 *)FUN_005a2750(local_8,&DAT_005c2d08);
  FUN_00569318(*(undefined4 *)(param_1 + 0x2dc),*puVar1);
  FUN_005a28c0(local_8,2);
  puVar1 = (undefined4 *)FUN_005a2750(local_c,0x5c2d09);
  FUN_00569318(*(undefined4 *)(param_1 + 0x2e0),*puVar1);
  FUN_005a28c0(local_c,2);
  FUN_00556dd8(param_1);
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 004d3498, recovered name Published_Image1MouseDown_004d3498

void Published_Image1MouseDown_004d3498(int param_1)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005c2d94);
  puVar1 = (undefined4 *)FUN_005a2750(local_8,0x5c2d0a);
  FUN_00569318(*(undefined4 *)(param_1 + 0x2dc),*puVar1);
  FUN_005a28c0(local_8,2);
  puVar1 = (undefined4 *)FUN_005a2750(local_c,0x5c2d0b);
  FUN_00569318(*(undefined4 *)(param_1 + 0x2e0),*puVar1);
  FUN_005a28c0(local_c,2);
  FUN_00556dd8(param_1);
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 004d3538, recovered name Published_FormKeyPress_004d3538

void Published_FormKeyPress_004d3538(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005c2dd4,param_2,param_3,param_3,param_2);
  puVar1 = (undefined4 *)FUN_005a2750(local_8,&DAT_005c2d0c);
  FUN_00569318(*(undefined4 *)(param_1 + 0x2dc),*puVar1);
  FUN_005a28c0(local_8,2);
  puVar1 = (undefined4 *)FUN_005a2750(local_c,&DAT_005c2d0d);
  FUN_00569318(*(undefined4 *)(param_1 + 0x2e0),*puVar1);
  FUN_005a28c0(local_c,2);
  FUN_00556dd8(param_1);
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 004d3684, recovered name Published_FormClose_004d3684

void Published_FormClose_004d3684(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00578e98(*(undefined4 *)(param_1 + 0x2d0),0,param_3,param_3,param_2);
  return;
}



// Entry 004d3a14, recovered name Published_FormCreate_004d3a14

void Published_FormCreate_004d3a14(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004d382c(param_1,param_2,param_3,param_2);
  return;
}



// Entry 004d3a2c, recovered name Published_FileListBox1DblClick_004d3a2c

void Published_FileListBox1DblClick_004d3a2c(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *in_FS_OFFSET;
  int local_8c;
  int local_80;
  int local_74;
  int local_70;
  undefined4 local_64;
  undefined1 local_38 [8];
  undefined4 local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  FUN_00596a18(&DAT_005c33f0);
  local_70 = 0;
  for (local_74 = 0; iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x2d0) + 0x1f0) + 0x14))(),
      local_74 < iVar2; local_74 = local_74 + 1) {
    cVar1 = FUN_0053cc68(*(undefined4 *)(param_1 + 0x2d0),local_74);
    if (cVar1 != '\0') {
      if (4 < local_70 + 1) break;
      iVar2 = *(int *)(param_1 + 0x2d0);
      uVar3 = FUN_0040328c(local_c);
      piVar4 = *(int **)(iVar2 + 0x1f0);
      (**(code **)(*piVar4 + 0xc))(piVar4,local_74,uVar3);
      uVar3 = FUN_0040328c(local_10);
      FUN_005a2904(local_70 * 4 + param_1 + 0x2ec,local_c,uVar3);
      FUN_005a28f0(local_70 * 4 + param_1 + 0x2ec,local_10);
      FUN_005a28c0(local_10,2);
      FUN_005a28c0(local_c,2);
      local_70 = local_70 + 1;
    }
  }
  *(int *)(param_1 + 0x2fc) = local_70;
  FUN_0040328c(&local_8);
  FUN_005a2750(local_14,&DAT_005c3183);
  FUN_005a28f0(&local_8,local_14);
  FUN_005a28c0(local_14,2);
  for (local_80 = 0; local_80 < *(int *)(param_1 + 0x2fc); local_80 = local_80 + 1) {
    uVar3 = FUN_0040328c(local_1c);
    FUN_005a2750(local_18,&DAT_005c31a2);
    FUN_005a2904(&local_8,local_18,uVar3);
    uVar3 = FUN_0040328c(local_20);
    FUN_005a2904(local_1c,local_80 * 4 + param_1 + 0x2ec,uVar3);
    FUN_005a28f0(&local_8,local_20);
    FUN_005a28c0(local_20,2);
    FUN_005a28c0(local_1c,2);
    FUN_005a28c0(local_18,2);
  }
  uVar3 = FUN_0040328c(local_28);
  FUN_005a2750(local_24,&DAT_005c31a4);
  FUN_005a2904(&local_8,local_24,uVar3);
  FUN_005a28f0(&local_8,local_28);
  FUN_005a28c0(local_28,2);
  FUN_005a28c0(local_24,2);
  FUN_00569318(*(undefined4 *)PTR__Form1_005c9468,local_8);
  FUN_005a2810(local_2c,0);
  FUN_005a28f0(*(int *)PTR__Form1_005c9468 + 0xba0,local_2c);
  FUN_005a28c0(local_2c,2);
  piVar4 = (int *)FUN_00423848(PTR_PTR_00580cd4,1);
  local_8c = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x2fc) <= local_8c) {
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + -4))(piVar4,3);
      }
      *(undefined1 *)(param_1 + 0x300) = 1;
      FUN_00556dd8(param_1);
      FUN_005a28c0(&local_8,2);
      *in_FS_OFFSET = local_64;
      return;
    }
    (**(code **)(*piVar4 + 0x40))();
    (**(code **)(*piVar4 + 0x58))(piVar4,*(undefined4 *)(param_1 + 0x2ec + local_8c * 4));
    uVar3 = FUN_0040328c(&local_30);
    (**(code **)(*piVar4 + 0xc))(piVar4,0,uVar3);
    iVar2 = FUN_0058d1e8(local_30);
    FUN_005a28c0(&local_30,2);
    if (iVar2 != 0x83b) break;
    local_8c = local_8c + 1;
  }
  puVar5 = (undefined4 *)FUN_005a2750(local_38,&DAT_005c31c2);
  FUN_005641c8(*puVar5);
  FUN_005a28c0(local_38,2);
  FUN_005a28c0(&local_8,2);
  *in_FS_OFFSET = local_64;
  return;
}



// Entry 004d3eb0, recovered name Published_FormShow_004d3eb0

void Published_FormShow_004d3eb0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  int iVar2;
  undefined4 local_30;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005c34b0);
  *(undefined1 *)(param_1 + 0x300) = 0;
  for (iVar2 = 0; iVar2 < *(int *)(param_1 + 0x2fc); iVar2 = iVar2 + 1) {
    uVar1 = FUN_0040328c(local_c);
    FUN_005a2750(local_8,&DAT_005c31dd);
    FUN_005a2904(*(int *)(param_1 + 0x2d0) + 0x238,local_8,uVar1,iVar2,param_2);
    FUN_005a28f0(iVar2 * 4 + param_1 + 0x2ec,local_c);
    FUN_005a28c0(local_c,2);
    FUN_005a28c0(local_8,2);
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 004d3f68, recovered name Published_SpeedButton2Click_004d3f68

void Published_SpeedButton2Click_004d3f68(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined1 *)(param_1 + 0x300) = 0;
  FUN_00556dd8(param_1,param_2,param_3,param_2);
  return;
}



// Entry 004d3f8c, recovered name Published_SpeedButton1Click_004d3f8c

void Published_SpeedButton1Click_004d3f8c(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *in_FS_OFFSET;
  int local_8c;
  int local_80;
  int local_74;
  int local_70;
  undefined4 local_64;
  undefined1 local_38 [8];
  undefined4 local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  FUN_00596a18(&DAT_005c35c4);
  local_70 = 0;
  for (local_74 = 0; iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x2d0) + 0x1f0) + 0x14))(),
      local_74 < iVar2; local_74 = local_74 + 1) {
    cVar1 = FUN_0053cc68(*(undefined4 *)(param_1 + 0x2d0),local_74);
    if (cVar1 != '\0') {
      if (4 < local_70 + 1) break;
      iVar2 = *(int *)(param_1 + 0x2d0);
      uVar3 = FUN_0040328c(local_c);
      piVar4 = *(int **)(iVar2 + 0x1f0);
      (**(code **)(*piVar4 + 0xc))(piVar4,local_74,uVar3);
      uVar3 = FUN_0040328c(local_10);
      FUN_005a2904(local_70 * 4 + param_1 + 0x2ec,local_c,uVar3);
      FUN_005a28f0(local_70 * 4 + param_1 + 0x2ec,local_10);
      FUN_005a28c0(local_10,2);
      FUN_005a28c0(local_c,2);
      local_70 = local_70 + 1;
    }
  }
  *(int *)(param_1 + 0x2fc) = local_70;
  FUN_0040328c(&local_8);
  FUN_005a2750(local_14,&DAT_005c31df);
  FUN_005a28f0(&local_8,local_14);
  FUN_005a28c0(local_14,2);
  for (local_80 = 0; local_80 < *(int *)(param_1 + 0x2fc); local_80 = local_80 + 1) {
    uVar3 = FUN_0040328c(local_1c);
    FUN_005a2750(local_18,&DAT_005c31fe);
    FUN_005a2904(&local_8,local_18,uVar3);
    uVar3 = FUN_0040328c(local_20);
    FUN_005a2904(local_1c,local_80 * 4 + param_1 + 0x2ec,uVar3);
    FUN_005a28f0(&local_8,local_20);
    FUN_005a28c0(local_20,2);
    FUN_005a28c0(local_1c,2);
    FUN_005a28c0(local_18,2);
  }
  uVar3 = FUN_0040328c(local_28);
  FUN_005a2750(local_24,&DAT_005c3200);
  FUN_005a2904(&local_8,local_24,uVar3);
  FUN_005a28f0(&local_8,local_28);
  FUN_005a28c0(local_28,2);
  FUN_005a28c0(local_24,2);
  FUN_00569318(*(undefined4 *)PTR__Form1_005c9468,local_8);
  FUN_005a2810(local_2c,0);
  FUN_005a28f0(*(int *)PTR__Form1_005c9468 + 0xba0,local_2c);
  FUN_005a28c0(local_2c,2);
  piVar4 = (int *)FUN_00423848(PTR_PTR_00580cd4,1);
  local_8c = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x2fc) <= local_8c) {
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + -4))(piVar4,3);
      }
      *(undefined1 *)(param_1 + 0x300) = 1;
      FUN_00556dd8(param_1);
      FUN_005a28c0(&local_8,2);
      *in_FS_OFFSET = local_64;
      return;
    }
    (**(code **)(*piVar4 + 0x40))();
    (**(code **)(*piVar4 + 0x58))(piVar4,*(undefined4 *)(param_1 + 0x2ec + local_8c * 4));
    uVar3 = FUN_0040328c(&local_30);
    (**(code **)(*piVar4 + 0xc))(piVar4,0,uVar3);
    iVar2 = FUN_0058d1e8(local_30);
    FUN_005a28c0(&local_30,2);
    if (iVar2 != 0x83b) break;
    local_8c = local_8c + 1;
  }
  puVar5 = (undefined4 *)FUN_005a2750(local_38,&DAT_005c321e);
  FUN_005641c8(*puVar5);
  FUN_005a28c0(local_38,2);
  FUN_005a28c0(&local_8,2);
  *in_FS_OFFSET = local_64;
  return;
}



// Entry 004d45c4, recovered name Published_SpeedButton1Click_004d45c4

void Published_SpeedButton1Click_004d45c4(undefined4 param_1,undefined4 param_2)

{
  Published_N84Click_00432a28(*(undefined4 *)PTR__Form1_005c9468,param_2);
  FUN_00556dd8(param_1);
  return;
}



// Entry 004d45ec, recovered name Published_SpeedButton2Click_004d45ec

void Published_SpeedButton2Click_004d45ec(undefined4 param_1,undefined4 param_2)

{
  Published_N85Click_00432c98(*(undefined4 *)PTR__Form1_005c9468,param_2);
  FUN_00556dd8(param_1);
  return;
}



// Entry 004d4614, recovered name Published_SpeedButton3Click_004d4614

void Published_SpeedButton3Click_004d4614(undefined4 param_1,undefined4 param_2)

{
  Published_N86Click_00432f08(*(undefined4 *)PTR__Form1_005c9468,param_2);
  FUN_00556dd8(param_1);
  return;
}



// Entry 004d463c, recovered name Published_SpeedButton4Click_004d463c

void Published_SpeedButton4Click_004d463c(undefined4 param_1,undefined4 param_2)

{
  Published_N87Click_00433178(*(undefined4 *)PTR__Form1_005c9468,param_2);
  FUN_00556dd8(param_1);
  return;
}



// Entry 004d4664, recovered name Published_Panel1MouseMove_004d4664

void Published_Panel1MouseMove_004d4664(void)

{
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,0xffeb);
  return;
}



// Entry 004d468c, recovered name Published_FormClose_004d468c

void Published_FormClose_004d468c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00558318(*(undefined4 *)PTR_DAT_005c9498,1,param_3,param_3,param_2,param_1);
  return;
}



// Entry 0052ca78, recovered name Published_FormShow_0052ca78

void Published_FormShow_0052ca78(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0059b0c4();
  FUN_0053d8a0(*(undefined4 *)(param_1 + 0x2dc),uVar1,param_1,param_2);
  return;
}



// Entry 0052caac, recovered name Published_SpeedButton2Click_0052caac

void Published_SpeedButton2Click_0052caac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00556dd8(param_1,param_2,param_3,param_2);
  return;
}



// Entry 0052cac4, recovered name Published_SpeedButton1Click_0052cac4

void Published_SpeedButton1Click_0052cac4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = PTR__Form1_005c9468;
  iVar1 = *(int *)(param_1 + 0x2dc);
  *(float *)(*(int *)PTR__Form1_005c9468 + 0xaec) = (float)*(int *)(iVar1 + 500);
  FUN_00556dd8(param_1,iVar1,puVar2,param_2);
  return;
}



// Entry 0052cc4c, recovered name Published_SpeedButton1Click_0052cc4c

void Published_SpeedButton1Click_0052cc4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 local_34;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00596a18(&DAT_005c42ec,param_2,param_3,param_2);
  uVar2 = FUN_0040328c(local_8);
  FUN_005692e8(*(undefined4 *)(param_1 + 0x2d0),uVar2);
  FUN_005a2750(local_c,&DAT_005c4288);
  cVar1 = FUN_005a2990(local_8,local_c);
  FUN_005a28c0(local_c,2);
  FUN_005a28c0(local_8,2);
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x2ec) = 1;
    FUN_00556dd8(param_1);
    *in_FS_OFFSET = local_34;
  }
  else {
    puVar3 = (undefined4 *)FUN_005a2750(local_10,&DAT_005c4289);
    FUN_005641c8(*puVar3);
    FUN_005a28c0(local_10,2);
    (**(code **)(**(int **)(param_1 + 0x2d0) + 0xb0))();
    *in_FS_OFFSET = local_34;
  }
  return;
}



// Entry 0052cd30, recovered name Published_SpeedButton2Click_0052cd30

void Published_SpeedButton2Click_0052cd30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00556dd8(param_1,param_2,param_3,param_2);
  return;
}



// Entry 0052cd48, recovered name Published_FormShow_0052cd48

void Published_FormShow_0052cd48(int param_1)

{
  *(undefined1 *)(param_1 + 0x2ec) = 0;
  return;
}



// Entry 0052cd64, recovered name Published_Edit1KeyPress_0052cd64

void Published_Edit1KeyPress_0052cd64(undefined4 param_1,undefined4 param_2,char *param_3)

{
  if (*param_3 == '\r') {
    Published_SpeedButton1Click_0052cc4c(param_1,param_2);
  }
  return;
}



