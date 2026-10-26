
void FUN_004fb700(int param_1)

{
  undefined2 *in_ECX;
  
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  FUN_004026e0(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0xe) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x20);
  return;
}

