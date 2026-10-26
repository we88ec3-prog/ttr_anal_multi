
void FUN_00572150(void)

{
  char cVar1;
  int unaff_EDI;
  
  FUN_005f5d10();
  cVar1 = FUN_00572230();
  if (cVar1 != '\0') {
    if (*(int *)(unaff_EDI + 4) == *(int *)(unaff_EDI + 8)) {
      FUN_00572250();
    }
    FUN_005724a0();
    *(int *)(unaff_EDI + 4) = *(int *)(unaff_EDI + 4) + 4;
    return;
  }
  if (*(int *)(unaff_EDI + 4) == *(int *)(unaff_EDI + 8)) {
    FUN_00572250();
  }
  FUN_005724b0();
  *(int *)(unaff_EDI + 4) = *(int *)(unaff_EDI + 4) + 4;
  return;
}

