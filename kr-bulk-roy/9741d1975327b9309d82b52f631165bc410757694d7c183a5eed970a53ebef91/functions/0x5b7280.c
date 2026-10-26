
void FUN_005b7280(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if ((in_EAX != (int *)0x0) && (iVar1 = (**(code **)(*in_EAX + 4))(), iVar1 != 0x105b9)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  iVar1 = FUN_004fb910();
  if (iVar1 != 0) {
    FUN_00636520(*(undefined4 *)(iVar1 + 4),0,0);
    FUN_0074a010(*(undefined4 *)(unaff_ESI + 0x224));
    FUN_00596e00(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x224));
  }
  return;
}

