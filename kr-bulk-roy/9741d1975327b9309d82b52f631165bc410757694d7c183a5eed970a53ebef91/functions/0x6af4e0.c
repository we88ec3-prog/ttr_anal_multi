
undefined4 FUN_006af4e0(int param_1)

{
  int in_ECX;
  
  if ((param_1 == 0xd) && ((*(uint *)(*(int *)(in_ECX + 0x11c) + 0x28) >> 7 & 1) != 0)) {
    FUN_006af280(in_ECX);
    return 1;
  }
  return 0;
}

