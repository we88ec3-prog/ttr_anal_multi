
void FUN_005af180(void)

{
  int *in_EAX;
  int iVar1;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ba) goto LAB_005af1b4;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005af1b4:
  FUN_006b8eb0(in_EAX[5],in_EAX[6]);
  return;
}

