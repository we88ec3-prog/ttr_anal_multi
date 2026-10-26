
void FUN_007ac230(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = *(int **)*param_1;
  if (piVar3 != (int *)*param_1) {
    do {
      puVar1 = (undefined4 *)piVar3[2];
      FUN_007beb30(puVar1,param_2);
      if ((puVar1[3] == 0) || (*(int *)(puVar1[3] + 0x3c) != 0)) {
        uVar2 = 0;
        if ((int)(puVar1[6] - puVar1[5]) >> 2 != 0) {
          do {
            *(undefined4 *)(*(int *)(puVar1[5] + uVar2 * 4) + 0x58) = 0;
            uVar2 = uVar2 + 1;
          } while (uVar2 < (uint)((int)(puVar1[6] - puVar1[5]) >> 2));
        }
        if ((undefined4 *)puVar1[1] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)puVar1[1])(1);
          puVar1[1] = 0;
        }
        (**(code **)*puVar1)(1);
        piVar4 = (int *)*piVar3;
        if (piVar3 != (int *)*param_1) {
          *(int **)piVar3[1] = piVar4;
          *(int *)(*piVar3 + 4) = piVar3[1];
          FUN_0089120c(piVar3);
          param_1[1] = param_1[1] + -1;
        }
      }
      else {
        piVar4 = (int *)*piVar3;
      }
      piVar3 = piVar4;
    } while (piVar4 != (int *)*param_1);
  }
  return;
}

