0x00461e54 FUN_00461e54 recovered/native/main/decompiled.cpp:29128
// Entry 00461e54, recovered name FUN_00461e54

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461e54(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  undefined1 *puVar5;
  int local_68;
  undefined4 local_64;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_00564a78);
  iVar2 = *(int *)(&DAT_00585850 + in_stack_00000004 * 4);
  *(undefined4 *)(iVar2 + 0x4320) = 0;
  *(undefined4 *)(iVar2 + 0x4324) = 0;
  iVar2 = *(int *)(&DAT_00585850 + in_stack_00000004 * 4);
  *(undefined4 *)(iVar2 + 0x4328) = 0;
  *(undefined4 *)(iVar2 + 0x432c) = 0;
  iVar2 = *(int *)(&DAT_00585850 + in_stack_00000004 * 4);
  *(undefined4 *)(iVar2 + 0x4330) = 0;
  *(undefined4 *)(iVar2 + 0x4334) = 0;
  iVar2 = *(int *)(&DAT_00585850 + in_stack_00000004 * 4);
  *(undefined4 *)(iVar2 + 0x4338) = 0;
  *(undefined4 *)(iVar2 + 0x433c) = 0;
  local_68 = 0;
  do {
    if (*(int *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x104) <= local_68) {
      *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4330) =
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4328) * 22.4 * 1000.0;
      iVar2 = *(int *)(&DAT_00585850 + in_stack_00000004 * 4);
      *(undefined4 *)(iVar2 + 0xa8) = 0;
      *(undefined4 *)(iVar2 + 0xac) = 0;
      *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0xa8) =
           (double)(_DAT_004624c8 *
                   _DAT_004624bc *
                   (longdouble)
                   (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4330) -
                   (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x28) -
                   *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4320))));
      if (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0xa8) < 0.0) {
        iVar2 = *(int *)(&DAT_00585850 + in_stack_00000004 * 4);
        *(undefined4 *)(iVar2 + 0xa8) = 0;
        *(undefined4 *)(iVar2 + 0xac) = 0;
      }
      *in_FS_OFFSET = local_64;
                    /* WARNING: Read-only address (ram,0x004624bc) is written */
                    /* WARNING: Read-only address (ram,0x004624c8) is written */
      return;
    }
    iVar2 = FUN_00452d9c();
    *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x298 + local_68 * 8) =
         *(double *)((&DAT_0057bc08)[iVar2] + 0x10) *
         *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x8d8 + local_68 * 8);
    if (*(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x8d8 + local_68 * 8) < -1e-10
       ) {
      DAT_0057a6f8 = 0;
      puVar3 = (undefined4 *)FUN_00540ec4(local_8,&DAT_0056379e);
      FUN_00500350(*puVar3);
      FUN_00540fe8(local_8,2);
      *in_FS_OFFSET = local_64;
      return;
    }
    FUN_004016e8(local_c,*(int *)(&DAT_00585850 + in_stack_00000004 * 4),local_68,
                 *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_68 * 4));
    FUN_00452acc();
    puVar5 = local_c;
    FUN_00540ec4(local_10,&DAT_005637b2);
    cVar1 = FUN_005410cc(puVar5,local_10);
    if (cVar1 == '\0') {
      FUN_004016e8(local_14,local_68,in_stack_00000004,
                   *(undefined4 *)
                    (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_68 * 4));
      FUN_00452acc();
      puVar5 = local_14;
      FUN_00540ec4(local_18,&DAT_005637b9);
      cVar1 = FUN_005410cc(puVar5,local_18);
      uVar4 = (uint)(cVar1 != '\0');
      FUN_00540fe8(local_18,2);
      FUN_00540fe8(local_14,2);
      if (uVar4 != 0) goto LAB_004620ba;
      FUN_004016e8(local_1c,*(int *)(&DAT_00585850 + in_stack_00000004 * 4),local_68,
                   *(undefined4 *)
                    (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_68 * 4));
      FUN_00452acc();
      puVar5 = local_1c;
      FUN_00540ec4(local_20,&DAT_005637c0);
      cVar1 = FUN_005410cc(puVar5,local_20);
      uVar4 = (uint)(cVar1 != '\0');
      FUN_00540fe8(local_20,2);
      FUN_00540fe8(local_1c,2);
      if (uVar4 != 0) goto LAB_004620ba;
      cVar1 = '\0';
    }
    else {
LAB_004620ba:
      cVar1 = '\x01';
    }
    FUN_00540fe8(local_10,2);
    FUN_00540fe8(local_c,2);
    if (cVar1 != '\0') {
      FUN_004016e8(local_24,*(int *)(&DAT_00585850 + in_stack_00000004 * 4),local_68,
                   *(undefined4 *)
                    (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_68 * 4));
      FUN_00452acc();
      puVar5 = local_24;
      FUN_00540ec4(local_28,&DAT_005637c7);
      cVar1 = FUN_005410cc(puVar5,local_28);
      FUN_00540fe8(local_28,2);
      FUN_00540fe8(local_24,2);
      if (cVar1 == '\0') {
        iVar2 = FUN_00452d9c();
        *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x5b8 + local_68 * 8) =
             *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x298 + local_68 * 8) /
             *(double *)((&DAT_0057bc08)[iVar2] + 0x30);
      }
      else {
        *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x5b8 + local_68 * 8) =
             *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x8d8 + local_68 * 8) *
             22.4 * 1000.0;
      }
    }
    FUN_004016e8(local_2c,in_stack_00000004,*(int *)(&DAT_00585850 + in_stack_00000004 * 4),
                 *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_68 * 4));
    FUN_00452acc();
    puVar5 = local_2c;
    FUN_00540ec4(local_30,&DAT_005637ce);
    cVar1 = FUN_005410cc(puVar5,local_30);
    FUN_00540fe8(local_30,2);
    FUN_00540fe8(local_2c,2);
    if (cVar1 != '\0') {
      *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4338) =
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x5b8 + local_68 * 8) +
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4338);
    }
    FUN_004016e8(local_34,local_68,in_stack_00000004,
                 *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_68 * 4));
    FUN_00452acc();
    puVar5 = local_34;
    FUN_00540ec4(local_38,&DAT_005637d5);
    cVar1 = FUN_005410cc(puVar5,local_38);
    FUN_00540fe8(local_38,2);
    FUN_00540fe8(local_34,2);
    if (cVar1 != '\0') {
      *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4320) =
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x5b8 + local_68 * 8) +
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4320);
    }
    FUN_004016e8(local_3c,local_68,in_stack_00000004,
                 *(undefined4 *)
                  (*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x108 + local_68 * 4));
    FUN_00452acc();
    puVar5 = local_3c;
    FUN_00540ec4(local_40,&DAT_005637dc);
    cVar1 = FUN_005410cc(puVar5,local_40);
    FUN_00540fe8(local_40,2);
    FUN_00540fe8(local_3c,2);
    if (cVar1 != '\0') {
      *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4328) =
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x8d8 + local_68 * 8) +
           *(double *)(*(int *)(&DAT_00585850 + in_stack_00000004 * 4) + 0x4328);
    }
    local_68 = local_68 + 1;
  } while( true );
}




