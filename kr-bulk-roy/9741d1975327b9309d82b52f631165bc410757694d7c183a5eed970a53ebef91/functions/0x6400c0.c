
void FUN_006400c0(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 in_ECX;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ba) goto LAB_006400f4;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_006400f4:
  if (in_EAX[6] == 0) {
    FUN_0063f310();
    return;
  }
  FUN_0063f3c0(in_ECX);
  return;
}

