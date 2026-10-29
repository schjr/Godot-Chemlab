// Entry 004624d8, recovered name FUN_004624d8

void FUN_004624d8(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_0058779c; local_8 = local_8 + 1) {
    if (100 < *(int *)(*(int *)(&DAT_00585850 + local_8 * 4) + 8)) {
      if (*(int *)(*(int *)(&DAT_00585850 + local_8 * 4) + 8) < 300) {
        FUN_00461e54();
      }
    }
  }
  return;
}



