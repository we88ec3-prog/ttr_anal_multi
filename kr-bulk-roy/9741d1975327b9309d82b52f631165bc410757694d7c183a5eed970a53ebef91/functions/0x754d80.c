
undefined4 * FUN_00754d80(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x150) != 0) {
    FUN_00758d70(in_ECX + 0xe8,in_ECX + 0xa4,*(undefined4 *)(in_ECX + 0x120));
    return param_1;
  }
  iVar1 = *(int *)(in_ECX + 0xac);
  iVar2 = *(int *)(in_ECX + 0xa4);
  *param_1 = 0;
  param_1[2] = iVar1 - iVar2;
  param_1[1] = 0;
  param_1[3] = 0;
  return param_1;
}

