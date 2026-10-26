
void FUN_00481970(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((*(int *)(param_1 + 0x124) == 1) && (iVar3 = DAT_00f94300 + 0x16f8, iVar3 != 0)) {
    if (99 < *(int *)(param_1 + 0x128) - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar2 = *(int *)(param_1 + 0x128) * 0x20;
    iVar1 = iVar2 + iVar3;
    if (((*(int *)(iVar2 + 0xc + iVar3) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)) {
      local_20 = *(undefined4 *)(iVar1 + 4);
      iVar3 = FUN_004034e0();
      FUN_008438c0(&local_20);
      if ((local_1c != *(int *)(iVar3 + 4)) && (*(int *)(local_1c + 0x10) != 0)) {
        (**(code **)(**(int **)(param_1 + 0xf8) + 0x19c))
                  (*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc),
                   *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
        (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

