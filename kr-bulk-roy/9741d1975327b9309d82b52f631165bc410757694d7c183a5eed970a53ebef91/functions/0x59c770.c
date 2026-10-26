
void FUN_0059c770(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105c4) goto LAB_0059c7a1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059c7a1:
  FUN_00668520(*(undefined4 *)(param_1 + 0x1d0),(char)unaff_ESI[5]);
  return;
}

