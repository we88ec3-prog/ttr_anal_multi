
undefined4 FUN_00768150(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xf4) != 0) {
    uVar1 = FUN_008fed10(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x10));
    return uVar1;
  }
  return 0;
}

