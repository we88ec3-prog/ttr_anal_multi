
void FUN_005baaa0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))();
    if (iVar1 != 0x105ba) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  FUN_0045d0a0(*(undefined4 *)(param_1 + 0x298));
  return;
}

