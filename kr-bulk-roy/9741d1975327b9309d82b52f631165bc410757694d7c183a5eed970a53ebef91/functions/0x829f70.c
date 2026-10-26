
void FUN_00829f70(int *param_1)

{
  char cVar1;
  int *piVar2;
  void **ppvVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b5d8;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_1 + 0x21);
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, cVar1 == '\0') {
    FUN_00829f70(param_1[2]);
    piVar2 = (int *)*param_1;
    local_8 = 0;
    FUN_005540c0(*(undefined4 *)param_1[5],(undefined4 *)param_1[5]);
    local_8 = 0xffffffff;
    FUN_0089120c(param_1[5],uVar4);
    FUN_0089120c(param_1);
    ppvVar3 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  ExceptionList = local_10;
  return;
}

