0x0044f658 FUN_0044f658 recovered/native/main/decompiled.cpp:22269
// Entry 0044f658, recovered name FUN_0044f658

undefined4 FUN_0044f658(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int in_stack_00000004;
  int in_stack_00000008;
  undefined4 uStack_40c;
  char local_408 [499];
  char acStack_215 [501];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_5;
  
  uStack_40c = (char *)(in_stack_00000008 * 0x208 + in_stack_00000004 + 0x3c044);
  FUN_0053493c();
  local_1c = 0;
  uStack_40c = acStack_215 + 1;
  local_10 = FUN_0053496c();
  if ((acStack_215[1] == '(') && (acStack_215[local_10] == ')')) {
    local_1c = 1;
    for (local_c = 1; acStack_215[local_c + 1] != '\0'; local_c = local_c + 1) {
      if (acStack_215[local_c + 1] == '(') {
        local_1c = local_1c + 1;
      }
      else if (acStack_215[local_c + 1] == ')') {
        local_1c = local_1c + -1;
      }
      if (local_1c == 0) break;
    }
    if (local_10 + -1 == local_c) {
      local_10 = 1;
      if (1 < local_c) {
        do {
          acStack_215[local_10] = acStack_215[local_10 + 1];
          local_10 = local_10 + 1;
        } while (local_10 < local_c);
      }
      acStack_215[local_10] = '\0';
    }
  }
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_5 = '+';
  for (local_c = 0; acStack_215[local_c + 1] != '\0'; local_c = local_c + 1) {
    if (acStack_215[local_c + 1] == '(') {
      local_1c = local_1c + 1;
    }
    else if (acStack_215[local_c + 1] == ')') {
      local_1c = local_1c + -1;
    }
    else if ((((local_c < 1) ||
              ((acStack_215[local_c + 1] != '+' && (acStack_215[local_c + 1] != '-')))) ||
             ((acStack_215[local_c] != 'e' && (acStack_215[local_c] != 'E')))) &&
            (((acStack_215[local_c + 1] == '+' || (acStack_215[local_c + 1] == '-')) &&
             (local_1c == 0)))) {
      local_18 = local_18 + 1;
      local_10 = local_14;
      if (local_14 < local_c) {
        do {
          local_408[local_10 - local_14] = acStack_215[local_10 + 1];
          local_10 = local_10 + 1;
        } while (local_10 < local_c);
      }
      local_408[local_10 - local_14] = '\0';
      *(int *)(in_stack_00000004 + 0x3c028) = *(int *)(in_stack_00000004 + 0x3c028) + 1;
      if (local_18 == 1) {
        *(int *)(in_stack_00000004 + 0x3c02c) = *(int *)(in_stack_00000004 + 0x3c02c) + 1;
      }
      *(int *)(in_stack_00000004 + 0x3be2c + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
           in_stack_00000008;
      *(int *)(in_stack_00000004 + 0x3be30 + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
           *(int *)(in_stack_00000004 + 0x3c02c) + -1;
      uStack_40c = local_408;
      FUN_0053493c();
      *(int *)(in_stack_00000004 + 0x3be34 + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
           (int)local_5;
      local_5 = acStack_215[local_c + 1];
      local_14 = local_c + 1;
    }
  }
  if (local_18 < 1) {
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_5 = '*';
    for (local_c = 0; acStack_215[local_c + 1] != '\0'; local_c = local_c + 1) {
      if (acStack_215[local_c + 1] == '(') {
        local_1c = local_1c + 1;
      }
      else if (acStack_215[local_c + 1] == ')') {
        local_1c = local_1c + -1;
      }
      else if (((acStack_215[local_c + 1] == '*') || (acStack_215[local_c + 1] == '/')) &&
              (local_1c == 0)) {
        local_18 = local_18 + 1;
        local_10 = local_14;
        if (local_14 < local_c) {
          do {
            local_408[local_10 - local_14] = acStack_215[local_10 + 1];
            local_10 = local_10 + 1;
          } while (local_10 < local_c);
        }
        local_408[local_10 - local_14] = '\0';
        *(int *)(in_stack_00000004 + 0x3c028) = *(int *)(in_stack_00000004 + 0x3c028) + 1;
        if (local_18 == 1) {
          *(int *)(in_stack_00000004 + 0x3c02c) = *(int *)(in_stack_00000004 + 0x3c02c) + 1;
        }
        *(int *)(in_stack_00000004 + 0x3be2c + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
             in_stack_00000008;
        *(int *)(in_stack_00000004 + 0x3be30 + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
             *(int *)(in_stack_00000004 + 0x3c02c) + -1;
        uStack_40c = local_408;
        FUN_0053493c();
        *(int *)(in_stack_00000004 + 0x3be34 + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
             (int)local_5;
        local_5 = acStack_215[local_c + 1];
        local_14 = local_c + 1;
      }
    }
    if (local_18 < 1) {
      local_20 = 0;
      uStack_40c = &DAT_00557b54;
      cVar2 = FUN_0044d498();
      if (cVar2 == '\x01') {
        local_20 = 0x96;
        local_14 = 4;
      }
      else {
        uStack_40c = &DAT_00557b58;
        cVar2 = FUN_0044d498();
        if (cVar2 == '\x01') {
          local_20 = 0xa0;
          local_14 = 5;
        }
        else {
          uStack_40c = s_arccos_00557b5d;
          cVar2 = FUN_0044d498();
          if (cVar2 == '\x01') {
            local_20 = 0xa0;
            local_14 = 7;
          }
          else {
            uStack_40c = &DAT_00557b64;
            cVar2 = FUN_0044d498();
            if (cVar2 == '\x01') {
              local_20 = 0x97;
              local_14 = 4;
            }
            else {
              uStack_40c = &DAT_00557b68;
              cVar2 = FUN_0044d498();
              if (cVar2 == '\x01') {
                local_20 = 0xa1;
                local_14 = 5;
              }
              else {
                uStack_40c = s_arcsin_00557b6d;
                cVar2 = FUN_0044d498();
                if (cVar2 == '\x01') {
                  local_20 = 0xa1;
                  local_14 = 7;
                }
                else {
                  uStack_40c = &DAT_00557b74;
                  cVar2 = FUN_0044d498();
                  if (cVar2 == '\x01') {
                    local_20 = 0xa2;
                    local_14 = 4;
                  }
                  else {
                    uStack_40c = &DAT_00557b78;
                    cVar2 = FUN_0044d498();
                    if (cVar2 == '\x01') {
                      local_20 = 0xa2;
                      local_14 = 3;
                    }
                    else {
                      uStack_40c = &DAT_00557b7b;
                      cVar2 = FUN_0044d498();
                      if (cVar2 == '\x01') {
                        local_20 = 0xa3;
                        local_14 = 5;
                      }
                      else {
                        uStack_40c = s_arctan_00557b80;
                        cVar2 = FUN_0044d498();
                        if (cVar2 == '\x01') {
                          local_20 = 0xa3;
                          local_14 = 7;
                        }
                        else {
                          uStack_40c = s_signum_00557b87;
                          cVar2 = FUN_0044d498();
                          if (cVar2 == '\x01') {
                            local_20 = 0xa4;
                            local_14 = 7;
                          }
                          else {
                            uStack_40c = &DAT_00557b8e;
                            cVar2 = FUN_0044d498();
                            if (cVar2 == '\x01') {
                              local_20 = 0xa4;
                              local_14 = 3;
                            }
                            else {
                              uStack_40c = &DAT_00557b91;
                              cVar2 = FUN_0044d498();
                              if (cVar2 == '\x01') {
                                local_20 = 0x98;
                                local_14 = 4;
                              }
                              else {
                                uStack_40c = &DAT_00557b95;
                                cVar2 = FUN_0044d498();
                                if (cVar2 == '\x01') {
                                  local_20 = 0x99;
                                  local_14 = 5;
                                }
                                else {
                                  uStack_40c = &DAT_00557b9a;
                                  cVar2 = FUN_0044d498();
                                  if (cVar2 == '\x01') {
                                    local_20 = 0x99;
                                    local_14 = 4;
                                  }
                                  else {
                                    uStack_40c = s_log10_00557b9e;
                                    cVar2 = FUN_0044d498();
                                    if (cVar2 == '\x01') {
                                      local_20 = 0x9b;
                                      local_14 = 6;
                                    }
                                    else {
                                      uStack_40c = &DAT_00557ba4;
                                      cVar2 = FUN_0044d498();
                                      if (cVar2 == '\x01') {
                                        local_20 = 0x9a;
                                        local_14 = 4;
                                      }
                                      else {
                                        uStack_40c = &DAT_00557ba8;
                                        cVar2 = FUN_0044d498();
                                        if (cVar2 == '\x01') {
                                          local_20 = 0x9c;
                                          local_14 = 5;
                                        }
                                        else {
                                          uStack_40c = &DAT_00557bad;
                                          cVar2 = FUN_0044d498();
                                          if (cVar2 == '\x01') {
                                            local_20 = 0x9d;
                                            local_14 = 4;
                                            *(int *)(in_stack_00000004 + 0x3c02c) =
                                                 *(int *)(in_stack_00000004 + 0x3c02c) + 1;
                                            for (local_c = 4;
                                                (acStack_215[local_c + 1] != ',' &&
                                                (acStack_215[local_c + 1] != '\0'));
                                                local_c = local_c + 1) {
                                              local_408[local_c - local_14] =
                                                   acStack_215[local_c + 1];
                                            }
                                            local_408[local_c - local_14] = '\0';
                                            *(int *)(in_stack_00000004 + 0x3c028) =
                                                 *(int *)(in_stack_00000004 + 0x3c028) + 1;
                                            *(int *)(in_stack_00000004 + 0x3be2c +
                                                    *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
                                                 in_stack_00000008;
                                            *(int *)(in_stack_00000004 + 0x3be30 +
                                                    *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
                                                 *(int *)(in_stack_00000004 + 0x3c02c) + -1;
                                            uStack_40c = local_408;
                                            FUN_0053493c();
                                            *(int *)(in_stack_00000004 + 0x3be34 +
                                                    *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
                                                 local_20;
                                            local_14 = local_c + 1;
                                            for (local_c = local_c + 1;
                                                acStack_215[local_c + 1] != '\0';
                                                local_c = local_c + 1) {
                                              local_408[local_c - local_14] =
                                                   acStack_215[local_c + 1];
                                            }
                                            local_408[(local_c - local_14) + -1] = '\0';
                                            *(int *)(in_stack_00000004 + 0x3c028) =
                                                 *(int *)(in_stack_00000004 + 0x3c028) + 1;
                                            *(int *)(in_stack_00000004 + 0x3be2c +
                                                    *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
                                                 in_stack_00000008;
                                            *(int *)(in_stack_00000004 + 0x3be30 +
                                                    *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
                                                 *(int *)(in_stack_00000004 + 0x3c02c) + -1;
                                            uStack_40c = local_408;
                                            FUN_0053493c();
                                            iVar1 = *(int *)(in_stack_00000004 + 0x3c028);
                                            *(int *)(in_stack_00000004 + 0x3be34 + iVar1 * 0x208) =
                                                 local_20;
                                            return CONCAT31((int3)((uint)(iVar1 * 0x41) >> 8),1);
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
      if (local_20 < 1) {
        uVar3 = 0;
      }
      else {
        *(int *)(in_stack_00000004 + 0x3c02c) = *(int *)(in_stack_00000004 + 0x3c02c) + 1;
        for (local_c = local_14; acStack_215[local_c + 1] != '\0'; local_c = local_c + 1) {
          local_408[local_c - local_14] = acStack_215[local_c + 1];
        }
        local_408[(local_c - local_14) + -1] = '\0';
        *(int *)(in_stack_00000004 + 0x3c028) = *(int *)(in_stack_00000004 + 0x3c028) + 1;
        *(int *)(in_stack_00000004 + 0x3be2c + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
             in_stack_00000008;
        *(int *)(in_stack_00000004 + 0x3be30 + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
             *(int *)(in_stack_00000004 + 0x3c02c) + -1;
        uStack_40c = local_408;
        FUN_0053493c();
        iVar1 = *(int *)(in_stack_00000004 + 0x3c028);
        *(int *)(in_stack_00000004 + 0x3be34 + iVar1 * 0x208) = local_20;
        uVar3 = CONCAT31((int3)((uint)(iVar1 * 0x41) >> 8),1);
      }
    }
    else {
      local_10 = local_14;
      if (local_14 < local_c) {
        do {
          local_408[local_10 - local_14] = acStack_215[local_10 + 1];
          local_10 = local_10 + 1;
        } while (local_10 < local_c);
      }
      local_408[local_10 - local_14] = '\0';
      *(int *)(in_stack_00000004 + 0x3c028) = *(int *)(in_stack_00000004 + 0x3c028) + 1;
      *(int *)(in_stack_00000004 + 0x3be2c + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
           in_stack_00000008;
      *(int *)(in_stack_00000004 + 0x3be30 + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
           *(int *)(in_stack_00000004 + 0x3c02c) + -1;
      uStack_40c = local_408;
      FUN_0053493c();
      iVar1 = *(int *)(in_stack_00000004 + 0x3c028);
      *(int *)(in_stack_00000004 + 0x3be34 + iVar1 * 0x208) = (int)local_5;
      uVar3 = CONCAT31((int3)((uint)(iVar1 * 0x41) >> 8),1);
    }
  }
  else {
    local_10 = local_14;
    if (local_14 < local_c) {
      do {
        local_408[local_10 - local_14] = acStack_215[local_10 + 1];
        local_10 = local_10 + 1;
      } while (local_10 < local_c);
    }
    local_408[local_10 - local_14] = '\0';
    *(int *)(in_stack_00000004 + 0x3c028) = *(int *)(in_stack_00000004 + 0x3c028) + 1;
    *(int *)(in_stack_00000004 + 0x3be2c + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
         in_stack_00000008;
    *(int *)(in_stack_00000004 + 0x3be30 + *(int *)(in_stack_00000004 + 0x3c028) * 0x208) =
         *(int *)(in_stack_00000004 + 0x3c02c) + -1;
    uStack_40c = local_408;
    FUN_0053493c();
    iVar1 = *(int *)(in_stack_00000004 + 0x3c028);
    *(int *)(in_stack_00000004 + 0x3be34 + iVar1 * 0x208) = (int)local_5;
    uVar3 = CONCAT31((int3)((uint)(iVar1 * 0x41) >> 8),1);
  }
  return uVar3;
}




