
void FUN_005db3a0(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009485fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x2b8) != 0) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    param_1 = *(uint *)(uVar2 + 0x2c0);
    FUN_008438c0(&param_1);
    if (in_ECX == DAT_00f8d91c) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x10);
    }
    if (*(int *)(iVar3 + 0x68) != 0) {
      uVar1 = *(ushort *)(*(int *)(iVar3 + 0x68) + 8);
      iVar3 = FUN_00404ba0();
      iVar3 = *(int *)(iVar3 + 0x6928);
      param_1 = (uint)uVar1;
      FUN_004a4cc0(&param_1);
      if (((in_ECX == *(int *)(iVar3 + 0x14)) || (*(int *)(in_ECX + 0x10) == 0)) ||
         (*(int *)(*(int *)(in_ECX + 0x10) + 0xc) == 0)) {
        uVar4 = 1;
        goto LAB_005db477;
      }
    }
  }
  uVar4 = 0;
LAB_005db477:
  (**(code **)(**(int **)(uVar2 + 0x2b0) + 0x94))(uVar4);
  (**(code **)(**(int **)(uVar2 + 0x2b0) + 200))();
  ExceptionList = local_10;
  return;
}

