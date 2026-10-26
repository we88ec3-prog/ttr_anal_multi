
void FUN_0059d510(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if ((unaff_ESI != (int *)0x0) && (iVar1 = (**(code **)(*unaff_ESI + 4))(), iVar1 != 0x105b9)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  FUN_005cf450();
  return;
}

