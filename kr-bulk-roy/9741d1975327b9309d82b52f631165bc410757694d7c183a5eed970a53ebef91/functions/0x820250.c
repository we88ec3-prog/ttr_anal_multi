
void FUN_00820250(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  undefined2 *unaff_EDI;
  
  puVar1 = (undefined4 *)FUN_00820120();
  *puVar1 = *(undefined4 *)(unaff_ESI + 4);
  puVar1[1] = *(undefined4 *)(unaff_ESI + 4);
  puVar1[2] = *(undefined4 *)(unaff_ESI + 4);
  *(undefined2 *)(puVar1 + 6) = 0;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    *(undefined2 *)(puVar1 + 3) = *unaff_EDI;
    puVar1[4] = *(undefined4 *)(unaff_EDI + 2);
    puVar1[5] = *(undefined4 *)(unaff_EDI + 4);
  }
  return;
}

