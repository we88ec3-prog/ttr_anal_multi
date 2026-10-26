
void FUN_006ba890(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d10e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (((uint)param_1[10] >> 8 & 1) == 0) {
    (**(code **)(*param_1 + 0xd0))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar2 = FUN_005c7190();
  if (iVar2 != 0) {
    param_1 = param_2;
    FUN_0082ef00(&param_1);
  }
  FUN_00745060();
  (**(code **)(*(int *)piVar1[0x20] + 200))();
  ExceptionList = local_10;
  return;
}

