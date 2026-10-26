
void FUN_00785b00(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((uint)((*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18)) / 0x44) <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  iVar1 = *(int *)(in_ECX + 0x18) + param_2 * 0x44;
  *param_1 = *(undefined4 *)(iVar1 + 4);
  uVar2 = *(undefined4 *)(iVar1 + 0xc);
  param_1[1] = *(undefined4 *)(iVar1 + 8);
  param_1[2] = uVar2;
  return;
}

