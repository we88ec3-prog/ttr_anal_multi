
undefined4 FUN_008de030(void)

{
  undefined4 uVar1;
  int in_ECX;
  uint in_EDX;
  
  if (in_EDX != 0xffff) {
    if (0x186 < in_EDX) {
      uVar1 = FUN_008de010();
      return uVar1;
    }
    if (*(int *)(in_ECX + 0xb8c) != 0) {
      uVar1 = (**(code **)(*(int *)(in_ECX + 0xb8c) + 0x14))();
      return uVar1;
    }
  }
  return 0;
}

