
void FUN_0052a270(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091021e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_0052a440(**(undefined4 **)(param_1 + 0x40),*(undefined4 **)(param_1 + 0x40));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x40),uVar1);
  if (7 < *(uint *)(param_1 + 0x34)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0x20),uVar1);
  }
  *(undefined4 *)(param_1 + 0x34) = 7;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined2 *)(param_1 + 0x20) = 0;
  if (7 < *(uint *)(param_1 + 0x18)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 4),uVar1);
  }
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  ExceptionList = local_10;
  return;
}

