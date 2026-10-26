
void FUN_006f5300(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  
  puVar2 = (undefined4 *)FUN_006f50f0();
  puVar1 = *(undefined4 **)(unaff_ESI + 8);
  *puVar1 = *puVar2;
  puVar1[1] = puVar2[1];
  puVar1[2] = puVar2[2];
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return;
}

