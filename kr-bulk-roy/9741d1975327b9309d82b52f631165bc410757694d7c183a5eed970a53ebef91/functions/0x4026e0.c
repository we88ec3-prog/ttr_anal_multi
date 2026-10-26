
void FUN_004026e0(int *param_1,uint param_2,uint param_3)

{
  size_t _Size;
  int *_Dst;
  int *in_ECX;
  uint uVar1;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar1 = param_1[4] - param_2;
  if (param_3 < uVar1) {
    uVar1 = param_3;
  }
  if (in_ECX == param_1) {
    FUN_00402400(uVar1 + param_2,0xffffffff);
    FUN_00402400(0,param_2);
    return;
  }
  if (0x7ffffffe < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if ((uint)in_ECX[5] < uVar1) {
    FUN_00402490(uVar1,in_ECX[4]);
    if (uVar1 == 0) {
      return;
    }
  }
  else if (uVar1 == 0) {
    in_ECX[4] = 0;
    if (7 < (uint)in_ECX[5]) {
      *(undefined2 *)*in_ECX = 0;
      return;
    }
    *(undefined2 *)in_ECX = 0;
    return;
  }
  if (7 < (uint)param_1[5]) {
    param_1 = (int *)*param_1;
  }
  _Dst = in_ECX;
  if (7 < (uint)in_ECX[5]) {
    _Dst = (int *)*in_ECX;
  }
  _Size = uVar1 * 2;
  FID_conflict__memcpy(_Dst,(void *)((int)param_1 + param_2 * 2),_Size);
  in_ECX[4] = uVar1;
  if ((uint)in_ECX[5] < 8) {
    *(undefined2 *)(_Size + (int)in_ECX) = 0;
    return;
  }
  *(undefined2 *)(_Size + *in_ECX) = 0;
  return;
}

