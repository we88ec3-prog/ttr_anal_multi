
void FUN_00425e20(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  int unaff_EDI;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(unaff_EDI + 0x248) + 0x19c))(0xffffffff,*in_ECX,0,0,uVar1);
  (**(code **)(**(int **)(unaff_EDI + 0x248) + 200))();
  FUN_00426ec0();
  local_8 = 0;
  FUN_00757710();
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x24c) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

