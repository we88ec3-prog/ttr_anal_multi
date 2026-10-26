
void FUN_0059c1b0(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105b9) goto LAB_0059c1e1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059c1e1:
  iVar1 = *(int *)(*(int *)(param_1 + 0x180) + 0xf4);
  if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 0)) && (unaff_ESI[5] == 0)) {
    FUN_0062e490(*(int *)(param_1 + 0x180));
  }
  return;
}

