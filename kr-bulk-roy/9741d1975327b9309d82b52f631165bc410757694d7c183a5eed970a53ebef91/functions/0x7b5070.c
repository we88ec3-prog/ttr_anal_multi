
void FUN_007b5070(uint param_1)

{
  void *_Dst;
  int iVar1;
  
  if (0x3fffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((int)DAT_00fbab5c - (int)DAT_00fbab54 >> 2) < param_1) {
    _Dst = (void *)FUN_007d01e0();
    FID_conflict__memcpy(_Dst,DAT_00fbab54,((int)DAT_00fbab58 - (int)DAT_00fbab54 >> 2) * 4);
    iVar1 = (int)DAT_00fbab58 - (int)DAT_00fbab54;
    if (DAT_00fbab54 != (void *)0x0) {
      FUN_0089120c(DAT_00fbab54);
    }
    DAT_00fbab58 = (void *)((int)_Dst + (iVar1 >> 2) * 4);
    DAT_00fbab5c = (void *)((int)_Dst + param_1 * 4);
    DAT_00fbab54 = _Dst;
  }
  return;
}

