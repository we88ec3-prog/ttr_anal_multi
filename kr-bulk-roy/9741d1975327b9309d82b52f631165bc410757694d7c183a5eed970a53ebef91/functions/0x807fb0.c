
undefined4 FUN_00807fb0(undefined4 param_1)

{
  void *_Dst;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *unaff_EDI;
  undefined4 local_8;
  
  uVar2 = 0;
  uVar3 = unaff_EDI[1] - *unaff_EDI >> 2;
  local_8 = 0;
  if (uVar3 == 0) {
LAB_00807fed:
    local_8 = 1;
  }
  else if (uVar3 != 0) {
    do {
      iVar1 = FUN_008092c0(*(undefined4 *)(*unaff_EDI + uVar2 * 4),param_1);
      if (iVar1 != 0) goto LAB_00807fed;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  _Dst = (void *)*unaff_EDI;
  if (_Dst != (void *)unaff_EDI[1]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_EDI[1],0);
    unaff_EDI[1] = (int)_Dst;
  }
  return local_8;
}

