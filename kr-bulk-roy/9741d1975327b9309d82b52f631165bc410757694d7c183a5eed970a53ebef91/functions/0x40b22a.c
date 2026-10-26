
void FUN_0040b22a(void)

{
  size_t _Size;
  undefined4 *puVar1;
  int unaff_EBP;
  uint unaff_ESI;
  undefined4 *unaff_EDI;
  
  _Size = *(size_t *)(unaff_EBP + 0x10);
  if (_Size != 0) {
    puVar1 = unaff_EDI;
    if (0xf < (uint)unaff_EDI[5]) {
      puVar1 = (undefined4 *)*unaff_EDI;
    }
    FID_conflict__memcpy(*(void **)(unaff_EBP + 0xc),puVar1,_Size);
  }
  if (0xf < (uint)unaff_EDI[5]) {
    FUN_0089120c(*unaff_EDI);
  }
  puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
  *(undefined1 *)unaff_EDI = 0;
  *unaff_EDI = puVar1;
  unaff_EDI[5] = unaff_ESI;
  unaff_EDI[4] = _Size;
  if (0xf < unaff_ESI) {
    unaff_EDI = puVar1;
  }
  *(undefined1 *)((int)unaff_EDI + _Size) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

