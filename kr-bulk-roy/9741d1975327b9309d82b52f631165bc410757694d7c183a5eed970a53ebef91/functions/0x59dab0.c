
void FUN_0059dab0(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105c4) goto LAB_0059dae7;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059dae7:
  iVar1 = *(int *)(param_1 + 0x164);
  *(char *)(iVar1 + 0x37c) = (char)unaff_ESI[5];
  FUN_005cd210();
  FUN_005cd3c0(iVar1);
  (**(code **)(**(int **)(param_1 + 0x164) + 200))();
  return;
}

