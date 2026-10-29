// Entry 0044e18c, recovered name FUN_0044e18c

bool FUN_0044e18c(void)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  undefined1 local_168 [100];
  char local_104 [100];
  char local_a0 [104];
  int local_38;
  undefined4 local_30;
  undefined2 local_20;
  int local_14;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_005616fc);
  FUN_00402908(in_stack_00000004 + 0x7b7d8);
  FUN_0053493c();
  for (local_38 = 0; (local_a0[local_38] != '=' && (local_a0[local_38] != '\0'));
      local_38 = local_38 + 1) {
    local_104[local_38] = local_a0[local_38];
  }
  local_104[local_38] = '\0';
  FUN_0053493c();
  local_20 = 8;
  FUN_00540ec4(local_8,local_104);
  local_14 = local_14 + 1;
  FUN_00541018(in_stack_00000004 + 0x7b7dc,local_8);
  local_14 = local_14 + -1;
  FUN_00540fe8(local_8,2);
  local_20 = 0x14;
  FUN_00540ec4(local_c,local_168);
  local_14 = local_14 + 1;
  FUN_00541018(in_stack_00000004 + 0x7b7e0,local_c);
  local_14 = local_14 + -1;
  FUN_00540fe8(local_c,2);
  iVar1 = FUN_00417424();
  if (-1 < iVar1) {
    *(int *)(in_stack_00000004 + 0x7b7d4) = iVar1;
    *in_FS_OFFSET = local_30;
  }
  else {
    *in_FS_OFFSET = local_30;
  }
  return -1 < iVar1;
}



