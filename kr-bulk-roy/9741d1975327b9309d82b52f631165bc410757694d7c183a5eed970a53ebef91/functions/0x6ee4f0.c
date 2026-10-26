
undefined4 FUN_006ee4f0(void)

{
  uint uVar1;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x34) != 0) {
    uVar1 = 0;
    if (*(int *)(unaff_EDI + 0x34) != 0) {
      do {
        SetEvent(*(HANDLE *)(*(int *)(unaff_EDI + 4) + uVar1 * 4));
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(unaff_EDI + 0x34));
    }
    WaitForMultipleObjects(*(DWORD *)(unaff_EDI + 0x34),*(HANDLE **)(unaff_EDI + 0x14),1,0xffffffff)
    ;
    *(undefined4 *)(unaff_EDI + 0x34) = 0;
    return 1;
  }
  return 0;
}

