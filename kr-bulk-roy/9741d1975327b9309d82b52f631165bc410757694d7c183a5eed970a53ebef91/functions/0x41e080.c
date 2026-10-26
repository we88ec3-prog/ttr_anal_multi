
void FUN_0041e080(int param_1,byte param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00927c9e;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  *(undefined4 *)(param_1 + 0x30) = 0x40000000;
  *(undefined4 *)(param_1 + 0x34) = 0x437f0000;
  *(undefined4 *)(param_1 + 0x38) = 0x3f333333;
  *(undefined1 *)(param_1 + 0x2c) = 1;
  param_1 = param_1 + (uint)param_2 * 0x3c;
  *(undefined4 *)(param_1 + 0x30) = 0x40000000;
  *(undefined4 *)(param_1 + 0x34) = 0x437f0000;
  *(undefined4 *)(param_1 + 0x38) = 0x3f333333;
  *(undefined1 *)(param_1 + 0x2c) = 1;
  iVar4 = FUN_0089289d(uVar3);
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3c) + (iVar4 % 3) * 8);
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 4 + (iVar4 % 3) * 8);
  if ((DAT_00fb72a4 & 1) == 0) {
    DAT_00fb72a4 = DAT_00fb72a4 | 1;
    local_c = 0;
    FUN_0049f850();
    _atexit((_func_4879 *)&LAB_00bccfe0);
    local_c = 0xffffffff;
  }
  FUN_004a07b0(&DAT_00fb72a8,uVar1,uVar2);
  ExceptionList = local_14;
  return;
}

