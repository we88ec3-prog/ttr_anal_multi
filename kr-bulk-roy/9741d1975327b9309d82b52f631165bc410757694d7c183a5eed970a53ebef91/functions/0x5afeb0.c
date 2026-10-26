
void FUN_005afeb0(void)

{
  int in_ECX;
  
  FUN_0059b1f0();
  if ((*(uint *)(*(int *)(in_ECX + 0x21c) + 0x28) >> 8 & 1) != 0) {
    FUN_0064e430(*(int *)(in_ECX + 0x21c));
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x220) + 0x28) >> 8 & 1) != 0) {
    FUN_0065d360();
  }
  if (*(int *)(in_ECX + 0x224) != 0) {
    FUN_00659bc0(*(int *)(in_ECX + 0x224));
  }
  if (*(int *)(in_ECX + 0x228) != 0) {
    FUN_006528c0(*(int *)(in_ECX + 0x228));
    FUN_00652ac0();
  }
  return;
}

