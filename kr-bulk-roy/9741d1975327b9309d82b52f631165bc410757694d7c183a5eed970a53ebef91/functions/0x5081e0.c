
/* WARNING: Removing unreachable block (ram,0x005081f1) */

void FUN_005081e0(void)

{
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x14) != *(int *)(unaff_EDI + 0x18)) {
    *(int *)(unaff_EDI + 0x18) = *(int *)(unaff_EDI + 0x14);
  }
  return;
}

