0x0044dc68 FUN_0044dc68 recovered/native/main/decompiled.cpp:21246
// Entry 0044dc68, recovered name FUN_0044dc68

undefined4 FUN_0044dc68(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST0;
  undefined4 in_stack_00000008;
  undefined8 local_188;
  undefined1 local_180 [100];
  char local_11c [99];
  char acStack_b9 [101];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  double local_40;
  double local_38;
  undefined4 local_30;
  undefined2 local_20;
  int local_14;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  local_188 = (double)CONCAT44(0x44dc7b,(undefined4)local_188);
  FUN_00534be0(&DAT_005616bc);
  local_188 = (double)CONCAT44(in_stack_00000008,acStack_b9 + 1);
  FUN_0053493c();
  local_50 = 0;
  local_188 = (double)CONCAT44(acStack_b9 + 1,0x44dc9e);
  local_48 = FUN_0053496c();
  if ((acStack_b9[1] == '(') && (acStack_b9[local_48] == ')')) {
    local_50 = 1;
    for (local_44 = 1; acStack_b9[local_44 + 1] != '\0'; local_44 = local_44 + 1) {
      if (acStack_b9[local_44 + 1] == '(') {
        local_50 = local_50 + 1;
      }
      else if (acStack_b9[local_44 + 1] == ')') {
        local_50 = local_50 + -1;
      }
      if (local_50 == 0) break;
    }
    if (local_48 + -1 == local_44) {
      local_48 = 1;
      if (1 < local_44) {
        do {
          acStack_b9[local_48] = acStack_b9[local_48 + 1];
          local_48 = local_48 + 1;
        } while (local_48 < local_44);
      }
      acStack_b9[local_48] = '\0';
    }
  }
  local_44 = 0;
  while( true ) {
    if (acStack_b9[local_44 + 1] == '\0') goto LAB_0044df58;
    if ((acStack_b9[local_44 + 2] == '=') &&
       (((acStack_b9[local_44 + 1] == '>' || (acStack_b9[local_44 + 1] == '<')) ||
        (acStack_b9[local_44 + 1] == '!')))) break;
    if (((acStack_b9[local_44 + 1] == '>') || (acStack_b9[local_44 + 1] == '<')) ||
       (acStack_b9[local_44 + 1] == '=')) {
      local_48 = 0;
      if (0 < local_44) {
        do {
          local_11c[local_48] = acStack_b9[local_48 + 1];
          local_48 = local_48 + 1;
        } while (local_48 < local_44);
      }
      local_11c[local_48] = '\0';
      for (local_48 = local_44 + 1; acStack_b9[local_48 + 1] != '\0'; local_48 = local_48 + 1) {
        local_180[(local_48 - local_44) + -1] = acStack_b9[local_48 + 1];
      }
      local_180[(local_48 - local_44) + -1] = 0;
      if (acStack_b9[local_44 + 1] == '>') {
        local_4c = 1;
      }
      else if (acStack_b9[local_44 + 1] == '<') {
        local_4c = 2;
      }
      else if (acStack_b9[local_44 + 1] == '=') {
        local_4c = 3;
      }
      goto LAB_0044df58;
    }
    local_44 = local_44 + 1;
  }
  local_48 = 0;
  if (0 < local_44) {
    do {
      local_11c[local_48] = acStack_b9[local_48 + 1];
      local_48 = local_48 + 1;
    } while (local_48 < local_44);
  }
  local_11c[local_48] = '\0';
  local_188 = (double)CONCAT44(acStack_b9 + local_44 + 3,local_180);
  FUN_0053493c();
  if (acStack_b9[local_44 + 1] == '>') {
    local_4c = 4;
  }
  else if (acStack_b9[local_44 + 1] == '<') {
    local_4c = 5;
  }
  else if (acStack_b9[local_44 + 1] == '!') {
    local_4c = 6;
  }
LAB_0044df58:
  local_188._4_4_ = &local_38;
  local_20 = 8;
  local_188._0_4_ = 0x44df70;
  puVar1 = (undefined4 *)FUN_00540ec4(local_8,local_11c);
  local_14 = local_14 + 1;
  local_188 = (double)CONCAT44(local_188._4_4_,*puVar1);
  local_54 = FUN_0044e2d8();
  local_14 = local_14 + -1;
  local_188 = (double)CONCAT44(0x44df93,(undefined4)local_188);
  FUN_00540fe8(local_8,2);
  if (local_54 == -1) {
    uVar2 = 0;
    *in_FS_OFFSET = local_30;
  }
  else if (local_54 == 0) {
    uVar2 = 0xffffffff;
    *in_FS_OFFSET = local_30;
  }
  else {
    local_188._4_4_ = &local_40;
    local_20 = 0x14;
    local_188._0_4_ = 0x44dfda;
    puVar1 = (undefined4 *)FUN_00540ec4(local_c,local_180);
    local_14 = local_14 + 1;
    local_188 = (double)CONCAT44(local_188._4_4_,*puVar1);
    local_54 = FUN_0044e2d8();
    local_14 = local_14 + -1;
    local_188 = (double)CONCAT44(0x44dffd,(undefined4)local_188);
    FUN_00540fe8(local_c,2);
    if (local_54 == -1) {
      uVar2 = 0;
      *in_FS_OFFSET = local_30;
    }
    else if (local_54 == 0) {
      uVar2 = 0xffffffff;
      *in_FS_OFFSET = local_30;
    }
    else if (local_4c == 1) {
      if (local_38 <= local_40) {
        uVar2 = 0;
        *in_FS_OFFSET = local_30;
      }
      else {
        uVar2 = 1;
        *in_FS_OFFSET = local_30;
      }
    }
    else if (local_4c == 2) {
      if (local_40 <= local_38) {
        uVar2 = 0;
        *in_FS_OFFSET = local_30;
      }
      else {
        uVar2 = 1;
        *in_FS_OFFSET = local_30;
      }
    }
    else if (local_4c == 3) {
      local_188 = local_38 - local_40;
      FUN_005394d4();
      if ((longdouble)0.01 <= in_ST0) {
        uVar2 = 0;
        *in_FS_OFFSET = local_30;
      }
      else {
        uVar2 = 1;
        *in_FS_OFFSET = local_30;
      }
    }
    else if (local_4c == 4) {
      if (local_38 < local_40) {
        uVar2 = 0;
        *in_FS_OFFSET = local_30;
      }
      else {
        uVar2 = 1;
        *in_FS_OFFSET = local_30;
      }
    }
    else if (local_4c == 5) {
      if (local_40 < local_38) {
        uVar2 = 0;
        *in_FS_OFFSET = local_30;
      }
      else {
        uVar2 = 1;
        *in_FS_OFFSET = local_30;
      }
    }
    else if (local_4c == 6) {
      if (local_38 == local_40) {
        uVar2 = 0;
        *in_FS_OFFSET = local_30;
      }
      else {
        uVar2 = 1;
        *in_FS_OFFSET = local_30;
      }
    }
    else {
      uVar2 = 0;
      *in_FS_OFFSET = local_30;
    }
  }
  return uVar2;
}




