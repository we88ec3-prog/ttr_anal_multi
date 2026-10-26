
/* WARNING: Removing unreachable block (ram,0x006ddda9) */
/* WARNING: Removing unreachable block (ram,0x006dddb3) */
/* WARNING: Removing unreachable block (ram,0x006dddb6) */

int * FUN_006ddcc0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912220;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0;
  param_1[3] = 0;
  piVar4 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))();
  }
  uVar6 = 1;
  local_8 = 0;
  piVar4 = param_1;
  cVar3 = FUN_006de110(param_1,1);
  if (cVar3 != '\0') {
    local_8 = 2;
    uVar5 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1) + 0x20))
                      (param_2,param_3,param_4);
    puVar1 = (uint *)(param_1 + 2);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + (uint)uVar5;
    param_1[3] = param_1[3] + (int)((ulonglong)uVar5 >> 0x20) + (uint)CARRY4(uVar2,(uint)uVar5);
    local_8 = 1;
    piVar4 = (int *)FUN_006ddd99(param_3,param_4,piVar4,uVar6);
    return piVar4;
  }
  local_8 = 0xffffffff;
  piVar4 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))();
  }
  ExceptionList = local_10;
  return param_1;
}

