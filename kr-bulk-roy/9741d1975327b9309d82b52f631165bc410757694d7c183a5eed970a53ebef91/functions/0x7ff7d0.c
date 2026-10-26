
void FUN_007ff7d0(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_1[1];
  *(undefined4 *)(in_ECX + 0x10) = param_1[2];
  iVar1 = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(iVar1 + 0x28) = *param_1;
  *(undefined4 *)(iVar1 + 0x2c) = param_1[1];
  *(undefined4 *)(iVar1 + 0x30) = param_1[2];
  *(undefined4 *)(iVar1 + 0x70) = 1;
  return;
}

