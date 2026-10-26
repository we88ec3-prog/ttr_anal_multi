
void FUN_004ca700(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xa0);
  uVar1 = *(undefined4 *)(in_ECX + 0xa8);
  param_1[1] = *(undefined4 *)(in_ECX + 0xa4);
  param_1[2] = uVar1;
  return;
}

