
void FUN_0059dd10(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bf) goto LAB_0059dd41;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059dd41:
  FUN_004064a0((char)unaff_ESI[5],unaff_ESI[6],(char)unaff_ESI[7]);
  return;
}

