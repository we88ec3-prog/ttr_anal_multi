
void * FUN_0071f6d0(int *param_1)

{
  void *_Dst;
  size_t _Size;
  
  if (*param_1 == 0) {
    return (void *)0x0;
  }
  _Size = param_1[1] - *param_1;
  _Dst = (void *)FUN_0071bdb0();
  if (_Dst == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0071f670();
  }
  FID_conflict__memcpy(_Dst,(void *)*param_1,_Size);
  *(undefined1 *)((int)_Dst + _Size) = 0;
  return _Dst;
}

