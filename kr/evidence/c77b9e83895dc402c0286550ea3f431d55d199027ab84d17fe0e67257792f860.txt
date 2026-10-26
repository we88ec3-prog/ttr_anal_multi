
void FUN_00544b90(void)

{
  int in_ECX;
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (puVar1 != *(undefined4 **)(in_ECX + 8)) {
    do {
      (**(code **)(*(int *)*puVar1 + 0x14))();
      puVar1 = puVar1 + 1;
    } while (puVar1 != *(undefined4 **)(in_ECX + 8));
  }
  return;
}

