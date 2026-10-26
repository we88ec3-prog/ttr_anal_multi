
void FUN_004556d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = param_2;
  uVar4 = *(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2;
  if (2 < uVar4) {
    return;
  }
  uVar5 = 0;
  if (uVar4 != 0) {
    piVar6 = *(int **)(param_1 + 0x154);
    do {
      if (*piVar6 == param_2) {
        return;
      }
      uVar5 = uVar5 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar5 < uVar4);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x158);
  if (&param_2 < puVar1) {
    puVar2 = *(undefined4 **)(param_1 + 0x154);
    if (puVar2 <= &param_2) {
      if (puVar1 == *(undefined4 **)(param_1 + 0x15c)) {
        FUN_006d6240();
      }
      if (*(undefined4 **)(param_1 + 0x158) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x158) =
             *(undefined4 *)(*(int *)(param_1 + 0x154) + ((int)&param_2 - (int)puVar2 >> 2) * 4);
      }
      goto LAB_00455787;
    }
  }
  if (puVar1 == *(undefined4 **)(param_1 + 0x15c)) {
    FUN_006d6240();
  }
  if (*(int **)(param_1 + 0x158) != (int *)0x0) {
    **(int **)(param_1 + 0x158) = iVar3;
  }
LAB_00455787:
  *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + 4;
  FUN_00826660(&local_c,&param_2);
  FUN_004ca160(local_c,local_8);
  *(int *)(param_1 + 0x174) = iVar3;
  return;
}

