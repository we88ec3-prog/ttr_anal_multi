
void FUN_005bbca0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x2c4) == 0) {
    return;
  }
  if ((*(uint *)(*(int *)(unaff_ESI + 0x2c4) + 0x28) >> 8 & 1) == 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x2c4) + 0xd0))();
    FUN_005bbce0();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005bbcd1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_ESI + 0x2c4) + 0xd4))();
  return;
}

