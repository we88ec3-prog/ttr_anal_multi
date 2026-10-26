
void FUN_00580fe0(float param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0xc) + 4);
  iVar2 = *(int *)(in_ECX + 4);
  *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar2 + 0x1c);
  *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar2 + 0x20);
  *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(iVar2 + 0x24);
  iVar1 = *(int *)(iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(iVar2 + 0x1c);
  *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(iVar2 + 0x20);
  *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)(iVar2 + 0x24);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  FUN_007cd8d0(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
  FUN_007cd830(param_1);
  *(float *)(in_ECX + 8) = *(float *)(in_ECX + 8) + param_1;
  return;
}

