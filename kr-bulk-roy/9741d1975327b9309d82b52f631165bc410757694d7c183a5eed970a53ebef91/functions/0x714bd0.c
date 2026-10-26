
void FUN_00714bd0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905a67;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(undefined4 **)(in_ECX + 0x100) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x100))(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *(undefined4 *)(in_ECX + 0x100) = 0;
  }
  local_8 = 1;
  FUN_00714eb0();
  FUN_0089120c(*(undefined4 *)(in_ECX + 0x104));
  ExceptionList = local_10;
  return;
}

