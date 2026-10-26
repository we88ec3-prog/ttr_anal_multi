
int FUN_008d0160(int *param_1,int param_2,void *param_3,size_t param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (((param_2 < 0) || (param_1[4] <= param_2)) || ((int)param_4 < 0)) {
    return 6;
  }
  uVar1 = param_1[2];
  if (uVar1 < param_1[1] + param_4) {
    uVar3 = (int)param_3 - *param_1;
    if (((int)uVar3 < 0) || (uVar1 <= uVar3)) {
      uVar3 = 0xffffffff;
    }
    if (uVar1 < param_1[1] + param_4) {
      do {
        uVar1 = (uVar1 >> 2) + 0x400 + uVar1 & 0xfffffc00;
      } while (uVar1 < param_4 + param_1[1]);
    }
    iVar2 = FUN_008d0100(uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (-1 < (int)uVar3) {
      param_3 = (void *)(*param_1 + uVar3);
    }
  }
  *(int *)(param_1[6] + param_2 * 4) = param_1[1] + *param_1;
  *(size_t *)(param_1[7] + param_2 * 4) = param_4;
  FID_conflict__memcpy((void *)(param_1[1] + *param_1),param_3,param_4);
  param_1[1] = param_1[1] + param_4;
  return 0;
}

