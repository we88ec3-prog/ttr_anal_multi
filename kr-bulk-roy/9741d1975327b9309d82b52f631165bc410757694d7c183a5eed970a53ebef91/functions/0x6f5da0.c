
void FUN_006f5da0(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int unaff_ESI;
  bool bVar5;
  byte *local_6c;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(uint *)(unaff_ESI + 0x14) <= *(uint *)(unaff_ESI + 0x28)) {
    FUN_006f5f30();
    __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006f8180(&DAT_00c4271c);
  pcVar4 = "method";
  do {
    bVar1 = *local_6c;
    bVar5 = bVar1 < (byte)*pcVar4;
    if (bVar1 != *pcVar4) {
LAB_006f5e2f:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_006f5e34;
    }
    if (bVar1 == 0) break;
    bVar1 = local_6c[1];
    bVar5 = bVar1 < (byte)pcVar4[1];
    if (bVar1 != pcVar4[1]) goto LAB_006f5e2f;
    local_6c = local_6c + 2;
    pcVar4 = pcVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_006f5e34:
  if ((iVar3 == 0) && (param_1 == 1)) {
    FUN_006f5f30();
    __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006f5f30();
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

