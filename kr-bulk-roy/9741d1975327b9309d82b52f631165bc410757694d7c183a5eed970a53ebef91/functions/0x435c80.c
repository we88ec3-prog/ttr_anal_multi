
void FUN_00435c80(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0xfc) + 0xcc);
  if (iVar2 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0xdc);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x20);
    }
  }
  *(undefined4 *)(unaff_EDI + 0x154) = *(undefined4 *)(unaff_EDI + 0x138 + iVar2 * 4);
  *(undefined4 *)(unaff_EDI + 0x138 + iVar2 * 4) = 0xffffffff;
  uVar1 = FUN_006bde40((undefined4 *)(unaff_EDI + 0x154));
  FUN_00436890(unaff_EDI + 0x144,uVar1);
  FUN_00435a90(unaff_EDI);
  return;
}

