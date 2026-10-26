
void FUN_007b25e0(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  undefined1 *unaff_EDI;
  
  uVar1 = FUN_0049ee10(in_EAX,0);
  *(undefined4 *)(unaff_EDI + 0x14) = 0xf;
  *(undefined4 *)(unaff_EDI + 0x10) = 0;
  *unaff_EDI = 0;
  FUN_00402bb0(uVar1);
  return;
}

