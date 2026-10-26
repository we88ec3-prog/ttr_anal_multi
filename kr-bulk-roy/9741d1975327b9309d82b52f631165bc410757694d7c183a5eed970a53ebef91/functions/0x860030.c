
void FUN_00860030(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if ((*(int **)(in_ECX + 0x74) != (int *)0x0) && (*(int *)(in_ECX + 0xa8) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x74) + 0x1c))(param_1);
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x7c);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x78); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0x1c))(param_1);
  }
  return;
}

