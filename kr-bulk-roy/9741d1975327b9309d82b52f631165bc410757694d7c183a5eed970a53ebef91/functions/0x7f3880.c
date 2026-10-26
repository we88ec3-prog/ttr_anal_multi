
void FUN_007f3880(int *param_1)

{
  int *piVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009046cb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    param_1[1] = 0;
  }
  if (*param_1 != 0) {
    FUN_007f3930();
    *param_1 = 0;
  }
  piVar1 = (int *)param_1[4];
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(param_1[4] + 4) = param_1[4];
  param_1[5] = 0;
  if (piVar2 != (int *)param_1[4]) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)param_1[4]);
  }
  FUN_0089120c(param_1[4]);
  ExceptionList = local_10;
  return;
}

