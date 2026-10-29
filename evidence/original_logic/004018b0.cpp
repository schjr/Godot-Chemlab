0x004018b0 FUN_004018b0 recovered/native/main/decompiled.cpp:381
// Entry 004018b0, recovered name FUN_004018b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004018b0(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  LPCSTR lpNewFileName;
  LPCSTR lpExistingFileName;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *in_FS_OFFSET;
  BOOL bFailIfExists;
  undefined1 *puVar6;
  undefined1 local_f8 [20];
  int *local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  undefined1 *local_c8;
  undefined4 local_c4;
  int local_c0;
  undefined4 local_bc;
  undefined2 local_ac;
  int local_a0;
  int *local_98;
  int local_94;
  undefined1 local_90 [4];
  undefined1 local_8c [4];
  undefined1 local_88 [4];
  undefined1 local_84 [4];
  undefined1 local_80 [4];
  undefined1 local_7c [4];
  undefined4 local_78;
  undefined1 local_74 [4];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
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
  undefined4 local_8;
  
  local_c8 = param_3;
  local_c4 = param_2;
  local_c0 = param_1;
  FUN_00534be0(&DAT_00557e2c);
  local_cc = FUN_0053d180();
  if (5 < local_cc - *(int *)(local_c0 + 0x5a8)) {
    if ((DAT_0057a6f8 == 1) && (*(int *)(local_c0 + 0x5bc) == 0)) {
      _DAT_005636d4 = (double)(_DAT_004028dc * ((longdouble)local_cc - (longdouble)DAT_0057a74c));
      _DAT_005636cc = _DAT_005636d4 + _DAT_005636cc;
      DAT_0057a74c = local_cc;
      FUN_00470060();
      FUN_0048e418();
      FUN_004849fc();
      iVar2 = FUN_004028ec();
      if ((iVar2 == 1) && ((DAT_005636b8 == 0 && (DAT_0057a718 != DAT_0057a71c)))) {
        *(undefined4 *)(*(int *)(&DAT_00585854 + DAT_0058779c * 4) + 8) = 10;
      }
      for (local_d0 = 0; local_d0 < DAT_0058779c; local_d0 = local_d0 + 1) {
        if (*(int *)(*(int *)(&DAT_00585850 + local_d0 * 4) + 0x18) == 0) {
          FUN_0046c84c();
        }
      }
      FUN_004624d8();
      FUN_0046ec50();
      FUN_0046d414();
      FUN_0046f704();
      FUN_004624d8();
      FUN_0048c428();
      iVar2 = local_cc / 0x1e;
      if (local_cc % 0x1e == 1) {
        iVar2 = CONCAT22((short)((uint)(local_cc / 0x1e) >> 0x10),
                         (ushort)(_DAT_005636b0 < 20.0) << 8 | (ushort)NAN(_DAT_005636b0) << 10 |
                         (ushort)(_DAT_005636b0 == 20.0) << 0xe);
        if (_DAT_005636b0 < 20.0) {
          iVar2 = local_c0;
          if (*(int *)(local_c0 + 0x578) != -*(int *)(local_c0 + 0x640)) {
            local_ac = 8;
            FUN_004016e8(local_c);
            local_a0 = local_a0 + 1;
            local_ac = 0x20;
            FUN_004016e8(local_10);
            local_a0 = local_a0 + 1;
            local_ac = 0x2c;
            uVar3 = FUN_004016e8(local_18);
            local_a0 = local_a0 + 1;
            FUN_00540ec4(local_14,s__res_gkp_z_BMP_00556598);
            local_a0 = local_a0 + 1;
            FUN_00541040(&DAT_0057a740,local_14,uVar3);
            FUN_00541018(local_c,local_18);
            local_a0 = local_a0 + -1;
            FUN_00540fe8(local_18,2);
            local_a0 = local_a0 + -1;
            FUN_00540fe8(local_14,2);
            local_ac = 0x38;
            uVar3 = FUN_004016e8(local_20);
            local_a0 = local_a0 + 1;
            FUN_00540ec4(local_1c,s__res_guti_bmp_005565a7);
            local_a0 = local_a0 + 1;
            FUN_00541040(&DAT_0057a740,local_1c,uVar3);
            FUN_00541018(local_10,local_20);
            local_a0 = local_a0 + -1;
            FUN_00540fe8(local_20,2);
            local_a0 = local_a0 + -1;
            FUN_00540fe8(local_1c,2);
            bFailIfExists = 0;
            lpNewFileName = (LPCSTR)FUN_00402908(local_10);
            lpExistingFileName = (LPCSTR)FUN_00402908(local_c);
            CopyFileA(lpExistingFileName,lpNewFileName,bFailIfExists);
            local_a0 = local_a0 + -1;
            FUN_00540fe8(local_10,2);
            local_a0 = local_a0 + -1;
            iVar2 = FUN_00540fe8(local_c,2);
            local_ac = 0;
          }
        }
      }
      iVar2 = FUN_00402928(iVar2);
      if (iVar2 == 0) {
        if (*(int *)(local_c0 + 0x3c018) == 100) {
          local_ac = 0x44;
          puVar4 = (undefined4 *)FUN_00540ec4(local_24,&DAT_005565b5);
          local_a0 = local_a0 + 1;
          FUN_00500350(*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_24,2);
          FUN_0043e794(local_c0,*(undefined4 *)(local_c0 + 0x400));
        }
        else {
          *(undefined4 *)(*(int *)PTR__GcForm_005799ec + 0x318) =
               *(undefined4 *)(local_c0 + 0x3c020);
          local_ac = 0x50;
          uVar3 = FUN_004016e8(local_28);
          local_a0 = local_a0 + 1;
          FUN_0052bac0(*(int *)(local_c0 + 0x3c020) + 1,uVar3);
          puVar6 = local_28;
          uVar3 = FUN_004016e8(local_2c);
          local_a0 = local_a0 + 1;
          FUN_0054139c(&DAT_005565cb,puVar6,uVar3);
          puVar6 = local_2c;
          uVar3 = FUN_004016e8(local_34);
          local_a0 = local_a0 + 1;
          FUN_00540ec4(local_30,&DAT_005565d5);
          local_a0 = local_a0 + 1;
          FUN_00541040(puVar6,local_30,uVar3);
          FUN_00541018(*(int *)PTR__GcForm_005799ec + 0x314,local_34);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_34,2);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_30,2);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_2c,2);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_28,2);
          *(undefined4 *)(*(int *)PTR__GcForm_005799ec + 0x310) =
               *(undefined4 *)(local_c0 + 0x3c01c);
          DAT_0057a6f8 = 0;
          (**(code **)(**(int **)PTR__GcForm_005799ec + 0xd8))();
          if (*(char *)(*(int *)PTR__GcForm_005799ec + 0x31c) == '\x01') {
            DAT_0057a6f8 = 0;
            FUN_0043e794(local_c0,*(undefined4 *)(local_c0 + 0x2f8));
          }
          else {
            DAT_0057a6f8 = 1;
          }
        }
      }
      FUN_0048c758();
      local_ac = 0x5c;
      FUN_004016e8(&local_8);
      local_a0 = local_a0 + 1;
      local_ac = 0x68;
      if (((DAT_0057a6f4 == 1) && (100 < DAT_0057a730)) && (DAT_0057a730 < 300)) {
        FUN_004dfb80(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x2e4),
                     *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104) + 1);
        for (local_d4 = 0; local_d4 < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x104);
            local_d4 = local_d4 + 1) {
          FUN_004e1cfc(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x2e4),1,local_d4 + 1,
                       *(undefined4 *)
                        (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0x108 + local_d4 * 4));
          thunk_FUN_0053958c();
          local_ac = 0x74;
          FUN_00540ec4(local_38,local_f8);
          local_a0 = local_a0 + 1;
          FUN_00541018(&local_8,local_38);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_38,2);
          FUN_004e1cfc(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x2e4),2,local_d4 + 1,local_8);
          thunk_FUN_0053958c();
          local_ac = 0x80;
          FUN_00540ec4(local_3c,local_f8);
          local_a0 = local_a0 + 1;
          FUN_00541018(&local_8,local_3c);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_3c,2);
          FUN_004e1cfc(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x2e4),3,local_d4 + 1,local_8);
        }
        if (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf18) == 0) {
          FUN_004dfb80(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x318),2);
        }
        else {
          FUN_004dfb80(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x318),
                       *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf18) + 1);
        }
        for (local_d8 = 0; local_d8 < *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf18);
            local_d8 = local_d8 + 1) {
          local_ac = 0x8c;
          FUN_00540ec4(local_40,&DAT_005565dd);
          local_a0 = local_a0 + 1;
          FUN_00541018(&local_8,local_40);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_40,2);
          for (local_dc = 0;
              local_dc <
              *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf28 + local_d8 * 0xe8);
              local_dc = local_dc + 1) {
            local_ac = 0x98;
            FUN_00540f38(local_44,*(undefined4 *)
                                   (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + local_d8 * 0xe8 +
                                    0xf80 + local_dc * 4));
            local_a0 = local_a0 + 1;
            FUN_0054102c(&local_8,local_44);
            local_a0 = local_a0 + -1;
            FUN_00540fe8(local_44,2);
            FUN_0054102c(&local_8,*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + local_d8 * 0xe8 +
                                  local_dc * 4 + 0xf30);
            if (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf28 + local_d8 * 0xe8) + -1
                == local_dc) {
              local_ac = 0xb0;
              FUN_00540ec4(local_4c,&DAT_005565e2);
              local_a0 = local_a0 + 1;
              FUN_0054102c(&local_8,local_4c);
              local_a0 = local_a0 + -1;
              FUN_00540fe8(local_4c,2);
            }
            else {
              local_ac = 0xa4;
              FUN_00540ec4(local_48,&DAT_005565de);
              local_a0 = local_a0 + 1;
              FUN_0054102c(&local_8,local_48);
              local_a0 = local_a0 + -1;
              FUN_00540fe8(local_48,2);
            }
          }
          local_ac = 0x68;
          for (local_e0 = 0;
              local_e0 <
              *(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf2c + local_d8 * 0xe8);
              local_e0 = local_e0 + 1) {
            local_ac = 0xbc;
            FUN_00540f38(local_50,*(undefined4 *)
                                   (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + local_d8 * 0xe8 +
                                    0xfa8 + local_e0 * 4));
            local_a0 = local_a0 + 1;
            FUN_0054102c(&local_8,local_50);
            local_a0 = local_a0 + -1;
            FUN_00540fe8(local_50,2);
            FUN_0054102c(&local_8,*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + local_d8 * 0xe8 +
                                  local_e0 * 4 + 0xf58);
            if (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf2c + local_d8 * 0xe8) + -1
                != local_e0) {
              local_ac = 200;
              FUN_00540ec4(local_54,&DAT_005565e7);
              local_a0 = local_a0 + 1;
              FUN_0054102c(&local_8,local_54);
              local_a0 = local_a0 + -1;
              FUN_00540fe8(local_54,2);
            }
          }
          FUN_004e1cfc(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x318),1,local_d8 + 1,local_8);
        }
        if (*(int *)(*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf18) == 0) {
          local_ac = 0xd4;
          puVar4 = (undefined4 *)FUN_00540ec4(local_58,&DAT_005565eb);
          local_a0 = local_a0 + 1;
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x330),*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_58,2);
          local_ac = 0xe0;
          puVar4 = (undefined4 *)FUN_00540ec4(local_5c,&DAT_005565ec);
          local_a0 = local_a0 + 1;
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x338),*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_5c,2);
          local_ac = 0xec;
          puVar4 = (undefined4 *)FUN_00540ec4(local_60,&DAT_005565ed);
          local_a0 = local_a0 + 1;
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x340),*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_60,2);
          local_ac = 0xf8;
          puVar4 = (undefined4 *)FUN_00540ec4(local_64,&DAT_005565ee);
          local_a0 = local_a0 + 1;
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x348),*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_64,2);
          local_ac = 0x104;
          puVar4 = (undefined4 *)FUN_00540ec4(local_68,&DAT_005565ef);
          local_a0 = local_a0 + 1;
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x350),*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_68,2);
        }
        else {
          local_ac = 0x110;
          iVar2 = *(int *)(*(int *)(*(int *)PTR__Form4_005799cc + 0x318) + 0x214);
          iVar1 = *(int *)(&DAT_00585850 + DAT_0057a734 * 4);
          puVar4 = (undefined4 *)
                   FUN_00540f7c(local_6c,iVar1,iVar2 * 0x1d,
                                *(undefined4 *)(iVar1 + 0xee8 + iVar2 * 0xe8),
                                *(undefined4 *)(iVar1 + 0xeec + iVar2 * 0xe8));
          local_a0 = local_a0 + 1;
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x330),*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_6c,2);
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x338),
                       *(undefined4 *)
                        (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xef0 +
                        *(int *)(*(int *)(*(int *)PTR__Form4_005799cc + 0x318) + 0x214) * 0xe8));
          local_ac = 0x11c;
          iVar2 = *(int *)(*(int *)(*(int *)PTR__Form4_005799cc + 0x318) + 0x214);
          puVar4 = (undefined4 *)
                   FUN_00540f7c(local_70,iVar2 * 0x1d,DAT_0057a734,
                                *(undefined4 *)
                                 (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xef8 + iVar2 * 0xe8)
                                ,*(undefined4 *)
                                  (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xefc + iVar2 * 0xe8
                                  ));
          local_a0 = local_a0 + 1;
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x340),*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_70,2);
          local_ac = 0x128;
          iVar2 = *(int *)(*(int *)(*(int *)PTR__Form4_005799cc + 0x318) + 0x214);
          iVar1 = *(int *)(&DAT_00585850 + DAT_0057a734 * 4);
          puVar4 = (undefined4 *)
                   FUN_00540f7c(local_74,iVar1,iVar2 * 0x1d,
                                *(undefined4 *)(iVar1 + 0xf00 + iVar2 * 0xe8),
                                *(undefined4 *)(iVar1 + 0xf04 + iVar2 * 0xe8));
          local_a0 = local_a0 + 1;
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x348),*puVar4);
          local_a0 = local_a0 + -1;
          FUN_00540fe8(local_74,2);
          FUN_00505410(*(undefined4 *)(*(int *)PTR__Form4_005799cc + 0x350),
                       *(undefined4 *)
                        (*(int *)(&DAT_00585850 + DAT_0057a734 * 4) + 0xf08 +
                        *(int *)(*(int *)(*(int *)PTR__Form4_005799cc + 0x318) + 0x214) * 0xe8));
        }
      }
      FUN_0048c428();
      FUN_0048d6e0();
      FUN_004126dc(local_c0);
      if (*(int *)(local_c0 + 0x5c4) == 1) {
        local_ac = 0x134;
        FUN_004016e8(&local_78);
        local_a0 = local_a0 + 1;
        local_ac = 0x14c;
        uVar3 = FUN_004016e8(local_80);
        local_a0 = local_a0 + 1;
        FUN_00540ec4(local_7c,s__picture__005565f0);
        local_a0 = local_a0 + 1;
        FUN_00541040(&DAT_0057a740,local_7c,uVar3);
        puVar6 = local_80;
        uVar3 = FUN_004016e8(local_88);
        local_a0 = local_a0 + 1;
        FUN_00540f38(local_84,*(undefined4 *)(local_c0 + 0x5c8));
        local_a0 = local_a0 + 1;
        FUN_00541040(puVar6,local_84,uVar3);
        puVar6 = local_88;
        uVar3 = FUN_004016e8(local_90);
        local_a0 = local_a0 + 1;
        FUN_00540ec4(local_8c,&DAT_005565fa);
        local_a0 = local_a0 + 1;
        FUN_00541040(puVar6,local_8c,uVar3);
        FUN_00541018(&local_78,local_90);
        local_a0 = local_a0 + -1;
        FUN_00540fe8(local_90,2);
        local_a0 = local_a0 + -1;
        FUN_00540fe8(local_8c,2);
        local_a0 = local_a0 + -1;
        FUN_00540fe8(local_88,2);
        local_a0 = local_a0 + -1;
        FUN_00540fe8(local_84,2);
        local_a0 = local_a0 + -1;
        FUN_00540fe8(local_80,2);
        local_a0 = local_a0 + -1;
        FUN_00540fe8(local_7c,2);
        local_e4 = (int *)FUN_004e8edc(&PTR_FUN_004e2af4,1);
        local_ac = 0x140;
        (**(code **)(*local_e4 + 0x40))(local_e4,*(undefined4 *)(*(int *)(local_c0 + 0x4cc) + 0x38))
        ;
        (**(code **)(*local_e4 + 0x34))(local_e4,*(undefined4 *)(*(int *)(local_c0 + 0x4cc) + 0x3c))
        ;
        uVar3 = FUN_004e6d8c(*(undefined4 *)(*(int *)(local_c0 + 0x4cc) + 0x128));
        uVar5 = FUN_004e9448(local_e4);
        FUN_004e44a8(uVar5,0,0,uVar3);
        (**(code **)(*local_e4 + 0x4c))(local_e4,local_78);
        local_98 = local_e4;
        if (local_e4 != (int *)0x0) {
          local_94 = *local_e4;
          local_ac = 0x164;
          (**(code **)(*local_e4 + -4))(local_e4,3);
          local_ac = 0x158;
        }
        *(int *)(local_c0 + 0x5c8) = *(int *)(local_c0 + 0x5c8) + 1;
        local_a0 = local_a0 + -1;
        FUN_00540fe8(&local_78,2);
        local_ac = 0x68;
      }
      local_a0 = local_a0 + -1;
      FUN_00540fe8(&local_8,2);
    }
    *(int *)(local_c0 + 0x5a8) = local_cc;
  }
  *local_c8 = 1;
  *in_FS_OFFSET = local_bc;
  return;
}




