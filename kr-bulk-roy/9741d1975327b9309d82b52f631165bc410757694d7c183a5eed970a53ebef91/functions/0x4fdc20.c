
void FUN_004fdc20(void)

{
  int in_ECX;
  
  if (7 < *(uint *)(in_ECX + 0x34)) {
    FUN_0089120c(*(undefined4 *)(in_ECX + 0x20));
  }
  *(undefined4 *)(in_ECX + 0x34) = 7;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined2 *)(in_ECX + 0x20) = 0;
  return;
}

