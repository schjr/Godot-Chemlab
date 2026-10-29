// Entry 004028ec, recovered name FUN_004028ec

int FUN_004028ec(void)

{
  int iVar1;
  int in_stack_00000004;
  
  if (in_stack_00000004 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00539c60();
    iVar1 = iVar1 % in_stack_00000004;
  }
  return iVar1;
}



