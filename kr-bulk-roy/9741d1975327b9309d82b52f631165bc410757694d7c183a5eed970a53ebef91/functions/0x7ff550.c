
void FUN_007ff550(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  iVar3 = *(int *)(in_ECX + 0x24);
  *(undefined4 *)(iVar3 + 0xc) = *param_1;
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  *(undefined4 *)(iVar3 + 0x14) = uVar2;
  return;
}

