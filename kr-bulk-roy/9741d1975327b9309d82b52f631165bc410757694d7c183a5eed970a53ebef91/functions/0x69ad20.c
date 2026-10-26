
void FUN_0069ad20(void)

{
  void *_Src;
  void *_Dst;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar2 = 0;
  uVar1 = *(int *)(unaff_ESI + 0x168) - *(int *)(unaff_ESI + 0x164) >> 2;
  if (uVar1 != 0) {
    puVar3 = *(undefined4 **)(unaff_ESI + 0x164);
    while (*(int *)*puVar3 != unaff_EDI) {
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
      if (uVar1 <= uVar2) {
        return;
      }
    }
    _Dst = (void *)(*(int *)(unaff_ESI + 0x164) + uVar2 * 4);
    _Src = (void *)((int)_Dst + 4);
    FID_conflict__memcpy(_Dst,_Src,(*(int *)(unaff_ESI + 0x168) - (int)_Src >> 2) * 4);
    *(int *)(unaff_ESI + 0x168) = *(int *)(unaff_ESI + 0x168) + -4;
    (**(code **)(**(int **)(unaff_ESI + 0xbc) + 0x90))
              (*(int *)(unaff_ESI + 0x164) != *(int *)(unaff_ESI + 0x168));
    FUN_0069a050(unaff_ESI);
  }
  return;
}

