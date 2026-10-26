
void FUN_0062d650(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  
  if (in_EAX == (int *)0x0) {
LAB_0062d686:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0062d686;
    }
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105cc) goto LAB_0062d6b5;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_0062d6b5:
  if (in_EAX[5] == 0x6a7) {
    iVar1 = piVar2[6];
  }
  else {
    if (in_EAX[5] != 0x6a8) {
      return;
    }
    iVar1 = piVar2[7];
  }
  FUN_0062d6f0(piVar2[5],iVar1,piVar2[8]);
  FUN_0062ccd0();
  return;
}

