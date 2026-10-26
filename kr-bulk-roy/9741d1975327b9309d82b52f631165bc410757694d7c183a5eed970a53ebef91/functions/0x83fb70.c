
int FUN_0083fb70(int *param_1,undefined2 *param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_1[8] == param_1[9]) {
    DAT_00fe34dc = DAT_00fe34dc + 1;
    iVar2 = param_1[5] - param_1[4] >> 2;
    if (0xffff < DAT_00fe34dc) {
      DAT_00fe34dc = 1;
    }
    param_2[1] = (short)DAT_00fe34dc;
    *param_2 = (short)iVar2;
    FUN_0085df00();
    FUN_006de9c0();
    return *param_1 + iVar2 * 0xc;
  }
  iVar2 = *(int *)(param_1[9] + -4);
  DAT_00fe34dc = DAT_00fe34dc + 1;
  if (0xffff < DAT_00fe34dc) {
    DAT_00fe34dc = 1;
  }
  uVar1 = DAT_00fe34dc;
  *param_2 = (short)iVar2;
  param_2[1] = (short)uVar1;
  if (param_1[8] != param_1[9]) {
    param_1[9] = param_1[9] + -4;
  }
  *(uint *)(param_1[4] + iVar2 * 4) = (uint)(ushort)param_2[1];
  return *param_1 + iVar2 * 0xc;
}

