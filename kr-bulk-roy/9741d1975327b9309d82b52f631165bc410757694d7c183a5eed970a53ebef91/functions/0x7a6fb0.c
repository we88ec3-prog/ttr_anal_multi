
void FUN_007a6fb0(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xe8) = *param_1;
  *(undefined4 *)(in_ECX + 0xec) = param_1[1];
  *(undefined4 *)(in_ECX + 0xf0) = param_1[2];
  iVar1 = *(int *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0xfc) = 1;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x28) = *param_1;
    *(undefined4 *)(iVar1 + 0x2c) = param_1[1];
    *(undefined4 *)(iVar1 + 0x30) = param_1[2];
    iVar1 = *(int *)(iVar1 + 0x10);
    *(undefined4 *)(iVar1 + 0x68) = *param_1;
    *(undefined4 *)(iVar1 + 0x6c) = param_1[1];
    *(undefined4 *)(iVar1 + 0x70) = param_1[2];
    *(undefined4 *)(iVar1 + 0xc0) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0x104);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x28) = *param_1;
    *(undefined4 *)(iVar1 + 0x2c) = param_1[1];
    *(undefined4 *)(iVar1 + 0x30) = param_1[2];
    *(undefined4 *)(iVar1 + 0x70) = 1;
  }
  if (*(int **)(in_ECX + 0x11c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x11c) + 0x14))(param_1);
  }
  return;
}

