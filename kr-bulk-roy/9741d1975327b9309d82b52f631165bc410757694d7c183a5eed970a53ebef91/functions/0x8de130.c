
char FUN_008de130(uint param_1)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *unaff_EDI;
  
  if (*unaff_EDI == '\0') {
    return *(char *)(param_1 + *(int *)(unaff_EDI + 8));
  }
  if (*unaff_EDI == '\x03') {
    if (param_1 - *(int *)(unaff_EDI + 0x10) < *(uint *)(unaff_EDI + 0x14)) {
      return unaff_EDI[0x18];
    }
    puVar2 = *(undefined1 **)(unaff_EDI + 8);
    pcVar3 = puVar2 + 2;
    uVar6 = (uint)CONCAT11(*puVar2,puVar2[1]);
    while( true ) {
      if (param_1 < uVar6) {
        return '\0';
      }
      cVar1 = *pcVar3;
      pcVar4 = pcVar3 + 3;
      uVar5 = (uint)CONCAT11(pcVar3[1],pcVar3[2]);
      if (param_1 < uVar5) break;
      pcVar3 = pcVar4;
      uVar6 = uVar5;
      if (puVar2 + *(int *)(unaff_EDI + 0xc) <= pcVar4) {
        return '\0';
      }
    }
    unaff_EDI[0x18] = cVar1;
    *(uint *)(unaff_EDI + 0x10) = uVar6;
    *(uint *)(unaff_EDI + 0x14) = uVar5 - uVar6;
    return cVar1;
  }
  return '\0';
}

