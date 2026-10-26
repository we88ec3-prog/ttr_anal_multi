
void FUN_0081d680(int *param_1)

{
  char cVar1;
  int *piVar2;
  void **ppvVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009115d3;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_1 + 0x41);
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, cVar1 == '\0') {
    FUN_0081d680(param_1[2]);
    piVar2 = (int *)*param_1;
    local_8 = 1;
    FUN_0081cbb0(*(undefined4 *)param_1[0xd],(undefined4 *)param_1[0xd]);
    FUN_0089120c(param_1[0xd],uVar4);
    local_8 = 0xffffffff;
    if (7 < (uint)param_1[10]) {
      FUN_0089120c(param_1[5],uVar4);
    }
    param_1[10] = 7;
    param_1[9] = 0;
    *(undefined2 *)(param_1 + 5) = 0;
    FUN_0089120c(param_1);
    ppvVar3 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x41);
  }
  ExceptionList = local_10;
  return;
}

