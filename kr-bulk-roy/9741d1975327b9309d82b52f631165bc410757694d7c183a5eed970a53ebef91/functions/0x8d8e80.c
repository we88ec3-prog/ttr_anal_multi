
void FUN_008d8e80(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x1c);
  FUN_008d8d00();
  *(undefined1 *)(unaff_EDI + 0x20) = 1;
  if ((*(uint *)(iVar1 + 4) < (uint)(*(short *)(iVar1 + 0x3a) + 1 + (int)*(short *)(iVar1 + 0x16)))
     || (*(uint *)(iVar1 + 8) < (uint)(*(short *)(iVar1 + 0x38) + 1 + (int)*(short *)(iVar1 + 0x14))
        )) {
    iVar1 = FUN_008bc9a0(iVar1,1,1);
    if (iVar1 != 0) {
      return;
    }
  }
  FUN_008d8d90();
  return;
}

