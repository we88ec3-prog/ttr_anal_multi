
void FUN_006ddbb0(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  undefined1 *unaff_ESI;
  
  uVar1 = FUN_00401ed0(in_EAX,0,0xffffffff);
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  FUN_00402bb0(uVar1);
  return;
}

