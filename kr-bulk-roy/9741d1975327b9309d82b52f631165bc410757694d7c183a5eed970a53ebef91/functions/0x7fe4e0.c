
void FUN_007fe4e0(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  *(undefined4 *)(iVar1 + 0x68) = *param_1;
  *(undefined4 *)(iVar1 + 0x6c) = param_1[1];
  *(undefined4 *)(iVar1 + 0x70) = param_1[2];
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  iVar1 = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(iVar1 + 0x68) = *param_1;
  *(undefined4 *)(iVar1 + 0x6c) = param_1[1];
  *(undefined4 *)(iVar1 + 0x70) = param_1[2];
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 1;
  *(undefined4 *)(in_ECX + 0x44) = 1;
  *(undefined4 *)(in_ECX + 0x8c) = 1;
  return;
}

