
void FUN_0081b070(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905136;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  if (*param_1 != 0) {
    FUN_0089120c(*param_1,uVar2);
    *param_1 = 0;
  }
  piVar1 = param_1 + 1;
  FUN_00523e40(piVar1);
  piVar3 = param_1 + 5;
  FUN_00523e40(piVar3);
  if (*piVar3 != 0) {
    FUN_0089120c(*piVar3,uVar2);
  }
  *piVar3 = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (*piVar1 != 0) {
    FUN_0089120c(*piVar1,uVar2);
  }
  *piVar1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  ExceptionList = local_10;
  return;
}

