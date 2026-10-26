
void FUN_005baa50(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if ((unaff_ESI != (int *)0x0) && (iVar1 = (**(code **)(*unaff_ESI + 4))(), iVar1 != 0x105ba)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  FUN_00609330(*(undefined4 *)(param_1 + 0x294));
  return;
}

