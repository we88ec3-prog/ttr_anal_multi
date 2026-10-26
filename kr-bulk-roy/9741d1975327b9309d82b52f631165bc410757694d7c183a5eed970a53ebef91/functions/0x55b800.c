
void FUN_0055b800(void)

{
  int *piVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090add6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)(in_ECX + 0x3c);
  local_8 = 1;
  FUN_00523e40(piVar1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (*piVar1 != 0) {
    FUN_0089120c(*piVar1);
  }
  *piVar1 = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  if (7 < *(uint *)(in_ECX + 0x2c)) {
    FUN_0089120c(*(undefined4 *)(in_ECX + 0x18));
  }
  *(undefined4 *)(in_ECX + 0x2c) = 7;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined2 *)(in_ECX + 0x18) = 0;
  ExceptionList = local_10;
  return;
}

