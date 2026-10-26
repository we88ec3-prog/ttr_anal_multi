
uint FUN_00528730(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  short *unaff_ESI;
  
  if (*unaff_ESI != 0x23) {
    return 0;
  }
  uVar1 = FUN_0049b1b0();
  uVar2 = FUN_0049b1b0();
  uVar3 = FUN_0049b1b0();
  return uVar3 & 0xff | ((uVar1 | 0xffffff00) << 8 | uVar2 & 0xff) << 8;
}

