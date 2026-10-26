
void FUN_0077f7c0(int param_1)

{
  int *piVar1;
  int *_Dst;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0xcc);
  _Dst = *(int **)(in_ECX + 200);
  if (_Dst != piVar1) {
    do {
      if (*_Dst == param_1) break;
      _Dst = _Dst + 1;
    } while (_Dst != piVar1);
    if (_Dst != piVar1) {
      FID_conflict__memcpy(_Dst,_Dst + 1,(*(int *)(in_ECX + 0xcc) - (int)(_Dst + 1) >> 2) * 4);
      *(int *)(in_ECX + 0xcc) = *(int *)(in_ECX + 0xcc) + -4;
    }
  }
  return;
}

