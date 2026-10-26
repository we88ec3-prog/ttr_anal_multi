
/* WARNING: Removing unreachable block (ram,0x0082cdb1) */

void FUN_0082cda0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 4) != *(int *)(unaff_ESI + 8)) {
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 4);
  }
  if (*(int *)(unaff_ESI + 4) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 4) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  FUN_0089120c();
  return;
}

