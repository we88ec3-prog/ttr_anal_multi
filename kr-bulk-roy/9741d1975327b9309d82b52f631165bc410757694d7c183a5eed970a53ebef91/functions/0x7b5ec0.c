
int * FUN_007b5ec0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009047eb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *param_1 = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  FUN_0089120c(param_1);
  ExceptionList = local_10;
  return param_1;
}

