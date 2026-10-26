
void FUN_005b7610(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_EDI;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105b9) goto LAB_005b7641;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005b7641:
  iVar1 = FUN_006071b0(in_EAX[5]);
  if (iVar1 != 0) {
    FUN_00596e00(unaff_EDI,*(undefined4 *)(unaff_EDI + 0x290));
  }
  return;
}

