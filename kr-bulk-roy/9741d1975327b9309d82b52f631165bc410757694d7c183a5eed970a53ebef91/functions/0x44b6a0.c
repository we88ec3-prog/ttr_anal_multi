
void FUN_0044b6a0(uint param_1)

{
  int iVar1;
  int iVar2;
  void *_Dst;
  int *unaff_ESI;
  
  if (0x7fffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(unaff_ESI[2] - *unaff_ESI >> 1) < param_1) {
    _Dst = (void *)FUN_0044b7d0(param_1);
    FID_conflict__memcpy(_Dst,(void *)*unaff_ESI,(unaff_ESI[1] - *unaff_ESI >> 1) * 2);
    iVar1 = *unaff_ESI;
    iVar2 = unaff_ESI[1];
    if (iVar1 != 0) {
      FUN_0089120c(iVar1);
    }
    *unaff_ESI = (int)_Dst;
    unaff_ESI[2] = (int)((int)_Dst + param_1 * 2);
    unaff_ESI[1] = (int)((int)_Dst + (iVar2 - iVar1 >> 1) * 2);
  }
  return;
}

