
void FUN_00659160(void)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  int local_10;
  
  FUN_0074a980();
  FUN_00429430();
  FUN_006ae700();
  FUN_00685430();
  iVar3 = 0x2bc0;
  do {
    FUN_0043c570(iVar3 + -200);
    FUN_00643ce0(iVar3 + -100);
    FUN_0043c570(iVar3);
    iVar3 = iVar3 + 1000;
  } while (iVar3 < 0x3b60);
  local_10 = 4;
  do {
    FUN_00749c50();
    FUN_00749d00();
    FUN_00749c50();
    FUN_00749d00();
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  iVar3 = *(int *)(*(int *)(in_ECX + 0x158) + 0xcc);
  piVar1 = (int *)(in_ECX + 0x158);
  if (iVar3 != 0) {
    FUN_00408920(iVar3,0x14);
  }
  local_10 = 0;
  do {
    iVar3 = *(int *)(*piVar1 + 0xcc);
    if ((((iVar3 != 0) && (-1 < local_10)) &&
        (local_10 < *(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2)) &&
       (piVar2 = *(int **)(*(int *)(iVar3 + 0xa8) + local_10 * 4), piVar2 != (int *)0x0)) {
      iVar3 = (**(code **)(*piVar2 + 4))();
      if (iVar3 == 0x12d) {
        FUN_00749d00();
      }
      else {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      }
    }
    local_10 = local_10 + 1;
  } while (local_10 < 0x14);
  FUN_00749c50();
  FUN_00749d00();
  FUN_00749c50();
  FUN_00749c50();
  *(undefined4 *)(*(int *)(*piVar1 + 0xd0) + 0xd8) = 0x1e;
  (**(code **)(**(int **)(in_ECX + 0x114) + 0x94))(0);
  (**(code **)(*(int *)*piVar1 + 0x94))(0);
  return;
}

