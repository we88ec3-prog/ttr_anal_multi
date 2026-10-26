
void FUN_004817c0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_28 [4];
  undefined1 local_24;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009405be;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((*(int *)(param_1 + 300) == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (99 < *(int *)(param_1 + 0x130) - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar4 = *(int *)(param_1 + 0x130) * 0x20 + DAT_00f94300 + 0x16f8;
    if (((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 8) != 0)) && (iVar4 != 0)) {
      local_20 = *(undefined4 *)(iVar4 + 4);
      iVar1 = FUN_004034e0();
      FUN_008438c0(&local_20);
      if ((local_1c != *(int *)(iVar1 + 4)) && (iVar1 = *(int *)(local_1c + 0x10), iVar1 != 0)) {
        iVar2 = FUN_004034e0();
        local_24 = *(undefined1 *)(iVar1 + 0x5c);
        local_28[0] = *(undefined1 *)(iVar1 + 8);
        FUN_00827050(iVar2 + 0x10,local_28);
        puVar3 = (undefined4 *)FUN_008271c0();
        *(undefined4 *)(param_1 + 0x134) = *puVar3;
        *(undefined4 *)(param_1 + 0x138) = puVar3[1];
        FUN_00482ac0(puVar3 + 2);
        (**(code **)(**(int **)(param_1 + 0xfc) + 0x19c))
                  (*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 0xc),
                   *(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14));
        (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

