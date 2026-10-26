
void FUN_00531930(undefined4 *param_1)

{
  undefined4 *in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d081;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *in_EDX;
    param_1[1] = in_EDX[1];
    param_1[2] = in_EDX[2];
    param_1[8] = 7;
    param_1[7] = 0;
    *(undefined2 *)(param_1 + 3) = 0;
    FUN_004026e0(in_EDX + 3,0,0xffffffff);
  }
  ExceptionList = local_10;
  return;
}

