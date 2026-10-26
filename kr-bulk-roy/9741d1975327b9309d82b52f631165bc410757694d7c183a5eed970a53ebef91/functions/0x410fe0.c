
void FUN_00410fe0(void)

{
  int *in_EAX;
  int iVar1;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105bd) goto LAB_00411014;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_00411014:
  if (in_EAX[5] == 0x6a7) {
    FUN_00411bd0();
  }
  return;
}

