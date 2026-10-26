
void FUN_005b7440(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f942c0 == '\0') {
    iVar1 = *(int *)(param_1 + 0x24c);
    (**(code **)(**(int **)(iVar1 + 0x110) + 0x90))(param_2);
    (**(code **)(**(int **)(iVar1 + 0x100) + 0x90))(param_2);
    (**(code **)(**(int **)(iVar1 + 0x108) + 0x90))(0);
    (**(code **)(**(int **)(iVar1 + 0x104) + 0x90))(0);
    FUN_006905f0(unaff_EDI);
    if (unaff_EDI != 0) {
      (**(code **)(**(int **)(param_1 + 0x24c) + 0xd0))();
      ExceptionList = local_14;
      return;
    }
    piVar2 = *(int **)(param_1 + 0x24c);
    if (((uint)piVar2[10] >> 8 & 1) == 0) {
      FUN_00596e00(param_1,piVar2);
    }
    else if (((uint)piVar2[10] >> 8 & 1) != 0) {
      (**(code **)(*piVar2 + 0xd4))();
      ExceptionList = local_14;
      return;
    }
  }
  ExceptionList = local_14;
  return;
}

