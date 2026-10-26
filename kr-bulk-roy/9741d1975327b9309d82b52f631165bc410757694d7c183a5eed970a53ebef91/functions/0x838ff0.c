
void FUN_00838ff0(int param_1)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  uVar5 = 0;
  if (uVar4 != 0) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 4) + uVar5 * 4);
      if ((piVar1[5] != 0) && (piVar2 = (int *)piVar1[2], piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 0x30))(piVar2);
        piVar1[5] = 0;
      }
      pcVar3 = *(code **)(*piVar1 + 8);
      piVar1[4] = 0;
      (*pcVar3)();
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar4);
  }
  FUN_00839060(param_1);
  return;
}

