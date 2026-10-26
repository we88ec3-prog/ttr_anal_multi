
void FUN_00844c20(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  uVar1 = FUN_00820120();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x18) = 1;
  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x19) = 1;
  return;
}

