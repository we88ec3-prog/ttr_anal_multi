
void FUN_00750350(void)

{
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x13dc) = 0;
  *(undefined4 *)(unaff_ESI + 0x13d0) = 0;
  *(undefined4 *)(unaff_ESI + 0x13e4) = 0;
  *(undefined4 *)(unaff_ESI + 0x13cc) = 0;
  *(undefined4 *)(unaff_ESI + 0x13e0) = 0;
  *(undefined4 *)(unaff_ESI + 0x13e8) = 0;
  *(undefined4 *)(unaff_ESI + 0x13d4) = 0;
  *(undefined4 *)(unaff_ESI + 0x13ec) = 0;
  if (*(int **)(unaff_ESI + 0x13f0) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x13f0) + 0xd4))();
  }
  if (*(int **)(unaff_ESI + 0x13f0) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x13f0) + 0x130))();
  }
  *(undefined4 *)(unaff_ESI + 0x13c8) = 0;
  *(undefined4 *)(unaff_ESI + 0x13f0) = 0;
  return;
}

