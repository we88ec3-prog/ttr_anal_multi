
void FUN_0045dcc0(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint local_84;
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
  local_1c = DAT_00d61f20 ^ (uint)&local_84;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  FUN_0045d930(local_78,param_1);
  local_c = 0;
  if ((local_70 != -1) && (local_6c != 0xffffffff)) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_0051c120(uVar3);
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_c = (uint)local_c._1_3_ << 8;
    }
    local_84 = local_6c;
    FUN_008438c0(&local_84);
    if (((local_80 != DAT_00f8d91c) && (iVar4 = *(int *)(local_80 + 0x10), iVar4 != 0)) &&
       (*(int *)(iVar4 + 0x40) == 0)) {
      local_80 = *(int *)(iVar4 + 0x54);
      if (local_80 != 0) {
        local_84 = local_84 & 0xffffff00;
        FUN_00409560(local_68,local_64);
        iVar4 = FUN_004dc700(local_68,local_64);
        if (iVar4 != 0) {
          local_84 = CONCAT31(local_84._1_3_,*(undefined1 *)(iVar4 + 0x30));
        }
        FUN_00404c10();
        iVar4 = FUN_0051d6d0();
        if (iVar4 != 0) {
          piVar5 = *(int **)(*(int *)(iVar4 + 0x54) + 0x148);
          piVar1 = *(int **)(*(int *)(iVar4 + 0x54) + 0x14c);
          if (piVar5 != piVar1) {
            uVar3 = (int)piVar1 - (int)piVar5 >> 2;
            uVar6 = 0;
            local_7c = uVar3;
            if (uVar3 != 0) {
              do {
                if ((*(short *)(*piVar5 + 8) == 0x18) &&
                   (cVar2 = FUN_0045cc80(*(undefined1 *)(local_80 + 8),
                                         *(undefined1 *)(local_80 + 0x58),local_84),
                   uVar3 = local_7c, cVar2 != '\0')) {
                  FUN_00609030();
                  goto LAB_0045de71;
                }
                uVar6 = uVar6 + 1;
                piVar5 = piVar5 + 1;
              } while (uVar6 < uVar3);
              FUN_00609030();
              goto LAB_0045de71;
            }
          }
        }
      }
      FUN_00609030();
      goto LAB_0045de71;
    }
  }
  if (7 < local_4c) {
    FUN_0089120c(local_60);
  }
LAB_0045de71:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_84);
  return;
}

