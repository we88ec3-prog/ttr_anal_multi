
void FUN_00558c10(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LONG LVar1;
  
  LVar1 = GetWindowLongW(param_1,-0x15);
  if (LVar1 == 0) {
    DefWindowProcW(param_1,param_2,param_3,param_4);
    return;
  }
  FUN_00558c60(LVar1,param_2,param_3,param_4);
  return;
}

