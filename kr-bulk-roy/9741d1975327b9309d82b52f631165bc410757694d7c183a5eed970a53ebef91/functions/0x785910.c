
void FUN_00785910(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  if ((uint)((*(int *)(in_ECX + 0x1c) - iVar1) / 0x30) <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *param_1 = *(undefined4 *)(iVar1 + 4 + param_2 * 0x30);
  uVar2 = *(undefined4 *)(iVar1 + 0xc + param_2 * 0x30);
  param_1[1] = *(undefined4 *)(iVar1 + 8 + param_2 * 0x30);
  param_1[2] = uVar2;
  return;
}

