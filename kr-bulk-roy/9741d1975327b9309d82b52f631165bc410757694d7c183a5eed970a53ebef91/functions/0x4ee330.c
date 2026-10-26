
void FUN_004ee330(void)

{
  uint uVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *unaff_EDI;
  
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (1 < (in_ECX - (int)unaff_EDI) / 0xc) {
    puVar2 = (undefined4 *)(in_ECX + -0xc);
    do {
      *puVar2 = *unaff_EDI;
      puVar2[1] = unaff_EDI[1];
      puVar2[2] = unaff_EDI[2];
      FUN_004ee580();
      puVar2 = puVar2 + -3;
    } while (1 < ((int)puVar2 + (0xc - (int)unaff_EDI)) / 0xc);
  }
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

