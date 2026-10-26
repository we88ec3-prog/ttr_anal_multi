
void FUN_00401000(void)

{
  int unaff_ESI;
  
  if (0xf < *(uint *)(unaff_ESI + 0xe0)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0xcc));
  }
  *(undefined4 *)(unaff_ESI + 0xe0) = 0xf;
  *(undefined4 *)(unaff_ESI + 0xdc) = 0;
  *(undefined1 *)(unaff_ESI + 0xcc) = 0;
  FUN_0071bc90(unaff_ESI);
  return;
}

