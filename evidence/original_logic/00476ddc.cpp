0x00476ddc FUN_00476ddc recovered/native/main/decompiled.cpp:37988
// Entry 00476ddc, recovered name FUN_00476ddc

void FUN_00476ddc(void)

{
  int iVar1;
  double dVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  int in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined1 *puVar7;
  int local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined4 local_58;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_00566b78);
  FUN_004016e8(local_8);
  local_60 = 0.0;
  local_68 = in_stack_0000000c;
  uStack_64 = in_stack_00000010;
  for (local_7c = 0; local_7c < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x104);
      local_7c = local_7c + 1) {
    FUN_004016e8(local_c,in_stack_00000004,*(int *)(&DAT_00585850 + in_stack_00000004 * 4),
                 *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_7c * 4));
    FUN_00452acc();
    puVar7 = local_c;
    FUN_00540ec4(local_10,&DAT_00563df4);
    cVar3 = FUN_005410cc(puVar7,local_10);
    FUN_00540fe8(local_10,2);
    FUN_00540fe8(local_c,2);
    if (cVar3 != '\0') {
      local_60 = *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x5b8 + local_7c * 8)
                 + local_60;
    }
  }
  if (1e-20 <= local_60) {
    if (local_60 < (double)CONCAT44(in_stack_00000010,in_stack_0000000c)) {
      local_68 = (undefined4)local_60;
      uStack_64 = local_60._4_4_;
    }
    for (local_80 = 0; local_80 < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x104);
        local_80 = local_80 + 1) {
      FUN_004016e8(local_14,*(int *)(&DAT_00585850 + in_stack_00000004 * 4),local_80,
                   *(undefined4 *)
                    (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_80 * 4));
      FUN_00452acc();
      puVar7 = local_14;
      FUN_00540ec4(local_18,&DAT_00563dfb);
      cVar3 = FUN_005410cc(puVar7,local_18);
      if (cVar3 == '\0') {
        FUN_004016e8(local_1c,local_80,in_stack_00000004,
                     *(undefined4 *)
                      (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_80 * 4));
        FUN_00452acc();
        puVar7 = local_1c;
        FUN_00540ec4(local_20,&DAT_00563e02);
        cVar3 = FUN_005410cc(puVar7,local_20);
        uVar6 = (uint)(cVar3 != '\0');
        FUN_00540fe8(local_20,2);
        FUN_00540fe8(local_1c,2);
        if (uVar6 != 0) goto LAB_004770dc;
        FUN_004016e8(local_24,*(int *)(&DAT_00585850 + in_stack_00000004 * 4),local_80,
                     *(undefined4 *)
                      (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_80 * 4));
        FUN_00452acc();
        puVar7 = local_24;
        FUN_00540ec4(local_28,&DAT_00563e09);
        cVar3 = FUN_005410cc(puVar7,local_28);
        uVar6 = (uint)(cVar3 != '\0');
        FUN_00540fe8(local_28,2);
        FUN_00540fe8(local_24,2);
        if (uVar6 != 0) goto LAB_004770dc;
        FUN_004016e8(local_2c,*(int *)(&DAT_00585850 + in_stack_00000004 * 4),local_80,
                     *(undefined4 *)
                      (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_80 * 4));
        FUN_00452acc();
        puVar7 = local_2c;
        FUN_00540ec4(local_30,&DAT_00563e10);
        cVar3 = FUN_005410cc(puVar7,local_30);
        uVar6 = (uint)(cVar3 != '\0');
        FUN_00540fe8(local_30,2);
        FUN_00540fe8(local_2c,2);
        if (uVar6 != 0) goto LAB_004770dc;
        cVar3 = '\0';
      }
      else {
LAB_004770dc:
        cVar3 = '\x01';
      }
      FUN_00540fe8(local_18,2);
      FUN_00540fe8(local_14,2);
      if (cVar3 != '\0') {
        FUN_00541018(local_8,*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + local_80 * 4 + 0x108)
        ;
        dVar2 = *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x8d8 + local_80 * 8)
                * ((double)CONCAT44(uStack_64,local_68) / local_60);
        *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x8d8 + local_80 * 8) =
             *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x8d8 + local_80 * 8) -
             dVar2;
        iVar4 = FUN_00461db4();
        if (iVar4 == -1) {
          FUN_00541018(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) +
                       *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104) * 4 + 0x108
                       ,local_8);
          iVar4 = *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104);
          iVar1 = *(int *)(&DAT_00585850 + in_stack_00000008 * 4);
          local_78 = SUB84(dVar2,0);
          *(undefined4 *)(iVar1 + 0x8d8 + iVar4 * 8) = local_78;
          uStack_74 = (undefined4)((ulonglong)dVar2 >> 0x20);
          *(undefined4 *)(iVar1 + 0x8dc + iVar4 * 8) = uStack_74;
          *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104) =
               *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104) + 1;
          if (99 < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104)) {
            DAT_0057a6f8 = 0;
            puVar5 = (undefined4 *)FUN_00540ec4(local_34,&DAT_00563e19);
            FUN_00500350(*puVar5);
            FUN_00540fe8(local_34,2);
          }
        }
        else {
          iVar4 = FUN_00461db4();
          *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + iVar4 * 8) =
               dVar2 + *(double *)
                        (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + iVar4 * 8);
        }
      }
    }
    dVar2 = *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x4320) +
            *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x4338);
    if (1e-10 < dVar2 + (double)CONCAT44(uStack_64,local_68)) {
      *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x88) =
           (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x88) *
            (double)CONCAT44(uStack_64,local_68) +
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x88) * dVar2) /
           (dVar2 + (double)CONCAT44(uStack_64,local_68));
    }
    FUN_00461e54();
    FUN_00461e54();
    FUN_00540fe8(local_8,2,in_stack_00000008);
    *in_FS_OFFSET = local_58;
  }
  else {
    FUN_00540fe8(local_8,2);
    *in_FS_OFFSET = local_58;
  }
  return;
}




