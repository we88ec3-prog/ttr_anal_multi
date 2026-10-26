
void FUN_00428100(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iStack_14;
  int local_c;
  
  local_c = 0;
  piVar3 = (int *)(param_1 + 0x124);
  do {
    FUN_00749a00(0,local_c + 0x1e);
    FUN_00749c50();
    FUN_00749d00();
    iVar2 = *(int *)(*(int *)(*piVar3 + 0xec) + 0xcc);
    if (iVar2 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(iVar2 + 0xa8);
    }
    iVar2 = piVar1[1] - *piVar1 >> 2;
    (**(code **)(*(int *)*piVar3 + 0x94))(iVar2 != 0);
    FUN_00749a00(9,iStack_14 + 0x45);
    iStack_14 = iStack_14 + iVar2 * 0x28;
    FUN_00749c50();
    FUN_00749d00();
    (**(code **)(*(int *)piVar3[-3] + 200))();
    (**(code **)(*(int *)*piVar3 + 200))();
    local_c = local_c + 0x1e;
    piVar3 = piVar3 + 1;
  } while (local_c < 0x5a);
  FUN_00749d00();
  return;
}

