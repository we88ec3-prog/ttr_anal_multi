
void FUN_0070d5f0(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int local_20 [7];
  
  local_20[6] = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_20[3] = 0x61754c1b;
  local_20[4] = 0x4010051;
  local_20[5] = 0x80404;
  iVar2 = FUN_006fee90(local_20,0xc);
  if (iVar2 != 0) {
    FUN_0070cc10();
  }
  uVar3 = 0xc;
  iVar2 = 0;
  do {
    if (*(int *)((int)local_20 + iVar2 + 0xc) != *(int *)((int)local_20 + iVar2)) {
      FUN_0070cc10();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar3 = uVar3 - 4;
    iVar2 = iVar2 + 4;
  } while (3 < uVar3);
  __security_check_cookie(local_20[6] ^ (uint)&stack0xfffffffc);
  return;
}

