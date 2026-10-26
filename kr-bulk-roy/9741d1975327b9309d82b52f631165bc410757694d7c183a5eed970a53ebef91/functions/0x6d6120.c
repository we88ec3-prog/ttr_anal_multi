
void FUN_006d6120(void)

{
  int *piVar1;
  int unaff_ESI;
  uint unaff_EDI;
  
  if (1 < *(int *)(unaff_ESI + 4)) {
    (**(code **)(**(int **)(unaff_ESI + 0x18) + 0x14))();
  }
  if (0 < *(int *)(unaff_ESI + 4)) {
    (**(code **)(**(int **)(unaff_ESI + 0x18) + 0xc))();
  }
  if ((uint)(*(int *)(unaff_ESI + 0xc) - *(int *)(unaff_ESI + 8) >> 2) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  piVar1 = *(int **)(*(int *)(unaff_ESI + 8) + unaff_EDI * 4);
  *(int **)(unaff_ESI + 0x18) = piVar1;
  if (0 < *(int *)(unaff_ESI + 4)) {
    (**(code **)(*piVar1 + 8))();
  }
  if (1 < *(int *)(unaff_ESI + 4)) {
                    /* WARNING: Could not recover jumptable at 0x006d617a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x18) + 0x10))();
    return;
  }
  return;
}

