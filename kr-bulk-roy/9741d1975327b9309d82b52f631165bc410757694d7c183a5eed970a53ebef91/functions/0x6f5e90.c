
void FUN_006f5e90(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_ESI;
  int local_60;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = FUN_006f7dd0();
  if (iVar3 != 0) {
    FUN_006f8180(&DAT_00c4277c);
    if (0 < local_60) {
      FUN_006f5580();
      __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <= *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44))
  {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(unaff_ESI + 8);
  uVar4 = FUN_006fec70();
  *puVar1 = uVar4;
  puVar1[2] = 4;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

