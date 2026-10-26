
void FUN_005b8f40(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105ba) goto LAB_005b8f71;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005b8f71:
  FUN_00604d50(*(undefined4 *)(param_1 + 0x280),unaff_ESI[5],unaff_ESI[6]);
  return;
}

