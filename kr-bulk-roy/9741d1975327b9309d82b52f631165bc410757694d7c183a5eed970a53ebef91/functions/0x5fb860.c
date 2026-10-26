
void FUN_005fb860(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI[4] == 0xf4397) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105ba) {
      FUN_005fcc60(unaff_ESI[6]);
      return;
    }
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    FUN_005fcc60(uRam00000018);
  }
  return;
}

