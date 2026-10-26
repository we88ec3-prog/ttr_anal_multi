
void FUN_00559310(void)

{
  int unaff_ESI;
  
  if (*(int **)(unaff_ESI + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x9c) + 8))();
    *(undefined4 *)(unaff_ESI + 0x9c) = 0;
  }
  if (*(int **)(unaff_ESI + 0x78) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x78) + 8))();
    *(undefined4 *)(unaff_ESI + 0x78) = 0;
  }
  if (*(int **)(unaff_ESI + 0x58) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x58) + 8))();
    *(undefined4 *)(unaff_ESI + 0x58) = 0;
  }
  if (*(int **)(unaff_ESI + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x38) + 8))();
    *(undefined4 *)(unaff_ESI + 0x38) = 0;
  }
  if (*(int **)(unaff_ESI + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x30) + 8))();
    *(undefined4 *)(unaff_ESI + 0x30) = 0;
  }
  if (*(int **)(unaff_ESI + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x10) + 8))();
    *(undefined4 *)(unaff_ESI + 0x10) = 0;
  }
  return;
}

