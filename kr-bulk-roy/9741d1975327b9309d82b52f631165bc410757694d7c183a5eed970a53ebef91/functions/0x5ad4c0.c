
void FUN_005ad4c0(void)

{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI == (int *)0x0) {
    *(undefined1 *)(unaff_ESI + 0x244) = DAT_00000014;
    return;
  }
  iVar1 = (**(code **)(*unaff_EDI + 4))();
  if (iVar1 == 0x105c4) {
    *(char *)(unaff_ESI + 0x244) = (char)unaff_EDI[5];
    return;
  }
  MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  *(undefined1 *)(unaff_ESI + 0x244) = DAT_00000014;
  return;
}

