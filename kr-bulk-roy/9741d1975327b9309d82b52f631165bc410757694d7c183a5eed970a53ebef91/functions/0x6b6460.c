
undefined4 FUN_006b6460(int param_1)

{
  int in_ECX;
  
  if ((param_1 == 0xd) && ((*(uint *)(*(int *)(in_ECX + 0x10c) + 0x28) >> 7 & 1) != 0)) {
    FUN_006b5dd0(in_ECX);
    return 1;
  }
  return 0;
}

