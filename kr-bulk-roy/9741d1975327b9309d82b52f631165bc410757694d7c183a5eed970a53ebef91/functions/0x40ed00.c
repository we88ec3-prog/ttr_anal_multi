
void FUN_0040ed00(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x10);
  iVar2 = *(int *)(in_ECX + 8);
  *param_1 = 0;
  param_1[2] = iVar1 - iVar2;
  iVar1 = *(int *)(in_ECX + 0x14);
  iVar2 = *(int *)(in_ECX + 0xc);
  param_1[1] = 0;
  param_1[3] = iVar1 - iVar2;
  return;
}

