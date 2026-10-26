
void FUN_00438ef2(void)

{
  int *piVar1;
  char cVar2;
  int unaff_EBP;
  int *unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_00431a90(0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 5;
  cVar2 = thunk_FUN_0089ccbb();
  if (cVar2 == '\0') {
    FUN_006ddfe0();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(*(int *)(*unaff_EDI + 4) + 0x38 + (int)unaff_EDI);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

