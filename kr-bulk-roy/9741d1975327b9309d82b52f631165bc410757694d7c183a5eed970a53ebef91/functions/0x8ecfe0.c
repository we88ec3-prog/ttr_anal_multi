
void FUN_008ecfe0(void)

{
  void *_Dst;
  int iVar1;
  undefined4 uVar2;
  int *in_EAX;
  int iVar3;
  int unaff_ESI;
  
  iVar1 = *in_EAX;
  if ((0 < iVar1) && (iVar1 <= *(int *)(unaff_ESI + 0x1c))) {
    iVar3 = *(int *)(unaff_ESI + 0x1c) - iVar1;
    uVar2 = *(undefined4 *)(*(int *)(unaff_ESI + 0x18) + iVar3 * 4);
    _Dst = (void *)(*(int *)(unaff_ESI + 0x18) + iVar3 * 4);
    FID_conflict__memcpy(_Dst,(void *)((int)_Dst + 4),iVar1 * 4 - 4);
    *(undefined4 *)(*(int *)(unaff_ESI + 0x18) + -4 + *(int *)(unaff_ESI + 0x1c) * 4) = uVar2;
    return;
  }
  if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  return;
}

