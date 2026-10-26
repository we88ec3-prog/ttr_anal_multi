
void FUN_00604800(undefined4 param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105c1) goto LAB_00604831;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_00604831:
  if (unaff_ESI[5] == 0xf43a5) {
    FUN_00604ba0(param_1,*(undefined4 *)(unaff_ESI[7] + 4),*(undefined4 *)(unaff_ESI[7] + 8),
                 unaff_ESI[6]);
  }
  return;
}

