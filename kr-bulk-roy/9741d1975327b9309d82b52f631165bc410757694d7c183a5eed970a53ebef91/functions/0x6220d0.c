
void FUN_006220d0(void)

{
  uint uVar1;
  undefined4 uVar2;
  int in_EDX;
  int unaff_EDI;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e268;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_EDX + 8) == *(int *)(*(int *)(unaff_EDI + 0x11c) + 0x20)) {
    uVar2 = FUN_0040ef80(uVar1);
    local_8 = 0;
    FUN_00757800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(unaff_EDI + 0x120) + 200))();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

