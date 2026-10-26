
void FUN_005bbdb0(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105b9) goto LAB_005bbdde;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005bbdde:
  if ((*(uint *)(*(int *)(unaff_EDI + 0x2c8) + 0x28) >> 8 & 1) == 0) {
    FUN_0043cea0(*(int *)(unaff_EDI + 0x2c8),unaff_ESI[5]);
    FUN_00596e00(unaff_EDI,*(undefined4 *)(unaff_EDI + 0x2c8));
  }
  return;
}

