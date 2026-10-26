
void FUN_004041f0(undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *in_ECX;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar2 = param_1[4] - param_2;
  if (uVar2 < param_3) {
    param_3 = uVar2;
  }
  iVar1 = in_ECX[4];
  if (-iVar1 - 1U <= param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (param_3 != 0) {
    uVar2 = iVar1 + param_3;
    if (0x7ffffffe < uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("string too long");
    }
    if ((uint)in_ECX[5] < uVar2) {
      FUN_00402490(uVar2,iVar1);
      if (uVar2 == 0) {
        return;
      }
    }
    else if (uVar2 == 0) {
      in_ECX[4] = 0;
      if (7 < (uint)in_ECX[5]) {
        *(undefined2 *)*in_ECX = 0;
        return;
      }
      *(undefined2 *)in_ECX = 0;
      return;
    }
    if (7 < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    piVar3 = in_ECX;
    if (7 < (uint)in_ECX[5]) {
      piVar3 = (int *)*in_ECX;
    }
    FID_conflict__memcpy
              ((void *)((int)piVar3 + in_ECX[4] * 2),(void *)((int)param_1 + param_2 * 2),
               param_3 * 2);
    in_ECX[4] = uVar2;
    if (7 < (uint)in_ECX[5]) {
      *(undefined2 *)(*in_ECX + uVar2 * 2) = 0;
      return;
    }
    *(undefined2 *)((int)in_ECX + uVar2 * 2) = 0;
  }
  return;
}

