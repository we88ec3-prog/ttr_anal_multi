
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ff9c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ebac;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (param_1 == 1) {
    iVar3 = DAT_00f94300 + 0x16f8;
  }
  else {
    iVar3 = 0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (param_3 == 1) {
    iVar6 = DAT_00f94300 + 0x16f8;
  }
  else {
    iVar6 = 0;
  }
  if ((iVar3 != 0) && (iVar6 != 0)) {
    if (99 < param_2 - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar1 = param_2 * 0x20 + iVar3;
    if (((*(int *)(param_2 * 0x20 + 0xc + iVar3) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
       (iVar1 != 0)) {
      local_20 = *(int *)(iVar1 + 4);
      iVar3 = FUN_004034e0();
      FUN_008438c0(&local_20);
      if (local_1c == *(int *)(iVar3 + 4)) {
        local_20 = 0;
      }
      else {
        local_20 = *(int *)(local_1c + 0x10);
      }
      iVar3 = 1;
      if (0 < *(int *)(iVar6 + 0xca0)) {
        piVar5 = (int *)(iVar6 + 0x2c);
        do {
          if (*piVar5 == *(int *)(iVar1 + 0xc)) {
            if (iVar3 != 0) goto LAB_005ffb60;
            break;
          }
          iVar3 = iVar3 + 1;
          piVar5 = piVar5 + 8;
        } while (iVar3 <= *(int *)(iVar6 + 0xca0));
      }
LAB_005ffbdc:
      iVar3 = 1;
      if (0 < *(int *)(iVar6 + 0xca0)) {
        piVar5 = (int *)(iVar6 + 0x28);
        while ((piVar5[1] != 0 || (*piVar5 != 0))) {
          iVar3 = iVar3 + 1;
          piVar5 = piVar5 + 8;
          if (*(int *)(iVar6 + 0xca0) < iVar3) {
            ExceptionList = local_14;
            return;
          }
        }
        if (iVar3 != 0) {
LAB_005ffc1e:
          if ((_DAT_00fb1314 & 1) == 0) {
            _DAT_00fb1314 = _DAT_00fb1314 | 1;
            _atexit((_func_4879 *)&DAT_00bccf10);
          }
          FUN_004a3900(param_1,param_2,param_3,iVar3);
        }
      }
    }
  }
  ExceptionList = local_14;
  return;
LAB_005ffb60:
  if (iVar3 - 1U < 100) {
    iVar4 = iVar3 * 0x20 + iVar6;
    if ((*(int *)(iVar4 + 0xc) == 0) || (*(int *)(iVar4 + 8) == 0)) goto LAB_005ffb8a;
  }
  else {
    FUN_006edb60(&DAT_00c0ddc0);
LAB_005ffb8a:
    iVar4 = 0;
  }
  if (((param_1 != param_3) || (iVar3 != param_2)) &&
     ((iVar4 != 0 && (*(int *)(iVar4 + 8) < *(int *)(local_20 + 0xc))))) {
    if (iVar3 != 0) goto LAB_005ffc1e;
    goto LAB_005ffbdc;
  }
  iVar3 = iVar3 + 1;
  if (*(int *)(iVar6 + 0xca0) < iVar3) goto LAB_005ffbdc;
  piVar5 = (int *)(iVar3 * 0x20 + 0xc + iVar6);
  while (*piVar5 != *(int *)(iVar1 + 0xc)) {
    iVar3 = iVar3 + 1;
    piVar5 = piVar5 + 8;
    if (*(int *)(iVar6 + 0xca0) < iVar3) goto LAB_005ffbdc;
  }
  if (iVar3 == 0) goto LAB_005ffbdc;
  goto LAB_005ffb60;
}

