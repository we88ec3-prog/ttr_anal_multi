
void FUN_0077ea70(undefined4 param_1)

{
  int in_ECX;
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(in_ECX + 200);
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if (puVar1 != *(undefined4 **)(in_ECX + 0xcc)) {
    do {
      (**(code **)(*(int *)*puVar1 + 0x1c))(param_1);
      puVar1 = puVar1 + 1;
    } while (puVar1 != *(undefined4 **)(in_ECX + 0xcc));
  }
  puVar1 = *(undefined4 **)(in_ECX + 0xd8);
  if (puVar1 != *(undefined4 **)(in_ECX + 0xdc)) {
    do {
      (**(code **)(*(int *)*puVar1 + 0x1c))(param_1);
      puVar1 = puVar1 + 1;
    } while (puVar1 != *(undefined4 **)(in_ECX + 0xdc));
  }
  return;
}

