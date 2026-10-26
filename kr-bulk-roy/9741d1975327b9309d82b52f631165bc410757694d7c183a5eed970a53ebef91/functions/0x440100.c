
void FUN_00440100(uint param_1)

{
  int in_ECX;
  
  if (param_1 <= *(uint *)(in_ECX + 0x10)) {
    FUN_00402400(param_1,0xffffffff);
    return;
  }
  FUN_00440010(param_1 - *(uint *)(in_ECX + 0x10),0);
  return;
}

