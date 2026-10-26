
void FUN_0046e1b0(uint param_1,char param_2)

{
  int *_Dst;
  int *in_ECX;
  
  if (param_1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (param_1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if ((uint)in_ECX[5] < param_1) {
    FUN_00402dc0(param_1,in_ECX[4]);
    if (param_1 == 0) {
      return;
    }
  }
  else if (param_1 == 0) {
    in_ECX[4] = 0;
    if (0xf < (uint)in_ECX[5]) {
      *(undefined1 *)*in_ECX = 0;
      return;
    }
    *(undefined1 *)in_ECX = 0;
    return;
  }
  if (param_1 == 1) {
    if ((uint)in_ECX[5] < 0x10) {
      *(char *)in_ECX = param_2;
    }
    else {
      *(char *)*in_ECX = param_2;
    }
  }
  else {
    _Dst = in_ECX;
    if (0xf < (uint)in_ECX[5]) {
      _Dst = (int *)*in_ECX;
    }
    _memset(_Dst,(int)param_2,param_1);
  }
  in_ECX[4] = param_1;
  if ((uint)in_ECX[5] < 0x10) {
    *(undefined1 *)((int)in_ECX + param_1) = 0;
    return;
  }
  *(undefined1 *)(*in_ECX + param_1) = 0;
  return;
}

