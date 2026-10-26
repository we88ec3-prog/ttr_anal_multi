
void FUN_007459c0(void)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x100;
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

