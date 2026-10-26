
void FUN_00527f60(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916f9b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00757640(in_ECX + 0x2c);
  if (7 < *(uint *)(in_ECX + 0x1c)) {
    FUN_0089120c(*(undefined4 *)(in_ECX + 8),uVar1);
  }
  *(undefined4 *)(in_ECX + 0x1c) = 7;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined2 *)(in_ECX + 8) = 0;
  ExceptionList = local_10;
  return;
}

