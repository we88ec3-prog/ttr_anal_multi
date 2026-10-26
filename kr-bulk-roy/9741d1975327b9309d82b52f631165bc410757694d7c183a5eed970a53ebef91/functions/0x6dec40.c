
undefined4 FUN_006dec40(void)

{
  HWND hWnd;
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x2c) != 0) {
    return 0x80004005;
  }
  hWnd = (HWND)FUN_006dfd60();
  *(HWND *)(unaff_ESI + 8) = hWnd;
  *(undefined4 *)(unaff_ESI + 0x30) = 1;
  ShowWindow(hWnd,5);
  uVar1 = FUN_006e76c0();
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  ShowWindow(*(HWND *)(unaff_ESI + 8),0);
  return uVar1;
}

