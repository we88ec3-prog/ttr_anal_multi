
void FUN_00786810(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  *param_1 = *(undefined4 *)(*(int *)(in_ECX + 0x14) + 8);
  param_1[1] = *(undefined4 *)(iVar1 + -8);
  return;
}

