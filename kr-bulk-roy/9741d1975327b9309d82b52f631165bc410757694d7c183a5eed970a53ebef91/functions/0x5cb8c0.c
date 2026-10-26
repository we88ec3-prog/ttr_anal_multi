
void FUN_005cb8c0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  if (7 < *(uint *)(in_ECX + 0x1c)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  *(undefined2 *)puVar1 = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  return;
}

