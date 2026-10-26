
void FUN_004c7db0(void)

{
  int unaff_EDI;
  
  FUN_007be5f0();
  if (*(int **)(unaff_EDI + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 0x28) + 0x10))();
    if (*(int **)(unaff_EDI + 0x28) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EDI + 0x28) + 8))();
      *(undefined4 *)(unaff_EDI + 0x28) = 0;
    }
  }
  FUN_0089120c();
  return;
}

