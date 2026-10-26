
void FUN_008674e0(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 8) == 0) {
    puVar1 = (undefined4 *)FUN_00891268(0xc);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
    }
    *(undefined4 **)(unaff_EDI + 8) = puVar1;
  }
  puVar1 = *(undefined4 **)(unaff_EDI + 8);
  *puVar1 = *unaff_ESI;
  puVar1[1] = unaff_ESI[1];
  puVar1[2] = unaff_ESI[2];
  return;
}

