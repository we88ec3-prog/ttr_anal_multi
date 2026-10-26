
undefined4 FUN_006ff0c0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((0x11b < unaff_ESI) && (unaff_ESI < 0x11f)) {
    FUN_006fef80(0);
    return **(undefined4 **)(unaff_EDI + 0x3c);
  }
  if (0x100 < unaff_ESI) {
    return *(undefined4 *)(&DAT_00c0babc + unaff_ESI * 4);
  }
  iVar1 = _iscntrl(unaff_ESI);
  if (iVar1 != 0) {
    uVar2 = FUN_006f7c30(*(undefined4 *)(unaff_EDI + 0x34),"char(%d)");
    return uVar2;
  }
  uVar2 = FUN_006f7c30(*(undefined4 *)(unaff_EDI + 0x34),&DAT_00c41240);
  return uVar2;
}

