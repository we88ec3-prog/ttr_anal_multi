
void FUN_006ddd99(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_00431a90(0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(*(int *)(*unaff_ESI + 4) + 0x38 + (int)unaff_ESI);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

