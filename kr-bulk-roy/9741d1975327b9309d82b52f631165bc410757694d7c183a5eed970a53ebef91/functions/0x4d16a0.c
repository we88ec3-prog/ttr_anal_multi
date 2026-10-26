
void FUN_004d16a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x424) != 0) {
    if (*(int *)(*(int *)(in_ECX + 0x424) + 0x24) != 0) {
      FUN_007be5f0();
    }
    if (*(int *)(in_ECX + 0x424) != 0) {
      FUN_004c7db0();
      *(undefined4 *)(in_ECX + 0x424) = 0;
    }
  }
  FUN_004c8360();
  return;
}

