
undefined4 FUN_00733aaf(void)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI != unaff_EBX) {
    FUN_00431a90(unaff_EBX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(*(int *)(*unaff_ESI + 4) + 0x38 + (int)unaff_ESI);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}

