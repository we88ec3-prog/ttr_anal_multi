
void FUN_00650500(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x28);
  param_1[1] = *(undefined4 *)(in_ECX + 0x2c);
  uVar1 = *(undefined4 *)(in_ECX + 0x34);
  param_1[2] = *(undefined4 *)(in_ECX + 0x30);
  param_1[3] = uVar1;
  return;
}

