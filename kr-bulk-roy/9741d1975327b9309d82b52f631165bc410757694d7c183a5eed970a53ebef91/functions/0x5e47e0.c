
void FUN_005e47e0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  int unaff_EDI;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d870;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = FUN_00483f00(param_2,uVar1);
  local_8 = 0;
  FUN_004041f0(uVar2,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  if (in_ECX != unaff_EDI) {
    uVar2 = FUN_004068f0();
    local_8 = 1;
    FUN_004041f0(uVar2,0,0xffffffff);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  FUN_00404300(L"<br>",4);
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

