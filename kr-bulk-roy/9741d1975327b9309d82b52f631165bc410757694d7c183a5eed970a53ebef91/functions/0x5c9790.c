
void FUN_005c9790(int *param_1)

{
  char cVar1;
  int *piVar2;
  void **ppvVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916758;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_1 + 0x55);
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, cVar1 == '\0') {
    FUN_005c9790(param_1[2]);
    piVar2 = (int *)*param_1;
    local_8 = 2;
    FUN_005c8ed0(*(undefined4 *)param_1[0x12],(undefined4 *)param_1[0x12]);
    FUN_0089120c(param_1[0x12],uVar4);
    if (7 < (uint)param_1[0xf]) {
      FUN_0089120c(param_1[10],uVar4);
    }
    local_8 = 0xffffffff;
    param_1[0xf] = 7;
    param_1[0xe] = 0;
    *(undefined2 *)(param_1 + 10) = 0;
    if (7 < (uint)param_1[8]) {
      FUN_0089120c(param_1[3]);
    }
    param_1[8] = 7;
    param_1[7] = 0;
    *(undefined2 *)(param_1 + 3) = 0;
    FUN_0089120c(param_1);
    ppvVar3 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x55);
  }
  ExceptionList = local_10;
  return;
}

