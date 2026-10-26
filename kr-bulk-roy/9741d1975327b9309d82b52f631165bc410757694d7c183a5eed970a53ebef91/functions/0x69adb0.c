
undefined4 FUN_0069adb0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_60;
  uint local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  undefined4 *local_48;
  int local_44;
  undefined4 local_40;
  int *local_38;
  int *local_34;
  undefined4 local_30;
  int *local_28;
  int *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00912411;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  iVar2 = FUN_0051d700(param_1);
  if (iVar2 == 0) {
    ExceptionList = local_14;
    return 0;
  }
  local_4c = iVar2;
  FUN_007e8a90(&local_28,iVar2 + 0x138);
  local_c = 1;
  iVar3 = 0;
  piVar4 = local_28;
  if (*(int *)(iVar2 + 8) - 1U < 0x2b) {
    iVar3 = FUN_00520f40();
    piVar4 = local_28;
  }
  for (; (piVar4 != local_24 && (*piVar4 != iVar3)); piVar4 = piVar4 + 1) {
  }
  uVar5 = (int)local_24 - (int)local_28 >> 2;
  if (uVar5 != 0) {
    local_48 = (undefined4 *)0x0;
    local_44 = 0;
    local_40 = 0;
    local_c = CONCAT31(local_c._1_3_,2);
    FUN_006dd790(*(int *)(DAT_00fb1318 + 0xbfe8) + 0xb4);
    iVar2 = local_44 - (int)local_48 >> 0x1f;
    iVar3 = (local_44 - (int)local_48) / 0xc + iVar2;
    local_58 = 0;
    puVar7 = local_48;
    if (iVar3 != iVar2) {
      local_60 = local_48;
      do {
        if ((DAT_00f8d9a8 & 1) == 0) {
          DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
          local_c._0_1_ = 3;
          FUN_00523540();
          local_c._0_1_ = 4;
          FUN_00521080(&DAT_00f8d9bc);
          _atexit((_func_4879 *)&LAB_00bccc50);
          local_c = CONCAT31(local_c._1_3_,2);
        }
        local_54 = *local_60;
        FUN_008438c0(&local_54);
        if (((local_50 != DAT_00f8d9b0) && (iVar1 = *(int *)(local_50 + 0x10), iVar1 != 0)) &&
           (*(int *)(iVar1 + 8) != *(int *)(local_4c + 8))) {
          FUN_007e8a90(&local_38,iVar1 + 0x138);
          uVar6 = 0;
          if (uVar5 != 0) {
            do {
              if (local_38 != local_34) {
                piVar4 = local_38;
                do {
                  if (*piVar4 == local_28[uVar6]) {
                    if (piVar4 != local_34) {
                      if (local_38 != (int *)0x0) {
                        FUN_0089120c(local_38);
                      }
                      if (local_48 != (undefined4 *)0x0) {
                        FUN_0089120c(local_48);
                      }
                      if (local_28 == (int *)0x0) {
                        ExceptionList = local_14;
                        return 0;
                      }
                      FUN_0089120c(local_28);
                      ExceptionList = local_14;
                      return 0;
                    }
                    break;
                  }
                  piVar4 = piVar4 + 1;
                } while (piVar4 != local_34);
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < uVar5);
          }
          if (local_38 != (int *)0x0) {
            FUN_0089120c(local_38);
          }
          local_38 = (int *)0x0;
          local_34 = (int *)0x0;
          local_30 = 0;
          puVar7 = local_48;
        }
        local_60 = local_60 + 3;
        local_58 = local_58 + 1;
      } while (local_58 < (uint)(iVar3 - iVar2));
    }
    if (puVar7 != (undefined4 *)0x0) {
      FUN_0089120c(puVar7);
    }
  }
  if (local_28 != (int *)0x0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return 1;
}

