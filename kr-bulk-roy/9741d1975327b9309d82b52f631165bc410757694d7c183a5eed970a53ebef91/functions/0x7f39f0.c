
void FUN_007f39f0(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  
  uVar1 = *(undefined4 *)(*param_1 + 0x10);
  uVar2 = *(undefined4 *)(*param_1 + 8);
  puVar3 = (undefined4 *)param_1[4];
  for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
    FUN_007f3210(uVar1,uVar2,*(undefined4 *)(puVar4[2] + 8),*(undefined4 *)(puVar4[2] + 4));
  }
  piVar5 = (int *)param_1[4];
  piVar6 = (int *)*piVar5;
  *piVar5 = (int)piVar5;
  *(int *)(param_1[4] + 4) = param_1[4];
  param_1[5] = 0;
  if (piVar6 != (int *)param_1[4]) {
    do {
      piVar5 = (int *)*piVar6;
      FUN_0089120c(piVar6);
      piVar6 = piVar5;
    } while (piVar5 != (int *)param_1[4]);
  }
  return;
}

