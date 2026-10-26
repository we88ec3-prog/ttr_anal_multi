
undefined4 FUN_0077f6a0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xcc);
  for (puVar2 = *(undefined4 **)(in_ECX + 200); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0x58))(param_1);
  }
  puVar1 = *(undefined4 **)(in_ECX + 0xdc);
  for (puVar2 = *(undefined4 **)(in_ECX + 0xd8); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0x28))(param_1);
  }
  return 1;
}

