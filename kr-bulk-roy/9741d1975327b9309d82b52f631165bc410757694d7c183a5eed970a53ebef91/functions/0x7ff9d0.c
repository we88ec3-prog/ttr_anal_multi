
void FUN_007ff9d0(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 8);
  param_1[1] = *(undefined4 *)(in_ECX + 0xc);
  param_1[2] = *(undefined4 *)(in_ECX + 0x10);
  *param_2 = 0x41200000;
  return;
}

