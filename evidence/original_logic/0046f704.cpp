// Entry 0046f704, recovered name FUN_0046f704

void FUN_0046f704(void)

{
  double dVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  char cVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  undefined4 uVar17;
  int extraout_EDX;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST0;
  longdouble lVar18;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble lVar19;
  undefined1 *puVar20;
  double local_a8;
  int local_98;
  int local_94;
  undefined8 local_90;
  double local_88;
  double local_80;
  double local_70;
  int local_60;
  undefined4 local_5c;
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
  
  FUN_00534be0(&DAT_005666c4);
  FUN_004016e8(&local_8);
  FUN_004016e8(&local_c);
  FUN_004016e8(local_10);
  local_60 = 0;
  do {
    if (DAT_00590ef4 <= local_60) {
      FUN_00540fe8(local_10,2);
      FUN_00540fe8(&local_c,2);
      FUN_00540fe8(&local_8,2);
      *in_FS_OFFSET = local_5c;
      return;
    }
    if (*(int *)(&DAT_0058fc34 + local_60 * 0x30) == 1) {
      FUN_00541018(&local_8,&DAT_0058fc38 + local_60 * 0x30);
      FUN_00541018(&local_c,&DAT_0058fc3c + local_60 * 0x30);
      iVar12 = FUN_00453f98();
      lVar18 = in_ST0;
      lVar5 = in_ST1;
      lVar6 = in_ST2;
      lVar7 = in_ST3;
      lVar8 = in_ST4;
      lVar9 = in_ST5;
      lVar10 = in_ST6;
      if (*(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x4328) < 0.0) {
        lVar19 = in_ST6;
        puVar13 = (undefined4 *)FUN_00540ec4(local_14,s_myrq_x__>all_qiti_mol<0_00563ccc);
        FUN_00500350(*puVar13);
        FUN_00540fe8(local_14,2);
        lVar18 = in_ST0;
        lVar5 = in_ST1;
        lVar6 = in_ST2;
        lVar7 = in_ST3;
        lVar8 = in_ST4;
        lVar9 = in_ST5;
        lVar10 = in_ST6;
        in_ST6 = lVar19;
      }
      in_ST5 = lVar10;
      in_ST4 = lVar9;
      in_ST3 = lVar8;
      in_ST2 = lVar7;
      in_ST1 = lVar6;
      in_ST0 = lVar5;
      FUN_00453f98();
      FUN_005394d4();
      if (lVar18 <= (longdouble)1e-20) {
        local_88 = 0.0;
      }
      else {
        iVar12 = FUN_00453f98();
        if (*(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x4328) <= 1e-20) {
          local_88 = 0.0;
        }
        else {
          iVar12 = FUN_00453f98();
          local_88 = *(double *)(&DAT_0058fc54 + local_60 * 0x30) /
                     *(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x4328);
        }
      }
      if (local_88 < 0.0) {
        local_88 = 0.0;
      }
      local_94 = 0;
      while( true ) {
        iVar12 = FUN_00453f98();
        if (*(int *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x104) <= local_94) break;
        uVar17 = local_8;
        iVar12 = FUN_00453f98();
        FUN_004016e8(local_18,local_94,uVar17,
                     *(undefined4 *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x108 + local_94 * 4));
        FUN_00452acc();
        puVar20 = local_18;
        FUN_00540ec4(local_1c,&DAT_00563ce4);
        cVar11 = FUN_005410cc(puVar20,local_1c);
        FUN_00540fe8(local_1c,2);
        FUN_00540fe8(local_18,2);
        if (cVar11 != '\0') {
          uVar17 = local_8;
          iVar12 = FUN_00453f98();
          FUN_00541018(local_10,*(int *)(&DAT_00585850 + iVar12 * 4) + local_94 * 4 + 0x108,uVar17);
          FUN_00540ec4(local_20,&DAT_00563ceb);
          cVar11 = FUN_005410cc(&local_c,local_20);
          FUN_00540fe8(local_20,2);
          if (cVar11 == '\0') {
            FUN_00540ec4(local_2c,&DAT_00563cf5);
            cVar11 = FUN_005410e4(&local_c,local_2c);
            if (cVar11 == '\0') {
LAB_0046fc28:
              cVar11 = '\0';
            }
            else {
              FUN_00540ec4(local_30,&DAT_00563cf8);
              cVar11 = FUN_005410e4(&local_c,local_30);
              uVar15 = (uint)(cVar11 != '\0');
              FUN_00540fe8(local_30,2);
              if (uVar15 == 0) goto LAB_0046fc28;
              cVar11 = '\x01';
            }
            FUN_00540fe8(local_2c,2);
            if (cVar11 != '\0') {
              uVar17 = local_8;
              iVar14 = FUN_00453f98();
              local_90 = *(double *)(*(int *)(&DAT_00585850 + iVar14 * 4) + 0x8d8 + local_94 * 8) *
                         local_88;
              bVar2 = NAN(local_90);
              bVar3 = local_90 < 0.0;
              bVar4 = local_90 == 0.0;
              iVar12 = local_94;
              if (bVar3) {
                iVar12 = 0;
                local_90 = 0.0;
              }
              iVar12 = FUN_00453f98(CONCAT22((short)((uint)*(int *)(&DAT_00585850 + iVar14 * 4) >>
                                                    0x10),
                                             (ushort)bVar3 << 8 | (ushort)bVar2 << 10 |
                                             (ushort)bVar4 << 0xe),iVar12,uVar17,local_8);
              if (*(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 + local_94 * 8) <
                  local_90) {
                iVar12 = FUN_00453f98();
                local_90 = (double)CONCAT44(*(undefined4 *)
                                             (*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8dc +
                                             local_94 * 8),
                                            *(undefined4 *)
                                             (*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 +
                                             local_94 * 8));
              }
              iVar12 = FUN_00453f98();
              *(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 + local_94 * 8) =
                   *(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 + local_94 * 8) -
                   local_90;
              FUN_00453f98();
              iVar12 = FUN_00461db4();
              if (iVar12 == -1) {
                iVar12 = FUN_00453f98();
                iVar12 = *(int *)(&DAT_00585850 + iVar12 * 4);
                uVar17 = local_c;
                iVar14 = FUN_00453f98();
                FUN_00541018(iVar12 + *(int *)(*(int *)(&DAT_00585850 + iVar14 * 4) + 0x104) * 4 +
                             0x108,local_10,uVar17);
                iVar12 = FUN_00453f98();
                iVar12 = *(int *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x104);
                uVar17 = local_c;
                iVar14 = FUN_00453f98();
                iVar14 = *(int *)(&DAT_00585850 + iVar14 * 4);
                *(undefined4 *)(iVar14 + 0x8d8 + iVar12 * 8) = (undefined4)local_90;
                *(undefined4 *)(iVar14 + 0x8dc + iVar12 * 8) = local_90._4_4_;
                iVar12 = FUN_00453f98(iVar14,local_90._4_4_,uVar17,local_c);
                *(int *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x104) =
                     *(int *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x104) + 1;
                uVar17 = local_c;
                iVar12 = FUN_00453f98();
                if (99 < *(int *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x104)) {
                  DAT_0057a6f8 = 0;
                  puVar13 = (undefined4 *)FUN_00540ec4(local_34,&DAT_00563d01,uVar17);
                  FUN_00500350(*puVar13);
                  FUN_00540fe8(local_34,2);
                }
              }
              else {
                FUN_00453f98();
                iVar12 = FUN_00461db4();
                iVar14 = FUN_00453f98();
                *(double *)(*(int *)(&DAT_00585850 + iVar14 * 4) + 0x8d8 + iVar12 * 8) =
                     local_90 +
                     *(double *)(*(int *)(&DAT_00585850 + iVar14 * 4) + 0x8d8 + iVar12 * 8);
              }
              FUN_00540ec4(local_38,&DAT_00563d19);
              cVar11 = FUN_005410e4(&DAT_0058fc44 + local_60 * 0x30,local_38);
              FUN_00540fe8(local_38,2);
              if (cVar11 != '\0') {
                uVar17 = *(undefined4 *)(&DAT_0058fc44 + local_60 * 0x30);
                iVar12 = FUN_00454024();
                iVar14 = FUN_00453f98(iVar12,local_60 * 6,uVar17,
                                      *(undefined4 *)(&DAT_0058fc3c + local_60 * 0x30));
                if (*(int *)(&DAT_0058fc4c + local_60 * 0x30) == 1) {
                  local_a8 = (double)*(int *)(*(int *)(&DAT_0058baec + iVar12 * 4) + 0xc);
                }
                if (*(int *)(&DAT_0058fc4c + local_60 * 0x30) == 2) {
                  local_a8 = (double)*(int *)(*(int *)(&DAT_0058baec + iVar12 * 4) + 0x14);
                }
                uVar15 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iVar14 * 4) + 0xfc) + 0x20
                                     ))();
                iVar16 = (int)uVar15 >> 1;
                if (iVar16 < 0) {
                  iVar16 = iVar16 + (uint)((uVar15 & 1) != 0);
                }
                if (local_a8 <=
                    (double)(iVar16 + *(int *)(*(int *)(&DAT_00585850 + iVar14 * 4) + 0x14)) -
                    *(double *)(*(int *)(&DAT_00585850 + iVar14 * 4) + 0x30)) {
                  iVar12 = *(int *)(&DAT_0058baec + iVar12 * 4);
                  *(undefined4 *)(iVar12 + 0x70) = 0;
                  *(undefined4 *)(iVar12 + 0x74) = 0;
                }
                else {
                  *(double *)(*(int *)(&DAT_0058baec + iVar12 * 4) + 0x70) =
                       local_90 * 200000.0 +
                       *(double *)(*(int *)(&DAT_0058baec + iVar12 * 4) + 0x70);
                  *(undefined4 *)(*(int *)(&DAT_0058baec + iVar12 * 4) + 0x78) =
                       *(undefined4 *)(&DAT_0058fc4c + local_60 * 0x30);
                }
              }
            }
          }
          else {
            iVar12 = FUN_00453f98();
            dVar1 = *(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x28);
            iVar12 = FUN_00453f98();
            iVar12 = *(int *)(&DAT_00585850 + iVar12 * 4);
            dVar1 = dVar1 - *(double *)(iVar12 + 0x4320);
            uVar17 = 0;
            local_70 = 0.0;
            iVar14 = 0;
            local_98 = 0;
            while( true ) {
              iVar12 = FUN_00453f98(iVar14,iVar12,uVar17,local_8);
              if (*(int *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x104) <= local_98) break;
              iVar12 = FUN_00453f98();
              FUN_004016e8(local_24,*(int *)(&DAT_00585850 + iVar12 * 4),local_98,
                           *(undefined4 *)
                            (*(int *)(&DAT_00585850 + iVar12 * 4) + 0x108 + local_98 * 4));
              FUN_00452acc();
              puVar20 = local_24;
              FUN_00540ec4(local_28,&DAT_00563cee);
              uVar17 = FUN_005410cc(puVar20,local_28);
              FUN_00540fe8(local_28,2);
              iVar14 = FUN_00540fe8(local_24,2);
              iVar12 = extraout_EDX;
              if ((char)uVar17 != '\0') {
                uVar17 = local_8;
                iVar12 = FUN_00453f98();
                iVar14 = *(int *)(&DAT_00585850 + iVar12 * 4);
                local_70 = *(double *)(iVar14 + 0x8d8 + local_98 * 8) + local_70;
                iVar12 = local_98;
              }
              local_98 = local_98 + 1;
            }
            local_90 = local_70 * 22.4 * 1000.0;
            if (dVar1 < local_90) {
              local_80 = local_90 - dVar1;
            }
            if (1e-100 <= local_90) {
              iVar12 = FUN_00453f98();
              local_90 = (*(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 + local_94 * 8) *
                         local_80) / local_90;
            }
            else {
              local_90 = 0.0;
            }
            if (local_90 < 0.0) {
              local_90 = 0.0;
            }
            iVar12 = FUN_00453f98();
            if (*(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 + local_94 * 8) < local_90)
            {
              iVar12 = FUN_00453f98();
              local_90 = (double)CONCAT44(*(undefined4 *)
                                           (*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8dc +
                                           local_94 * 8),
                                          *(undefined4 *)
                                           (*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 +
                                           local_94 * 8));
            }
            iVar12 = FUN_00453f98();
            *(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 + local_94 * 8) =
                 *(double *)(*(int *)(&DAT_00585850 + iVar12 * 4) + 0x8d8 + local_94 * 8) - local_90
            ;
          }
        }
        local_94 = local_94 + 1;
      }
    }
    local_60 = local_60 + 1;
  } while( true );
}



