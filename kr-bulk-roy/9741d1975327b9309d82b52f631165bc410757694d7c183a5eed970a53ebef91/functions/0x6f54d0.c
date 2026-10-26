
void FUN_006f54d0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <= *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44))
  {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(unaff_ESI + 8);
  uVar2 = FUN_006fec70();
  *puVar1 = uVar2;
  puVar1[2] = 4;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return;
}

