
undefined4 * FUN_006f9c10(void)

{
  undefined4 *puVar1;
  int in_EDX;
  int unaff_ESI;
  
  puVar1 = (undefined4 *)
           (((1 << (*(byte *)(in_EDX + 7) & 0x1f)) - 1U & *(uint *)(unaff_ESI + 8)) * 0x20 +
           *(int *)(in_EDX + 0x10));
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return &DAT_00c0bfc8;
    }
    if ((puVar1[6] == 4) && (puVar1[4] == unaff_ESI)) break;
    puVar1 = (undefined4 *)puVar1[7];
  }
  return puVar1;
}

