
void FUN_0059dcc0(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if ((unaff_ESI != (int *)0x0) && (iVar1 = (**(code **)(*unaff_ESI + 4))(), iVar1 != 0x105bc)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  FUN_0061d6b0(*(undefined4 *)(param_1 + 0x1e0));
  return;
}

