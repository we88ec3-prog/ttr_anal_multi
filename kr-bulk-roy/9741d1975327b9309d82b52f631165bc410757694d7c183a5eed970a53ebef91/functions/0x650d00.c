
void FUN_00650d00(void)

{
  int iVar1;
  HWND hWnd;
  int *unaff_ESI;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bd) goto LAB_00650d2e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_00650d2e:
  if (unaff_ESI[5] == 0x6a7) {
    lParam = 1;
    wParam = 0;
    Msg = 0x10;
    hWnd = (HWND)FUN_006dfd60();
    PostMessageW(hWnd,Msg,wParam,lParam);
  }
  return;
}

