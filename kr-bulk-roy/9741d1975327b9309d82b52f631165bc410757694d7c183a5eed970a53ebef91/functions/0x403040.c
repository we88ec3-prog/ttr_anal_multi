
void FUN_00403040(int *param_1,uint param_2,uint param_3)

{
  int *_Dst;
  int *in_ECX;
  uint _Size;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  _Size = param_1[4] - param_2;
  if (param_3 < _Size) {
    _Size = param_3;
  }
  if (in_ECX == param_1) {
    FUN_00402c80(_Size + param_2,0xffffffff);
    FUN_00402c80(0,param_2);
    return;
  }
  if (_Size == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if ((uint)in_ECX[5] < _Size) {
    FUN_00402dc0(_Size,in_ECX[4]);
    if (_Size == 0) {
      return;
    }
  }
  else if (_Size == 0) {
    in_ECX[4] = 0;
    if (0xf < (uint)in_ECX[5]) {
      *(undefined1 *)*in_ECX = 0;
      return;
    }
    *(undefined1 *)in_ECX = 0;
    return;
  }
  if (0xf < (uint)param_1[5]) {
    param_1 = (int *)*param_1;
  }
  _Dst = in_ECX;
  if (0xf < (uint)in_ECX[5]) {
    _Dst = (int *)*in_ECX;
  }
  FID_conflict__memcpy(_Dst,(void *)((int)param_1 + param_2),_Size);
  in_ECX[4] = _Size;
  if ((uint)in_ECX[5] < 0x10) {
    *(undefined1 *)((int)in_ECX + _Size) = 0;
    return;
  }
  *(undefined1 *)(*in_ECX + _Size) = 0;
  return;
}

