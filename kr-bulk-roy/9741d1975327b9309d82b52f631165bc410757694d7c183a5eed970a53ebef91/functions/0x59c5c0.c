
void FUN_0059c5c0(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105ba) goto LAB_0059c5f1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059c5f1:
  if ((uint)unaff_ESI[5] < 6) {
    (**(code **)(**(int **)(param_1 + 0x1ac) + 0xd4))();
  }
  return;
}

