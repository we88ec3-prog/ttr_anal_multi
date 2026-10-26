
void FUN_007fe660(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_008fed10();
  (**(code **)(**(int **)(in_ECX + 0x28) + 0x1c))(uVar1);
  (**(code **)(**(int **)(in_ECX + 0x2c) + 0x1c))(uVar1);
  *(undefined4 *)(in_ECX + 0x78) = 1;
  return;
}

