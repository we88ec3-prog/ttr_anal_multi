
void FUN_005b9120(void)

{
  int *in_EAX;
  int iVar1;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105bf) goto LAB_005b9155;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005b9155:
  FUN_00679150(in_EAX[6],in_EAX[7]);
  return;
}

