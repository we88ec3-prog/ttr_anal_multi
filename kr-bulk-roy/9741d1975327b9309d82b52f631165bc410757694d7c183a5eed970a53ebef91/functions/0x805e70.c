
void FUN_00805e70(int param_1)

{
  LPCRITICAL_SECTION p_Var1;
  int *piVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090999c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00805f50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  p_Var1 = *(LPCRITICAL_SECTION *)(param_1 + 0xa0d4);
  if (p_Var1 != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(p_Var1);
    FUN_0089120c(p_Var1);
    *(undefined4 *)(param_1 + 0xa0d4) = 0;
  }
  piVar2 = *(int **)(param_1 + 0xa074);
  piVar3 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*(int *)(param_1 + 0xa074) + 4) = *(int *)(param_1 + 0xa074);
  *(undefined4 *)(param_1 + 0xa078) = 0;
  if (piVar3 != *(int **)(param_1 + 0xa074)) {
    do {
      piVar2 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0xa074));
  }
  FUN_0089120c(*(undefined4 *)(param_1 + 0xa074));
  p_Var1 = *(LPCRITICAL_SECTION *)(param_1 + 0x501c);
  if (p_Var1 != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(p_Var1);
    FUN_0089120c(p_Var1);
    *(undefined4 *)(param_1 + 0x501c) = 0;
  }
  ExceptionList = local_10;
  return;
}

