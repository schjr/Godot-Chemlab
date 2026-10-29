// Entry 00471650, recovered name FUN_00471650

/* WARNING: Removing unreachable block (ram,0x00472191) */
/* WARNING: Removing unreachable block (ram,0x004720f3) */
/* WARNING: Removing unreachable block (ram,0x004720db) */
/* WARNING: Removing unreachable block (ram,0x00472179) */
/* WARNING: Removing unreachable block (ram,0x00472216) */
/* WARNING: Removing unreachable block (ram,0x0047241b) */
/* WARNING: Removing unreachable block (ram,0x004721fc) */
/* WARNING: Removing unreachable block (ram,0x004725cd) */
/* WARNING: Removing unreachable block (ram,0x004725e2) */
/* WARNING: Removing unreachable block (ram,0x004725fa) */
/* WARNING: Removing unreachable block (ram,0x00472547) */
/* WARNING: Removing unreachable block (ram,0x0047222b) */
/* WARNING: Removing unreachable block (ram,0x0047210b) */
/* WARNING: Removing unreachable block (ram,0x004723ad) */
/* WARNING: Removing unreachable block (ram,0x00472398) */
/* WARNING: Removing unreachable block (ram,0x004722fa) */
/* WARNING: Removing unreachable block (ram,0x004721a6) */
/* WARNING: Removing unreachable block (ram,0x0047255f) */
/* WARNING: Removing unreachable block (ram,0x00472433) */
/* WARNING: Removing unreachable block (ram,0x0047244e) */
/* WARNING: Removing unreachable block (ram,0x00472312) */
/* WARNING: Removing unreachable block (ram,0x004723c8) */
/* WARNING: Removing unreachable block (ram,0x0047232a) */
/* WARNING: Removing unreachable block (ram,0x0047257a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00471650(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *in_FS_OFFSET;
  longdouble lVar10;
  undefined4 in_stack_00000004;
  int in_stack_00000008;
  undefined1 *puVar11;
  uint uStack_d4c;
  double adStack_d48 [300];
  undefined8 uStack_3e8;
  undefined8 local_c8;
  double local_c0;
  double local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 local_a4;
  undefined1 local_a3;
  byte local_a2;
  undefined1 local_a1;
  undefined1 local_a0;
  undefined1 local_9f;
  byte local_9e;
  undefined1 local_9d;
  uint local_9c;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  int local_60;
  undefined4 local_5c;
  undefined2 local_4c;
  int local_40;
  undefined1 local_38 [4];
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
  
  FUN_00534be0(&DAT_0056680c);
  local_b0 = 0;
  local_68 = 0.0;
  local_70 = 0;
  uStack_6c = 0;
  for (local_60 = 0; local_60 < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104);
      local_60 = local_60 + 1) {
    local_4c = 8;
    FUN_004016e8(local_8,local_60,in_stack_00000008,
                 *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x108 + local_60 * 4));
    local_40 = local_40 + 1;
    FUN_00452acc();
    puVar11 = local_8;
    FUN_00540ec4(local_c,&DAT_00563d1a);
    local_40 = local_40 + 1;
    cVar2 = FUN_005410cc(puVar11,local_c);
    local_40 = local_40 + -1;
    FUN_00540fe8(local_c,2);
    local_40 = local_40 + -1;
    FUN_00540fe8(local_8,2);
    if (cVar2 != '\0') {
      local_68 = *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x5b8 + local_60 * 8)
                 + local_68;
    }
    local_4c = 0x14;
    FUN_00540ec4(local_10,&DAT_00563d21);
    local_40 = local_40 + 1;
    cVar2 = FUN_005410cc(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + local_60 * 4 + 0x108,
                         local_10);
    local_40 = local_40 + -1;
    FUN_00540fe8(local_10,2);
    if (cVar2 != '\0') {
      local_70 = *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x5b8 + local_60 * 8);
      uStack_6c = *(undefined4 *)
                   (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x5bc + local_60 * 8);
    }
  }
  if (local_68 < 1e-10) {
    *in_FS_OFFSET = local_5c;
    return;
  }
  for (local_60 = 0; local_60 < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104);
      local_60 = local_60 + 1) {
    local_4c = 0x20;
    FUN_004016e8(local_14,*(int *)(&DAT_00585850 + in_stack_00000008 * 4),local_60,
                 *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x108 + local_60 * 4));
    local_40 = local_40 + 1;
    FUN_00452acc();
    puVar11 = local_14;
    FUN_00540ec4(local_18,&DAT_00563d2b);
    local_40 = local_40 + 1;
    cVar2 = FUN_005410cc(puVar11,local_18);
    local_40 = local_40 + -1;
    FUN_00540fe8(local_18,2);
    local_40 = local_40 + -1;
    FUN_00540fe8(local_14,2);
    if (cVar2 != '\0') {
      iVar3 = FUN_00452d9c();
      local_9c = *(uint *)((&DAT_0057bc08)[iVar3] + 0x28);
      uStack_d4c = *(uint *)((&DAT_0057bc08)[iVar3] + 0x28) & 0xff;
      adStack_d48[local_b0 * 3] =
           ((double)uStack_d4c *
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x5b8 + local_60 * 8)) /
           local_68;
      uStack_d4c = local_9c >> 8 & 0xff;
      adStack_d48[local_b0 * 3 + 1] =
           ((double)uStack_d4c *
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x5b8 + local_60 * 8)) /
           local_68;
      uStack_d4c = local_9c >> 0x10 & 0xff;
      adStack_d48[local_b0 * 3 + 2] =
           ((double)uStack_d4c *
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x5b8 + local_60 * 8)) /
           local_68;
      local_b0 = local_b0 + 1;
    }
  }
  local_88 = 0.0;
  local_90 = 0.0;
  local_98 = 0.0;
  local_60 = 0;
  if (0 < local_b0) {
    do {
      local_88 = adStack_d48[local_60 * 3] + local_88;
      local_90 = adStack_d48[local_60 * 3 + 1] + local_90;
      local_98 = adStack_d48[local_60 * 3 + 2] + local_98;
      local_60 = local_60 + 1;
    } while (local_60 < local_b0);
  }
  local_a0 = FUN_005394fc();
  local_9f = FUN_005394fc();
  local_9e = FUN_005394fc();
  local_9d = 0;
  local_b0 = 0;
  local_80 = 0.0;
  for (local_60 = 0; local_60 < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104);
      local_60 = local_60 + 1) {
    local_4c = 0x2c;
    FUN_004016e8(local_1c,in_stack_00000008,*(int *)(&DAT_00585850 + in_stack_00000008 * 4),
                 *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x108 + local_60 * 4));
    local_40 = local_40 + 1;
    FUN_00452acc();
    puVar11 = local_1c;
    FUN_00540ec4(local_20,&DAT_00563d32);
    local_40 = local_40 + 1;
    cVar2 = FUN_005410cc(puVar11,local_20);
    if (cVar2 == '\0') {
      FUN_004016e8(local_24,local_60,in_stack_00000008,
                   *(undefined4 *)
                    (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x108 + local_60 * 4));
      local_40 = local_40 + 1;
      FUN_00452acc();
      puVar11 = local_24;
      FUN_00540ec4(local_28,&DAT_00563d39);
      local_40 = local_40 + 1;
      cVar2 = FUN_005410cc(puVar11,local_28);
      uVar9 = (uint)(cVar2 != '\0');
      local_40 = local_40 + -1;
      FUN_00540fe8(local_28,2);
      local_40 = local_40 + -1;
      FUN_00540fe8(local_24,2);
      if (uVar9 != 0) goto LAB_00471ad7;
LAB_00471af6:
      cVar2 = '\0';
    }
    else {
LAB_00471ad7:
      if (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + local_60 * 8) <=
          1e-10) goto LAB_00471af6;
      cVar2 = '\x01';
    }
    local_40 = local_40 + -1;
    FUN_00540fe8(local_20,2);
    local_40 = local_40 + -1;
    FUN_00540fe8(local_1c,2);
    if ((cVar2 != '\0') &&
       (iVar4 = FUN_00452d9c(), iVar3 = local_b0, *(int *)((&DAT_0057bc08)[iVar4] + 0x28) != 0)) {
      local_78 = (*(double *)
                   (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + local_60 * 8) /
                 (double)CONCAT44(uStack_6c,local_70)) * 1000.0;
      *(undefined4 *)(&uStack_3e8 + local_b0) = (undefined4)local_78;
      *(undefined4 *)((int)&uStack_3e8 + iVar3 * 8 + 4) = local_78._4_4_;
      local_80 = local_78 + local_80;
      iVar3 = FUN_00452d9c();
      local_9c = *(uint *)((&DAT_0057bc08)[iVar3] + 0x28);
      if (local_78 <= 0.5) {
        uStack_d4c = local_9c & 0xff;
        adStack_d48[local_b0 * 3] =
             (double)(235.0 - (235.0 - (float)uStack_d4c) * (float)local_78 * 2.0);
        uStack_d4c = local_9c >> 8 & 0xff;
        adStack_d48[local_b0 * 3 + 1] =
             (double)(245.0 - (245.0 - (float)uStack_d4c) * (float)local_78 * 2.0);
        uStack_d4c = local_9c >> 0x10 & 0xff;
        adStack_d48[local_b0 * 3 + 2] =
             (double)(248.0 - (248.0 - (float)uStack_d4c) * (float)local_78 * 2.0);
      }
      else {
        uStack_d4c = local_9c & 0xff;
        adStack_d48[local_b0 * 3] = (double)uStack_d4c;
        uStack_d4c = local_9c >> 8 & 0xff;
        adStack_d48[local_b0 * 3 + 1] = (double)uStack_d4c;
        uStack_d4c = local_9c >> 0x10 & 0xff;
        adStack_d48[local_b0 * 3 + 2] = (double)uStack_d4c;
      }
      local_b0 = local_b0 + 1;
    }
  }
  local_88 = 0.0;
  local_90 = 0.0;
  local_98 = 0.0;
  local_60 = 0;
  if (0 < local_b0) {
    do {
      local_88 = (adStack_d48[local_60 * 3] * (double)(&uStack_3e8)[local_60]) / local_80 + local_88
      ;
      local_90 = (adStack_d48[local_60 * 3 + 1] * (double)(&uStack_3e8)[local_60]) / local_80 +
                 local_90;
      local_98 = (adStack_d48[local_60 * 3 + 2] * (double)(&uStack_3e8)[local_60]) / local_80 +
                 local_98;
      local_60 = local_60 + 1;
    } while (local_60 < local_b0);
  }
  local_a4 = FUN_005394fc();
  local_a3 = FUN_005394fc();
  local_a2 = FUN_005394fc();
  if (local_b0 == 0) {
    local_a4 = local_a0;
    local_a3 = local_9f;
    local_a2 = local_9e;
  }
  local_a1 = 0;
  uVar1 = FUN_005394fc();
  local_a8 = CONCAT31(local_a8._1_3_,uVar1);
  uVar1 = FUN_005394fc();
  local_a8._0_2_ = CONCAT11(uVar1,(undefined1)local_a8);
  uStack_d4c = (uint)local_9e;
  lVar10 = _DAT_00472cf4 * (longdouble)local_a2 * (longdouble)2.0 +
           _DAT_00472cf4 * (longdouble)uStack_d4c;
  uVar1 = FUN_005394fc();
  local_a8._0_3_ = CONCAT12(uVar1,(ushort)local_a8);
  local_a8 = (uint)(uint3)local_a8;
  local_b8 = 7.0;
  for (local_60 = 0; local_60 < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104);
      local_60 = local_60 + 1) {
    local_4c = 0x38;
    FUN_00540ec4(local_2c,&DAT_00563d40);
    local_40 = local_40 + 1;
    cVar2 = FUN_005410cc(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + local_60 * 4 + 0x108,
                         local_2c);
    local_40 = local_40 + -1;
    FUN_00540fe8(local_2c,2);
    if (cVar2 != '\0') {
      local_c0 = (*(double *)
                   (*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + local_60 * 8) /
                 (double)CONCAT44(uStack_6c,local_70)) * 1000.0;
      if (1e-100 < local_c0) {
        FUN_005397ec();
        local_b8 = (double)-lVar10;
      }
      break;
    }
  }
  for (local_60 = 0; local_60 < *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x104);
      local_60 = local_60 + 1) {
    local_4c = 0x44;
    FUN_00540ec4(local_30,&DAT_00563d49);
    local_40 = local_40 + 1;
    cVar2 = FUN_005410cc(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + local_60 * 4 + 0x108,
                         local_30);
    if ((cVar2 == '\0') ||
       (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + local_60 * 8) <= 1e-10
       )) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    local_40 = local_40 + -1;
    FUN_00540fe8(local_30,2);
    if (cVar2 != '\0') {
      if (3.2 <= local_b8) {
        if ((local_b8 < 3.2) || (4.5 <= local_b8)) {
          if (4.5 <= local_b8) {
            if (local_a8 == DAT_0057a748) {
              local_a8 = CONCAT13(local_a8._3_1_,0x7fe5ff);
            }
            else {
              iVar3 = (int)((local_a8 & 0xff) + 0xff) >> 1;
              local_a8._0_2_ = CONCAT11((char)(iVar3 + 0xcc >> 1),(char)iVar3);
              local_a8._0_3_ =
                   CONCAT12((char)((int)((ushort)local_a8 & 0xff) >> 1),(ushort)local_a8);
            }
          }
        }
        else if (local_a8 == DAT_0057a748) {
          local_a8 = CONCAT13(local_a8._3_1_,0x7fb9ff);
        }
        else {
          iVar3 = (int)((local_a8 & 0xff) + 0xff) >> 1;
          local_a8._0_2_ = CONCAT11((char)(iVar3 + 0x73 >> 1),(char)iVar3);
          local_a8._0_3_ = CONCAT12((char)((int)((ushort)local_a8 & 0xff) >> 1),(ushort)local_a8);
        }
      }
      else if (local_a8 == DAT_0057a748) {
        local_a8 = CONCAT13(local_a8._3_1_,0x7f7fff);
      }
      else {
        iVar3 = (int)((local_a8 & 0xff) + 0xdc) >> 1;
        local_a8._0_2_ = CONCAT11((char)(iVar3 + 0x32 >> 1),(char)iVar3);
        local_a8._0_3_ =
             CONCAT12((char)((int)(((ushort)local_a8 & 0xff) + 0x32) >> 1),(ushort)local_a8);
      }
    }
    local_4c = 0x50;
    FUN_00540ec4(local_34,&DAT_00563d58);
    local_40 = local_40 + 1;
    cVar2 = FUN_005410cc(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + local_60 * 4 + 0x108,
                         local_34);
    if ((cVar2 == '\0') ||
       (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + local_60 * 8) <= 1e-10
       )) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    local_40 = local_40 + -1;
    FUN_00540fe8(local_34,2);
    if (cVar2 != '\0') {
      if (5.0 <= local_b8) {
        if ((local_b8 < 5.0) || (8.0 <= local_b8)) {
          if (8.0 <= local_b8) {
            if (local_a8 == DAT_0057a748) {
              local_a8 = CONCAT13(local_a8._3_1_,0xd9a7a2);
            }
            else {
              iVar3 = (int)((local_a8 & 0xff) + 0x46) >> 1;
              local_a8._0_2_ = CONCAT11((char)(iVar3 + 0x50 >> 1),(char)iVar3);
              local_a8._0_3_ =
                   CONCAT12((char)((int)(((ushort)local_a8 & 0xff) + 0xb4) >> 1),(ushort)local_a8);
            }
          }
        }
        else if (local_a8 == DAT_0057a748) {
          local_a8 = CONCAT13(local_a8._3_1_,0xc37fc3);
        }
        else {
          iVar3 = (local_a8 & 0xff) + 0x87;
          local_a8._0_2_ = CONCAT11((char)(iVar3 >> 2),(char)(iVar3 >> 1));
          local_a8._0_3_ =
               CONCAT12((char)((int)(((ushort)local_a8 & 0xff) + 0x87) >> 1),(ushort)local_a8);
        }
      }
      else if (local_a8 == DAT_0057a748) {
        local_a8 = CONCAT13(local_a8._3_1_,0x7f7fff);
      }
      else {
        iVar3 = (int)((local_a8 & 0xff) + 0xdc) >> 1;
        local_a8._0_2_ = CONCAT11((char)(iVar3 + 0x32 >> 1),(char)iVar3);
        local_a8._0_3_ =
             CONCAT12((char)((int)(((ushort)local_a8 & 0xff) + 0x32) >> 1),(ushort)local_a8);
      }
    }
    local_4c = 0x5c;
    FUN_00540ec4(local_38,&DAT_00563d65);
    local_40 = local_40 + 1;
    cVar2 = FUN_005410cc(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + local_60 * 4 + 0x108,
                         local_38);
    if ((cVar2 == '\0') ||
       (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x8d8 + local_60 * 8) <= 1e-10
       )) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    local_40 = local_40 + -1;
    FUN_00540fe8(local_38,2);
    if ((cVar2 != '\0') && (8.0 <= local_b8)) {
      if ((local_b8 < 8.0) || (10.0 <= local_b8)) {
        if (10.0 <= local_b8) {
          if (local_a8 == DAT_0057a748) {
            local_a8 = CONCAT13(local_a8._3_1_,0x9d7ff0);
          }
          else {
            iVar3 = (local_a8 & 0xff) + 0xe1;
            local_a8._0_2_ = CONCAT11((char)(iVar3 >> 2),(char)(iVar3 >> 1));
            local_a8._0_3_ =
                 CONCAT12((char)((int)(((ushort)local_a8 & 0xff) + 0x3c) >> 1),(ushort)local_a8);
          }
        }
      }
      else if (local_a8 == DAT_0057a748) {
        local_a8 = CONCAT13(local_a8._3_1_,0xf0b6f0);
      }
      else {
        iVar3 = (int)((local_a8 & 0xff) + 0xe1) >> 1;
        local_a8._0_2_ = CONCAT11((char)(iVar3 + 0x6e >> 1),(char)iVar3);
        local_a8._0_3_ =
             CONCAT12((char)((int)(((ushort)local_a8 & 0xff) + 0xe1) >> 1),(ushort)local_a8);
      }
    }
  }
  uVar1 = FUN_005394fc();
  local_ac = CONCAT31(local_ac._1_3_,uVar1);
  uVar1 = FUN_005394fc();
  local_ac._0_2_ = CONCAT11(uVar1,(undefined1)local_ac);
  uStack_d4c = local_a8 >> 0x10 & 0xff;
  lVar10 = _DAT_00472d20 * (longdouble)uStack_d4c * (longdouble)6.0;
  uVar1 = FUN_005394fc();
  local_ac._0_3_ = CONCAT12(uVar1,(undefined2)local_ac);
  *(uint *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x3cd0) = local_a8;
  iVar3 = FUN_004e9448(in_stack_00000004);
  FUN_004e4158(*(undefined4 *)(iVar3 + 0x14),local_a8);
  iVar3 = FUN_004e9448(in_stack_00000004);
  FUN_004e3e50(*(undefined4 *)(iVar3 + 0x10),local_ac);
  iVar3 = FUN_004e9448(in_stack_00000004);
  FUN_004e4274(*(undefined4 *)(iVar3 + 0x14),0);
  if (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x28) < local_68) {
    local_68 = *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x28);
  }
  iVar3 = *(int *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 8);
  if (iVar3 < 0xcd) {
    if (iVar3 == 0xcc) {
      iVar3 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20
                          ))();
      local_c8 = (local_68 / *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x28)) *
                 (double)iVar3 + 0.5;
      if (53.7 < local_c8) {
        local_c8 = 53.7;
      }
      uVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x2c
                          ))();
      uVar6 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20
                          ))();
      (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))();
      uVar7 = FUN_005394fc();
      uVar8 = FUN_004e9448(in_stack_00000004);
      FUN_004e4744(uVar8,0,uVar7,uVar6,uVar5);
      goto switchD_00472782_default;
    }
    if (iVar3 < 0x6a) {
      if (1 < iVar3 - 0x65U) {
        if (iVar3 - 0x67U < 3) {
          FUN_005399d8();
          iVar3 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) +
                              0x20))();
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) +
                              0x20))();
          local_c8 = (double)iVar4 - (double)iVar3 * (double)lVar10;
          uVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) +
                              0x2c))();
          uVar6 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) +
                              0x20))();
          (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))()
          ;
          uVar7 = FUN_005394fc();
          uVar8 = FUN_004e9448(in_stack_00000004);
          FUN_004e4744(uVar8,0,uVar7,uVar6,uVar5);
        }
        goto switchD_00472782_default;
      }
    }
    else if (((2 < iVar3 - 0x6aU) && (iVar3 != 0x79)) && (1 < iVar3 - 0xc9U))
    goto switchD_00472782_default;
switchD_00472782_caseD_d4:
    iVar3 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))
                      ();
    local_c8 = (local_68 / *(double *)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0x28)) *
               (double)iVar3 + 0.5;
    uVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x2c))
                      ();
    uVar6 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))
                      ();
    (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))();
    uVar7 = FUN_005394fc();
    uVar8 = FUN_004e9448(in_stack_00000004);
    FUN_004e4744(uVar8,0,uVar7,uVar6,uVar5);
  }
  else {
    switch(iVar3) {
    case 0xcf:
    case 0xd0:
      local_c8 = local_68 * 4.0 + 22.0;
      uVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x2c
                          ))();
      iVar3 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20
                          ))();
      iVar3 = iVar3 + -0x16;
      (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))();
      uVar6 = FUN_005394fc();
      uVar7 = FUN_004e9448(in_stack_00000004);
      FUN_004e4744(uVar7,0,uVar6,iVar3,uVar5);
      break;
    case 0xd1:
      if (50.0 < local_68) {
        local_68 = 50.0;
      }
      FUN_005399d8();
      local_c8 = (double)(lVar10 * (longdouble)25.0 + (longdouble)30.0);
      uVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x2c
                          ))();
      iVar3 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20
                          ))();
      iVar3 = iVar3 + -0x1e;
      (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))();
      uVar6 = FUN_005394fc();
      uVar7 = FUN_004e9448(in_stack_00000004);
      FUN_004e4744(uVar7,0,uVar6,iVar3,uVar5);
      break;
    case 0xd2:
      local_c8 = (double)(_DAT_00472d4c * (longdouble)local_68 * (longdouble)2.0 + (longdouble)76.0)
      ;
      uVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x2c
                          ))();
      iVar3 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20
                          ))();
      iVar3 = iVar3 + -0x4d;
      (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))();
      uVar6 = FUN_005394fc();
      uVar7 = FUN_004e9448(in_stack_00000004);
      FUN_004e4744(uVar7,0,uVar6,iVar3,uVar5);
      break;
    case 0xd3:
      local_c8 = local_68 * 0.5 + 77.0;
      uVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x2c
                          ))();
      iVar3 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20
                          ))();
      iVar3 = iVar3 + -0x4d;
      (**(code **)(**(int **)(*(int *)(&DAT_00585850 + in_stack_00000008 * 4) + 0xfc) + 0x20))();
      uVar6 = FUN_005394fc();
      uVar7 = FUN_004e9448(in_stack_00000004);
      FUN_004e4744(uVar7,0,uVar6,iVar3,uVar5);
      break;
    case 0xd4:
      goto switchD_00472782_caseD_d4;
    }
  }
switchD_00472782_default:
  iVar3 = *(int *)(&DAT_00585850 + in_stack_00000008 * 4);
  *(undefined4 *)(iVar3 + 0x30) = (undefined4)local_c8;
  *(undefined4 *)(iVar3 + 0x34) = local_c8._4_4_;
  iVar3 = *(int *)(&DAT_00585850 + in_stack_00000008 * 4);
  *(undefined4 *)(iVar3 + 0x4320) = (undefined4)local_68;
  *(undefined4 *)(iVar3 + 0x4324) = local_68._4_4_;
  *in_FS_OFFSET = local_5c;
                    /* WARNING: Read-only address (ram,0x00472cf4) is written */
                    /* WARNING: Read-only address (ram,0x00472d20) is written */
                    /* WARNING: Read-only address (ram,0x00472d4c) is written */
  return;
}



