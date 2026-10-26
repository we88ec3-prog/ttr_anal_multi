
void FUN_0063af90(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105b9) goto LAB_0063afbe;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0063afbe:
  iVar1 = unaff_ESI[5];
  if (iVar1 == 0) {
    FUN_0063ad80();
    return;
  }
  if (iVar1 == 1) {
    FUN_0063ae20();
    return;
  }
  if (iVar1 != 2) {
    return;
  }
  FUN_0063add0();
  return;
}

