
void FUN_0059a4e0(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105b9) goto LAB_0059a515;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059a515:
  iVar1 = FUN_00665150(unaff_ESI[5]);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(param_1 + 0x1d4) + 0xd0))();
  }
  return;
}

