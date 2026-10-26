
void FUN_005b8710(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105b9) goto LAB_005b873e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005b873e:
  FUN_00677080(*(undefined4 *)(unaff_EDI + 0x274),unaff_ESI[5]);
  FUN_00596e00(unaff_EDI,*(undefined4 *)(unaff_EDI + 0x274));
  return;
}

