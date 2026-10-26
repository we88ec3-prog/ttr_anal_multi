
void FUN_008ef4b0(void)

{
  uint uVar1;
  uint uVar2;
  uint *in_EDX;
  int unaff_ESI;
  
  uVar1 = *in_EDX;
  uVar2 = 0;
  if ((uVar1 & 1) != 0) {
    uVar2 = 0x23;
  }
  if (((uVar1 & 2) != 0) && (*(char *)(unaff_ESI + 0x119) != '\0')) {
    uVar2 = uVar2 | 0x80;
  }
  if (((uVar1 & 4) != 0) && (*(char *)(unaff_ESI + 0x11a) != '\0')) {
    uVar2 = uVar2 | 0x100;
  }
  if (((uVar1 & 0x20) != 0) && (*(char *)(unaff_ESI + 0x25c) != '\0')) {
    uVar2 = uVar2 | 0x1000;
  }
  *in_EDX = uVar2;
  return;
}

