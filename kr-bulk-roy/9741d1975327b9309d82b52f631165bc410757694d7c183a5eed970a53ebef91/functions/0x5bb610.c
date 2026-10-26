
void FUN_005bb610(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int unaff_ESI;
  
  if (in_EAX != (int *)0x0) {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 == 0x105ba) goto LAB_005bb641;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005bb641:
  iVar2 = *(int *)(unaff_ESI + 0x2b8);
  if ((*(uint *)(iVar2 + 0x28) >> 8 & 1) != 0) {
    FUN_00457ba0(iVar2);
    FUN_00457f50();
    FUN_00457ae0(iVar2);
    return;
  }
  iVar1 = in_EAX[6];
  *(int *)(iVar2 + 0x150) = in_EAX[5];
  *(int *)(iVar2 + 0x154) = iVar1;
  FUN_00596e00(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x2b8));
  return;
}

