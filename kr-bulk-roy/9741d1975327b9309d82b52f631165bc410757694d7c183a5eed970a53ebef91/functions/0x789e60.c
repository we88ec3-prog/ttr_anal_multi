
void FUN_00789e60(void)

{
  undefined4 *puVar1;
  undefined4 *in_EDX;
  int unaff_ESI;
  
  if (in_EDX != (undefined4 *)0x0) {
    puVar1 = in_EDX + 1;
    *in_EDX = gbKey<gbQuat>::vftable;
    *puVar1 = 0;
    in_EDX[2] = 0;
    in_EDX[3] = 0;
    in_EDX[4] = 0x3f800000;
    if (puVar1 != (undefined4 *)(unaff_ESI + 4)) {
      in_EDX[4] = *(undefined4 *)(unaff_ESI + 0x10);
      *puVar1 = *(undefined4 *)(unaff_ESI + 4);
      in_EDX[2] = *(undefined4 *)(unaff_ESI + 8);
      in_EDX[3] = *(undefined4 *)(unaff_ESI + 0xc);
    }
    in_EDX[5] = *(undefined4 *)(unaff_ESI + 0x14);
    in_EDX[6] = *(undefined4 *)(unaff_ESI + 0x18);
  }
  return;
}

