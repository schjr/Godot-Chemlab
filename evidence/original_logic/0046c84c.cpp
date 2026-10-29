// Entry 0046c84c, recovered name FUN_0046c84c

void FUN_0046c84c(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int extraout_EDX;
  int iVar2;
  
  iVar2 = *(int *)(&DAT_00585850 + param_4 * 4);
  iVar1 = param_4;
  if (*(int *)(iVar2 + 0x3c74) == 1) {
    param_3 = param_4;
    iVar1 = FUN_0046b858();
    iVar2 = extraout_EDX;
  }
  FUN_00462c18(iVar1,iVar2,param_3,param_4);
  if (*(int *)(*(int *)(&DAT_00585850 + param_4 * 4) + 0x3c74) == 1) {
    FUN_0046b858();
  }
  return;
}



