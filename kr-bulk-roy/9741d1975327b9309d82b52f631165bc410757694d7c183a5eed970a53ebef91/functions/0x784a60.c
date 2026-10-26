
void FUN_00784a60(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  if ((uint)((*(int *)(in_ECX + 0x1c) - iVar1) / 0x60) <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  iVar3 = param_2 * 0x60 + iVar1;
  *param_1 = *(undefined4 *)(param_2 * 0x60 + 4 + iVar1);
  param_1[1] = *(undefined4 *)(iVar3 + 8);
  uVar2 = *(undefined4 *)(iVar3 + 0x10);
  param_1[2] = *(undefined4 *)(iVar3 + 0xc);
  param_1[3] = uVar2;
  return;
}

