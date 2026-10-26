
void FUN_006feb00(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_8;
  
  if (*(char *)(*(int *)(param_1 + 0x10) + 0x15) != '\x02') {
    if (param_2 + 1U < 0x40000000) {
      puVar3 = (undefined4 *)FUN_00700880(param_1,0,0,param_2 * 4);
    }
    else {
      puVar3 = (undefined4 *)FUN_00700860(param_1);
    }
    piVar1 = *(int **)(param_1 + 0x10);
    iVar5 = param_2;
    puVar7 = puVar3;
    if (0 < param_2) {
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
    }
    local_8 = 0;
    if (0 < piVar1[2]) {
      do {
        piVar4 = *(int **)(*piVar1 + local_8 * 4);
        if (piVar4 != (int *)0x0) {
          do {
            piVar2 = (int *)*piVar4;
            uVar6 = piVar4[2] & param_2 - 1U;
            *piVar4 = puVar3[uVar6];
            puVar3[uVar6] = piVar4;
            piVar4 = piVar2;
          } while (piVar2 != (int *)0x0);
        }
        local_8 = local_8 + 1;
      } while (local_8 < piVar1[2]);
    }
    FUN_00700880(param_1,*piVar1,piVar1[2] * 4,0);
    piVar1[2] = param_2;
    *piVar1 = (int)puVar3;
  }
  return;
}

