
void FUN_00438300(int param_1,short *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  short local_8;
  
  puVar5 = (undefined4 *)(param_1 + 0x104);
  iVar6 = 2;
  do {
    (**(code **)(*(int *)*puVar5 + 0x94))(0);
    (**(code **)(*(int *)*puVar5 + 200))();
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  local_8 = *param_2;
  piVar7 = (int *)(param_1 + 0x10c);
  param_2 = (short *)0x0;
  do {
    piVar2 = piVar7 + -1;
    param_2 = (short *)((int)param_2 + 1);
    piVar7 = piVar7 + -1;
    (**(code **)(*(int *)*piVar2 + 0x94))(1);
    iVar3 = (int)local_8;
    local_8 = local_8 / 10;
    iVar6 = *piVar7;
    iVar3 = *(int *)(param_1 + 0x10c + (iVar3 % 10) * 4);
    if ((((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) &&
        (iVar4 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(), iVar4 == 0xbf6b)) &&
       (iVar6 = *(int *)(iVar6 + 0x94), *(int *)(iVar6 + 0x10) != iVar3)) {
      if (((iVar3 != 0) && (piVar2 = *(int **)(iVar3 + 8), piVar2 != (int *)0x0)) &&
         (piVar2[0x27] = piVar2[0x27] + 1, piVar2[0x27] == 1)) {
        (**(code **)(*piVar2 + 0x24))();
      }
      if ((*(int *)(iVar6 + 0x10) != 0) &&
         (piVar2 = *(int **)(*(int *)(iVar6 + 0x10) + 8), piVar2 != (int *)0x0)) {
        piVar1 = piVar2 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar2 + 0x28))();
        }
      }
      *(int *)(iVar6 + 0x10) = iVar3;
    }
    (**(code **)(*(int *)*piVar7 + 200))();
  } while (local_8 != 0);
  FUN_00749a00(*(int *)(param_1 + 0x150) - (2 - (int)param_2) * *(int *)(param_1 + 0x154),
               *(undefined4 *)(*(int *)(param_1 + 0xf4) + 0xc));
  (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  return;
}

