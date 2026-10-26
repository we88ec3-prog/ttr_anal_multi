
void FUN_005bc0a0(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105c4) goto LAB_005bc0d1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005bc0d1:
  if ((*(uint *)(*(int *)(param_1 + 0x2e4) + 0x28) >> 8 & 1) == 0) {
    FUN_0042d0d0(*(int *)(param_1 + 0x2e4),(char)unaff_ESI[5]);
  }
  return;
}

