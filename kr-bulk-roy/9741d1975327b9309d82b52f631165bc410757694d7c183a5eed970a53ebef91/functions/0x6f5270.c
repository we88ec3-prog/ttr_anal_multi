
void FUN_006f5270(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  
  puVar1 = (undefined4 *)FUN_006f50f0();
  puVar2 = puVar1 + 4;
  if (puVar2 < *(undefined4 **)(unaff_ESI + 8)) {
    do {
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar1[6];
      puVar2 = puVar2 + 4;
      puVar1 = puVar1 + 4;
    } while (puVar2 < *(undefined4 **)(unaff_ESI + 8));
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  return;
}

