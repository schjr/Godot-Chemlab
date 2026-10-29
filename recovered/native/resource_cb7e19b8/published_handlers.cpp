/* Published event names recovered from executable metadata.
   Bodies are Ghidra pseudocode, not original/buildable source.
   Class ownership and original signatures are unresolved. */

// Preserved published name: FormShow
// Entry 00411bac, recovered name Published_FormShow_00411bac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_FormShow_00411bac(int param_1)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  int iVar9;
  uint *puVar10;
  char *pcVar11;
  uint *puVar12;
  undefined4 *in_FS_OFFSET;
  byte bVar13;
  CHAR local_86c [1004];
  uint local_480 [257];
  int local_7c;
  undefined4 local_78;
  undefined2 local_68;
  int local_5c;
  int local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c [3];
  int local_20;
  int local_1c;
  int local_18;
  uint *local_14;
  int local_10;
  char *local_c;
  int local_8;
  
  bVar13 = 0;
  local_7c = param_1;
  FUN_004be6dc(0x4e129c);
  local_68 = 8;
  local_c = (char *)0x0;
  local_5c = local_5c + 1;
  FUN_004946c4(*(undefined4 *)PTR_DAT_004efd74,(int *)&local_c);
  pcVar2 = local_c;
  if (local_c == (char *)0x0) {
    pcVar2 = &DAT_004df688;
  }
  uVar7 = 0xffffffff;
  do {
    pcVar11 = pcVar2;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar11 = pcVar2 + (uint)bVar13 * -2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar11;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  puVar10 = (uint *)(pcVar11 + -uVar7);
  puVar12 = local_480;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar12 = *puVar10;
    puVar10 = puVar10 + (uint)bVar13 * -2 + 1;
    puVar12 = puVar12 + (uint)bVar13 * -2 + 1;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(char *)puVar12 = (char)*puVar10;
    puVar10 = (uint *)((int)puVar10 + (uint)bVar13 * -2 + 1);
    puVar12 = (uint *)((int)puVar12 + (uint)bVar13 * -2 + 1);
  }
  local_5c = local_5c + -1;
  FUN_004ca834((int *)&local_c,2);
  pcVar11 = FUN_004be468(local_480);
  for (pcVar2 = (char *)((int)local_480 + (int)pcVar11); *pcVar2 != '\\'; pcVar2 = pcVar2 + -1) {
    pcVar11 = pcVar11 + -1;
  }
  *(char *)((int)local_480 + (int)pcVar11) = '\0';
  local_68 = 0x14;
  piVar3 = FUN_004ca710(&local_10);
  local_5c = local_5c + 1;
  FUN_004ca864((int *)&DAT_004f05ac,piVar3);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_10,2);
  FUN_004ca864((int *)(local_7c + 0x38c),(undefined4 *)&DAT_004f05ac);
  FUN_0041137c();
  local_68 = 0x20;
  local_14 = (uint *)0x0;
  local_5c = local_5c + 1;
  FUN_004946c4(*(undefined4 *)PTR_DAT_004efd74,(int *)&local_14);
  FUN_0049d4c8(local_7c,local_14);
  local_5c = local_5c + -1;
  FUN_004ca834((int *)&local_14,2);
  if (DAT_004f0550 == 0) {
    FUN_0049d3b0(*(int **)(local_7c + 0x2e0),0,local_7c);
    piVar3 = (int *)FUN_004841d8(*(int **)(*(int *)(local_7c + 0x350) + 0x128));
    (**(code **)(*piVar3 + 0x40))(piVar3,*(undefined4 *)(*(int *)(local_7c + 0x350) + 0x38));
    piVar3 = (int *)FUN_004841d8(*(int **)(*(int *)(local_7c + 0x350) + 0x128));
    (**(code **)(*piVar3 + 0x34))(piVar3,*(undefined4 *)(*(int *)(local_7c + 0x350) + 0x3c));
  }
  _DAT_004f055c = 0;
  local_8 = 0;
  local_5c = local_5c + 1;
  _DAT_004f056c = 0;
  local_68 = 0x38;
  GetWindowsDirectoryA(local_86c,1000);
  local_68 = 0x44;
  FUN_004ca710(&local_18);
  local_5c = local_5c + 1;
  FUN_004ca864(&local_8,&local_18);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_18,2);
  local_68 = 0x50;
  FUN_004ca710(&local_1c);
  local_20 = 0;
  local_5c = local_5c + 2;
  FUN_004ca878(&local_8,&local_1c,&local_20);
  FUN_004ca864((int *)&DAT_004f05b0,&local_20);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_20,2);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_1c,2);
  local_68 = 0x5c;
  FUN_004ca710(local_2c + 2);
  local_2c[1] = 0;
  local_5c = local_5c + 2;
  FUN_004ca878((undefined4 *)&DAT_004f05b0,local_2c + 2,local_2c + 1);
  FUN_004ca864((int *)(local_7c + 0x3cc),local_2c + 1);
  local_5c = local_5c + -1;
  FUN_004ca834(local_2c + 1,2);
  local_5c = local_5c + -1;
  FUN_004ca834(local_2c + 2,2);
  uVar4 = FUN_00412208((int *)&PTR_FUN_004a8c98,'\x01');
  *(undefined4 *)(local_7c + 0x3d0) = uVar4;
  *(undefined1 *)(local_7c + 0xbab) = 0;
  *(undefined4 *)(local_7c + 0x3b8) = 0;
  DAT_004fd60c = 0;
  DAT_005028fc = 0;
  iVar9 = 0;
  puVar5 = &DAT_004f05c0;
  do {
    iVar9 = iVar9 + 1;
    *puVar5 = 0;
    puVar5[0xc] = 0;
    puVar5 = puVar5 + 0xd;
  } while (iVar9 < 0x66);
  iVar9 = 0;
  puVar5 = &DAT_00504dd4;
  do {
    iVar9 = iVar9 + 1;
    *puVar5 = 0;
    puVar5 = puVar5 + 0x52;
  } while (iVar9 < 10);
  FUN_0043350c();
  uVar4 = FUN_004c69f4((int *)0x0);
  FUN_004c3468(uVar4);
  local_68 = 0x68;
  DAT_004f6898 = 0;
  FUN_004ca710(local_2c);
  local_30 = 0;
  local_5c = local_5c + 2;
  FUN_004ca878((undefined4 *)&DAT_004f05b0,local_2c,&local_30);
  FUN_0043c458(local_30);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_30,2);
  local_5c = local_5c + -1;
  FUN_004ca834(local_2c,2);
  local_68 = 0x74;
  DAT_004fb6bc = 0;
  FUN_004ca710(&local_34);
  local_38 = 0;
  local_5c = local_5c + 2;
  FUN_004ca878((undefined4 *)&DAT_004f05b0,&local_34,&local_38);
  FUN_0043ca38(local_38);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_38,2);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_34,2);
  puVar5 = (undefined4 *)(local_7c + 0xbb0);
  FUN_0041225c(puVar5);
  piVar3 = FUN_004860ec((int *)&PTR_FUN_00480310,'\x01',puVar5);
  *(int **)(local_7c + 0xbac) = piVar3;
  DAT_004fc660 = FUN_004860ec((int *)&PTR_FUN_00480310,'\x01',local_7c);
  (**(code **)(*DAT_004fc660 + 0x3c))(DAT_004fc660,1);
  FUN_004876e4(DAT_004fc660,0xffffff);
  DAT_004fc664 = FUN_004860ec((int *)&PTR_FUN_00480310,'\x01',extraout_ECX);
  (**(code **)(*DAT_004fc664 + 0x3c))(DAT_004fc664,1);
  FUN_004876e4(DAT_004fc664,0xffffff);
  DAT_004f05b4 = 0xffffff;
  FUN_00410fc0(local_7c);
  iVar9 = FUN_004841d8(*(int **)(*(int *)(local_7c + 0x350) + 0x128));
  (**(code **)(**(int **)(local_7c + 0xbac) + 8))(*(int **)(local_7c + 0xbac),iVar9);
  piVar3 = FUN_004860ec((int *)&PTR_FUN_00480310,'\x01',extraout_ECX_00);
  local_68 = 0x80;
  DAT_004f058c = piVar3;
  FUN_004ca710(&local_3c);
  local_40 = 0;
  local_5c = local_5c + 2;
  FUN_004ca878((undefined4 *)&DAT_004f05b0,&local_3c,&local_40);
  (**(code **)(*piVar3 + 0x48))(piVar3,local_40);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_40,2);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_3c,2);
  piVar3 = FUN_004db8fc((int *)&PTR_FUN_004db6bc,'\x01',extraout_ECX_01);
  local_68 = 0x8c;
  FUN_004ca710(&local_44);
  local_48 = 0;
  local_5c = local_5c + 2;
  FUN_004ca878((undefined4 *)&DAT_004f05b0,&local_44,&local_48);
  (**(code **)(*piVar3 + 0x48))(piVar3,local_48);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_48,2);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_44,2);
  piVar6 = FUN_004860ec((int *)&PTR_FUN_00480310,'\x01',extraout_ECX_02);
  *(int **)(local_7c + 0x368) = piVar6;
  (**(code **)(*piVar6 + 8))(piVar6,piVar3);
  local_50 = piVar3;
  if (piVar3 != (int *)0x0) {
    local_4c = *piVar3;
    local_68 = 0xa4;
    (**(code **)(*piVar3 + -4))(piVar3,3);
  }
  *(undefined4 *)(local_7c + 0x388) = 0;
  local_68 = 0xb0;
  FUN_004ca710(&local_54);
  local_5c = local_5c + 1;
  cVar1 = FUN_004ca91c((undefined4 *)(local_7c + 0x3cc),&local_54);
  local_5c = local_5c + -1;
  FUN_004ca834(&local_54,2);
  if (cVar1 != '\0') {
    FUN_0041e2e8(local_7c,*(undefined4 *)(local_7c + 0x3cc),1);
    (**(code **)(**(int **)(local_7c + 0x350) + 0x5c))(*(int **)(local_7c + 0x350),1);
    FUN_00429888(local_7c);
  }
  local_5c = local_5c + -1;
  FUN_004ca834(&local_8,2);
  *in_FS_OFFSET = local_78;
  return;
}



// Preserved published name: FormResize
// Entry 004123f4, recovered name Published_FormResize_004123f4

void Published_FormResize_004123f4(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004841d8(*(int **)(*(int *)(param_1 + 0x350) + 0x128));
  (**(code **)(*piVar1 + 0x40))(piVar1,*(undefined4 *)(*(int *)(param_1 + 0x350) + 0x38));
  piVar1 = (int *)FUN_004841d8(*(int **)(*(int *)(param_1 + 0x350) + 0x128));
  (**(code **)(*piVar1 + 0x34))(piVar1,*(undefined4 *)(*(int *)(param_1 + 0x350) + 0x3c));
  FUN_00410fc0(param_1);
  return;
}



// Preserved published name: Image1MouseDown
// Entry 00412440, recovered name Published_Image1MouseDown_00412440

void Published_Image1MouseDown_00412440
               (int param_1,undefined4 param_2,char param_3,int param_4,int param_5)

{
  double dVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  int *piVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST0;
  longdouble lVar10;
  longdouble lVar11;
  longdouble in_ST1;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  undefined1 *local_84;
  int *local_7c;
  int *local_74;
  char *local_70;
  undefined1 *local_6c;
  int *local_64;
  int *local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_48;
  undefined4 local_38;
  int local_14 [3];
  int local_8;
  
  FUN_004be6dc(0x4e13a8);
  if (*(int *)(param_1 + 0x388) != 0) {
    *(int *)(param_1 + 0x388) = *(int *)(param_1 + 0x388) + -1;
    *in_FS_OFFSET = local_38;
    return;
  }
  local_8 = 0;
  *(int *)(param_1 + 0x398) = param_5;
  *(int *)(param_1 + 0x39c) = param_4;
  FUN_0049d5dc(*(int *)(param_1 + 0x350),'\0');
  if (param_3 == '\0') {
    *(undefined4 *)(param_1 + 0x3b4) = 1;
    if (DAT_004f0590 == 0) {
      if (DAT_004f059c == 0xcc) {
        uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
        iVar4 = (int)uVar3 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
        }
        if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4 < param_4) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x14) {
                DAT_004f05a4 = 1;
                *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10)
                ;
                *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14)
                ;
                goto LAB_00414cd2;
              }
            }
          }
        }
        uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
        iVar4 = (int)uVar3 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
        }
        if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if ((*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x17 < param_4) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x2b) {
                DAT_004f05a4 = 2;
                *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10)
                ;
                *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14)
                ;
                goto LAB_00414cd2;
              }
            }
          }
        }
      }
      if ((DAT_004f059c == 0xcf) || (DAT_004f059c == 0xd0)) {
        uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
        iVar4 = (int)uVar3 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
        }
        if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x46 < param_4) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_4 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x32) {
                DAT_004f05a4 = 1;
                *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10)
                ;
                *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14)
                ;
                goto LAB_00414cd2;
              }
            }
          }
        }
        uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
        iVar4 = (int)uVar3 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
        }
        if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x2f < param_4) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_4 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x1b) {
                DAT_004f05a4 = 2;
                *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10)
                ;
                *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14)
                ;
                goto LAB_00414cd2;
              }
            }
          }
        }
        uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
        iVar4 = (int)uVar3 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
        }
        if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x18 < param_4) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_4 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -4) {
                DAT_004f05a4 = 3;
                *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10)
                ;
                *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14)
                ;
                goto LAB_00414cd2;
              }
            }
          }
        }
      }
      if (DAT_004f059c == 0xd3) {
        uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
        iVar4 = (int)uVar3 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
        }
        if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4 < param_4) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x14) {
                DAT_004f05a4 = 1;
                *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10)
                ;
                *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14)
                ;
                goto LAB_00414cd2;
              }
            }
          }
        }
        uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
        iVar4 = (int)uVar3 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
        }
        if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if ((*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x17 < param_4) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x2b) {
                DAT_004f05a4 = 2;
                *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10)
                ;
                *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14)
                ;
                goto LAB_00414cd2;
              }
            }
          }
        }
        uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
        iVar4 = (int)uVar3 >> 1;
        if (iVar4 < 0) {
          iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
        }
        if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if ((*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x2e < param_4) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x42) {
                DAT_004f05a4 = 3;
                *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10)
                ;
                *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14)
                ;
                goto LAB_00414cd2;
              }
            }
          }
        }
      }
      DAT_004f059c = 0;
      DAT_004f05a0 = 0;
      DAT_004f05a4 = 0;
      piVar6 = &DAT_0050195c;
      for (local_48 = 0; local_48 < DAT_005028fc; local_48 = local_48 + 1) {
        iVar4 = *piVar6;
        if (((*(int *)(iVar4 + 8) + -4 < param_5) && (param_5 < *(int *)(iVar4 + 8) + 4)) &&
           ((*(int *)(iVar4 + 0xc) + -4 < param_4 && (param_4 < *(int *)(iVar4 + 0xc) + 4)))) {
          DAT_004f059c = 0x3e9;
          DAT_004f05a0 = local_48;
          DAT_004f05a4 = 1;
          *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_0050195c)[local_48] + 8);
          *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0xc);
          goto LAB_00414cd2;
        }
        iVar4 = *piVar6;
        if ((((*(int *)(iVar4 + 0x10) + -4 < param_5) && (param_5 < *(int *)(iVar4 + 0x10) + 4)) &&
            (*(int *)(iVar4 + 0x14) + -4 < param_4)) && (param_4 < *(int *)(iVar4 + 0x14) + 4)) {
          DAT_004f059c = 0x3e9;
          DAT_004f05a0 = local_48;
          DAT_004f05a4 = 2;
          *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_0050195c)[local_48] + 0x10);
          *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x14);
          goto LAB_00414cd2;
        }
        piVar6 = piVar6 + 1;
      }
      iVar4 = FUN_00437c00(param_5,param_4);
      if (iVar4 == -1) {
        piVar6 = &DAT_004fb6c0;
        for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
          if (*(int *)(*piVar6 + 8) == 0x12d) {
            uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if ((double)param_5 <= (double)*(int *)(*piVar6 + 0x10) - (double)iVar4 * DAT_004e6fb8)
            {
LAB_00413125:
              uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if ((double)*(int *)(*piVar6 + 0x10) - (double)(iVar4 + -0xe) * DAT_004e6fb8 <
                  (double)param_5) {
                uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if ((double)param_5 <
                    (double)*(int *)(*piVar6 + 0x10) - (double)(iVar4 + -0x24) * DAT_004e6fb8) {
                  uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
                  iVar4 = (int)uVar3 >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                  }
                  if ((double)*(int *)(*piVar6 + 0x14) +
                      (double)(iVar4 - *(int *)(*piVar6 + 0x74)) * DAT_004e6fb8 < (double)param_4) {
                    uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
                    iVar4 = (int)uVar3 >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                    }
                    if (((double)param_4 <
                         (double)*(int *)(*piVar6 + 0x14) +
                         (double)((iVar4 - *(int *)(*piVar6 + 0x74)) + 0x16) * DAT_004e6fb8) &&
                       (*(int *)(*piVar6 + 0xc) == 1)) goto LAB_00413254;
                  }
                }
              }
            }
            else {
              uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if ((double)*(int *)(*piVar6 + 0x10) + (double)(iVar4 + -0x18) * DAT_004e6fb8 <=
                  (double)param_5) goto LAB_00413125;
              uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if ((double)param_4 <=
                  (double)*(int *)(*piVar6 + 0x14) +
                  (double)(iVar4 - *(int *)(*piVar6 + 0x74)) * DAT_004e6fb8) goto LAB_00413125;
              uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (((double)*(int *)(*piVar6 + 0x14) +
                   (double)((iVar4 - *(int *)(*piVar6 + 0x74)) + 0xf) * DAT_004e6fb8 <=
                   (double)param_4) || (*(int *)(*piVar6 + 0xc) != 0)) goto LAB_00413125;
LAB_00413254:
              if (*(int *)(*piVar6 + 0x68) != 0) {
                DAT_004f059c = *(int *)(*piVar6 + 8);
                DAT_004f05a0 = local_48;
                DAT_004f05a4 = 1;
                (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
                uVar5 = FUN_004c2d58();
                *(undefined4 *)(param_1 + 0x3a8) = uVar5;
                goto LAB_00414cd2;
              }
            }
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            in_ST6 = in_ST5;
            if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                   (float)param_5) &&
                 (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(), in_ST6 = in_ST5,
                 (float)param_5 <
                 (float)*(int *)(*piVar6 + 0x10) + ((float)iVar4 * 0.5 - 4.0) * (float)DAT_004e6fb8)
                 ) && (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(), in_ST6 = in_ST5,
                      (float)*(int *)(*piVar6 + 0x14) +
                      (((float)iVar4 * 0.5 - (float)*(int *)(*piVar6 + 0x7c)) + 4.0) *
                      (float)DAT_004e6fb8 < (float)param_4)) &&
               ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(), in_ST6 = in_ST5,
                (float)param_4 <
                (float)*(int *)(*piVar6 + 0x14) +
                (((float)iVar4 * 0.5 - (float)*(int *)(*piVar6 + 0x7c)) + 12.0) *
                (float)DAT_004e6fb8 && (*(int *)(*piVar6 + 0x6c) != 0)))) {
              DAT_004f059c = *(int *)(*piVar6 + 8);
              DAT_004f05a0 = local_48;
              DAT_004f05a4 = 2;
              (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
              uVar5 = FUN_004c2d58();
              *(undefined4 *)(param_1 + 0x3a8) = uVar5;
              goto LAB_00414cd2;
            }
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_004fb6c0;
        for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
          if ((*(int *)(*piVar6 + 8) == 0x137) && (*(int *)(*piVar6 + 0xc) == 2)) {
            lVar10 = in_ST6;
            FUN_004c3234((double)((*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x3c)) -
                                 (*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x44))),0,0x40000000
                        );
            lVar11 = lVar10;
            FUN_004c3234((double)((*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x40)) -
                                 (*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x48))),0,0x40000000
                        );
            FUN_004c4544(SUB84((double)(in_ST1 + (longdouble)(double)in_ST0),0),
                         (uint)((ulonglong)(double)(in_ST1 + (longdouble)(double)in_ST0) >> 0x20));
            in_ST0 = lVar11;
            FUN_004c3234((double)(param_5 - (*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x3c))),0
                         ,0x40000000);
            dVar1 = (double)in_ST3;
            in_ST1 = in_ST0;
            FUN_004c3234((double)(param_4 - (*(int *)(*piVar6 + 0x14) + *(int *)(*piVar6 + 0x40))),0
                         ,0x40000000);
            in_ST3 = in_ST1;
            FUN_004c4544(SUB84((double)(in_ST4 + (longdouble)dVar1),0),
                         (uint)((ulonglong)(double)(in_ST4 + (longdouble)dVar1) >> 0x20));
            FUN_004c3234((double)(param_5 - (*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x44))),0
                         ,0x40000000);
            dVar1 = (double)in_ST6;
            in_ST4 = in_ST3;
            FUN_004c3234((double)(param_4 - (*(int *)(*piVar6 + 0x14) + *(int *)(*piVar6 + 0x48))),0
                         ,0x40000000);
            in_ST6 = in_ST4;
            FUN_004c4544(SUB84((double)(lVar10 + (longdouble)dVar1),0),
                         (uint)((ulonglong)(double)(lVar10 + (longdouble)dVar1) >> 0x20));
            FUN_004c2d30();
            if (lVar11 <= (longdouble)2.0) {
              DAT_004f059c = *(int *)(*piVar6 + 8);
              DAT_004f05a0 = local_48;
              *(int *)(param_1 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
              *(int *)(param_1 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
              goto LAB_00414cd2;
            }
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_00502904;
        local_48 = 0;
        do {
          if (*piVar6 == 0) break;
          iVar4 = piVar6[0xd] >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
          }
          if ((piVar6[1] - iVar4) + -4 < param_5) {
            iVar4 = piVar6[0xd] >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
            }
            if (param_5 < iVar4 + piVar6[1] + 4) {
              iVar4 = piVar6[0xe] >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
              }
              if ((piVar6[2] - iVar4) + -4 < param_4) {
                iVar4 = piVar6[0xe] >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                }
                if (param_4 < iVar4 + piVar6[2] + 4) {
                  DAT_004f059c = 2000;
                  DAT_004f05a0 = local_48;
                  iVar4 = piVar6[0xd] >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
                  }
                  if ((piVar6[1] - iVar4) + -4 < param_5) {
                    iVar4 = piVar6[0xd] >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
                    }
                    if (param_5 < (piVar6[1] - iVar4) + 4) {
                      iVar4 = piVar6[0xe] >> 1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                      }
                      if ((piVar6[2] - iVar4) + -4 < param_4) {
                        iVar4 = piVar6[0xe] >> 1;
                        if (iVar4 < 0) {
                          iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                        }
                        if (param_4 < (piVar6[2] - iVar4) + 4) {
                          DAT_004f05a4 = 1;
                        }
                      }
                    }
                  }
                  iVar4 = piVar6[0xd] >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
                  }
                  if (iVar4 + piVar6[1] + -4 < param_5) {
                    iVar4 = piVar6[0xd] >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
                    }
                    if (param_5 < iVar4 + piVar6[1] + 4) {
                      iVar4 = piVar6[0xe] >> 1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                      }
                      if ((piVar6[2] - iVar4) + -4 < param_4) {
                        iVar4 = piVar6[0xe] >> 1;
                        if (iVar4 < 0) {
                          iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                        }
                        if (param_4 < (piVar6[2] - iVar4) + 4) {
                          DAT_004f05a4 = 2;
                        }
                      }
                    }
                  }
                  iVar4 = piVar6[0xd] >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
                  }
                  if ((piVar6[1] - iVar4) + -4 < param_5) {
                    iVar4 = piVar6[0xd] >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
                    }
                    if (param_5 < (piVar6[1] - iVar4) + 4) {
                      iVar4 = piVar6[0xe] >> 1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                      }
                      if (iVar4 + piVar6[2] + -4 < param_4) {
                        iVar4 = piVar6[0xe] >> 1;
                        if (iVar4 < 0) {
                          iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                        }
                        if (param_4 < iVar4 + piVar6[2] + 4) {
                          DAT_004f05a4 = 3;
                        }
                      }
                    }
                  }
                  iVar4 = piVar6[0xd] >> 1;
                  if (iVar4 < 0) {
                    iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
                  }
                  if (iVar4 + piVar6[1] + -4 < param_5) {
                    iVar4 = piVar6[0xd] >> 1;
                    if (iVar4 < 0) {
                      iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
                    }
                    if (param_5 < iVar4 + piVar6[1] + 4) {
                      iVar4 = piVar6[0xe] >> 1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                      }
                      if (iVar4 + piVar6[2] + -4 < param_4) {
                        iVar4 = piVar6[0xe] >> 1;
                        if (iVar4 < 0) {
                          iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                        }
                        if (param_4 < iVar4 + piVar6[2] + 4) {
                          DAT_004f05a4 = 4;
                        }
                      }
                    }
                  }
                  *(int *)(param_1 + 0x36c) = piVar6[0xd];
                  *(int *)(param_1 + 0x370) = piVar6[0xe];
                  *(int *)(param_1 + 0x374) = piVar6[1];
                  *(int *)(param_1 + 0x378) = piVar6[2];
                  *(int *)(param_1 + 0x3a4) = param_5 - piVar6[1];
                  *(int *)(param_1 + 0x3a8) = param_4 - piVar6[2];
                  goto LAB_00414cd2;
                }
              }
            }
          }
          local_48 = local_48 + 1;
          piVar6 = piVar6 + 0x17;
        } while (local_48 < 100);
        piVar6 = &DAT_004fb6c0;
        for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
          iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
          if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                 (float)param_5) &&
               (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
               (float)param_5 <
               (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8)) &&
              (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
              (float)param_4)) &&
             ((((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                (float)param_4 <
                (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 &&
                (*(int *)(*piVar6 + 8) != 0x12d)) &&
               ((*(int *)(*piVar6 + 8) != 0x13c && (*(int *)(*piVar6 + 8) != 0x13e)))) &&
              ((*(int *)(*piVar6 + 8) != 0x137 || (*(int *)(*piVar6 + 0xc) != 2)))))) {
            DAT_004f059c = *(int *)(*piVar6 + 8);
            DAT_004f05a0 = local_48;
            DAT_004f05a4 = 0;
            *(int *)(param_1 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
            *(int *)(param_1 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
            goto LAB_00414cd2;
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_004fb6c0;
        for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
          iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
          if ((((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0
                 < (float)param_5) &&
               (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
               (float)param_5 <
               (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0)) &&
              (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0 <
              (float)param_4)) &&
             ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)param_4 <
              (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0 &&
              (*(int *)(*piVar6 + 8) == 0x13c)))) {
            DAT_004f059c = *(int *)(*piVar6 + 8);
            DAT_004f05a0 = local_48;
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0
                  < (float)param_5) &&
                ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                 (float)param_5 <
                 ((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) + 4.0
                 && (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                    ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                    4.0 < (float)param_4)))) &&
               (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
               (float)param_4 <
               ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) + 4.0))
            {
              DAT_004f05a4 = 1;
            }
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if ((((((float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                   4.0 < (float)param_5) &&
                 (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                 (float)param_5 <
                 (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0))
                && (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                   4.0 < (float)param_4)) &&
               (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
               (float)param_4 <
               ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) + 4.0))
            {
              DAT_004f05a4 = 2;
            }
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0
                  < (float)param_5) &&
                (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                (float)param_5 <
                ((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) + 4.0))
               && ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   ((float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                   4.0 < (float)param_4 &&
                   (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   (float)param_4 <
                   (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0)
                   ))) {
              DAT_004f05a4 = 3;
            }
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if (((((float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0
                  < (float)param_5) &&
                (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                (float)param_5 <
                (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0))
               && ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   ((float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                   4.0 < (float)param_4 &&
                   (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   (float)param_4 <
                   (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0)
                   ))) {
              DAT_004f05a4 = 4;
            }
            uVar5 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            *(undefined4 *)(param_1 + 0x36c) = uVar5;
            uVar5 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
            *(undefined4 *)(param_1 + 0x370) = uVar5;
            *(undefined4 *)(param_1 + 0x374) = *(undefined4 *)(*piVar6 + 0x10);
            *(undefined4 *)(param_1 + 0x378) = *(undefined4 *)(*piVar6 + 0x14);
            *(int *)(param_1 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
            *(int *)(param_1 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
            goto LAB_00414cd2;
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_004fb6c0;
        for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
          iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
          if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                 (float)param_5) &&
               (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
               (float)param_5 <
               (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8)) &&
              (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
              (float)param_4)) &&
             ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)param_4 <
              (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 &&
              (*(int *)(*piVar6 + 8) == 0x12d)))) {
            DAT_004f059c = *(int *)(*piVar6 + 8);
            DAT_004f05a0 = local_48;
            *(int *)(param_1 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
            *(int *)(param_1 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
            goto LAB_00414cd2;
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_004fb6c0;
        for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
          if ((((double)*(int *)(*piVar6 + 0xc4) * DAT_004e6fb8 + (double)*(int *)(*piVar6 + 0x10) <
                (double)param_5) &&
              ((double)param_5 <
               (double)*(int *)(*piVar6 + 0xcc) +
               (double)*(int *)(*piVar6 + 0xc4) * DAT_004e6fb8 + (double)*(int *)(*piVar6 + 0x10)))
             && (((double)*(int *)(*piVar6 + 200) * DAT_004e6fb8 + (double)*(int *)(*piVar6 + 0x14)
                  < (double)param_4 &&
                 ((((((double)param_4 <
                      (double)*(int *)(*piVar6 + 0xd0) * DAT_004e6fb8 +
                      (double)*(int *)(*piVar6 + 200) * DAT_004e6fb8 +
                      (double)*(int *)(*piVar6 + 0x14) && (*(int *)(*piVar6 + 8) != 0x12d)) &&
                    (*(int *)(*piVar6 + 8) != 0x13c)) && (*(int *)(*piVar6 + 8) != 0x13e)) &&
                  ((*(int *)(*piVar6 + 8) != 0x137 || (*(int *)(*piVar6 + 0xc) != 2)))))))) {
            DAT_004f059c = *(int *)(*piVar6 + 8);
            DAT_004f05a0 = local_48;
            DAT_004f05a4 = 1;
            uVar5 = FUN_004c2d58();
            *(undefined4 *)(param_1 + 0x3a4) = uVar5;
            uVar5 = FUN_004c2d58();
            *(undefined4 *)(param_1 + 0x3a8) = uVar5;
            goto LAB_00414cd2;
          }
          piVar6 = piVar6 + 1;
        }
        iVar4 = 0;
        piVar6 = &DAT_004f05c0;
        do {
          if (*piVar6 == 0) break;
          if (((piVar6[1] < param_5) &&
              ((double)param_5 < (double)piVar6[3] * DAT_004e6fb8 + (double)piVar6[1])) &&
             ((piVar6[2] < param_4 &&
              ((double)param_4 < (double)piVar6[4] * DAT_004e6fb8 + (double)piVar6[2])))) {
            DAT_004f059c = 1000;
            DAT_004f05a0 = iVar4;
            *(int *)(param_1 + 0x3a4) = param_5 - piVar6[1];
            *(int *)(param_1 + 0x3a8) = param_4 - piVar6[2];
            goto LAB_00414cd2;
          }
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 0xd;
        } while (iVar4 < 100);
        iVar4 = 0;
        piVar6 = &DAT_00504dd4;
        do {
          if (*piVar6 == 0) break;
          if ((((piVar6[1] + -0x78 < param_5) && (param_5 < piVar6[1] + 0x78)) &&
              (piVar6[2] + -0x78 < param_4)) && (param_4 < piVar6[2] + 0x78)) {
            DAT_004f059c = 3000;
            DAT_004f05a0 = iVar4;
            *(int *)(param_1 + 0x3a4) = param_5 - piVar6[1];
            *(int *)(param_1 + 0x3a8) = param_4 - piVar6[2];
            goto LAB_00414cd2;
          }
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 0x52;
        } while (iVar4 < 10);
        piVar6 = &DAT_004fb6c0;
        for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
          iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
          if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0 <
                (float)param_5) &&
              (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
              (float)param_5 <
              (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0)) &&
             ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0 <
              (float)param_4 &&
              ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
               (float)param_4 <
               (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0 &&
               (*(int *)(*piVar6 + 8) == 0x13e)))))) {
            DAT_004f059c = *(int *)(*piVar6 + 8);
            DAT_004f05a0 = local_48;
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if ((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0
                 < (float)param_5) &&
               (((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                 (float)param_5 <
                 ((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) + 4.0
                 && (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                    ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                    4.0 < (float)param_4)) &&
                (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                (float)param_4 <
                ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) + 4.0))
               )) {
              DAT_004f05a4 = 1;
            }
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if (((((float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0
                  < (float)param_5) &&
                (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                (float)param_5 <
                (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0))
               && ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                   4.0 < (float)param_4 &&
                   (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   (float)param_4 <
                   ((float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) +
                   4.0)))) {
              DAT_004f05a4 = 2;
            }
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) - 4.0
                  < (float)param_5) &&
                (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                (float)param_5 <
                ((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8) + 4.0))
               && ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   ((float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                   4.0 < (float)param_4 &&
                   (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   (float)param_4 <
                   (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0)
                   ))) {
              DAT_004f05a4 = 3;
            }
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if ((((((float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                   4.0 < (float)param_5) &&
                 (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                 (float)param_5 <
                 (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0))
                && (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                   ((float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8) -
                   4.0 < (float)param_4)) &&
               (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
               (float)param_4 <
               (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 + 4.0)) {
              DAT_004f05a4 = 4;
            }
            uVar5 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            *(undefined4 *)(param_1 + 0x36c) = uVar5;
            uVar5 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
            *(undefined4 *)(param_1 + 0x370) = uVar5;
            *(undefined4 *)(param_1 + 0x374) = *(undefined4 *)(*piVar6 + 0x10);
            *(undefined4 *)(param_1 + 0x378) = *(undefined4 *)(*piVar6 + 0x14);
            *(int *)(param_1 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
            *(int *)(param_1 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
            goto LAB_00414cd2;
          }
          piVar6 = piVar6 + 1;
        }
        DAT_004f059c = -1;
        DAT_004f057c = param_5;
        DAT_004f0580 = param_4;
        DAT_004f0584 = param_5;
        DAT_004f0588 = param_4;
      }
      else {
        DAT_004f059c = 0x3e9;
        DAT_004f05a0 = iVar4;
        *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_0050195c)[iVar4] + 8);
        *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0xc);
      }
    }
    else {
      DAT_004f059c = 0;
      DAT_004f05a0 = 0;
      DAT_004f05a4 = 0;
    }
  }
  else if (((param_3 == '\x01') && (*(int *)(param_1 + 0x3b8) == 1)) && (DAT_004f0590 == 0x3e9)) {
    local_14[2] = *(int *)(&DAT_00501958 + DAT_005028fc * 4);
    if (local_14[2] != 0) {
      FUN_004ca834((int *)(local_14[2] + 0x38),2);
      FUN_004ca834((int *)(local_14[2] + 0x2c),2);
      FUN_004ca834((int *)(local_14[2] + 4),2);
      FUN_004bd61c();
    }
    DAT_005028fc = DAT_005028fc + -1;
    DAT_00502900 = DAT_00502900 + -1;
    *(undefined4 *)(param_1 + 0x3b8) = 0;
    DAT_004f0590 = 0;
  }
LAB_00414cd2:
  puVar7 = (undefined1 *)(param_1 + 0x3d4);
  for (iVar4 = 0; iVar4 < DAT_004fd60c; iVar4 = iVar4 + 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  if (DAT_004f059c == 0x12d) {
    piVar6 = &DAT_004fb6c0;
    local_60 = (int *)(param_1 + 0x3d4);
    for (local_50 = 0; local_50 < DAT_004fd60c; local_50 = local_50 + 1) {
      bVar2 = FUN_004ca904((undefined4 *)(*piVar6 + 0x80),
                           (undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4));
      if (bVar2 != 0) {
        *(undefined1 *)local_60 = 1;
      }
      local_60 = (int *)((int)local_60 + 1);
      piVar6 = piVar6 + 1;
    }
  }
  if (DAT_004f059c == 0x13c) {
    local_60 = &DAT_004fb6c0;
    puVar7 = (undefined1 *)(param_1 + 0x3d4);
    for (local_54 = 0; local_54 < DAT_004fd60c; local_54 = local_54 + 1) {
      bVar2 = FUN_004ca904((undefined4 *)(*local_60 + 0x80),
                           (undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4));
      if (bVar2 != 0) {
        if (*(int *)(*local_60 + 8) == 0x12d) {
          local_6c = (undefined1 *)(param_1 + 0x3d4);
          local_64 = &DAT_004fb6c0;
          for (local_58 = 0; local_58 < DAT_004fd60c; local_58 = local_58 + 1) {
            bVar2 = FUN_004ca904((undefined4 *)(*local_64 + 0x80),(undefined4 *)(*local_60 + 4));
            if (bVar2 != 0) {
              *local_6c = 1;
            }
            local_6c = local_6c + 1;
            local_64 = local_64 + 1;
          }
        }
        *puVar7 = 1;
      }
      puVar7 = puVar7 + 1;
      local_60 = local_60 + 1;
    }
  }
  if ((100 < DAT_004f059c) && (DAT_004f059c < 300)) {
    puVar7 = (undefined1 *)(param_1 + 0x3d4);
    for (local_5c = 0; local_5c < DAT_004fd60c; local_5c = local_5c + 1) {
      if (local_5c == DAT_004f05a0) {
        *puVar7 = 1;
      }
      else {
        *puVar7 = 0;
      }
      puVar7 = puVar7 + 1;
    }
  }
  piVar6 = &DAT_004fb6c0;
  local_60 = (int *)(param_1 + 0x3d4);
  for (iVar4 = 0; iVar4 < DAT_004fd60c; iVar4 = iVar4 + 1) {
    if (((100 < *(int *)(*piVar6 + 8)) && (*(int *)(*piVar6 + 8) < 300)) &&
       ((char)*local_60 == '\x01')) {
      local_74 = &DAT_004fb6c0;
      local_70 = (char *)(param_1 + 0x3d4);
      for (iVar9 = 0; iVar9 < DAT_004fd60c; iVar9 = iVar9 + 1) {
        if ((((iVar9 != iVar4) && (*local_70 != '\x01')) && (100 < *(int *)(*local_74 + 8))) &&
           ((*(int *)(*local_74 + 8) < 300 &&
            (bVar2 = FUN_004ca904((undefined4 *)(*local_74 + 0x80),(undefined4 *)(*piVar6 + 4)),
            bVar2 != 0)))) {
          *local_70 = '\x01';
        }
        local_74 = local_74 + 1;
        local_70 = local_70 + 1;
      }
    }
    local_60 = (int *)((int)local_60 + 1);
    piVar6 = piVar6 + 1;
  }
  local_60 = (int *)(param_1 + 0x7bc);
  for (iVar4 = 0; iVar4 < DAT_005028fc; iVar4 = iVar4 + 1) {
    *(undefined1 *)local_60 = 0;
    local_60 = (int *)((int)local_60 + 1);
  }
  if (DAT_004f059c == 0x3e9) {
    *(undefined1 *)(param_1 + 0x7bc + DAT_004f05a0) = 1;
  }
  piVar6 = &DAT_004fb6c0;
  local_60 = (int *)(param_1 + 0x3d4);
  for (iVar4 = 0; iVar4 < DAT_004fd60c; iVar4 = iVar4 + 1) {
    if ((char)*local_60 == '\x01') {
      local_84 = (undefined1 *)(param_1 + 0x7bc);
      local_7c = &DAT_0050195c;
      for (iVar9 = 0; iVar9 < DAT_005028fc; iVar9 = iVar9 + 1) {
        bVar2 = FUN_004ca904((undefined4 *)(*local_7c + 0x2c),(undefined4 *)(*piVar6 + 4));
        if ((bVar2 != 0) ||
           (bVar2 = FUN_004ca904((undefined4 *)(*local_7c + 0x38),(undefined4 *)(*piVar6 + 4)),
           bVar2 != 0)) {
          *local_84 = 1;
        }
        local_84 = local_84 + 1;
        local_7c = local_7c + 1;
      }
    }
    piVar6 = piVar6 + 1;
    local_60 = (int *)((int)local_60 + 1);
  }
  piVar6 = &DAT_0050195c;
  for (iVar4 = 0; iVar4 < DAT_005028fc; iVar4 = iVar4 + 1) {
    *(undefined4 *)(*piVar6 + 0x4c) = 0;
    piVar6 = piVar6 + 1;
  }
  local_60 = &DAT_0050195c;
  pcVar8 = (char *)(param_1 + 0x7bc);
  for (iVar4 = 0; iVar4 < DAT_005028fc; iVar4 = iVar4 + 1) {
    if (*pcVar8 == '\x01') {
      local_14[1] = 0;
      FUN_004299e8(param_1,iVar4,1,local_14 + 1,*(int *)(*local_60 + 0x2c));
      FUN_004ca834(local_14 + 1,2);
      local_14[0] = 0;
      FUN_004299e8(param_1,iVar4,2,local_14,*(int *)(*local_60 + 0x38));
      FUN_004ca834(local_14,2);
    }
    local_60 = local_60 + 1;
    pcVar8 = pcVar8 + 1;
  }
  if (DAT_004f059c == 0x12d) {
    *(undefined1 *)(param_1 + 0x3d4 + DAT_004f05a0) = 1;
  }
  if (DAT_004f059c == 0x12e) {
    *(undefined1 *)(param_1 + 0x3d4 + DAT_004f05a0) = 1;
  }
  if (DAT_004f059c == 0x12f) {
    *(undefined1 *)(param_1 + 0x3d4 + DAT_004f05a0) = 1;
  }
  if (DAT_004f059c == 0x13c) {
    *(undefined1 *)(param_1 + 0x3d4 + DAT_004f05a0) = 1;
  }
  if (DAT_004f059c == 0x13e) {
    *(undefined1 *)(param_1 + 0x3d4 + DAT_004f05a0) = 1;
  }
  if (DAT_004f059c == 0x137) {
    *(undefined1 *)(param_1 + 0x3d4 + DAT_004f05a0) = 1;
  }
  *(undefined1 *)(param_1 + 0xba4) = 1;
  *(undefined1 *)(param_1 + 0xba5) = 1;
  *(undefined1 *)(param_1 + 0xba8) = 1;
  *(undefined1 *)(param_1 + 0xba9) = 1;
  *(undefined1 *)(param_1 + 0xbaa) = 1;
  FUN_00410fc0(param_1);
  iVar4 = FUN_004841d8(*(int **)(*(int *)(param_1 + 0x350) + 0x128));
  (**(code **)(**(int **)(param_1 + 0xbac) + 8))(*(int **)(param_1 + 0xbac),iVar4);
  *(undefined1 *)(param_1 + 0xba4) = 0;
  *(undefined1 *)(param_1 + 0xba5) = 0;
  *(undefined1 *)(param_1 + 0xba8) = 0;
  *(undefined1 *)(param_1 + 0xba9) = 0;
  *(undefined1 *)(param_1 + 0xbaa) = 0;
  if (DAT_004f059c == 3000) {
    FUN_0042bf74(param_1);
  }
  if (DAT_004f059c == 1000) {
    FUN_0042b1f8(param_1);
  }
  FUN_004085cc(param_1);
  FUN_00406234(param_1);
  FUN_0041004c(param_1,extraout_EDX,extraout_ECX);
  FUN_00406acc(param_1);
  FUN_00407ba8(param_1);
  FUN_00409c30(param_1);
  FUN_00408d5c(param_1);
  FUN_00407d58(param_1);
  FUN_00406530(param_1);
  FUN_004052c8(param_1);
  FUN_0042a364(param_1,extraout_EDX_00,extraout_ECX_00);
  FUN_004ca834(&local_8,2);
  *in_FS_OFFSET = local_38;
  return;
}



// Preserved published name: Image1MouseMove
// Entry 0041714c, recovered name Published_Image1MouseMove_0041714c

void Published_Image1MouseMove_0041714c
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  int extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  int iVar5;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar6;
  int extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  longdouble in_ST0;
  longdouble lVar7;
  longdouble in_ST1;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  longdouble in_ST4;
  longdouble lVar20;
  longdouble in_ST5;
  longdouble in_ST6;
  
  if (*(int *)(param_1 + 0x388) == 0) {
    *(int *)(param_1 + 0x398) = param_5;
    *(int *)(param_1 + 0x39c) = param_4;
    if (DAT_004f059c == -1) {
      DAT_004f0584 = param_5;
      DAT_004f0588 = param_4;
    }
    FUN_0049d688(*(int *)(param_1 + 0x350),0);
    if (DAT_004f0590 == 0) {
      FUN_00415304(param_1,param_5,param_4);
    }
    if ((*(int *)(param_1 + 0x3b8) == 1) && (DAT_004f0590 == 0x3e9)) {
      uVar4 = *(undefined4 *)(param_1 + 0x3b4);
      *(undefined4 *)(param_1 + 0x3b4) = 1;
      *(int *)(*(int *)(&DAT_00501958 + DAT_005028fc * 4) + 0x10) = param_5;
      *(int *)(*(int *)(&DAT_00501958 + DAT_005028fc * 4) + 0x14) = param_4;
      if (*(int *)(*(int *)(&DAT_00501958 + DAT_005028fc * 4) + 0x28) == 3) {
        *(undefined4 *)(*(int *)(&DAT_00501958 + DAT_005028fc * 4) + 0x14) =
             *(undefined4 *)(*(int *)(&DAT_00501958 + DAT_005028fc * 4) + 0xc);
      }
      if (*(int *)(*(int *)(&DAT_00501958 + DAT_005028fc * 4) + 0x28) == 4) {
        *(undefined4 *)(*(int *)(&DAT_00501958 + DAT_005028fc * 4) + 0x10) =
             *(undefined4 *)(*(int *)(&DAT_00501958 + DAT_005028fc * 4) + 8);
      }
      puVar1 = (undefined1 *)(param_1 + 0x3d4);
      for (iVar5 = 0; iVar5 < DAT_004fd60c; iVar5 = iVar5 + 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      }
      *(undefined1 *)(param_1 + 0x7bb + DAT_005028fc) = 1;
      piVar2 = (int *)FUN_004841d8(*(int **)(*(int *)(param_1 + 0x350) + 0x128));
      (**(code **)(*piVar2 + 8))(piVar2,*(undefined4 *)(param_1 + 0xbac));
      *(undefined1 *)(param_1 + 0xba4) = 0;
      *(undefined1 *)(param_1 + 0xba5) = 0;
      FUN_004085cc(param_1);
      FUN_00406234(param_1);
      FUN_0041004c(param_1,extraout_EDX,extraout_ECX);
      FUN_00406acc(param_1);
      FUN_00407ba8(param_1);
      FUN_00409c30(param_1);
      FUN_00408d5c(param_1);
      FUN_00407d58(param_1);
      FUN_00406530(param_1);
      FUN_004052c8(param_1);
      FUN_0042a364(param_1,extraout_EDX_00,extraout_ECX_00);
      *(undefined1 *)(param_1 + 0x7bb + DAT_005028fc) = 0;
      *(undefined4 *)(param_1 + 0x3b4) = uVar4;
    }
    if ((((DAT_004f0590 == 0) && (DAT_004f059c != 0)) && (*(int *)(param_1 + 0x3b4) == 1)) &&
       ((((DAT_004f059c != 0xcc && (DAT_004f059c != 0xcf)) &&
         ((DAT_004f059c != 0xd0 && (DAT_004f059c != 0xd3)))) || (DAT_004f05a4 == 0)))) {
      if ((100 < DAT_004f059c) && (DAT_004f059c < 400)) {
        if ((DAT_004f05a4 == 0) || (DAT_004f059c != 0x12d)) {
          if ((DAT_004f05a4 == 0) || (DAT_004f059c != 0x13c)) {
            if ((DAT_004f05a4 == 0) || (DAT_004f059c != 0x13e)) {
              if (DAT_004f05a4 == 1) {
                lVar7 = (longdouble)(param_5 - *(int *)(param_1 + 0x3a4)) / (longdouble)DAT_004e6fb8
                ;
                lVar13 = in_ST0;
                in_ST5 = in_ST3;
                in_ST6 = in_ST4;
                uVar4 = FUN_004c2d58();
                *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc4) = uVar4;
                in_ST0 = (longdouble)(param_4 - *(int *)(param_1 + 0x3a8)) /
                         (longdouble)DAT_004e6fb8;
                in_ST3 = in_ST1;
                in_ST4 = in_ST2;
                uVar4 = FUN_004c2d58();
                *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 200) = uVar4;
                in_ST1 = lVar7;
                in_ST2 = lVar13;
              }
              else if (DAT_004f05a4 == 0) {
                *(int *)(param_1 + 0x3ac) =
                     (param_5 - *(int *)(param_1 + 0x3a4)) -
                     *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10);
                *(int *)(param_1 + 0x3b0) =
                     (param_4 - *(int *)(param_1 + 0x3a8)) -
                     *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14);
                *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = param_5 - *(int *)(param_1 + 0x3a4)
                ;
                *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = param_4 - *(int *)(param_1 + 0x3a8)
                ;
                FUN_00434804(*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4),
                             *(int *)(param_1 + 0x3ac),*(int *)(param_1 + 0x3b0));
                FUN_00434604(*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4),
                             *(int *)(param_1 + 0x3ac),*(int *)(param_1 + 0x3b0));
              }
            }
            else {
              *(int *)(param_1 + 0x3ac) =
                   (param_5 - *(int *)(param_1 + 0x3a4)) -
                   *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10);
              *(int *)(param_1 + 0x3b0) =
                   (param_4 - *(int *)(param_1 + 0x3a8)) -
                   *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14);
              lVar13 = in_ST0;
              lVar12 = in_ST1;
              lVar7 = in_ST2;
              lVar10 = in_ST3;
              lVar14 = in_ST4;
              lVar17 = in_ST5;
              lVar16 = in_ST6;
              if (DAT_004f05a4 == 1) {
                (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                lVar16 = in_ST6;
                FUN_004c2d30();
                lVar13 = in_ST1;
                lVar12 = in_ST2;
                lVar7 = in_ST3;
                lVar10 = in_ST4;
                lVar14 = in_ST5;
                lVar17 = in_ST6;
                if (in_ST0 != (longdouble)0.0) {
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  lVar13 = in_ST2;
                  lVar7 = in_ST4;
                  lVar9 = lVar16;
                  FUN_004c2d30();
                  lVar12 = in_ST3;
                  lVar10 = in_ST5;
                  lVar14 = in_ST6;
                  lVar17 = lVar16;
                  lVar16 = lVar9;
                  if (in_ST1 != (longdouble)0.0) {
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                    FUN_004c2d30();
                    uVar4 = FUN_004c2d58();
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x40))
                              (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                    FUN_004c2d30();
                    uVar4 = FUN_004c2d58();
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x34))
                              (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                    iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))()
                    ;
                    lVar12 = (longdouble)*(int *)(param_1 + 0x374) +
                             (longdouble)(*(int *)(param_1 + 0x36c) - iVar5) * (longdouble)0.5;
                    lVar14 = lVar7;
                    uVar4 = FUN_004c2d58();
                    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = uVar4;
                    lVar7 = lVar13;
                    iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))()
                    ;
                    lVar13 = (longdouble)*(int *)(param_1 + 0x378) +
                             (longdouble)(*(int *)(param_1 + 0x370) - iVar5) * (longdouble)0.5;
                    uVar4 = FUN_004c2d58();
                    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = uVar4;
                    lVar10 = in_ST3;
                    lVar17 = in_ST5;
                    lVar16 = in_ST6;
                  }
                }
              }
              lVar9 = lVar13;
              lVar8 = lVar12;
              lVar15 = lVar7;
              lVar11 = lVar10;
              lVar18 = lVar14;
              lVar19 = lVar17;
              lVar20 = lVar16;
              if (DAT_004f05a4 == 2) {
                (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                lVar20 = lVar16;
                FUN_004c2d30();
                lVar9 = lVar12;
                lVar8 = lVar7;
                lVar15 = lVar10;
                lVar11 = lVar14;
                lVar18 = lVar17;
                lVar19 = lVar16;
                if (lVar13 != (longdouble)0.0) {
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  lVar9 = lVar7;
                  lVar15 = lVar14;
                  lVar13 = lVar20;
                  FUN_004c2d30();
                  lVar8 = lVar10;
                  lVar11 = lVar17;
                  lVar18 = lVar16;
                  lVar19 = lVar20;
                  lVar20 = lVar13;
                  if (lVar12 != (longdouble)0.0) {
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                    FUN_004c2d30();
                    uVar4 = FUN_004c2d58();
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x40))
                              (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                    FUN_004c2d30();
                    uVar4 = FUN_004c2d58();
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x34))
                              (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                    iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))()
                    ;
                    lVar8 = (longdouble)*(int *)(param_1 + 0x374) -
                            (longdouble)(*(int *)(param_1 + 0x36c) - iVar5) * (longdouble)0.5;
                    lVar18 = lVar15;
                    uVar4 = FUN_004c2d58();
                    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = uVar4;
                    lVar15 = lVar9;
                    iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))()
                    ;
                    lVar9 = (longdouble)*(int *)(param_1 + 0x378) +
                            (longdouble)(*(int *)(param_1 + 0x370) - iVar5) * (longdouble)0.5;
                    uVar4 = FUN_004c2d58();
                    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = uVar4;
                    lVar11 = lVar10;
                    lVar19 = lVar17;
                    lVar20 = lVar16;
                  }
                }
              }
              lVar13 = lVar9;
              lVar12 = lVar8;
              lVar7 = lVar15;
              lVar10 = lVar11;
              lVar14 = lVar18;
              lVar17 = lVar19;
              lVar16 = lVar20;
              if (DAT_004f05a4 == 3) {
                (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                lVar16 = lVar20;
                FUN_004c2d30();
                lVar13 = lVar8;
                lVar12 = lVar15;
                lVar7 = lVar11;
                lVar10 = lVar18;
                lVar14 = lVar19;
                lVar17 = lVar20;
                if (lVar9 != (longdouble)0.0) {
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  lVar13 = lVar15;
                  lVar7 = lVar18;
                  lVar9 = lVar16;
                  FUN_004c2d30();
                  lVar12 = lVar11;
                  lVar10 = lVar19;
                  lVar14 = lVar20;
                  lVar17 = lVar16;
                  lVar16 = lVar9;
                  if (lVar8 != (longdouble)0.0) {
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                    FUN_004c2d30();
                    uVar4 = FUN_004c2d58();
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x40))
                              (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                    FUN_004c2d30();
                    uVar4 = FUN_004c2d58();
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x34))
                              (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                    iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))()
                    ;
                    lVar12 = (longdouble)*(int *)(param_1 + 0x374) +
                             (longdouble)(*(int *)(param_1 + 0x36c) - iVar5) * (longdouble)0.5;
                    lVar14 = lVar7;
                    uVar4 = FUN_004c2d58();
                    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = uVar4;
                    lVar7 = lVar13;
                    iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))()
                    ;
                    lVar13 = (longdouble)*(int *)(param_1 + 0x378) -
                             (longdouble)(*(int *)(param_1 + 0x370) - iVar5) * (longdouble)0.5;
                    uVar4 = FUN_004c2d58();
                    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = uVar4;
                    lVar10 = lVar11;
                    lVar17 = lVar19;
                    lVar16 = lVar20;
                  }
                }
              }
              in_ST0 = lVar13;
              in_ST1 = lVar12;
              in_ST2 = lVar7;
              in_ST3 = lVar10;
              in_ST4 = lVar14;
              in_ST5 = lVar17;
              in_ST6 = lVar16;
              if (DAT_004f05a4 == 4) {
                (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                in_ST6 = lVar16;
                FUN_004c2d30();
                in_ST0 = lVar12;
                in_ST1 = lVar7;
                in_ST2 = lVar10;
                in_ST3 = lVar14;
                in_ST4 = lVar17;
                in_ST5 = lVar16;
                if (lVar13 != (longdouble)0.0) {
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  in_ST0 = lVar7;
                  in_ST2 = lVar14;
                  lVar13 = in_ST6;
                  FUN_004c2d30();
                  in_ST1 = lVar10;
                  in_ST3 = lVar17;
                  in_ST4 = lVar16;
                  in_ST5 = in_ST6;
                  in_ST6 = lVar13;
                  if (lVar12 != (longdouble)0.0) {
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                    FUN_004c2d30();
                    uVar4 = FUN_004c2d58();
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x40))
                              (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                    FUN_004c2d30();
                    uVar4 = FUN_004c2d58();
                    (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x34))
                              (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                    iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))()
                    ;
                    in_ST1 = (longdouble)*(int *)(param_1 + 0x374) -
                             (longdouble)(*(int *)(param_1 + 0x36c) - iVar5) * (longdouble)0.5;
                    in_ST4 = in_ST2;
                    uVar4 = FUN_004c2d58();
                    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = uVar4;
                    in_ST2 = in_ST0;
                    iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))()
                    ;
                    in_ST0 = (longdouble)*(int *)(param_1 + 0x378) -
                             (longdouble)(*(int *)(param_1 + 0x370) - iVar5) * (longdouble)0.5;
                    uVar4 = FUN_004c2d58();
                    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = uVar4;
                    in_ST3 = lVar10;
                    in_ST5 = lVar17;
                    in_ST6 = lVar16;
                  }
                }
              }
              *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10);
              *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14);
              FUN_00434804(*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4),
                           *(int *)(param_1 + 0x3ac),*(int *)(param_1 + 0x3b0));
              FUN_00434604(*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4),
                           *(int *)(param_1 + 0x3ac),*(int *)(param_1 + 0x3b0));
            }
          }
          else {
            *(int *)(param_1 + 0x3ac) =
                 (param_5 - *(int *)(param_1 + 0x3a4)) -
                 *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10);
            *(int *)(param_1 + 0x3b0) =
                 (param_4 - *(int *)(param_1 + 0x3a8)) -
                 *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14);
            lVar13 = in_ST0;
            lVar12 = in_ST1;
            lVar7 = in_ST2;
            lVar10 = in_ST3;
            lVar14 = in_ST4;
            lVar17 = in_ST5;
            lVar16 = in_ST6;
            if (DAT_004f05a4 == 1) {
              (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              lVar16 = in_ST6;
              FUN_004c2d30();
              lVar13 = in_ST1;
              lVar12 = in_ST2;
              lVar7 = in_ST3;
              lVar10 = in_ST4;
              lVar14 = in_ST5;
              lVar17 = in_ST6;
              if (in_ST0 != (longdouble)0.0) {
                (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                lVar13 = in_ST2;
                lVar7 = in_ST4;
                lVar9 = lVar16;
                FUN_004c2d30();
                lVar12 = in_ST3;
                lVar10 = in_ST5;
                lVar14 = in_ST6;
                lVar17 = lVar16;
                lVar16 = lVar9;
                if (in_ST1 != (longdouble)0.0) {
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                  FUN_004c2d30();
                  uVar4 = FUN_004c2d58();
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x40))
                            (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  FUN_004c2d30();
                  uVar4 = FUN_004c2d58();
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x34))
                            (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                  iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                  lVar12 = (longdouble)*(int *)(param_1 + 0x374) +
                           (longdouble)(*(int *)(param_1 + 0x36c) - iVar5) * (longdouble)0.5;
                  lVar14 = lVar7;
                  uVar4 = FUN_004c2d58();
                  *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = uVar4;
                  lVar7 = lVar13;
                  iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  lVar13 = (longdouble)*(int *)(param_1 + 0x378) +
                           (longdouble)(*(int *)(param_1 + 0x370) - iVar5) * (longdouble)0.5;
                  uVar4 = FUN_004c2d58();
                  *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = uVar4;
                  lVar10 = in_ST3;
                  lVar17 = in_ST5;
                  lVar16 = in_ST6;
                }
              }
            }
            lVar9 = lVar13;
            lVar8 = lVar12;
            lVar15 = lVar7;
            lVar11 = lVar10;
            lVar18 = lVar14;
            lVar19 = lVar17;
            lVar20 = lVar16;
            if (DAT_004f05a4 == 2) {
              (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              lVar20 = lVar16;
              FUN_004c2d30();
              lVar9 = lVar12;
              lVar8 = lVar7;
              lVar15 = lVar10;
              lVar11 = lVar14;
              lVar18 = lVar17;
              lVar19 = lVar16;
              if (lVar13 != (longdouble)0.0) {
                (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                lVar9 = lVar7;
                lVar15 = lVar14;
                lVar13 = lVar20;
                FUN_004c2d30();
                lVar8 = lVar10;
                lVar11 = lVar17;
                lVar18 = lVar16;
                lVar19 = lVar20;
                lVar20 = lVar13;
                if (lVar12 != (longdouble)0.0) {
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                  FUN_004c2d30();
                  uVar4 = FUN_004c2d58();
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x40))
                            (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  FUN_004c2d30();
                  uVar4 = FUN_004c2d58();
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x34))
                            (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                  iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                  lVar8 = (longdouble)*(int *)(param_1 + 0x374) -
                          (longdouble)(*(int *)(param_1 + 0x36c) - iVar5) * (longdouble)0.5;
                  lVar18 = lVar15;
                  uVar4 = FUN_004c2d58();
                  *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = uVar4;
                  lVar15 = lVar9;
                  iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  lVar9 = (longdouble)*(int *)(param_1 + 0x378) +
                          (longdouble)(*(int *)(param_1 + 0x370) - iVar5) * (longdouble)0.5;
                  uVar4 = FUN_004c2d58();
                  *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = uVar4;
                  lVar11 = lVar10;
                  lVar19 = lVar17;
                  lVar20 = lVar16;
                }
              }
            }
            lVar13 = lVar9;
            lVar12 = lVar8;
            lVar7 = lVar15;
            lVar10 = lVar11;
            lVar14 = lVar18;
            lVar17 = lVar19;
            lVar16 = lVar20;
            if (DAT_004f05a4 == 3) {
              (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              lVar16 = lVar20;
              FUN_004c2d30();
              lVar13 = lVar8;
              lVar12 = lVar15;
              lVar7 = lVar11;
              lVar10 = lVar18;
              lVar14 = lVar19;
              lVar17 = lVar20;
              if (lVar9 != (longdouble)0.0) {
                (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                lVar13 = lVar15;
                lVar7 = lVar18;
                lVar9 = lVar16;
                FUN_004c2d30();
                lVar12 = lVar11;
                lVar10 = lVar19;
                lVar14 = lVar20;
                lVar17 = lVar16;
                lVar16 = lVar9;
                if (lVar8 != (longdouble)0.0) {
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                  FUN_004c2d30();
                  uVar4 = FUN_004c2d58();
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x40))
                            (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  FUN_004c2d30();
                  uVar4 = FUN_004c2d58();
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x34))
                            (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                  iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                  lVar12 = (longdouble)*(int *)(param_1 + 0x374) +
                           (longdouble)(*(int *)(param_1 + 0x36c) - iVar5) * (longdouble)0.5;
                  lVar14 = lVar7;
                  uVar4 = FUN_004c2d58();
                  *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = uVar4;
                  lVar7 = lVar13;
                  iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  lVar13 = (longdouble)*(int *)(param_1 + 0x378) -
                           (longdouble)(*(int *)(param_1 + 0x370) - iVar5) * (longdouble)0.5;
                  uVar4 = FUN_004c2d58();
                  *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = uVar4;
                  lVar10 = lVar11;
                  lVar17 = lVar19;
                  lVar16 = lVar20;
                }
              }
            }
            in_ST0 = lVar13;
            in_ST1 = lVar12;
            in_ST2 = lVar7;
            in_ST3 = lVar10;
            in_ST4 = lVar14;
            in_ST5 = lVar17;
            in_ST6 = lVar16;
            if (DAT_004f05a4 == 4) {
              (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              in_ST6 = lVar16;
              FUN_004c2d30();
              in_ST0 = lVar12;
              in_ST1 = lVar7;
              in_ST2 = lVar10;
              in_ST3 = lVar14;
              in_ST4 = lVar17;
              in_ST5 = lVar16;
              if (lVar13 != (longdouble)0.0) {
                (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                in_ST0 = lVar7;
                in_ST2 = lVar14;
                lVar13 = in_ST6;
                FUN_004c2d30();
                in_ST1 = lVar10;
                in_ST3 = lVar17;
                in_ST4 = lVar16;
                in_ST5 = in_ST6;
                in_ST6 = lVar13;
                if (lVar12 != (longdouble)0.0) {
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                  FUN_004c2d30();
                  uVar4 = FUN_004c2d58();
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x40))
                            (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  FUN_004c2d30();
                  uVar4 = FUN_004c2d58();
                  (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x34))
                            (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),uVar4);
                  iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
                  in_ST1 = (longdouble)*(int *)(param_1 + 0x374) -
                           (longdouble)(*(int *)(param_1 + 0x36c) - iVar5) * (longdouble)0.5;
                  in_ST4 = in_ST2;
                  uVar4 = FUN_004c2d58();
                  *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) = uVar4;
                  in_ST2 = in_ST0;
                  iVar5 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                  in_ST0 = (longdouble)*(int *)(param_1 + 0x378) -
                           (longdouble)(*(int *)(param_1 + 0x370) - iVar5) * (longdouble)0.5;
                  uVar4 = FUN_004c2d58();
                  *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) = uVar4;
                  in_ST3 = lVar10;
                  in_ST5 = lVar17;
                  in_ST6 = lVar16;
                }
              }
            }
            *(int *)(param_1 + 0x3a4) = param_5 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10);
            *(int *)(param_1 + 0x3a8) = param_4 - *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14);
            FUN_00434804(*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4),
                         *(int *)(param_1 + 0x3ac),*(int *)(param_1 + 0x3b0));
            FUN_00434604(*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4),
                         *(int *)(param_1 + 0x3ac),*(int *)(param_1 + 0x3b0));
          }
        }
        else if (DAT_004f05a4 == 1) {
          iVar5 = *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x74);
          iVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          lVar7 = (((longdouble)*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) +
                   ((longdouble)iVar3 * (longdouble)0.5 * (longdouble)DAT_004e6fb8 -
                   (longdouble)param_4)) - (longdouble)*(int *)(param_1 + 0x3a8)) /
                  (longdouble)DAT_004e6fb8;
          lVar13 = in_ST0;
          uVar4 = FUN_004c2d58();
          *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x74) = uVar4;
          if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x74) < 0x1e) {
            *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x74) = 0x1e;
          }
          if (200 < *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x74)) {
            *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x74) = 200;
          }
          *(undefined4 *)(param_1 + 0x3ac) = 0;
          in_ST0 = (longdouble)-(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x74) - iVar5) *
                   (longdouble)DAT_004e6fb8;
          in_ST5 = in_ST3;
          in_ST6 = in_ST4;
          uVar4 = FUN_004c2d58();
          *(undefined4 *)(param_1 + 0x3b0) = uVar4;
          in_ST3 = in_ST1;
          in_ST4 = in_ST2;
          FUN_00434804(*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4),*(int *)(param_1 + 0x3ac),
                       *(int *)(param_1 + 0x3b0));
          in_ST1 = lVar7;
          in_ST2 = lVar13;
        }
        else if (DAT_004f05a4 == 2) {
          iVar5 = *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x7c);
          iVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
          lVar7 = (((longdouble)*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) +
                   ((longdouble)iVar3 * (longdouble)0.5 * (longdouble)DAT_004e6fb8 -
                   (longdouble)param_4)) - (longdouble)*(int *)(param_1 + 0x3a8)) /
                  (longdouble)DAT_004e6fb8;
          lVar13 = in_ST0;
          uVar4 = FUN_004c2d58();
          *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x7c) = uVar4;
          if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x7c) < 0x1e) {
            *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x7c) = 0x1e;
          }
          if (200 < *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x7c)) {
            *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x7c) = 200;
          }
          *(undefined4 *)(param_1 + 0x3ac) = 0;
          in_ST0 = (longdouble)-(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x7c) - iVar5) *
                   (longdouble)DAT_004e6fb8;
          in_ST5 = in_ST3;
          in_ST6 = in_ST4;
          uVar4 = FUN_004c2d58();
          *(undefined4 *)(param_1 + 0x3b0) = uVar4;
          in_ST3 = in_ST1;
          in_ST4 = in_ST2;
          FUN_00434804(*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 4),*(int *)(param_1 + 0x3ac),
                       *(int *)(param_1 + 0x3b0));
          in_ST1 = lVar7;
          in_ST2 = lVar13;
        }
      }
      if (DAT_004f059c == 0x3e9) {
        if (DAT_004f05a4 == 0) {
          *(int *)(param_1 + 0x3ac) =
               (param_5 - *(int *)(param_1 + 0x3a4)) - *(int *)((&DAT_0050195c)[DAT_004f05a0] + 8);
          *(int *)(param_1 + 0x3b0) =
               (param_4 - *(int *)(param_1 + 0x3a8)) - *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0xc)
          ;
          *(int *)((&DAT_0050195c)[DAT_004f05a0] + 8) = param_5 - *(int *)(param_1 + 0x3a4);
          *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0xc) = param_4 - *(int *)(param_1 + 0x3a8);
          *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x10) =
               *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x10) + *(int *)(param_1 + 0x3ac);
          *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x14) =
               *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x14) + *(int *)(param_1 + 0x3b0);
        }
        if (DAT_004f05a4 == 1) {
          *(int *)(param_1 + 0x3ac) =
               (param_5 - *(int *)(param_1 + 0x3a4)) - *(int *)((&DAT_0050195c)[DAT_004f05a0] + 8);
          *(int *)(param_1 + 0x3b0) =
               (param_4 - *(int *)(param_1 + 0x3a8)) - *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0xc)
          ;
          if (*(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x28) == 3) {
            *(int *)((&DAT_0050195c)[DAT_004f05a0] + 8) = param_5 - *(int *)(param_1 + 0x3a4);
            *(undefined4 *)(param_1 + 0x3b0) = 0;
          }
          else if (*(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x28) == 4) {
            *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0xc) = param_4 - *(int *)(param_1 + 0x3a8);
            *(undefined4 *)(param_1 + 0x3ac) = 0;
          }
          else {
            *(int *)((&DAT_0050195c)[DAT_004f05a0] + 8) = param_5 - *(int *)(param_1 + 0x3a4);
            *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0xc) = param_4 - *(int *)(param_1 + 0x3a8);
          }
        }
        if (DAT_004f05a4 == 2) {
          *(int *)(param_1 + 0x3ac) =
               (param_5 - *(int *)(param_1 + 0x3a4)) -
               *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x10);
          *(int *)(param_1 + 0x3b0) =
               (param_4 - *(int *)(param_1 + 0x3a8)) -
               *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x14);
          if (*(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x28) == 3) {
            *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x10) = param_5 - *(int *)(param_1 + 0x3a4);
            *(undefined4 *)(param_1 + 0x3ac) = 0;
          }
          else if (*(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x28) == 4) {
            *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x14) = param_4 - *(int *)(param_1 + 0x3a8);
            *(undefined4 *)(param_1 + 0x3b0) = 0;
          }
          else {
            *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x10) = param_5 - *(int *)(param_1 + 0x3a4);
            *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0x14) = param_4 - *(int *)(param_1 + 0x3a8);
          }
        }
        iVar5 = (&DAT_0050195c)[DAT_004f05a0];
        if (*(int *)(iVar5 + 0x28) == 3) {
          *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar5 + 0xc);
        }
        iVar5 = (&DAT_0050195c)[DAT_004f05a0];
        if (*(int *)(iVar5 + 0x28) == 4) {
          *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar5 + 8);
        }
        piVar2 = &DAT_0050195c;
        for (iVar5 = 0; iVar5 < DAT_005028fc; iVar5 = iVar5 + 1) {
          iVar3 = *piVar2;
          *(undefined4 *)(iVar3 + 0x34) = 0;
          *(undefined4 *)(iVar3 + 0x40) = 0;
          piVar2 = piVar2 + 1;
        }
        FUN_004342f8(*(int *)((&DAT_0050195c)[DAT_004f05a0] + 4));
      }
      if (DAT_004f059c == 2000) {
        if (DAT_004f05a4 == 0) {
          *(int *)(param_1 + 0x3ac) =
               (param_5 - *(int *)(param_1 + 0x3a4)) - (&DAT_00502908)[DAT_004f05a0 * 0x17];
          *(int *)(param_1 + 0x3b0) =
               (param_4 - *(int *)(param_1 + 0x3a8)) - (&DAT_0050290c)[DAT_004f05a0 * 0x17];
          (&DAT_00502908)[DAT_004f05a0 * 0x17] = param_5 - *(int *)(param_1 + 0x3a4);
          (&DAT_0050290c)[DAT_004f05a0 * 0x17] = param_4 - *(int *)(param_1 + 0x3a8);
        }
        else {
          *(int *)(param_1 + 0x3ac) =
               (param_5 - *(int *)(param_1 + 0x3a4)) - (&DAT_00502908)[DAT_004f05a0 * 0x17];
          *(int *)(param_1 + 0x3b0) =
               (param_4 - *(int *)(param_1 + 0x3a8)) - (&DAT_0050290c)[DAT_004f05a0 * 0x17];
          lVar13 = in_ST0;
          lVar12 = in_ST1;
          lVar7 = in_ST2;
          lVar14 = in_ST3;
          lVar10 = in_ST4;
          lVar17 = in_ST5;
          if (DAT_004f05a4 == 1) {
            lVar16 = in_ST6;
            FUN_004c2d30();
            lVar13 = in_ST1;
            lVar12 = in_ST2;
            lVar7 = in_ST3;
            lVar14 = in_ST4;
            lVar10 = in_ST5;
            lVar17 = in_ST6;
            if (in_ST0 != (longdouble)0.0) {
              lVar13 = in_ST2;
              FUN_004c2d30();
              lVar12 = in_ST3;
              lVar7 = in_ST4;
              lVar14 = in_ST5;
              lVar10 = in_ST6;
              lVar17 = lVar16;
              if (in_ST1 != (longdouble)0.0) {
                FUN_004c2d30();
                uVar4 = FUN_004c2d58();
                (&DAT_00502938)[DAT_004f05a0 * 0x17] = uVar4;
                FUN_004c2d30();
                uVar4 = FUN_004c2d58();
                iVar5 = DAT_004f05a0;
                (&DAT_0050293c)[DAT_004f05a0 * 0x17] = uVar4;
                lVar12 = (longdouble)(*(int *)(param_1 + 0x36c) - (&DAT_00502938)[iVar5 * 0x17]) *
                         (longdouble)0.5 + (longdouble)*(int *)(param_1 + 0x374);
                lVar7 = lVar13;
                uVar4 = FUN_004c2d58();
                (&DAT_00502908)[iVar5 * 0x17] = uVar4;
                lVar13 = (longdouble)(*(int *)(param_1 + 0x370) - (&DAT_0050293c)[iVar5 * 0x17]) *
                         (longdouble)0.5 + (longdouble)*(int *)(param_1 + 0x378);
                uVar4 = FUN_004c2d58();
                (&DAT_0050290c)[iVar5 * 0x17] = uVar4;
                lVar14 = in_ST3;
                lVar10 = in_ST4;
                lVar17 = in_ST5;
              }
            }
          }
          lVar16 = lVar13;
          lVar15 = lVar12;
          lVar9 = lVar7;
          lVar8 = lVar14;
          if (DAT_004f05a4 == 2) {
            FUN_004c2d30();
            lVar16 = lVar12;
            lVar15 = lVar7;
            lVar9 = lVar14;
            lVar8 = lVar10;
            if (lVar13 != (longdouble)0.0) {
              lVar16 = lVar7;
              lVar9 = lVar10;
              FUN_004c2d30();
              lVar15 = lVar14;
              lVar8 = lVar17;
              if (lVar12 != (longdouble)0.0) {
                FUN_004c2d30();
                uVar4 = FUN_004c2d58();
                (&DAT_00502938)[DAT_004f05a0 * 0x17] = uVar4;
                FUN_004c2d30();
                uVar4 = FUN_004c2d58();
                iVar5 = DAT_004f05a0;
                (&DAT_0050293c)[DAT_004f05a0 * 0x17] = uVar4;
                lVar15 = (longdouble)*(int *)(param_1 + 0x374) -
                         (longdouble)(*(int *)(param_1 + 0x36c) - (&DAT_00502938)[iVar5 * 0x17]) *
                         (longdouble)0.5;
                lVar9 = lVar16;
                uVar4 = FUN_004c2d58();
                (&DAT_00502908)[iVar5 * 0x17] = uVar4;
                lVar16 = (longdouble)(*(int *)(param_1 + 0x370) - (&DAT_0050293c)[iVar5 * 0x17]) *
                         (longdouble)0.5 + (longdouble)*(int *)(param_1 + 0x378);
                uVar4 = FUN_004c2d58();
                (&DAT_0050290c)[iVar5 * 0x17] = uVar4;
                lVar8 = lVar14;
              }
            }
          }
          lVar13 = lVar16;
          lVar7 = lVar15;
          if (DAT_004f05a4 == 3) {
            lVar7 = lVar9;
            FUN_004c2d30();
            lVar13 = lVar15;
            if (lVar16 != (longdouble)0.0) {
              lVar13 = lVar7;
              lVar7 = lVar8;
              FUN_004c2d30();
              if (lVar15 != (longdouble)0.0) {
                FUN_004c2d30();
                uVar4 = FUN_004c2d58();
                (&DAT_00502938)[DAT_004f05a0 * 0x17] = uVar4;
                FUN_004c2d30();
                uVar4 = FUN_004c2d58();
                iVar5 = DAT_004f05a0;
                (&DAT_0050293c)[DAT_004f05a0 * 0x17] = uVar4;
                lVar7 = (longdouble)(*(int *)(param_1 + 0x36c) - (&DAT_00502938)[iVar5 * 0x17]) *
                        (longdouble)0.5 + (longdouble)*(int *)(param_1 + 0x374);
                uVar4 = FUN_004c2d58();
                (&DAT_00502908)[iVar5 * 0x17] = uVar4;
                lVar13 = (longdouble)*(int *)(param_1 + 0x378) -
                         (longdouble)(*(int *)(param_1 + 0x370) - (&DAT_0050293c)[iVar5 * 0x17]) *
                         (longdouble)0.5;
                uVar4 = FUN_004c2d58();
                (&DAT_0050290c)[iVar5 * 0x17] = uVar4;
              }
            }
          }
          if (DAT_004f05a4 == 4) {
            FUN_004c2d30();
            if (lVar13 != (longdouble)0.0) {
              FUN_004c2d30();
              if (lVar7 != (longdouble)0.0) {
                FUN_004c2d30();
                uVar4 = FUN_004c2d58();
                (&DAT_00502938)[DAT_004f05a0 * 0x17] = uVar4;
                FUN_004c2d30();
                uVar4 = FUN_004c2d58();
                iVar5 = DAT_004f05a0;
                (&DAT_0050293c)[DAT_004f05a0 * 0x17] = uVar4;
                uVar4 = FUN_004c2d58();
                (&DAT_00502908)[iVar5 * 0x17] = uVar4;
                uVar4 = FUN_004c2d58();
                (&DAT_0050290c)[iVar5 * 0x17] = uVar4;
              }
            }
          }
          *(int *)(param_1 + 0x3a4) = param_5 - (&DAT_00502908)[DAT_004f05a0 * 0x17];
          *(int *)(param_1 + 0x3a8) = param_4 - (&DAT_0050290c)[DAT_004f05a0 * 0x17];
        }
      }
      if (DAT_004f059c == 1000) {
        *(int *)(param_1 + 0x3ac) =
             (param_5 - *(int *)(param_1 + 0x3a4)) - (&DAT_004f05c4)[DAT_004f05a0 * 0xd];
        *(int *)(param_1 + 0x3b0) =
             (param_4 - *(int *)(param_1 + 0x3a8)) - (&DAT_004f05c8)[DAT_004f05a0 * 0xd];
        (&DAT_004f05c4)[DAT_004f05a0 * 0xd] = param_5 - *(int *)(param_1 + 0x3a4);
        (&DAT_004f05c8)[DAT_004f05a0 * 0xd] = param_4 - *(int *)(param_1 + 0x3a8);
      }
      if (DAT_004f059c == 3000) {
        *(int *)(param_1 + 0x3ac) =
             (param_5 - *(int *)(param_1 + 0x3a4)) - (&DAT_00504dd8)[DAT_004f05a0 * 0x52];
        *(int *)(param_1 + 0x3b0) =
             (param_4 - *(int *)(param_1 + 0x3a8)) - (&DAT_00504ddc)[DAT_004f05a0 * 0x52];
        (&DAT_00504dd8)[DAT_004f05a0 * 0x52] = param_5 - *(int *)(param_1 + 0x3a4);
        (&DAT_00504ddc)[DAT_004f05a0 * 0x52] = param_4 - *(int *)(param_1 + 0x3a8);
      }
      piVar2 = (int *)FUN_004841d8(*(int **)(*(int *)(param_1 + 0x350) + 0x128));
      (**(code **)(*piVar2 + 8))(piVar2,*(undefined4 *)(param_1 + 0xbac));
      *(undefined1 *)(param_1 + 0xba4) = 0;
      *(undefined1 *)(param_1 + 0xba5) = 0;
      *(undefined1 *)(param_1 + 0xba8) = 0;
      *(undefined1 *)(param_1 + 0xba9) = 0;
      *(undefined1 *)(param_1 + 0xbaa) = 0;
      uVar4 = extraout_ECX_01;
      uVar6 = extraout_EDX_01;
      if (DAT_004f059c == 3000) {
        FUN_0042bf74(param_1);
        uVar4 = extraout_ECX_02;
        uVar6 = extraout_EDX_02;
      }
      if (DAT_004f059c == 2000) {
        FUN_0042a364(param_1,uVar6,uVar4);
      }
      if (DAT_004f059c == 1000) {
        FUN_0042b1f8(param_1);
      }
      FUN_004085cc(param_1);
      FUN_00406234(param_1);
      FUN_0041004c(param_1,extraout_EDX_03,extraout_ECX_03);
      FUN_00406acc(param_1);
      FUN_00407ba8(param_1);
      FUN_00409c30(param_1);
      FUN_00408d5c(param_1);
      FUN_00407d58(param_1);
      FUN_00406530(param_1);
      FUN_004052c8(param_1);
      FUN_0042a364(param_1,extraout_EDX_04,extraout_ECX_04);
      if (DAT_004f059c == -1) {
        iVar5 = FUN_00496b94(*(int *)(param_1 + 0x350),extraout_EDX_05,extraout_ECX_05);
        FUN_0048166c(*(int **)(iVar5 + 0x10),0x800000);
        iVar5 = FUN_00496b94(*(int *)(param_1 + 0x350),extraout_EDX_06,extraout_ECX_06);
        FUN_00481748(*(int **)(iVar5 + 0x10),2);
        iVar5 = FUN_00496b94(*(int *)(param_1 + 0x350),extraout_EDX_07,extraout_ECX_07);
        FUN_00481a6c(*(int **)(iVar5 + 0x14),'\x01');
        iVar5 = DAT_004f0588;
        iVar3 = DAT_004f0584;
        piVar2 = (int *)FUN_00496b94(*(int *)(param_1 + 0x350),extraout_EDX_08,DAT_004f0584);
        FUN_00481ecc(piVar2,DAT_004f057c,DAT_004f0580,iVar5,iVar3);
        iVar5 = FUN_00496b94(*(int *)(param_1 + 0x350),extraout_EDX_09,extraout_ECX_08);
        FUN_00481748(*(int **)(iVar5 + 0x10),0);
      }
    }
  }
  return;
}



// Preserved published name: Image1MouseUp
// Entry 004191e0, recovered name Published_Image1MouseUp_004191e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_Image1MouseUp_004191e0
               (int param_1,undefined4 param_2,char param_3,int param_4,int param_5)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST0;
  longdouble lVar7;
  longdouble lVar8;
  longdouble in_ST1;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  undefined1 auStack_104 [4];
  undefined4 uStack_100;
  undefined4 auStack_fc [2];
  undefined1 auStack_f4 [4];
  undefined4 uStack_f0;
  undefined4 auStack_ec [2];
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
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 auStack_4c [2];
  int iStack_44;
  int iStack_3c;
  char cStack_35;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined2 uStack_1c;
  int iStack_10;
  int iStack_8;
  
  cStack_35 = param_3;
  uStack_34 = param_2;
  iStack_30 = param_1;
  FUN_004be6dc(0x4e1408);
  if (*(int *)(iStack_30 + 0x388) == 0) {
    *(undefined4 *)(iStack_30 + 0x3b4) = 0;
    *(int *)(iStack_30 + 0x398) = param_5;
    *(int *)(iStack_30 + 0x39c) = param_4;
    if (DAT_004f0570 != 1) {
      FUN_0049d5dc(*(int *)(iStack_30 + 0x350),'\x01');
    }
    if (DAT_004f059c == -1) {
      DAT_004f059c = 0;
    }
    if ((DAT_004f0584 == DAT_004f057c) || (DAT_004f0588 == DAT_004f0580)) {
      DAT_004f057c = 0;
      DAT_004f0584 = 0;
      DAT_004f0580 = 0;
      DAT_004f0588 = 0;
    }
    if (DAT_004f0570 == 1) {
      _DAT_004f05bc = FUN_004c69dc();
    }
    if (cStack_35 == '\0') {
      if (DAT_004f0570 == 1) {
        if (DAT_004f059c == 0xcc) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4 < param_4) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
                uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x14) {
                  DAT_004f05a4 = 1;
                  func_0x004516ac();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if ((*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x17 < param_4) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
                uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x2b) {
                  DAT_004f05a4 = 2;
                  func_0x004516ac();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
        }
        if ((DAT_004f059c == 0xcf) || (DAT_004f059c == 0xd0)) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x46 < param_4) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
                uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if (param_4 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x32) {
                  DAT_004f05a4 = 1;
                  func_0x004516ac();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x2f < param_4) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
                uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if (param_4 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x1b) {
                  DAT_004f05a4 = 2;
                  func_0x004516ac();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -0x18 < param_4) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
                uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if (param_4 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) + -4) {
                  DAT_004f05a4 = 3;
                  func_0x004516ac();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
        }
        if (DAT_004f059c == 0xd3) {
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4 < param_4) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
                uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x14) {
                  DAT_004f05a4 = 1;
                  func_0x004516ac();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if ((*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x17 < param_4) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
                uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x2b) {
                  DAT_004f05a4 = 2;
                  func_0x004516ac();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
          uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
          iVar4 = (int)uVar3 >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
          }
          if (iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 10 < param_5) {
            uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
            iVar4 = (int)uVar3 >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
            }
            if ((*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x2e < param_4) {
              uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x2c))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              if (param_5 < iVar4 + *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x10) + 0x2d) {
                uVar3 = (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 0x20))();
                iVar4 = (int)uVar3 >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
                }
                if (param_4 < (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x14) - iVar4) + 0x42) {
                  DAT_004f05a4 = 3;
                  func_0x004516ac();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
        }
        piVar6 = &DAT_00502904;
        iStack_3c = 0;
        do {
          if (*piVar6 == 0) break;
          iVar4 = piVar6[0xd] >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
          }
          if (piVar6[1] - iVar4 < param_5) {
            iVar4 = piVar6[0xd] >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
            }
            if (param_5 < iVar4 + piVar6[1]) {
              iVar4 = piVar6[0xe] >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
              }
              if (piVar6[2] - iVar4 < param_4) {
                iVar4 = piVar6[0xe] >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                }
                if (param_4 < iVar4 + piVar6[2]) {
                  uVar5 = FUN_0046337c();
                  iVar4 = FUN_00401b04(uVar5,iStack_3c + 1,iStack_30,(int *)iStack_30,iStack_3c + 1)
                  ;
                  if (iVar4 == 0) {
                    if (*(int *)(iStack_30 + 0x3bda8) == 100) {
                      uStack_1c = 8;
                      piVar6 = FUN_004ca710(&iStack_8);
                      iStack_10 = iStack_10 + 1;
                      FUN_00498434(*piVar6);
                      iStack_10 = iStack_10 + -1;
                      FUN_004ca834(&iStack_8,2);
                      Published_SpeedButton20Click_00428de8(iStack_30);
                    }
                    else {
                      Published_SpeedButton20Click_00428de8(iStack_30);
                    }
                  }
                  FUN_00463680();
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
          iStack_3c = iStack_3c + 1;
          piVar6 = piVar6 + 0x17;
        } while (iStack_3c < 100);
      }
      FUN_00434a60();
      FUN_00438094();
      if (DAT_004f0570 != 1) {
        FUN_00410fc0(iStack_30);
      }
      *in_FS_OFFSET = uStack_2c;
    }
    else {
      if ((cStack_35 == '\x01') && (DAT_004f0590 == 0)) {
        DAT_004f059c = 0;
        DAT_004f05a0 = 0;
        DAT_004f05a4 = 0;
        iStack_44 = FUN_00437c00(param_5,param_4);
        if (iStack_44 != -1) {
          DAT_004f059c = 0x3e9;
          DAT_004f05a0 = iStack_44;
          *(int *)(iStack_30 + 0x3a4) = param_5 - *(int *)((&DAT_0050195c)[iStack_44] + 8);
          *(int *)(iStack_30 + 0x3a8) = param_4 - *(int *)((&DAT_0050195c)[DAT_004f05a0] + 0xc);
          FUN_00410fc0(iStack_30);
          func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_54);
          func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_4c);
          (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                    (*(int **)(iStack_30 + 0x304),auStack_4c[0],uStack_50);
          *in_FS_OFFSET = uStack_2c;
          return;
        }
        piVar6 = &DAT_004fb6c0;
        iStack_44 = 0xffffffff;
        for (iStack_3c = 0; iStack_3c < DAT_004fd60c; iStack_3c = iStack_3c + 1) {
          if (*(int *)(*piVar6 + 8) == 0x12d) {
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            if (((((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                     (float)param_5) &&
                   (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                   (float)param_5 <
                   (float)*(int *)(*piVar6 + 0x10) +
                   ((float)iVar4 * 0.5 - 24.0) * (float)DAT_004e6fb8)) &&
                  (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                  (float)*(int *)(*piVar6 + 0x14) +
                  ((float)iVar4 * 0.5 - (float)*(int *)(*piVar6 + 0x74)) * (float)DAT_004e6fb8 <
                  (float)param_4)) &&
                 ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                  (float)param_4 <
                  (float)*(int *)(*piVar6 + 0x14) +
                  (((float)iVar4 * 0.5 - (float)*(int *)(*piVar6 + 0x74)) + 15.0) *
                  (float)DAT_004e6fb8 && (*(int *)(*piVar6 + 0xc) == 0)))) ||
                ((((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                   (float)*(int *)(*piVar6 + 0x10) -
                   ((float)iVar4 * 0.5 - 14.0) * (float)DAT_004e6fb8 < (float)param_5 &&
                   ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
                    (float)param_5 <
                    (float)*(int *)(*piVar6 + 0x10) -
                    ((float)iVar4 * 0.5 - 36.0) * (float)DAT_004e6fb8 &&
                    (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                    (float)*(int *)(*piVar6 + 0x14) +
                    ((float)iVar4 * 0.5 - (float)*(int *)(*piVar6 + 0x74)) * (float)DAT_004e6fb8 <
                    (float)param_4)))) &&
                  (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                  (float)param_4 <
                  (float)*(int *)(*piVar6 + 0x14) +
                  (((float)iVar4 * 0.5 - (float)*(int *)(*piVar6 + 0x74)) + 22.0) *
                  (float)DAT_004e6fb8)) && (*(int *)(*piVar6 + 0xc) == 1)))) &&
               (*(int *)(*piVar6 + 0x68) != 0)) {
              DAT_004f059c = *(undefined4 *)(*piVar6 + 8);
              DAT_004f05a0 = iStack_3c;
              DAT_004f05a4 = 1;
              uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              *(int *)(iStack_30 + 0x3a8) =
                   ((iVar4 - param_4) + *(int *)(*piVar6 + 0x14)) - *(int *)(*piVar6 + 0x74);
              FUN_00410fc0(iStack_30);
              func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_64);
              func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_5c);
              (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                        (*(int **)(iStack_30 + 0x304),auStack_5c[0],uStack_60);
              *in_FS_OFFSET = uStack_2c;
              return;
            }
            iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
            in_ST6 = in_ST5;
            if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                   (float)param_5) &&
                 (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(), in_ST6 = in_ST5,
                 (float)param_5 <
                 (float)*(int *)(*piVar6 + 0x10) + ((float)iVar4 * 0.5 - 4.0) * (float)DAT_004e6fb8)
                 ) && (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(), in_ST6 = in_ST5,
                      (float)*(int *)(*piVar6 + 0x14) +
                      (((float)iVar4 * 0.5 - (float)*(int *)(*piVar6 + 0x7c)) + 4.0) *
                      (float)DAT_004e6fb8 < (float)param_4)) &&
               ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(), in_ST6 = in_ST5,
                (float)param_4 <
                (float)*(int *)(*piVar6 + 0x14) +
                (((float)iVar4 * 0.5 - (float)*(int *)(*piVar6 + 0x7c)) + 12.0) *
                (float)DAT_004e6fb8 && (*(int *)(*piVar6 + 0x6c) != 0)))) {
              DAT_004f059c = *(undefined4 *)(*piVar6 + 8);
              DAT_004f05a0 = iStack_3c;
              DAT_004f05a4 = 2;
              uVar3 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))();
              iVar4 = (int)uVar3 >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((uVar3 & 1) != 0);
              }
              *(int *)(iStack_30 + 0x3a8) =
                   ((iVar4 - param_4) + *(int *)(*piVar6 + 0x14)) - *(int *)(*piVar6 + 0x7c);
              FUN_00410fc0(iStack_30);
              func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_74);
              func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_6c);
              (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                        (*(int **)(iStack_30 + 0x304),auStack_6c[0],uStack_70);
              *in_FS_OFFSET = uStack_2c;
              return;
            }
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_004fb6c0;
        for (iStack_3c = 0; iStack_3c < DAT_004fd60c; iStack_3c = iStack_3c + 1) {
          if ((*(int *)(*piVar6 + 8) == 0x137) && (*(int *)(*piVar6 + 0xc) == 2)) {
            lVar7 = in_ST6;
            FUN_004c3234((double)((*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x3c)) -
                                 (*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x44))),0,0x40000000
                        );
            lVar8 = lVar7;
            FUN_004c3234((double)((*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x40)) -
                                 (*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x48))),0,0x40000000
                        );
            FUN_004c4544(SUB84((double)(in_ST1 + (longdouble)(double)in_ST0),0),
                         (uint)((ulonglong)(double)(in_ST1 + (longdouble)(double)in_ST0) >> 0x20));
            in_ST0 = lVar8;
            FUN_004c3234((double)(param_5 - (*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x3c))),0
                         ,0x40000000);
            dVar1 = (double)in_ST3;
            in_ST1 = in_ST0;
            FUN_004c3234((double)(param_4 - (*(int *)(*piVar6 + 0x14) + *(int *)(*piVar6 + 0x40))),0
                         ,0x40000000);
            in_ST3 = in_ST1;
            FUN_004c4544(SUB84((double)(in_ST4 + (longdouble)dVar1),0),
                         (uint)((ulonglong)(double)(in_ST4 + (longdouble)dVar1) >> 0x20));
            FUN_004c3234((double)(param_5 - (*(int *)(*piVar6 + 0x10) + *(int *)(*piVar6 + 0x44))),0
                         ,0x40000000);
            dVar1 = (double)in_ST6;
            in_ST4 = in_ST3;
            FUN_004c3234((double)(param_4 - (*(int *)(*piVar6 + 0x14) + *(int *)(*piVar6 + 0x48))),0
                         ,0x40000000);
            in_ST6 = in_ST4;
            FUN_004c4544(SUB84((double)(lVar7 + (longdouble)dVar1),0),
                         (uint)((ulonglong)(double)(lVar7 + (longdouble)dVar1) >> 0x20));
            FUN_004c2d30();
            if (lVar8 <= (longdouble)2.0) {
              DAT_004f059c = *(undefined4 *)(*piVar6 + 8);
              DAT_004f05a0 = iStack_3c;
              *(int *)(iStack_30 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
              *(int *)(iStack_30 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
              FUN_00410fc0(iStack_30);
              func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_84);
              func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_7c);
              (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                        (*(int **)(iStack_30 + 0x304),auStack_7c[0],uStack_80);
              *in_FS_OFFSET = uStack_2c;
              return;
            }
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_00502904;
        iStack_3c = 0;
        do {
          if (*piVar6 == 0) break;
          iVar4 = piVar6[0xd] >> 1;
          if (iVar4 < 0) {
            iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
          }
          iVar2 = piVar6[1];
          if (iVar2 - iVar4 < param_5) {
            iVar4 = piVar6[0xd] >> 1;
            if (iVar4 < 0) {
              iVar4 = iVar4 + (uint)((piVar6[0xd] & 1U) != 0);
            }
            if (param_5 < iVar4 + iVar2) {
              iVar4 = piVar6[0xe] >> 1;
              if (iVar4 < 0) {
                iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
              }
              if (piVar6[2] - iVar4 < param_4) {
                iVar4 = piVar6[0xe] >> 1;
                if (iVar4 < 0) {
                  iVar4 = iVar4 + (uint)((piVar6[0xe] & 1U) != 0);
                }
                if (param_4 < iVar4 + piVar6[2]) {
                  DAT_004f059c = 2000;
                  DAT_004f05a0 = iStack_3c;
                  *(int *)(iStack_30 + 0x3a4) = param_5 - iVar2;
                  *(int *)(iStack_30 + 0x3a8) = param_4 - piVar6[2];
                  FUN_00410fc0(iStack_30);
                  func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_94);
                  func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_8c);
                  (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                            (*(int **)(iStack_30 + 0x304),auStack_8c[0],uStack_90);
                  *in_FS_OFFSET = uStack_2c;
                  return;
                }
              }
            }
          }
          iStack_3c = iStack_3c + 1;
          piVar6 = piVar6 + 0x17;
        } while (iStack_3c < 100);
        piVar6 = &DAT_004fb6c0;
        for (iStack_3c = 0; iStack_3c < DAT_004fd60c; iStack_3c = iStack_3c + 1) {
          iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
          if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                 (float)param_5) &&
               (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
               (float)param_5 <
               (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8)) &&
              (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
              (float)param_4)) &&
             ((((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
                (float)param_4 <
                (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 &&
                (iVar4 = *(int *)(*piVar6 + 8), iVar4 != 0x12d)) &&
               ((iVar4 != 0x13c && (iVar4 != 0x13e)))) &&
              ((*(int *)(*piVar6 + 8) != 0x137 || (*(int *)(*piVar6 + 0xc) != 2)))))) {
            DAT_004f059c = *(undefined4 *)(*piVar6 + 8);
            DAT_004f05a0 = iStack_3c;
            *(int *)(iStack_30 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
            *(int *)(iStack_30 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
            FUN_00410fc0(iStack_30);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_a4);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_9c);
            (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                      (*(int **)(iStack_30 + 0x304),auStack_9c[0],uStack_a0);
            *in_FS_OFFSET = uStack_2c;
            return;
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_004fb6c0;
        for (iStack_3c = 0; iStack_3c < DAT_004fd60c; iStack_3c = iStack_3c + 1) {
          iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
          if (((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                 (float)param_5) &&
               (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
               (float)param_5 <
               (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8)) &&
              (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
              (float)param_4)) &&
             ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)param_4 <
              (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 &&
              (*(int *)(*piVar6 + 8) == 0x13c)))) {
            DAT_004f059c = *(undefined4 *)(*piVar6 + 8);
            DAT_004f05a0 = iStack_3c;
            *(int *)(iStack_30 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
            *(int *)(iStack_30 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
            FUN_00410fc0(iStack_30);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_b4);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_ac);
            (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                      (*(int **)(iStack_30 + 0x304),auStack_ac[0],uStack_b0);
            *in_FS_OFFSET = uStack_2c;
            return;
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_004fb6c0;
        for (iStack_3c = 0; iStack_3c < DAT_004fd60c; iStack_3c = iStack_3c + 1) {
          iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
          if ((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                (float)param_5) &&
              (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
              (float)param_5 <
              (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8)) &&
             ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
              (float)param_4 &&
              ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
               (float)param_4 <
               (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 &&
               (*(int *)(*piVar6 + 8) == 0x12d)))))) {
            DAT_004f059c = *(undefined4 *)(*piVar6 + 8);
            DAT_004f05a0 = iStack_3c;
            *(int *)(iStack_30 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
            *(int *)(iStack_30 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
            FUN_00410fc0(iStack_30);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_c4);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_bc);
            (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                      (*(int **)(iStack_30 + 0x304),auStack_bc[0],uStack_c0);
            *in_FS_OFFSET = uStack_2c;
            return;
          }
          piVar6 = piVar6 + 1;
        }
        piVar6 = &DAT_004fb6c0;
        for (iStack_3c = 0; iStack_3c < DAT_004fd60c; iStack_3c = iStack_3c + 1) {
          if (((((double)*(int *)(*piVar6 + 0xc4) * DAT_004e6fb8 + (double)*(int *)(*piVar6 + 0x10)
                 < (double)param_5) &&
               ((double)param_5 <
                (double)*(int *)(*piVar6 + 0xcc) +
                (double)*(int *)(*piVar6 + 0xc4) * DAT_004e6fb8 + (double)*(int *)(*piVar6 + 0x10)))
              && ((double)*(int *)(*piVar6 + 200) * DAT_004e6fb8 + (double)*(int *)(*piVar6 + 0x14)
                  < (double)param_4)) &&
             (((((double)param_4 <
                 (double)*(int *)(*piVar6 + 0xd0) * DAT_004e6fb8 +
                 (double)*(int *)(*piVar6 + 200) * DAT_004e6fb8 + (double)*(int *)(*piVar6 + 0x14)
                && (*(int *)(*piVar6 + 8) != 0x12d)) &&
               ((*(int *)(*piVar6 + 8) != 0x13c && (*(int *)(*piVar6 + 8) != 0x13e)))) &&
              ((*(int *)(*piVar6 + 8) != 0x137 || (*(int *)(*piVar6 + 0xc) != 2)))))) {
            DAT_004f059c = *(undefined4 *)(*piVar6 + 8);
            DAT_004f05a0 = iStack_3c;
            DAT_004f05a4 = 1;
            uVar5 = FUN_004c2d58();
            *(undefined4 *)(iStack_30 + 0x3a4) = uVar5;
            uVar5 = FUN_004c2d58();
            *(undefined4 *)(iStack_30 + 0x3a8) = uVar5;
            FUN_00410fc0(iStack_30);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_d4);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_cc);
            (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                      (*(int **)(iStack_30 + 0x304),auStack_cc[0],uStack_d0);
            *in_FS_OFFSET = uStack_2c;
            return;
          }
          piVar6 = piVar6 + 1;
        }
        iVar4 = 0;
        piVar6 = &DAT_004f05c0;
        do {
          if (*piVar6 == 0) break;
          if ((((piVar6[1] < param_5) &&
               ((double)param_5 < (double)piVar6[3] * DAT_004e6fb8 + (double)piVar6[1])) &&
              (piVar6[2] < param_4)) &&
             ((double)param_4 < (double)piVar6[4] * DAT_004e6fb8 + (double)piVar6[2])) {
            DAT_004f059c = 1000;
            DAT_004f05a0 = iVar4;
            *(int *)(iStack_30 + 0x3a4) = param_5 - piVar6[1];
            *(int *)(iStack_30 + 0x3a8) = param_4 - piVar6[2];
            FUN_00410fc0(iStack_30);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_e4);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_dc);
            (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                      (*(int **)(iStack_30 + 0x304),auStack_dc[0],uStack_e0);
            *in_FS_OFFSET = uStack_2c;
            return;
          }
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 0xd;
        } while (iVar4 < 100);
        iVar4 = 0;
        piVar6 = &DAT_00504dd4;
        do {
          if (*piVar6 == 0) break;
          if (((piVar6[1] + -0x78 < param_5) && (param_5 < piVar6[1] + 0x78)) &&
             ((piVar6[2] + -0x78 < param_4 && (param_4 < piVar6[2] + 0x78)))) {
            DAT_004f059c = 3000;
            DAT_004f05a0 = iVar4;
            *(int *)(iStack_30 + 0x3a4) = param_5 - piVar6[1];
            *(int *)(iStack_30 + 0x3a8) = param_4 - piVar6[2];
            FUN_00410fc0(iStack_30);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_f4);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_ec);
            (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                      (*(int **)(iStack_30 + 0x304),auStack_ec[0],uStack_f0);
            *in_FS_OFFSET = uStack_2c;
            return;
          }
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 0x52;
        } while (iVar4 < 10);
        piVar6 = &DAT_004fb6c0;
        for (iStack_3c = 0; iStack_3c < DAT_004fd60c; iStack_3c = iStack_3c + 1) {
          iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))();
          if ((((float)*(int *)(*piVar6 + 0x10) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
                (float)param_5) &&
              (iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x2c))(),
              (float)param_5 <
              (float)*(int *)(*piVar6 + 0x10) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8)) &&
             ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
              (float)*(int *)(*piVar6 + 0x14) - (float)iVar4 * 0.5 * (float)DAT_004e6fb8 <
              (float)param_4 &&
              ((iVar4 = (**(code **)(**(int **)(*piVar6 + 0xfc) + 0x20))(),
               (float)param_4 <
               (float)*(int *)(*piVar6 + 0x14) + (float)iVar4 * 0.5 * (float)DAT_004e6fb8 &&
               (*(int *)(*piVar6 + 8) == 0x13e)))))) {
            DAT_004f059c = *(undefined4 *)(*piVar6 + 8);
            DAT_004f05a0 = iStack_3c;
            *(int *)(iStack_30 + 0x3a4) = param_5 - *(int *)(*piVar6 + 0x10);
            *(int *)(iStack_30 + 0x3a8) = param_4 - *(int *)(*piVar6 + 0x14);
            FUN_00410fc0(iStack_30);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_104);
            func_0x004a7698(*(undefined4 *)PTR_DAT_004efd7c,auStack_fc);
            (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                      (*(int **)(iStack_30 + 0x304),auStack_fc[0],uStack_100);
            *in_FS_OFFSET = uStack_2c;
            return;
          }
          piVar6 = piVar6 + 1;
        }
        if (_DAT_004f05a8 != 0) {
          (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                    (*(int **)(iStack_30 + 0x304),
                     *(int *)(*(int *)(iStack_30 + 0x350) + 0x30) + param_5,
                     *(int *)(*(int *)(iStack_30 + 0x350) + 0x34) + param_4);
          *in_FS_OFFSET = uStack_2c;
          return;
        }
        (**(code **)(**(int **)(iStack_30 + 0x304) + 0x40))
                  (*(int **)(iStack_30 + 0x304),
                   *(int *)(*(int *)(iStack_30 + 0x350) + 0x30) + param_5,
                   *(int *)(*(int *)(iStack_30 + 0x350) + 0x34) + param_4);
      }
      *in_FS_OFFSET = uStack_2c;
    }
  }
  else {
    *(int *)(iStack_30 + 0x388) = *(int *)(iStack_30 + 0x388) + -1;
    *in_FS_OFFSET = uStack_2c;
  }
  return;
}



// Preserved published name: SpeedButton21Click
// Entry 00428678, recovered name Published_SpeedButton21Click_00428678

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_SpeedButton21Click_00428678(int param_1)

{
  if (DAT_004f0570 == 2) {
    _DAT_004f05bc = FUN_004c69dc();
    DAT_004f0570 = 1;
    FUN_004b1fd4(*(int **)(param_1 + 0x2ec),'\0');
    FUN_0049d5dc(*(int *)(param_1 + 0x350),'\0');
    return;
  }
  if (DAT_004f0570 == 1) {
    DAT_004f0570 = 2;
    FUN_004b1fd4(*(int **)(param_1 + 0x2ec),'\x01');
    FUN_0049d5dc(*(int *)(param_1 + 0x350),'\x01');
  }
  return;
}



// Preserved published name: SpeedButton19Click
// Entry 004286e4, recovered name Published_SpeedButton19Click_004286e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Published_SpeedButton19Click_004286e4(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *in_FS_OFFSET;
  byte bVar9;
  int *local_68;
  int *local_5c;
  int *local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_38;
  int local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  bVar9 = 0;
  FUN_004be6dc(0x4e4e64);
  _DAT_004df440 = 0;
  FUN_0049d5dc(*(int *)(param_1 + 0x350),'\0');
  *(undefined4 *)(param_1 + 0x3c4) = DAT_004f059c;
  *(undefined4 *)(param_1 + 0x3c8) = DAT_004f05a0;
  (**(code **)(**(int **)(param_1 + 0x2e8) + 0x5c))(*(int **)(param_1 + 0x2e8),1);
  (**(code **)(**(int **)(param_1 + 0x2ec) + 0x5c))(*(int **)(param_1 + 0x2ec),1);
  FUN_004b1fd4(*(int **)(param_1 + 0x2ec),'\0');
  if (*(char *)(param_1 + 0xbab) == '\x01') {
    DAT_004fd608 = 0;
    local_5c = &DAT_004fb6c0;
    local_58 = &DAT_004fc668;
    for (local_44 = 0; local_44 < DAT_004fd60c; local_44 = local_44 + 1) {
      local_8 = (undefined4 *)FUN_004bd650();
      if (local_8 != (undefined4 *)0x0) {
        local_8[1] = 0;
        FUN_004bdaac(local_8 + 2,0xe8,0x32,1,FUN_00423c04);
      }
      *local_58 = (int)local_8;
      *local_8 = 1;
      FUN_004ca864(local_8 + 1,(undefined4 *)(*local_5c + 4));
      for (iVar4 = 0; iVar4 < *(int *)(*local_5c + 0xf18); iVar4 = iVar4 + 1) {
        iVar5 = *local_5c + iVar4 * 0xe8;
        iVar6 = *local_58 + iVar4 * 0xe8;
        FUN_004ca864((int *)(iVar6 + 0xc),(undefined4 *)(iVar5 + 0xf24));
        FUN_004bd8d8(iVar6 + 0x18,iVar5 + 0xf30,4,10,3,FUN_004ca864);
        FUN_004bd8d8(iVar6 + 0x40,iVar5 + 0xf58,4,10,3,FUN_004ca864);
        FUN_004ca864((int *)(iVar6 + 0xc0),(undefined4 *)(iVar5 + 0xfd8));
        FUN_004ca864((int *)(iVar6 + 0xd8),(undefined4 *)(iVar5 + 0xff0));
        FUN_004ca864((int *)(iVar6 + 0xdc),(undefined4 *)(iVar5 + 0xff4));
        FUN_004ca864((int *)(iVar6 + 0xe0),(undefined4 *)(iVar5 + 0xff8));
        FUN_004ca864((int *)(iVar6 + 0xe4),(undefined4 *)(iVar5 + 0xffc));
        FUN_004ca864((int *)(iVar6 + 0xe8),(undefined4 *)(iVar5 + 0x1000));
        *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar5 + 0xf20);
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar5 + 0xf28);
        *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(iVar5 + 0xf2c);
        puVar7 = (undefined4 *)(iVar5 + 0xf80);
        puVar8 = (undefined4 *)(iVar6 + 0x68);
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
          puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
        }
        puVar7 = (undefined4 *)(iVar5 + 0xfa8);
        puVar8 = (undefined4 *)(iVar6 + 0x90);
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
          puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
        }
        *(undefined4 *)(iVar6 + 0xb8) = *(undefined4 *)(iVar5 + 0xfd0);
        *(undefined4 *)(iVar6 + 0xbc) = *(undefined4 *)(iVar5 + 0xfd4);
        *(undefined4 *)(iVar6 + 200) = *(undefined4 *)(iVar5 + 0xfe0);
        *(undefined4 *)(iVar6 + 0xcc) = *(undefined4 *)(iVar5 + 0xfe4);
        *(undefined4 *)(iVar6 + 0xd0) = *(undefined4 *)(iVar5 + 0xfe8);
        *(undefined4 *)(iVar6 + 0xd4) = *(undefined4 *)(iVar5 + 0xfec);
      }
      *(undefined4 *)(*local_58 + 0x2d58) = *(undefined4 *)(*local_5c + 0xf18);
      DAT_004fd608 = DAT_004fd608 + 1;
      local_5c = local_5c + 1;
      local_58 = local_58 + 1;
    }
    FUN_0043350c();
    piVar2 = FUN_004ca710(&local_c);
    FUN_0041e2e8(param_1,*piVar2,0);
    FUN_004ca834(&local_c,2);
    local_5c = &DAT_004fb6c0;
    for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
      if (*(int *)(*local_5c + 0xa4) == 1) {
        local_4c = -1;
        iVar4 = 0;
        local_68 = &DAT_004fc668;
        while ((iVar3 = local_4c, iVar4 < DAT_004fd608 &&
               (bVar1 = FUN_004ca904((undefined4 *)(*local_68 + 4),(undefined4 *)(*local_5c + 4)),
               iVar3 = iVar4, bVar1 == 0))) {
          iVar4 = iVar4 + 1;
          local_68 = local_68 + 1;
        }
        local_4c = iVar3;
        if (local_4c != -1) {
          for (local_50 = 0; local_50 < *(int *)((&DAT_004fc668)[local_4c] + 0x2d58);
              local_50 = local_50 + 1) {
            iVar6 = (&DAT_004fc668)[local_4c] + local_50 * 0xe8;
            iVar3 = *local_5c + local_50 * 0xe8;
            FUN_004ca864((int *)(iVar3 + 0xf24),(undefined4 *)(iVar6 + 0xc));
            FUN_004bd8d8(iVar3 + 0xf30,iVar6 + 0x18,4,10,3,FUN_004ca864);
            FUN_004bd8d8(iVar3 + 0xf58,iVar6 + 0x40,4,10,3,FUN_004ca864);
            FUN_004ca864((int *)(iVar3 + 0xfd8),(undefined4 *)(iVar6 + 0xc0));
            FUN_004ca864((int *)(iVar3 + 0xff0),(undefined4 *)(iVar6 + 0xd8));
            FUN_004ca864((int *)(iVar3 + 0xff4),(undefined4 *)(iVar6 + 0xdc));
            FUN_004ca864((int *)(iVar3 + 0xff8),(undefined4 *)(iVar6 + 0xe0));
            FUN_004ca864((int *)(iVar3 + 0xffc),(undefined4 *)(iVar6 + 0xe4));
            FUN_004ca864((int *)(iVar3 + 0x1000),(undefined4 *)(iVar6 + 0xe8));
            *(undefined4 *)(iVar3 + 0xf20) = *(undefined4 *)(iVar6 + 8);
            *(undefined4 *)(iVar3 + 0xf28) = *(undefined4 *)(iVar6 + 0x10);
            *(undefined4 *)(iVar3 + 0xf2c) = *(undefined4 *)(iVar6 + 0x14);
            puVar7 = (undefined4 *)(iVar6 + 0x68);
            puVar8 = (undefined4 *)(iVar3 + 0xf80);
            for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
              puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
            }
            puVar7 = (undefined4 *)(iVar6 + 0x90);
            puVar8 = (undefined4 *)(iVar3 + 0xfa8);
            for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
              puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
            }
            *(undefined4 *)(iVar3 + 0xfd0) = *(undefined4 *)(iVar6 + 0xb8);
            *(undefined4 *)(iVar3 + 0xfd4) = *(undefined4 *)(iVar6 + 0xbc);
            *(undefined4 *)(iVar3 + 0xfe0) = *(undefined4 *)(iVar6 + 200);
            *(undefined4 *)(iVar3 + 0xfe4) = *(undefined4 *)(iVar6 + 0xcc);
            *(undefined4 *)(iVar3 + 0xfe8) = *(undefined4 *)(iVar6 + 0xd0);
            *(undefined4 *)(iVar3 + 0xfec) = *(undefined4 *)(iVar6 + 0xd4);
          }
          *(undefined4 *)(*local_5c + 0xf18) = *(undefined4 *)((&DAT_004fc668)[local_4c] + 0x2d58);
        }
      }
      local_5c = local_5c + 1;
    }
    local_5c = &DAT_004fc668;
    for (local_54 = 0; local_54 < DAT_004fd608; local_54 = local_54 + 1) {
      local_10 = *local_5c;
      if (local_10 != 0) {
        FUN_004bd94c(local_10 + 8,0xe8,0x32,1,FUN_00423ce8);
        FUN_004ca834((int *)(local_10 + 4),2);
        FUN_004bd61c();
      }
      *local_5c = 0;
      local_5c = local_5c + 1;
    }
    DAT_004fd608 = 0;
    DAT_004f059c = *(undefined4 *)(param_1 + 0x3c4);
    DAT_004f05a0 = *(undefined4 *)(param_1 + 0x3c8);
  }
  local_5c = &DAT_004fb6c0;
  for (iVar4 = 0; iVar4 < DAT_004fd60c; iVar4 = iVar4 + 1) {
    iVar3 = *local_5c;
    *(undefined4 *)(iVar3 + 0x3cc8) = 0;
    *(undefined4 *)(iVar3 + 0x3ccc) = 0;
    *(undefined4 *)(iVar3 + 0x4318) = 0;
    *(undefined4 *)(iVar3 + 0x431c) = 0;
    for (iVar3 = 0; iVar6 = *local_5c, iVar3 < *(int *)(iVar6 + 0x104); iVar3 = iVar3 + 1) {
      *(undefined4 *)(iVar6 + 0x3cd8 + iVar3 * 8) = 0;
      *(undefined4 *)(iVar6 + 0x3cdc + iVar3 * 8) = 0;
      *(undefined4 *)(iVar6 + 0x3ff8 + iVar3 * 8) = 0;
      *(undefined4 *)(iVar6 + 0x3ffc + iVar3 * 8) = 0;
    }
    local_5c = local_5c + 1;
  }
  local_5c = &DAT_0050195c;
  for (iVar4 = 0; iVar4 < DAT_005028fc; iVar4 = iVar4 + 1) {
    iVar3 = *local_5c;
    *(undefined4 *)(iVar3 + 0x70) = 0;
    *(undefined4 *)(iVar3 + 0x74) = 0;
    *(undefined4 *)(iVar3 + 0x78) = 0;
    local_5c = local_5c + 1;
  }
  FUN_00429888(param_1);
  DAT_004e6fc4 = 0;
  DAT_004e6fc8 = 0;
  _DAT_004f05bc = FUN_004c69dc();
  piVar2 = FUN_004ca710(&local_14);
  FUN_0041b130(param_1,*piVar2,0);
  FUN_004ca834(&local_14,2);
  *(undefined1 *)(param_1 + 0xbab) = 1;
  FUN_00448024();
  FUN_00464e70();
  DAT_004f0570 = 1;
  *in_FS_OFFSET = local_38;
  return;
}



// Preserved published name: SpeedButton20Click
// Entry 00428de8, recovered name Published_SpeedButton20Click_00428de8

void Published_SpeedButton20Click_00428de8(int param_1)

{
  byte bVar1;
  LPCSTR lpFile;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *in_FS_OFFSET;
  byte bVar8;
  int *local_68;
  int *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_40;
  int local_1c;
  int local_18;
  LPCSTR local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  bVar8 = 0;
  FUN_004be6dc(0x4e4f20);
  FUN_0049d5dc(*(int *)(param_1 + 0x350),'\x01');
  (**(code **)(**(int **)(param_1 + 0x2e8) + 0x5c))(*(int **)(param_1 + 0x2e8),0);
  (**(code **)(**(int **)(param_1 + 0x2ec) + 0x5c))(*(int **)(param_1 + 0x2ec),0);
  FUN_004b1fd4(*(int **)(param_1 + 0x2ec),'\0');
  DAT_004f0570 = 0;
  DAT_004e6fc4 = 0;
  DAT_004e6fc8 = 0;
  if (*(char *)(param_1 + 0xbab) == '\x01') {
    DAT_004fd608 = 0;
    piVar6 = &DAT_004fb6c0;
    local_5c = &DAT_004fc668;
    for (local_48 = 0; local_48 < DAT_004fd60c; local_48 = local_48 + 1) {
      local_8 = (undefined4 *)FUN_004bd650();
      if (local_8 != (undefined4 *)0x0) {
        local_8[1] = 0;
        FUN_004bdaac(local_8 + 2,0xe8,0x32,1,FUN_00423c04);
      }
      *local_5c = (int)local_8;
      *local_8 = 1;
      FUN_004ca864(local_8 + 1,(undefined4 *)(*piVar6 + 4));
      for (local_4c = 0; local_4c < *(int *)(*piVar6 + 0xf18); local_4c = local_4c + 1) {
        iVar4 = *piVar6 + local_4c * 0xe8;
        iVar2 = *local_5c + local_4c * 0xe8;
        FUN_004ca864((int *)(iVar2 + 0xc),(undefined4 *)(iVar4 + 0xf24));
        FUN_004bd8d8(iVar2 + 0x18,iVar4 + 0xf30,4,10,3,FUN_004ca864);
        FUN_004bd8d8(iVar2 + 0x40,iVar4 + 0xf58,4,10,3,FUN_004ca864);
        FUN_004ca864((int *)(iVar2 + 0xc0),(undefined4 *)(iVar4 + 0xfd8));
        FUN_004ca864((int *)(iVar2 + 0xd8),(undefined4 *)(iVar4 + 0xff0));
        FUN_004ca864((int *)(iVar2 + 0xdc),(undefined4 *)(iVar4 + 0xff4));
        FUN_004ca864((int *)(iVar2 + 0xe0),(undefined4 *)(iVar4 + 0xff8));
        FUN_004ca864((int *)(iVar2 + 0xe4),(undefined4 *)(iVar4 + 0xffc));
        FUN_004ca864((int *)(iVar2 + 0xe8),(undefined4 *)(iVar4 + 0x1000));
        *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar4 + 0xf20);
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar4 + 0xf28);
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar4 + 0xf2c);
        puVar5 = (undefined4 *)(iVar4 + 0xf80);
        puVar7 = (undefined4 *)(iVar2 + 0x68);
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + (uint)bVar8 * -2 + 1;
          puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
        }
        puVar5 = (undefined4 *)(iVar4 + 0xfa8);
        puVar7 = (undefined4 *)(iVar2 + 0x90);
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + (uint)bVar8 * -2 + 1;
          puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
        }
        *(undefined4 *)(iVar2 + 0xb8) = *(undefined4 *)(iVar4 + 0xfd0);
        *(undefined4 *)(iVar2 + 0xbc) = *(undefined4 *)(iVar4 + 0xfd4);
        *(undefined4 *)(iVar2 + 200) = *(undefined4 *)(iVar4 + 0xfe0);
        *(undefined4 *)(iVar2 + 0xcc) = *(undefined4 *)(iVar4 + 0xfe4);
        *(undefined4 *)(iVar2 + 0xd0) = *(undefined4 *)(iVar4 + 0xfe8);
        *(undefined4 *)(iVar2 + 0xd4) = *(undefined4 *)(iVar4 + 0xfec);
      }
      *(undefined4 *)(*local_5c + 0x2d58) = *(undefined4 *)(*piVar6 + 0xf18);
      DAT_004fd608 = DAT_004fd608 + 1;
      piVar6 = piVar6 + 1;
      local_5c = local_5c + 1;
    }
    FUN_0043350c();
    piVar6 = FUN_004ca710(&local_c);
    FUN_0041e2e8(param_1,*piVar6,0);
    FUN_004ca834(&local_c,2);
    piVar6 = &DAT_004fb6c0;
    for (local_50 = 0; local_50 < DAT_004fd60c; local_50 = local_50 + 1) {
      if (*(int *)(*piVar6 + 0xa4) == 1) {
        local_54 = -1;
        iVar3 = 0;
        local_68 = &DAT_004fc668;
        while ((iVar2 = local_54, iVar3 < DAT_004fd608 &&
               (bVar1 = FUN_004ca904((undefined4 *)(*local_68 + 4),(undefined4 *)(*piVar6 + 4)),
               iVar2 = iVar3, bVar1 == 0))) {
          iVar3 = iVar3 + 1;
          local_68 = local_68 + 1;
        }
        local_54 = iVar2;
        if (local_54 != -1) {
          for (local_58 = 0; local_58 < *(int *)((&DAT_004fc668)[local_54] + 0x2d58);
              local_58 = local_58 + 1) {
            iVar4 = (&DAT_004fc668)[local_54] + local_58 * 0xe8;
            iVar2 = *piVar6 + local_58 * 0xe8;
            FUN_004ca864((int *)(iVar2 + 0xf24),(undefined4 *)(iVar4 + 0xc));
            FUN_004bd8d8(iVar2 + 0xf30,iVar4 + 0x18,4,10,3,FUN_004ca864);
            FUN_004bd8d8(iVar2 + 0xf58,iVar4 + 0x40,4,10,3,FUN_004ca864);
            FUN_004ca864((int *)(iVar2 + 0xfd8),(undefined4 *)(iVar4 + 0xc0));
            FUN_004ca864((int *)(iVar2 + 0xff0),(undefined4 *)(iVar4 + 0xd8));
            FUN_004ca864((int *)(iVar2 + 0xff4),(undefined4 *)(iVar4 + 0xdc));
            FUN_004ca864((int *)(iVar2 + 0xff8),(undefined4 *)(iVar4 + 0xe0));
            FUN_004ca864((int *)(iVar2 + 0xffc),(undefined4 *)(iVar4 + 0xe4));
            FUN_004ca864((int *)(iVar2 + 0x1000),(undefined4 *)(iVar4 + 0xe8));
            *(undefined4 *)(iVar2 + 0xf20) = *(undefined4 *)(iVar4 + 8);
            *(undefined4 *)(iVar2 + 0xf28) = *(undefined4 *)(iVar4 + 0x10);
            *(undefined4 *)(iVar2 + 0xf2c) = *(undefined4 *)(iVar4 + 0x14);
            puVar5 = (undefined4 *)(iVar4 + 0x68);
            puVar7 = (undefined4 *)(iVar2 + 0xf80);
            for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + (uint)bVar8 * -2 + 1;
              puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
            }
            puVar5 = (undefined4 *)(iVar4 + 0x90);
            puVar7 = (undefined4 *)(iVar2 + 0xfa8);
            for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + (uint)bVar8 * -2 + 1;
              puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
            }
            *(undefined4 *)(iVar2 + 0xfd0) = *(undefined4 *)(iVar4 + 0xb8);
            *(undefined4 *)(iVar2 + 0xfd4) = *(undefined4 *)(iVar4 + 0xbc);
            *(undefined4 *)(iVar2 + 0xfe0) = *(undefined4 *)(iVar4 + 200);
            *(undefined4 *)(iVar2 + 0xfe4) = *(undefined4 *)(iVar4 + 0xcc);
            *(undefined4 *)(iVar2 + 0xfe8) = *(undefined4 *)(iVar4 + 0xd0);
            *(undefined4 *)(iVar2 + 0xfec) = *(undefined4 *)(iVar4 + 0xd4);
          }
          *(undefined4 *)(*piVar6 + 0xf18) = *(undefined4 *)((&DAT_004fc668)[local_54] + 0x2d58);
        }
      }
      piVar6 = piVar6 + 1;
    }
    piVar6 = &DAT_004fc668;
    for (iVar3 = 0; iVar3 < DAT_004fd608; iVar3 = iVar3 + 1) {
      local_10 = *piVar6;
      if (local_10 != 0) {
        FUN_004bd94c(local_10 + 8,0xe8,0x32,1,FUN_00423ce8);
        FUN_004ca834((int *)(local_10 + 4),2);
        FUN_004bd61c();
      }
      *piVar6 = 0;
      piVar6 = piVar6 + 1;
    }
    DAT_004fd608 = 0;
    DAT_004f059c = *(undefined4 *)(param_1 + 0x3c4);
    DAT_004f05a0 = *(undefined4 *)(param_1 + 0x3c8);
  }
  *(undefined1 *)(param_1 + 0xbab) = 0;
  FUN_00429888(param_1);
  if (*(int *)(param_1 + 0x3bc) == 1) {
    *(undefined4 *)(param_1 + 0x3bc) = 0;
    *(undefined4 *)(param_1 + 0x3c0) = 0;
    local_14 = (LPCSTR)0x0;
    FUN_004ca710(&local_18);
    local_1c = 0;
    FUN_004ca878((undefined4 *)&DAT_004f05b0,&local_18,&local_1c);
    FUN_004ca864((int *)&local_14,&local_1c);
    FUN_004ca834(&local_1c,2);
    FUN_004ca834(&local_18,2);
    lpFile = local_14;
    if (local_14 == (LPCSTR)0x0) {
      lpFile = &DAT_004dfc2c;
    }
    ShellExecuteA(*(HWND *)(*(int *)PTR_DAT_004efd74 + 0x24),&DAT_004dfc25,lpFile,&DAT_004dfc2a,
                  &DAT_004dfc2b,1);
    FUN_004ca834((int *)&local_14,2);
  }
  *in_FS_OFFSET = local_40;
  return;
}



// Preserved published name: PopupMenu1Popup
// Entry 00429490, recovered name Published_PopupMenu1Popup_00429490

void Published_PopupMenu1Popup_00429490(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  int local_c;
  int local_8;
  
  FUN_004be6dc(0x4e4fa8);
  FUN_0047cae8(*(int **)(param_1 + 0x30c),'\0');
  FUN_0047cae8(*(int **)(param_1 + 0x310),'\0');
  FUN_0047cae8(*(int **)(param_1 + 0x314),'\0');
  FUN_0047cae8(*(int **)(param_1 + 0x324),'\0');
  FUN_0047cae8(*(int **)(param_1 + 800),'\0');
  FUN_0047cae8(*(int **)(param_1 + 0x31c),'\0');
  if (((100 < DAT_004f059c) && (DAT_004f059c < 300)) &&
     ((((DAT_004f059c == 0x65 ||
        ((((DAT_004f059c == 0x67 || (DAT_004f059c == 0x68)) || (DAT_004f059c == 0x69)) ||
         ((DAT_004f059c == 0x6a || (DAT_004f059c == 0x6b)))))) ||
       ((DAT_004f059c == 0x6c || ((DAT_004f059c == 0xc9 || (DAT_004f059c == 0xca)))))) &&
      (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) == 0)))) {
    FUN_0047cae8(*(int **)(param_1 + 800),'\x01');
    FUN_0047cae8(*(int **)(param_1 + 0x330),'\x01');
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) == 0) {
      FUN_0047c978(*(int *)(param_1 + 800),0);
    }
    else {
      FUN_0047c978(*(int *)(param_1 + 800),1);
    }
  }
  if (DAT_004f059c == 0x12e) {
    FUN_0047cae8(*(int **)(param_1 + 0x360),'\x01');
    FUN_0047cae8(*(int **)(param_1 + 0x31c),'\x01');
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) == 0) {
      piVar1 = FUN_004ca710(&local_8);
      FUN_0047c908(*(int **)(param_1 + 0x31c),(uint *)*piVar1);
      FUN_004ca834(&local_8,2);
    }
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) == 1) {
      piVar1 = FUN_004ca710(&local_c);
      FUN_0047c908(*(int **)(param_1 + 0x31c),(uint *)*piVar1);
      FUN_004ca834(&local_c,2);
    }
  }
  if (DAT_004f059c == 0x12d) {
    FUN_0047cae8(*(int **)(param_1 + 0x30c),'\x01');
    FUN_0047cae8(*(int **)(param_1 + 0x310),'\x01');
    FUN_0047cae8(*(int **)(param_1 + 0x314),'\x01');
    FUN_0047cae8(*(int **)(param_1 + 0x324),'\x01');
    FUN_0047c978(*(int *)(param_1 + 0x30c),0);
    FUN_0047c978(*(int *)(param_1 + 0x310),0);
    FUN_0047c978(*(int *)(param_1 + 0x314),0);
    FUN_0047c978(*(int *)(param_1 + 0x324),0);
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x68) == 1) {
      FUN_0047c978(*(int *)(param_1 + 0x30c),1);
    }
    if ((*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) == 1) ||
       (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) == 2)) {
      FUN_0047c978(*(int *)(param_1 + 0x310),1);
    }
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) == 2) {
      FUN_0047c978(*(int *)(param_1 + 0x314),1);
    }
  }
  FUN_0047cae8(*(int **)(param_1 + 0x308),'\0');
  if (((((DAT_004f059c == 0x66) || (DAT_004f059c == 0x67)) || (DAT_004f059c == 0x68)) ||
      (((DAT_004f059c == 0x69 || (DAT_004f059c == 0xc9)) || (DAT_004f059c == 0xca)))) &&
     (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) == 0)) {
    FUN_0047cae8(*(int **)(param_1 + 0x308),'\x01');
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) == 0) {
      FUN_0047c978(*(int *)(param_1 + 0x308),0);
    }
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) == 2) {
      FUN_0047c978(*(int *)(param_1 + 0x308),1);
    }
  }
  else if (((DAT_004f059c == 0x65) &&
           ((*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 0 ||
            (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 0x2d)))) &&
          (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) == 0)) {
    FUN_0047cae8(*(int **)(param_1 + 0x308),'\x01');
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) == 0) {
      FUN_0047c978(*(int *)(param_1 + 0x308),0);
    }
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) == 2) {
      FUN_0047c978(*(int *)(param_1 + 0x308),1);
    }
  }
  else {
    FUN_0047cae8(*(int **)(param_1 + 0x308),'\0');
  }
  FUN_0047cae8(*(int **)(param_1 + 0x318),'\0');
  if (DAT_004f059c == 0xd1) {
    FUN_0047cae8(*(int **)(param_1 + 0x318),'\x01');
    if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) == 1) {
      FUN_0047c978(*(int *)(param_1 + 0x318),1);
    }
    else {
      FUN_0047c978(*(int *)(param_1 + 0x318),0);
    }
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: FormCloseQuery
// Entry 0042c0ac, recovered name Published_FormCloseQuery_0042c0ac

void Published_FormCloseQuery_0042c0ac(void)

{
  FUN_0043350c();
  return;
}



// Preserved published name: SpeedButton1Click
// Entry 0042c0b8, recovered name Published_SpeedButton1Click_0042c0b8

void Published_SpeedButton1Click_0042c0b8(void)

{
  FUN_0043350c();
  FUN_004c525c(1);
  return;
}



// Preserved published name: SpeedButton28Click
// Entry 0042c0cc, recovered name Published_SpeedButton28Click_0042c0cc

void Published_SpeedButton28Click_0042c0cc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (DAT_004e6fb8 < 2.0) {
    DAT_004f057c = 0;
    DAT_004f0580 = 0;
    DAT_004f0584 = 0;
    DAT_004f0588 = 0;
    piVar3 = &DAT_004fb6c0;
    for (iVar4 = 0; iVar4 < DAT_004fd60c; iVar4 = iVar4 + 1) {
      iVar2 = *piVar3;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0x10) = uVar1;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0x14) = uVar1;
      piVar3 = piVar3 + 1;
    }
    piVar3 = &DAT_0050195c;
    for (iVar4 = 0; iVar4 < DAT_005028fc; iVar4 = iVar4 + 1) {
      iVar2 = *piVar3;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 8) = uVar1;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0x10) = uVar1;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0x14) = uVar1;
      piVar3 = piVar3 + 1;
    }
    iVar4 = 0;
    piVar3 = &DAT_004f05c0;
    do {
      if (*piVar3 == 0) break;
      iVar2 = FUN_004c2d58();
      piVar3[1] = iVar2;
      iVar2 = FUN_004c2d58();
      piVar3[2] = iVar2;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0xd;
    } while (iVar4 < 100);
    iVar4 = 0;
    piVar3 = &DAT_00502904;
    do {
      if (*piVar3 == 0) break;
      iVar2 = FUN_004c2d58();
      piVar3[1] = iVar2;
      iVar2 = FUN_004c2d58();
      piVar3[2] = iVar2;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0x17;
    } while (iVar4 < 100);
    iVar4 = 0;
    piVar3 = &DAT_00504dd4;
    do {
      if (*piVar3 == 0) break;
      iVar2 = FUN_004c2d58();
      piVar3[1] = iVar2;
      iVar2 = FUN_004c2d58();
      piVar3[2] = iVar2;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0x52;
    } while (iVar4 < 10);
    DAT_004e6fb8 = DAT_004e6fb8 + 0.1;
    FUN_00429888(param_1);
  }
  (**(code **)(**(int **)(param_1 + 0x2fc) + 0x5c))(*(int **)(param_1 + 0x2fc),1);
  (**(code **)(**(int **)(param_1 + 0x300) + 0x5c))(*(int **)(param_1 + 0x300),1);
  if (1.99 <= DAT_004e6fb8) {
    (**(code **)(**(int **)(param_1 + 0x2fc) + 0x5c))(*(int **)(param_1 + 0x2fc),0);
    (**(code **)(**(int **)(param_1 + 0x300) + 0x5c))(*(int **)(param_1 + 0x300),1);
  }
  return;
}



// Preserved published name: SpeedButton29Click
// Entry 0042c358, recovered name Published_SpeedButton29Click_0042c358

void Published_SpeedButton29Click_0042c358(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (1.05 < DAT_004e6fb8) {
    DAT_004f057c = 0;
    DAT_004f0580 = 0;
    DAT_004f0584 = 0;
    DAT_004f0588 = 0;
    piVar3 = &DAT_004fb6c0;
    for (iVar4 = 0; iVar4 < DAT_004fd60c; iVar4 = iVar4 + 1) {
      iVar2 = *piVar3;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0x10) = uVar1;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0x14) = uVar1;
      piVar3 = piVar3 + 1;
    }
    piVar3 = &DAT_0050195c;
    for (iVar4 = 0; iVar4 < DAT_005028fc; iVar4 = iVar4 + 1) {
      iVar2 = *piVar3;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 8) = uVar1;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0x10) = uVar1;
      uVar1 = FUN_004c2d58();
      *(undefined4 *)(iVar2 + 0x14) = uVar1;
      piVar3 = piVar3 + 1;
    }
    iVar4 = 0;
    piVar3 = &DAT_004f05c0;
    do {
      if (*piVar3 == 0) break;
      iVar2 = FUN_004c2d58();
      piVar3[1] = iVar2;
      iVar2 = FUN_004c2d58();
      piVar3[2] = iVar2;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0xd;
    } while (iVar4 < 100);
    iVar4 = 0;
    piVar3 = &DAT_00502904;
    do {
      if (*piVar3 == 0) break;
      iVar2 = FUN_004c2d58();
      piVar3[1] = iVar2;
      iVar2 = FUN_004c2d58();
      piVar3[2] = iVar2;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0x17;
    } while (iVar4 < 100);
    iVar4 = 0;
    piVar3 = &DAT_00504dd4;
    do {
      if (*piVar3 == 0) break;
      iVar2 = FUN_004c2d58();
      piVar3[1] = iVar2;
      iVar2 = FUN_004c2d58();
      piVar3[2] = iVar2;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0x52;
    } while (iVar4 < 10);
    DAT_004e6fb8 = DAT_004e6fb8 - 0.1;
    FUN_00429888(param_1);
  }
  (**(code **)(**(int **)(param_1 + 0x2fc) + 0x5c))(*(int **)(param_1 + 0x2fc),1);
  (**(code **)(**(int **)(param_1 + 0x300) + 0x5c))(*(int **)(param_1 + 0x300),1);
  if (DAT_004e6fb8 <= 1.01) {
    (**(code **)(**(int **)(param_1 + 0x2fc) + 0x5c))(*(int **)(param_1 + 0x2fc),1);
    (**(code **)(**(int **)(param_1 + 0x300) + 0x5c))(*(int **)(param_1 + 0x300),0);
  }
  return;
}



// Preserved published name: N18Click
// Entry 0042c5e8, recovered name Published_N18Click_0042c5e8

void Published_N18Click_0042c5e8(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1f8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1cc;
  int iStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  int iStack_1bc;
  int iStack_1b8;
  int iStack_1b4;
  int iStack_1b0;
  int iStack_1ac;
  int iStack_1a8;
  int iStack_1a4;
  int iStack_1a0;
  int iStack_19c;
  int iStack_198;
  int iStack_194;
  int iStack_190;
  int iStack_18c;
  int iStack_188;
  int iStack_184;
  int iStack_180;
  int iStack_17c;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  int iStack_164;
  int iStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  int iStack_150;
  int iStack_14c;
  int iStack_148;
  int iStack_144;
  int iStack_140;
  int iStack_13c;
  int iStack_138;
  int iStack_134;
  int iStack_130;
  int iStack_12c;
  int iStack_128;
  int iStack_124;
  int iStack_120;
  int iStack_11c;
  int iStack_118;
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  int iStack_108;
  int iStack_104;
  int iStack_100;
  int iStack_fc;
  int iStack_f8;
  int iStack_f4;
  int iStack_f0;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  int iStack_e0;
  int iStack_dc;
  int iStack_d8;
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  int iStack_b4;
  int iStack_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  FUN_004be6dc(0x4e5bd8);
  if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) == 0) {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) = 2;
    FUN_0047c978(*(int *)(param_1 + 0x308),1);
    iVar1 = *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 8);
    if (iVar1 < 0x6a) {
      if (iVar1 == 0x69) {
        FUN_004ca710(&iStack_78);
        iStack_7c = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_78,&iStack_7c);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_7c);
        FUN_004ca834(&iStack_7c,2);
        FUN_004ca834(&iStack_78,2);
        FUN_004ca710(&iStack_80);
        iStack_84 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_80,&iStack_84);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_84);
        FUN_004ca834(&iStack_84,2);
        FUN_004ca834(&iStack_80,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
      else if (iVar1 == 0x65) {
        FUN_004ca710(&iStack_8);
        iStack_c = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_8,&iStack_c);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_c);
        FUN_004ca834(&iStack_c,2);
        FUN_004ca834(&iStack_8,2);
        FUN_004ca710(&iStack_10);
        iStack_14 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_10,&iStack_14);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_14);
        FUN_004ca834(&iStack_14,2);
        FUN_004ca834(&iStack_10,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        piVar2 = *(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc);
        (**(code **)(*piVar2 + 8))(piVar2,*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
      else if (iVar1 == 0x66) {
        iVar1 = (&DAT_004fb6c0)[DAT_004f05a0];
        if (*(int *)(iVar1 + 0xc) == 100) {
          FUN_004ca710(&iStack_18);
          iStack_1c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_18,&iStack_1c);
          piVar2 = *(int **)(iVar1 + 0xf4);
          (**(code **)(*piVar2 + 0x48))(piVar2,iStack_1c);
          FUN_004ca834(&iStack_1c,2);
          FUN_004ca834(&iStack_18,2);
          FUN_004ca710(&iStack_20);
          iStack_24 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_20,&iStack_24);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_24);
          FUN_004ca834(&iStack_24,2);
          FUN_004ca834(&iStack_20,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 200) {
          FUN_004ca710(&iStack_28);
          iStack_2c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_28,&iStack_2c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_2c);
          FUN_004ca834(&iStack_2c,2);
          FUN_004ca834(&iStack_28,2);
          FUN_004ca710(&iStack_30);
          iStack_34 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_30,&iStack_34);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_34);
          FUN_004ca834(&iStack_34,2);
          FUN_004ca834(&iStack_30,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 500) {
          FUN_004ca710(&iStack_38);
          iStack_3c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_38,&iStack_3c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_3c);
          FUN_004ca834(&iStack_3c,2);
          FUN_004ca834(&iStack_38,2);
          FUN_004ca710(&iStack_40);
          iStack_44 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_40,&iStack_44);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_44);
          FUN_004ca834(&iStack_44,2);
          FUN_004ca834(&iStack_40,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
      }
      else if (iVar1 == 0x67) {
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 100) {
          FUN_004ca710(&iStack_48);
          iStack_4c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_48,&iStack_4c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_4c);
          FUN_004ca834(&iStack_4c,2);
          FUN_004ca834(&iStack_48,2);
          FUN_004ca710(&iStack_50);
          iStack_54 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_50,&iStack_54);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_54);
          FUN_004ca834(&iStack_54,2);
          FUN_004ca834(&iStack_50,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 0xfa) {
          FUN_004ca710(&iStack_58);
          iStack_5c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_58,&iStack_5c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_5c);
          FUN_004ca834(&iStack_5c,2);
          FUN_004ca834(&iStack_58,2);
          FUN_004ca710(&iStack_60);
          iStack_64 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_60,&iStack_64);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_64);
          FUN_004ca834(&iStack_64,2);
          FUN_004ca834(&iStack_60,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
      }
      else if (iVar1 == 0x68) {
        FUN_004ca710(&iStack_68);
        iStack_6c = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_68,&iStack_6c);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_6c);
        FUN_004ca834(&iStack_6c,2);
        FUN_004ca834(&iStack_68,2);
        FUN_004ca710(&iStack_70);
        iStack_74 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_70,&iStack_74);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_74);
        FUN_004ca834(&iStack_74,2);
        FUN_004ca834(&iStack_70,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
    }
    else if (iVar1 == 0x6a) {
      FUN_004ca710(&iStack_88);
      iStack_8c = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_88,&iStack_8c);
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_8c);
      FUN_004ca834(&iStack_8c,2);
      FUN_004ca834(&iStack_88,2);
      FUN_004ca710(&iStack_90);
      iStack_94 = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_90,&iStack_94);
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_94);
      FUN_004ca834(&iStack_94,2);
      FUN_004ca834(&iStack_90,2);
      FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                 *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
    }
    else if (iVar1 == 0x79) {
      FUN_004ca710(&iStack_98);
      iStack_9c = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_98,&iStack_9c);
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_9c);
      FUN_004ca834(&iStack_9c,2);
      FUN_004ca834(&iStack_98,2);
      FUN_004ca710(&iStack_a0);
      iStack_a4 = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_a0,&iStack_a4);
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_a4);
      FUN_004ca834(&iStack_a4,2);
      FUN_004ca834(&iStack_a0,2);
      FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                 *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
    }
    else if (iVar1 == 0xc9) {
      if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 100) {
        FUN_004ca710(&iStack_a8);
        iStack_ac = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_a8,&iStack_ac);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_ac);
        FUN_004ca834(&iStack_ac,2);
        FUN_004ca834(&iStack_a8,2);
        FUN_004ca710(&iStack_b0);
        iStack_b4 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_b0,&iStack_b4);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_b4);
        FUN_004ca834(&iStack_b4,2);
        FUN_004ca834(&iStack_b0,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
      else if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 1000) {
        FUN_004ca710(&iStack_b8);
        iStack_bc = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_b8,&iStack_bc);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_bc);
        FUN_004ca834(&iStack_bc,2);
        FUN_004ca834(&iStack_b8,2);
        FUN_004ca710(&iStack_c0);
        iStack_c4 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_c0,&iStack_c4);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_c4);
        FUN_004ca834(&iStack_c4,2);
        FUN_004ca834(&iStack_c0,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
    }
    else if (iVar1 == 0xca) {
      if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 100) {
        FUN_004ca710(&iStack_c8);
        iStack_cc = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_c8,&iStack_cc);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_cc);
        FUN_004ca834(&iStack_cc,2);
        FUN_004ca834(&iStack_c8,2);
        FUN_004ca710(&iStack_d0);
        iStack_d4 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_d0,&iStack_d4);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_d4);
        FUN_004ca834(&iStack_d4,2);
        FUN_004ca834(&iStack_d0,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
      else if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 1000) {
        FUN_004ca710(&iStack_d8);
        iStack_dc = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_d8,&iStack_dc);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_dc);
        FUN_004ca834(&iStack_dc,2);
        FUN_004ca834(&iStack_d8,2);
        FUN_004ca710(&iStack_e0);
        iStack_e4 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_e0,&iStack_e4);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_e4);
        FUN_004ca834(&iStack_e4,2);
        FUN_004ca834(&iStack_e0,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
    }
  }
  else if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) == 2) {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x18) = 0;
    FUN_0047c978(*(int *)(param_1 + 0x308),0);
    iVar1 = *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 8);
    if (iVar1 < 0x6a) {
      if (iVar1 == 0x69) {
        FUN_004ca710(&iStack_168);
        iStack_16c = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_168,&iStack_16c);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_16c);
        FUN_004ca834(&iStack_16c,2);
        FUN_004ca834(&iStack_168,2);
        FUN_004ca710(&iStack_170);
        iStack_174 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_170,&iStack_174);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_174);
        FUN_004ca834(&iStack_174,2);
        FUN_004ca834(&iStack_170,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
      else if (iVar1 == 0x65) {
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 0) {
          FUN_004ca710(&iStack_e8);
          iStack_ec = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_e8,&iStack_ec);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_ec);
          FUN_004ca834(&iStack_ec,2);
          FUN_004ca834(&iStack_e8,2);
          FUN_004ca710(&iStack_f0);
          iStack_f4 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_f0,&iStack_f4);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_f4);
          FUN_004ca834(&iStack_f4,2);
          FUN_004ca834(&iStack_f0,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 0x2d) {
          FUN_004ca710(&iStack_f8);
          iStack_fc = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_f8,&iStack_fc);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_fc);
          FUN_004ca834(&iStack_fc,2);
          FUN_004ca834(&iStack_f8,2);
          FUN_004ca710(&iStack_100);
          iStack_104 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_100,&iStack_104);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_104);
          FUN_004ca834(&iStack_104,2);
          FUN_004ca834(&iStack_100,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
      }
      else if (iVar1 == 0x66) {
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 100) {
          FUN_004ca710(&iStack_108);
          iStack_10c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_108,&iStack_10c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_10c);
          FUN_004ca834(&iStack_10c,2);
          FUN_004ca834(&iStack_108,2);
          FUN_004ca710(&iStack_110);
          iStack_114 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_110,&iStack_114);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_114);
          FUN_004ca834(&iStack_114,2);
          FUN_004ca834(&iStack_110,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 200) {
          FUN_004ca710(&iStack_118);
          iStack_11c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_118,&iStack_11c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_11c);
          FUN_004ca834(&iStack_11c,2);
          FUN_004ca834(&iStack_118,2);
          FUN_004ca710(&iStack_120);
          iStack_124 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_120,&iStack_124);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_124);
          FUN_004ca834(&iStack_124,2);
          FUN_004ca834(&iStack_120,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 500) {
          FUN_004ca710(&iStack_128);
          iStack_12c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_128,&iStack_12c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_12c);
          FUN_004ca834(&iStack_12c,2);
          FUN_004ca834(&iStack_128,2);
          FUN_004ca710(&iStack_130);
          iStack_134 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_130,&iStack_134);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_134);
          FUN_004ca834(&iStack_134,2);
          FUN_004ca834(&iStack_130,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
      }
      else if (iVar1 == 0x67) {
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 100) {
          FUN_004ca710(&iStack_138);
          iStack_13c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_138,&iStack_13c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_13c);
          FUN_004ca834(&iStack_13c,2);
          FUN_004ca834(&iStack_138,2);
          FUN_004ca710(&iStack_140);
          iStack_144 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_140,&iStack_144);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_144);
          FUN_004ca834(&iStack_144,2);
          FUN_004ca834(&iStack_140,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
        if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 0xfa) {
          FUN_004ca710(&iStack_148);
          iStack_14c = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_148,&iStack_14c);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_14c);
          FUN_004ca834(&iStack_14c,2);
          FUN_004ca834(&iStack_148,2);
          FUN_004ca710(&iStack_150);
          iStack_154 = 0;
          FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_150,&iStack_154);
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_154);
          FUN_004ca834(&iStack_154,2);
          FUN_004ca834(&iStack_150,2);
          FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
          (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                    (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                     *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        }
      }
      else if (iVar1 == 0x68) {
        FUN_004ca710(&iStack_158);
        iStack_15c = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_158,&iStack_15c);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_15c);
        FUN_004ca834(&iStack_15c,2);
        FUN_004ca834(&iStack_158,2);
        FUN_004ca710(&iStack_160);
        iStack_164 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_160,&iStack_164);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_164);
        FUN_004ca834(&iStack_164,2);
        FUN_004ca834(&iStack_160,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
    }
    else if (iVar1 == 0x6a) {
      FUN_004ca710(&iStack_178);
      iStack_17c = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_178,&iStack_17c);
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_17c);
      FUN_004ca834(&iStack_17c,2);
      FUN_004ca834(&iStack_178,2);
      FUN_004ca710(&iStack_180);
      iStack_184 = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_180,&iStack_184);
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_184);
      FUN_004ca834(&iStack_184,2);
      FUN_004ca834(&iStack_180,2);
      FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                 *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
    }
    else if (iVar1 == 0x79) {
      FUN_004ca710(&iStack_188);
      iStack_18c = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_188,&iStack_18c);
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_18c);
      FUN_004ca834(&iStack_18c,2);
      FUN_004ca834(&iStack_188,2);
      FUN_004ca710(&iStack_190);
      iStack_194 = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_190,&iStack_194);
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_194);
      FUN_004ca834(&iStack_194,2);
      FUN_004ca834(&iStack_190,2);
      FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
      (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                 *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
    }
    else if (iVar1 == 0xc9) {
      if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 100) {
        FUN_004ca710(&iStack_198);
        iStack_19c = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_198,&iStack_19c);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_19c);
        FUN_004ca834(&iStack_19c,2);
        FUN_004ca834(&iStack_198,2);
        FUN_004ca710(&iStack_1a0);
        iStack_1a4 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_1a0,&iStack_1a4);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_1a4);
        FUN_004ca834(&iStack_1a4,2);
        FUN_004ca834(&iStack_1a0,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
      else if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 1000) {
        FUN_004ca710(&iStack_1a8);
        iStack_1ac = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_1a8,&iStack_1ac);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_1ac);
        FUN_004ca834(&iStack_1ac,2);
        FUN_004ca834(&iStack_1a8,2);
        FUN_004ca710(&iStack_1b0);
        iStack_1b4 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_1b0,&iStack_1b4);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_1b4);
        FUN_004ca834(&iStack_1b4,2);
        FUN_004ca834(&iStack_1b0,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
    }
    else if (iVar1 == 0xca) {
      if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 100) {
        FUN_004ca710(&iStack_1b8);
        iStack_1bc = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_1b8,&iStack_1bc);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_1bc);
        FUN_004ca834(&iStack_1bc,2);
        FUN_004ca834(&iStack_1b8,2);
        FUN_004ca710(&iStack_1c0);
        iStack_1c4 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_1c0,&iStack_1c4);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_1c4);
        FUN_004ca834(&iStack_1c4,2);
        FUN_004ca834(&iStack_1c0,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
      else if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xc) == 1000) {
        FUN_004ca710(&iStack_1c8);
        iStack_1cc = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_1c8,&iStack_1cc);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4),iStack_1cc);
        FUN_004ca834(&iStack_1cc,2);
        FUN_004ca834(&iStack_1c8,2);
        FUN_004ca710(&iStack_1d0);
        iStack_1d4 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_1d0,&iStack_1d4);
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8) + 0x48))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf8),iStack_1d4);
        FUN_004ca834(&iStack_1d4,2);
        FUN_004ca834(&iStack_1d0,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        (**(code **)(**(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc) + 8))
                  (*(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc),
                   *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      }
    }
  }
  if (DAT_004f0570 != 1) {
    FUN_00410fc0(param_1);
  }
  *in_FS_OFFSET = uStack_1f8;
  return;
}



// Preserved published name: N11Click
// Entry 0042eb14, recovered name Published_N11Click_0042eb14

void Published_N11Click_0042eb14(int param_1)

{
  if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x68) == 1) {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x68) = 0;
  }
  else {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x68) = 1;
  }
  FUN_00434a60();
  FUN_00438094();
  FUN_00410fc0(param_1);
  return;
}



// Preserved published name: N12Click
// Entry 0042eb5c, recovered name Published_N12Click_0042eb5c

void Published_N12Click_0042eb5c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c);
  if ((iVar1 == 1) || (iVar1 == 2)) {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) = 0;
  }
  else {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) = 1;
  }
  FUN_00434a60();
  FUN_00438094();
  FUN_00410fc0(param_1);
  return;
}



// Preserved published name: N14Click
// Entry 0042ebb4, recovered name Published_N14Click_0042ebb4

void Published_N14Click_0042ebb4(int param_1)

{
  if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) == 2) {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) = 1;
  }
  else {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x6c) = 2;
  }
  FUN_00434a60();
  FUN_00438094();
  FUN_00410fc0(param_1);
  return;
}



// Preserved published name: N40Click
// Entry 0042ec00, recovered name Published_N40Click_0042ec00

int Published_N40Click_0042ec00(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_38;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar3 = FUN_004be6dc(0x4e5ed0);
  iVar1 = (&DAT_004fb6c0)[DAT_004f05a0];
  if (*(int *)(iVar1 + 8) == 0xd1) {
    if (*(int *)(iVar1 + 0x6c) == 0) {
      FUN_004ca710(&iStack_8);
      iStack_c = 0;
      FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_8,&iStack_c);
      (**(code **)(**(int **)(iVar1 + 0xf4) + 0x48))(*(int **)(iVar1 + 0xf4),iStack_c);
      FUN_004ca834(&iStack_c,2);
      FUN_004ca834(&iStack_8,2);
      FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
      piVar2 = *(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc);
      (**(code **)(*piVar2 + 8))(piVar2,*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
      iVar3 = (&DAT_004fb6c0)[DAT_004f05a0];
      *(undefined4 *)(iVar3 + 0x6c) = 1;
    }
    else {
      iVar1 = (&DAT_004fb6c0)[DAT_004f05a0];
      iVar3 = DAT_004f05a0;
      if (*(int *)(iVar1 + 0x6c) == 1) {
        FUN_004ca710(&iStack_10);
        iStack_14 = 0;
        FUN_004ca878((undefined4 *)&DAT_004f0564,&iStack_10,&iStack_14);
        piVar2 = *(int **)(iVar1 + 0xf4);
        (**(code **)(*piVar2 + 0x48))(piVar2,iStack_14);
        FUN_004ca834(&iStack_14,2);
        FUN_004ca834(&iStack_10,2);
        FUN_00486370(*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc));
        piVar2 = *(int **)((&DAT_004fb6c0)[DAT_004f05a0] + 0xfc);
        (**(code **)(*piVar2 + 8))(piVar2,*(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0xf4));
        iVar3 = (&DAT_004fb6c0)[DAT_004f05a0];
        *(undefined4 *)(iVar3 + 0x6c) = 0;
      }
    }
  }
  if (DAT_004f0570 != 1) {
    iVar3 = FUN_00410fc0(param_1);
  }
  *in_FS_OFFSET = uStack_38;
  return iVar3;
}



// Preserved published name: N9Click
// Entry 0042ede0, recovered name Published_N9Click_0042ede0

void Published_N9Click_0042ede0(int param_1)

{
  if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) == 0) {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) = 1;
  }
  else {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) = 0;
  }
  FUN_00410fc0(param_1);
  return;
}



// Preserved published name: N2Click
// Entry 0042ee1c, recovered name Published_N2Click_0042ee1c

void Published_N2Click_0042ee1c(int param_1)

{
  if (*(int *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) == 0) {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) = 1;
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x50) = 1;
  }
  else {
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x38) = 0;
    *(undefined4 *)((&DAT_004fb6c0)[DAT_004f05a0] + 0x50) = 0;
  }
  FUN_00434a60();
  FUN_00438094();
  FUN_00410fc0(param_1);
  return;
}



// Preserved published name: Image1DblClick
// Entry 0042ee8c, recovered name Published_Image1DblClick_0042ee8c

void Published_Image1DblClick_0042ee8c(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 local_2c;
  int local_8;
  
  FUN_004be6dc(0x4e5f00);
  iVar4 = 0;
  param_1[0xe2] = 2;
  piVar1 = &DAT_00502904;
  do {
    if (*piVar1 == 0) break;
    iVar3 = piVar1[0xd] >> 1;
    if (iVar3 < 0) {
      iVar3 = iVar3 + (uint)((piVar1[0xd] & 1U) != 0);
    }
    if (piVar1[1] - iVar3 < param_1[0xe6]) {
      iVar3 = piVar1[0xd] >> 1;
      if (iVar3 < 0) {
        iVar3 = iVar3 + (uint)((piVar1[0xd] & 1U) != 0);
      }
      if (param_1[0xe6] < iVar3 + piVar1[1]) {
        iVar3 = piVar1[0xe] >> 1;
        if (iVar3 < 0) {
          iVar3 = iVar3 + (uint)((piVar1[0xe] & 1U) != 0);
        }
        if (piVar1[2] - iVar3 < param_1[0xe7]) {
          iVar3 = piVar1[0xe] >> 1;
          if (iVar3 < 0) {
            iVar3 = iVar3 + (uint)((piVar1[0xe] & 1U) != 0);
          }
          if (param_1[0xe7] < iVar3 + piVar1[2]) {
            uVar2 = FUN_0046337c();
            iVar4 = FUN_00401b04(uVar2,extraout_EDX,extraout_ECX,param_1,iVar4 + 1);
            if (iVar4 == 0) {
              if (param_1[0xef6a] == 100) {
                piVar1 = FUN_004ca710(&local_8);
                FUN_00498434(*piVar1);
                FUN_004ca834(&local_8,2);
                Published_SpeedButton20Click_00428de8((int)param_1);
              }
              else {
                Published_SpeedButton20Click_00428de8((int)param_1);
              }
            }
            FUN_00463680();
            *in_FS_OFFSET = local_2c;
            return;
          }
        }
      }
    }
    iVar4 = iVar4 + 1;
    piVar1 = piVar1 + 0x17;
  } while (iVar4 < 100);
  *in_FS_OFFSET = local_2c;
  return;
}



// Preserved published name: FormCreate
// Entry 0042efb4, recovered name Published_FormCreate_0042efb4

void Published_FormCreate_0042efb4(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x350);
  *(undefined **)(iVar1 + 0x140) = &UNK_00403094;
  *(int *)(iVar1 + 0x144) = param_1;
  *(code **)(iVar1 + 0x148) = FUN_00402940;
  *(int *)(iVar1 + 0x14c) = param_1;
  return;
}



// Preserved published name: Timer1Timer
// Entry 0042f000, recovered name Published_Timer1Timer_0042f000

void Published_Timer1Timer_0042f000(int param_1)

{
  FUN_00429888(param_1);
  func_0x00497440(*(undefined4 *)(param_1 + 0x354),0);
  return;
}



// Preserved published name: N3Click
// Entry 0042f01c, recovered name Published_N3Click_0042f01c

void Published_N3Click_0042f01c(undefined4 param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 local_30;
  
  FUN_004be6dc(0x4e5f24);
  piVar1 = (int *)FUN_00472898((int *)PTR_PTR_004eada0,'\x01',param_1);
  *(int **)PTR__Form9_004efd70 = piVar1;
  (**(code **)(*piVar1 + 0xd8))();
  piVar1 = *(int **)PTR__Form9_004efd70;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + -4))(piVar1,3);
  }
  *in_FS_OFFSET = local_30;
  return;
}



// Preserved published name: BitBtn1Click
// Entry 004728f0, recovered name Published_BitBtn1Click_004728f0

void Published_BitBtn1Click_004728f0(int *param_1,undefined4 param_2,int param_3)

{
  FUN_00490fb8(param_1,param_2,param_3);
  return;
}



// Preserved published name: Label2Click
// Entry 004728f8, recovered name Published_Label2Click_004728f8

void Published_Label2Click_004728f8(void)

{
  ShellExecuteA(*(HWND *)(*(int *)PTR_DAT_004efd74 + 0x24),(LPCSTR)0x4ead5c,
                s_http___www_easy_edu_com_004ead61,(LPCSTR)0x0,(LPCSTR)0x0,5);
  return;
}



