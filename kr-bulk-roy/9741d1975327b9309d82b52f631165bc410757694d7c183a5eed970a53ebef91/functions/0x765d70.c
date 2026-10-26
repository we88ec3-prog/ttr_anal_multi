
void FUN_00765d70(void)

{
  void *_Src;
  int iVar1;
  int iVar2;
  int in_EAX;
  void *_Dst;
  int unaff_ESI;
  
  iVar2 = in_EAX * 4;
  if (*(int *)(*(int *)(unaff_ESI + 0x110) + iVar2) != 0) {
    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x110) + iVar2);
    if (iVar1 != 0) {
      FUN_00757640(iVar1);
      FUN_0089120c(iVar1);
    }
    *(undefined4 *)(iVar2 + *(int *)(unaff_ESI + 0x110)) = 0;
  }
  _Dst = (void *)(*(int *)(unaff_ESI + 0x110) + iVar2);
  _Src = (void *)((int)_Dst + 4);
  FID_conflict__memcpy(_Dst,_Src,(*(int *)(unaff_ESI + 0x114) - (int)_Src >> 2) * 4);
  *(int *)(unaff_ESI + 0x114) = *(int *)(unaff_ESI + 0x114) + -4;
  return;
}

