
void FUN_00765c20(void)

{
  int unaff_ESI;
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(unaff_ESI + 0x114) - *(int *)(unaff_ESI + 0x110) >> 2 != 0) {
    do {
      FUN_004041f0(*(undefined4 *)(*(int *)(unaff_ESI + 0x110) + uVar1 * 4),0,0xffffffff);
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(unaff_ESI + 0x114) - *(int *)(unaff_ESI + 0x110) >> 2));
  }
  return;
}

