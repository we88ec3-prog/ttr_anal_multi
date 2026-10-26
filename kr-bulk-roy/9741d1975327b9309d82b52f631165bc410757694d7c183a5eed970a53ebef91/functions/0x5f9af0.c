
void FUN_005f9af0(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ee2a;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  iVar3 = param_3 + -0x50 + param_2 * 0x50;
  if (0x1df < iVar3 - 1U) {
    FUN_006edb60(&DAT_00c0ddc0);
    ExceptionList = local_14;
    return;
  }
  iVar4 = DAT_00f94300 + 0x23a0 + iVar3 * 0x18;
  if (((*(int *)(DAT_00f94300 + 0x23ac + iVar3 * 0x18) == 0) || (*(int *)(iVar4 + 8) == 0)) ||
     (iVar4 == 0)) {
    ExceptionList = local_14;
    return;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar3 = *(int *)(DAT_00f94300 + 0x50d8);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (((iVar3 == 1) && (DAT_00f94300 != -0x16f8)) && (iVar3 = FUN_00508dd0(), iVar3 != 0)) {
    iVar4 = *(int *)(iVar4 + 8);
    if (iVar4 < 2) {
      FUN_005fa0f0(param_2,param_3,1);
      ExceptionList = local_14;
      return;
    }
    FUN_005f5d20(param_1,0xf4371,iVar4,iVar4,param_2,param_3,1,iVar3);
    ExceptionList = local_14;
    return;
  }
  local_20 = 0x196;
  iVar3 = FUN_005854b0();
  FUN_005740f0(&local_20);
  if (local_1c[0] == *(int *)(iVar3 + 4)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(uint *)(local_1c[0] + 0x24) < 8) {
    iVar3 = local_1c[0] + 0x10;
  }
  else {
    iVar3 = *(int *)(local_1c[0] + 0x10);
  }
  local_1c[0] = 0xbe;
  iVar4 = FUN_005854b0();
  FUN_005740f0(local_1c);
  if (local_20 == *(int *)(iVar4 + 4)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar5 = (undefined4 *)(local_20 + 0x10);
  if (7 < *(uint *)(local_20 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  FUN_00404b10(0xca,puVar5,iVar3,0,0);
  ExceptionList = local_14;
  return;
}

