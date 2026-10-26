
void FUN_005baf70(void)

{
  int *piVar1;
  int unaff_ESI;
  
  if (((uint)(*(int **)(unaff_ESI + 0x224))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x224) + 0xd4))();
  }
  piVar1 = *(int **)(unaff_ESI + 0x2ac);
  if (((uint)piVar1[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005bafa5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xd4))();
    return;
  }
  FUN_00596e00(unaff_ESI,piVar1);
  return;
}

