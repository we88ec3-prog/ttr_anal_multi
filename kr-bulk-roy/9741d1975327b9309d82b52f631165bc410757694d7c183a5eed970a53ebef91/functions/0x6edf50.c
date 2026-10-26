
void FUN_006edf50(uint param_1)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  undefined1 *puVar3;
  int *unaff_ESI;
  
  if ((uint)unaff_ESI[2] < param_1) {
    if ((param_1 == 0) || ((int)param_1 < 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = param_1 - 1 | param_1 - 1 >> 1;
      uVar1 = uVar1 | uVar1 >> 2;
      uVar1 = uVar1 | uVar1 >> 4;
      uVar1 = uVar1 | uVar1 >> 8;
      uVar1 = (uVar1 >> 0x10 | uVar1) + 1;
    }
    if (*unaff_ESI == 0) {
      iVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)param_1 * 2 >> 0x20) != 0) |
                           (uint)((ulonglong)param_1 * 2));
      unaff_ESI[1] = param_1;
      *unaff_ESI = iVar2;
      unaff_ESI[2] = 0;
      return;
    }
    _Dst = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)uVar1 * 2 >> 0x20) != 0) |
                                (uint)((ulonglong)uVar1 * 2));
    _memcpy_s(_Dst,uVar1 * 2,(void *)*unaff_ESI,unaff_ESI[1] * 2);
    puVar3 = (undefined1 *)*unaff_ESI;
    for (iVar2 = unaff_ESI[1] * 2; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    FUN_00891d3d(*unaff_ESI);
    unaff_ESI[1] = uVar1;
    *unaff_ESI = (int)_Dst;
  }
  return;
}

