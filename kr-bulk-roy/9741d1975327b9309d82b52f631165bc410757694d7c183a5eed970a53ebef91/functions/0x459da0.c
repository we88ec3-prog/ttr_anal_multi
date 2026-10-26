
void FUN_00459da0(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f63e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005d6f30(param_1);
  FUN_0043c570(iVar2 + 1,uVar3);
  piVar1 = (int *)(in_ECX + 0x2a0);
  FUN_0046b6f0(iVar2 + 2);
  (**(code **)(*(int *)*piVar1 + 0x94))(*(undefined1 *)(in_ECX + 0x2a4));
  iVar2 = *piVar1;
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar2 + 0xa4) = 1;
  iVar2 = *piVar1;
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar4 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar4 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  if (DAT_00f943e4 != 0) {
    param_1 = 999999;
    FUN_0082ef00(&param_1);
  }
  FUN_00745060();
  ExceptionList = local_10;
  return;
}

