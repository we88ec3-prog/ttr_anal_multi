
int FUN_008109d0(int param_1,int param_2,int *param_3)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int iVar3;
  int local_10 [2];
  int local_8;
  
  iVar3 = 0;
  *param_3 = 0;
  iVar2 = 0;
  local_8 = 0;
  if ((*(int *)(in_ECX + 0x1c) != 0) && (*(int *)(in_ECX + 0x18) != 0)) {
    local_10[0] = *(int *)(*(int *)(in_ECX + 8) + 4);
    if (*(int *)(in_ECX + 0x18) < param_1 / (local_10[0] * 2) + *(int *)(in_ECX + 0x10)) {
      iVar1 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x10);
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      param_1 = local_10[0] * iVar1 * 2;
      local_8 = 1;
    }
  }
  if (0 < param_1) {
    do {
      iVar3 = ov_read(*(undefined4 *)(in_ECX + 4),iVar2 + param_2,param_1 - iVar2,0,2,1,local_10);
      if (iVar3 < 1) {
        if (iVar3 < 0) {
          return iVar3;
        }
        if (iVar3 != -3) break;
      }
      else {
        iVar2 = iVar2 + iVar3;
        *(int *)(in_ECX + 0x10) =
             *(int *)(in_ECX + 0x10) + iVar3 / (*(int *)(*(int *)(in_ECX + 8) + 4) * 2);
      }
    } while (iVar2 < param_1);
    if (iVar2 != 0) {
      if (local_8 != 0) {
        ov_pcm_seek(*(undefined4 *)(in_ECX + 4),*(int *)(in_ECX + 0x14),
                    *(int *)(in_ECX + 0x14) >> 0x1f);
        *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x14);
      }
      *param_3 = iVar2;
    }
  }
  return iVar3;
}

