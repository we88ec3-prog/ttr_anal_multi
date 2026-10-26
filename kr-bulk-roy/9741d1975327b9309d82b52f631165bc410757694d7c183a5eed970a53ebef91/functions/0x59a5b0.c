
void FUN_0059a5b0(int param_1)

{
  int *in_EAX;
  int iVar1;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ba) goto LAB_0059a5e5;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059a5e5:
  FUN_0060abf0(in_EAX[5]);
  FUN_0060ad30(*(undefined4 *)(param_1 + 0x1d8),in_EAX[6]);
  (**(code **)(**(int **)(param_1 + 0x1d8) + 0xd0))();
  return;
}

