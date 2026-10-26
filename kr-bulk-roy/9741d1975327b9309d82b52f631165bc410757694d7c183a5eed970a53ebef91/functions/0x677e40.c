
void FUN_00677e40(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x110) + 0xcc) != 0) {
    FUN_0042c8e0(0);
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x110) + 0xcc);
  if ((iVar2 != 0) && (piVar1 = *(int **)(iVar2 + 0xdc), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 != 0x12d) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      return;
    }
    if (piVar1[0x92] != 0) {
      *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(piVar1[0x92] + 0x254);
      FUN_006767d0();
    }
  }
  return;
}

