
undefined4 FUN_005a51e0(void)

{
  int unaff_EDI;
  
  if (((*(uint *)(*(int *)(unaff_EDI + 0x144) + 0x28) >> 8 & 1) == 0) &&
     (*(char *)(unaff_EDI + 0x134) == '\0')) {
    FUN_00641d90(*(int *)(unaff_EDI + 0x144));
    (**(code **)(**(int **)(unaff_EDI + 0x144) + 0xd0))();
    FUN_00643220();
    *(undefined1 *)(unaff_EDI + 0x13c) = 1;
    FUN_0040f060();
    *(undefined4 *)(DAT_00fba7a4 + 8) = 0;
    return 1;
  }
  return 0;
}

