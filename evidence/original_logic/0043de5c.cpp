0x0043de5c Published_SpeedButton19Click_0043de5c recovered/native/main/published_recovered.cpp:11184
// Entry 0043de5c, recovered name Published_SpeedButton19Click_0043de5c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_SpeedButton19Click_0043de5c(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *in_FS_OFFSET;
  byte bVar7;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_48;
  int local_44;
  undefined4 local_38;
  undefined1 local_14 [4];
  int local_10;
  undefined1 local_c [4];
  int local_8;
  
  bVar7 = 0;
  FUN_00534be0(&DAT_0055e8e8);
  _DAT_00556594 = 0;
  FUN_00505524(*(undefined4 *)(param_1 + 0x4cc),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x358),0);
  *(undefined4 *)(param_1 + 0x5cc) = DAT_0057a730;
  *(undefined4 *)(param_1 + 0x5d0) = DAT_0057a734;
  (**(code **)(**(int **)(param_1 + 800) + 0x5c))(*(int **)(param_1 + 800),0);
  (**(code **)(**(int **)(param_1 + 0x324) + 0x5c))(*(int **)(param_1 + 0x324),0);
  (**(code **)(**(int **)(param_1 + 0x328) + 0x5c))(*(int **)(param_1 + 0x328),0);
  (**(code **)(**(int **)(param_1 + 0x400) + 0x5c))(*(int **)(param_1 + 0x400),1);
  (**(code **)(**(int **)(param_1 + 0x404) + 0x5c))(*(int **)(param_1 + 0x404),1);
  FUN_00527f18(*(undefined4 *)(param_1 + 0x404),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x330),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x334),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x498),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x49c),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x474),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x47c),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x33c),0);
  FUN_004d38b8(*(undefined4 *)(param_1 + 0x340),0);
  iVar2 = FUN_0053d180();
  if (iVar2 % 9 == 0) {
    DAT_005636b8 = 0;
    DAT_0057a718 = DAT_0057a714 + _DAT_005636bc;
  }
  if (*(char *)(param_1 + 0xe1b) == '\x01') {
    DAT_00587798 = 0;
    for (local_44 = 0; local_44 < DAT_0058779c; local_44 = local_44 + 1) {
      local_8 = FUN_00533ad8();
      if (local_8 != 0) {
        FUN_004016e8(local_8 + 4);
        FUN_00533f34();
      }
      *(int *)(&DAT_005867f8 + local_44 * 4) = local_8;
      **(undefined4 **)(&DAT_005867f8 + local_44 * 4) = 1;
      FUN_00541018(*(int *)(&DAT_005867f8 + local_44 * 4) + 4,
                   *(int *)(&DAT_00585850 + local_44 * 4) + 4);
      for (local_48 = 0; local_48 < *(int *)(*(int *)(&DAT_00585850 + local_44 * 4) + 0xf18);
          local_48 = local_48 + 1) {
        iVar2 = *(int *)(&DAT_00585850 + local_44 * 4) + local_48 * 0xe8;
        iVar4 = *(int *)(&DAT_005867f8 + local_44 * 4) + local_48 * 0xe8;
        FUN_00541018(iVar4 + 0xc,iVar2 + 0xf24);
        FUN_00533d60();
        FUN_00533d60();
        FUN_00541018(iVar4 + 0xc0,iVar2 + 0xfd8);
        FUN_00541018(iVar4 + 0xd8,iVar2 + 0xff0);
        FUN_00541018(iVar4 + 0xdc,iVar2 + 0xff4);
        FUN_00541018(iVar4 + 0xe0,iVar2 + 0xff8);
        FUN_00541018(iVar4 + 0xe4,iVar2 + 0xffc);
        FUN_00541018(iVar4 + 0xe8,iVar2 + 0x1000);
        *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar2 + 0xf20);
        *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar2 + 0xf28);
        *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar2 + 0xf2c);
        puVar3 = (undefined4 *)(iVar2 + 0xf80);
        puVar6 = (undefined4 *)(iVar4 + 0x68);
        for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar6 = *puVar3;
          puVar3 = puVar3 + (uint)bVar7 * -2 + 1;
          puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
        }
        puVar3 = (undefined4 *)(iVar2 + 0xfa8);
        puVar6 = (undefined4 *)(iVar4 + 0x90);
        for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar6 = *puVar3;
          puVar3 = puVar3 + (uint)bVar7 * -2 + 1;
          puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
        }
        *(undefined4 *)(iVar4 + 0xb8) = *(undefined4 *)(iVar2 + 0xfd0);
        *(undefined4 *)(iVar4 + 0xbc) = *(undefined4 *)(iVar2 + 0xfd4);
        *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(iVar2 + 0xfe0);
        *(undefined4 *)(iVar4 + 0xcc) = *(undefined4 *)(iVar2 + 0xfe4);
        *(undefined4 *)(iVar4 + 0xd0) = *(undefined4 *)(iVar2 + 0xfe8);
        *(undefined4 *)(iVar4 + 0xd4) = *(undefined4 *)(iVar2 + 0xfec);
      }
      *(undefined4 *)(*(int *)(&DAT_005867f8 + local_44 * 4) + 0x2d58) =
           *(undefined4 *)(*(int *)(&DAT_00585850 + local_44 * 4) + 0xf18);
      DAT_00587798 = DAT_00587798 + 1;
    }
    FUN_00452e28();
    puVar3 = (undefined4 *)FUN_00540ec4(local_c,&DAT_00557249,0);
    FUN_0043240c(param_1,*puVar3,0);
    FUN_00540fe8(local_c,2);
    for (local_54 = 0; local_54 < DAT_0058779c; local_54 = local_54 + 1) {
      if (*(int *)(*(int *)(&DAT_00585850 + local_54 * 4) + 0xa4) == 1) {
        local_58 = -1;
        for (local_5c = 0; local_5c < DAT_00587798; local_5c = local_5c + 1) {
          cVar1 = FUN_005410cc(*(int *)(&DAT_005867f8 + local_5c * 4) + 4,
                               *(int *)(&DAT_00585850 + local_54 * 4) + 4);
          if (cVar1 != '\0') {
            local_58 = local_5c;
            break;
          }
        }
        if (local_58 != -1) {
          for (local_60 = 0; local_60 < *(int *)(*(int *)(&DAT_005867f8 + local_58 * 4) + 0x2d58);
              local_60 = local_60 + 1) {
            iVar2 = *(int *)(&DAT_005867f8 + local_58 * 4) + local_60 * 0xe8;
            iVar4 = *(int *)(&DAT_00585850 + local_54 * 4) + local_60 * 0xe8;
            FUN_00541018(iVar4 + 0xf24,iVar2 + 0xc);
            FUN_00533d60();
            FUN_00533d60();
            FUN_00541018(iVar4 + 0xfd8,iVar2 + 0xc0);
            FUN_00541018(iVar4 + 0xff0,iVar2 + 0xd8);
            FUN_00541018(iVar4 + 0xff4,iVar2 + 0xdc);
            FUN_00541018(iVar4 + 0xff8,iVar2 + 0xe0);
            FUN_00541018(iVar4 + 0xffc,iVar2 + 0xe4);
            FUN_00541018(iVar4 + 0x1000,iVar2 + 0xe8);
            *(undefined4 *)(iVar4 + 0xf20) = *(undefined4 *)(iVar2 + 8);
            *(undefined4 *)(iVar4 + 0xf28) = *(undefined4 *)(iVar2 + 0x10);
            *(undefined4 *)(iVar4 + 0xf2c) = *(undefined4 *)(iVar2 + 0x14);
            puVar3 = (undefined4 *)(iVar2 + 0x68);
            puVar6 = (undefined4 *)(iVar4 + 0xf80);
            for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar6 = *puVar3;
              puVar3 = puVar3 + (uint)bVar7 * -2 + 1;
              puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
            }
            puVar3 = (undefined4 *)(iVar2 + 0x90);
            puVar6 = (undefined4 *)(iVar4 + 0xfa8);
            for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar6 = *puVar3;
              puVar3 = puVar3 + (uint)bVar7 * -2 + 1;
              puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
            }
            *(undefined4 *)(iVar4 + 0xfd0) = *(undefined4 *)(iVar2 + 0xb8);
            *(undefined4 *)(iVar4 + 0xfd4) = *(undefined4 *)(iVar2 + 0xbc);
            *(undefined4 *)(iVar4 + 0xfe0) = *(undefined4 *)(iVar2 + 200);
            *(undefined4 *)(iVar4 + 0xfe4) = *(undefined4 *)(iVar2 + 0xcc);
            *(undefined4 *)(iVar4 + 0xfe8) = *(undefined4 *)(iVar2 + 0xd0);
            *(undefined4 *)(iVar4 + 0xfec) = *(undefined4 *)(iVar2 + 0xd4);
          }
          *(undefined4 *)(*(int *)(&DAT_00585850 + local_54 * 4) + 0xf18) =
               *(undefined4 *)(*(int *)(&DAT_005867f8 + local_58 * 4) + 0x2d58);
        }
      }
    }
    for (local_6c = 0; local_6c < DAT_00587798; local_6c = local_6c + 1) {
      local_10 = *(int *)(&DAT_005867f8 + local_6c * 4);
      if (local_10 != 0) {
        FUN_00533dd4();
        FUN_00540fe8(local_10 + 4,2);
        FUN_00533aa4();
      }
      *(undefined4 *)(&DAT_005867f8 + local_6c * 4) = 0;
    }
    DAT_00587798 = 0;
    DAT_0057a730 = *(undefined4 *)(param_1 + 0x5cc);
    DAT_0057a734 = *(undefined4 *)(param_1 + 0x5d0);
  }
  for (local_70 = 0; local_70 < DAT_0058779c; local_70 = local_70 + 1) {
    iVar2 = *(int *)(&DAT_00585850 + local_70 * 4);
    *(undefined4 *)(iVar2 + 0x3cc8) = 0;
    *(undefined4 *)(iVar2 + 0x3ccc) = 0;
    iVar2 = *(int *)(&DAT_00585850 + local_70 * 4);
    *(undefined4 *)(iVar2 + 0x4318) = 0;
    *(undefined4 *)(iVar2 + 0x431c) = 0;
    for (local_74 = 0; local_74 < *(int *)(*(int *)(&DAT_00585850 + local_70 * 4) + 0x104);
        local_74 = local_74 + 1) {
      iVar2 = *(int *)(&DAT_00585850 + local_70 * 4);
      *(undefined4 *)(iVar2 + 0x3cd8 + local_74 * 8) = 0;
      *(undefined4 *)(iVar2 + 0x3cdc + local_74 * 8) = 0;
      iVar2 = *(int *)(&DAT_00585850 + local_70 * 4);
      *(undefined4 *)(iVar2 + 0x3ff8 + local_74 * 8) = 0;
      *(undefined4 *)(iVar2 + 0x3ffc + local_74 * 8) = 0;
    }
  }
  for (local_78 = 0; local_78 < DAT_0058ca8c; local_78 = local_78 + 1) {
    iVar2 = *(int *)(&DAT_0058baec + local_78 * 4);
    *(undefined4 *)(iVar2 + 0x70) = 0;
    *(undefined4 *)(iVar2 + 0x74) = 0;
    *(undefined4 *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x78) = 0;
  }
  FUN_0043f7bc(param_1);
  DAT_005636cc = 0;
  DAT_005636d0 = 0;
  DAT_0057a74c = FUN_0053d180();
  puVar3 = (undefined4 *)FUN_00540ec4(local_14,&DAT_0055724a);
  FUN_0042dc3c(param_1,*puVar3,0);
  FUN_00540fe8(local_14,2);
  *(undefined1 *)(param_1 + 0xe1b) = 1;
  FUN_0046c894();
  FUN_0048e9b4();
  if (DAT_0057a74c % 0x50 == 1) {
    _DAT_005636b0 = _DAT_005636b0 - 1.1;
  }
  DAT_0057a6f8 = 1;
  *in_FS_OFFSET = local_38;
  return;
}




