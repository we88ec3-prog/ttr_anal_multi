
void FUN_0075b5f0(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  FUN_00744640(param_1,param_2);
  if ((*(int *)(in_ECX + 0x44) != 0) && (*(int *)(in_ECX + 0xf8) != 0)) {
    iVar1 = *(int *)(in_ECX + 0x44);
    if (*(int *)(iVar1 + 0xb0) != 0) {
      FUN_007586b0(iVar1 + 0xa0,0,*(undefined4 *)(iVar1 + 0xb0),*(undefined4 *)(in_ECX + 0xcc),
                   *(undefined4 *)(in_ECX + 0xfc),*(undefined4 *)(in_ECX + 200),
                   *(int *)(in_ECX + 0xa4) + param_1,*(int *)(in_ECX + 0xa8) + param_2,
                   *(int *)(in_ECX + 0xac) + param_1,*(int *)(in_ECX + 0xb0) + param_2);
    }
  }
  return;
}

