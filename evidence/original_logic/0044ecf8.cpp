0x0044ecf8 FUN_0044ecf8 recovered/native/main/decompiled.cpp:21860
// Entry 0044ecf8, recovered name FUN_0044ecf8

undefined4 FUN_0044ecf8(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST0;
  longdouble lVar6;
  longdouble lVar7;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  int in_stack_00000004;
  double *in_stack_0000000c;
  double local_58;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  FUN_00534be0(&DAT_00561920);
  FUN_00540efc(&stack0x00000008,&stack0x00000008);
  FUN_004016e8(&local_8);
  FUN_00402908(&stack0x00000008);
  FUN_0053493c();
  FUN_0044f580();
  local_44 = *(int *)(in_stack_00000004 + 0x3c028) + -1;
  do {
    if (local_44 < 1) {
      uVar4 = FUN_00540ec4(local_1c,in_stack_00000004 + 0x3c044);
      FUN_00541018(&local_8,uVar4);
      FUN_00540fe8(local_1c,2);
      FUN_00541348(&local_8);
      *in_stack_0000000c = (double)in_ST0;
      uVar4 = 1;
      FUN_00540fe8(&local_8,2);
      FUN_00540fe8(&stack0x00000008,2);
      *in_FS_OFFSET = local_40;
      return uVar4;
    }
    iVar1 = *(int *)(in_stack_00000004 + 0x3c038 + local_44 * 0x208);
    for (; local_48 = local_44, *(int *)(in_stack_00000004 + 0x3c038 + local_44 * 0x208) == iVar1;
        local_44 = local_44 + -1) {
    }
    while( true ) {
      local_48 = local_48 + 1;
      iVar2 = *(int *)(in_stack_00000004 + 0x3c038 + local_48 * 0x208);
      iVar5 = local_48;
      if ((iVar2 != iVar1) ||
         (iVar5 = in_stack_00000004, *(int *)(in_stack_00000004 + 0x3c028) <= local_48)) break;
      if (local_44 + 1 == local_48) {
        uVar4 = FUN_00540ec4(local_c,local_48 * 0x208 + in_stack_00000004 + 0x3c044);
        FUN_00541018(&local_8,uVar4);
        FUN_00540fe8(local_c,2);
        FUN_00540ec4(local_10,&DAT_00557b53);
        cVar3 = FUN_005410cc(&local_8,local_10);
        FUN_00540fe8(local_10,2);
        if (cVar3 == '\0') {
          lVar6 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
          FUN_00541348(&local_8);
          local_58 = (double)in_ST0;
          in_ST7 = in_ST6;
        }
        else {
          local_58 = 0.0;
          lVar6 = in_ST0;
        }
        if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x96) {
          FUN_00539238();
          local_58 = (double)lVar6;
          in_ST0 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0xa0) {
          FUN_005394d4();
          if ((longdouble)1.0 < lVar6) {
            uVar4 = 0;
            FUN_00540fe8(&local_8,2);
            FUN_00540fe8(&stack0x00000008,2);
            *in_FS_OFFSET = local_40;
            return uVar4;
          }
          lVar6 = in_ST7;
          FUN_005390b5();
          local_58 = (double)in_ST1;
          in_ST0 = in_ST2;
          in_ST1 = in_ST3;
          in_ST2 = in_ST4;
          in_ST3 = in_ST5;
          in_ST4 = in_ST6;
          in_ST5 = in_ST7;
          in_ST6 = lVar6;
          in_ST7 = lVar6;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x97) {
          FUN_0053aca8();
          local_58 = (double)lVar6;
          in_ST0 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0xa1) {
          FUN_005394d4();
          if ((longdouble)1.0 < lVar6) {
            uVar4 = 0;
            FUN_00540fe8(&local_8,2);
            FUN_00540fe8(&stack0x00000008,2);
            *in_FS_OFFSET = local_40;
            return uVar4;
          }
          lVar6 = in_ST7;
          FUN_005390d0();
          local_58 = (double)in_ST1;
          in_ST0 = in_ST2;
          in_ST1 = in_ST3;
          in_ST2 = in_ST4;
          in_ST3 = in_ST5;
          in_ST4 = in_ST6;
          in_ST5 = in_ST7;
          in_ST6 = lVar6;
          in_ST7 = lVar6;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0xa2) {
          FUN_0053ad24();
          local_58 = (double)lVar6;
          in_ST0 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0xa3) {
          FUN_005390e8();
          local_58 = (double)lVar6;
          in_ST0 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
        }
        else {
          in_ST0 = lVar6;
          if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0xa4) {
            if (local_58 == 0.0) {
              local_58 = 0.0;
              in_ST7 = in_ST6;
            }
            else if (local_58 <= 0.0) {
              in_ST7 = in_ST6;
              if (local_58 < 0.0) {
                local_58 = -1.0;
              }
            }
            else {
              local_58 = 1.0;
              in_ST7 = in_ST6;
            }
          }
          else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x98) {
            FUN_005392f0();
            local_58 = (double)lVar6;
            in_ST0 = in_ST1;
            in_ST1 = in_ST2;
            in_ST2 = in_ST3;
            in_ST3 = in_ST4;
            in_ST4 = in_ST5;
            in_ST5 = in_ST6;
            in_ST6 = in_ST7;
          }
          else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x99) {
            FUN_005394d4();
            local_58 = (double)lVar6;
            in_ST0 = in_ST1;
            in_ST1 = in_ST2;
            in_ST2 = in_ST3;
            in_ST3 = in_ST4;
            in_ST4 = in_ST5;
            in_ST5 = in_ST6;
            in_ST6 = in_ST7;
          }
          else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x9a) {
            if (local_58 <= 0.0) {
              uVar4 = 0;
              FUN_00540fe8(&local_8,2);
              FUN_00540fe8(&stack0x00000008,2);
              *in_FS_OFFSET = local_40;
              return uVar4;
            }
            in_ST7 = in_ST6;
            FUN_0053977c();
            local_58 = (double)lVar6;
            in_ST0 = in_ST1;
            in_ST1 = in_ST2;
            in_ST2 = in_ST3;
            in_ST3 = in_ST4;
            in_ST4 = in_ST5;
            in_ST5 = in_ST6;
            in_ST6 = in_ST7;
          }
          else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x9b) {
            if (local_58 <= 0.0) {
              uVar4 = 0;
              FUN_00540fe8(&local_8,2);
              FUN_00540fe8(&stack0x00000008,2);
              *in_FS_OFFSET = local_40;
              return uVar4;
            }
            in_ST7 = in_ST6;
            FUN_005397ec();
            local_58 = (double)lVar6;
            in_ST0 = in_ST1;
            in_ST1 = in_ST2;
            in_ST2 = in_ST3;
            in_ST3 = in_ST4;
            in_ST4 = in_ST5;
            in_ST5 = in_ST6;
            in_ST6 = in_ST7;
          }
          else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x9c) {
            if (local_58 <= 0.0) {
              uVar4 = 0;
              FUN_00540fe8(&local_8,2);
              FUN_00540fe8(&stack0x00000008,2);
              *in_FS_OFFSET = local_40;
              return uVar4;
            }
            in_ST7 = in_ST6;
            FUN_0053ace8();
            local_58 = (double)lVar6;
            in_ST0 = in_ST1;
            in_ST1 = in_ST2;
            in_ST2 = in_ST3;
            in_ST3 = in_ST4;
            in_ST4 = in_ST5;
            in_ST5 = in_ST6;
            in_ST6 = in_ST7;
          }
        }
      }
      else {
        uVar4 = FUN_00540ec4(local_14,local_48 * 0x208 + in_stack_00000004 + 0x3c044);
        FUN_00541018(&local_8,uVar4);
        FUN_00540fe8(local_14,2);
        cVar3 = FUN_0044f5f8();
        if (cVar3 == '\0') {
          FUN_00500350(local_8);
          uVar4 = 0;
          FUN_00540fe8(&local_8,2);
          FUN_00540fe8(&stack0x00000008,2);
          *in_FS_OFFSET = local_40;
          return uVar4;
        }
        if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x2b) {
          FUN_00541348(&local_8);
          local_58 = (double)(in_ST0 + (longdouble)local_58);
          in_ST0 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x2d) {
          FUN_00541348(&local_8);
          local_58 = (double)((longdouble)local_58 - in_ST0);
          in_ST0 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x2a) {
          FUN_00541348(&local_8);
          local_58 = (double)(in_ST0 * (longdouble)local_58);
          in_ST0 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x2f) {
          FUN_00541348(&local_8);
          local_58 = (double)((longdouble)local_58 / in_ST0);
          in_ST0 = in_ST1;
          in_ST1 = in_ST2;
          in_ST2 = in_ST3;
          in_ST3 = in_ST4;
          in_ST4 = in_ST5;
          in_ST5 = in_ST6;
          in_ST6 = in_ST7;
        }
        else if (*(int *)(in_stack_00000004 + 0x3c03c + local_48 * 0x208) == 0x9d) {
          FUN_00541348(&local_8);
          lVar7 = (longdouble)(double)in_ST0;
          FUN_005394fc();
          in_ST0 = in_ST2;
          in_ST2 = in_ST4;
          in_ST4 = in_ST6;
          lVar6 = in_ST6;
          FUN_005394d4();
          in_ST6 = lVar6;
          if ((longdouble)1e-20 <= lVar7) {
            FUN_005399d8();
            local_58 = (double)in_ST1;
            in_ST1 = in_ST3;
            in_ST3 = in_ST5;
            in_ST5 = lVar6;
            in_ST7 = in_ST6;
          }
          else {
            FUN_005399d8();
            local_58 = (double)in_ST1;
            in_ST1 = in_ST3;
            in_ST3 = in_ST5;
            in_ST5 = lVar6;
            in_ST7 = in_ST6;
          }
        }
      }
    }
    FUN_00540f7c(local_18,iVar2,iVar5,local_58._0_4_,(int)((ulonglong)local_58 >> 0x20));
    FUN_00541018(&local_8,local_18);
    FUN_00540fe8(local_18,2);
    FUN_00402908(&local_8);
    FUN_0053493c();
  } while( true );
}




