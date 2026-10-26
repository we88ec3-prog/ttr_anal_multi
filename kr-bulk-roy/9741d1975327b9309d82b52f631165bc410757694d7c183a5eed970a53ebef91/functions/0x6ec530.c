
void FUN_006ec530(void)

{
  int unaff_ESI;
  
  if (*(void **)(unaff_ESI + 0x44) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x44));
    *(undefined4 *)(unaff_ESI + 0x44) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  if (*(void **)(unaff_ESI + 0x38) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x38));
    *(undefined4 *)(unaff_ESI + 0x38) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  if (*(void **)(unaff_ESI + 0x2c) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x2c));
    *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  if (*(void **)(unaff_ESI + 0x20) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x20));
    *(undefined4 *)(unaff_ESI + 0x20) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  if (*(void **)(unaff_ESI + 0x14) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x14));
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  return;
}

