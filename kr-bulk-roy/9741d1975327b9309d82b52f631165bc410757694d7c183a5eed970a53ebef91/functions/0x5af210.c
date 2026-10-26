
void FUN_005af210(void)

{
  int *in_EAX;
  int iVar1;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105bf) goto LAB_005af244;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005af244:
  FUN_006b0660(in_EAX[5],in_EAX[6],in_EAX[7]);
  return;
}

