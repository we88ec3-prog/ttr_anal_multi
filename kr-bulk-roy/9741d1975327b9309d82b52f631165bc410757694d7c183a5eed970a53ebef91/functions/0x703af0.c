
void FUN_00703af0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xc);
  if (0x1f < iVar1) {
    FUN_006f5f30(*(undefined4 *)(unaff_ESI + 8),"too many captures");
  }
  *(undefined4 *)(unaff_ESI + 0x10 + iVar1 * 8) = param_1;
  *(undefined4 *)(unaff_ESI + 0x14 + iVar1 * 8) = param_3;
  *(int *)(unaff_ESI + 0xc) = iVar1 + 1;
  iVar1 = FUN_00703c30();
  if (iVar1 == 0) {
    *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + -1;
  }
  return;
}

