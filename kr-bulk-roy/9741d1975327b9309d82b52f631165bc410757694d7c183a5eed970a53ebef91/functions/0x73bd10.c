
void FUN_0073bd10(void)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  
  uVar2 = 0;
  if (*(int *)(unaff_EDI + 0x1c) - *(int *)(unaff_EDI + 0x18) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(unaff_EDI + 0x18) + uVar2 * 4);
      if (iVar1 != 0) {
        if (*(HGDIOBJ *)(iVar1 + 0xac) != (HGDIOBJ)0x0) {
          DeleteObject(*(HGDIOBJ *)(iVar1 + 0xac));
          *(undefined4 *)(iVar1 + 0xac) = 0;
        }
        FUN_0089120c(iVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_EDI + 0x1c) - *(int *)(unaff_EDI + 0x18) >> 2));
  }
  return;
}

