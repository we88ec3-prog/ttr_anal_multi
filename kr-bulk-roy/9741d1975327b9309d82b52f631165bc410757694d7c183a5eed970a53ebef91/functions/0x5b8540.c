
void FUN_005b8540(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI != (int *)0x0) {
    iVar2 = (**(code **)(*unaff_EDI + 4))();
    if (iVar2 == 0x105ba) goto LAB_005b856e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_EDI = (int *)0x0;
LAB_005b856e:
  iVar2 = unaff_EDI[6];
  iVar1 = *(int *)(unaff_ESI + 0x254);
  *(int *)(iVar1 + 0xf4) = unaff_EDI[5];
  *(int *)(iVar1 + 0xf8) = iVar2;
  FUN_00596e00(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x254));
  return;
}

