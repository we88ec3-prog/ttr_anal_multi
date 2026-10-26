
void FUN_005bbf20(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105ba) goto LAB_005bbf51;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005bbf51:
  FUN_004435e0(*(undefined4 *)(param_1 + 0x2d4),(char)unaff_ESI[5],unaff_ESI[6]);
  return;
}

