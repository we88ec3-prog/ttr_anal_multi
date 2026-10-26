
void FUN_007a7050(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xe8);
  uVar1 = *(undefined4 *)(in_ECX + 0xf0);
  param_1[1] = *(undefined4 *)(in_ECX + 0xec);
  param_1[2] = uVar1;
  return;
}

