
/* WARNING: Removing unreachable block (ram,0x008de11e) */

int FUN_008de0a0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *unaff_EDI;
  
  iVar2 = FUN_008b97e0();
  if (iVar2 != 0) {
    return iVar2;
  }
  cVar1 = FUN_008b9a40();
  *unaff_EDI = cVar1;
  unaff_EDI[0x14] = '\0';
  unaff_EDI[0x15] = '\0';
  unaff_EDI[0x16] = '\0';
  unaff_EDI[0x17] = '\0';
  if (cVar1 != '\0') {
    if (cVar1 == '\x03') {
      uVar3 = FUN_008b9ab0();
      if ((uVar3 & 0xffff) != 0) {
        *(uint *)(unaff_EDI + 0xc) = (uVar3 & 0xffff) * 3 + 2;
        goto LAB_008de109;
      }
    }
    return 3;
  }
  *(undefined4 *)(unaff_EDI + 0xc) = param_1;
LAB_008de109:
  iVar2 = FUN_008bc7a0();
  return iVar2;
}

