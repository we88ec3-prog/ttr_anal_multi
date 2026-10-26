
void FUN_00733b00(int *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915a60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0;
  param_1[3] = 0;
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  uVar3 = 1;
  local_8 = 0;
  cVar2 = FUN_006de110(param_1,1);
  local_8 = 1;
  if (cVar2 != '\0') {
    local_8 = 2;
    piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
    if ((*(int *)piVar1[8] == 0) || (*(int *)piVar1[0xc] < 1)) {
      (**(code **)(*piVar1 + 0x18))();
    }
    local_8 = 1;
    FUN_00733bdf(uVar3);
    return;
  }
  FUN_00733bdf(uVar3);
  return;
}

