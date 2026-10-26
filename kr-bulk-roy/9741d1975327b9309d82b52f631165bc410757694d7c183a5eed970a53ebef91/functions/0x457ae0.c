
void FUN_00457ae0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0x154) % 5;
  piVar2 = (int *)(param_1 + 0x114);
  local_8 = 5;
  iVar3 = (*(int *)(param_1 + 0x154) / 5) * 5;
  do {
    FUN_007597b0(0);
    piVar2[10] = iVar3;
    *(undefined4 *)(*piVar2 + 0x154) = 0xffffffff;
    (**(code **)(*(int *)*piVar2 + 0x90))(iVar3 < *(int *)(param_1 + 0x150));
    (**(code **)(*(int *)*piVar2 + 200))();
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  (**(code **)(**(int **)(param_1 + 0x114 + iVar1 * 4) + 0xa0))(1);
  *(undefined4 *)(*(int *)(param_1 + 0x114 + iVar1 * 4) + 0x154) = 0xffffff00;
  return;
}

