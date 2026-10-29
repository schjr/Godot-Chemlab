// Entry 0048e9b4, recovered name FUN_0048e9b4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048e9b4(void)

{
  double dVar1;
  double dVar2;
  char cVar3;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar5;
  int local_68;
  int local_64;
  double local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_00567284);
  for (local_64 = 0; local_64 < DAT_0058779c; local_64 = local_64 + 1) {
    FUN_00540ec4(local_8,&DAT_00563edf);
    local_40 = FUN_00461db4();
    FUN_00540fe8(local_8,2);
    if (local_40 == -1) {
      local_40 = *(int *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x104);
      *(int *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x104) =
           *(int *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x104) + 1;
    }
    FUN_00540ec4(local_c,&DAT_00563eee);
    FUN_00541018(*(int *)(&DAT_00585850 + local_64 * 4) + local_40 * 4 + 0x108,local_c);
    FUN_00540fe8(local_c,2);
    iVar4 = *(int *)(&DAT_00585850 + local_64 * 4);
    *(undefined4 *)(iVar4 + 0x8d8 + local_40 * 8) = 0;
    *(undefined4 *)(iVar4 + 0x8dc + local_40 * 8) = 0;
    iVar4 = *(int *)(&DAT_00585850 + local_64 * 4);
    *(undefined4 *)(iVar4 + 0x298 + local_40 * 8) = 0;
    *(undefined4 *)(iVar4 + 0x29c + local_40 * 8) = 0;
    iVar4 = *(int *)(&DAT_00585850 + local_64 * 4);
    *(undefined4 *)(iVar4 + 0x5b8 + local_40 * 8) = 0;
    *(undefined4 *)(iVar4 + 0x5bc + local_40 * 8) = 0;
    dVar1 = *(double *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x28) -
            *(double *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x4320);
    local_48 = 0.0;
    for (local_68 = 0; local_68 < *(int *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x104);
        local_68 = local_68 + 1) {
      FUN_004016e8(local_10,local_68,local_64,
                   *(undefined4 *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x108 + local_68 * 4));
      FUN_00452acc();
      puVar5 = local_10;
      FUN_00540ec4(local_14,&DAT_00563efd);
      cVar3 = FUN_005410cc(puVar5,local_14);
      FUN_00540fe8(local_14,2);
      FUN_00540fe8(local_10,2);
      if (cVar3 != '\0') {
        local_48 = *(double *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x8d8 + local_68 * 8) +
                   local_48;
      }
    }
    dVar2 = local_48 * 22.4 * 1000.0;
    if (dVar2 < dVar1) {
      *(double *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x8d8 + local_40 * 8) =
           (double)(_DAT_0048ec88 * _DAT_0048ec7c * (longdouble)(dVar1 - dVar2));
      FUN_00540ec4(local_18,&DAT_00563f04);
      iVar4 = FUN_00452d9c();
      *(double *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x298 + local_40 * 8) =
           *(double *)((&DAT_0057bc08)[iVar4] + 0x10) *
           *(double *)(*(int *)(&DAT_00585850 + local_64 * 4) + 0x8d8 + local_40 * 8);
      FUN_00540fe8(local_18,2);
    }
  }
  *in_FS_OFFSET = local_3c;
  return;
}



