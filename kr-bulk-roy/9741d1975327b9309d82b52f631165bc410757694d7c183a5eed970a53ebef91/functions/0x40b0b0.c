
void FUN_0040b0b0(int *param_1,uint param_2)

{
  char cVar1;
  uint _Size;
  int *_Dst;
  uint in_ECX;
  int *unaff_EDI;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  _Size = param_1[4] - param_2;
  if (in_ECX < _Size) {
    _Size = in_ECX;
  }
  if (unaff_EDI != param_1) {
    cVar1 = FUN_0040b2c0();
    if (cVar1 != '\0') {
      if (0xf < (uint)param_1[5]) {
        param_1 = (int *)*param_1;
      }
      _Dst = unaff_EDI;
      if (0xf < (uint)unaff_EDI[5]) {
        _Dst = (int *)*unaff_EDI;
      }
      FID_conflict__memcpy(_Dst,(void *)((int)param_1 + param_2),_Size);
      unaff_EDI[4] = _Size;
      if (0xf < (uint)unaff_EDI[5]) {
        *(undefined1 *)(*unaff_EDI + _Size) = 0;
        return;
      }
      *(undefined1 *)((int)unaff_EDI + _Size) = 0;
    }
    return;
  }
  FUN_0040b040();
  FUN_0040b040();
  return;
}

