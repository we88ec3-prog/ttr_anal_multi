
void FUN_0059d4c0(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105c4) goto LAB_0059d4f1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059d4f1:
  (**(code **)(**(int **)(param_1 + 400) + 0x90))((char)unaff_ESI[5]);
  return;
}

