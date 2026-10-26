
void FUN_006db280(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  uVar1 = FUN_006db770();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x30) = 1;
  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x31) = 1;
  return;
}

