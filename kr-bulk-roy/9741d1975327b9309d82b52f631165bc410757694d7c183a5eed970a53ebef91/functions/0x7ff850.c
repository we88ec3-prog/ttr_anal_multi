
void FUN_007ff850(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = *param_1;
  *(undefined4 *)(in_ECX + 0x24) = param_1[1];
  *(undefined4 *)(in_ECX + 0x28) = param_1[2];
  iVar1 = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(iVar1 + 0x18) = *param_1;
  *(undefined4 *)(iVar1 + 0x70) = 1;
  return;
}

