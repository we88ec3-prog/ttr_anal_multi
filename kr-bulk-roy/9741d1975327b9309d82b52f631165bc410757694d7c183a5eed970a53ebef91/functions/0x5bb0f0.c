
void FUN_005bb0f0(void)

{
  int in_ECX;
  
  FUN_00595f80();
  FUN_0059aa60();
  if ((*(uint *)(*(int *)(in_ECX + 0x2b0) + 0x28) >> 8 & 1) != 0) {
    FUN_00476020();
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x2c0) + 0x28) >> 8 & 1) != 0) {
    FUN_00439f30();
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x2d4) + 0x28) >> 8 & 1) != 0) {
    FUN_00442680();
  }
  return;
}

