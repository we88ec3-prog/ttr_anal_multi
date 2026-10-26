
void FUN_004296e0(uint param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (param_1 <= *(uint *)(in_ECX + 0x10)) {
    FUN_00402c80(param_1,0xffffffff);
    return;
  }
  FUN_00429630(param_1 - *(uint *)(in_ECX + 0x10),param_2);
  return;
}

