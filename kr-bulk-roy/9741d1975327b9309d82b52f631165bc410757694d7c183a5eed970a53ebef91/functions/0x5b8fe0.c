
void FUN_005b8fe0(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bf) goto LAB_005b9011;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005b9011:
  FUN_006797b0(*(undefined4 *)(param_1 + 0x278),unaff_ESI[6],unaff_ESI[7]);
  return;
}

