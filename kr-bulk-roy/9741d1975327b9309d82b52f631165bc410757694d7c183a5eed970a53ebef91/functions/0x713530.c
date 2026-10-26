
void FUN_00713530(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905a67;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = Package::CPackageMgr::vftable;
  local_8 = 0;
  if ((undefined4 *)in_ECX[0x41] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x41])(1,uVar1);
    in_ECX[0x41] = 0;
  }
  local_8 = 1;
  FUN_00714eb0();
  FUN_0089120c(in_ECX[0x42]);
  ExceptionList = local_10;
  return;
}

