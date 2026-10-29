/* GHIDRA PSEUDOCODE FOR PUBLISHED METHOD ENTRIES; NOT ORIGINAL/BUILDABLE SOURCE.
Metadata-seeded entries supplement default analysis. Names preserve published names
with synthetic prefix and address suffix; original class ownership/signatures unknown.
SHA256: 6b1e97cc92b87d79a1062f1b45f0f974b762c9415f226b4261c9ae7309e201c7 */

// Entry 00402698, recovered name Published_FormCreate_00402698

void Published_FormCreate_00402698(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  float fVar3;
  float fVar4;
  undefined4 local_2c;
  undefined1 local_8 [4];
  
  FUN_004aa20c(&DAT_004ca720);
  *(undefined4 *)(param_1 + 0x38c) = 0x41c80000;
  *(undefined4 *)(param_1 + 0x390) = 0x41700000;
  *(undefined4 *)(param_1 + 0x3f4) = 0;
  *(undefined4 *)(param_1 + 0x3f8) = 0;
  *(undefined4 *)(param_1 + 0x3fc) = 0;
  *(undefined4 *)(param_1 + 0x3c4) = 0x3f0ccccd;
  *(undefined4 *)(param_1 + 0x3c8) = 0x3f3ae148;
  *(undefined4 *)(param_1 + 0x3cc) = 0x3e19999a;
  *(undefined4 *)(param_1 + 0x3d0) = 0x3f3d70a4;
  *(undefined4 *)(param_1 + 0x3d4) = 0x3f1c28f6;
  *(undefined4 *)(param_1 + 0x3d8) = 0x3da3d70a;
  *(undefined4 *)(param_1 + 0x3dc) = 0x3f70a3d7;
  *(undefined4 *)(param_1 + 0x3e0) = 0x3f0ccccd;
  *(undefined4 *)(param_1 + 0x3e4) = 0x3d23d70a;
  *(undefined4 *)(param_1 + 0x394) = 0x3e800000;
  *(undefined4 *)(param_1 + 0x398) = 0x3e570a3d;
  *(undefined4 *)(param_1 + 0x39c) = 0x3e19999a;
  *(undefined4 *)(param_1 + 0x3a0) = 0x3e8a3d71;
  *(undefined4 *)(param_1 + 0x3a4) = 0x3f5eb852;
  *(undefined4 *)(param_1 + 0x3a8) = 0x3f2e147b;
  *(undefined4 *)(param_1 + 0x3ac) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0x3b0) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0x3b4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3b8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3bc) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0x3c0) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 1000) = 0x3f3fbe77;
  *(undefined4 *)(param_1 + 0x3ec) = 0x3ec49ba6;
  *(undefined4 *)(param_1 + 0x3f0) = 0x3d50e560;
  *(undefined4 *)(param_1 + 0x400) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0x404) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0x408) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0x40c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x450) = 0x3f800000;
  FUN_004c8d80(local_8,0);
  FUN_004c8df4(param_1 + 0x440,local_8);
  FUN_004c8dc4(local_8,2);
  fVar4 = (float)*(int *)(_Form1 + 0x38);
  iVar2 = *(int *)(_Form1 + 0x3c) + -10;
  fVar3 = (float)iVar2;
  uVar1 = FUN_00487764(param_1,iVar2,_Form1,fVar3,fVar4);
  DAT_004d2574 = FUN_0042a498(PTR_DAT_004cd0b8,1,uVar1,fVar3,fVar4);
  FUN_0042acf4(DAT_004d2574);
  FUN_0042ad14(DAT_004d2574,0);
  *(undefined4 *)(DAT_004d2574 + 0x88c) = *(undefined4 *)(param_1 + 0x3f4);
  *(undefined4 *)(DAT_004d2574 + 0x890) = *(undefined4 *)(param_1 + 0x3f8);
  *(undefined4 *)(DAT_004d2574 + 0x894) = *(undefined4 *)(param_1 + 0x3fc);
  DAT_004d2578 = FUN_00429528(PTR_DAT_004cd1b4,1,0);
  *(undefined4 *)(DAT_004d2578 + 0x38) = 0x3f800000;
  *(undefined4 *)(DAT_004d2578 + 0x3c) = 0x3f800000;
  *(undefined4 *)(DAT_004d2578 + 0x40) = 0x3f800000;
  *(undefined4 *)(DAT_004d2578 + 0x44) = 0;
  *(undefined4 *)(DAT_004d2578 + 0x18) = 0x3f666666;
  *(undefined4 *)(DAT_004d2578 + 0x1c) = 0x3f666666;
  *(undefined4 *)(DAT_004d2578 + 0x20) = 0x3f666666;
  *(undefined4 *)(DAT_004d2578 + 0x24) = 0x3f800000;
  *(undefined4 *)(DAT_004d2578 + 0x28) = 0x3f666666;
  *(undefined4 *)(DAT_004d2578 + 0x2c) = 0x3f666666;
  *(undefined4 *)(DAT_004d2578 + 0x30) = 0x3f666666;
  *(undefined4 *)(DAT_004d2578 + 0x34) = 0x3f800000;
  FUN_0042972c(DAT_004d2578);
  FUN_0042add8(DAT_004d2574,DAT_004d2578);
  *(undefined4 *)(param_1 + 0x410) = *(undefined4 *)(DAT_004d2578 + 0x38);
  *(undefined4 *)(param_1 + 0x414) = *(undefined4 *)(DAT_004d2578 + 0x3c);
  *(undefined4 *)(param_1 + 0x418) = *(undefined4 *)(DAT_004d2578 + 0x40);
  *(undefined4 *)(param_1 + 0x41c) = *(undefined4 *)(DAT_004d2578 + 0x44);
  *(undefined4 *)(param_1 + 0x420) = *(undefined4 *)(DAT_004d2578 + 0x18);
  *(undefined4 *)(param_1 + 0x424) = *(undefined4 *)(DAT_004d2578 + 0x1c);
  *(undefined4 *)(param_1 + 0x428) = *(undefined4 *)(DAT_004d2578 + 0x20);
  *(undefined4 *)(param_1 + 0x42c) = *(undefined4 *)(DAT_004d2578 + 0x24);
  *(undefined4 *)(param_1 + 0x430) = *(undefined4 *)(DAT_004d2578 + 0x28);
  *(undefined4 *)(param_1 + 0x434) = *(undefined4 *)(DAT_004d2578 + 0x2c);
  *(undefined4 *)(param_1 + 0x438) = *(undefined4 *)(DAT_004d2578 + 0x30);
  *(undefined4 *)(param_1 + 0x43c) = *(undefined4 *)(DAT_004d2578 + 0x34);
  *(undefined1 *)(param_1 + 0x375) = 1;
  *in_FS_OFFSET = local_2c;
  return;
}



// Entry 00402c40, recovered name Published_FormPaint_00402c40

void Published_FormPaint_00402c40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0042b040(DAT_004d2574,param_2,param_3,param_2,param_1);
  return;
}



// Entry 00402c5c, recovered name Published_FormKeyDown_00402c5c

void Published_FormKeyDown_00402c5c(int param_1,undefined4 param_2,short *param_3)

{
  float fVar1;
  
  if (*param_3 == 0x41) {
    Published_N43Click_00420014(param_1,param_2);
  }
  else if (*param_3 == 0x53) {
    Published_N44Click_004200e4(param_1,param_2);
  }
  else if (*param_3 == 0x20) {
    Published_N54Click_00420ae8(param_1,param_2);
  }
  else {
    fVar1 = *(float *)(DAT_004d2574 + 0x87c);
    if (*param_3 == 0x26) {
      *(float *)(DAT_004d2574 + 0x86c) = *(float *)(DAT_004d2574 + 0x86c) - fVar1;
      *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
    }
    if (*param_3 == 0x28) {
      *(float *)(DAT_004d2574 + 0x86c) = *(float *)(DAT_004d2574 + 0x86c) + fVar1;
      *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
    }
    if (*param_3 == 0x25) {
      if (((*(float *)(DAT_004d2574 + 0x86c) < 90.0) && (0.0 <= *(float *)(DAT_004d2574 + 0x86c)))
         || ((*(float *)(DAT_004d2574 + 0x86c) < 360.0 && (270.0 < *(float *)(DAT_004d2574 + 0x86c))
             ))) {
        *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) - fVar1;
      }
      else {
        *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) + fVar1;
      }
      *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
    }
    if (*param_3 == 0x27) {
      if (((*(float *)(DAT_004d2574 + 0x86c) < 90.0) && (0.0 <= *(float *)(DAT_004d2574 + 0x86c)))
         || ((*(float *)(DAT_004d2574 + 0x86c) < 360.0 && (270.0 < *(float *)(DAT_004d2574 + 0x86c))
             ))) {
        *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) + fVar1;
      }
      else {
        *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) - fVar1;
      }
      *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
    }
    if (360.0 < *(float *)(DAT_004d2574 + 0x870)) {
      *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) - 360.0;
    }
    if (*(float *)(DAT_004d2574 + 0x870) < 0.0) {
      *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) + 360.0;
    }
    if (360.0 < *(float *)(DAT_004d2574 + 0x86c)) {
      *(float *)(DAT_004d2574 + 0x86c) = *(float *)(DAT_004d2574 + 0x86c) - 360.0;
    }
    if (*(float *)(DAT_004d2574 + 0x86c) < 0.0) {
      *(float *)(DAT_004d2574 + 0x86c) = *(float *)(DAT_004d2574 + 0x86c) + 360.0;
    }
  }
  return;
}



// Entry 00402f58, recovered name Published_FormResize_00402f58

void Published_FormResize_00402f58(int param_1)

{
  int iVar1;
  
  if (DAT_004d2574 != 0) {
    iVar1 = *(int *)(param_1 + 0x3c) + -10;
    FUN_0042ab44(DAT_004d2574,param_1,iVar1,(float)iVar1,(float)*(int *)(param_1 + 0x38));
  }
  return;
}



// Entry 00402f9c, recovered name Published_FormMouseDown_00402f9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormMouseDown_00402f9c
               (int param_1,undefined4 param_2,char param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 uVar2;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  undefined4 local_2c;
  undefined4 *local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined1 local_18 [11];
  char local_d;
  undefined4 local_c;
  int local_8;
  
  if ((DAT_004ca4cc < 1) && (DAT_004ca4d4 < 1)) {
    DAT_004ca4e6 = '\0';
  }
  else {
    DAT_004ca4e6 = '\x01';
  }
  local_d = param_3;
  local_c = param_2;
  local_8 = param_1;
  if (param_3 == '\x01') {
    (**(code **)(**(int **)(param_1 + 0x2e4) + 0x40))(*(int **)(param_1 + 0x2e4),param_5,param_4);
  }
  else if (param_3 == '\0') {
    FUN_004ae4b0();
    uVar2 = extraout_var;
    if (((in_ST0 < (longdouble)0.0001) &&
        (FUN_004ae4b0(), uVar2 = extraout_var_00, in_ST1 < (longdouble)0.0001)) &&
       (FUN_004ae4b0(), uVar2 = extraout_var_01, in_ST2 < (longdouble)0.0001)) {
      if (*(char *)(*(int *)(local_8 + 0x358) + 0x47) != '\0') {
        Published_FormResize_00402f58(local_8,local_c);
      }
      (**(code **)(**(int **)(local_8 + 0x358) + 0x5c))(*(int **)(local_8 + 0x358),0);
      FUN_0048158c(*(undefined4 *)(local_8 + 0x358),0);
      uVar2 = extraout_var_02;
    }
    if (DAT_004ca4e5 == '\0') {
      FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,CONCAT22(uVar2,2));
    }
    if (DAT_004ca4e6 != '\0') {
      DAT_004ca4e7 = 1;
      _DAT_004ca4f0 = param_5;
      DAT_004ca4f4 = param_4;
    }
    if (DAT_004ca4e5 != '\0') {
      FUN_0042b454(DAT_004d2574,param_5,param_4);
      local_1c = 0;
      while( true ) {
        if (DAT_004ca4cc <= local_1c) goto LAB_0040314e;
        if (*(char *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x339) != '\0') break;
        local_1c = local_1c + 1;
      }
      local_20 = 0;
      do {
        local_18[local_20] =
             *(undefined1 *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x300 + local_20);
        local_20 = local_20 + 1;
      } while (local_20 < 10);
LAB_0040314e:
      for (local_24 = 0; local_24 < DAT_004ca4cc; local_24 = local_24 + 1) {
        iVar1 = FUN_004a9f1c();
        if (iVar1 == 0) {
          *(undefined1 *)(*(int *)(&DAT_00515bc8 + local_24 * 4) + 0x339) = 1;
        }
      }
      local_2c = 1;
      local_28 = &local_2c;
      DAT_004ca4c0 = FUN_00403400(local_8,local_28);
      DAT_004ca4bc = *local_28;
      return;
    }
    if (DAT_004ca4eb == '\0') {
      if (DAT_004ca4e4 != '\0') {
        if (9 < DAT_004ca4c8) {
          return;
        }
        DAT_004ca4c8 = DAT_004ca4c8 + 1;
        *(int *)(local_8 + 900) = *(int *)(local_8 + 900) + 1;
        (&DAT_004cb9ac)[DAT_004ca4c8 * 0x1af5] = 1;
        FUN_0042b638();
        if (DAT_004ca4b9 == '\x02') {
          FUN_0041616c(local_8);
          DAT_004ca4e4 = 0;
          return;
        }
        FUN_004049ac(local_8);
      }
      DAT_004ca4e4 = '\0';
    }
    else if (DAT_004ca4c8 < 10) {
      DAT_004ca4c8 = DAT_004ca4c8 + 1;
      *(int *)(local_8 + 900) = *(int *)(local_8 + 900) + 1;
      (&DAT_004cb9ac)[DAT_004ca4c8 * 0x1af5] = 6;
      FUN_0044fd68();
      FUN_004049ac(local_8);
      DAT_004ca4eb = '\0';
    }
  }
  return;
}



// Entry 004043e0, recovered name Published_FormMouseMove_004043e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormMouseMove_004043e0
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  int local_1c;
  
  if (*(char *)(param_1 + 0x378) != '\0') {
    fVar1 = (float)(_DAT_0040479c * (longdouble)(param_5 - _DAT_004ca4f0));
    fVar2 = (float)(_DAT_0040479c * (longdouble)(DAT_004ca4f4 - param_4));
    DAT_004ca4e7 = '\0';
    for (local_1c = 0; local_1c < DAT_004ca4cc; local_1c = local_1c + 1) {
      if ((*(char *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x9dc) == '\x03') &&
         ((int)*(char *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x301) ==
          *(int *)(param_1 + 0x37c))) {
        *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x398) =
             *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x398) + fVar1;
        *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x39c) =
             *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x39c) + fVar2;
      }
      if ((*(char *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x9dc) == '\x04') &&
         ((int)*(char *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x305) ==
          *(int *)(param_1 + 0x37c))) {
        *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x398) =
             *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x398) + fVar1;
        *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x39c) =
             *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x39c) + fVar2;
        *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x3a8) =
             *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x3a8) + fVar1;
        *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x3ac) =
             *(float *)(*(int *)(&DAT_00515bc8 + local_1c * 4) + 0x3ac) + fVar2;
      }
    }
    *(undefined1 *)(param_1 + 0x377) = 1;
    _DAT_004ca4f0 = param_5;
    DAT_004ca4f4 = param_4;
    *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
  }
  if (DAT_004ca4e7 != '\0') {
    *(undefined1 *)(param_1 + 0x377) = 1;
    fVar1 = (float)(_DAT_004047a8 * (longdouble)(param_5 - _DAT_004ca4f0));
    lVar3 = _DAT_004047a8 * (longdouble)(param_4 - DAT_004ca4f4);
    if (((*(float *)(DAT_004d2574 + 0x86c) < 90.0) && (0.0 < *(float *)(DAT_004d2574 + 0x86c))) ||
       ((*(float *)(DAT_004d2574 + 0x86c) < 360.0 && (270.0 < *(float *)(DAT_004d2574 + 0x86c))))) {
      *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) + fVar1;
    }
    else {
      *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) - fVar1;
    }
    *(float *)(DAT_004d2574 + 0x86c) = *(float *)(DAT_004d2574 + 0x86c) + (float)lVar3;
    if (360.0 < *(float *)(DAT_004d2574 + 0x870)) {
      *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) - 360.0;
    }
    if (*(float *)(DAT_004d2574 + 0x870) < 0.0) {
      *(float *)(DAT_004d2574 + 0x870) = *(float *)(DAT_004d2574 + 0x870) + 360.0;
    }
    if (360.0 < *(float *)(DAT_004d2574 + 0x86c)) {
      *(float *)(DAT_004d2574 + 0x86c) = *(float *)(DAT_004d2574 + 0x86c) - 360.0;
    }
    if (*(float *)(DAT_004d2574 + 0x86c) < 0.0) {
      *(float *)(DAT_004d2574 + 0x86c) = *(float *)(DAT_004d2574 + 0x86c) + 360.0;
    }
    _DAT_004ca4f0 = param_5;
    DAT_004ca4f4 = param_4;
    *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
  }
  return;
}



// Entry 004047c4, recovered name Published_FormMouseUp_004047c4

void Published_FormMouseUp_004047c4(int param_1,undefined4 param_2,undefined1 param_3)

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
  if (DAT_004ca4e5 == '\0') {
    FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,1);
  }
  else {
    FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0);
  }
  DAT_004ca4e6 = 1;
  DAT_004ca4e7 = 0;
  uStack_18 = 0xffffffff;
  puStack_14 = &uStack_18;
  for (iStack_20 = 0; iStack_20 < DAT_004ca4c8; iStack_20 = iStack_20 + 1) {
    for (iStack_24 = 0; iStack_24 < *(int *)(&DAT_004d2580 + iStack_20 * 0x6bd4);
        iStack_24 = iStack_24 + 1) {
      (&DAT_004d25e0)[iStack_24 * 0x114 + iStack_20 * 0x6bd4] = 0;
      (&DAT_004d261c)[iStack_24 * 0x114 + iStack_20 * 0x6bd4] = 0;
      (&DAT_004d2658)[iStack_24 * 0x114 + iStack_20 * 0x6bd4] = 0;
      (&DAT_004d2694)[iStack_24 * 0x114 + iStack_20 * 0x6bd4] = 0;
    }
  }
  if ((DAT_004ca4e5 != '\0') && (*(char *)(*(int *)(iStack_8 + 0x364) + 0x2c) == '\0')) {
    DAT_004ca4c0 = FUN_00403400(iStack_8,puStack_14);
    DAT_004ca4bc = *puStack_14;
  }
  if (*(char *)(iStack_8 + 0x378) != '\0') {
    DAT_004ca4c0 = 0xffffffff;
    DAT_004ca4bc = 0xffffffff;
    *(undefined1 *)(iStack_8 + 0x378) = 0;
    FUN_00423424(iStack_8);
    for (iStack_28 = 0; iStack_28 < DAT_004ca4c8; iStack_28 = iStack_28 + 1) {
      for (iStack_2c = 0; iStack_2c < *(int *)(&DAT_004d2580 + iStack_28 * 0x6bd4);
          iStack_2c = iStack_2c + 1) {
        (&DAT_004d25e0)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
        (&DAT_004d261c)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
        (&DAT_004d2658)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
        (&DAT_004d2694)[iStack_2c * 0x114 + iStack_28 * 0x6bd4] = 0;
      }
    }
  }
  return;
}



// Entry 00416154, recovered name Published_Timer1Timer_00416154

void Published_Timer1Timer_00416154(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00415f54(param_1,param_2,param_3,param_2);
  return;
}



// Entry 0041f210, recovered name Published_PopupMenu1Popup_0041f210

void Published_PopupMenu1Popup_0041f210(void)

{
  return;
}



// Entry 0041f5ac, recovered name Published_FormClose_0041f5ac

void Published_FormClose_0041f5ac(void)

{
  undefined4 *in_FS_OFFSET;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  undefined4 uStack_30;
  
  FUN_004aa20c(0x4cba24);
  for (iStack_40 = 0; iStack_40 < DAT_004ca4cc; iStack_40 = iStack_40 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + iStack_40 * 4));
  }
  DAT_004ca4cc = 0;
  for (iStack_44 = 0; iStack_44 < DAT_004ca4d0; iStack_44 = iStack_44 + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + iStack_44 * 4));
  }
  DAT_004ca4d0 = 0;
  for (iStack_48 = 0; iStack_48 < DAT_004ca4d4; iStack_48 = iStack_48 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + iStack_48 * 4));
  }
  DAT_004ca4d4 = 0;
  FUN_0042af84(DAT_004d2574,DAT_004d2578);
  if (DAT_004d2574 != (int *)0x0) {
    (**(code **)(*DAT_004d2574 + -4))(DAT_004d2574,3);
  }
  DAT_004d2574 = (int *)0x0;
  *in_FS_OFFSET = uStack_30;
  return;
}



// Entry 0041f6c8, recovered name Published_N65Click_0041f6c8

void Published_N65Click_0041f6c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(*(int *)(param_1 + 0x2d0) + 0x38) != '\0') {
    FUN_0047969c(*(undefined4 *)(param_1 + 0x2d0),0,param_3,param_2);
    *(undefined4 *)(DAT_004d2574 + 0x86c) = DAT_00521748;
    *(undefined4 *)(DAT_004d2574 + 0x870) = DAT_0052174c;
    *(undefined4 *)(DAT_004d2574 + 0x874) = DAT_00521750;
  }
  return;
}



// Entry 0041f72c, recovered name Published_N61Click_0041f72c

void Published_N61Click_0041f72c(int param_1)

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
  
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x354),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x35c),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x364),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x300),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x304),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x310),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x2e4),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x2e8),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x2ec),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0048f79c(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x374),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0048f79c(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x378),uVar4);
  uVar4 = FUN_004ae4d8();
  FUN_0048f79c(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x37c),uVar4);
  uVar1 = FUN_004ae4d8();
  uVar2 = FUN_004ae4d8();
  uVar3 = FUN_004ae4d8();
  FUN_00481800(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x31c),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_004ae4d8();
  uVar2 = FUN_004ae4d8();
  uVar3 = FUN_004ae4d8();
  FUN_00481800(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x32c),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_004ae4d8();
  uVar2 = FUN_004ae4d8();
  uVar3 = FUN_004ae4d8();
  FUN_00481800(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x324),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_004ae4d8();
  uVar2 = FUN_004ae4d8();
  uVar3 = FUN_004ae4d8();
  FUN_00481800(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x334),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_004ae4d8();
  uVar2 = FUN_004ae4d8();
  uVar3 = FUN_004ae4d8();
  FUN_00481800(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x33c),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_004ae4d8();
  uVar2 = FUN_004ae4d8();
  uVar3 = FUN_004ae4d8();
  FUN_00481800(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x344),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_004ae4d8();
  uVar2 = FUN_004ae4d8();
  uVar3 = FUN_004ae4d8();
  FUN_00481800(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x3ac),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  uVar1 = FUN_004ae4d8();
  uVar2 = FUN_004ae4d8();
  uVar3 = FUN_004ae4d8();
  FUN_00481800(*(undefined4 *)(*(int *)PTR__Form2_004d2170 + 0x3b0),
               (uint)CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  (**(code **)(**(int **)PTR__Form2_004d2170 + 0xd8))();
  *(undefined4 *)(DAT_004d2578 + 0x38) = *(undefined4 *)(param_1 + 0x410);
  *(undefined4 *)(DAT_004d2578 + 0x3c) = *(undefined4 *)(param_1 + 0x414);
  *(undefined4 *)(DAT_004d2578 + 0x40) = *(undefined4 *)(param_1 + 0x418);
  *(undefined4 *)(DAT_004d2578 + 0x44) = *(undefined4 *)(param_1 + 0x41c);
  *(undefined4 *)(DAT_004d2578 + 0x18) = *(undefined4 *)(param_1 + 0x420);
  *(undefined4 *)(DAT_004d2578 + 0x1c) = *(undefined4 *)(param_1 + 0x424);
  *(undefined4 *)(DAT_004d2578 + 0x20) = *(undefined4 *)(param_1 + 0x428);
  *(undefined4 *)(DAT_004d2578 + 0x24) = *(undefined4 *)(param_1 + 0x42c);
  *(undefined4 *)(DAT_004d2578 + 0x28) = *(undefined4 *)(param_1 + 0x430);
  *(undefined4 *)(DAT_004d2578 + 0x2c) = *(undefined4 *)(param_1 + 0x434);
  *(undefined4 *)(DAT_004d2578 + 0x30) = *(undefined4 *)(param_1 + 0x438);
  *(undefined4 *)(DAT_004d2578 + 0x34) = *(undefined4 *)(param_1 + 0x43c);
  FUN_0042972c(DAT_004d2578);
  *(undefined4 *)(DAT_004d2574 + 0x89c) = *(undefined4 *)(param_1 + 0x400);
  *(undefined4 *)(DAT_004d2574 + 0x8a0) = *(undefined4 *)(param_1 + 0x404);
  *(undefined4 *)(DAT_004d2574 + 0x8a4) = *(undefined4 *)(param_1 + 0x408);
  *(undefined4 *)(DAT_004d2574 + 0x8a8) = *(undefined4 *)(param_1 + 0x40c);
  FUN_0042acf4(DAT_004d2574);
  for (local_10 = 0; local_10 < DAT_004ca4cc; local_10 = local_10 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_10 * 4));
  }
  DAT_004ca4cc = 0;
  for (local_14 = 0; local_14 < DAT_004ca4d0; local_14 = local_14 + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_14 * 4));
  }
  DAT_004ca4d0 = 0;
  for (local_18 = 0; local_18 < DAT_004ca4d4; local_18 = local_18 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_18 * 4));
  }
  DAT_004ca4d4 = 0;
  for (local_1c = 0; local_1c < DAT_004ca4c8; local_1c = local_1c + 1) {
    for (local_20 = 0; local_20 < *(int *)(&DAT_004d2580 + local_1c * 0x6bd4);
        local_20 = local_20 + 1) {
      (&DAT_004d25a4)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d25e1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d261d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d2659)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d2695)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d25a5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d25e2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d261e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d265a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d2696)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
    }
  }
  FUN_0042b00c(DAT_004d2574);
  FUN_0042ab18(DAT_004d2574);
  DAT_004ca4cc = 0;
  DAT_004ca4d0 = 0;
  FUN_004049ac(param_1);
  FUN_00420eb0(param_1);
  return;
}



// Entry 0041ffac, recovered name Published_N64Click_0041ffac

void Published_N64Click_0041ffac(void)

{
  *(undefined4 *)(DAT_004d2574 + 0x86c) = 0;
  *(undefined4 *)(DAT_004d2574 + 0x870) = 0;
  *(undefined4 *)(DAT_004d2574 + 0x874) = 0;
  *(undefined4 *)(DAT_004d2574 + 0x8bc) = 0x3f800000;
  *(undefined4 *)(DAT_004d2574 + 0x8c0) = 0x3f800000;
  *(undefined4 *)(DAT_004d2574 + 0x8c4) = 0x3f800000;
  return;
}



// Entry 00420014, recovered name Published_N43Click_00420014

void Published_N43Click_00420014(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
  DAT_004ca4e4 = 0;
  DAT_004ca4eb = 0;
  if (5.0 <= *(float *)(DAT_004d2574 + 0x8bc)) {
    FUN_0045ed98(*(undefined4 *)(param_1 + 0x2e8),0,param_1,param_2);
  }
  else {
    *(float *)(DAT_004d2574 + 0x8bc) = *(float *)(DAT_004d2574 + 0x8bc) + 0.1;
    iVar1 = DAT_004d2574;
    *(float *)(DAT_004d2574 + 0x8c0) = *(float *)(DAT_004d2574 + 0x8c0) + 0.1;
    *(float *)(DAT_004d2574 + 0x8c4) = *(float *)(DAT_004d2574 + 0x8c4) + 0.1;
    FUN_0045ed98(*(undefined4 *)(param_1 + 0x2ec),CONCAT31((int3)((uint)iVar1 >> 8),1),param_1,
                 param_2);
    FUN_0042ace0(DAT_004d2574);
  }
  return;
}



// Entry 004200e4, recovered name Published_N44Click_004200e4

void Published_N44Click_004200e4(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
  DAT_004ca4e4 = 0;
  DAT_004ca4eb = 0;
  if (*(float *)(DAT_004d2574 + 0x8bc) <= 0.1) {
    FUN_0045ed98(*(undefined4 *)(param_1 + 0x2ec),0,param_1,param_2);
  }
  else {
    *(float *)(DAT_004d2574 + 0x8bc) = *(float *)(DAT_004d2574 + 0x8bc) - 0.1;
    iVar1 = DAT_004d2574;
    *(float *)(DAT_004d2574 + 0x8c0) = *(float *)(DAT_004d2574 + 0x8c0) - 0.1;
    *(float *)(DAT_004d2574 + 0x8c4) = *(float *)(DAT_004d2574 + 0x8c4) - 0.1;
    FUN_0045ed98(*(undefined4 *)(param_1 + 0x2e8),CONCAT31((int3)((uint)iVar1 >> 8),1),param_1,
                 param_2);
    FUN_0042ace0(DAT_004d2574);
  }
  return;
}



// Entry 004201b0, recovered name Published_Y1Click_004201b0

void Published_Y1Click_004201b0(int param_1,undefined4 param_2)

{
  DAT_004ca4e4 = 0;
  DAT_004ca4eb = 0;
  DAT_00521748 = *(undefined4 *)(DAT_004d2574 + 0x86c);
  DAT_0052174c = *(undefined4 *)(DAT_004d2574 + 0x870);
  DAT_00521750 = *(undefined4 *)(DAT_004d2574 + 0x874);
  FUN_0047969c(*(undefined4 *)(param_1 + 0x2d0),CONCAT31((int3)((uint)DAT_004d2574 >> 8),1),
               DAT_00521750,param_2);
  DAT_004ca4e5 = 0;
  DAT_004ca4e8 = 1;
  DAT_004ca4e9 = 0;
  DAT_004ca4ea = 0;
  return;
}



// Entry 00420230, recovered name Published_X1Click_00420230

void Published_X1Click_00420230(int param_1,undefined4 param_2)

{
  DAT_004ca4e4 = 0;
  DAT_004ca4eb = 0;
  DAT_00521748 = *(undefined4 *)(DAT_004d2574 + 0x86c);
  DAT_0052174c = *(undefined4 *)(DAT_004d2574 + 0x870);
  DAT_00521750 = *(undefined4 *)(DAT_004d2574 + 0x874);
  FUN_0047969c(*(undefined4 *)(param_1 + 0x2d0),CONCAT31((int3)((uint)DAT_004d2574 >> 8),1),
               DAT_00521750,param_2);
  DAT_004ca4e5 = 0;
  DAT_004ca4e9 = 1;
  DAT_004ca4e8 = 0;
  DAT_004ca4ea = 0;
  return;
}



// Entry 004202b0, recovered name Published_Z2Click_004202b0

void Published_Z2Click_004202b0(int param_1,undefined4 param_2)

{
  DAT_004ca4e4 = 0;
  DAT_004ca4eb = 0;
  DAT_00521748 = *(undefined4 *)(DAT_004d2574 + 0x86c);
  DAT_0052174c = *(undefined4 *)(DAT_004d2574 + 0x870);
  DAT_00521750 = *(undefined4 *)(DAT_004d2574 + 0x874);
  FUN_0047969c(*(undefined4 *)(param_1 + 0x2d0),CONCAT31((int3)((uint)DAT_004d2574 >> 8),1),
               DAT_00521750,param_2);
  DAT_004ca4e5 = 0;
  DAT_004ca4ea = 1;
  DAT_004ca4e9 = 0;
  DAT_004ca4e8 = 0;
  return;
}



// Entry 00420330, recovered name Published_N51Click_00420330

void Published_N51Click_00420330(int param_1)

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
  
  FUN_004aa20c(&DAT_004cba44);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_004d2184 + 0x38);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0xfff5);
  DAT_004ca4b9 = 1;
  FUN_00471920(param_1,*(undefined4 *)(param_1 + 0x344));
  for (local_38 = 0; local_38 < DAT_004ca4cc; local_38 = local_38 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_38 * 4));
  }
  DAT_004ca4cc = 0;
  for (local_3c = 0; local_3c < DAT_004ca4d0; local_3c = local_3c + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_3c * 4));
  }
  DAT_004ca4d0 = 0;
  for (local_40 = 0; local_40 < DAT_004ca4d4; local_40 = local_40 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_40 * 4));
  }
  DAT_004ca4d4 = 0;
  for (local_44 = 0; local_44 < DAT_004ca4c8; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_004d2580 + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_004d25a4)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2659)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2695)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25a5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d265a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2696)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_0042b00c(DAT_004d2574);
  FUN_0042ab18(DAT_004d2574);
  DAT_004ca4cc = 0;
  DAT_004ca4d0 = 0;
  FUN_004049ac(param_1);
  FUN_00420eb0(param_1);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 004205c0, recovered name Published_N48Click_004205c0

void Published_N48Click_004205c0(int param_1)

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
  
  FUN_004aa20c(&DAT_004cba58);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_004d2184 + 0x38);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0xfff5);
  DAT_004ca4ec = 1;
  DAT_004ca4ed = 0;
  DAT_004ca4b9 = 2;
  FUN_00471920(param_1,*(undefined4 *)(param_1 + 0x344));
  for (local_38 = 0; local_38 < DAT_004ca4cc; local_38 = local_38 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_38 * 4));
  }
  DAT_004ca4cc = 0;
  for (local_3c = 0; local_3c < DAT_004ca4d0; local_3c = local_3c + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_3c * 4));
  }
  DAT_004ca4d0 = 0;
  for (local_40 = 0; local_40 < DAT_004ca4d4; local_40 = local_40 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_40 * 4));
  }
  DAT_004ca4d4 = 0;
  for (local_44 = 0; local_44 < DAT_004ca4c8; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_004d2580 + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_004d25a4)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2659)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2695)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25a5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d265a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2696)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_0042b00c(DAT_004d2574);
  FUN_0042ab18(DAT_004d2574);
  DAT_004ca4cc = 0;
  DAT_004ca4d0 = 0;
  FUN_004049ac(param_1);
  FUN_00420eb0(param_1);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 0042085c, recovered name Published_N58Click_0042085c

void Published_N58Click_0042085c(int param_1)

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
  
  FUN_004aa20c(&DAT_004cba6c);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_004d2184 + 0x38);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0xfff5);
  DAT_004ca4ec = 0;
  DAT_004ca4ed = 1;
  DAT_004ca4b9 = 2;
  FUN_00471920(param_1,*(undefined4 *)(param_1 + 0x344));
  for (local_38 = 0; local_38 < DAT_004ca4cc; local_38 = local_38 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_38 * 4));
  }
  DAT_004ca4cc = 0;
  for (local_3c = 0; local_3c < DAT_004ca4d0; local_3c = local_3c + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_3c * 4));
  }
  DAT_004ca4d0 = 0;
  for (local_40 = 0; local_40 < DAT_004ca4d4; local_40 = local_40 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_40 * 4));
  }
  DAT_004ca4d4 = 0;
  for (local_44 = 0; local_44 < DAT_004ca4c8; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_004d2580 + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_004d25a4)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2659)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2695)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25a5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d265a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2696)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_0042b00c(DAT_004d2574);
  FUN_0042ab18(DAT_004d2574);
  FUN_004049ac(param_1);
  FUN_00420eb0(param_1);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00420ae8, recovered name Published_N54Click_00420ae8

void Published_N54Click_00420ae8(int param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_004ca4e4 = 0;
  DAT_004ca4eb = 0;
  if (DAT_004ca4e5 == '\0') {
    FUN_0045ed44(*(undefined4 *)(param_1 + 0x310),1,param_3,param_2);
    FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0);
    DAT_004ca4e5 = '\x01';
    DAT_004ca4e9 = 0;
    DAT_004ca4e8 = 0;
    DAT_004ca4ea = 0;
    if (*(char *)(*(int *)(param_1 + 0x2d0) + 0x38) != '\0') {
      FUN_0047969c(*(undefined4 *)(param_1 + 0x2d0),0);
      *(undefined4 *)(DAT_004d2574 + 0x86c) = DAT_00521748;
      *(undefined4 *)(DAT_004d2574 + 0x870) = DAT_0052174c;
      *(undefined4 *)(DAT_004d2574 + 0x874) = DAT_00521750;
    }
  }
  else if (DAT_004ca4e5 == '\x01') {
    DAT_004ca4e5 = '\0';
    FUN_0045ed44(*(undefined4 *)(param_1 + 0x310),0,param_1,param_2);
    FUN_0045ed44(*(undefined4 *)(param_1 + 0x364),0);
    FUN_0045ed44(*(undefined4 *)(param_1 + 0x368),0);
  }
  return;
}



// Entry 00420be8, recovered name Published_N55Click_00420be8

void Published_N55Click_00420be8(int param_1)

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
  
  DAT_004ca4e4 = 0;
  DAT_004ca4eb = 0;
  FUN_0047969c(*(undefined4 *)(param_1 + 0x2d0),0);
  if (DAT_004ca4c4 == '\0') {
    UVar5 = 0;
    pCVar4 = (LPCSTR)0x0;
    pCVar3 = &DAT_004ca664;
    pHVar2 = (HWND)FUN_00487764(param_1);
    MessageBoxA(pHVar2,pCVar3,pCVar4,UVar5);
  }
  else if (((DAT_004ca4c0 != -1) && (DAT_004ca4bc != -1)) && (DAT_004ca4e5 == '\x01')) {
    for (local_10 = 0; local_10 < DAT_004ca4cc; local_10 = local_10 + 1) {
      FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_10 * 4));
    }
    DAT_004ca4cc = 0;
    for (local_14 = 0; local_14 < DAT_004ca4d0; local_14 = local_14 + 1) {
      FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_14 * 4));
    }
    DAT_004ca4d0 = 0;
    for (local_18 = 0; local_18 < DAT_004ca4d4; local_18 = local_18 + 1) {
      FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_18 * 4));
    }
    DAT_004ca4d4 = 0;
    for (local_1c = 0; local_1c < DAT_004ca4c8; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(int *)(&DAT_004d2580 + local_1c * 0x6bd4);
          local_20 = local_20 + 1) {
        (&DAT_004d25a4)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d25e1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d261d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d2659)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d2695)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d25a5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d25e2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d261e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d265a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
        (&DAT_004d2696)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      }
    }
    FUN_0042b00c(DAT_004d2574);
    FUN_0042ab18(DAT_004d2574);
    DAT_004ca4cc = 0;
    if (DAT_004ca4c4 != '\0') {
      cVar1 = FUN_0042be68();
      if (cVar1 == '\0') {
        UVar5 = 0;
        pCVar4 = (LPCSTR)0x0;
        pCVar3 = &DAT_004ca673;
        pHVar2 = (HWND)FUN_00487764(param_1);
        MessageBoxA(pHVar2,pCVar3,pCVar4,UVar5);
      }
      else {
        *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
      }
    }
    FUN_004049ac(param_1);
    FUN_00420eb0(param_1);
    DAT_004ca4c0 = -1;
    DAT_004ca4bc = -1;
  }
  return;
}



// Entry 00421ec0, recovered name Published_Edit1KeyDown_00421ec0

void Published_Edit1KeyDown_00421ec0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  Published_FormKeyDown_00402c5c(param_1,param_2,param_3,param_4);
  return;
}



// Entry 00421ee8, recovered name Published_N76Click_00421ee8

void Published_N76Click_00421ee8(int param_1)

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
  
  FUN_004aa20c(&DAT_004cba88);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_004d2184 + 0x38);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0xfff5);
  DAT_004ca4b9 = 3;
  FUN_00471920(param_1,*(undefined4 *)(param_1 + 0x344));
  for (local_38 = 0; local_38 < DAT_004ca4cc; local_38 = local_38 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_38 * 4));
  }
  DAT_004ca4cc = 0;
  for (local_3c = 0; local_3c < DAT_004ca4d0; local_3c = local_3c + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_3c * 4));
  }
  DAT_004ca4d0 = 0;
  for (local_40 = 0; local_40 < DAT_004ca4d4; local_40 = local_40 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_40 * 4));
  }
  DAT_004ca4d4 = 0;
  for (local_44 = 0; local_44 < DAT_004ca4c8; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_004d2580 + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_004d25a4)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2659)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2695)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25a5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d265a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2696)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_0042b00c(DAT_004d2574);
  FUN_0042ab18(DAT_004d2574);
  DAT_004ca4cc = 0;
  DAT_004ca4d0 = 0;
  FUN_004049ac(param_1);
  FUN_00420eb0(param_1);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00422178, recovered name Published_FormShow_00422178

void Published_FormShow_00422178(int param_1,undefined4 param_2,undefined4 param_3)

{
  HCURSOR pHVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  undefined1 local_8 [4];
  
  FUN_004aa20c(&DAT_004cbaac,param_2,param_3,param_2);
  pHVar1 = LoadCursorA(*(HINSTANCE *)PTR_DAT_004d216c,&DAT_004ca682);
  thunk_FUN_00474754(*(undefined4 *)PTR_DAT_004d2184,1,pHVar1);
  pHVar1 = LoadCursorA(*(HINSTANCE *)PTR_DAT_004d216c,&DAT_004ca687);
  thunk_FUN_00474754(*(undefined4 *)PTR_DAT_004d2184,2,pHVar1);
  FUN_00471920(param_1,*(undefined4 *)(param_1 + 0x344));
  uVar2 = FUN_00402650(local_8);
  FUN_004224b0(param_1,uVar2);
  FUN_004c8df4(param_1 + 0x440,local_8);
  FUN_004c8dc4(local_8,2);
  FUN_0041b594(param_1);
  *in_FS_OFFSET = local_2c;
  return;
}



// Entry 0042223c, recovered name Published_FormMouseWheelUp_0042223c

void Published_FormMouseWheelUp_0042223c(undefined4 param_1,undefined4 param_2)

{
  Published_N43Click_00420014(param_1,param_2);
  return;
}



// Entry 0042225c, recovered name Published_FormMouseWheelDown_0042225c

void Published_FormMouseWheelDown_0042225c(undefined4 param_1,undefined4 param_2)

{
  Published_N44Click_004200e4(param_1,param_2);
  return;
}



// Entry 0042227c, recovered name Published_N95Click_0042227c

void Published_N95Click_0042227c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00473184(param_1,param_2,param_3,param_2);
  return;
}



// Entry 00422294, recovered name Published_N1Click_00422294

void Published_N1Click_00422294(int param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  (**(code **)(**(int **)PTR__Form9_004d2178 + 0xd8))();
  for (local_10 = 0; local_10 < DAT_004ca4cc; local_10 = local_10 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_10 * 4));
  }
  DAT_004ca4cc = 0;
  for (local_14 = 0; local_14 < DAT_004ca4d0; local_14 = local_14 + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_14 * 4));
  }
  DAT_004ca4d0 = 0;
  for (local_18 = 0; local_18 < DAT_004ca4d4; local_18 = local_18 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_18 * 4));
  }
  DAT_004ca4d4 = 0;
  for (local_1c = 0; local_1c < DAT_004ca4c8; local_1c = local_1c + 1) {
    for (local_20 = 0; local_20 < *(int *)(&DAT_004d2580 + local_1c * 0x6bd4);
        local_20 = local_20 + 1) {
      (&DAT_004d25a4)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d25e1)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d261d)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d2659)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d2695)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d25a5)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d25e2)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d261e)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d265a)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
      (&DAT_004d2696)[local_20 * 0x114 + local_1c * 0x6bd4] = 0;
    }
  }
  FUN_0042b00c(DAT_004d2574);
  FUN_0042ab18(DAT_004d2574);
  *(float *)(param_1 + 0x390) = *(float *)(param_1 + 0x38c) - 5.0;
  DAT_004ca4cc = 0;
  DAT_004ca4d0 = 0;
  FUN_004049ac(param_1);
  FUN_00420eb0(param_1);
  return;
}



// Entry 00422810, recovered name Published_N2Click_00422810

void Published_N2Click_00422810(void)

{
  (**(code **)(**(int **)PTR__Form3_004d217c + 0xd8))();
  return;
}



// Entry 00422830, recovered name Published_N3Click_00422830

void Published_N3Click_00422830(int param_1)

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
  
  FUN_004aa20c(&DAT_004cbc58);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_004d2184 + 0x38);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0xfff5);
  DAT_004ca4b9 = 0;
  FUN_00471920(param_1,*(undefined4 *)(param_1 + 0x344));
  for (local_38 = 0; local_38 < DAT_004ca4cc; local_38 = local_38 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_38 * 4));
  }
  DAT_004ca4cc = 0;
  for (local_3c = 0; local_3c < DAT_004ca4d0; local_3c = local_3c + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_3c * 4));
  }
  DAT_004ca4d0 = 0;
  for (local_40 = 0; local_40 < DAT_004ca4d4; local_40 = local_40 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_40 * 4));
  }
  DAT_004ca4d4 = 0;
  for (local_44 = 0; local_44 < DAT_004ca4c8; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_004d2580 + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_004d25a4)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2659)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2695)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25a5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d265a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2696)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_0042b00c(DAT_004d2574);
  FUN_0042ab18(DAT_004d2574);
  DAT_004ca4cc = 0;
  DAT_004ca4d0 = 0;
  FUN_004049ac(param_1);
  FUN_00420eb0(param_1);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00422ac0, recovered name Published_N4Click_00422ac0

void Published_N4Click_00422ac0(int param_1)

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
  
  FUN_004aa20c(&DAT_004cbc6c);
  *(undefined1 *)(param_1 + 0x375) = 0;
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_004d2184 + 0x38);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0xfff5);
  DAT_004ca4b9 = 0;
  FUN_00471920(param_1,*(undefined4 *)(param_1 + 0x344));
  for (local_38 = 0; local_38 < DAT_004ca4cc; local_38 = local_38 + 1) {
    FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_38 * 4));
  }
  DAT_004ca4cc = 0;
  for (local_3c = 0; local_3c < DAT_004ca4d0; local_3c = local_3c + 1) {
    FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_3c * 4));
  }
  DAT_004ca4d0 = 0;
  for (local_40 = 0; local_40 < DAT_004ca4d4; local_40 = local_40 + 1) {
    FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_40 * 4));
  }
  DAT_004ca4d4 = 0;
  for (local_44 = 0; local_44 < DAT_004ca4c8; local_44 = local_44 + 1) {
    for (local_48 = 0; local_48 < *(int *)(&DAT_004d2580 + local_44 * 0x6bd4);
        local_48 = local_48 + 1) {
      (&DAT_004d25a4)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2659)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2695)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25a5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d25e2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d261e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d265a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      (&DAT_004d2696)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
    }
  }
  FUN_0042b00c(DAT_004d2574);
  FUN_0042ab18(DAT_004d2574);
  DAT_004ca4cc = 0;
  DAT_004ca4d0 = 0;
  FUN_004049ac(param_1);
  FUN_00420eb0(param_1);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,uVar1);
  if (local_16 != 0) {
    return;
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00422d58, recovered name Published_ScrollBar1Change_00422d58

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar1Change_00422d58(int param_1)

{
  int iVar1;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_18;
  int local_14;
  
  *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
  FUN_004ae4b0();
  if (((in_ST0 < (longdouble)0.0001) && (FUN_004ae4b0(), in_ST1 < (longdouble)0.0001)) &&
     (FUN_004ae4b0(), in_ST2 < (longdouble)0.0001)) {
    FUN_0048158c(*(undefined4 *)(param_1 + 0x358),0);
    (**(code **)(**(int **)(param_1 + 0x358) + 0x5c))(*(int **)(param_1 + 0x358),0);
    FUN_0045a918(*(undefined4 *)(param_1 + 0x358),0);
    *(undefined4 *)(param_1 + 0x380) = 0;
    FUN_00423424(param_1);
    return;
  }
  if ((*(int *)(param_1 + 0x380) - *(int *)(*(int *)(param_1 + 0x358) + 500) < 0) &&
     (*(int *)(*(int *)(param_1 + 0x358) + 500) == 0x168)) {
    FUN_0045a918(*(undefined4 *)(param_1 + 0x358),1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x358) + 500);
  if ((*(int *)(param_1 + 0x380) != iVar1 && -1 < *(int *)(param_1 + 0x380) - iVar1) &&
     (*(int *)(*(int *)(param_1 + 0x358) + 500) == 0)) {
    FUN_0045a918(*(undefined4 *)(param_1 + 0x358),0x167);
  }
  for (local_14 = 0; local_14 < DAT_004ca4cc; local_14 = local_14 + 1) {
    if (*(char *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 4) != '\0') {
      if (*(char *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x9dc) == '\x03') {
        FUN_00401ff4();
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x398) = local_3c;
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x39c) = local_38;
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x3a0) = local_34;
      }
      if (*(char *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x9dc) == '\x04') {
        FUN_00401ff4();
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x398) = local_3c;
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x39c) = local_38;
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x3a0) = local_34;
        FUN_00401ff4();
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x3a8) = local_3c;
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x3ac) = local_38;
        *(undefined4 *)(*(int *)(&DAT_00515bc8 + local_14 * 4) + 0x3b0) = local_34;
      }
    }
  }
  for (local_18 = 0; local_18 < DAT_004ca4cc; local_18 = local_18 + 1) {
    if ((*(char *)(*(int *)(&DAT_00515bc8 + local_18 * 4) + 4) != '\0') &&
       (*(char *)(*(int *)(&DAT_00515bc8 + local_18 * 4) + 0x9dc) == '\x04')) {
      FUN_004af964();
      FUN_004af964();
      FUN_004af964();
      FUN_004ae3b1();
      FUN_004ae3b1();
      FUN_004ae3b1();
      FUN_0042947c(*(undefined4 *)(&DAT_00515bc8 + local_18 * 4));
    }
  }
  *(undefined4 *)(param_1 + 0x380) = *(undefined4 *)(*(int *)(param_1 + 0x358) + 500);
                    /* WARNING: Read-only address (ram,0x0042334c) is written */
                    /* WARNING: Read-only address (ram,0x0042335c) is written */
  return;
}



// Entry 00423368, recovered name Published_N5Click_00423368

void Published_N5Click_00423368(int param_1,undefined4 param_2)

{
  if (*(char *)(*(int *)(param_1 + 0x364) + 0x2c) == '\0') {
    FUN_0045ed44(*(undefined4 *)(param_1 + 0x364),
                 CONCAT31((int3)((uint)*(int *)(param_1 + 0x364) >> 8),1));
  }
  else {
    FUN_0045ed44(*(undefined4 *)(param_1 + 0x364),0);
    FUN_00423424(param_1);
    Published_ScrollBar1Change_00422d58(param_1,param_2);
    FUN_0048158c(*(undefined4 *)(param_1 + 0x358),0);
    (**(code **)(**(int **)(param_1 + 0x358) + 0x5c))(*(int **)(param_1 + 0x358),0);
    FUN_0045a918(*(undefined4 *)(param_1 + 0x358),0);
    *(undefined4 *)(DAT_004d2574 + 0x860) = 0;
    *(undefined4 *)(DAT_004d2574 + 0x864) = 0;
    *(undefined4 *)(DAT_004d2574 + 0x868) = 0;
    Published_ScrollBar1Change_00422d58(param_1,param_2);
  }
  return;
}



// Entry 0042517c, recovered name Published_N6Click_0042517c

void Published_N6Click_0042517c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(*(int *)(param_1 + 0x368) + 0x2c) == '\0') {
    FUN_0045ed44(*(undefined4 *)(param_1 + 0x368),
                 CONCAT31((int3)((uint)*(int *)(param_1 + 0x368) >> 8),1),param_3,param_2);
  }
  else {
    FUN_0045ed44(*(undefined4 *)(param_1 + 0x368),0,param_1,param_2);
  }
  return;
}



// Entry 004251c0, recovered name Published_N7Click_004251c0

void Published_N7Click_004251c0(int param_1)

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
  
  FUN_004aa20c(&DAT_004cbc80);
  FUN_0047bbe8(*(undefined4 *)(param_1 + 0x2d8),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x58));
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d8) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(undefined2 *)(*(int *)PTR_DAT_004d2184 + 0x38);
    FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,CONCAT22(extraout_var,0xfff5));
    FUN_00481760(*(undefined4 *)(param_1 + 0x2d4),*(undefined4 *)(*(int *)(param_1 + 0x2d8) + 0x50))
    ;
    for (local_38 = 0; local_38 < DAT_004ca4cc; local_38 = local_38 + 1) {
      FUN_0042adfc(DAT_004d2574,*(undefined4 *)(&DAT_00515bc8 + local_38 * 4));
    }
    DAT_004ca4cc = 0;
    for (local_3c = 0; local_3c < DAT_004ca4d0; local_3c = local_3c + 1) {
      FUN_0042ae88(DAT_004d2574,*(undefined4 *)(&DAT_00519a48 + local_3c * 4));
    }
    DAT_004ca4d0 = 0;
    for (local_40 = 0; local_40 < DAT_004ca4d4; local_40 = local_40 + 1) {
      FUN_0042af14(DAT_004d2574,*(undefined4 *)(&DAT_0051d8c8 + local_40 * 4));
    }
    DAT_004ca4d4 = 0;
    for (local_44 = 0; local_44 < DAT_004ca4c8; local_44 = local_44 + 1) {
      for (local_48 = 0; local_48 < *(int *)(&DAT_004d2580 + local_44 * 0x6bd4);
          local_48 = local_48 + 1) {
        (&DAT_004d25a4)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d25e1)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d261d)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d2659)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d2695)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d25a5)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d25e2)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d261e)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d265a)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
        (&DAT_004d2696)[local_48 * 0x114 + local_44 * 0x6bd4] = 0;
      }
    }
    FUN_0042b00c(DAT_004d2574);
    FUN_0042ab18(DAT_004d2574);
    FUN_0042b040(DAT_004d2574);
    FUN_004049ac(param_1);
    FUN_00420eb0(param_1);
    FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,uVar1);
    if (local_16 != 0) {
      return;
    }
  }
  *in_FS_OFFSET = local_28;
  return;
}



// Entry 00425dd8, recovered name Published_FormCreate_00425dd8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormCreate_00425dd8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  undefined1 local_8 [4];
  
  FUN_004aa20c(&DAT_004cc3d0,param_2,param_3,param_2);
  FUN_00402650(local_8);
  iVar1 = FUN_00478df0(*(undefined4 *)(param_1 + 0x350));
  FUN_00463a38(*(undefined4 *)(iVar1 + 0x10),_DAT_00bd8390);
  iVar1 = FUN_00478df0(*(undefined4 *)(param_1 + 0x350));
  FUN_00463d1c(*(undefined4 *)(iVar1 + 0x14),_DAT_00bd8390);
  _DAT_00bd8390 = 0;
  FUN_00425ef0(param_1);
  *(undefined4 *)(param_1 + 0x3f8) = 0x3f800000;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x40c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x408) = 0;
  *(undefined4 *)(param_1 + 0x418) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x428) = 0x3f800000;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x41c) = 0;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x42c) = 0x3f800000;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x43c) = 0x3f800000;
  FUN_004c8dc4(local_8,2);
  *in_FS_OFFSET = local_2c;
  return;
}



// Entry 00425ee0, recovered name Published_FormDestroy_00425ee0

void Published_FormDestroy_00425ee0(void)

{
  return;
}



// Entry 00425f64, recovered name Published_ScrollBar1Change_00425f64

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar1Change_00425f64(int param_1)

{
  DAT_00bd8390 = *(byte *)(*(int *)(param_1 + 0x354) + 500);
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x3f4) =
       (float)(_DAT_00426004 * (longdouble)DAT_00bd8390);
  if (255.0 < *(float *)(*(int *)PTR__Form1_004d2168 + 0x3f4)) {
    *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3f4) = 0x437f0000;
  }
  FUN_00425ef0(param_1);
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x400) =
       (float)(_DAT_00426014 * (longdouble)*(int *)(*(int *)(param_1 + 0x300) + 500));
  return;
}



// Entry 00426020, recovered name Published_ScrollBar2Change_00426020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar2Change_00426020(int param_1)

{
  DAT_00bd8391 = *(byte *)(*(int *)(param_1 + 0x35c) + 500);
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x3f8) =
       (float)(_DAT_004260c0 * (longdouble)DAT_00bd8391);
  if (255.0 < *(float *)(*(int *)PTR__Form1_004d2168 + 0x3f8)) {
    *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3f8) = 0x437f0000;
  }
  FUN_00425ef0(param_1);
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x404) =
       (float)(_DAT_004260d0 * (longdouble)*(int *)(*(int *)(param_1 + 0x304) + 500));
  return;
}



// Entry 004260dc, recovered name Published_ScrollBar3Change_004260dc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar3Change_004260dc(int param_1)

{
  DAT_00bd8392 = *(byte *)(*(int *)(param_1 + 0x364) + 500);
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x3fc) =
       (float)(_DAT_0042617c * (longdouble)DAT_00bd8392);
  if (255.0 < *(float *)(*(int *)PTR__Form1_004d2168 + 0x3fc)) {
    *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3fc) = 0x437f0000;
  }
  FUN_00425ef0(param_1);
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x408) =
       (float)(_DAT_0042618c * (longdouble)*(int *)(*(int *)(param_1 + 0x310) + 500));
  return;
}



// Entry 00426198, recovered name Published_Label5Click_00426198

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label5Click_00426198(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00481800(*(undefined4 *)(param_1 + 0x31c),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x394) =
         (float)(_DAT_0042624c * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x398) =
         (float)(_DAT_0042624c * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x39c) =
         (float)(_DAT_0042624c * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 00426258, recovered name Published_Label7Click_00426258

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label7Click_00426258(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00481800(*(undefined4 *)(param_1 + 0x324),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3a0) =
         (float)(_DAT_0042630c * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3a4) =
         (float)(_DAT_0042630c * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3a8) =
         (float)(_DAT_0042630c * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 00426318, recovered name Published_Label8Click_00426318

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label8Click_00426318(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00481800(*(undefined4 *)(param_1 + 0x334),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3c4) =
         (float)(_DAT_004263cc * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3c8) =
         (float)(_DAT_004263cc * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3cc) =
         (float)(_DAT_004263cc * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004263d8, recovered name Published_Label9Click_004263d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label9Click_004263d8(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00481800(*(undefined4 *)(param_1 + 0x33c),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3d0) =
         (float)(_DAT_0042648c * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3d4) =
         (float)(_DAT_0042648c * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3d8) =
         (float)(_DAT_0042648c * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 00426498, recovered name Published_Label6Click_00426498

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label6Click_00426498(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00481800(*(undefined4 *)(param_1 + 0x32c),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3dc) =
         (float)(_DAT_0042654c * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3e0) =
         (float)(_DAT_0042654c * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3e4) =
         (float)(_DAT_0042654c * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 00426558, recovered name Published_Label10Click_00426558

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label10Click_00426558(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00481800(*(undefined4 *)(param_1 + 0x344),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_004d2168 + 1000) =
         (float)(_DAT_0042660c * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3ec) =
         (float)(_DAT_0042660c * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3f0) =
         (float)(_DAT_0042660c * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 00426618, recovered name Published_SpeedButton1Click_00426618

void Published_SpeedButton1Click_00426618(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)PTR__Form1_004d2168;
  piVar1 = (int *)(iVar2 + 900);
  *piVar1 = *piVar1 + 1;
  FUN_00473184(param_1,iVar2,param_3,param_2);
  return;
}



// Entry 00426640, recovered name Published_SpeedButton2Click_00426640

void Published_SpeedButton2Click_00426640(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0045a918(*(undefined4 *)(param_1 + 0x354),DAT_00bd8400,param_3,param_2);
  FUN_0045a918(*(undefined4 *)(param_1 + 0x35c),DAT_00bd8404);
  FUN_0045a918(*(undefined4 *)(param_1 + 0x364),DAT_00bd8408);
  FUN_0045a918(*(undefined4 *)(param_1 + 0x300),DAT_00bd840c);
  FUN_0045a918(*(undefined4 *)(param_1 + 0x304),DAT_00bd8410);
  FUN_0045a918(*(undefined4 *)(param_1 + 0x310),DAT_00bd8414);
  FUN_0045a918(*(undefined4 *)(param_1 + 0x2e4),DAT_00bd8418);
  FUN_0045a918(*(undefined4 *)(param_1 + 0x2e8),DAT_00bd841c);
  FUN_0045a918(*(undefined4 *)(param_1 + 0x2ec),DAT_00bd8420);
  FUN_0048f79c(*(undefined4 *)(param_1 + 0x374),DAT_00bd8424);
  FUN_0048f79c(*(undefined4 *)(param_1 + 0x378),DAT_00bd8428);
  FUN_0048f79c(*(undefined4 *)(param_1 + 0x37c),DAT_00bd842c);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3ac) = DAT_00bd83ac;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3b0) = DAT_00bd83b0;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3b4) = DAT_00bd83b4;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3b8) = DAT_00bd83b8;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3bc) = DAT_00bd83bc;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3c0) = DAT_00bd83c0;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x394) = DAT_00bd8394;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x398) = DAT_00bd8398;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x39c) = DAT_00bd839c;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3a0) = DAT_00bd83a0;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3a4) = DAT_00bd83a4;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3a8) = DAT_00bd83a8;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3c4) = DAT_00bd83c4;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3c8) = DAT_00bd83c8;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3cc) = DAT_00bd83cc;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3d0) = DAT_00bd83d0;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3d4) = DAT_00bd83d4;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3d8) = DAT_00bd83d8;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3dc) = DAT_00bd83dc;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3e0) = DAT_00bd83e0;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3e4) = DAT_00bd83e4;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 1000) = DAT_00bd83e8;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3ec) = DAT_00bd83ec;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3f0) = DAT_00bd83f0;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3f4) = DAT_00bd83f4;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3f8) = DAT_00bd83f8;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x3fc) = DAT_00bd83fc;
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x400) = *(undefined4 *)(param_1 + 0x3ec);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x404) = *(undefined4 *)(param_1 + 0x3f0);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x408) = *(undefined4 *)(param_1 + 0x3f4);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x40c) = *(undefined4 *)(param_1 + 0x3f8);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x410) = *(undefined4 *)(param_1 + 0x3fc);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x414) = *(undefined4 *)(param_1 + 0x400);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x418) = *(undefined4 *)(param_1 + 0x404);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x41c) = *(undefined4 *)(param_1 + 0x408);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x420) = *(undefined4 *)(param_1 + 0x40c);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x424) = *(undefined4 *)(param_1 + 0x410);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x428) = *(undefined4 *)(param_1 + 0x414);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x42c) = *(undefined4 *)(param_1 + 0x418);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x430) = *(undefined4 *)(param_1 + 0x41c);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x434) = *(undefined4 *)(param_1 + 0x420);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x438) = *(undefined4 *)(param_1 + 0x424);
  *(undefined4 *)(*(int *)PTR__Form1_004d2168 + 0x43c) = *(undefined4 *)(param_1 + 0x428);
  FUN_00473184(param_1);
  return;
}



// Entry 00426ab4, recovered name Published_FormShow_00426ab4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormShow_00426ab4(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined2 local_10;
  
  DAT_00bd8390 = FUN_004ae4d8();
  DAT_00bd8391 = FUN_004ae4d8();
  DAT_00bd8392 = FUN_004ae4d8();
  DAT_00bd8400 = *(undefined4 *)(*(int *)(param_1 + 0x354) + 500);
  DAT_00bd8404 = *(undefined4 *)(*(int *)(param_1 + 0x35c) + 500);
  DAT_00bd8408 = *(undefined4 *)(*(int *)(param_1 + 0x364) + 500);
  DAT_00bd840c = *(undefined4 *)(*(int *)(param_1 + 0x300) + 500);
  DAT_00bd8410 = *(undefined4 *)(*(int *)(param_1 + 0x304) + 500);
  DAT_00bd8414 = *(undefined4 *)(*(int *)(param_1 + 0x310) + 500);
  DAT_00bd8418 = *(undefined4 *)(*(int *)(param_1 + 0x2e4) + 500);
  DAT_00bd841c = *(undefined4 *)(*(int *)(param_1 + 0x2e8) + 500);
  DAT_00bd8420 = *(undefined4 *)(*(int *)(param_1 + 0x2ec) + 500);
  DAT_00bd8424 = *(undefined4 *)(*(int *)(param_1 + 0x374) + 0x210);
  DAT_00bd8428 = *(undefined4 *)(*(int *)(param_1 + 0x378) + 0x210);
  DAT_00bd842c = *(undefined4 *)(*(int *)(param_1 + 0x37c) + 0x210);
  bVar1 = *(byte *)(*(int *)(param_1 + 0x35c) + 500);
  local_10 = CONCAT11(bVar1,*(undefined1 *)(*(int *)(param_1 + 0x354) + 500));
  DAT_00bd83f4 = (float)(_DAT_00427278 * (longdouble)(local_10 & 0xff));
  DAT_00bd83f8 = (float)(_DAT_00427278 * (longdouble)bVar1);
  DAT_00bd83fc = (float)(_DAT_00427278 * (longdouble)*(byte *)(*(int *)(param_1 + 0x364) + 500));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x3ac) + 0x60);
  DAT_00bd83ac = (float)(_DAT_00427278 * (longdouble)(uVar2 & 0xff));
  DAT_00bd83b0 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00bd83b4 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x3b0) + 0x60);
  DAT_00bd83b8 = (float)(_DAT_00427278 * (longdouble)(uVar2 & 0xff));
  DAT_00bd83bc = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00bd83c0 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x31c) + 0x60);
  DAT_00bd8394 = (float)(_DAT_00427278 * (longdouble)(uVar2 & 0xff));
  DAT_00bd8398 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00bd839c = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x324) + 0x60);
  DAT_00bd83a0 = (float)(_DAT_00427278 * (longdouble)(uVar2 & 0xff));
  DAT_00bd83a4 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00bd83a8 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x334) + 0x60);
  DAT_00bd83c4 = (float)(_DAT_00427278 * (longdouble)(uVar2 & 0xff));
  DAT_00bd83c8 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00bd83cc = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x33c) + 0x60);
  DAT_00bd83d0 = (float)(_DAT_00427278 * (longdouble)(uVar2 & 0xff));
  DAT_00bd83d4 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00bd83d8 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x32c) + 0x60);
  DAT_00bd83dc = (float)(_DAT_00427278 * (longdouble)(uVar2 & 0xff));
  DAT_00bd83e0 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00bd83e4 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 0x10 & 0xff));
  uVar2 = *(uint *)(*(int *)(param_1 + 0x344) + 0x60);
  DAT_00bd83e8 = (float)(_DAT_00427278 * (longdouble)(uVar2 & 0xff));
  DAT_00bd83ec = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 8 & 0xff));
  DAT_00bd83f0 = (float)(_DAT_00427278 * (longdouble)(uVar2 >> 0x10 & 0xff));
  *(float *)(param_1 + 0x3ec) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x300) + 500));
  *(float *)(param_1 + 0x3f0) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x304) + 500));
  *(float *)(param_1 + 0x3f4) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x310) + 500));
  *(float *)(param_1 + 0x40c) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(param_1 + 0x410) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(param_1 + 0x414) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(param_1 + 0x41c) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(param_1 + 0x420) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(param_1 + 0x424) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(param_1 + 0x3fc) = (float)*(int *)(*(int *)(param_1 + 0x374) + 0x210) - 5.0;
  *(float *)(param_1 + 0x400) = (float)*(int *)(*(int *)(param_1 + 0x378) + 0x210) - 5.0;
  *(float *)(param_1 + 0x404) = (float)*(int *)(*(int *)(param_1 + 0x37c) + 0x210) - 5.0;
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x400) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x300) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x404) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x304) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x408) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x310) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x420) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x424) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x428) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x430) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x434) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x438) =
       (float)(_DAT_00427284 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x410) =
       (float)*(int *)(*(int *)(param_1 + 0x374) + 0x210) - 5.0;
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x414) =
       (float)*(int *)(*(int *)(param_1 + 0x378) + 0x210) - 5.0;
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x418) =
       (float)*(int *)(*(int *)(param_1 + 0x37c) + 0x210) - 5.0;
  return;
}



// Entry 00427294, recovered name Published_ScrollBar7Change_00427294

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar7Change_00427294(int param_1)

{
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x420) =
       (float)(_DAT_004272f0 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x430) =
       (float)(_DAT_004272f0 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e4) + 500));
  return;
}



// Entry 004272fc, recovered name Published_ScrollBar8Change_004272fc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar8Change_004272fc(int param_1)

{
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x424) =
       (float)(_DAT_00427358 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x434) =
       (float)(_DAT_00427358 * (longdouble)*(int *)(*(int *)(param_1 + 0x2e8) + 500));
  return;
}



// Entry 00427364, recovered name Published_ScrollBar9Change_00427364

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_ScrollBar9Change_00427364(int param_1)

{
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x428) =
       (float)(_DAT_004273c0 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x438) =
       (float)(_DAT_004273c0 * (longdouble)*(int *)(*(int *)(param_1 + 0x2ec) + 500));
  return;
}



// Entry 004273cc, recovered name Published_TrackBar1Change_004273cc

void Published_TrackBar1Change_004273cc(int param_1)

{
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x410) =
       (float)*(int *)(*(int *)(param_1 + 0x374) + 0x210) - 5.0;
  return;
}



// Entry 00427404, recovered name Published_TrackBar2Change_00427404

void Published_TrackBar2Change_00427404(int param_1)

{
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x414) =
       (float)*(int *)(*(int *)(param_1 + 0x378) + 0x210) - 5.0;
  return;
}



// Entry 0042743c, recovered name Published_TrackBar3Change_0042743c

void Published_TrackBar3Change_0042743c(int param_1)

{
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x418) =
       (float)*(int *)(*(int *)(param_1 + 0x37c) + 0x210) - 5.0;
  return;
}



// Entry 00427474, recovered name Published_Label32Click_00427474

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label32Click_00427474(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00481800(*(undefined4 *)(param_1 + 0x3ac),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3ac) =
         (float)(_DAT_00427528 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3b0) =
         (float)(_DAT_00427528 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3b4) =
         (float)(_DAT_00427528 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 00427534, recovered name Published_Label33Click_00427534

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Label33Click_00427534(int param_1)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x2d4) + 0x3c))();
  if (cVar2 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2d4) + 0x50);
    FUN_00481800(*(undefined4 *)(param_1 + 0x3b0),*(undefined4 *)(*(int *)(param_1 + 0x2d4) + 0x50))
    ;
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3b8) =
         (float)(_DAT_004275e8 * (longdouble)(uVar1 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3bc) =
         (float)(_DAT_004275e8 * (longdouble)(uVar1 >> 8 & 0xff));
    *(float *)(*(int *)PTR__Form1_004d2168 + 0x3c0) =
         (float)(_DAT_004275e8 * (longdouble)(uVar1 >> 0x10 & 0xff));
  }
  return;
}



// Entry 004513b0, recovered name Published_FormShow_004513b0

void Published_FormShow_004513b0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_004ae4d8();
  FUN_0045a918(*(undefined4 *)(param_1 + 0x2dc),uVar1,param_1,param_2);
  return;
}



// Entry 004513e4, recovered name Published_SpeedButton2Click_004513e4

void Published_SpeedButton2Click_004513e4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00473184(param_1,param_2,param_3,param_2);
  return;
}



// Entry 004513fc, recovered name Published_SpeedButton1Click_004513fc

void Published_SpeedButton1Click_004513fc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = PTR__Form1_004d2168;
  iVar1 = *(int *)(param_1 + 0x2dc);
  *(float *)(*(int *)PTR__Form1_004d2168 + 0x38c) = (float)*(int *)(iVar1 + 500);
  FUN_00473184(param_1,iVar1,puVar2,param_2);
  return;
}



// Entry 00451580, recovered name Published_Label3Click_00451580

void Published_Label3Click_00451580(undefined4 param_1)

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
  
  FUN_004aa20c(&DAT_004cd52c);
  FUN_00402650(local_8);
  FUN_004c8cc0(local_c,s_http___www_eedduu_com_004cd4b8);
  FUN_004c8df4(local_8,local_c);
  FUN_004c8dc4(local_c,2);
  lpFile = (LPCSTR)FUN_0041f1cc(local_8);
  uVar1 = *(undefined2 *)(*(int *)PTR_DAT_004d2184 + 0x38);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,0xfff5);
  nShowCmd = 1;
  lpDirectory = &DAT_004cd4d4;
  lpParameters = &DAT_004cd4d3;
  lpOperation = &DAT_004cd4ce;
  hwnd = (HWND)FUN_00487764(param_1);
  ShellExecuteA(hwnd,lpOperation,lpFile,lpParameters,lpDirectory,nShowCmd);
  FUN_004746c4(*(undefined4 *)PTR_DAT_004d2184,uVar1);
  if (local_1e != 0) {
    return;
  }
  FUN_004c8dc4(local_8,2);
  *in_FS_OFFSET = local_30;
  return;
}



// Entry 0045167c, recovered name Published_SpeedButton1Click_0045167c

void Published_SpeedButton1Click_0045167c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00473184(param_1,param_2,param_3,param_2);
  return;
}



// Entry 00451694, recovered name Published_FormClick_00451694

void Published_FormClick_00451694(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00473184(param_1,param_2,param_3,param_2);
  return;
}



