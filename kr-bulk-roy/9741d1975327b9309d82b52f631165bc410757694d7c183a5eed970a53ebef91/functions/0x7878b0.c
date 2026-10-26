
void FUN_007878b0(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1c);
  *param_1 = *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x14);
  param_1[1] = *(undefined4 *)(iVar1 + -0x28);
  return;
}

