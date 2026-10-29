// Entry 0048e418, recovered name FUN_0048e418

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048e418(void)

{
  int iVar1;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble lVar2;
  double local_14;
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_0058779c; local_8 = local_8 + 1) {
    local_14 = (double)*(int *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x3c78);
    if (local_14 < 1.0) {
      local_14 = 1.0;
    }
    if (19.0 < local_14) {
      local_14 = 19.0;
    }
    lVar2 = in_ST6;
    FUN_005394d4();
    if ((longdouble)0.1 <= in_ST0) {
      if (local_14 <= 10.0) {
        if (local_14 < 10.0) {
          local_14 = (double)(_DAT_0048e680 * (longdouble)local_14);
        }
      }
      else {
        local_14 = local_14 - 9.0;
      }
    }
    else {
      local_14 = 1.0;
    }
    iVar1 = *(int *)(*(int *)(&DAT_00585850 + local_8 * 4) + 8);
    if (((iVar1 - 0x65U < 6) || (iVar1 == 0x6c)) || (iVar1 == 0x79)) {
      if (*(int *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0xa0) == 1) {
        if (*(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x4320) <= 0.001) {
          *(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88) =
               (double)((float)_DAT_005636d4 * 50.0 * (float)local_14 +
                       (float)*(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88));
          if (800.0 < *(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88)) {
            iVar1 = *(int *)(&DAT_00585850 + local_8 * 4);
            *(undefined4 *)(iVar1 + 0x88) = 0;
            *(undefined4 *)(iVar1 + 0x8c) = 0x40890000;
          }
        }
        else {
          *(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88) =
               (double)((float)_DAT_005636d4 * 5.0 * (float)local_14 +
                       (float)*(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88));
          if (100.0 < *(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88)) {
            iVar1 = *(int *)(&DAT_00585850 + local_8 * 4);
            *(undefined4 *)(iVar1 + 0x88) = 0;
            *(undefined4 *)(iVar1 + 0x8c) = 0x40590000;
          }
        }
      }
      if ((*(int *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0xa0) == 0) &&
         (*(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88) =
               (double)((float)*(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88) -
                       (float)_DAT_005636d4 * 5.0 * (float)local_14),
         *(double *)(*(int *)(&DAT_00585850 + local_8 * 4) + 0x88) < 20.0)) {
        iVar1 = *(int *)(&DAT_00585850 + local_8 * 4);
        *(undefined4 *)(iVar1 + 0x88) = 0;
        *(undefined4 *)(iVar1 + 0x8c) = 0x40340000;
      }
    }
    in_ST0 = in_ST1;
    in_ST1 = in_ST2;
    in_ST2 = in_ST3;
    in_ST3 = in_ST4;
    in_ST4 = in_ST5;
    in_ST5 = in_ST6;
    in_ST6 = lVar2;
  }
  return;
}



