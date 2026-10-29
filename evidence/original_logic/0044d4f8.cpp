// Entry 0044d4f8, recovered name FUN_0044d4f8

int FUN_0044d4f8(void)

{
  char cVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  char acStack_129 [100];
  char acStack_c5 [101];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined2 local_30;
  int local_24;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_005615dc);
  local_24 = 1;
  FUN_00540efc(&stack0x00000008,&stack0x00000008);
  local_24 = local_24 + 1;
  local_30 = 8;
  local_5c = 1;
  local_48 = 0;
  local_54 = 0;
  FUN_00402908(&stack0x00000008);
  FUN_0053493c();
  local_58 = 0;
  local_48 = FUN_0053496c();
  if ((acStack_c5[1] == '(') && (acStack_c5[local_48] == ')')) {
    local_58 = 1;
    for (local_44 = 1; acStack_c5[local_44 + 1] != '\0'; local_44 = local_44 + 1) {
      if (acStack_c5[local_44 + 1] == '(') {
        local_58 = local_58 + 1;
      }
      else if (acStack_c5[local_44 + 1] == ')') {
        local_58 = local_58 + -1;
      }
      if (local_58 == 0) break;
    }
    if (local_48 + -1 == local_44) {
      local_48 = 1;
      if (1 < local_44) {
        do {
          acStack_c5[local_48] = acStack_c5[local_48 + 1];
          local_48 = local_48 + 1;
        } while (local_48 < local_44);
      }
      acStack_c5[local_48] = '\0';
    }
  }
  local_44 = 0;
  while (((acStack_c5[local_44 + 1] != '\0' && (cVar1 = FUN_0044d498(), cVar1 != '\x01')) &&
         (cVar1 = FUN_0044d498(), cVar1 != '\x01'))) {
    local_44 = local_44 + 1;
  }
  if (acStack_c5[local_44 + 1] == '\0') {
    iVar2 = FUN_0044dc68();
    local_24 = local_24 + -1;
    FUN_00540fe8(&stack0x00000008,2);
    *in_FS_OFFSET = local_40;
  }
  else {
    local_48 = 0;
    local_58 = 0;
    for (local_44 = 0; acStack_c5[local_44 + 1] != '\0'; local_44 = local_44 + 1) {
      if (acStack_c5[local_44 + 1] == '(') {
        local_58 = local_58 + 1;
      }
      else if (acStack_c5[local_44 + 1] == ')') {
        local_58 = local_58 + -1;
      }
      acStack_129[local_48 + 1] = acStack_c5[local_44 + 1];
      local_48 = local_48 + 1;
      if ((local_58 == 0) && (cVar1 = FUN_0044d498(), cVar1 == '\x01')) {
        acStack_129[local_48] = '\0';
        local_48 = 0;
        if (local_54 == 0) {
          local_30 = 0x14;
          FUN_00540ec4(local_8,acStack_129 + 1);
          local_24 = local_24 + 1;
          local_60 = FUN_0044d4f8();
          local_24 = local_24 + -1;
          FUN_00540fe8(local_8,2);
          if (local_60 == -1) {
            local_24 = local_24 + -1;
            FUN_00540fe8(&stack0x00000008,2);
            *in_FS_OFFSET = local_40;
            return -1;
          }
          if ((local_5c == 0) || (local_60 == 0)) {
            local_5c = 0;
          }
          else {
            local_5c = 1;
          }
        }
        else if (local_54 == 1) {
          local_30 = 0x20;
          FUN_00540ec4(local_c,acStack_129 + 1);
          local_24 = local_24 + 1;
          local_60 = FUN_0044d4f8();
          local_24 = local_24 + -1;
          FUN_00540fe8(local_c,2);
          if (local_60 == -1) {
            local_24 = local_24 + -1;
            FUN_00540fe8(&stack0x00000008,2);
            *in_FS_OFFSET = local_40;
            return -1;
          }
          if ((local_5c == 0) && (local_60 == 0)) {
            local_5c = 0;
          }
          else {
            local_5c = 1;
          }
        }
        local_54 = 0;
        local_44 = local_44 + 1;
      }
      if ((local_58 == 0) && (cVar1 = FUN_0044d498(), cVar1 == '\x01')) {
        acStack_129[local_48] = '\0';
        local_48 = 0;
        if (local_54 == 0) {
          local_30 = 0x2c;
          FUN_00540ec4(local_10,acStack_129 + 1);
          local_24 = local_24 + 1;
          local_60 = FUN_0044d4f8();
          local_24 = local_24 + -1;
          FUN_00540fe8(local_10,2);
          if (local_60 == -1) {
            local_24 = local_24 + -1;
            FUN_00540fe8(&stack0x00000008,2);
            *in_FS_OFFSET = local_40;
            return -1;
          }
          if ((local_5c == 0) || (local_60 == 0)) {
            local_5c = 0;
          }
          else {
            local_5c = 1;
          }
        }
        else if (local_54 == 1) {
          local_30 = 0x38;
          FUN_00540ec4(local_14,acStack_129 + 1);
          local_24 = local_24 + 1;
          local_60 = FUN_0044d4f8();
          local_24 = local_24 + -1;
          FUN_00540fe8(local_14,2);
          if (local_60 == -1) {
            local_24 = local_24 + -1;
            FUN_00540fe8(&stack0x00000008,2);
            *in_FS_OFFSET = local_40;
            return -1;
          }
          if ((local_5c == 0) && (local_60 == 0)) {
            local_5c = 0;
          }
          else {
            local_5c = 1;
          }
        }
        local_54 = 1;
        local_44 = local_44 + 1;
      }
    }
    acStack_129[local_48 + 1] = '\0';
    local_48 = 0;
    if (local_54 == 0) {
      local_30 = 0x44;
      FUN_00540ec4(local_18,acStack_129 + 1);
      local_24 = local_24 + 1;
      local_60 = FUN_0044d4f8();
      local_24 = local_24 + -1;
      FUN_00540fe8(local_18,2);
      if (local_60 == -1) {
        local_24 = local_24 + -1;
        FUN_00540fe8(&stack0x00000008,2);
        *in_FS_OFFSET = local_40;
        return -1;
      }
      if ((local_5c == 0) || (local_60 == 0)) {
        local_5c = 0;
      }
      else {
        local_5c = 1;
      }
    }
    else if (local_54 == 1) {
      local_30 = 0x50;
      FUN_00540ec4(local_1c,acStack_129 + 1);
      local_24 = local_24 + 1;
      local_60 = FUN_0044d4f8();
      local_24 = local_24 + -1;
      FUN_00540fe8(local_1c,2);
      if (local_60 == -1) {
        local_24 = local_24 + -1;
        FUN_00540fe8(&stack0x00000008,2);
        *in_FS_OFFSET = local_40;
        return -1;
      }
      if ((local_5c == 0) && (local_60 == 0)) {
        local_5c = 0;
      }
      else {
        local_5c = 1;
      }
    }
    iVar2 = local_5c;
    local_24 = local_24 + -1;
    FUN_00540fe8(&stack0x00000008,2);
    *in_FS_OFFSET = local_40;
  }
  return iVar2;
}



