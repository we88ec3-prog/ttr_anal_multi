
void FUN_00837e90(void)

{
  int in_ECX;
  
  do {
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    if (*(int *)(in_ECX + 8) != 0) {
      FUN_00837e90();
    }
    in_ECX = *(int *)(in_ECX + 0xc);
  } while (in_ECX != 0);
  return;
}

