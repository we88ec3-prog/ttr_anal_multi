
void FUN_004cbf90(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009088f8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = in_ECX + 4;
  local_8 = 0;
  FUN_004cca50(local_18,**(undefined4 **)(in_ECX + 8),*(undefined4 **)(in_ECX + 8));
  FUN_0089120c(*(undefined4 *)(in_ECX + 8),uVar1);
  ExceptionList = local_10;
  return;
}

