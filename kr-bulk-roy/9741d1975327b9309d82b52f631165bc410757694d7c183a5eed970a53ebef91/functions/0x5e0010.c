
void FUN_005e0010(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_ECX;
  
  FUN_005d7240(param_1,param_2,param_3,param_4);
  if ((*(uint *)(in_ECX + 0x28) & 8) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 8;
  }
  return;
}

