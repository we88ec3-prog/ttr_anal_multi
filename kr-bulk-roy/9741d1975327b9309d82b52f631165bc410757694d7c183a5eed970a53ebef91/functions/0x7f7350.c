
void FUN_007f7350(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x70) != 0) {
    FUN_00891d3d(*(int *)(unaff_ESI + 0x70));
    *(undefined4 *)(unaff_ESI + 0x70) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x74) = 0;
  FUN_0089120c();
  return;
}

