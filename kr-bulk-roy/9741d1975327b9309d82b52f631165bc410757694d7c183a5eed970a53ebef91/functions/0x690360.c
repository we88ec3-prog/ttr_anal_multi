
void FUN_00690360(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bd) goto LAB_00690391;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_00690391:
  if (unaff_ESI[5] != 0x6a7) {
    return;
  }
  FUN_006903b0();
  return;
}

