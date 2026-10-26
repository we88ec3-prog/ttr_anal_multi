
void FUN_007a6c30(void)

{
  int unaff_ESI;
  
  if (*(int **)(unaff_ESI + 0x120) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x120) + 0x10))();
    (**(code **)(**(int **)(unaff_ESI + 0x120) + 8))();
    *(undefined4 *)(unaff_ESI + 0x120) = 0;
  }
  return;
}

