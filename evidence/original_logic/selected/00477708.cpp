// Original PE SHA256 7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c
// Entry 00477708

/* WARNING: Removing unreachable block (ram,0x0047e54f) */
/* WARNING: Removing unreachable block (ram,0x0047b6c9) */
/* WARNING: Removing unreachable block (ram,0x0047b697) */
/* WARNING: Removing unreachable block (ram,0x0047b6ac) */
/* WARNING: Removing unreachable block (ram,0x0047ce0c) */
/* WARNING: Removing unreachable block (ram,0x0047cdda) */
/* WARNING: Removing unreachable block (ram,0x0047cdef) */
/* WARNING: Removing unreachable block (ram,0x00479f76) */
/* WARNING: Removing unreachable block (ram,0x00479f44) */
/* WARNING: Removing unreachable block (ram,0x00479f59) */
/* WARNING: Removing unreachable block (ram,0x0047e53a) */
/* WARNING: Removing unreachable block (ram,0x0047e56c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477708(void)

{
  double *pdVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *in_FS_OFFSET;
  longdouble lVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 local_23c [16];
  undefined1 local_22c [16];
  undefined1 local_21c [16];
  undefined1 local_20c [16];
  undefined1 local_1fc [16];
  undefined1 local_1ec [16];
  undefined1 local_1dc [16];
  undefined1 local_1cc [16];
  undefined1 local_1bc [16];
  undefined1 local_1ac [16];
  undefined1 local_19c [16];
  undefined1 local_18c [16];
  undefined1 local_17c [16];
  undefined1 local_16c [16];
  undefined1 local_15c [16];
  undefined1 local_14c [16];
  float local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 uStack_130;
  double local_12c;
  int local_124;
  uint local_120;
  int local_11c;
  float local_118;
  float local_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  double local_108;
  int local_100;
  uint local_fc;
  int local_f8;
  float local_f4;
  float local_f0;
  undefined4 local_ec;
  undefined4 uStack_e8;
  double local_e4;
  int local_dc;
  uint local_d8;
  int local_d4;
  float local_d0;
  float local_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  double local_c0;
  int local_b8;
  uint local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  double local_88;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int *local_6c;
  undefined4 local_68;
  undefined2 local_58;
  int local_4c;
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
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_00566d48);
  local_6c = (int *)FUN_004e8edc(&PTR_FUN_004e2af4,1);
  (**(code **)(*local_6c + 0x40))(local_6c,100);
  (**(code **)(*local_6c + 0x34))(local_6c,100);
  uVar9 = 0x6400000064;
  uVar3 = FUN_004e9448(local_6c);
  FUN_004e4744(uVar3,0,0,uVar9);
  if (DAT_0057a730 != 0xcc) {
    if (DAT_0057a730 != 0xcf) {
      if (DAT_0057a730 != 0xd0) {
        if (DAT_0057a730 != 0xd3) goto LAB_0047e6ba;
        if (DAT_0057a738 == 1) {
          *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 0;
          goto LAB_0047e6ba;
        }
        if (DAT_0057a738 == 2) {
          *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 1;
          goto LAB_0047e6ba;
        }
        if (DAT_0057a738 != 3) goto LAB_0047e6ba;
        *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 1;
        local_70 = *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10);
        uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x20))
                          ();
        iVar4 = (int)uVar7 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
        }
        lVar8 = (longdouble)*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) +
                (longdouble)iVar4 * (longdouble)_DAT_005636c0;
        local_74 = FUN_005394fc();
        local_80 = -1;
        local_78 = 0;
        for (local_11c = 0; local_11c < DAT_0058779c; local_11c = local_11c + 1) {
          iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 8);
          if (iVar4 < 0x6a) {
            if (iVar4 == 0x69) {
              if (((float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                   (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
                 ((float)local_70 <
                  (float)_DAT_005636c0 * 5.0 +
                  (float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10))) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                    0x20))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                if (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                    (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
                  uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                      0x20))();
                  iVar4 = (int)uVar7 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                  }
                  if ((double)local_74 <
                      ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) +
                      (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
                    uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc)
                                        + 0x20))();
                    iVar4 = (int)uVar7 >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                    }
                    if ((double)local_78 <
                        (double)local_74 -
                        (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                         (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                      uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc
                                                     ) + 0x20))();
                      iVar4 = (int)uVar7 >> 1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                      }
                      lVar8 = (longdouble)local_74 -
                              (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14)
                               - (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                              (longdouble)50.0 * (longdouble)_DAT_005636c0);
                      local_78 = FUN_005394fc();
                      local_80 = local_11c;
                    }
                  }
                }
              }
            }
            else if (iVar4 == 0x65) {
              if (((*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xc) == 0) &&
                  ((float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                   (float)_DAT_005636c0 * 7.0 < (float)local_70)) &&
                 ((float)local_70 <
                  (float)_DAT_005636c0 * 7.0 +
                  (float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10))) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                    0x20))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                if (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                    (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
                  uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                      0x20))();
                  iVar4 = (int)uVar7 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                  }
                  if ((double)local_74 <
                      ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) +
                      (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
                    uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc)
                                        + 0x20))();
                    iVar4 = (int)uVar7 >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                    }
                    if ((double)local_78 <
                        (double)local_74 -
                        (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                         (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                      uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc
                                                     ) + 0x20))();
                      iVar4 = (int)uVar7 >> 1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                      }
                      lVar8 = (longdouble)local_74 -
                              (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14)
                               - (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                              (longdouble)50.0 * (longdouble)_DAT_005636c0);
                      local_78 = FUN_005394fc();
                      local_80 = local_11c;
                    }
                  }
                }
              }
            }
            else if (iVar4 == 0x66) {
              uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) + 0x2c
                                  ))();
              iVar4 = (int)uVar7 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
              }
              if (_DAT_005636c0 * 7.0 +
                  ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                  (double)iVar4 * _DAT_005636c0) < (double)local_70) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                    0x2c))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                if ((double)local_70 <
                    ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) +
                    (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 2.0) {
                  uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                      0x20))();
                  iVar4 = (int)uVar7 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                  }
                  if (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                      (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
                    uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc)
                                        + 0x20))();
                    iVar4 = (int)uVar7 >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                    }
                    if ((double)local_74 <
                        ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) +
                        (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
                      uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc
                                                     ) + 0x20))();
                      iVar4 = (int)uVar7 >> 1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                      }
                      if ((double)local_78 <
                          (double)local_74 -
                          (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                           (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                        uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) +
                                                       0xfc) + 0x20))();
                        iVar4 = (int)uVar7 >> 1;
                        if (iVar4 < 0) {
                          iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                        }
                        lVar8 = (longdouble)local_74 -
                                (((longdouble)
                                  *(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                                 (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                                (longdouble)50.0 * (longdouble)_DAT_005636c0);
                        local_78 = FUN_005394fc();
                        local_80 = local_11c;
                      }
                    }
                  }
                }
              }
            }
            else if (iVar4 == 0x67) {
              if (((((float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                     (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
                   ((float)local_70 <
                    (float)_DAT_005636c0 * 5.0 +
                    (float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10))) &&
                  (*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xc) == 100)) ||
                 ((((float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                    (float)_DAT_005636c0 * 7.0 < (float)local_70 &&
                   ((float)local_70 <
                    (float)_DAT_005636c0 * 7.0 +
                    (float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10))) &&
                  (*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xc) == 0xfa)))) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                    0x20))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                if (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                    (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
                  uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                      0x20))();
                  iVar4 = (int)uVar7 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                  }
                  if ((double)local_74 <
                      ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) +
                      (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
                    uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc)
                                        + 0x20))();
                    iVar4 = (int)uVar7 >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                    }
                    if ((double)local_78 <
                        (double)local_74 -
                        (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                         (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                      uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc
                                                     ) + 0x20))();
                      iVar4 = (int)uVar7 >> 1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                      }
                      lVar8 = (longdouble)local_74 -
                              (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14)
                               - (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                              (longdouble)50.0 * (longdouble)_DAT_005636c0);
                      local_78 = FUN_005394fc();
                      local_80 = local_11c;
                    }
                  }
                }
              }
            }
            else if (((iVar4 == 0x68) &&
                     ((float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                      (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
                    ((float)local_70 <
                     (float)_DAT_005636c0 * 5.0 +
                     (float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10))) {
              uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) + 0x20
                                  ))();
              iVar4 = (int)uVar7 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
              }
              if (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                  (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                    0x20))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                if ((double)local_74 <
                    ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) +
                    (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
                  uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                      0x20))();
                  iVar4 = (int)uVar7 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                  }
                  if ((double)local_78 <
                      (double)local_74 -
                      (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                       (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                    uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc)
                                        + 0x20))();
                    iVar4 = (int)uVar7 >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                    }
                    lVar8 = (longdouble)local_74 -
                            (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                             (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                            (longdouble)50.0 * (longdouble)_DAT_005636c0);
                    local_78 = FUN_005394fc();
                    local_80 = local_11c;
                  }
                }
              }
            }
          }
          else if (iVar4 == 0x6b) {
            if (((float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                 (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
               ((float)local_70 <
                (float)_DAT_005636c0 * 7.0 +
                (float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10))) {
              uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) + 0x20
                                  ))();
              iVar4 = (int)uVar7 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
              }
              if (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                  (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                    0x20))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                if ((double)local_74 <
                    ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) +
                    (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
                  uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                      0x20))();
                  iVar4 = (int)uVar7 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                  }
                  if ((double)local_78 <
                      (double)local_74 -
                      (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                       (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                    uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc)
                                        + 0x20))();
                    iVar4 = (int)uVar7 >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                    }
                    lVar8 = (longdouble)local_74 -
                            (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                             (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                            (longdouble)50.0 * (longdouble)_DAT_005636c0);
                    local_78 = FUN_005394fc();
                    local_80 = local_11c;
                  }
                }
              }
            }
          }
          else if (iVar4 == 0xc9) {
            if (((float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                 (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
               ((float)local_70 <
                (float)_DAT_005636c0 * 7.0 +
                (float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10))) {
              uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) + 0x20
                                  ))();
              iVar4 = (int)uVar7 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
              }
              if (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                  (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                    0x20))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                if ((double)local_74 <
                    ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) +
                    (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
                  uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                      0x20))();
                  iVar4 = (int)uVar7 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                  }
                  if ((double)local_78 <
                      (double)local_74 -
                      (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                       (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                    uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc)
                                        + 0x20))();
                    iVar4 = (int)uVar7 >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                    }
                    lVar8 = (longdouble)local_74 -
                            (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                             (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                            (longdouble)50.0 * (longdouble)_DAT_005636c0);
                    local_78 = FUN_005394fc();
                    local_80 = local_11c;
                  }
                }
              }
            }
          }
          else if (((iVar4 == 0xca) &&
                   ((float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10) -
                    (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
                  ((float)local_70 <
                   (float)_DAT_005636c0 * 5.0 +
                   (float)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x10))) {
            uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) + 0x20))
                              ();
            iVar4 = (int)uVar7 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
            }
            if (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
              uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) + 0x20
                                  ))();
              iVar4 = (int)uVar7 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
              }
              if ((double)local_74 <
                  ((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) +
                  (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                    0x20))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                if ((double)local_78 <
                    (double)local_74 -
                    (((double)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                     (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                  uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_11c * 4) + 0xfc) +
                                      0x20))();
                  iVar4 = (int)uVar7 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                  }
                  lVar8 = (longdouble)local_74 -
                          (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_11c * 4) + 0x14) -
                           (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                          (longdouble)50.0 * (longdouble)_DAT_005636c0);
                  local_78 = FUN_005394fc();
                  local_80 = local_11c;
                }
              }
            }
          }
        }
        if (local_80 == -1) goto LAB_0047e6ba;
        local_124 = DAT_0057a734;
        if (1e-10 < *(double *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x4320)) {
          local_120 = FUN_00472d60();
          pdVar1 = (double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x4320);
          local_134 = *(undefined4 *)pdVar1;
          uStack_130 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x4324);
          if (*(double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28) < *pdVar1) {
            local_134 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28);
            uStack_130 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x2c);
          }
          iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_80 * 4) + 8);
          if (iVar4 < 0xc9) {
            if (iVar4 - 0x65U < 2) goto LAB_0047e1c8;
            if (iVar4 - 0x67U < 3) {
              FUN_005399d8();
              iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20)
                      )();
              iVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20)
                      )();
              local_12c = (double)iVar5 - (double)iVar4 * (double)lVar8;
              (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
              local_7c = FUN_005394fc();
            }
            else if (iVar4 == 0x6b) goto LAB_0047e1c8;
          }
          else {
            if (1 < iVar4 - 0xc9U) {
              if (iVar4 == 0xd1) {
                if (50.0 < (double)CONCAT44(uStack_130,local_134)) {
                  local_134 = 0;
                  uStack_130 = 0x40490000;
                }
                FUN_005399d8();
                local_12c = (double)(lVar8 * (longdouble)25.0 + (longdouble)30.0);
                (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
                local_7c = FUN_005394fc();
              }
              else if (iVar4 == 0xd2) {
                local_12c = (double)(_DAT_0047e6f0 *
                                     (longdouble)(double)CONCAT44(uStack_130,local_134) *
                                     (longdouble)2.0 + (longdouble)76.0);
                (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
                local_7c = FUN_005394fc();
              }
              goto LAB_0047e449;
            }
LAB_0047e1c8:
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))
                              ();
            local_12c = ((double)CONCAT44(uStack_130,local_134) /
                        *(double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28)) * (double)iVar4;
            (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
            local_7c = FUN_005394fc();
          }
LAB_0047e449:
          local_13c = 0.0;
          while( true ) {
            local_138 = local_13c * 0.5 * local_13c * 0.2;
            uVar3 = FUN_005394fc();
            uVar9 = CONCAT44(uVar3,local_21c);
            uVar3 = FUN_005394fc();
            FUN_0051ef38(local_70 + -1,uVar3,local_70 + 2,uVar9);
            FUN_0051ef38(0,0,3);
            puVar10 = local_20c;
            uVar3 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
            uVar6 = FUN_004e9448(local_6c);
            FUN_004e4420(uVar6,puVar10,uVar3);
            iVar4 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
            FUN_004e4158(*(undefined4 *)(iVar4 + 0x14),local_120);
            iVar4 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
            FUN_004e3e50(*(undefined4 *)(iVar4 + 0x10),
                         (int)(local_120 & 0xff) >> 1 | ((int)(local_120 >> 8 & 0xff) >> 1) << 8 |
                         ((int)(local_120 >> 0x10 & 0xff) >> 1) << 0x10);
            iVar4 = local_70 + 2;
            uVar3 = FUN_005394fc();
            uVar9 = CONCAT44(iVar4,uVar3);
            uVar3 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc),
                                 PTR__Form1_005799c4,*(int *)PTR__Form1_005799c4,uVar3);
            uVar6 = FUN_005394fc();
            FUN_004e4588(uVar3,local_70 + -1,uVar6,uVar9);
            (**(code **)(**(int **)(*(int *)PTR__Form1_005799c4 + 0x4cc) + 0x80))();
            FUN_0051ef38(0,0,3,local_23c,5);
            FUN_005394fc();
            uVar3 = FUN_005394fc();
            FUN_0051ef38(local_70 + -1,uVar3,local_70 + 2);
            puVar10 = local_22c;
            uVar3 = FUN_004e9448(local_6c);
            uVar6 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
            FUN_004e4420(uVar6,puVar10,uVar3);
            if ((float)(local_7c - local_74) < local_138) break;
            local_13c = local_13c + 0.12;
          }
        }
        FUN_00476ddc();
        goto LAB_0047e6ba;
      }
      if (DAT_0057a738 == 1) {
        *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 0;
        goto LAB_0047e6ba;
      }
      if (DAT_0057a738 == 2) {
        *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 1;
        goto LAB_0047e6ba;
      }
      if (DAT_0057a738 != 3) goto LAB_0047e6ba;
      *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 1;
      local_70 = *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10);
      iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x20))();
      lVar8 = (longdouble)*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) +
              (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0;
      local_74 = FUN_005394fc();
      local_80 = -1;
      local_78 = 0;
      for (local_f8 = 0; local_f8 < DAT_0058779c; local_f8 = local_f8 + 1) {
        iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 8);
        if (iVar4 < 0x6a) {
          if (iVar4 == 0x69) {
            if ((((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                  (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
                ((float)local_70 <
                 (float)_DAT_005636c0 * 5.0 +
                 (float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10))) &&
               ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                     0x20))(),
                ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
                (float)local_74 &&
                ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                      0x20))(),
                 (float)local_74 <
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) +
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
                 (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                      0x20))(),
                 (float)local_78 <
                 (float)local_74 -
                 (((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                  (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
              iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20)
                      )();
              lVar8 = (longdouble)local_74 -
                      (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                       (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                      (longdouble)50.0 * (longdouble)_DAT_005636c0);
              local_78 = FUN_005394fc();
              local_80 = local_f8;
            }
          }
          else if (iVar4 == 0x65) {
            if ((((*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xc) == 0) &&
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                  (float)_DAT_005636c0 * 7.0 < (float)local_70)) &&
                ((float)local_70 <
                 (float)_DAT_005636c0 * 7.0 +
                 (float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10))) &&
               (((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                      0x20))(),
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
                 (float)local_74 &&
                 (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                      0x20))(),
                 (float)local_74 <
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) +
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) &&
                (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                     0x20))(),
                (float)local_78 <
                (float)local_74 -
                (((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))) {
              iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20)
                      )();
              lVar8 = (longdouble)local_74 -
                      (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                       (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                      (longdouble)50.0 * (longdouble)_DAT_005636c0);
              local_78 = FUN_005394fc();
              local_80 = local_f8;
            }
          }
          else if (iVar4 == 0x66) {
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x2c))
                              ();
            if ((((float)_DAT_005636c0 * 7.0 +
                  ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                  (float)iVar4 * 0.5 * (float)_DAT_005636c0) < (float)local_70) &&
                (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                     0x2c))(),
                (float)local_70 <
                ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) +
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 2.0)) &&
               ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                     0x20))(),
                ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
                (float)local_74 &&
                ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                      0x20))(),
                 (float)local_74 <
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) +
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
                 (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                      0x20))(),
                 (float)local_78 <
                 (float)local_74 -
                 (((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                  (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
              iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20)
                      )();
              lVar8 = (longdouble)local_74 -
                      (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                       (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                      (longdouble)50.0 * (longdouble)_DAT_005636c0);
              local_78 = FUN_005394fc();
              local_80 = local_f8;
            }
          }
          else if (iVar4 == 0x67) {
            if ((((((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                    (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
                  ((float)local_70 <
                   (float)_DAT_005636c0 * 5.0 +
                   (float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10))) &&
                 (*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xc) == 100)) ||
                ((((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                   (float)_DAT_005636c0 * 7.0 < (float)local_70 &&
                  ((float)local_70 <
                   (float)_DAT_005636c0 * 7.0 +
                   (float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10))) &&
                 (*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xc) == 0xfa)))) &&
               (((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                      0x20))(),
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
                 (float)local_74 &&
                 (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                      0x20))(),
                 (float)local_74 <
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) +
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) &&
                (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                     0x20))(),
                (float)local_78 <
                (float)local_74 -
                (((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))) {
              iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20)
                      )();
              lVar8 = (longdouble)local_74 -
                      (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                       (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                      (longdouble)50.0 * (longdouble)_DAT_005636c0);
              local_78 = FUN_005394fc();
              local_80 = local_f8;
            }
          }
          else if (((((iVar4 == 0x68) &&
                     ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                      (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
                    ((float)local_70 <
                     (float)_DAT_005636c0 * 5.0 +
                     (float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10))) &&
                   ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc)
                                         + 0x20))(),
                    ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                    (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
                    (float)local_74 &&
                    (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc)
                                         + 0x20))(),
                    (float)local_74 <
                    ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) +
                    (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) &&
                  (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                       0x20))(),
                  (float)local_78 <
                  (float)local_74 -
                  (((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                   (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))) {
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20))
                              ();
            lVar8 = (longdouble)local_74 -
                    (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                     (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                    (longdouble)50.0 * (longdouble)_DAT_005636c0);
            local_78 = FUN_005394fc();
            local_80 = local_f8;
          }
        }
        else if (iVar4 == 0x6b) {
          if (((((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                 (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
               ((float)local_70 <
                (float)_DAT_005636c0 * 7.0 +
                (float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10))) &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20
                                   ))(),
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
              (float)local_74)) &&
             ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20
                                   ))(),
              (float)local_74 <
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) +
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20
                                   ))(),
              (float)local_78 <
              (float)local_74 -
              (((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))) {
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20))
                              ();
            lVar8 = (longdouble)local_74 -
                    (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                     (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                    (longdouble)50.0 * (longdouble)_DAT_005636c0);
            local_78 = FUN_005394fc();
            local_80 = local_f8;
          }
        }
        else if (iVar4 == 0xc9) {
          if ((((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
              ((float)local_70 <
               (float)_DAT_005636c0 * 7.0 +
               (float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10))) &&
             ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20
                                   ))(),
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
              (float)local_74 &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20
                                   ))(),
              (float)local_74 <
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) +
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) {
            uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20))
                              ();
            iVar4 = (int)uVar7 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
            }
            if ((double)local_78 <
                (double)local_74 -
                (((double)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                 (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
              uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20)
                      )();
              iVar4 = (int)uVar7 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
              }
              lVar8 = (longdouble)local_74 -
                      (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                       (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                      (longdouble)50.0 * (longdouble)_DAT_005636c0);
              local_78 = FUN_005394fc();
              local_80 = local_f8;
            }
          }
        }
        else if (((iVar4 == 0xca) &&
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10) -
                  (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
                ((float)local_70 <
                 (float)_DAT_005636c0 * 5.0 +
                 (float)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x10))) {
          uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20))();
          iVar4 = (int)uVar7 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
          }
          if (((double)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
              (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0 < (double)local_74) {
            uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20))
                              ();
            iVar4 = (int)uVar7 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
            }
            if ((double)local_74 <
                ((double)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) +
                (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 3.0) {
              uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) + 0x20)
                      )();
              iVar4 = (int)uVar7 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
              }
              if ((double)local_78 <
                  (double)local_74 -
                  (((double)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                   (double)iVar4 * _DAT_005636c0) - _DAT_005636c0 * 50.0)) {
                uVar7 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0xfc) +
                                    0x20))();
                iVar4 = (int)uVar7 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar7 & 1) != 0);
                }
                lVar8 = (longdouble)local_74 -
                        (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_f8 * 4) + 0x14) -
                         (longdouble)iVar4 * (longdouble)_DAT_005636c0) -
                        (longdouble)50.0 * (longdouble)_DAT_005636c0);
                local_78 = FUN_005394fc();
                local_80 = local_f8;
              }
            }
          }
        }
      }
      if (local_80 == -1) goto LAB_0047e6ba;
      local_100 = DAT_0057a734;
      if (1e-10 < *(double *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x4320)) {
        local_fc = FUN_00472d60();
        pdVar1 = (double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x4320);
        local_110 = *(undefined4 *)pdVar1;
        uStack_10c = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x4324);
        if (*(double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28) < *pdVar1) {
          local_110 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28);
          uStack_10c = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x2c);
        }
        iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_80 * 4) + 8);
        if (iVar4 < 0xc9) {
          if (iVar4 - 0x65U < 2) goto LAB_0047ca68;
          if (iVar4 - 0x67U < 3) {
            FUN_005399d8();
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))
                              ();
            iVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))
                              ();
            local_108 = (double)iVar5 - (double)iVar4 * (double)lVar8;
            (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
            local_7c = FUN_005394fc();
          }
          else if (iVar4 == 0x6b) goto LAB_0047ca68;
        }
        else {
          if (1 < iVar4 - 0xc9U) {
            if (iVar4 == 0xd1) {
              if (50.0 < (double)CONCAT44(uStack_10c,local_110)) {
                local_110 = 0;
                uStack_10c = 0x40490000;
              }
              FUN_005399d8();
              local_108 = (double)(lVar8 * (longdouble)25.0 + (longdouble)30.0);
              (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
              local_7c = FUN_005394fc();
            }
            else if (iVar4 == 0xd2) {
              local_108 = (double)(_DAT_0047e6f0 *
                                   (longdouble)(double)CONCAT44(uStack_10c,local_110) *
                                   (longdouble)2.0 + (longdouble)76.0);
              (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
              local_7c = FUN_005394fc();
            }
            goto LAB_0047cce9;
          }
LAB_0047ca68:
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
          local_108 = ((double)CONCAT44(uStack_10c,local_110) /
                      *(double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28)) * (double)iVar4;
          (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
          local_7c = FUN_005394fc();
        }
LAB_0047cce9:
        local_118 = 0.0;
        while( true ) {
          local_114 = local_118 * 0.5 * local_118 * 0.2;
          uVar3 = FUN_005394fc();
          uVar9 = CONCAT44(uVar3,local_1dc);
          uVar3 = FUN_005394fc();
          FUN_0051ef38(local_70 + -1,uVar3,local_70 + 2,uVar9);
          FUN_0051ef38(0,0,3);
          puVar10 = local_1cc;
          uVar3 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
          uVar6 = FUN_004e9448(local_6c);
          FUN_004e4420(uVar6,puVar10,uVar3);
          iVar4 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
          FUN_004e4158(*(undefined4 *)(iVar4 + 0x14),local_fc);
          iVar4 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
          FUN_004e3e50(*(undefined4 *)(iVar4 + 0x10),
                       (int)(local_fc & 0xff) >> 1 | ((int)(local_fc >> 8 & 0xff) >> 1) << 8 |
                       ((int)(local_fc >> 0x10 & 0xff) >> 1) << 0x10);
          iVar4 = local_70 + 2;
          uVar3 = FUN_005394fc();
          uVar9 = CONCAT44(iVar4,uVar3);
          uVar3 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc),
                               PTR__Form1_005799c4,*(int *)PTR__Form1_005799c4,uVar3);
          uVar6 = FUN_005394fc();
          FUN_004e4588(uVar3,local_70 + -1,uVar6,uVar9);
          (**(code **)(**(int **)(*(int *)PTR__Form1_005799c4 + 0x4cc) + 0x80))();
          FUN_0051ef38(0,0,3,local_1fc,5);
          FUN_005394fc();
          uVar3 = FUN_005394fc();
          FUN_0051ef38(local_70 + -1,uVar3,local_70 + 2);
          puVar10 = local_1ec;
          uVar3 = FUN_004e9448(local_6c);
          uVar6 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
          FUN_004e4420(uVar6,puVar10,uVar3);
          if ((float)(local_7c - local_74) < local_114) break;
          local_118 = local_118 + 0.12;
        }
      }
      FUN_00476ddc();
      goto LAB_0047e6ba;
    }
    if (DAT_0057a738 == 1) {
      *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 0;
      goto LAB_0047e6ba;
    }
    if (DAT_0057a738 == 2) {
      *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 1;
      goto LAB_0047e6ba;
    }
    if (DAT_0057a738 != 3) goto LAB_0047e6ba;
    *(undefined4 *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x68) = 1;
    local_70 = FUN_005394fc();
    iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x20))();
    lVar8 = (longdouble)*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) +
            (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0;
    local_74 = FUN_005394fc();
    local_80 = -1;
    local_78 = 0;
    for (local_d4 = 0; local_d4 < DAT_0058779c; local_d4 = local_d4 + 1) {
      iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 8);
      if (iVar4 < 0x6a) {
        if (iVar4 == 0x69) {
          if ((((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
                (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
              ((float)local_70 <
               (float)_DAT_005636c0 * 5.0 +
               (float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10))) &&
             ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20
                                   ))(),
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
              (float)local_74 &&
              ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                    0x20))(),
               (float)local_74 <
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) +
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
               (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                    0x20))(),
               (float)local_78 <
               (float)local_74 -
               (((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))
                              ();
            lVar8 = (longdouble)local_74 -
                    (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                     (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                    (longdouble)50.0 * (longdouble)_DAT_005636c0);
            local_78 = FUN_005394fc();
            local_80 = local_d4;
          }
        }
        else if (iVar4 == 0x65) {
          if (((((*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xc) == 0) &&
                ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
                 (float)_DAT_005636c0 * 7.0 < (float)local_70)) &&
               ((float)local_70 <
                (float)_DAT_005636c0 * 7.0 +
                (float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10))) &&
              ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                    0x20))(),
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
               (float)local_74 &&
               (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                    0x20))(),
               (float)local_74 <
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) +
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) &&
             (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_78 <
             (float)local_74 -
             (((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))) {
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))
                              ();
            lVar8 = (longdouble)local_74 -
                    (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                     (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                    (longdouble)50.0 * (longdouble)_DAT_005636c0);
            local_78 = FUN_005394fc();
            local_80 = local_d4;
          }
        }
        else if (iVar4 == 0x66) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x2c))();
          if ((((float)_DAT_005636c0 * 7.0 +
                ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) < (float)local_70) &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x2c
                                   ))(),
              (float)local_70 <
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) +
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 2.0)) &&
             ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20
                                   ))(),
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
              (float)local_74 &&
              ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                    0x20))(),
               (float)local_74 <
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) +
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
               (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                    0x20))(),
               (float)local_78 <
               (float)local_74 -
               (((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))
                              ();
            lVar8 = (longdouble)local_74 -
                    (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                     (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                    (longdouble)50.0 * (longdouble)_DAT_005636c0);
            local_78 = FUN_005394fc();
            local_80 = local_d4;
          }
        }
        else if (iVar4 == 0x67) {
          if ((((((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
                  (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
                ((float)local_70 <
                 (float)_DAT_005636c0 * 5.0 +
                 (float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10))) &&
               (*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xc) == 100)) ||
              ((((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
                 (float)_DAT_005636c0 * 7.0 < (float)local_70 &&
                ((float)local_70 <
                 (float)_DAT_005636c0 * 7.0 +
                 (float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10))) &&
               (*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xc) == 0xfa)))) &&
             (((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                    0x20))(),
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
               (float)local_74 &&
               (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                    0x20))(),
               (float)local_74 <
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) +
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20
                                   ))(),
              (float)local_78 <
              (float)local_74 -
              (((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))) {
            iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))
                              ();
            lVar8 = (longdouble)local_74 -
                    (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                     (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                    (longdouble)50.0 * (longdouble)_DAT_005636c0);
            local_78 = FUN_005394fc();
            local_80 = local_d4;
          }
        }
        else if (((((iVar4 == 0x68) &&
                   ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
                    (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
                  ((float)local_70 <
                   (float)_DAT_005636c0 * 5.0 +
                   (float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10))) &&
                 ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                       0x20))(),
                  ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                  (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
                  (float)local_74 &&
                  (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                       0x20))(),
                  (float)local_74 <
                  ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) +
                  (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) &&
                (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                     0x20))(),
                (float)local_78 <
                (float)local_74 -
                (((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))();
          lVar8 = (longdouble)local_74 -
                  (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                   (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                  (longdouble)50.0 * (longdouble)_DAT_005636c0);
          local_78 = FUN_005394fc();
          local_80 = local_d4;
        }
      }
      else if (iVar4 == 0x6b) {
        if ((((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
              (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
            ((float)local_70 <
             (float)_DAT_005636c0 * 7.0 +
             (float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10))) &&
           ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))
                               (),
            ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
            (float)local_74 &&
            ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_74 <
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) +
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
             (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_78 <
             (float)local_74 -
             (((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))();
          lVar8 = (longdouble)local_74 -
                  (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                   (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                  (longdouble)50.0 * (longdouble)_DAT_005636c0);
          local_78 = FUN_005394fc();
          local_80 = local_d4;
        }
      }
      else if (iVar4 == 0xc9) {
        if (((((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
               (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
             ((float)local_70 <
              (float)_DAT_005636c0 * 7.0 +
              (float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10))) &&
            (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))
                               (),
            ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
            (float)local_74)) &&
           ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))
                               (),
            (float)local_74 <
            ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) +
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
            (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))
                               (),
            (float)local_78 <
            (float)local_74 -
            (((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))();
          lVar8 = (longdouble)local_74 -
                  (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                   (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                  (longdouble)50.0 * (longdouble)_DAT_005636c0);
          local_78 = FUN_005394fc();
          local_80 = local_d4;
        }
      }
      else if (((iVar4 == 0xca) &&
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) -
                (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
              (((float)local_70 <
                (float)_DAT_005636c0 * 5.0 +
                (float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x10) &&
               (((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                      0x20))(),
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
                 (float)local_74 &&
                 (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                      0x20))(),
                 (float)local_74 <
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) +
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) &&
                (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) +
                                     0x20))(),
                (float)local_78 <
                (float)local_74 -
                (((float)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
        iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0xfc) + 0x20))();
        lVar8 = (longdouble)local_74 -
                (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_d4 * 4) + 0x14) -
                 (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                (longdouble)50.0 * (longdouble)_DAT_005636c0);
        local_78 = FUN_005394fc();
        local_80 = local_d4;
      }
    }
    if (local_80 == -1) goto LAB_0047e6ba;
    local_dc = DAT_0057a734;
    if (1e-10 < *(double *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x4320)) {
      local_d8 = FUN_00472d60();
      pdVar1 = (double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x4320);
      local_ec = *(undefined4 *)pdVar1;
      uStack_e8 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x4324);
      if (*(double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28) < *pdVar1) {
        local_ec = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28);
        uStack_e8 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x2c);
      }
      iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_80 * 4) + 8);
      if (iVar4 < 0xc9) {
        if (iVar4 - 0x65U < 2) goto LAB_0047b325;
        if (iVar4 - 0x67U < 3) {
          FUN_005399d8();
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
          iVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
          local_e4 = (double)iVar5 - (double)iVar4 * (double)lVar8;
          (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
          local_7c = FUN_005394fc();
        }
        else if (iVar4 == 0x6b) goto LAB_0047b325;
      }
      else {
        if (1 < iVar4 - 0xc9U) {
          if (iVar4 == 0xd1) {
            if (50.0 < (double)CONCAT44(uStack_e8,local_ec)) {
              local_ec = 0;
              uStack_e8 = 0x40490000;
            }
            FUN_005399d8();
            local_e4 = (double)(lVar8 * (longdouble)25.0 + (longdouble)30.0);
            (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
            local_7c = FUN_005394fc();
          }
          else if (iVar4 == 0xd2) {
            local_e4 = (double)(_DAT_0047e6f0 * (longdouble)(double)CONCAT44(uStack_e8,local_ec) *
                                (longdouble)2.0 + (longdouble)76.0);
            (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
            local_7c = FUN_005394fc();
          }
          goto LAB_0047b5a6;
        }
LAB_0047b325:
        iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
        local_e4 = ((double)CONCAT44(uStack_e8,local_ec) /
                   *(double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28)) * (double)iVar4;
        (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
        local_7c = FUN_005394fc();
      }
LAB_0047b5a6:
      local_f4 = 0.0;
      while( true ) {
        local_f0 = local_f4 * 0.5 * local_f4 * 0.2;
        uVar3 = FUN_005394fc();
        uVar9 = CONCAT44(uVar3,local_19c);
        uVar3 = FUN_005394fc();
        FUN_0051ef38(local_70 + -1,uVar3,local_70 + 2,uVar9);
        FUN_0051ef38(0,0,3);
        puVar10 = local_18c;
        uVar3 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
        uVar6 = FUN_004e9448(local_6c);
        FUN_004e4420(uVar6,puVar10,uVar3);
        iVar4 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
        FUN_004e4158(*(undefined4 *)(iVar4 + 0x14),local_d8);
        iVar4 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
        FUN_004e3e50(*(undefined4 *)(iVar4 + 0x10),
                     (int)(local_d8 & 0xff) >> 1 | ((int)(local_d8 >> 8 & 0xff) >> 1) << 8 |
                     ((int)(local_d8 >> 0x10 & 0xff) >> 1) << 0x10);
        iVar4 = local_70 + 2;
        uVar3 = FUN_005394fc();
        uVar9 = CONCAT44(iVar4,uVar3);
        uVar3 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc),
                             PTR__Form1_005799c4,*(int *)PTR__Form1_005799c4,uVar3);
        uVar6 = FUN_005394fc();
        FUN_004e4588(uVar3,local_70 + -1,uVar6,uVar9);
        (**(code **)(**(int **)(*(int *)PTR__Form1_005799c4 + 0x4cc) + 0x80))();
        FUN_0051ef38(0,0,3,local_1bc,5);
        FUN_005394fc();
        uVar3 = FUN_005394fc();
        FUN_0051ef38(local_70 + -1,uVar3,local_70 + 2);
        puVar10 = local_1ac;
        uVar3 = FUN_004e9448(local_6c);
        uVar6 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
        FUN_004e4420(uVar6,puVar10,uVar3);
        if ((float)(local_7c - local_74) < local_f0) break;
        local_f4 = local_f4 + 0.12;
      }
    }
    FUN_00476ddc();
    goto LAB_0047e6ba;
  }
  local_70 = *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10);
  iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x20))();
  lVar8 = (longdouble)*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) +
          (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0;
  local_74 = FUN_005394fc();
  if (DAT_0057a738 == 1) {
    local_88 = 0.0;
    for (local_8c = 0; local_8c < DAT_0058779c; local_8c = local_8c + 1) {
      iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 8);
      if (iVar4 < 0x6a) {
        if (iVar4 == 0x69) {
          if (((((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
                 (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
               ((float)local_70 <
                (float)_DAT_005636c0 * 5.0 +
                (float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10))) &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20
                                   ))(),
              ((double)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
              (double)iVar4 * 0.5 * _DAT_005636c0) -
              *(double *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x30) * _DAT_005636c0 <
              (double)local_74)) &&
             (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_74 <
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) {
            for (local_a0 = 0;
                local_a0 < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104);
                local_a0 = local_a0 + 1) {
              local_58 = 0x38;
              FUN_004016e8(local_28);
              local_4c = local_4c + 1;
              FUN_00452acc();
              puVar10 = local_28;
              FUN_00540ec4(local_2c,&DAT_00563e73);
              local_4c = local_4c + 1;
              cVar2 = FUN_005410cc(puVar10,local_2c);
              local_4c = local_4c + -1;
              FUN_00540fe8(local_2c,2);
              local_4c = local_4c + -1;
              FUN_00540fe8(local_28,2);
              if (cVar2 != '\0') {
                local_88 = *(double *)
                            (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x5b8 + local_a0 * 8) +
                           local_88;
              }
            }
            FUN_00476ddc();
            *in_FS_OFFSET = local_68;
            return;
          }
        }
        else if (iVar4 == 0x65) {
          if (((*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xc) == 0) &&
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
               (float)_DAT_005636c0 * 7.0 < (float)local_70)) &&
             (((float)local_70 <
               (float)_DAT_005636c0 * 7.0 +
               (float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) &&
              ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) +
                                    0x20))(),
               ((double)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
               (double)iVar4 * 0.5 * _DAT_005636c0) -
               *(double *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x30) * _DAT_005636c0 <
               (double)local_74 &&
               (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) +
                                    0x20))(),
               (float)local_74 <
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))))) {
            for (local_90 = 0;
                local_90 < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104);
                local_90 = local_90 + 1) {
              local_58 = 8;
              FUN_004016e8(local_8);
              local_4c = local_4c + 1;
              FUN_00452acc();
              puVar10 = local_8;
              FUN_00540ec4(local_c,&DAT_00563e57);
              local_4c = local_4c + 1;
              cVar2 = FUN_005410cc(puVar10,local_c);
              local_4c = local_4c + -1;
              FUN_00540fe8(local_c,2);
              local_4c = local_4c + -1;
              FUN_00540fe8(local_8,2);
              if (cVar2 != '\0') {
                local_88 = *(double *)
                            (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x5b8 + local_90 * 8) +
                           local_88;
              }
            }
            FUN_00476ddc();
            *in_FS_OFFSET = local_68;
            return;
          }
        }
        else if (iVar4 == 0x66) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x2c))();
          if (((((float)_DAT_005636c0 * 7.0 +
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) < (float)local_70) &&
               (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) +
                                    0x2c))(),
               (float)local_70 <
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) +
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 2.0)) &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20
                                   ))(),
              ((double)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
              (double)iVar4 * 0.5 * _DAT_005636c0) -
              *(double *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x30) * _DAT_005636c0 <
              (double)local_74)) &&
             (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_74 <
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) {
            for (local_94 = 0;
                local_94 < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104);
                local_94 = local_94 + 1) {
              local_58 = 0x14;
              FUN_004016e8(local_10);
              local_4c = local_4c + 1;
              FUN_00452acc();
              puVar10 = local_10;
              FUN_00540ec4(local_14,&DAT_00563e5e);
              local_4c = local_4c + 1;
              cVar2 = FUN_005410cc(puVar10,local_14);
              local_4c = local_4c + -1;
              FUN_00540fe8(local_14,2);
              local_4c = local_4c + -1;
              FUN_00540fe8(local_10,2);
              if (cVar2 != '\0') {
                local_88 = *(double *)
                            (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x5b8 + local_94 * 8) +
                           local_88;
              }
            }
            FUN_00476ddc();
            *in_FS_OFFSET = local_68;
            return;
          }
        }
        else if (iVar4 == 0x67) {
          if ((((((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
                  (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
                ((float)local_70 <
                 (float)_DAT_005636c0 * 5.0 +
                 (float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10))) &&
               (*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xc) == 100)) ||
              ((((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
                 (float)_DAT_005636c0 * 7.0 < (float)local_70 &&
                ((float)local_70 <
                 (float)_DAT_005636c0 * 7.0 +
                 (float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10))) &&
               (*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xc) == 0xfa)))) &&
             ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20
                                   ))(),
              ((double)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
              (double)iVar4 * 0.5 * _DAT_005636c0) -
              *(double *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x30) * _DAT_005636c0 <
              (double)local_74 &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20
                                   ))(),
              (float)local_74 <
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) {
            for (local_98 = 0;
                local_98 < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104);
                local_98 = local_98 + 1) {
              local_58 = 0x20;
              FUN_004016e8(local_18);
              local_4c = local_4c + 1;
              FUN_00452acc();
              puVar10 = local_18;
              FUN_00540ec4(local_1c,&DAT_00563e65);
              local_4c = local_4c + 1;
              cVar2 = FUN_005410cc(puVar10,local_1c);
              local_4c = local_4c + -1;
              FUN_00540fe8(local_1c,2);
              local_4c = local_4c + -1;
              FUN_00540fe8(local_18,2);
              if (cVar2 != '\0') {
                local_88 = *(double *)
                            (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x5b8 + local_98 * 8) +
                           local_88;
              }
            }
            FUN_00476ddc();
            *in_FS_OFFSET = local_68;
            return;
          }
        }
        else if ((((iVar4 == 0x68) &&
                  ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
                   (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
                 ((float)local_70 <
                  (float)_DAT_005636c0 * 5.0 +
                  (float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10))) &&
                ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) +
                                      0x20))(),
                 ((double)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
                 (double)iVar4 * 0.5 * _DAT_005636c0) -
                 *(double *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x30) * _DAT_005636c0 <
                 (double)local_74 &&
                 (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) +
                                      0x20))(),
                 (float)local_74 <
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
                 (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) {
          for (local_9c = 0; local_9c < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104)
              ; local_9c = local_9c + 1) {
            local_58 = 0x2c;
            FUN_004016e8(local_20);
            local_4c = local_4c + 1;
            FUN_00452acc();
            puVar10 = local_20;
            FUN_00540ec4(local_24,&DAT_00563e6c);
            local_4c = local_4c + 1;
            cVar2 = FUN_005410cc(puVar10,local_24);
            local_4c = local_4c + -1;
            FUN_00540fe8(local_24,2);
            local_4c = local_4c + -1;
            FUN_00540fe8(local_20,2);
            if (cVar2 != '\0') {
              local_88 = *(double *)
                          (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x5b8 + local_9c * 8) +
                         local_88;
            }
          }
          FUN_00476ddc();
          *in_FS_OFFSET = local_68;
          return;
        }
      }
      else if (iVar4 == 0x6b) {
        if ((((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
              (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
            ((float)local_70 <
             (float)_DAT_005636c0 * 7.0 +
             (float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10))) &&
           ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20))
                               (),
            ((double)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
            (double)iVar4 * 0.5 * _DAT_005636c0) -
            *(double *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x30) * _DAT_005636c0 <
            (double)local_74 &&
            (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20))
                               (),
            (float)local_74 <
            ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) {
          for (local_a4 = 0; local_a4 < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104)
              ; local_a4 = local_a4 + 1) {
            local_58 = 0x44;
            FUN_004016e8(local_30);
            local_4c = local_4c + 1;
            FUN_00452acc();
            puVar10 = local_30;
            FUN_00540ec4(local_34,&DAT_00563e7a);
            local_4c = local_4c + 1;
            cVar2 = FUN_005410cc(puVar10,local_34);
            local_4c = local_4c + -1;
            FUN_00540fe8(local_34,2);
            local_4c = local_4c + -1;
            FUN_00540fe8(local_30,2);
            if (cVar2 != '\0') {
              local_88 = *(double *)
                          (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x5b8 + local_a4 * 8) +
                         local_88;
            }
          }
          FUN_00476ddc();
          *in_FS_OFFSET = local_68;
          return;
        }
      }
      else if (iVar4 == 0xc9) {
        if (((((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
               (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
             ((float)local_70 <
              (float)_DAT_005636c0 * 7.0 +
              (float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10))) &&
            (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20))
                               (),
            ((double)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
            (double)iVar4 * 0.5 * _DAT_005636c0) -
            *(double *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x30) * _DAT_005636c0 <
            (double)local_74)) &&
           (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) + 0x20))
                              (),
           (float)local_74 <
           ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
           (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) {
          for (local_a8 = 0; local_a8 < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104)
              ; local_a8 = local_a8 + 1) {
            local_58 = 0x50;
            FUN_004016e8(local_38);
            local_4c = local_4c + 1;
            FUN_00452acc();
            puVar10 = local_38;
            FUN_00540ec4(local_3c,&DAT_00563e81);
            local_4c = local_4c + 1;
            cVar2 = FUN_005410cc(puVar10,local_3c);
            local_4c = local_4c + -1;
            FUN_00540fe8(local_3c,2);
            local_4c = local_4c + -1;
            FUN_00540fe8(local_38,2);
            if (cVar2 != '\0') {
              local_88 = *(double *)
                          (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x5b8 + local_a8 * 8) +
                         local_88;
            }
          }
          FUN_00476ddc();
          *in_FS_OFFSET = local_68;
          return;
        }
      }
      else if (((iVar4 == 0xca) &&
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) -
                (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
              (((float)local_70 <
                (float)_DAT_005636c0 * 5.0 +
                (float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x10) &&
               ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) +
                                     0x20))(),
                ((double)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
                (double)iVar4 * 0.5 * _DAT_005636c0) -
                *(double *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x30) * _DAT_005636c0 <
                (double)local_74 &&
                (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_8c * 4) + 0xfc) +
                                     0x20))(),
                (float)local_74 <
                ((float)*(int *)(*(int *)(&DAT_00585850 + local_8c * 4) + 0x14) +
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))))) {
        for (local_ac = 0; local_ac < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104);
            local_ac = local_ac + 1) {
          local_58 = 0x5c;
          FUN_004016e8(local_40);
          local_4c = local_4c + 1;
          FUN_00452acc();
          puVar10 = local_40;
          FUN_00540ec4(local_44,&DAT_00563e88);
          local_4c = local_4c + 1;
          cVar2 = FUN_005410cc(puVar10,local_44);
          local_4c = local_4c + -1;
          FUN_00540fe8(local_44,2);
          local_4c = local_4c + -1;
          FUN_00540fe8(local_40,2);
          if (cVar2 != '\0') {
            local_88 = *(double *)
                        (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x5b8 + local_ac * 8) +
                       local_88;
          }
        }
        FUN_00476ddc();
        *in_FS_OFFSET = local_68;
        return;
      }
    }
    goto LAB_0047e6ba;
  }
  if (DAT_0057a738 != 2) goto LAB_0047e6ba;
  local_80 = -1;
  local_78 = 0;
  for (local_b0 = 0; local_b0 < DAT_0058779c; local_b0 = local_b0 + 1) {
    iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 8);
    if (iVar4 < 0x6a) {
      if (iVar4 == 0x69) {
        if ((((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
              (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
            ((float)local_70 <
             (float)_DAT_005636c0 * 5.0 +
             (float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10))) &&
           ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))
                               (),
            ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
            (float)local_74 &&
            ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_74 <
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) +
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
             (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_78 <
             (float)local_74 -
             (((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))();
          lVar8 = (longdouble)local_74 -
                  (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
                   (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                  (longdouble)50.0 * (longdouble)_DAT_005636c0);
          local_78 = FUN_005394fc();
          local_80 = local_b0;
        }
      }
      else if (iVar4 == 0x65) {
        if (((((*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xc) == 0) &&
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
               (float)_DAT_005636c0 * 7.0 < (float)local_70)) &&
             ((float)local_70 <
              (float)_DAT_005636c0 * 7.0 +
              (float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10))) &&
            ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20)
                      )(),
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
             (float)local_74 &&
             (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_74 <
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) +
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) &&
           (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))
                              (),
           (float)local_78 <
           (float)local_74 -
           (((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))();
          lVar8 = (longdouble)local_74 -
                  (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
                   (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                  (longdouble)50.0 * (longdouble)_DAT_005636c0);
          local_78 = FUN_005394fc();
          local_80 = local_b0;
        }
      }
      else if (iVar4 == 0x66) {
        iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x2c))();
        if ((((float)_DAT_005636c0 * 7.0 +
              ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) < (float)local_70) &&
            (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x2c))
                               (),
            (float)local_70 <
            ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) +
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 2.0)) &&
           ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))
                               (),
            ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
            (float)local_74 &&
            ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_74 <
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) +
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
             (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_78 <
             (float)local_74 -
             (((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
              (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))();
          lVar8 = (longdouble)local_74 -
                  (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
                   (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                  (longdouble)50.0 * (longdouble)_DAT_005636c0);
          local_78 = FUN_005394fc();
          local_80 = local_b0;
        }
      }
      else if (iVar4 == 0x67) {
        if ((((((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
                (float)_DAT_005636c0 * 5.0 < (float)local_70) &&
              ((float)local_70 <
               (float)_DAT_005636c0 * 5.0 +
               (float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10))) &&
             (*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xc) == 100)) ||
            ((((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
               (float)_DAT_005636c0 * 7.0 < (float)local_70 &&
              ((float)local_70 <
               (float)_DAT_005636c0 * 7.0 +
               (float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10))) &&
             (*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xc) == 0xfa)))) &&
           (((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20)
                      )(),
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
             (float)local_74 &&
             (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20)
                      )(),
             (float)local_74 <
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) +
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) &&
            (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))
                               (),
            (float)local_78 <
            (float)local_74 -
            (((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))) {
          iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))();
          lVar8 = (longdouble)local_74 -
                  (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
                   (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                  (longdouble)50.0 * (longdouble)_DAT_005636c0);
          local_78 = FUN_005394fc();
          local_80 = local_b0;
        }
      }
      else if (((((iVar4 == 0x68) &&
                 ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
                  (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
                ((float)local_70 <
                 (float)_DAT_005636c0 * 5.0 +
                 (float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10))) &&
               ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) +
                                     0x20))(),
                ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
                (float)local_74 &&
                (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) +
                                     0x20))(),
                (float)local_74 <
                ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) +
                (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)))) &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20
                                   ))(),
              (float)local_78 <
              (float)local_74 -
              (((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))) {
        iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))();
        lVar8 = (longdouble)local_74 -
                (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
                 (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                (longdouble)50.0 * (longdouble)_DAT_005636c0);
        local_78 = FUN_005394fc();
        local_80 = local_b0;
      }
    }
    else if (iVar4 == 0x6b) {
      if ((((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
            (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
          ((float)local_70 <
           (float)_DAT_005636c0 * 7.0 +
           (float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10))) &&
         ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))()
          , ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
            (float)local_74 &&
          ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))
                              (),
           (float)local_74 <
           ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) +
           (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
           (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))
                              (),
           (float)local_78 <
           (float)local_74 -
           (((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
        iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))();
        lVar8 = (longdouble)local_74 -
                (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
                 (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                (longdouble)50.0 * (longdouble)_DAT_005636c0);
        local_78 = FUN_005394fc();
        local_80 = local_b0;
      }
    }
    else if (iVar4 == 0xc9) {
      if (((((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
             (float)_DAT_005636c0 * 7.0 < (float)local_70) &&
           ((float)local_70 <
            (float)_DAT_005636c0 * 7.0 +
            (float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10))) &&
          (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))()
          , ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
            (float)local_74)) &&
         ((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))()
          , (float)local_74 <
            ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) +
            (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0 &&
          (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))()
          , (float)local_78 <
            (float)local_74 -
            (((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
             (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))) {
        iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))();
        lVar8 = (longdouble)local_74 -
                (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
                 (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
                (longdouble)50.0 * (longdouble)_DAT_005636c0);
        local_78 = FUN_005394fc();
        local_80 = local_b0;
      }
    }
    else if (((iVar4 == 0xca) &&
             ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) -
              (float)_DAT_005636c0 * 5.0 < (float)local_70)) &&
            (((float)local_70 <
              (float)_DAT_005636c0 * 5.0 +
              (float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x10) &&
             (((iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) +
                                    0x20))(),
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0 <
               (float)local_74 &&
               (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) +
                                    0x20))(),
               (float)local_74 <
               ((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) +
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 3.0)) &&
              (iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20
                                   ))(),
              (float)local_78 <
              (float)local_74 -
              (((float)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
               (float)iVar4 * 0.5 * (float)_DAT_005636c0) - (float)_DAT_005636c0 * 50.0))))))) {
      iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0xfc) + 0x20))();
      lVar8 = (longdouble)local_74 -
              (((longdouble)*(int *)(*(int *)(&DAT_00585850 + local_b0 * 4) + 0x14) -
               (longdouble)iVar4 * (longdouble)0.5 * (longdouble)_DAT_005636c0) -
              (longdouble)50.0 * (longdouble)_DAT_005636c0);
      local_78 = FUN_005394fc();
      local_80 = local_b0;
    }
  }
  if (local_80 == -1) goto LAB_0047e6ba;
  local_b8 = DAT_0057a734;
  if (1e-10 < *(double *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x4320)) {
    local_b4 = FUN_00472d60();
    pdVar1 = (double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x4320);
    local_c8 = *(undefined4 *)pdVar1;
    uStack_c4 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x4324);
    if (*(double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28) < *pdVar1) {
      local_c8 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28);
      uStack_c4 = *(undefined4 *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x2c);
    }
    iVar4 = *(int *)(*(int *)(&DAT_00585850 + local_80 * 4) + 8);
    if (iVar4 < 0xc9) {
      if (iVar4 - 0x65U < 2) goto LAB_00479bd2;
      if (iVar4 - 0x67U < 3) {
        FUN_005399d8();
        iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
        iVar5 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
        local_c0 = (double)iVar5 - (double)iVar4 * (double)lVar8;
        (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
        local_7c = FUN_005394fc();
      }
      else if (iVar4 == 0x6b) goto LAB_00479bd2;
    }
    else {
      if (1 < iVar4 - 0xc9U) {
        if (iVar4 == 0xd1) {
          if (50.0 < (double)CONCAT44(uStack_c4,local_c8)) {
            local_c8 = 0;
            uStack_c4 = 0x40490000;
          }
          FUN_005399d8();
          local_c0 = (double)(lVar8 * (longdouble)25.0 + (longdouble)30.0);
          (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
          local_7c = FUN_005394fc();
        }
        else if (iVar4 == 0xd2) {
          local_c0 = (double)(_DAT_0047e6f0 * (longdouble)(double)CONCAT44(uStack_c4,local_c8) *
                              (longdouble)2.0 + (longdouble)76.0);
          (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
          local_7c = FUN_005394fc();
        }
        goto LAB_00479e53;
      }
LAB_00479bd2:
      iVar4 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
      local_c0 = ((double)CONCAT44(uStack_c4,local_c8) /
                 *(double *)(*(int *)(&DAT_00585850 + local_80 * 4) + 0x28)) * (double)iVar4;
      (**(code **)(**(int **)(*(int *)(&DAT_00585850 + local_80 * 4) + 0xfc) + 0x20))();
      local_7c = FUN_005394fc();
    }
LAB_00479e53:
    local_d0 = 0.0;
    while( true ) {
      local_cc = local_d0 * 0.5 * local_d0 * 0.2;
      uVar3 = FUN_005394fc();
      uVar9 = CONCAT44(uVar3,local_15c);
      uVar3 = FUN_005394fc();
      FUN_0051ef38(local_70 + -1,uVar3,local_70 + 2,uVar9);
      FUN_0051ef38(0,0,3);
      puVar10 = local_14c;
      uVar3 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
      uVar6 = FUN_004e9448(local_6c);
      FUN_004e4420(uVar6,puVar10,uVar3);
      iVar4 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
      FUN_004e4158(*(undefined4 *)(iVar4 + 0x14),local_b4);
      iVar4 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
      FUN_004e3e50(*(undefined4 *)(iVar4 + 0x10),
                   (int)(local_b4 & 0xff) >> 1 | ((int)(local_b4 >> 8 & 0xff) >> 1) << 8 |
                   ((int)(local_b4 >> 0x10 & 0xff) >> 1) << 0x10);
      iVar4 = local_70 + 2;
      uVar3 = FUN_005394fc();
      uVar9 = CONCAT44(iVar4,uVar3);
      uVar3 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc),PTR__Form1_005799c4,
                           *(int *)PTR__Form1_005799c4,uVar3);
      uVar6 = FUN_005394fc();
      FUN_004e4588(uVar3,local_70 + -1,uVar6,uVar9);
      (**(code **)(**(int **)(*(int *)PTR__Form1_005799c4 + 0x4cc) + 0x80))();
      FUN_0051ef38(0,0,3,local_17c,5);
      FUN_005394fc();
      uVar3 = FUN_005394fc();
      FUN_0051ef38(local_70 + -1,uVar3,local_70 + 2);
      puVar10 = local_16c;
      uVar3 = FUN_004e9448(local_6c);
      uVar6 = FUN_004fb0ac(*(undefined4 *)(*(int *)PTR__Form1_005799c4 + 0x4cc));
      FUN_004e4420(uVar6,puVar10,uVar3);
      if ((float)(local_7c - local_74) < local_cc) break;
      local_d0 = local_d0 + 0.12;
    }
  }
  FUN_00476ddc();
LAB_0047e6ba:
  *in_FS_OFFSET = local_68;
                    /* WARNING: Read-only address (ram,0x0047e6f0) is written */
  return;
}

