
bool FUN_006e7a60(void)

{
  BOOL BVar1;
  tagMSG local_20;
  
  FUN_006dfd60();
  local_20.message = 0;
  BVar1 = PeekMessageW(&local_20,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    TranslateMessage(&local_20);
    DispatchMessageW(&local_20);
  }
  return BVar1 != 0;
}

