
/* WARNING: Removing unreachable block (ram,0x007ee968) */
/* WARNING: Removing unreachable block (ram,0x007ee970) */
/* WARNING: Removing unreachable block (ram,0x007ee990) */

void FUN_007ee950(void)

{
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  if (*(int *)(unaff_ESI + 4) != *(int *)(unaff_ESI + 8)) {
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 4);
  }
  return;
}

