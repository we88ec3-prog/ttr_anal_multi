
void FUN_00852370(int *param_1)

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
  cVar1 = *(char *)((int)param_1 + 0x1d);
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, cVar1 == '\0') {
    FUN_00852370(param_1[2]);
    piVar2 = (int *)*param_1;
    local_8 = 0;
    FUN_004ca160(*(undefined4 *)param_1[4],(undefined4 *)param_1[4]);
    local_8 = 0xffffffff;
    FUN_0089120c(param_1[4],uVar4);
    FUN_0089120c(param_1);
    ppvVar3 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x1d);
  }
  ExceptionList = local_10;
  return;
}

