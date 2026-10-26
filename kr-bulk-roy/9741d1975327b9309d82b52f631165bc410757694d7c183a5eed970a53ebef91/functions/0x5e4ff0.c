
void FUN_005e4ff0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e238;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((-1 < unaff_EDI) && (unaff_EDI < 6)) {
    local_38 = 0x1c5;
    iVar2 = FUN_00585620(local_14);
    FUN_005740f0(&local_38);
    if (local_34 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar3 = FUN_004ed610();
    local_8 = 0;
    FUN_004041f0(uVar3,0,0xffffffff);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

