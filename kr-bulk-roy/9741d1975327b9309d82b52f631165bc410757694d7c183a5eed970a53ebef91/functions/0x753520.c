
void FUN_00753520(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int in_EAX;
  int *piVar4;
  
  FUN_00750350();
  puVar1 = *(undefined4 **)(in_EAX + 0x1420);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (*(int *)(in_EAX + 0x13c4) != 0) {
      (**(code **)(*(int *)puVar2[2] + 0xd4))();
      (**(code **)(**(int **)(in_EAX + 0x13c4) + 0x74))(puVar2[2]);
    }
    if ((int *)puVar2[2] != (int *)0x0) {
      (**(code **)(*(int *)puVar2[2] + 0x1c))(1);
      puVar2[2] = 0;
    }
  }
  piVar3 = *(int **)(in_EAX + 0x1420);
  piVar4 = (int *)*piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(*(int *)(in_EAX + 0x1420) + 4) = *(int *)(in_EAX + 0x1420);
  *(undefined4 *)(in_EAX + 0x1424) = 0;
  if (piVar4 != *(int **)(in_EAX + 0x1420)) {
    do {
      piVar3 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar3;
    } while (piVar3 != (int *)*(int *)(in_EAX + 0x1420));
  }
  return;
}

