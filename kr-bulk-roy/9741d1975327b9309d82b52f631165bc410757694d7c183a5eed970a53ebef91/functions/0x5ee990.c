
void FUN_005ee990(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((*(int *)(in_ECX + 0x184) != 0) &&
      (iVar1 = *(int *)(*(int *)(in_ECX + 0x184) + 0x58), 0 < iVar1)) && (iVar1 < 7)) {
    uVar3 = 0x14f;
    FUN_00585620(0x14f,uVar2);
    FUN_00585330(uVar3);
    uVar3 = FUN_004ed610();
    local_8 = 0;
    FUN_00757800(uVar3);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x194) + 0x154) = 0xffffffff;
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

