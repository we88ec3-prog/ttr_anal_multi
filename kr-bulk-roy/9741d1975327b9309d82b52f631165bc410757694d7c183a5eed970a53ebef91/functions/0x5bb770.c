
void FUN_005bb770(void)

{
  int unaff_ESI;
  
  if (((uint)(*(int **)(unaff_ESI + 0x224))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x224) + 0xd4))();
  }
                    /* WARNING: Could not recover jumptable at 0x005bb79b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_ESI + 0x2c0) + 0xd0))();
  return;
}

