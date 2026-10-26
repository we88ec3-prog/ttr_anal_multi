
undefined2 FUN_008de250(void)

{
  undefined2 uVar1;
  uint in_ECX;
  int in_EDX;
  
  uVar1 = 0;
  if (in_ECX <= *(uint *)(in_EDX + 0x10)) {
    uVar1 = *(undefined2 *)(*(int *)(in_EDX + 0xc) + in_ECX * 2);
  }
  return uVar1;
}

