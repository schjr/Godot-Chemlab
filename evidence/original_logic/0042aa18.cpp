// Entry 0042aa18, recovered name Published_Image1MouseUp_0042aa18

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Image1MouseUp_0042aa18
               (int param_1,undefined4 param_2,char param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  longdouble lVar5;
  longdouble in_ST5;
  longdouble in_ST6;
  undefined1 auStack_13c [4];
  undefined4 uStack_138;
  undefined4 auStack_134 [2];
  undefined1 auStack_12c [4];
  undefined4 uStack_128;
  undefined4 auStack_124 [2];
  undefined1 auStack_11c [4];
  undefined4 uStack_118;
  undefined4 auStack_114 [2];
  undefined1 auStack_10c [4];
  undefined4 uStack_108;
  undefined4 auStack_104 [2];
  int iStack_fc;
  undefined1 auStack_f8 [4];
  undefined4 uStack_f4;
  undefined4 auStack_f0 [2];
  int iStack_e8;
  undefined1 auStack_e4 [4];
  undefined4 uStack_e0;
  undefined4 auStack_dc [2];
  undefined1 auStack_d4 [4];
  undefined4 uStack_d0;
  undefined4 auStack_cc [2];
  undefined1 auStack_c4 [4];
  undefined4 uStack_c0;
  undefined4 auStack_bc [2];
  undefined1 auStack_b4 [4];
  undefined4 uStack_b0;
  undefined4 auStack_ac [2];
  undefined1 auStack_a4 [4];
  undefined4 uStack_a0;
  undefined4 auStack_9c [2];
  undefined1 auStack_94 [4];
  undefined4 uStack_90;
  undefined4 auStack_8c [2];
  undefined1 auStack_84 [4];
  undefined4 uStack_80;
  undefined4 auStack_7c [2];
  undefined1 auStack_74 [4];
  undefined4 uStack_70;
  undefined4 auStack_6c [2];
  undefined1 auStack_64 [4];
  undefined4 uStack_60;
  undefined4 auStack_5c [2];
  int iStack_54;
  int iStack_4c;
  char cStack_45;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined2 uStack_2c;
  int iStack_20;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  
  cStack_45 = param_3;
  uStack_44 = param_2;
  iStack_40 = param_1;
  FUN_00534be0(0x55aba4);
  DAT_00556590 = 1;
  if (*(int *)(iStack_40 + 0x588) == 0) {
    *(undefined4 *)(iStack_40 + 0x5bc) = 0;
    *(int *)(iStack_40 + 0x5a0) = param_5;
    *(int *)(iStack_40 + 0x5a4) = param_4;
    if (DAT_0057a6f8 != 1) {
      FUN_00505524(*(undefined4 *)(iStack_40 + 0x4cc),1);
    }
    if (DAT_0057a730 == -1) {
      DAT_0057a730 = 0;
    }
    if ((DAT_0057a70c == DAT_0057a704) || (DAT_0057a710 == DAT_0057a708)) {
      DAT_0057a704 = 0;
      DAT_0057a70c = 0;
      DAT_0057a708 = 0;
      DAT_0057a710 = 0;
    }
    if (DAT_0057a6f8 == 1) {
      DAT_0057a74c = FUN_0053d180();
    }
    if (cStack_45 == '\0') {
      if (DAT_0057a6f8 == 1) {
        if (DAT_0057a730 == 0xcc) {
          uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x2c)
                  )();
          iVar2 = (int)uVar1 >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
          }
          if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) + 10 < param_5) {
            uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                0x20))();
            iVar2 = (int)uVar1 >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
            }
            if (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2 < param_4) {
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                  0x2c))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              if (param_5 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) +
                            0x2d) {
                uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                    0x20))();
                iVar2 = (int)uVar1 >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
                }
                if (param_4 < (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2)
                              + 0x14) {
                  DAT_0057a738 = 1;
                  func_0x00477708();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
          uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x2c)
                  )();
          iVar2 = (int)uVar1 >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
          }
          if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) + 10 < param_5) {
            uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                0x20))();
            iVar2 = (int)uVar1 >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
            }
            if ((*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2) + 0x17 <
                param_4) {
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                  0x2c))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              if (param_5 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) +
                            0x2d) {
                uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                    0x20))();
                iVar2 = (int)uVar1 >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
                }
                if (param_4 < (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2)
                              + 0x2b) {
                  DAT_0057a738 = 2;
                  func_0x00477708();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
        }
        if ((DAT_0057a730 == 0xcf) || (DAT_0057a730 == 0xd0)) {
          uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x2c)
                  )();
          iVar2 = (int)uVar1 >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
          }
          if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) + 10 < param_5) {
            uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                0x20))();
            iVar2 = (int)uVar1 >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
            }
            if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) + -0x46 <
                param_4) {
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                  0x2c))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              if (param_5 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) +
                            0x2d) {
                uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                    0x20))();
                iVar2 = (int)uVar1 >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
                }
                if (param_4 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) +
                              -0x32) {
                  DAT_0057a738 = 1;
                  func_0x00477708();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
          uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x2c)
                  )();
          iVar2 = (int)uVar1 >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
          }
          if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) + 10 < param_5) {
            uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                0x20))();
            iVar2 = (int)uVar1 >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
            }
            if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) + -0x2f <
                param_4) {
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                  0x2c))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              if (param_5 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) +
                            0x2d) {
                uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                    0x20))();
                iVar2 = (int)uVar1 >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
                }
                if (param_4 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) +
                              -0x1b) {
                  DAT_0057a738 = 2;
                  func_0x00477708();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
          uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x2c)
                  )();
          iVar2 = (int)uVar1 >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
          }
          if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) + 10 < param_5) {
            uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                0x20))();
            iVar2 = (int)uVar1 >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
            }
            if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) + -0x18 <
                param_4) {
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                  0x2c))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              if (param_5 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) +
                            0x2d) {
                uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                    0x20))();
                iVar2 = (int)uVar1 >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
                }
                if (param_4 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) +
                              -4) {
                  DAT_0057a738 = 3;
                  func_0x00477708();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
        }
        if (DAT_0057a730 == 0xd3) {
          uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x2c)
                  )();
          iVar2 = (int)uVar1 >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
          }
          if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) + 10 < param_5) {
            uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                0x20))();
            iVar2 = (int)uVar1 >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
            }
            if (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2 < param_4) {
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                  0x2c))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              if (param_5 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) +
                            0x2d) {
                uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                    0x20))();
                iVar2 = (int)uVar1 >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
                }
                if (param_4 < (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2)
                              + 0x14) {
                  DAT_0057a738 = 1;
                  func_0x00477708();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
          uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x2c)
                  )();
          iVar2 = (int)uVar1 >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
          }
          if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) + 10 < param_5) {
            uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                0x20))();
            iVar2 = (int)uVar1 >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
            }
            if ((*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2) + 0x17 <
                param_4) {
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                  0x2c))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              if (param_5 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) +
                            0x2d) {
                uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                    0x20))();
                iVar2 = (int)uVar1 >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
                }
                if (param_4 < (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2)
                              + 0x2b) {
                  DAT_0057a738 = 2;
                  func_0x00477708();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
          uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) + 0x2c)
                  )();
          iVar2 = (int)uVar1 >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
          }
          if (iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) + 10 < param_5) {
            uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                0x20))();
            iVar2 = (int)uVar1 >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
            }
            if ((*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2) + 0x2e <
                param_4) {
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                  0x2c))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              if (param_5 < iVar2 + *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x10) +
                            0x2d) {
                uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xfc) +
                                    0x20))();
                iVar2 = (int)uVar1 >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
                }
                if (param_4 < (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x14) - iVar2)
                              + 0x42) {
                  DAT_0057a738 = 3;
                  func_0x00477708();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
        }
        iStack_4c = 0;
        do {
          if (*(int *)(&DAT_0058ca94 + iStack_4c * 0x5c) == 0) break;
          iVar2 = (int)*(uint *)(&DAT_0058cac8 + iStack_4c * 0x5c) >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((*(uint *)(&DAT_0058cac8 + iStack_4c * 0x5c) & 1) != 0);
          }
          if (*(int *)(&DAT_0058ca98 + iStack_4c * 0x5c) - iVar2 < param_5) {
            iVar2 = (int)*(uint *)(&DAT_0058cac8 + iStack_4c * 0x5c) >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((*(uint *)(&DAT_0058cac8 + iStack_4c * 0x5c) & 1) != 0);
            }
            if (param_5 < *(int *)(&DAT_0058ca98 + iStack_4c * 0x5c) + iVar2) {
              iVar2 = (int)*(uint *)(&DAT_0058cacc + iStack_4c * 0x5c) >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((*(uint *)(&DAT_0058cacc + iStack_4c * 0x5c) & 1) != 0);
              }
              if (*(int *)(&DAT_0058ca9c + iStack_4c * 0x5c) - iVar2 < param_4) {
                iVar2 = (int)*(uint *)(&DAT_0058cacc + iStack_4c * 0x5c) >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((*(uint *)(&DAT_0058cacc + iStack_4c * 0x5c) & 1) != 0);
                }
                if (param_4 < *(int *)(&DAT_0058ca9c + iStack_4c * 0x5c) + iVar2) {
                  FUN_0048c428();
                  iVar2 = FUN_00402928();
                  if (iVar2 == 0) {
                    if (*(int *)(iStack_40 + 0x3c018) == 100) {
                      uStack_2c = 8;
                      puVar3 = (undefined4 *)FUN_00540ec4(auStack_8,0x556c96);
                      iStack_20 = iStack_20 + 1;
                      FUN_00500350(*puVar3);
                      iStack_20 = iStack_20 + -1;
                      FUN_00540fe8(auStack_8,2);
                      Published_SpeedButton20Click_0043e794
                                (iStack_40,*(undefined4 *)(iStack_40 + 0x400));
                    }
                    else {
                      *(undefined4 *)(*(int *)PTR__GcForm_005799ec + 0x318) =
                           *(undefined4 *)(iStack_40 + 0x3c020);
                      uStack_2c = 0x14;
                      uVar4 = FUN_004016e8(auStack_c);
                      iStack_20 = iStack_20 + 1;
                      FUN_0052bac0(*(int *)(iStack_40 + 0x3c020) + 1,uVar4);
                      uVar4 = FUN_004016e8(auStack_10);
                      iStack_20 = iStack_20 + 1;
                      FUN_0054139c(0x556cac,auStack_c,uVar4);
                      uVar4 = FUN_004016e8(auStack_18);
                      iStack_20 = iStack_20 + 1;
                      FUN_00540ec4(auStack_14,0x556cb6);
                      iStack_20 = iStack_20 + 1;
                      FUN_00541040(auStack_10,auStack_14,uVar4);
                      FUN_00541018(*(int *)PTR__GcForm_005799ec + 0x314,auStack_18);
                      iStack_20 = iStack_20 + -1;
                      FUN_00540fe8(auStack_18,2);
                      iStack_20 = iStack_20 + -1;
                      FUN_00540fe8(auStack_14,2);
                      iStack_20 = iStack_20 + -1;
                      FUN_00540fe8(auStack_10,2);
                      iStack_20 = iStack_20 + -1;
                      FUN_00540fe8(auStack_c,2);
                      *(undefined4 *)(*(int *)PTR__GcForm_005799ec + 0x310) =
                           *(undefined4 *)(iStack_40 + 0x3c01c);
                      DAT_0057a6f8 = 0;
                      (**(code **)(**(int **)PTR__GcForm_005799ec + 0xd8))();
                      if (*(char *)(*(int *)PTR__GcForm_005799ec + 0x31c) == '\x01') {
                        DAT_0057a6f8 = 0;
                        Published_SpeedButton20Click_0043e794
                                  (iStack_40,*(undefined4 *)(iStack_40 + 0x2f8));
                      }
                      else {
                        DAT_0057a6f8 = 1;
                      }
                    }
                  }
                  FUN_0048c758();
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
          iStack_4c = iStack_4c + 1;
        } while (iStack_4c < 100);
      }
      FUN_00454e44();
      FUN_00459f1c();
      if (DAT_0057a6f8 != 1) {
        FUN_004126dc(iStack_40);
      }
      *in_FS_OFFSET = uStack_3c;
    }
    else {
      if ((cStack_45 == '\x01') && (DAT_0057a724 == 0)) {
        DAT_0057a730 = 0;
        DAT_0057a734 = 0;
        DAT_0057a738 = 0;
        iStack_54 = FUN_00459760();
        if (iStack_54 != -1) {
          DAT_0057a730 = 0x3e9;
          DAT_0057a734 = iStack_54;
          *(int *)(iStack_40 + 0x5ac) =
               param_5 - *(int *)(*(int *)(&DAT_0058baec + iStack_54 * 4) + 8);
          *(int *)(iStack_40 + 0x5b0) =
               param_4 - *(int *)(*(int *)(&DAT_0058baec + DAT_0057a734 * 4) + 0xc);
          FUN_004126dc(iStack_40);
          FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_64);
          FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_5c);
          (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                    (*(int **)(iStack_40 + 0x3a4),auStack_5c[0],uStack_60);
          *in_FS_OFFSET = uStack_3c;
          return;
        }
        iStack_54 = 0xffffffff;
        for (iStack_4c = 0; iStack_4c < DAT_0058779c; iStack_4c = iStack_4c + 1) {
          if (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) == 0x12d) {
            iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) + 0x2c))
                              ();
            if (((((((float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) -
                     (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_5) &&
                   (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc)
                                        + 0x2c))(),
                   (float)param_5 <
                   (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) +
                   ((float)iVar2 * 0.5 - 24.0) * (float)_DAT_005636c0)) &&
                  (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                       0x20))(),
                  (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
                  ((float)iVar2 * 0.5 -
                  (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x74)) *
                  (float)_DAT_005636c0 < (float)param_4)) &&
                 ((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                       0x20))(),
                  (float)param_4 <
                  (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
                  (((float)iVar2 * 0.5 -
                   (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x74)) + 15.0) *
                  (float)_DAT_005636c0 &&
                  (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xc) == 0)))) ||
                ((((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc)
                                        + 0x2c))(),
                   (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) -
                   ((float)iVar2 * 0.5 - 14.0) * (float)_DAT_005636c0 < (float)param_5 &&
                   ((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc)
                                         + 0x2c))(),
                    (float)param_5 <
                    (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) -
                    ((float)iVar2 * 0.5 - 36.0) * (float)_DAT_005636c0 &&
                    (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc)
                                         + 0x20))(),
                    (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
                    ((float)iVar2 * 0.5 -
                    (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x74)) *
                    (float)_DAT_005636c0 < (float)param_4)))) &&
                  (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                       0x20))(),
                  (float)param_4 <
                  (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
                  (((float)iVar2 * 0.5 -
                   (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x74)) + 22.0) *
                  (float)_DAT_005636c0)) &&
                 (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xc) == 1)))) &&
               (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x68) != 0)) {
              DAT_0057a730 = *(undefined4 *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8);
              DAT_0057a734 = iStack_4c;
              DAT_0057a738 = 1;
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) + 0x20
                                  ))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              *(int *)(iStack_40 + 0x5b0) =
                   ((iVar2 - param_4) + *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14)) -
                   *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x74);
              FUN_004126dc(iStack_40);
              FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_74);
              FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_6c);
              (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                        (*(int **)(iStack_40 + 0x3a4),auStack_6c[0],uStack_70);
              *in_FS_OFFSET = uStack_3c;
              return;
            }
            iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) + 0x2c))
                              ();
            in_ST6 = in_ST5;
            if (((((float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) -
                   (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_5) &&
                 (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                      0x2c))(), in_ST6 = in_ST5,
                 (float)param_5 <
                 (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) +
                 ((float)iVar2 * 0.5 - 4.0) * (float)_DAT_005636c0)) &&
                (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                     0x20))(), in_ST6 = in_ST5,
                (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
                (((float)iVar2 * 0.5 -
                 (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x7c)) + 4.0) *
                (float)_DAT_005636c0 < (float)param_4)) &&
               ((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                     0x20))(), in_ST6 = in_ST5,
                (float)param_4 <
                (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
                (((float)iVar2 * 0.5 -
                 (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x7c)) + 12.0) *
                (float)_DAT_005636c0 &&
                (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x6c) != 0)))) {
              DAT_0057a730 = *(undefined4 *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8);
              DAT_0057a734 = iStack_4c;
              DAT_0057a738 = 2;
              uVar1 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) + 0x20
                                  ))();
              iVar2 = (int)uVar1 >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((uVar1 & 1) != 0);
              }
              *(int *)(iStack_40 + 0x5b0) =
                   ((iVar2 - param_4) + *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14)) -
                   *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x7c);
              FUN_004126dc(iStack_40);
              FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_84);
              FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_7c);
              (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                        (*(int **)(iStack_40 + 0x3a4),auStack_7c[0],uStack_80);
              *in_FS_OFFSET = uStack_3c;
              return;
            }
          }
        }
        for (iStack_4c = 0; iStack_4c < DAT_0058779c; iStack_4c = iStack_4c + 1) {
          if ((*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) == 0x137) &&
             (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xc) == 2)) {
            FUN_005399d8();
            FUN_005399d8();
            lVar5 = in_ST6;
            FUN_0053ace8();
            in_ST6 = lVar5;
            FUN_005399d8();
            FUN_005399d8();
            FUN_0053ace8();
            FUN_005399d8();
            FUN_005399d8();
            FUN_0053ace8();
            FUN_005394d4();
            if (lVar5 <= (longdouble)2.0) {
              DAT_0057a730 = *(undefined4 *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8);
              DAT_0057a734 = iStack_4c;
              *(int *)(iStack_40 + 0x5ac) =
                   param_5 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10);
              *(int *)(iStack_40 + 0x5b0) =
                   param_4 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14);
              FUN_004126dc(iStack_40);
              FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_94);
              FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_8c);
              (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                        (*(int **)(iStack_40 + 0x3a4),auStack_8c[0],uStack_90);
              *in_FS_OFFSET = uStack_3c;
              return;
            }
          }
        }
        iStack_4c = 0;
        do {
          if (*(int *)(&DAT_0058ca94 + iStack_4c * 0x5c) == 0) break;
          iVar2 = (int)*(uint *)(&DAT_0058cac8 + iStack_4c * 0x5c) >> 1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + (uint)((*(uint *)(&DAT_0058cac8 + iStack_4c * 0x5c) & 1) != 0);
          }
          if (*(int *)(&DAT_0058ca98 + iStack_4c * 0x5c) - iVar2 < param_5) {
            iVar2 = (int)*(uint *)(&DAT_0058cac8 + iStack_4c * 0x5c) >> 1;
            if (iVar2 < 0) {
              iVar2 = iVar2 + (uint)((*(uint *)(&DAT_0058cac8 + iStack_4c * 0x5c) & 1) != 0);
            }
            if (param_5 < *(int *)(&DAT_0058ca98 + iStack_4c * 0x5c) + iVar2) {
              iVar2 = (int)*(uint *)(&DAT_0058cacc + iStack_4c * 0x5c) >> 1;
              if (iVar2 < 0) {
                iVar2 = iVar2 + (uint)((*(uint *)(&DAT_0058cacc + iStack_4c * 0x5c) & 1) != 0);
              }
              if (*(int *)(&DAT_0058ca9c + iStack_4c * 0x5c) - iVar2 < param_4) {
                iVar2 = (int)*(uint *)(&DAT_0058cacc + iStack_4c * 0x5c) >> 1;
                if (iVar2 < 0) {
                  iVar2 = iVar2 + (uint)((*(uint *)(&DAT_0058cacc + iStack_4c * 0x5c) & 1) != 0);
                }
                if (param_4 < *(int *)(&DAT_0058ca9c + iStack_4c * 0x5c) + iVar2) {
                  DAT_0057a730 = 2000;
                  DAT_0057a734 = iStack_4c;
                  *(int *)(iStack_40 + 0x5ac) = param_5 - *(int *)(&DAT_0058ca98 + iStack_4c * 0x5c)
                  ;
                  *(int *)(iStack_40 + 0x5b0) = param_4 - *(int *)(&DAT_0058ca9c + iStack_4c * 0x5c)
                  ;
                  FUN_004126dc(iStack_40);
                  FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_a4);
                  FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_9c);
                  (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                            (*(int **)(iStack_40 + 0x3a4),auStack_9c[0],uStack_a0);
                  *in_FS_OFFSET = uStack_3c;
                  return;
                }
              }
            }
          }
          iStack_4c = iStack_4c + 1;
        } while (iStack_4c < 100);
        for (iStack_4c = 0; iStack_4c < DAT_0058779c; iStack_4c = iStack_4c + 1) {
          iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) + 0x2c))()
          ;
          if (((((float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) -
                 (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_5) &&
               (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                    0x2c))(),
               (float)param_5 <
               (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) +
               (float)iVar2 * 0.5 * (float)_DAT_005636c0)) &&
              (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                   0x20))(),
              (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) -
              (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_4)) &&
             ((((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                     0x20))(),
                (float)param_4 <
                (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
                (float)iVar2 * 0.5 * (float)_DAT_005636c0 &&
                (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) != 0x12d)) &&
               ((*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) != 0x13c &&
                (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) != 0x13e)))) &&
              ((*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) != 0x137 ||
               (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xc) != 2)))))) {
            DAT_0057a730 = *(undefined4 *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8);
            DAT_0057a734 = iStack_4c;
            *(int *)(iStack_40 + 0x5ac) =
                 param_5 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10);
            *(int *)(iStack_40 + 0x5b0) =
                 param_4 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14);
            FUN_004126dc(iStack_40);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_b4);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_ac);
            (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                      (*(int **)(iStack_40 + 0x3a4),auStack_ac[0],uStack_b0);
            *in_FS_OFFSET = uStack_3c;
            return;
          }
        }
        for (iStack_4c = 0; iStack_4c < DAT_0058779c; iStack_4c = iStack_4c + 1) {
          iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) + 0x2c))()
          ;
          if (((((float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) -
                 (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_5) &&
               (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                    0x2c))(),
               (float)param_5 <
               (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) +
               (float)iVar2 * 0.5 * (float)_DAT_005636c0)) &&
              (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                   0x20))(),
              (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) -
              (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_4)) &&
             ((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                   0x20))(),
              (float)param_4 <
              (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
              (float)iVar2 * 0.5 * (float)_DAT_005636c0 &&
              (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) == 0x13c)))) {
            DAT_0057a730 = *(undefined4 *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8);
            DAT_0057a734 = iStack_4c;
            *(int *)(iStack_40 + 0x5ac) =
                 param_5 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10);
            *(int *)(iStack_40 + 0x5b0) =
                 param_4 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14);
            FUN_004126dc(iStack_40);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_c4);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_bc);
            (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                      (*(int **)(iStack_40 + 0x3a4),auStack_bc[0],uStack_c0);
            *in_FS_OFFSET = uStack_3c;
            return;
          }
        }
        for (iStack_4c = 0; iStack_4c < DAT_0058779c; iStack_4c = iStack_4c + 1) {
          iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) + 0x2c))()
          ;
          if ((((float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) -
                (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_5) &&
              (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                   0x2c))(),
              (float)param_5 <
              (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) +
              (float)iVar2 * 0.5 * (float)_DAT_005636c0)) &&
             ((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                   0x20))(),
              (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) -
              (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_4 &&
              ((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                    0x20))(),
               (float)param_4 <
               (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
               (float)iVar2 * 0.5 * (float)_DAT_005636c0 &&
               (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) == 0x12d)))))) {
            DAT_0057a730 = *(undefined4 *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8);
            DAT_0057a734 = iStack_4c;
            *(int *)(iStack_40 + 0x5ac) =
                 param_5 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10);
            *(int *)(iStack_40 + 0x5b0) =
                 param_4 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14);
            FUN_004126dc(iStack_40);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_d4);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_cc);
            (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                      (*(int **)(iStack_40 + 0x3a4),auStack_cc[0],uStack_d0);
            *in_FS_OFFSET = uStack_3c;
            return;
          }
        }
        for (iStack_4c = 0; iStack_4c < DAT_0058779c; iStack_4c = iStack_4c + 1) {
          if (((((double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xc4) * _DAT_005636c0 +
                 (double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) < (double)param_5)
               && ((double)param_5 <
                   (double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xcc) +
                   (double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xc4) * _DAT_005636c0
                   + (double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10))) &&
              ((double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 200) * _DAT_005636c0 +
               (double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) < (double)param_4))
             && (((((double)param_4 <
                    (double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xd0) * _DAT_005636c0
                    + (double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 200) *
                      _DAT_005636c0 +
                      (double)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) &&
                   (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) != 0x12d)) &&
                  ((*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) != 0x13c &&
                   (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) != 0x13e)))) &&
                 ((*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) != 0x137 ||
                  (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xc) != 2)))))) {
            DAT_0057a730 = *(undefined4 *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8);
            DAT_0057a734 = iStack_4c;
            DAT_0057a738 = 1;
            uVar4 = FUN_005394fc();
            *(undefined4 *)(iStack_40 + 0x5ac) = uVar4;
            uVar4 = FUN_005394fc();
            *(undefined4 *)(iStack_40 + 0x5b0) = uVar4;
            FUN_004126dc(iStack_40);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_e4);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_dc);
            (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                      (*(int **)(iStack_40 + 0x3a4),auStack_dc[0],uStack_e0);
            *in_FS_OFFSET = uStack_3c;
            return;
          }
        }
        iStack_e8 = 0;
        do {
          if (*(int *)(&DAT_0057a750 + iStack_e8 * 0x34) == 0) break;
          if ((((*(int *)(&DAT_0057a754 + iStack_e8 * 0x34) < param_5) &&
               ((double)param_5 <
                (double)*(int *)(&DAT_0057a75c + iStack_e8 * 0x34) * _DAT_005636c0 +
                (double)*(int *)(&DAT_0057a754 + iStack_e8 * 0x34))) &&
              (*(int *)(&DAT_0057a758 + iStack_e8 * 0x34) < param_4)) &&
             ((double)param_4 <
              (double)*(int *)(&DAT_0057a760 + iStack_e8 * 0x34) * _DAT_005636c0 +
              (double)*(int *)(&DAT_0057a758 + iStack_e8 * 0x34))) {
            DAT_0057a730 = 1000;
            DAT_0057a734 = iStack_e8;
            *(int *)(iStack_40 + 0x5ac) = param_5 - *(int *)(&DAT_0057a754 + iStack_e8 * 0x34);
            *(int *)(iStack_40 + 0x5b0) = param_4 - *(int *)(&DAT_0057a758 + iStack_e8 * 0x34);
            FUN_004126dc(iStack_40);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_f8);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_f0);
            (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                      (*(int **)(iStack_40 + 0x3a4),auStack_f0[0],uStack_f4);
            *in_FS_OFFSET = uStack_3c;
            return;
          }
          iStack_e8 = iStack_e8 + 1;
        } while (iStack_e8 < 100);
        iStack_fc = 0;
        do {
          if (*(int *)(&DAT_0058ef64 + iStack_fc * 0x148) == 0) break;
          if (((*(int *)(&DAT_0058ef68 + iStack_fc * 0x148) + -0x78 < param_5) &&
              (param_5 < *(int *)(&DAT_0058ef68 + iStack_fc * 0x148) + 0x78)) &&
             ((*(int *)(&DAT_0058ef6c + iStack_fc * 0x148) + -0x78 < param_4 &&
              (param_4 < *(int *)(&DAT_0058ef6c + iStack_fc * 0x148) + 0x78)))) {
            DAT_0057a730 = 3000;
            DAT_0057a734 = iStack_fc;
            *(int *)(iStack_40 + 0x5ac) = param_5 - *(int *)(&DAT_0058ef68 + iStack_fc * 0x148);
            *(int *)(iStack_40 + 0x5b0) = param_4 - *(int *)(&DAT_0058ef6c + iStack_fc * 0x148);
            FUN_004126dc(iStack_40);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_10c);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_104);
            (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                      (*(int **)(iStack_40 + 0x3a4),auStack_104[0],uStack_108);
            *in_FS_OFFSET = uStack_3c;
            return;
          }
          iStack_fc = iStack_fc + 1;
        } while (iStack_fc < 10);
        for (iStack_4c = 0; iStack_4c < DAT_0058779c; iStack_4c = iStack_4c + 1) {
          iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) + 0x2c))()
          ;
          if ((((float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) -
                (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_5) &&
              (iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                   0x2c))(),
              (float)param_5 <
              (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10) +
              (float)iVar2 * 0.5 * (float)_DAT_005636c0)) &&
             ((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                   0x20))(),
              (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) -
              (float)iVar2 * 0.5 * (float)_DAT_005636c0 < (float)param_4 &&
              ((iVar2 = (**(code **)(**(int **)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0xfc) +
                                    0x20))(),
               (float)param_4 <
               (float)*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14) +
               (float)iVar2 * 0.5 * (float)_DAT_005636c0 &&
               (*(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8) == 0x13e)))))) {
            DAT_0057a730 = *(undefined4 *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 8);
            DAT_0057a734 = iStack_4c;
            *(int *)(iStack_40 + 0x5ac) =
                 param_5 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x10);
            *(int *)(iStack_40 + 0x5b0) =
                 param_4 - *(int *)(*(int *)(&DAT_00585850 + iStack_4c * 4) + 0x14);
            FUN_004126dc(iStack_40);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_11c);
            FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_114);
            (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                      (*(int **)(iStack_40 + 0x3a4),auStack_114[0],uStack_118);
            *in_FS_OFFSET = uStack_3c;
            return;
          }
        }
        if ((DAT_0057a704 != DAT_0057a70c) && (DAT_0057a708 != DAT_0057a710)) {
          FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_12c);
          FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_124);
          (**(code **)(**(int **)(iStack_40 + 0x4d0) + 0x40))
                    (*(int **)(iStack_40 + 0x4d0),auStack_124[0],uStack_128);
        }
        if (DAT_0057a73c != 0) {
          FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_13c);
          FUN_0050f6ac(*(undefined4 *)PTR_DAT_00579a18,auStack_134);
          (**(code **)(**(int **)(iStack_40 + 0x3a4) + 0x40))
                    (*(int **)(iStack_40 + 0x3a4),auStack_134[0],uStack_138);
        }
      }
      *in_FS_OFFSET = uStack_3c;
    }
  }
  else {
    *(int *)(iStack_40 + 0x588) = *(int *)(iStack_40 + 0x588) + -1;
    *in_FS_OFFSET = uStack_3c;
  }
  return;
}



