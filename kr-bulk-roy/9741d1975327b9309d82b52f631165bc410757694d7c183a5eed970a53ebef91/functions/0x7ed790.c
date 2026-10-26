
/* WARNING: Removing unreachable block (ram,0x007ed883) */
/* WARNING: Removing unreachable block (ram,0x007ed88e) */
/* WARNING: Removing unreachable block (ram,0x007ed891) */

int * FUN_007ed790(int *param_1,undefined1 *param_2)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914690;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar5 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
  }
  local_8 = 0;
  cVar3 = FUN_006de110(param_1,0);
  if (cVar3 == '\0') {
    local_8 = 0xffffffff;
    piVar5 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))();
    }
    ExceptionList = local_10;
    return param_1;
  }
  local_8 = 2;
  piVar5 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if ((*(int *)piVar5[8] == 0) || (piVar1 = (int *)piVar5[0xc], *piVar1 < 1)) {
    uVar4 = (**(code **)(*piVar5 + 0x1c))();
  }
  else {
    *piVar1 = *piVar1 + -1;
    pbVar2 = *(byte **)piVar5[8];
    *(byte **)piVar5[8] = pbVar2 + 1;
    uVar4 = (uint)*pbVar2;
  }
  if (uVar4 != 0xffffffff) {
    *param_2 = (char)uVar4;
    local_8 = 1;
    piVar5 = (int *)FUN_007ed878();
    return piVar5;
  }
  local_8 = 1;
  piVar5 = (int *)FUN_007ed878();
  return piVar5;
}

