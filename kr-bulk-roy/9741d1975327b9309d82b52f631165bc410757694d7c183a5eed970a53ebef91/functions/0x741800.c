
void FUN_00741800(int *param_1,uint param_2)

{
  size_t _Size;
  char cVar1;
  uint in_EAX;
  int *_Dst;
  uint uVar2;
  int *unaff_EDI;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar2 = param_1[4] - param_2;
  if (in_EAX < uVar2) {
    uVar2 = in_EAX;
  }
  if (unaff_EDI != param_1) {
    cVar1 = FUN_00741a40();
    if (cVar1 != '\0') {
      if (7 < (uint)param_1[5]) {
        param_1 = (int *)*param_1;
      }
      _Dst = unaff_EDI;
      if (7 < (uint)unaff_EDI[5]) {
        _Dst = (int *)*unaff_EDI;
      }
      _Size = uVar2 * 2;
      FID_conflict__memcpy(_Dst,(void *)((int)param_1 + param_2 * 2),_Size);
      unaff_EDI[4] = uVar2;
      if (7 < (uint)unaff_EDI[5]) {
        *(undefined2 *)(_Size + *unaff_EDI) = 0;
        return;
      }
      *(undefined2 *)(_Size + (int)unaff_EDI) = 0;
    }
    return;
  }
  FUN_007419c0();
  FUN_007419c0();
  return;
}

