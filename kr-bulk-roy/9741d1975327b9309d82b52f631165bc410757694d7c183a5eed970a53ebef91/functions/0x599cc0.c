
void FUN_00599cc0(void)

{
  int unaff_ESI;
  
  if (((uint)(*(int **)(unaff_ESI + 0x184))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x184) + 0xd4))();
  }
  if (((uint)(*(int **)(unaff_ESI + 0x188))[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00599cf6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x188) + 0xd4))();
    return;
  }
  return;
}

