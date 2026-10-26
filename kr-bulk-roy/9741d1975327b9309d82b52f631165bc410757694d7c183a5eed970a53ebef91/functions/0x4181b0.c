
void FUN_004181b0(void)

{
  undefined4 uVar1;
  int *in_EAX;
  int iVar2;
  int in_ECX;
  
  if (in_EAX != (int *)0x0) {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 == 0x105b9) goto LAB_004181e4;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_004181e4:
  uVar1 = *(undefined4 *)(in_ECX + 0x1a4);
  *(int *)(in_ECX + 0x1a8) = in_EAX[5];
  FUN_00414fc0(*(undefined4 *)(in_ECX + 0x1a0),uVar1);
  FUN_00414ef0(in_ECX,uVar1);
  FUN_00415690();
  return;
}

