0x00402928 FUN_00402928 recovered/native/main/decompiled.cpp:868
// Entry 00402928, recovered name FUN_00402928

undefined4
FUN_00402928(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  char cVar1;
  LPCSTR pCVar2;
  undefined4 *puVar3;
  HWND hwnd;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  LPCSTR lpOperation;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  char *pcVar5;
  UINT fuSound;
  INT nShowCmd;
  undefined1 *puVar6;
  undefined4 uVar7;
  char local_1610 [992];
  char acStack_1230 [556];
  undefined4 uStack_1004;
  char acStack_e49 [9];
  char local_e40 [1000];
  char local_a58 [2200];
  char local_1c0 [100];
  char local_15c [100];
  char local_f8 [5];
  char acStack_f3 [4];
  char acStack_ef [91];
  int local_94;
  int local_90;
  LPCSTR local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_70;
  undefined4 local_6c;
  undefined2 local_5c;
  int local_50;
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
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  uStack_1004 = param_1;
  FUN_00534be0(&DAT_00561334);
  local_5c = 8;
  FUN_004016e8(local_8);
  local_50 = local_50 + 1;
  local_70 = param_5;
  *(int *)(param_4 + 0x3c024) = param_5;
  local_5c = 0x20;
  local_78 = 0;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                while( true ) {
                  if (*(int *)(param_4 + 0x5dd8 + local_70 * 0x7e0) <= local_78) {
                    uVar7 = 1;
                    local_50 = local_50 + -1;
                    FUN_00540fe8(local_8,2);
                    *in_FS_OFFSET = local_6c;
                    return uVar7;
                  }
                  FUN_00541018(local_8,local_70 * 0x7e0 + param_4 + local_78 * 4 + 0x5de8);
                  FUN_00402908(local_8);
                  FUN_0053493c();
                  FUN_0044d43c();
                  cVar1 = FUN_0044d498();
                  if (cVar1 != '\x01') break;
                  for (local_7c = 0; local_f8[local_7c] != ':'; local_7c = local_7c + 1) {
                    local_15c[local_7c] = local_f8[local_7c];
                  }
                  local_15c[local_7c] = '\0';
                  FUN_0053493c();
                  FUN_0053493c();
                  FUN_005348b4();
                  for (; local_f8[local_7c] != '('; local_7c = local_7c + 1) {
                  }
                  FUN_0053493c();
                  for (local_7c = 0; local_1c0[local_7c] != '\0'; local_7c = local_7c + 1) {
                  }
                  for (; local_1c0[local_7c] != ')'; local_7c = local_7c + -1) {
                    local_1c0[local_7c] = '\0';
                  }
                  local_1c0[local_7c] = '\0';
                  local_1c0[local_7c] = '\0';
                  local_5c = 0x2c;
                  FUN_00540ec4(local_c,local_1c0);
                  local_50 = local_50 + 1;
                  local_80 = FUN_0044d4f8();
                  local_50 = local_50 + -1;
                  FUN_00540fe8(local_c,2);
                  if (local_80 == -1) {
                    *(undefined4 *)(param_4 + 0x3c018) = 0x1e;
                    *(int *)(param_4 + 0x3c01c) = local_70;
                    *(int *)(param_4 + 0x3c020) = local_78;
                    uVar7 = 0;
                    local_50 = local_50 + -1;
                    FUN_00540fe8(local_8,2);
                    *in_FS_OFFSET = local_6c;
                    return uVar7;
                  }
                  if (local_80 == 1) {
                    local_78 = local_78 + 1;
                  }
                  else {
                    while( true ) {
                      pcVar5 = local_15c;
                      local_5c = 0x38;
                      uVar7 = FUN_004016e8(local_10);
                      local_50 = local_50 + 1;
                      FUN_00541270(local_70 * 0x7e0 + param_4 + local_78 * 4 + 0x5de8,uVar7,
                                   local_78 * 4,pcVar5);
                      FUN_00402908(local_10);
                      cVar1 = FUN_0044d498();
                      if ((cVar1 == '\0') &&
                         (local_78 < *(int *)(param_4 + 0x5dd8 + local_70 * 0x7e0))) {
                        iVar4 = 1;
                      }
                      else {
                        iVar4 = 0;
                      }
                      local_50 = local_50 + -1;
                      FUN_00540fe8(local_10,2);
                      if (iVar4 == 0) break;
                      local_78 = local_78 + 1;
                    }
                    if (*(int *)(param_4 + 0x5dd8 + local_70 * 0x7e0) <= local_78) {
                      *(undefined4 *)(param_4 + 0x3c018) = 0x1f;
                      *(int *)(param_4 + 0x3c01c) = local_70;
                      *(int *)(param_4 + 0x3c020) = local_78;
                      uVar7 = 0;
                      local_50 = local_50 + -1;
                      FUN_00540fe8(local_8,2);
                      *in_FS_OFFSET = local_6c;
                      return uVar7;
                    }
                    local_78 = local_78 + 1;
                  }
                }
                cVar1 = FUN_0044d498();
                if (cVar1 != '\x01') break;
                for (local_7c = 0; local_f8[local_7c] != ':'; local_7c = local_7c + 1) {
                  local_15c[local_7c] = local_f8[local_7c];
                }
                local_15c[local_7c] = '\0';
                FUN_0053493c();
                FUN_0053493c();
                FUN_005348b4();
                for (; local_f8[local_7c] != '('; local_7c = local_7c + 1) {
                }
                FUN_0053493c();
                for (local_7c = 0; local_1c0[local_7c] != '\0'; local_7c = local_7c + 1) {
                }
                for (; local_1c0[local_7c] != ')'; local_7c = local_7c + -1) {
                  local_1c0[local_7c] = '\0';
                }
                local_1c0[local_7c] = '\0';
                local_1c0[local_7c] = '\0';
                local_5c = 0x44;
                FUN_00540ec4(local_14,local_1c0);
                local_50 = local_50 + 1;
                local_80 = FUN_0044d4f8();
                local_50 = local_50 + -1;
                FUN_00540fe8(local_14,2);
                if (local_80 == -1) {
                  *(undefined4 *)(param_4 + 0x3c018) = 0x28;
                  *(int *)(param_4 + 0x3c01c) = local_70;
                  *(int *)(param_4 + 0x3c020) = local_78;
                  uVar7 = 0;
                  local_50 = local_50 + -1;
                  FUN_00540fe8(local_8,2);
                  *in_FS_OFFSET = local_6c;
                  return uVar7;
                }
                if (local_80 == 1) {
                  local_78 = local_78 + 1;
                }
                else {
                  while( true ) {
                    pcVar5 = local_15c;
                    local_5c = 0x50;
                    uVar7 = FUN_004016e8(local_18);
                    local_50 = local_50 + 1;
                    FUN_00541270(local_70 * 0x7e0 + param_4 + local_78 * 4 + 0x5de8,uVar7,
                                 local_78 * 4,pcVar5);
                    FUN_00402908(local_18);
                    cVar1 = FUN_0044d498();
                    if ((cVar1 == '\0') &&
                       (local_78 < *(int *)(param_4 + 0x5dd8 + local_70 * 0x7e0))) {
                      iVar4 = 1;
                    }
                    else {
                      iVar4 = 0;
                    }
                    local_50 = local_50 + -1;
                    FUN_00540fe8(local_18,2);
                    if (iVar4 == 0) break;
                    local_78 = local_78 + 1;
                  }
                  if (*(int *)(param_4 + 0x5dd8 + local_70 * 0x7e0) <= local_78) {
                    *(undefined4 *)(param_4 + 0x3c018) = 0x29;
                    *(int *)(param_4 + 0x3c01c) = local_70;
                    *(int *)(param_4 + 0x3c020) = local_78;
                    uVar7 = 0;
                    local_50 = local_50 + -1;
                    FUN_00540fe8(local_8,2);
                    *in_FS_OFFSET = local_6c;
                    return uVar7;
                  }
                  local_78 = local_78 + 1;
                }
              }
              cVar1 = FUN_0044d498();
              if (cVar1 != '\x01') break;
              local_78 = local_78 + 1;
            }
            cVar1 = FUN_0044d498();
            if (cVar1 != '\x01') break;
            FUN_0053493c();
            while( true ) {
              FUN_00402908(local_70 * 0x7e0 + param_4 + local_78 * 4 + 0x5de8);
              cVar1 = FUN_0044d498();
              if ((cVar1 != '\0') || (local_78 < 1)) break;
              local_78 = local_78 + -1;
            }
          }
          cVar1 = FUN_0044d498();
          if (cVar1 != '\x01') break;
          local_78 = local_78 + 1;
        }
        cVar1 = FUN_0044d498();
        if (cVar1 != '\x01') break;
        local_78 = local_78 + 1;
      }
      cVar1 = FUN_0044d498();
      if (cVar1 == '\x01') break;
      cVar1 = FUN_0044d498();
      if (cVar1 == '\x01') {
        local_5c = 0xa4;
        FUN_004016e8(local_2c);
        local_50 = local_50 + 1;
        local_5c = 0xb0;
        for (local_90 = 5; local_f8[local_90] != ')'; local_90 = local_90 + 1) {
          acStack_1230[local_90 + 3] = local_f8[local_90];
        }
        acStack_1230[local_90 + 3] = '\0';
        if ((((acStack_1230[local_90 + 2] == 'm') || (acStack_1230[local_90 + 2] == 'M')) &&
            ((acStack_1230[local_90 + 1] == 'e' || (acStack_1230[local_90 + 1] == 'E')))) &&
           ((acStack_1230[local_90] == 'c' || (acStack_1230[local_90] == 'C')))) {
          local_5c = 0xbc;
          puVar3 = (undefined4 *)FUN_00540ec4(local_30,acStack_1230 + 8);
          local_50 = local_50 + 1;
          FUN_0040461c(param_4,*puVar3);
          local_50 = local_50 + -1;
          FUN_00540fe8(local_30,2);
        }
        else {
          cVar1 = FUN_0044d498();
          if ((cVar1 != '\x01') && (cVar1 = FUN_0044d498(), cVar1 != '\x01')) {
            local_5c = 200;
            FUN_00540ec4(local_34,&DAT_00557a87);
            local_50 = local_50 + 1;
            cVar1 = FUN_005410cc(param_4 + 0x5d4,local_34);
            local_50 = local_50 + -1;
            FUN_00540fe8(local_34,2);
            if (cVar1 == '\0') {
              FUN_00402908(param_4 + 0x5d4);
              FUN_0053493c();
              local_94 = FUN_0053496c();
              for (local_90 = local_94; local_1610[local_90] != '\\'; local_90 = local_90 + -1) {
              }
              local_1610[local_90] = '\0';
              FUN_005348b4();
              FUN_005348b4();
              FUN_0053493c();
            }
            else {
              local_5c = 0xd4;
              puVar3 = (undefined4 *)FUN_00540ec4(local_38,&DAT_00557a88);
              local_50 = local_50 + 1;
              FUN_00500350(*puVar3);
              local_50 = local_50 + -1;
              FUN_00540fe8(local_38,2);
            }
          }
        }
        local_5c = 0xe0;
        FUN_00540ec4(local_3c,acStack_1230 + 8);
        local_50 = local_50 + 1;
        FUN_00541018(local_2c,local_3c);
        local_50 = local_50 + -1;
        FUN_00540fe8(local_3c,2);
        pCVar2 = (LPCSTR)FUN_00402908(local_2c);
        local_8c = pCVar2;
        if ((((acStack_1230[local_90 + 2] != 'm') && (acStack_1230[local_90 + 2] != 'M')) ||
            ((acStack_1230[local_90 + 1] != 'e' && (acStack_1230[local_90 + 1] != 'E')))) ||
           ((acStack_1230[local_90] != 'c' && (acStack_1230[local_90] != 'C')))) {
          nShowCmd = 1;
          lpDirectory = &DAT_00557aa5;
          lpParameters = &DAT_00557aa4;
          lpOperation = &DAT_00557a9f;
          hwnd = (HWND)FUN_0050b540(param_4);
          ShellExecuteA(hwnd,lpOperation,pCVar2,lpParameters,lpDirectory,nShowCmd);
        }
        local_78 = local_78 + 1;
        local_50 = local_50 + -1;
        FUN_00540fe8(local_2c,2);
        local_5c = 0x20;
      }
      else {
        cVar1 = FUN_0044d498();
        if (cVar1 == '\x01') {
          FUN_0052d7f8();
          local_78 = local_78 + 1;
        }
        else {
          cVar1 = FUN_0044d498();
          if (cVar1 == '\x01') {
            FUN_0043ddd8(param_4,*(undefined4 *)(param_4 + 0x404));
            local_78 = local_78 + 1;
          }
          else {
            cVar1 = FUN_0044d498();
            if (cVar1 == '\x01') {
              FUN_0043e794(param_4,*(undefined4 *)(param_4 + 0x400));
              local_78 = local_78 + 1;
            }
            else {
              cVar1 = FUN_0044d498();
              if (cVar1 == '\x01') {
                FUN_0043de5c(param_4,*(undefined4 *)(param_4 + 0x3fc));
                local_78 = local_78 + 1;
              }
              else {
                cVar1 = FUN_0044d498();
                if (cVar1 == '\x01') {
                  FUN_0053ba00();
                  local_78 = local_78 + 1;
                }
                else {
                  FUN_00540ec4(local_44,&DAT_00557ac7);
                  local_50 = local_50 + 1;
                  puVar6 = local_44;
                  local_5c = 0xec;
                  uVar7 = FUN_00540ec4(local_40,local_f8);
                  local_50 = local_50 + 1;
                  cVar1 = FUN_005410e4(uVar7,puVar6);
                  local_50 = local_50 + -1;
                  FUN_00540fe8(local_44,2);
                  local_50 = local_50 + -1;
                  FUN_00540fe8(local_40,2);
                  if (cVar1 != '\0') {
                    local_5c = 0xf8;
                    FUN_00540ec4(local_48,local_f8);
                    local_50 = local_50 + 1;
                    cVar1 = FUN_0044dacc();
                    cVar1 = cVar1 == '\0';
                    local_50 = local_50 + -1;
                    FUN_00540fe8(local_48,2);
                    if (cVar1 != '\0') {
                      *(undefined4 *)(param_4 + 0x3c018) = 5;
                      *(int *)(param_4 + 0x3c01c) = local_70;
                      *(int *)(param_4 + 0x3c020) = local_78;
                      uVar7 = 0;
                      local_50 = local_50 + -1;
                      FUN_00540fe8(local_8,2);
                      *in_FS_OFFSET = local_6c;
                      return uVar7;
                    }
                  }
                  local_78 = local_78 + 1;
                }
              }
            }
          }
        }
      }
    }
    local_5c = 0x5c;
    FUN_00540ec4(local_20,&DAT_00557a73);
    local_50 = local_50 + 1;
    cVar1 = FUN_005410cc(param_4 + 0x5d4,local_20);
    local_50 = local_50 + -1;
    FUN_00540fe8(local_20,2);
    if (cVar1 != '\0') {
      *(undefined4 *)(param_4 + 0x3c018) = 100;
      *(int *)(param_4 + 0x3c01c) = local_70;
      *(int *)(param_4 + 0x3c020) = local_78;
      uVar7 = 0;
      local_50 = local_50 + -1;
      FUN_00540fe8(local_8,2);
      *in_FS_OFFSET = local_6c;
      return uVar7;
    }
    for (local_84 = 9; local_f8[local_84] != ')'; local_84 = local_84 + 1) {
      acStack_e49[local_84] = local_f8[local_84];
    }
    acStack_e49[local_84] = '\0';
    local_5c = 0x68;
    FUN_004016e8(local_1c);
    local_50 = local_50 + 1;
    local_5c = 0x80;
    FUN_00540ec4(local_24,local_e40);
    local_50 = local_50 + 1;
    FUN_00541018(local_1c,local_24);
    local_50 = local_50 + -1;
    FUN_00540fe8(local_24,2);
    FUN_00402908(param_4 + 0x5d4);
    FUN_0053493c();
    local_84 = 0;
    do {
      if (local_a58[local_84] == '\0') {
        local_88 = local_84;
        goto joined_r0x00403143;
      }
      local_84 = local_84 + 1;
    } while (local_84 < 2000);
LAB_00403185:
    fuSound = 1;
    local_5c = 0x98;
    uVar7 = FUN_004016e8(local_28);
    local_50 = local_50 + 1;
    FUN_0054139c(local_a58,local_1c,uVar7);
    pCVar2 = (LPCSTR)FUN_00402908(local_28);
    sndPlaySoundA(pCVar2,fuSound);
    local_50 = local_50 + -1;
    FUN_00540fe8(local_28,2);
    local_5c = 0x74;
    local_78 = local_78 + 1;
    local_50 = local_50 + -1;
    FUN_00540fe8(local_1c,2);
    local_5c = 0x20;
  } while( true );
joined_r0x00403143:
  if (local_88 < 1) goto LAB_00403185;
  if (local_a58[local_88] == '\\') {
    local_a58[local_88 + 1] = '\0';
    goto LAB_00403185;
  }
  local_88 = local_88 + -1;
  goto joined_r0x00403143;
}




