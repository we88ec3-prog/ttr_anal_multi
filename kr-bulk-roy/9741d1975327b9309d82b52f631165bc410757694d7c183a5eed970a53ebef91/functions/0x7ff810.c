
void FUN_007ff810(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = *param_1;
  *(undefined4 *)(in_ECX + 0x18) = param_1[1];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[2];
  iVar1 = *(int *)(in_ECX + 0x2c);
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  *(undefined4 *)(iVar1 + 0x34) = *param_1;
  *(undefined4 *)(iVar1 + 0x38) = uVar2;
  *(undefined4 *)(iVar1 + 0x3c) = uVar3;
  *(undefined4 *)(iVar1 + 0x70) = 1;
  return;
}

