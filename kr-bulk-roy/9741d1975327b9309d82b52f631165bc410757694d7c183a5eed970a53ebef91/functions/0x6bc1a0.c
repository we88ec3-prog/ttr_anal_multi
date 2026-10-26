
void FUN_006bc1a0(int param_1,int param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar3 = *(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2;
  if (*(uint *)(param_1 + 0xd8) <= uVar3) {
    return;
  }
  uVar4 = 0;
  if (uVar3 != 0) {
    piVar5 = *(int **)(param_1 + 0xf4);
    do {
      if (*piVar5 == param_2) {
        return;
      }
      uVar4 = uVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (uVar4 < uVar3);
  }
  puVar1 = *(undefined4 **)(param_1 + 0xf8);
  if (&param_2 < puVar1) {
    puVar2 = *(undefined4 **)(param_1 + 0xf4);
    if (puVar2 <= &param_2) {
      if (puVar1 == *(undefined4 **)(param_1 + 0xfc)) {
        FUN_006d6240();
      }
      if (*(undefined4 **)(param_1 + 0xf8) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0xf8) =
             *(undefined4 *)(*(int *)(param_1 + 0xf4) + ((int)&param_2 - (int)puVar2 >> 2) * 4);
      }
      goto LAB_006bc25d;
    }
  }
  if (puVar1 == *(undefined4 **)(param_1 + 0xfc)) {
    FUN_006d6240();
  }
  if (*(int **)(param_1 + 0xf8) != (int *)0x0) {
    **(int **)(param_1 + 0xf8) = param_2;
  }
LAB_006bc25d:
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 4;
  FUN_00826660(&local_c,&param_2);
  FUN_004ca160(local_c,local_8);
  *(int *)(param_1 + 0xdc) = param_2;
  if (param_3 != '\0') {
    *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
  }
  return;
}

