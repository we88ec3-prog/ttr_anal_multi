
void FUN_00733980(int *param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915a90;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0;
  param_1[3] = 0;
  piVar2 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  uVar6 = 1;
  local_8 = 0;
  cVar4 = FUN_006de110(param_1,1);
  local_8 = 1;
  if (cVar4 == '\0') {
    FUN_00733aaf(uVar6);
    return;
  }
  local_8 = 2;
  piVar2 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if ((*(int *)piVar2[8] == 0) || (*(int *)piVar2[0xc] < 1)) {
    uVar5 = (**(code **)(*piVar2 + 0x18))();
  }
  else {
    uVar5 = (uint)**(byte **)piVar2[8];
  }
  if (uVar5 == 0xffffffff) {
    local_8 = 1;
    FUN_00733aaf(uVar6);
    return;
  }
  piVar2 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if ((*(int *)piVar2[8] != 0) && (piVar3 = (int *)piVar2[0xc], 0 < *piVar3)) {
    *piVar3 = *piVar3 + -1;
    *(int *)piVar2[8] = *(int *)piVar2[8] + 1;
    puVar1 = (uint *)(param_1 + 2);
    uVar5 = *puVar1;
    *puVar1 = *puVar1 + 1;
    param_1[3] = param_1[3] + (uint)(0xfffffffe < uVar5);
    local_8 = 1;
    FUN_00733aaf(uVar6);
    return;
  }
  (**(code **)(*piVar2 + 0x1c))();
  puVar1 = (uint *)(param_1 + 2);
  uVar5 = *puVar1;
  *puVar1 = *puVar1 + 1;
  param_1[3] = param_1[3] + (uint)(0xfffffffe < uVar5);
  local_8 = 1;
  FUN_00733aaf(uVar6);
  return;
}

