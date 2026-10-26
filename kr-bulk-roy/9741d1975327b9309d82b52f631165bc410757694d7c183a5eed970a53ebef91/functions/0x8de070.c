
void FUN_008de070(undefined4 param_1)

{
  undefined1 *unaff_ESI;
  
  if (*(int *)(unaff_ESI + 8) != 0) {
    FUN_008bab90(param_1,unaff_ESI + 8);
  }
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *unaff_ESI = 0;
  *(undefined4 *)(unaff_ESI + 4) = 0;
  return;
}

