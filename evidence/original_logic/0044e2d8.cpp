// Entry 0044e2d8, recovered name FUN_0044e2d8

bool FUN_0044e2d8(void)

{
  bool bVar1;
  longdouble lVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble lVar5;
  longdouble in_ST7;
  longdouble lVar6;
  int in_stack_00000004;
  undefined4 in_stack_0000000c;
  char local_88c [1099];
  char acStack_441 [1001];
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined2 local_3c;
  int local_30;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [8];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  FUN_00534be0(&DAT_005617ec);
  local_30 = 1;
  FUN_00540efc(&stack0x00000008,&stack0x00000008);
  local_30 = local_30 + 1;
  local_3c = 0x14;
  FUN_004016e8(local_8);
  local_30 = local_30 + 1;
  local_3c = 0x20;
  FUN_004016e8(local_c);
  local_30 = local_30 + 1;
  local_3c = 8;
  FUN_00402908(&stack0x00000008);
  FUN_0053493c();
  local_50 = 0;
  do {
    if (acStack_441[local_50 + 1] == '\0') {
      local_3c = 0x68;
      uVar4 = FUN_00540ec4(local_28,acStack_441 + 1);
      local_30 = local_30 + 1;
      FUN_00541018(local_8,uVar4);
      local_30 = local_30 + -1;
      FUN_00540fe8(local_28,2);
      cVar3 = FUN_0044ecf8();
      if (cVar3 != '\x01') {
        local_30 = local_30 + -1;
        FUN_00540fe8(local_c,2);
        local_30 = local_30 + -1;
        FUN_00540fe8(local_8,2);
        local_30 = local_30 + -1;
        FUN_00540fe8(&stack0x00000008,2);
        *in_FS_OFFSET = local_4c;
      }
      else {
        local_30 = local_30 + -1;
        FUN_00540fe8(local_c,2);
        local_30 = local_30 + -1;
        FUN_00540fe8(local_8,2);
        local_30 = local_30 + -1;
        FUN_00540fe8(&stack0x00000008,2);
        *in_FS_OFFSET = local_4c;
      }
      return cVar3 == '\x01';
    }
    if ((((((local_50 < 1) ||
           (((acStack_441[local_50 + 1] != 'e' && (acStack_441[local_50 + 1] != 'E')) ||
            (acStack_441[local_50] < '0')))) ||
          (('9' < acStack_441[local_50] ||
           ((acStack_441[local_50 + 2] != '+' && (acStack_441[local_50 + 2] != '-')))))) &&
         (((acStack_441[local_50 + 1] < '0' || ('9' < acStack_441[local_50 + 1])) &&
          (((acStack_441[local_50 + 1] != '>' && (acStack_441[local_50 + 1] != '<')) &&
           (acStack_441[local_50 + 1] != '=')))))) &&
        ((((acStack_441[local_50 + 1] != ',' && (acStack_441[local_50 + 1] != '.')) &&
          (acStack_441[local_50 + 1] != '+')) &&
         (((acStack_441[local_50 + 1] != '-' && (acStack_441[local_50 + 1] != '*')) &&
          ((acStack_441[local_50 + 1] != '/' &&
           ((acStack_441[local_50 + 1] != '(' && (acStack_441[local_50 + 1] != ')')))))))))) &&
       (acStack_441[local_50 + 1] != ' ')) {
      cVar3 = FUN_0044d498();
      if (cVar3 == '\x01') {
        local_50 = local_50 + 3;
      }
      else {
        cVar3 = FUN_0044d498();
        if (cVar3 == '\x01') {
          local_50 = local_50 + 4;
        }
        else {
          cVar3 = FUN_0044d498();
          if (cVar3 == '\x01') {
            local_50 = local_50 + 6;
          }
          else {
            cVar3 = FUN_0044d498();
            if (cVar3 == '\x01') {
              local_50 = local_50 + 3;
            }
            else {
              cVar3 = FUN_0044d498();
              if (cVar3 == '\x01') {
                local_50 = local_50 + 4;
              }
              else {
                cVar3 = FUN_0044d498();
                if (cVar3 == '\x01') {
                  local_50 = local_50 + 6;
                }
                else {
                  cVar3 = FUN_0044d498();
                  if (cVar3 == '\x01') {
                    local_50 = local_50 + 3;
                  }
                  else {
                    cVar3 = FUN_0044d498();
                    if (cVar3 == '\x01') {
                      local_50 = local_50 + 2;
                    }
                    else {
                      cVar3 = FUN_0044d498();
                      if (cVar3 == '\x01') {
                        local_50 = local_50 + 4;
                      }
                      else {
                        cVar3 = FUN_0044d498();
                        if (cVar3 == '\x01') {
                          local_50 = local_50 + 6;
                        }
                        else {
                          cVar3 = FUN_0044d498();
                          if (cVar3 == '\x01') {
                            local_50 = local_50 + 6;
                          }
                          else {
                            cVar3 = FUN_0044d498();
                            if (cVar3 == '\x01') {
                              local_50 = local_50 + 2;
                            }
                            else {
                              cVar3 = FUN_0044d498();
                              if (cVar3 == '\x01') {
                                local_50 = local_50 + 2;
                              }
                              else {
                                cVar3 = FUN_0044d498();
                                if (cVar3 == '\x01') {
                                  local_50 = local_50 + 3;
                                }
                                else {
                                  cVar3 = FUN_0044d498();
                                  if (cVar3 == '\x01') {
                                    local_50 = local_50 + 4;
                                  }
                                  else {
                                    cVar3 = FUN_0044d498();
                                    if (cVar3 == '\x01') {
                                      local_50 = local_50 + 3;
                                    }
                                    else {
                                      cVar3 = FUN_0044d498();
                                      if (cVar3 == '\x01') {
                                        local_50 = local_50 + 3;
                                      }
                                      else {
                                        cVar3 = FUN_0044d498();
                                        if (cVar3 == '\x01') {
                                          local_50 = local_50 + 5;
                                        }
                                        else {
                                          cVar3 = FUN_0044d498();
                                          if (cVar3 == '\x01') {
                                            local_50 = local_50 + 4;
                                          }
                                          else {
                                            cVar3 = FUN_0044d498();
                                            if (cVar3 == '\x01') {
                                              local_50 = local_50 + 3;
                                            }
                                            else {
                                              local_54 = 0;
                                              while (((((((acStack_441[local_54 + local_50 + 1] !=
                                                           '>' && (acStack_441
                                                                   [local_54 + local_50 + 1] != '<')
                                                          ) && (acStack_441[local_54 + local_50 + 1]
                                                                != '=')) &&
                                                        ((acStack_441[local_54 + local_50 + 1] !=
                                                          ',' && (acStack_441
                                                                  [local_54 + local_50 + 1] != '+'))
                                                        )) && ((acStack_441[local_54 + local_50 + 1]
                                                                != '-' &&
                                                               ((acStack_441
                                                                 [local_54 + local_50 + 1] != '*' &&
                                                                (acStack_441
                                                                 [local_54 + local_50 + 1] != '/')))
                                                               ))) &&
                                                      (acStack_441[local_54 + local_50 + 1] != '('))
                                                     && (((acStack_441[local_54 + local_50 + 1] !=
                                                           ')' && (acStack_441
                                                                   [local_54 + local_50 + 1] != ' ')
                                                          ) && (acStack_441[local_54 + local_50 + 1]
                                                                != '\0'))))) {
                                                local_88c[local_54] =
                                                     acStack_441[local_54 + local_50 + 1];
                                                local_54 = local_54 + 1;
                                              }
                                              local_88c[local_54] = '\0';
                                              local_3c = 0x2c;
                                              uVar4 = FUN_00540ec4(local_10,local_88c);
                                              local_30 = local_30 + 1;
                                              FUN_00541018(local_8,uVar4);
                                              local_30 = local_30 + -1;
                                              FUN_00540fe8(local_10,2);
                                              local_58 = FUN_00417424();
                                              if (local_58 == -1) {
                                                local_30 = local_30 + -1;
                                                FUN_00540fe8(local_c,2);
                                                local_30 = local_30 + -1;
                                                FUN_00540fe8(local_8,2);
                                                local_30 = local_30 + -1;
                                                FUN_00540fe8(&stack0x00000008,2);
                                                *in_FS_OFFSET = local_4c;
                                                return false;
                                              }
                                              FUN_00541018(local_c,local_58 * 0x44 +
                                                                   in_stack_00000004 + 0xe60);
                                              local_3c = 0x38;
                                              FUN_00541348(local_c);
                                              lVar5 = in_ST7;
                                              FUN_005394d4();
                                              bVar1 = in_ST1 < (longdouble)1e-20;
                                              in_ST1 = in_ST4;
                                              lVar2 = in_ST7;
                                              lVar6 = lVar5;
                                              if (bVar1) {
                                                local_3c = 0x44;
                                                FUN_00540ec4(local_14,&DAT_00557b46);
                                                local_30 = local_30 + 1;
                                                FUN_00541018(local_c,local_14);
                                                local_30 = local_30 + -1;
                                                FUN_00540fe8(local_14,2);
                                                in_ST1 = in_ST4;
                                                lVar2 = in_ST7;
                                              }
                                              in_ST7 = lVar6;
                                              in_ST4 = lVar2;
                                              local_3c = 8;
                                              FUN_00541348(local_c);
                                              if (in_ST2 < (longdouble)0.0) {
                                                local_3c = 0x5c;
                                                uVar4 = FUN_004016e8(local_1c);
                                                local_30 = local_30 + 1;
                                                FUN_0054139c(&DAT_00557b4e,local_c,uVar4);
                                                uVar4 = FUN_004016e8(local_24);
                                                local_30 = local_30 + 1;
                                                FUN_00540ec4(local_20,&DAT_00557b51);
                                                local_30 = local_30 + 1;
                                                FUN_00541040(local_1c,local_20,uVar4);
                                                FUN_00541018(local_c,local_24);
                                                local_30 = local_30 + -1;
                                                FUN_00540fe8(local_24,2);
                                                local_30 = local_30 + -1;
                                                FUN_00540fe8(local_20,2);
                                                local_30 = local_30 + -1;
                                                FUN_00540fe8(local_1c,2);
                                                FUN_00402908(local_c);
                                                FUN_0053493c();
                                                in_ST2 = in_ST5;
                                                in_ST5 = lVar5;
                                              }
                                              else {
                                                FUN_00402908(local_c);
                                                FUN_0053493c();
                                                in_ST2 = in_ST5;
                                                in_ST5 = lVar5;
                                              }
                                              FUN_0053493c();
                                              acStack_441[local_50 + 1] = '\0';
                                              FUN_005348b4();
                                              FUN_005348b4();
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    local_50 = local_50 + 1;
  } while( true );
}



