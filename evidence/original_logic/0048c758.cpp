// Entry 0048c758, recovered name FUN_0048c758

void FUN_0048c758(void)

{
  char cVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST0;
  longdouble lVar3;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_00566e9c);
  for (local_34 = 0; local_34 < DAT_0058779c; local_34 = local_34 + 1) {
    local_38 = 0;
    while( true ) {
      if (*(int *)(*(int *)(&DAT_00585850 + local_34 * 4) + 0x104) <= local_38) break;
      FUN_00540ec4(local_8,&DAT_00563e91);
      cVar1 = FUN_005410e4(*(int *)(&DAT_00585850 + local_34 * 4) + local_38 * 4 + 0xd88,local_8);
      FUN_00540fe8(local_8,2);
      lVar3 = in_ST0;
      if (cVar1 != '\0') {
        iVar2 = FUN_00417424();
        lVar3 = in_ST1;
        in_ST1 = in_ST2;
        in_ST2 = in_ST3;
        in_ST3 = in_ST4;
        in_ST4 = in_ST5;
        in_ST5 = in_ST6;
        in_ST6 = in_ST7;
        FUN_00541348(iVar2 * 0x44 + *(int *)PTR__Form1_005799c4 + 0xe60);
        *(double *)(*(int *)(&DAT_00585850 + local_34 * 4) + 0x8d8 + local_38 * 8) = (double)in_ST0;
        in_ST7 = in_ST6;
        if (*(double *)(*(int *)(&DAT_00585850 + local_34 * 4) + 0x8d8 + local_38 * 8) < 0.0) {
          iVar2 = *(int *)(&DAT_00585850 + local_34 * 4);
          *(undefined4 *)(iVar2 + 0x8d8 + local_38 * 8) = 0;
          *(undefined4 *)(iVar2 + 0x8dc + local_38 * 8) = 0;
        }
      }
      FUN_00540ec4(local_c,&DAT_00563e92);
      cVar1 = FUN_005410e4(*(int *)(&DAT_00585850 + local_34 * 4) + local_38 * 4 + 0xbf8,local_c);
      FUN_00540fe8(local_c,2);
      in_ST0 = lVar3;
      if (cVar1 != '\0') {
        iVar2 = FUN_00417424();
        in_ST0 = in_ST1;
        in_ST1 = in_ST2;
        in_ST2 = in_ST3;
        in_ST3 = in_ST4;
        in_ST4 = in_ST5;
        in_ST5 = in_ST6;
        in_ST6 = in_ST7;
        FUN_00541348(iVar2 * 0x44 + *(int *)PTR__Form1_005799c4 + 0xe60);
        iVar2 = FUN_00452d9c();
        *(double *)(*(int *)(&DAT_00585850 + local_34 * 4) + 0x8d8 + local_38 * 8) =
             (double)lVar3 / *(double *)((&DAT_0057bc08)[iVar2] + 0x10);
        in_ST7 = in_ST6;
        if (*(double *)(*(int *)(&DAT_00585850 + local_34 * 4) + 0x8d8 + local_38 * 8) < 0.0) {
          iVar2 = *(int *)(&DAT_00585850 + local_34 * 4);
          *(undefined4 *)(iVar2 + 0x8d8 + local_38 * 8) = 0;
          *(undefined4 *)(iVar2 + 0x8dc + local_38 * 8) = 0;
        }
      }
      local_38 = local_38 + 1;
    }
  }
  FUN_004624d8();
  *in_FS_OFFSET = local_30;
  return;
}



