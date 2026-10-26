
void FUN_00766030(void)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cc2b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00765af0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar1 = FUN_00891268(0x38);
  local_8 = 0;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00757200(iVar1);
  }
  local_8 = 0xffffffff;
  FUN_00757c60(iVar1,in_ECX,0,*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(iVar1 + 0x10));
  FUN_007bb350();
  FUN_00766390(0,0,0);
  FUN_00767fa0();
  ExceptionList = local_10;
  return;
}

