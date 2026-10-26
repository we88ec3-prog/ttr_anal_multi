
void FUN_00745930(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x74);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (((uint)((int *)puVar2[2])[10] >> 8 & 1) != 0) {
      (**(code **)(*(int *)puVar2[2] + 0xd4))();
    }
  }
  if ((*(uint *)(in_ECX + 0x28) & 0x100) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x100;
  }
  if ((((*(int *)(in_ECX + 0x24) != 0) &&
       (*(int *)(in_ECX + 0x34) != *(int *)(in_ECX + 0x2c) &&
        -1 < *(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x2c))) &&
      (*(int *)(in_ECX + 0x38) != *(int *)(in_ECX + 0x30) &&
       -1 < *(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x30))) &&
     ((*(uint *)(in_ECX + 0x28) & 0x100000) == 0)) {
    FUN_00753020(*(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(in_ECX + 0x30),
                 *(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x38));
  }
  return;
}

