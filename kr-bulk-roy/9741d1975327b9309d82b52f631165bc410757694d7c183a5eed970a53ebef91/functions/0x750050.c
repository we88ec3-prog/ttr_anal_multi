
void FUN_00750050(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x1480);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[2] + 0x40))(param_1);
    (**(code **)(**(int **)(puVar2[2] + 8) + 0xcc))();
  }
  piVar3 = *(int **)(in_ECX + 0x1480);
  piVar4 = (int *)*piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(*(int *)(in_ECX + 0x1480) + 4) = *(int *)(in_ECX + 0x1480);
  *(undefined4 *)(in_ECX + 0x1484) = 0;
  if (piVar4 != *(int **)(in_ECX + 0x1480)) {
    do {
      piVar3 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar3;
    } while (piVar3 != (int *)*(int *)(in_ECX + 0x1480));
  }
  return;
}

