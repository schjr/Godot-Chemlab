// Entry 0046d414, recovered name FUN_0046d414

void FUN_0046d414(void)

{
  double dVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *in_FS_OFFSET;
  int aiStack_588 [102];
  undefined4 auStack_3f0 [204];
  int local_c0;
  int local_bc;
  undefined4 *local_9c;
  undefined4 *local_98;
  undefined4 *local_94;
  undefined4 *local_90;
  undefined4 *local_8c;
  undefined4 *local_88;
  int local_80;
  int local_7c;
  int local_78;
  undefined4 local_74;
  undefined2 local_64;
  int local_58;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
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
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_00534be0(&DAT_005663bc);
  for (local_78 = 0; local_78 < DAT_0058ca8c; local_78 = local_78 + 1) {
    *(undefined4 *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x44) = 0;
    *(undefined4 *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x4c) = 0;
  }
  FUN_0046cdec();
  local_64 = 8;
  FUN_004016e8(&local_8);
  local_58 = local_58 + 1;
  local_64 = 0x20;
  FUN_004016e8(&local_c);
  local_58 = local_58 + 1;
  local_64 = 0x14;
  for (local_78 = 0; local_78 < DAT_0058ca8c; local_78 = local_78 + 1) {
    if (*(int *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x4c) != 1) {
      local_7c = 0;
      local_80 = 0;
      if ((100 < *(int *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x30)) &&
         (*(int *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x30) < 300)) {
        DAT_00590ef8 = local_78;
        FUN_00541018(&local_8,*(int *)(&DAT_0058baec + local_78 * 4) + 0x2c);
        FUN_00541018(&DAT_00590f00,*(int *)(&DAT_0058baec + local_78 * 4) + 4);
        local_64 = 0x2c;
        FUN_00540ec4(local_14,&DAT_00563c1b);
        local_58 = local_58 + 1;
        FUN_00541018(&DAT_00590f04,local_14);
        local_58 = local_58 + -1;
        FUN_00540fe8(local_14,2);
        DAT_00590f08 = 1;
        DAT_00590f0c = 0;
        local_64 = 0x38;
        FUN_004016e8(local_18,*(int *)(&DAT_0058baec + local_78 * 4),0,local_78,2,
                     *(undefined4 *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x38));
        local_58 = local_58 + 1;
        FUN_0046cee0();
        FUN_00541018(&local_c,local_18);
        local_58 = local_58 + -1;
        FUN_00540fe8(local_18,2);
        if (99 < DAT_00590ef4) {
          local_64 = 0x44;
          puVar7 = (undefined4 *)FUN_00540ec4(local_1c,&DAT_00563c1c);
          local_58 = local_58 + 1;
          FUN_00500350(*puVar7);
          local_58 = local_58 + -1;
          FUN_00540fe8(local_1c,2);
          local_58 = local_58 + -1;
          FUN_00540fe8(&local_c,2);
          local_58 = local_58 + -1;
          FUN_00540fe8(&local_8,2);
          *in_FS_OFFSET = local_74;
          return;
        }
        iVar8 = FUN_00453f98();
        if (*(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x38) == 0) {
          local_7c = 1;
        }
        FUN_00453f98();
        iVar8 = FUN_00453f98();
        iVar8 = *(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x14);
        iVar3 = FUN_00453f98();
        local_88 = (undefined4 *)(*(int *)(&DAT_00585850 + iVar3 * 4) + 0xfc);
        uVar4 = (**(code **)(*(int *)*local_88 + 0x20))();
        iVar3 = (int)uVar4 >> 1;
        if (iVar3 < 0) {
          iVar3 = iVar3 + (uint)((uVar4 & 1) != 0);
        }
        iVar5 = FUN_00453f98();
        if ((double)(iVar8 + iVar3) - *(double *)(*(int *)(&DAT_00585850 + iVar5 * 4) + 0x30) <
            (double)*(int *)(*(int *)(&DAT_0058baec + DAT_00590ef8 * 4) + 0xc)) {
          local_7c = 1;
        }
        if ((*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30) == 0x3e9) ||
           (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30) == 0x3ea)) {
          if (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c) == 0) {
            local_80 = 1;
          }
          if ((100 < *(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c)) &&
             (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c) < 300)) {
            iVar8 = FUN_00453f98();
            if (*(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x38) == 0) {
              local_80 = 1;
            }
            FUN_00453f98();
            uVar6 = *(undefined4 *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x38);
            iVar8 = FUN_00453f98();
            iVar8 = *(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x14);
            iVar3 = FUN_00453f98(DAT_00590efc,*(int *)(&DAT_0058baec + DAT_00590efc * 4),uVar6,
                                 *(undefined4 *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x38))
            ;
            local_8c = (undefined4 *)(*(int *)(&DAT_00585850 + iVar3 * 4) + 0xfc);
            uVar4 = (**(code **)(*(int *)*local_8c + 0x20))();
            iVar3 = (int)uVar4 >> 1;
            if (iVar3 < 0) {
              iVar3 = iVar3 + (uint)((uVar4 & 1) != 0);
            }
            iVar5 = FUN_00453f98();
            if ((double)(iVar8 + iVar3) - *(double *)(*(int *)(&DAT_00585850 + iVar5 * 4) + 0x30) <
                (double)*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x14)) {
              local_80 = 1;
            }
          }
        }
        if ((*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c) == 0x3e9) ||
           (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c) == 0x3ea)) {
          if (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30) == 0) {
            local_80 = 1;
          }
          if ((100 < *(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30)) &&
             (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30) < 300)) {
            iVar8 = FUN_00453f98();
            if (*(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x38) == 0) {
              local_80 = 1;
            }
            FUN_00453f98();
            uVar6 = *(undefined4 *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x2c);
            iVar8 = FUN_00453f98();
            iVar8 = *(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x14);
            iVar3 = FUN_00453f98(DAT_00590efc,*(int *)(&DAT_0058baec + DAT_00590efc * 4),uVar6,
                                 *(undefined4 *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x2c))
            ;
            local_90 = (undefined4 *)(*(int *)(&DAT_00585850 + iVar3 * 4) + 0xfc);
            uVar4 = (**(code **)(*(int *)*local_90 + 0x20))();
            iVar3 = (int)uVar4 >> 1;
            if (iVar3 < 0) {
              iVar3 = iVar3 + (uint)((uVar4 & 1) != 0);
            }
            iVar5 = FUN_00453f98();
            if ((double)(iVar8 + iVar3) - *(double *)(*(int *)(&DAT_00585850 + iVar5 * 4) + 0x30) <
                (double)*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0xc)) {
              local_80 = 1;
            }
          }
        }
        if (local_7c == 0) {
          if (local_80 == 0) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0;
          }
          if (local_80 == 1) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
          }
          if (local_80 == 2) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0xffffffff;
          }
        }
        if (local_7c == 1) {
          if (local_80 == 0) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0xffffffff;
          }
          if (local_80 == 1) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
          }
          if (local_80 == 2) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0xffffffff;
          }
        }
        if (local_7c == 2) {
          if (local_80 == 0) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
          }
          if (local_80 == 1) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
          }
          if (local_80 == 2) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
          }
        }
        local_64 = 0x50;
        FUN_00540ec4(local_20,&DAT_00563c30);
        local_58 = local_58 + 1;
        cVar2 = FUN_005410cc(&local_c,local_20);
        if (cVar2 == '\0') {
          FUN_00540ec4(local_24,&DAT_00563c33);
          local_58 = local_58 + 1;
          cVar2 = FUN_005410cc(&local_c,local_24);
          uVar4 = (uint)(cVar2 != '\0');
          local_58 = local_58 + -1;
          FUN_00540fe8(local_24,2);
          if (uVar4 != 0) goto LAB_0046db5e;
          cVar2 = '\0';
        }
        else {
LAB_0046db5e:
          cVar2 = '\x01';
        }
        local_58 = local_58 + -1;
        FUN_00540fe8(local_20,2);
        if (cVar2 == '\0') {
          uVar6 = local_8;
          iVar8 = FUN_00453f98();
          dVar1 = *(double *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0xa8);
          iVar8 = FUN_00453f98(iVar8,*(int *)(&DAT_00585850 + iVar8 * 4),uVar6,local_c);
          if (dVar1 <= *(double *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0xa8)) {
            if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == 0) {
              *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0xffffffff;
            }
            if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == 1) {
              *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
            }
          }
          else {
            if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == 0) {
              *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
            }
            if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == -1) {
              *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
            }
          }
        }
        else {
          if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == 0) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
          }
          if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == -1) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
          }
        }
        FUN_00541018(&DAT_0058fc38 + DAT_00590ef4 * 0x30,&local_8);
        FUN_00541018(&DAT_0058fc3c + DAT_00590ef4 * 0x30,&local_c);
        FUN_00541018(&DAT_0058fc40 + DAT_00590ef4 * 0x30,&DAT_00590f00);
        FUN_00541018(&DAT_0058fc44 + DAT_00590ef4 * 0x30,&DAT_00590f04);
        *(undefined4 *)(&DAT_0058fc48 + DAT_00590ef4 * 0x30) = DAT_00590f08;
        *(undefined4 *)(&DAT_0058fc4c + DAT_00590ef4 * 0x30) = DAT_00590f0c;
        DAT_00590ef4 = DAT_00590ef4 + 1;
      }
      if ((100 < *(int *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x3c)) &&
         (*(int *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x3c) < 300)) {
        DAT_00590ef8 = local_78;
        FUN_00541018(&local_8,*(int *)(&DAT_0058baec + local_78 * 4) + 0x38);
        FUN_00541018(&DAT_00590f00,*(int *)(&DAT_0058baec + local_78 * 4) + 4);
        local_64 = 0x5c;
        FUN_00540ec4(local_28,&DAT_00563c3c);
        local_58 = local_58 + 1;
        FUN_00541018(&DAT_00590f04,local_28);
        local_58 = local_58 + -1;
        FUN_00540fe8(local_28,2);
        DAT_00590f08 = 2;
        DAT_00590f0c = 0;
        local_64 = 0x68;
        FUN_004016e8(local_2c,*(int *)(&DAT_0058baec + local_78 * 4),0,local_78,1,
                     *(undefined4 *)(*(int *)(&DAT_0058baec + local_78 * 4) + 0x2c));
        local_58 = local_58 + 1;
        FUN_0046cee0();
        FUN_00541018(&local_c,local_2c);
        local_58 = local_58 + -1;
        FUN_00540fe8(local_2c,2);
        if (99 < DAT_00590ef4) {
          local_64 = 0x74;
          puVar7 = (undefined4 *)FUN_00540ec4(local_30,&DAT_00563c3d);
          local_58 = local_58 + 1;
          FUN_00500350(*puVar7);
          local_58 = local_58 + -1;
          FUN_00540fe8(local_30,2);
          local_58 = local_58 + -1;
          FUN_00540fe8(&local_c,2);
          local_58 = local_58 + -1;
          FUN_00540fe8(&local_8,2);
          *in_FS_OFFSET = local_74;
          return;
        }
        iVar8 = FUN_00453f98();
        if (*(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x38) == 0) {
          local_7c = 1;
        }
        FUN_00453f98();
        iVar8 = FUN_00453f98();
        iVar8 = *(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x14);
        iVar3 = FUN_00453f98();
        local_94 = (undefined4 *)(*(int *)(&DAT_00585850 + iVar3 * 4) + 0xfc);
        uVar4 = (**(code **)(*(int *)*local_94 + 0x20))();
        iVar3 = (int)uVar4 >> 1;
        if (iVar3 < 0) {
          iVar3 = iVar3 + (uint)((uVar4 & 1) != 0);
        }
        iVar5 = FUN_00453f98();
        if ((double)(iVar8 + iVar3) - *(double *)(*(int *)(&DAT_00585850 + iVar5 * 4) + 0x30) <
            (double)*(int *)(*(int *)(&DAT_0058baec + DAT_00590ef8 * 4) + 0xc)) {
          local_7c = 1;
        }
        if ((*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30) == 0x3e9) ||
           (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30) == 0x3ea)) {
          if (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c) == 0) {
            local_80 = 1;
          }
          if ((100 < *(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c)) &&
             (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c) < 300)) {
            iVar8 = FUN_00453f98();
            if (*(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x38) == 0) {
              local_80 = 1;
            }
            FUN_00453f98();
            uVar6 = *(undefined4 *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x38);
            iVar8 = FUN_00453f98();
            iVar8 = *(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x14);
            iVar3 = FUN_00453f98(DAT_00590efc,*(int *)(&DAT_0058baec + DAT_00590efc * 4),uVar6,
                                 *(undefined4 *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x38))
            ;
            local_98 = (undefined4 *)(*(int *)(&DAT_00585850 + iVar3 * 4) + 0xfc);
            uVar4 = (**(code **)(*(int *)*local_98 + 0x20))();
            iVar3 = (int)uVar4 >> 1;
            if (iVar3 < 0) {
              iVar3 = iVar3 + (uint)((uVar4 & 1) != 0);
            }
            iVar5 = FUN_00453f98();
            if ((double)(iVar8 + iVar3) - *(double *)(*(int *)(&DAT_00585850 + iVar5 * 4) + 0x30) <
                (double)*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x14)) {
              local_80 = 1;
            }
          }
        }
        if ((*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c) == 0x3e9) ||
           (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x3c) == 0x3ea)) {
          if (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30) == 0) {
            local_80 = 1;
          }
          if ((100 < *(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30)) &&
             (*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x30) < 300)) {
            iVar8 = FUN_00453f98();
            if (*(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x38) == 0) {
              local_80 = 1;
            }
            FUN_00453f98();
            uVar6 = *(undefined4 *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x2c);
            iVar8 = FUN_00453f98();
            iVar8 = *(int *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0x14);
            iVar3 = FUN_00453f98(DAT_00590efc,*(int *)(&DAT_0058baec + DAT_00590efc * 4),uVar6,
                                 *(undefined4 *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0x2c))
            ;
            local_9c = (undefined4 *)(*(int *)(&DAT_00585850 + iVar3 * 4) + 0xfc);
            uVar4 = (**(code **)(*(int *)*local_9c + 0x20))();
            iVar3 = (int)uVar4 >> 1;
            if (iVar3 < 0) {
              iVar3 = iVar3 + (uint)((uVar4 & 1) != 0);
            }
            iVar5 = FUN_00453f98();
            if ((double)(iVar8 + iVar3) - *(double *)(*(int *)(&DAT_00585850 + iVar5 * 4) + 0x30) <
                (double)*(int *)(*(int *)(&DAT_0058baec + DAT_00590efc * 4) + 0xc)) {
              local_80 = 1;
            }
          }
        }
        if (local_7c == 0) {
          if (local_80 == 0) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0;
          }
          if (local_80 == 1) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
          }
          if (local_80 == 2) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0xffffffff;
          }
        }
        if (local_7c == 1) {
          if (local_80 == 0) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0xffffffff;
          }
          if (local_80 == 1) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
          }
          if (local_80 == 2) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0xffffffff;
          }
        }
        if (local_7c == 2) {
          if (local_80 == 0) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
          }
          if (local_80 == 1) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
          }
          if (local_80 == 2) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
          }
        }
        local_64 = 0x80;
        FUN_00540ec4(local_34,&DAT_00563c51);
        local_58 = local_58 + 1;
        cVar2 = FUN_005410cc(&local_c,local_34);
        if (cVar2 == '\0') {
          FUN_00540ec4(local_38,&DAT_00563c54);
          local_58 = local_58 + 1;
          cVar2 = FUN_005410cc(&local_c,local_38);
          uVar4 = (uint)(cVar2 != '\0');
          local_58 = local_58 + -1;
          FUN_00540fe8(local_38,2);
          if (uVar4 != 0) goto LAB_0046e404;
          cVar2 = '\0';
        }
        else {
LAB_0046e404:
          cVar2 = '\x01';
        }
        local_58 = local_58 + -1;
        FUN_00540fe8(local_34,2);
        if (cVar2 == '\0') {
          uVar6 = local_8;
          iVar8 = FUN_00453f98();
          dVar1 = *(double *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0xa8);
          iVar8 = FUN_00453f98(iVar8,*(int *)(&DAT_00585850 + iVar8 * 4),uVar6,local_c);
          if (dVar1 <= *(double *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0xa8)) {
            if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == 0) {
              *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 0xffffffff;
            }
            if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == 1) {
              *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
            }
          }
          else {
            if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == 0) {
              *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
            }
            if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == -1) {
              *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
            }
          }
        }
        else {
          if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == 0) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 1;
          }
          if (*(int *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) == -1) {
            *(undefined4 *)(&DAT_0058fc34 + DAT_00590ef4 * 0x30) = 2;
          }
        }
        FUN_00541018(&DAT_0058fc38 + DAT_00590ef4 * 0x30,&local_8);
        FUN_00541018(&DAT_0058fc3c + DAT_00590ef4 * 0x30,&local_c);
        FUN_00541018(&DAT_0058fc40 + DAT_00590ef4 * 0x30,&DAT_00590f00);
        FUN_00541018(&DAT_0058fc44 + DAT_00590ef4 * 0x30,&DAT_00590f04);
        *(undefined4 *)(&DAT_0058fc48 + DAT_00590ef4 * 0x30) = DAT_00590f08;
        *(undefined4 *)(&DAT_0058fc4c + DAT_00590ef4 * 0x30) = DAT_00590f0c;
        DAT_00590ef4 = DAT_00590ef4 + 1;
      }
    }
  }
  local_64 = 0x8c;
  FUN_004016e8(local_10);
  local_58 = local_58 + 1;
  local_64 = 0x14;
  for (local_78 = 0; local_78 < DAT_00590ef4; local_78 = local_78 + 1) {
    if (*(int *)(&DAT_0058fc34 + local_78 * 0x30) == -1) {
      FUN_00541018(local_10,&DAT_0058fc38 + local_78 * 0x30);
      FUN_00541018(&DAT_0058fc38 + local_78 * 0x30,&DAT_0058fc3c + local_78 * 0x30);
      FUN_00541018(&DAT_0058fc3c + local_78 * 0x30,local_10);
      FUN_00541018(local_10,&DAT_0058fc40 + local_78 * 0x30);
      FUN_00541018(&DAT_0058fc40 + local_78 * 0x30,&DAT_0058fc44 + local_78 * 0x30);
      FUN_00541018(&DAT_0058fc44 + local_78 * 0x30,local_10);
      local_64 = 0x98;
      FUN_00540f38(local_3c,*(undefined4 *)(&DAT_0058fc48 + local_78 * 0x30));
      local_58 = local_58 + 1;
      FUN_00541018(local_10,local_3c);
      local_58 = local_58 + -1;
      FUN_00540fe8(local_3c,2);
      *(undefined4 *)(&DAT_0058fc48 + local_78 * 0x30) =
           *(undefined4 *)(&DAT_0058fc4c + local_78 * 0x30);
      uVar6 = FUN_005412f8(local_10);
      *(undefined4 *)(&DAT_0058fc4c + local_78 * 0x30) = uVar6;
      *(undefined4 *)(&DAT_0058fc34 + local_78 * 0x30) = 1;
    }
  }
  local_78 = 0;
  do {
    if (DAT_00590ef4 <= local_78) {
      local_58 = local_58 + -1;
      FUN_00540fe8(local_10,2);
      local_58 = local_58 + -1;
      FUN_00540fe8(&local_c,2);
      local_58 = local_58 + -1;
      FUN_00540fe8(&local_8,2);
      *in_FS_OFFSET = local_74;
      return;
    }
    if (*(int *)(&DAT_0058fc34 + local_78 * 0x30) == 1) {
      local_64 = 0xa4;
      FUN_00540ec4(local_40,&DAT_00563c5d);
      local_58 = local_58 + 1;
      cVar2 = FUN_005410cc(&DAT_0058fc38 + local_78 * 0x30,local_40);
      if (cVar2 == '\0') {
        FUN_00540ec4(local_44,&DAT_00563c60);
        local_58 = local_58 + 1;
        cVar2 = FUN_005410cc(&DAT_0058fc38 + local_78 * 0x30,local_44);
        uVar4 = (uint)(cVar2 != '\0');
        local_58 = local_58 + -1;
        FUN_00540fe8(local_44,2);
        if (uVar4 != 0) goto LAB_0046e81c;
        cVar2 = '\0';
      }
      else {
LAB_0046e81c:
        cVar2 = '\x01';
      }
      local_58 = local_58 + -1;
      FUN_00540fe8(local_40,2);
      if (cVar2 != '\0') {
        local_64 = 0xb0;
        puVar7 = (undefined4 *)FUN_00540ec4(local_48,&DAT_00563c69);
        local_58 = local_58 + 1;
        FUN_00500350(*puVar7);
        local_58 = local_58 + -1;
        FUN_00540fe8(local_48,2);
      }
      FUN_00541018(local_10,&DAT_0058fc38 + local_78 * 0x30);
      local_bc = 1;
      local_64 = 0x14;
      for (local_c0 = 0; local_c0 < DAT_00590ef4; local_c0 = local_c0 + 1) {
        if (((local_c0 != local_78) &&
            (cVar2 = FUN_005410cc(&DAT_0058fc38 + local_c0 * 0x30,local_10), cVar2 != '\0')) &&
           (*(int *)(&DAT_0058fc34 + local_c0 * 0x30) == 1)) {
          aiStack_588[local_bc] = local_c0;
          local_64 = 0xbc;
          FUN_00540ec4(local_4c,&DAT_00563c79);
          local_58 = local_58 + 1;
          cVar2 = FUN_005410cc(&DAT_0058fc3c + local_c0 * 0x30,local_4c);
          if (cVar2 == '\0') {
            FUN_00540ec4(local_50,&DAT_00563c7c);
            local_58 = local_58 + 1;
            cVar2 = FUN_005410cc(&DAT_0058fc3c + local_c0 * 0x30,local_50);
            uVar4 = (uint)(cVar2 != '\0');
            local_58 = local_58 + -1;
            FUN_00540fe8(local_50,2);
            if (uVar4 != 0) goto LAB_0046e975;
            cVar2 = '\0';
          }
          else {
LAB_0046e975:
            cVar2 = '\x01';
          }
          local_58 = local_58 + -1;
          FUN_00540fe8(local_4c,2);
          iVar8 = local_bc;
          if (cVar2 == '\0') {
            iVar8 = FUN_00453f98();
            iVar3 = local_bc;
            iVar8 = *(int *)(&DAT_00585850 + iVar8 * 4);
            auStack_3f0[local_bc * 2] = *(undefined4 *)(iVar8 + 0xa8);
            auStack_3f0[iVar3 * 2 + 1] = *(undefined4 *)(iVar8 + 0xac);
          }
          else {
            auStack_3f0[local_bc * 2] = 0;
            auStack_3f0[iVar8 * 2 + 1] = 0;
          }
          local_bc = local_bc + 1;
        }
      }
      iVar8 = FUN_00453f98();
      *(double *)(&DAT_0058fc54 + local_78 * 0x30) =
           *(double *)(*(int *)(&DAT_00585850 + iVar8 * 4) + 0xa8) / (double)local_bc;
      if (*(double *)(&DAT_0058fc54 + local_78 * 0x30) < 0.0) {
        *(undefined4 *)(&DAT_0058fc54 + local_78 * 0x30) = 0;
        *(undefined4 *)(&DAT_0058fc58 + local_78 * 0x30) = 0;
      }
    }
    local_78 = local_78 + 1;
  } while( true );
}



