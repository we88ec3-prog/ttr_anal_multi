
void FUN_005cf450(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  int unaff_EDI;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e268;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar1 = *(code **)(**(int **)(unaff_EDI + 0x308) + 0x94);
  if (in_ECX == 0xffff) {
    (*pcVar1)(0,uVar2);
    (**(code **)(**(int **)(unaff_EDI + 0x308) + 200))();
  }
  else {
    (*pcVar1)(1,uVar2);
    (**(code **)(**(int **)(unaff_EDI + 0x308) + 200))();
    (**(code **)(**(int **)(unaff_EDI + 0x304) + 0x94))(1);
    uVar3 = FUN_0040ef80();
    local_8 = 0;
    FUN_00757800(uVar3);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(unaff_EDI + 0x304) + 200))();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

