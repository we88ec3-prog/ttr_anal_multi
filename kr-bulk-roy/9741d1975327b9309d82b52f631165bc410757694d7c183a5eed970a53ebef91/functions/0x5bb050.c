
void FUN_005bb050(int param_1)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  
  if (in_EAX != (int *)0x0) {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 == 0x105c0) goto LAB_005bb084;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005bb084:
  iVar2 = *(int *)(param_1 + 0x2b0);
  if ((*(uint *)(iVar2 + 0x28) >> 8 & 1) == 0) {
    FUN_00596e00(param_1,iVar2);
  }
  else if (*(int *)(iVar2 + 0x60) != 0) {
    FUN_0074a010(iVar2);
  }
  iVar2 = in_EAX[5];
  if ((iVar2 != 0) && (iVar1 = *(int *)(param_1 + 0x2b0), *(int *)(iVar1 + 0x118) != iVar2)) {
    *(int *)(iVar1 + 0x118) = iVar2;
    FUN_004751e0(iVar1);
  }
  FUN_00475510(in_EAX[7],in_EAX[8]);
  return;
}

