0x0048c428 FUN_0048c428 recovered/native/main/decompiled.cpp:43100
// Entry 0048c428, recovered name FUN_0048c428

void FUN_0048c428(void)

{
  char cVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar3;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_00566e20);
  FUN_00540f7c(local_8);
  FUN_00541018(*(int *)PTR__Form1_005799c4 + 0xe60,local_8);
  FUN_00540fe8(local_8,2);
  for (local_48 = 0; local_48 < DAT_0058779c; local_48 = local_48 + 1) {
    for (local_4c = 0; local_4c < *(int *)(*(int *)(&DAT_00585850 + local_48 * 4) + 0x104);
        local_4c = local_4c + 1) {
      FUN_00540ec4(local_c,&DAT_00563e8f);
      cVar1 = FUN_005410e4(*(int *)(&DAT_00585850 + local_48 * 4) + local_4c * 4 + 0xd88,local_c);
      FUN_00540fe8(local_c,2);
      if (cVar1 != '\0') {
        iVar2 = *(int *)(&DAT_00585850 + local_48 * 4);
        FUN_00540f7c(local_10,iVar2,local_4c,*(undefined4 *)(iVar2 + 0x8d8 + local_4c * 8),
                     *(undefined4 *)(iVar2 + 0x8dc + local_4c * 8));
        puVar3 = local_10;
        iVar2 = FUN_00417424();
        FUN_00541018(iVar2 * 0x44 + *(int *)PTR__Form1_005799c4 + 0xe60,puVar3);
        FUN_00540fe8(local_10,2);
        FUN_00540f7c(local_14);
        puVar3 = local_14;
        iVar2 = FUN_00417424();
        FUN_00541018(iVar2 * 0x44 + *(int *)PTR__Form1_005799c4 + 0xe64,puVar3);
        FUN_00540fe8(local_14,2);
      }
      FUN_00540ec4(local_18,&DAT_00563e90);
      cVar1 = FUN_005410e4(*(int *)(&DAT_00585850 + local_48 * 4) + local_4c * 4 + 0xbf8,local_18);
      FUN_00540fe8(local_18,2);
      if (cVar1 != '\0') {
        iVar2 = *(int *)(&DAT_00585850 + local_48 * 4);
        FUN_00540f7c(local_1c,iVar2,local_4c,*(undefined4 *)(iVar2 + 0x298 + local_4c * 8),
                     *(undefined4 *)(iVar2 + 0x29c + local_4c * 8));
        puVar3 = local_1c;
        iVar2 = FUN_00417424();
        FUN_00541018(iVar2 * 0x44 + *(int *)PTR__Form1_005799c4 + 0xe60,puVar3);
        FUN_00540fe8(local_1c,2);
        FUN_00540f7c(local_20);
        puVar3 = local_20;
        iVar2 = FUN_00417424();
        FUN_00541018(iVar2 * 0x44 + *(int *)PTR__Form1_005799c4 + 0xe64,puVar3);
        FUN_00540fe8(local_20,2);
      }
    }
  }
  *in_FS_OFFSET = local_44;
  return;
}




