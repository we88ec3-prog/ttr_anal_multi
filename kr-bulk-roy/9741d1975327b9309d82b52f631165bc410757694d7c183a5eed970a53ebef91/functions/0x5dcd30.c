
void FUN_005dcd30(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092185c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005d6f30(param_1);
  FUN_0043c570(iVar3 + 1,uVar2);
  FUN_0046b6f0(iVar3 + 2);
  FUN_0046b6f0(iVar3 + 3);
  FUN_0046b6f0(iVar3 + 4);
  FUN_0046b6f0(iVar3 + 6);
  FUN_0046b6f0(iVar3 + 7);
  FUN_0046b6f0(iVar3 + 8);
  piVar1 = (int *)(in_ECX + 0x2c4);
  FUN_0046b6f0(iVar3 + 9);
  FUN_0043c570(iVar3 + 10);
  iVar3 = *(int *)(in_ECX + 0x2c0);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *piVar1;
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  param_1 = 0;
  FUN_0082ef00(&param_1);
  if (local_20 == DAT_00f945c4) {
    param_1 = 0;
  }
  else {
    param_1 = *(undefined4 *)(local_20 + 0x10);
  }
  iVar3 = *piVar1;
  if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) &&
     (iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
    FUN_0077b200();
  }
  iVar3 = *(int *)(in_ECX + 0x2a4);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *(int *)(in_ECX + 0x2a4);
  if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) &&
     (iVar4 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar4 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar3 + 0x94) + 0x4c) = 1;
  }
  iVar3 = *(int *)(in_ECX + 0x2ac);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *(int *)(in_ECX + 0x2ac);
  if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) &&
     (iVar4 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar4 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar3 + 0x94) + 0x4c) = 1;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  if (DAT_00f943e4 != 0) {
    param_1 = 999999;
    FUN_0082ef00(&param_1);
  }
  FUN_00745060();
  (**(code **)(**(int **)(in_ECX + 0x2b0) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 700) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x2c0) + 0x94))(0);
  (**(code **)(*(int *)*piVar1 + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x2c8) + 0x94))(0);
  ExceptionList = local_10;
  return;
}

