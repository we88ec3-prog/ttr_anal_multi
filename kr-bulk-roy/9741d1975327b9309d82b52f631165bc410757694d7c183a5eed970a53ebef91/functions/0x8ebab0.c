
void FUN_008ebab0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int unaff_EDI;
  uint local_18;
  uint local_14;
  char local_10 [4];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = *(uint *)(unaff_EDI + 0x2b8);
  uVar4 = 0;
  local_18 = 0;
  local_14 = 0;
  if (uVar1 != 0) {
    do {
      FUN_008ea840();
      uVar2 = local_18;
      if ((local_c != 0) && (local_14 = local_14 + 1, uVar2 = uVar4, 1 < local_14)) break;
      local_18 = uVar2;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
    if ((local_14 == 1) &&
       ((local_18 == 0 ||
        (((iVar3 = FUN_008b8d60(), iVar3 == 0 && (local_10[0] == '.')) &&
         (iVar3 = _strncmp(local_10,".notdef",8), iVar3 == 0)))))) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

