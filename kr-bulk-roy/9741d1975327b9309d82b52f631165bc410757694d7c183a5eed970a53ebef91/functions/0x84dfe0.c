
void FUN_0084dfe0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x40) != 0) {
    FUN_0084d650(*(int *)(unaff_ESI + 0x40));
    *(undefined4 *)(unaff_ESI + 0x40) = 0;
  }
  if (*(int *)(unaff_ESI + 0x48) != *(int *)(unaff_ESI + 0x4c)) {
    uVar1 = FUN_008525a0(*(int *)(unaff_ESI + 0x4c));
    FUN_008510f0(*(undefined4 *)(unaff_ESI + 0x4c));
    *(undefined4 *)(unaff_ESI + 0x4c) = uVar1;
  }
  *(undefined4 *)(unaff_ESI + 0x38) = 1;
  return;
}

