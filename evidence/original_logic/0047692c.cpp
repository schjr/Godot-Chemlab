// Entry 0047692c, recovered name FUN_0047692c

uint FUN_0047692c(void)

{
  bool bVar1;
  uint3 uVar2;
  uint uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint *in_FS_OFFSET;
  undefined4 in_stack_00000004;
  int in_stack_00000008;
  undefined1 *puVar10;
  double adStack_9dc [300];
  double local_7c;
  int local_74;
  undefined4 local_70;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  uint local_68;
  double local_64;
  double local_5c;
  double local_54;
  double local_4c;
  double local_44;
  int local_3c;
  uint local_38;
  undefined2 local_28;
  int local_1c;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_00566aa8);
  local_74 = 0;
  local_44 = *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x28) -
             *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x4320);
  if (0.0 < local_44) {
    local_4c = 0.0;
    for (local_3c = 0; local_3c < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104);
        local_3c = local_3c + 1) {
      local_28 = 8;
      FUN_004016e8(local_8,in_stack_00000008,*(int *)(&DAT_00585850 + in_stack_00000008 * 4),
                   *(undefined4 *)
                    (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x108 + local_3c * 4));
      local_1c = local_1c + 1;
      FUN_00452acc();
      puVar10 = local_8;
      FUN_00540ec4(local_c,&DAT_00563de6);
      local_1c = local_1c + 1;
      cVar4 = FUN_005410cc(puVar10,local_c);
      local_1c = local_1c + -1;
      FUN_00540fe8(local_c,2);
      local_1c = local_1c + -1;
      FUN_00540fe8(local_8,2);
      if (cVar4 != '\0') {
        local_4c = *(double *)
                    (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + local_3c * 8) * 22.4
                   * 1000.0 + local_4c;
      }
    }
    if (local_4c < 0.1) {
      *in_FS_OFFSET = local_38;
      local_38 = (uint)(ushort)((ushort)(local_4c < 0.1) << 8 | (ushort)NAN(local_4c) << 10 |
                               (ushort)(local_4c == 0.1) << 0xe);
    }
    else {
      for (local_3c = 0;
          local_3c < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104);
          local_3c = local_3c + 1) {
        local_28 = 0x14;
        FUN_004016e8(local_10,*(int *)(&DAT_00585850 + in_stack_00000008 * 4),local_3c,
                     *(undefined4 *)
                      (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x108 + local_3c * 4));
        local_1c = local_1c + 1;
        FUN_00452acc();
        puVar10 = local_10;
        FUN_00540ec4(local_14,&DAT_00563ded);
        local_1c = local_1c + 1;
        cVar4 = FUN_005410cc(puVar10,local_14);
        local_1c = local_1c + -1;
        FUN_00540fe8(local_14,2);
        local_1c = local_1c + -1;
        FUN_00540fe8(local_10,2);
        if (cVar4 != '\0') {
          local_7c = *(double *)
                      (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + local_3c * 8) *
                     22.4 * 1000.0;
          iVar6 = FUN_00452d9c();
          local_68 = *(uint *)((&DAT_0057bc08)[iVar6] + 0x28);
          adStack_9dc[local_74 * 3] =
               ((double)(*(uint *)((&DAT_0057bc08)[iVar6] + 0x28) & 0xff) * local_7c) / local_4c;
          adStack_9dc[local_74 * 3 + 1] = ((double)(local_68 >> 8 & 0xff) * local_7c) / local_4c;
          adStack_9dc[local_74 * 3 + 2] = ((double)(local_68 >> 0x10 & 0xff) * local_7c) / local_4c;
          local_74 = local_74 + 1;
        }
      }
      local_54 = 0.0;
      local_5c = 0.0;
      local_64 = 0.0;
      local_3c = 0;
      if (0 < local_74) {
        do {
          local_54 = adStack_9dc[local_3c * 3] + local_54;
          local_5c = adStack_9dc[local_3c * 3 + 1] + local_5c;
          local_64 = adStack_9dc[local_3c * 3 + 2] + local_64;
          local_3c = local_3c + 1;
        } while (local_3c < local_74);
      }
      local_6c = FUN_005394fc();
      local_6b = FUN_005394fc();
      local_6a = FUN_005394fc();
      local_69 = 0;
      if (local_4c < local_44) {
        uVar5 = FUN_005394fc();
        local_70 = CONCAT31(local_70._1_3_,uVar5);
        uVar5 = FUN_005394fc();
        local_70._0_2_ = CONCAT11(uVar5,(byte)local_70);
        uVar5 = FUN_005394fc();
        local_70._0_3_ = CONCAT12(uVar5,(undefined2)local_70);
        uVar2 = (uint3)local_70;
      }
      else {
        local_70._0_2_ = CONCAT11(local_6b,local_6c);
        local_70._0_3_ = CONCAT12(local_6a,(undefined2)local_70);
        uVar2 = (uint3)local_70;
      }
      local_70 = (uint)uVar2;
      uVar3 = local_70;
      local_70._0_1_ = (byte)uVar2;
      bVar1 = 0xfc < (byte)local_70;
      local_70 = uVar3;
      if (((bVar1) && (local_70._1_1_ = (byte)(uVar2 >> 8), bVar1 = 0xfc < local_70._1_1_, bVar1))
         && (local_70._2_1_ = (byte)(uVar2 >> 0x10), bVar1 = 0xfc < local_70._2_1_, bVar1)) {
        local_70 = 0xffffff;
      }
      iVar6 = FUN_004e9448(in_stack_00000004);
      FUN_004e3e50(*(undefined4 *)(iVar6 + 0x10),local_70);
      iVar6 = FUN_004e9448(in_stack_00000004);
      FUN_004e4158(*(undefined4 *)(iVar6 + 0x14),local_70);
      iVar6 = FUN_004e9448(in_stack_00000004);
      FUN_004e4274(*(undefined4 *)(iVar6 + 0x14),0);
      uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x2c
                          ))();
      (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))();
      uVar8 = FUN_005394fc();
      uVar9 = FUN_004e9448(in_stack_00000004);
      FUN_004e4744(uVar9,0,0,uVar8,uVar7);
      *in_FS_OFFSET = local_38;
    }
  }
  else {
    *in_FS_OFFSET = local_38;
  }
  return local_38;
}



