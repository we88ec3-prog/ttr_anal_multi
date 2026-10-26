
void FUN_00418220(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 in_ECX;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ba) goto LAB_00418250;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_00418250:
  FUN_0075d6a0(in_EAX[5]);
  FUN_00414fc0(in_EAX[5],in_EAX[6]);
  FUN_00414ef0(in_ECX,in_EAX[6]);
  FUN_00415690();
  return;
}

