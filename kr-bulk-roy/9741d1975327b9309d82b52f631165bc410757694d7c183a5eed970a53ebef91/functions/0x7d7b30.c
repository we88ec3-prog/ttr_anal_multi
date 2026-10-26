
void FUN_007d7b30(void)

{
  int iVar1;
  undefined4 in_EDX;
  undefined1 local_e0 [216];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = FUN_007d7c50(3,local_e0);
  if (iVar1 != 0) {
    iVar1 = FUN_007d7c50(iVar1,in_EDX);
    if (iVar1 != 0) {
      iVar1 = FUN_007d7c50(iVar1,local_e0);
      if (iVar1 != 0) {
        iVar1 = FUN_007d7c50(iVar1,in_EDX);
        if (iVar1 != 0) {
          iVar1 = FUN_007d7c50(iVar1,local_e0);
          if (iVar1 != 0) {
            FUN_007d7c50(iVar1,in_EDX);
          }
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

