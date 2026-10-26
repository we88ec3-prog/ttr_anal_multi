
void FUN_00466d70(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xa4);
  param_1[1] = *(undefined4 *)(in_ECX + 0xa8);
  uVar1 = *(undefined4 *)(in_ECX + 0xb0);
  param_1[2] = *(undefined4 *)(in_ECX + 0xac);
  param_1[3] = uVar1;
  return;
}

