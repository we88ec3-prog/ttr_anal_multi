
void FUN_00539630(void)

{
  int iVar1;
  int unaff_ESI;
  
  FUN_00797a00();
  iVar1 = *(int *)(unaff_ESI + 0x28);
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  *(int *)(unaff_ESI + 0x28) = 0;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x18) = 7;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined2 *)(unaff_ESI + 4) = 0;
  return;
}

