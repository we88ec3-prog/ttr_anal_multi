
undefined4 FUN_008601c0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x7c);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x78); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0x28))(param_1);
  }
  (**(code **)(**(int **)(in_ECX + 0x74) + 0x58))(param_1);
  return 1;
}

