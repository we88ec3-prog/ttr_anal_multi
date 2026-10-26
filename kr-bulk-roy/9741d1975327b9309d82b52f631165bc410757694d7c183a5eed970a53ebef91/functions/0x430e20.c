
void FUN_00430e20(int *param_1)

{
  int *piVar1;
  char cVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910e98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  cVar2 = thunk_FUN_0089ccbb(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (cVar2 == '\0') {
    FUN_006ddfe0();
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
  }
  ExceptionList = local_10;
  return;
}

