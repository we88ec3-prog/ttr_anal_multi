
void FUN_005ac8c0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar2 = (**(code **)(*unaff_ESI + 4))();
    if (iVar2 == 0x105cb) goto LAB_005ac8f1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005ac8f1:
  if ((*(uint *)(*(int *)(param_1 + 0x220) + 0x28) >> 8 & 1) != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x220) + 0xc0);
    *piVar1 = *piVar1 + unaff_ESI[5];
  }
  return;
}

