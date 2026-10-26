
int FUN_007ffbc0(int param_1,int param_2)

{
  undefined2 *puVar1;
  int *in_ECX;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  if (in_ECX[0x1b] == 0) {
    return param_1;
  }
  if (*in_ECX != 0) {
    puVar1 = (undefined2 *)(param_2 + param_1 * 6);
    uVar2 = in_ECX[3] & 0x80000001;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
    }
    *puVar1 = (short)in_ECX[3];
    puVar1[1] = (short)in_ECX[4];
    if (uVar2 != 1) {
      puVar1[2] = (short)in_ECX[6];
      puVar1[3] = (short)in_ECX[6];
      puVar1[4] = (short)in_ECX[5];
      puVar1[5] = (short)in_ECX[3];
      return param_1 + 2;
    }
    puVar1[2] = (short)in_ECX[5];
    puVar1[3] = (short)in_ECX[5];
    puVar1[4] = (short)in_ECX[4];
    puVar1[5] = (short)in_ECX[6];
    return param_1 + 2;
  }
  if (in_ECX[0x1b] == 1) {
    FID_conflict__memcpy((void *)(param_2 + param_1 * 6),(void *)in_ECX[0x1c],in_ECX[0x1d] * 6);
    return in_ECX[0x1d] + param_1;
  }
  piVar3 = in_ECX + 7;
  iVar4 = 4;
  do {
    if (*piVar3 != 0) {
      param_1 = FUN_007ffbc0(param_1,param_2);
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return param_1;
}

