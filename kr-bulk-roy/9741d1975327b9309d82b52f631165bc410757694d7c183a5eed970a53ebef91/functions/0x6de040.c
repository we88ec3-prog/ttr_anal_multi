
void FUN_006de040(int *param_1)

{
  int *piVar1;
  char cVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0090f448;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0;
  cVar2 = thunk_FUN_0089ccbb(DAT_00d61f20 ^ (uint)&stack0xffffffec);
  if (cVar2 == '\0') {
    FUN_006ddfe0();
  }
  local_4 = 0xffffffff;
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
  }
  ExceptionList = local_c;
  return;
}

