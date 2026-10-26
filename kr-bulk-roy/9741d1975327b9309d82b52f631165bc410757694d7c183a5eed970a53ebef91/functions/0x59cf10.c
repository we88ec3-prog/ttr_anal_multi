
void FUN_0059cf10(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105ba) goto LAB_0059cf41;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059cf41:
  FUN_005fd1b0(*(undefined4 *)(param_1 + 0x168),unaff_ESI[6]);
  return;
}

