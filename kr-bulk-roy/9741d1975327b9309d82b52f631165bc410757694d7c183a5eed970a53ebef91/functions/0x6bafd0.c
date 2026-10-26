
void FUN_006bafd0(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092124e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x24c) = param_1;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_8 = 0xffffffff;
  uVar1 = *(undefined4 *)(in_ECX + 0x24c);
  iVar3 = FUN_005c7190();
  if (iVar3 != 0) {
    param_1 = uVar1;
    FUN_0082ef00(&param_1);
  }
  FUN_00745060();
  ExceptionList = local_10;
  return;
}

