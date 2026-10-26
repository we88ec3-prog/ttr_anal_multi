
void FUN_00757640(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911cbb;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_006d7120(*(undefined4 *)param_1[0xb],(undefined4 *)param_1[0xb]);
  FUN_0089120c(param_1[0xb],uVar2);
  piVar1 = (int *)param_1[7];
  piVar3 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(undefined4 *)(param_1[7] + 4) = param_1[7];
  param_1[8] = 0;
  if (piVar3 != (int *)param_1[7]) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3,uVar2);
      piVar3 = piVar1;
    } while (piVar1 != (int *)param_1[7]);
  }
  FUN_0089120c(param_1[7],uVar2);
  if (7 < (uint)param_1[5]) {
    FUN_0089120c(*param_1,uVar2);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

