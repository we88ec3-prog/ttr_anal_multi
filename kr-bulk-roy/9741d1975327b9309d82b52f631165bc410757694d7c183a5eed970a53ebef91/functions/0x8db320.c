
uint FUN_008db320(void)

{
  uint uVar1;
  byte *pbVar2;
  char in_DL;
  undefined4 *unaff_ESI;
  
  pbVar2 = (byte *)*unaff_ESI;
  uVar1 = 0;
  for (; in_DL != '\0'; in_DL = in_DL + -1) {
    uVar1 = uVar1 << 8 | (uint)*pbVar2;
    pbVar2 = pbVar2 + 1;
  }
  *unaff_ESI = pbVar2;
  return uVar1;
}

