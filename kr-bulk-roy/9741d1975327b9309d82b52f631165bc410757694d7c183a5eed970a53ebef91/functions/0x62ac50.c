
void FUN_0062ac50(int param_1)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  int local_8;
  
  if (in_EAX == (int *)0x0) {
LAB_0062ac87:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0062ac87;
    }
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105cc) goto LAB_0062acb2;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_0062acb2:
  if (in_EAX[5] == 0x6a7) {
    FUN_0062b4e0(piVar2[5],piVar2[6],piVar2[8]);
  }
  else {
    if (in_EAX[5] != 0x6a8) {
      return;
    }
    local_8 = piVar2[5];
    FUN_0062daa0(&local_8);
    if ((param_1 != *(int *)(param_1 + 0x104)) &&
       ((uint)piVar2[8] < (uint)(*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40) >> 2))) {
      *(int *)(*(int *)(param_1 + 0x40) + piVar2[8] * 4) = piVar2[7];
    }
  }
  FUN_0062b1d0();
  *(undefined4 *)(param_1 + 0x118) = 0;
  return;
}

