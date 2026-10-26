
void FUN_0043e0d0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar4 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f63e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005d6f30(param_1);
  FUN_0043c570(iVar4 + 1,uVar2);
  FUN_0043c570(iVar4 + 2);
  piVar1 = (int *)(in_ECX + 0x2a4);
  FUN_0046b6f0(iVar4 + 3);
  iVar4 = *piVar1;
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar4 + 0xa4) = 1;
  iVar4 = *piVar1;
  if (((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) &&
     (iVar3 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  param_1 = 0;
  FUN_0082ef00(&param_1);
  iVar4 = *piVar1;
  if (((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) &&
     (iVar4 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))(), iVar4 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(*(int *)*piVar1 + 0x94))(0);
  ExceptionList = local_10;
  return;
}

