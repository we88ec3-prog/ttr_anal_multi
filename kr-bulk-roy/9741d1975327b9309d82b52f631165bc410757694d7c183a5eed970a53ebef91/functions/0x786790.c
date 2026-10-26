
void FUN_00786790(int param_1)

{
  int in_ECX;
  
  if (param_1 != in_ECX) {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  }
  return;
}

