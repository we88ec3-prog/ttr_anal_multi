
void FUN_00858b10(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  undefined4 in_EDX;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x18) == 0) {
    iVar1 = *(int *)(in_ECX + 0xc);
    if (iVar1 == 3) {
      iVar1 = *(int *)(in_ECX + 0x10);
      if (iVar1 == 1) {
        __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc,in_EDX,0,3,5,6,7);
        return;
      }
      if (iVar1 == 3) {
        __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc,in_EDX,0,3,5,6,7);
        return;
      }
      if (iVar1 == 4) {
        __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc,in_EDX,0,3,5,6,7);
        return;
      }
    }
    else {
      if ((((iVar1 == 9) || (iVar1 == 8)) || (iVar1 == 7)) || ((iVar1 == 6 || (iVar1 == 5)))) {
        __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc,in_EDX,0,3,5,6,7);
        return;
      }
      if (iVar1 == 2) {
        __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc,in_EDX,0,3,5,6,7);
        return;
      }
      if (iVar1 == 1) {
        __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc,in_EDX,0,3,5,6,7);
        return;
      }
    }
  }
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc,in_EDX,0,3,5,6,7);
  return;
}

