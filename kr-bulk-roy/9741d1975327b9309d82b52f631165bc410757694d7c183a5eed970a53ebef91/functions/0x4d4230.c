
/* WARNING: Removing unreachable block (ram,0x004d4250) */
/* WARNING: Removing unreachable block (ram,0x004d4251) */
/* WARNING: Removing unreachable block (ram,0x004d4265) */

void FUN_004d4230(void)

{
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x10c) = 0;
  if (*(int *)(unaff_ESI + 0xfc) != *(int *)(unaff_ESI + 0x100)) {
    *(int *)(unaff_ESI + 0x100) = *(int *)(unaff_ESI + 0xfc);
  }
  return;
}

