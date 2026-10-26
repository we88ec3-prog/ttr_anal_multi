
void FUN_0059a540(int param_1)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  
  if (in_EAX != (int *)0x0) {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 == 0x105c5) goto LAB_0059a571;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059a571:
  piVar1 = *(int **)(*(int *)(param_1 + 0x20c) + 0x114);
  FUN_00460230(piVar1,in_EAX[7]);
  if ((char)in_EAX[5] != '\0') {
    (**(code **)(*piVar1 + 4))();
  }
  return;
}

