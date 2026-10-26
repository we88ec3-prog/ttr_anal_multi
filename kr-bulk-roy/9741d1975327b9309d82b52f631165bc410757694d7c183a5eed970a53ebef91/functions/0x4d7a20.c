
void FUN_004d7a20(void)

{
  short *psVar1;
  short sVar2;
  bool bVar3;
  short *psVar4;
  undefined4 *_Src;
  int unaff_ESI;
  undefined4 *_Dst;
  
  _Dst = *(undefined4 **)(unaff_ESI + 0x10c);
  bVar3 = false;
  if (_Dst != *(undefined4 **)(unaff_ESI + 0x110)) {
    _Src = _Dst + 1;
    do {
      psVar4 = (short *)*_Dst;
      psVar1 = psVar4 + 1;
      do {
        sVar2 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar2 != 0);
      if ((int)psVar4 - (int)psVar1 >> 1 == 0) {
        _Dst = _Dst + 1;
        _Src = _Src + 1;
      }
      else {
        FID_conflict__memcpy(_Dst,_Src,(*(int *)(unaff_ESI + 0x110) - (int)_Src >> 2) * 4);
        *(int *)(unaff_ESI + 0x110) = *(int *)(unaff_ESI + 0x110) + -4;
        bVar3 = true;
      }
    } while (_Dst != *(undefined4 **)(unaff_ESI + 0x110));
    if (bVar3) {
      FUN_004d6c90();
    }
  }
  return;
}

