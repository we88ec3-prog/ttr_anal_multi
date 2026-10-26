
void FUN_0059dc30(void)

{
  int unaff_ESI;
  
  if (((uint)(*(int **)(unaff_ESI + 0x1ec))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x1ec) + 0xd4))();
  }
  if (((uint)(*(int **)(unaff_ESI + 0x1e8))[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0059dc66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x1e8) + 0xd4))();
    return;
  }
  return;
}

