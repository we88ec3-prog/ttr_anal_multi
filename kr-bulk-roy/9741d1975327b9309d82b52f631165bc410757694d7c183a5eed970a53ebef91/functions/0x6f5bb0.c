
void FUN_006f5bb0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (1 < in_EAX) {
    if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <= *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44)
       ) {
      FUN_006fb3a0();
    }
    FUN_006fc080();
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + in_EAX * -0x10 + 0x10;
    return;
  }
  if (in_EAX == 0) {
    puVar1 = *(undefined4 **)(unaff_ESI + 8);
    uVar2 = FUN_006fec70();
    *puVar1 = uVar2;
    puVar1[2] = 4;
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  }
  return;
}

