
void FUN_00609e70(undefined4 param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  int *piVar7;
  undefined1 auStack_84 [4];
  int local_80;
  uint local_7c;
  undefined1 local_78 [8];
  int local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_4c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009431c6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  FUN_0045d930(local_78,param_1);
  local_c = 0;
  if ((local_70 != -1) && (local_6c != 0xffffffff)) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_0051c120(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_c = (uint)local_c._1_3_ << 8;
    }
    local_7c = local_6c;
    FUN_008438c0(&local_7c);
    if ((local_80 != DAT_00f8d91c) && (iVar3 = *(int *)(local_80 + 0x10), iVar3 != 0)) {
      local_80 = *(int *)(iVar3 + 0x54);
      if (local_80 == 0) {
        if (7 < local_4c) {
          FUN_0089120c(local_60);
        }
      }
      else {
        if (*(int *)(iVar3 + 100) != 0) {
          FUN_00409560(local_68,local_64);
          iVar3 = FUN_004dc700(local_68,local_64);
          if ((iVar3 != 0) && (*(int *)(iVar3 + 0x10) != 0)) {
            FUN_00404c10();
            iVar3 = FUN_0051d6d0();
            if (iVar3 != 0) {
              piVar7 = *(int **)(*(int *)(iVar3 + 0x54) + 0x148);
              piVar1 = *(int **)(*(int *)(iVar3 + 0x54) + 0x14c);
              if (piVar7 != piVar1) {
                local_7c = (int)piVar1 - (int)piVar7 >> 2;
                uVar2 = 0;
                if (local_7c != 0) {
                  do {
                    iVar3 = *piVar7;
                    if (*(short *)(iVar3 + 8) == 0x12) {
                      uVar5 = 0;
                      uVar4 = *(int *)(iVar3 + 0x10) - *(int *)(iVar3 + 0xc) >> 1;
                      if (uVar4 != 0) {
                        psVar6 = *(short **)(iVar3 + 0xc);
                        do {
                          if (*psVar6 == *(short *)(local_80 + 8)) {
                            FUN_00609030();
                            goto LAB_0060a02a;
                          }
                          uVar5 = uVar5 + 1;
                          psVar6 = psVar6 + 1;
                        } while (uVar5 < uVar4);
                      }
                    }
                    uVar2 = uVar2 + 1;
                    piVar7 = piVar7 + 1;
                  } while (uVar2 < local_7c);
                }
              }
            }
          }
        }
        FUN_00609030();
      }
      goto LAB_0060a02a;
    }
  }
  if (7 < local_4c) {
    FUN_0089120c(local_60);
  }
LAB_0060a02a:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

