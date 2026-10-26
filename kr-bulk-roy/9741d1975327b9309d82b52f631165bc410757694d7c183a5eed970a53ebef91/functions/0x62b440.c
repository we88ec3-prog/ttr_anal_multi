
void FUN_0062b440(int param_1)

{
  void *_Src;
  void *_Dst;
  uint in_EAX;
  int *piVar1;
  
  FUN_0062daa0(&stack0x00000008);
  if (param_1 != *(int *)(param_1 + 0x104)) {
    if (in_EAX < (uint)(*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40) >> 2)) {
      _Dst = (void *)(*(int *)(param_1 + 0x40) + in_EAX * 4);
      _Src = (void *)((int)_Dst + 4);
      FID_conflict__memcpy(_Dst,_Src,(*(int *)(param_1 + 0x44) - (int)_Src >> 2) * 4);
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -4;
      return;
    }
    if ((in_EAX == 1) && (piVar1 = (int *)FUN_00831f50(), *(char *)(*piVar1 + 0x254) != '\0')) {
      FUN_0062da70(*(int *)(param_1 + 0x40));
    }
  }
  return;
}

