
void FUN_008674a0(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (*(int *)(unaff_ESI + 8) == 0) {
    puVar1 = (undefined4 *)FUN_00891268(8);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
      puVar1[1] = 0;
      *(undefined4 **)(unaff_ESI + 8) = puVar1;
      *puVar1 = *unaff_EDI;
      puVar1[1] = unaff_EDI[1];
      return;
    }
    *(undefined4 *)(unaff_ESI + 8) = 0;
  }
  puVar1 = *(undefined4 **)(unaff_ESI + 8);
  *puVar1 = *unaff_EDI;
  puVar1[1] = unaff_EDI[1];
  return;
}

