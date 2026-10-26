
void FUN_0062ec20(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  
  if (in_EAX == (int *)0x0) {
LAB_0062ec59:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0062ec59;
    }
  }
  if (in_EAX[5] != 0x6a7) {
    return;
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105ba) goto LAB_0062ec91;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_0062ec91:
  iVar1 = piVar2[5];
  if (iVar1 == 0) {
    FUN_0062ece0();
    return;
  }
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      FUN_0062f050(piVar2[6]);
    }
    return;
  }
  FUN_0062ed60();
  return;
}

