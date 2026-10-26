
undefined4 FUN_008fc610(void)

{
  void *_Dst;
  uint _Size;
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int local_8;
  
  _Size = *(uint *)(unaff_ESI + 0x54);
  if (_Size == 0) {
    iVar2 = 0x200;
  }
  else {
    iVar2 = (_Size >> 2) + _Size;
  }
  iVar1 = FUN_008bc7d0(*(undefined4 *)(unaff_ESI + 0xa8),3,_Size,iVar2,
                       *(undefined4 *)(unaff_ESI + 0x4c),&local_8);
  *(int *)(unaff_ESI + 0x4c) = iVar1;
  if (local_8 != 0) {
    return 0xffffffff;
  }
  _Dst = (void *)(iVar1 + iVar2 * 2);
  *(void **)(unaff_ESI + 0x50) = _Dst;
  FID_conflict__memcpy(_Dst,(void *)(iVar1 + _Size * 2),_Size);
  *(int *)(unaff_ESI + 0x54) = iVar2;
  return 0;
}

