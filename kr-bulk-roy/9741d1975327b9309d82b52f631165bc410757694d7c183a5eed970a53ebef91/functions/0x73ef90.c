
void FUN_0073ef90(int *param_1)

{
  char cVar1;
  int *piVar2;
  void **ppvVar3;
  uint uVar4;
  int *piVar5;
  undefined1 local_20 [4];
  int *local_1c;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ca10;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_1 + 0x39);
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, cVar1 == '\0') {
    FUN_0073ef90(param_1[2]);
    piVar2 = (int *)*param_1;
    piVar5 = param_1 + 3;
    local_1c = param_1 + 10;
    local_8 = 1;
    local_18 = piVar5;
    FUN_0073f170(local_20,*(undefined4 *)param_1[0xb],(undefined4 *)param_1[0xb]);
    FUN_0089120c(param_1[0xb],uVar4);
    local_8 = 0xffffffff;
    if (7 < (uint)param_1[8]) {
      FUN_0089120c(*piVar5,uVar4);
    }
    param_1[8] = 7;
    param_1[7] = 0;
    *(undefined2 *)piVar5 = 0;
    FUN_0089120c(param_1);
    ppvVar3 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x39);
  }
  ExceptionList = local_10;
  return;
}

