
void FUN_005b7590(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105c4) goto LAB_005b75c1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005b75c1:
  FUN_0068c5b0(*(undefined4 *)(param_1 + 0x238),(char)unaff_ESI[5]);
  return;
}

