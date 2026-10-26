
void FUN_004ec6f0(void)

{
  void *_Src;
  void *_Dst;
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar2 = 0;
  uVar1 = *(int *)(unaff_ESI + 0x5eb0) - *(int *)(unaff_ESI + 0x5eac) >> 2;
  if (uVar1 != 0) {
    piVar3 = *(int **)(unaff_ESI + 0x5eac);
    while (*(int *)(*piVar3 + 4) != unaff_EDI) {
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
      if (uVar1 <= uVar2) {
        return;
      }
    }
    _Dst = (void *)(*(int *)(unaff_ESI + 0x5eac) + uVar2 * 4);
    _Src = (void *)((int)_Dst + 4);
    FID_conflict__memcpy(_Dst,_Src,(*(int *)(unaff_ESI + 0x5eb0) - (int)_Src >> 2) * 4);
    *(int *)(unaff_ESI + 0x5eb0) = *(int *)(unaff_ESI + 0x5eb0) + -4;
  }
  return;
}

