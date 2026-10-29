// Entry 0044d43c, recovered name FUN_0044d43c

void FUN_0044d43c(void)

{
  int in_stack_00000008;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  while (*(char *)(in_stack_00000008 + local_8) != '\0') {
    if (*(char *)(in_stack_00000008 + local_8) == ' ') {
      for (local_c = local_8; *(char *)(in_stack_00000008 + local_c) != '\0'; local_c = local_c + 1)
      {
        *(undefined1 *)(in_stack_00000008 + local_c) =
             *(undefined1 *)(in_stack_00000008 + 1 + local_c);
      }
    }
    else {
      local_8 = local_8 + 1;
    }
  }
  return;
}



