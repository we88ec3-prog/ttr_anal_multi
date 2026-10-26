
void FUN_0062d760(int param_1)

{
  void *_Src;
  void *_Dst;
  uint unaff_EDI;
  
  FUN_0062daa0(&stack0x00000008);
  if ((param_1 != *(int *)(param_1 + 0x120)) &&
     (unaff_EDI < (uint)(*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40) >> 2))) {
    _Dst = (void *)(*(int *)(param_1 + 0x40) + unaff_EDI * 4);
    _Src = (void *)((int)_Dst + 4);
    FID_conflict__memcpy(_Dst,_Src,(*(int *)(param_1 + 0x44) - (int)_Src >> 2) * 4);
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -4;
  }
  return;
}

