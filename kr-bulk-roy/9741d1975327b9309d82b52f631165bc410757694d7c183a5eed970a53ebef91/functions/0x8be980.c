
int FUN_008be980(void *param_1)

{
  size_t in_EAX;
  int iVar1;
  int unaff_ESI;
  void *_Dst;
  int local_8;
  
  local_8 = 0;
  iVar1 = FUN_008bc7d0(*(undefined4 *)(unaff_ESI + 0x44088),1,*(int *)(unaff_ESI + 0x58),
                       *(int *)(unaff_ESI + 0x58) + 1 + in_EAX,*(undefined4 *)(unaff_ESI + 0x54),
                       &local_8);
  *(int *)(unaff_ESI + 0x54) = iVar1;
  if (local_8 == 0) {
    _Dst = (void *)(*(int *)(unaff_ESI + 0x58) + iVar1);
    FID_conflict__memcpy(_Dst,param_1,in_EAX);
    *(undefined1 *)((int)_Dst + in_EAX) = 10;
    *(int *)(unaff_ESI + 0x58) = *(int *)(unaff_ESI + 0x58) + in_EAX + 1;
    return local_8;
  }
  return local_8;
}

