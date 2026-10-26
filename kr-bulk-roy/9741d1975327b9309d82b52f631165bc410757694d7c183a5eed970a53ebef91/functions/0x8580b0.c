
void FUN_008580b0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  
  FUN_00858240(*(undefined4 *)(param_1 + 4),param_1);
  piVar1 = *(int **)(param_1 + 4);
  for (piVar2 = piVar1 + -4; piVar2 != piVar1; piVar2 = piVar2 + 4) {
    if (*piVar2 != 0) {
      FUN_0089120c(*piVar2);
    }
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar2[2] = 0;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x10;
  *param_2 = param_3;
  return;
}

