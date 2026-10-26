
/* WARNING: Removing unreachable block (ram,0x00407d5b) */

void FUN_00407d50(uint param_1)

{
  int iVar1;
  int iVar2;
  void *_Dst;
  int *unaff_ESI;
  
  if ((uint)(unaff_ESI[2] - *unaff_ESI) < param_1) {
    _Dst = (void *)FUN_00407dc0();
    FID_conflict__memcpy(_Dst,(void *)*unaff_ESI,unaff_ESI[1] - *unaff_ESI);
    iVar1 = *unaff_ESI;
    iVar2 = unaff_ESI[1];
    if (iVar1 != 0) {
      FUN_0089120c(iVar1);
    }
    *unaff_ESI = (int)_Dst;
    unaff_ESI[1] = (iVar2 - iVar1) + (int)_Dst;
    unaff_ESI[2] = (int)_Dst + param_1;
  }
  return;
}

