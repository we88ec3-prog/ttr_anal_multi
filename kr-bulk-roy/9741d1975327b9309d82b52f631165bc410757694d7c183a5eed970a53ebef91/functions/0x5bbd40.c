
void FUN_005bbd40(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  if ((*(uint *)(*(int *)(unaff_EDI + 700) + 0x28) >> 8 & 1) != 0) {
    if (unaff_ESI != (int *)0x0) {
      iVar1 = (**(code **)(*unaff_ESI + 4))();
      if (iVar1 == 0x105b9) {
        FUN_00436030(*(undefined4 *)(unaff_EDI + 700),(char)unaff_ESI[5]);
        return;
      }
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    FUN_00436030(*(undefined4 *)(unaff_EDI + 700),DAT_00000014);
  }
  return;
}

