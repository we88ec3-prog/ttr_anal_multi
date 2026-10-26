
void FUN_00786a70(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1c);
  *param_1 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + 8);
  param_1[1] = *(undefined4 *)(iVar1 + -0x10);
  return;
}

