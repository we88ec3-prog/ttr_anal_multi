
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005af270(void)

{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI == (int *)0x0) {
    *(undefined4 *)(unaff_ESI + 0x22c) = _DAT_00000014;
    return;
  }
  iVar1 = (**(code **)(*unaff_EDI + 4))();
  if (iVar1 == 0x105b9) {
    *(int *)(unaff_ESI + 0x22c) = unaff_EDI[5];
    return;
  }
  MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  *(undefined4 *)(unaff_ESI + 0x22c) = _DAT_00000014;
  return;
}

