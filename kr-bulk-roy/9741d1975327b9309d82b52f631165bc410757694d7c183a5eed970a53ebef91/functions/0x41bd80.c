
undefined4 * FUN_0041bd80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_EDX;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  puVar2 = unaff_EDI;
  for (iVar1 = unaff_ESI; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *in_EDX;
    puVar2 = puVar2 + 1;
  }
  return unaff_EDI + unaff_ESI;
}

