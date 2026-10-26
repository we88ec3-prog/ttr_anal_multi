
void FUN_00754a70(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  FUN_00744640(param_1,param_2);
  if (*(int *)(in_ECX + 0x150) != 0) {
    iVar1 = *(int *)(in_ECX + 0x24);
    if (((iVar1 != 0) && (*(char *)(iVar1 + 0x165b8) != '\0')) && (*(char *)(in_ECX + 200) != '\0'))
    {
      FUN_00754ef0(*(undefined4 *)(iVar1 + 0x165bc));
    }
    if (*(int *)(in_ECX + 0xf8) != 0) {
      FUN_007586b0(in_ECX + 0xe8,0,*(int *)(in_ECX + 0xf8),*(undefined4 *)(in_ECX + 0x120),
                   *(undefined4 *)(in_ECX + 0x154),*(undefined4 *)(in_ECX + 0x124),
                   *(int *)(in_ECX + 0xa4) + param_1,*(int *)(in_ECX + 0xa8) + param_2,
                   *(int *)(in_ECX + 0xac) + param_1,*(int *)(in_ECX + 0xb0) + param_2);
    }
  }
  return;
}

