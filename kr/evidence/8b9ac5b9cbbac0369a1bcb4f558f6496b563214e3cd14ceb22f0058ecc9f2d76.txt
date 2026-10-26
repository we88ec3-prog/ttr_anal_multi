
undefined4 FUN_004443b0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009371bb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007be770(**(undefined4 **)(in_ECX + 0xb4));
  FUN_0079c7d0(*(undefined4 *)(in_ECX + 0xb8));
  iVar2 = FUN_00891268(0x48,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00734010();
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xa0) = uVar3;
  FUN_007340c0(uVar3);
  ExceptionList = local_10;
  return 0;
}

