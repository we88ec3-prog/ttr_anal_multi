
void FUN_005bae30(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105ba) goto LAB_005bae61;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005bae61:
  FUN_00409da0(*(undefined4 *)(param_1 + 0x2a4),unaff_ESI[5],unaff_ESI[6]);
  return;
}

