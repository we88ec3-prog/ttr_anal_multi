
void FUN_0070ad90(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_006f7dd0();
  FUN_006f8180(&DAT_00c43598);
  puVar1 = *(undefined4 **)(in_ECX + 8);
  *puVar1 = puVar1[-8];
  puVar1[1] = puVar1[-7];
  puVar1[2] = puVar1[-6];
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
  FUN_006f59b0();
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

