
int FUN_00832da0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint local_c;
  int local_8;
  
  uVar3 = param_1[2] - param_1[1] >> 3;
  local_8 = 0;
  local_c = 0;
  if (uVar3 != 0) {
    do {
      if (local_8 != 0) break;
      if (*(int *)(param_1[1] + local_c * 8) != 0) {
        iVar1 = *(int *)(param_1[1] + local_c * 8 + 4);
        if ((((*(int *)(iVar1 + 8) < *param_2) && (*(int *)(iVar1 + 8) < param_2[1])) &&
            (*param_2 < *(int *)(iVar1 + 0xc))) && (param_2[1] < *(int *)(iVar1 + 0x10))) {
          local_8 = FUN_00837b80();
        }
      }
      local_c = local_c + 1;
    } while (local_c < uVar3);
  }
  param_1 = (int *)*param_1;
  iVar1 = *param_2 / *param_1;
  iVar2 = param_2[1] / param_1[1];
  piVar4 = (int *)((param_1[2] * iVar2 + iVar1) * 0x10 + param_1[6]);
  if (*piVar4 != 0) {
    return piVar4[1];
  }
  uVar3 = piVar4[3] * (param_2[1] - param_1[1] * iVar2) + (*param_2 - *param_1 * iVar1);
  if (piVar4[1] <= (int)uVar3) {
    return 0;
  }
  iVar1 = FUN_008fed10();
  uVar3 = uVar3 & 0x80000007;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
  }
  return (int)(char)(*(byte *)(piVar4[2] - iVar1) & '\x01' << ((byte)uVar3 & 0x1f));
}

