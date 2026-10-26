
void FUN_005adbe0(void)

{
  int *in_EAX;
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105bc) goto LAB_005adc15;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005adc15:
  iVar1 = in_EAX[5];
  piVar2 = (int *)**(int **)(in_ECX + 0x24c);
  if (piVar2 != *(int **)(in_ECX + 0x24c)) {
    do {
      if (*(int *)(((int *)piVar2[2])[0x43] + 0x1c) == *(int *)(iVar1 + 0x1c)) {
        (**(code **)(*(int *)piVar2[2] + 0xd4))();
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(in_ECX + 0x24c));
  }
  FUN_005adb70();
  return;
}

