
void FUN_004f0b60(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  uVar2 = in_ECX[4];
  if (uVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  if (-uVar2 - 1 <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (param_2 != 0) {
    uVar1 = uVar2 + param_2;
    if (0x7ffffffe < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("string too long");
    }
    if ((uint)in_ECX[5] < uVar1) {
      FUN_00402490(uVar1,uVar2);
      if (uVar1 == 0) {
        return;
      }
    }
    else if (uVar1 == 0) {
      in_ECX[4] = 0;
      if ((uint)in_ECX[5] < 8) {
        *(undefined2 *)in_ECX = 0;
        return;
      }
      *(undefined2 *)*in_ECX = 0;
      return;
    }
    piVar4 = in_ECX;
    piVar3 = in_ECX;
    if (7 < (uint)in_ECX[5]) {
      piVar4 = (int *)*in_ECX;
      piVar3 = (int *)*in_ECX;
    }
    FID_conflict__memcpy
              ((void *)((int)piVar4 + (param_1 + param_2) * 2),(void *)((int)piVar3 + param_1 * 2),
               (in_ECX[4] - param_1) * 2);
    FUN_004022e0(param_1,param_2,param_3);
    in_ECX[4] = uVar1;
    if (7 < (uint)in_ECX[5]) {
      *(undefined2 *)(*in_ECX + uVar1 * 2) = 0;
      return;
    }
    *(undefined2 *)((int)in_ECX + uVar1 * 2) = 0;
  }
  return;
}

