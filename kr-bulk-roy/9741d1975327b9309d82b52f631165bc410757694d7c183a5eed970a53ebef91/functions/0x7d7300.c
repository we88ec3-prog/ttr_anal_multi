
void FUN_007d7300(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x3ecc) != 0) {
    MessageBoxA((HWND)0x0,"Decal Refcount Error","ERROR",0);
  }
  if (0xf < *(uint *)(unaff_ESI + 0x3ec4)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x3eb0));
  }
  *(undefined4 *)(unaff_ESI + 0x3ec4) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x3ec0) = 0;
  *(undefined1 *)(unaff_ESI + 0x3eb0) = 0;
  return;
}

