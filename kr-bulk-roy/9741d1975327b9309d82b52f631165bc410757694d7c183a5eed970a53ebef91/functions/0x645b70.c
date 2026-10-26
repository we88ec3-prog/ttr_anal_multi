
void FUN_00645b70(int *param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  param_1[1] = 0;
  iVar2 = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8);
  iVar3 = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc);
  iVar1 = *(int *)(in_ECX + 0xf4);
  param_1[2] = iVar2;
  iVar2 = iVar2 - iVar1;
  param_1[3] = iVar3;
  *param_1 = iVar1;
  if (iVar2 < iVar1) {
    iVar2 = iVar1;
  }
  iVar3 = iVar3 - iVar1;
  param_1[2] = iVar2;
  param_1[1] = iVar1;
  if (iVar3 < iVar1) {
    param_1[3] = iVar1;
    return;
  }
  param_1[3] = iVar3;
  return;
}

