
int * FUN_00721910(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091202a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  local_8 = 0;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (*(int *)(*(int *)(*param_1 + 4) + 0x3c + (int)param_1) != 0)) {
    FUN_006de0c0();
  }
  local_8 = 1;
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) {
    local_8 = 2;
    (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1) + 0x24))
              (param_2,param_3,param_4);
    local_8 = 1;
    piVar2 = (int *)FUN_007219fb(param_3,param_4);
    return piVar2;
  }
  FUN_00431a90(0);
  local_8 = 4;
  cVar1 = thunk_FUN_0089ccbb();
  if (cVar1 == '\0') {
    FUN_006ddfe0();
  }
  local_8 = 0xffffffff;
  piVar2 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))();
  }
  ExceptionList = local_10;
  return param_1;
}

