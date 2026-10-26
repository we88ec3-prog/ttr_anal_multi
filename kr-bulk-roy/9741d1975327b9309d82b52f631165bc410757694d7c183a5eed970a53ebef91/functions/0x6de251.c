
uint FUN_006de251(void)

{
  uint uVar1;
  int unaff_EBP;
  int *unaff_EDI;
  
  if (*(int *)((int)unaff_EDI + *(int *)(*unaff_EDI + 4) + 0xc) == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return CONCAT31((int3)((uint)*unaff_EDI >> 8),1);
  }
  uVar1 = FUN_00431a90(0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1 & 0xffffff00;
}

