
void FUN_00745b80(void)

{
  int in_EAX;
  
  if ((((*(int *)(in_EAX + 0x24) != 0) &&
       (*(int *)(in_EAX + 0x34) != *(int *)(in_EAX + 0x2c) &&
        -1 < *(int *)(in_EAX + 0x34) - *(int *)(in_EAX + 0x2c))) &&
      (*(int *)(in_EAX + 0x38) != *(int *)(in_EAX + 0x30) &&
       -1 < *(int *)(in_EAX + 0x38) - *(int *)(in_EAX + 0x30))) &&
     ((*(uint *)(in_EAX + 0x28) & 0x100000) == 0)) {
    FUN_00753020(*(undefined4 *)(in_EAX + 0x2c),*(undefined4 *)(in_EAX + 0x30),
                 *(undefined4 *)(in_EAX + 0x34),*(undefined4 *)(in_EAX + 0x38));
  }
  return;
}

