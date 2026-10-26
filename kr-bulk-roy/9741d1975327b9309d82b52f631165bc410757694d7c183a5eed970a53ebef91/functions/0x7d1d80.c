
void FUN_007d1d80(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x20);
  uVar1 = *(undefined4 *)(in_ECX + 0x28);
  param_1[1] = *(undefined4 *)(in_ECX + 0x24);
  param_1[2] = uVar1;
  return;
}

