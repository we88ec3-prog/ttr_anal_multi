
void FUN_00703b40(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xc) + -1;
  if (-1 < iVar1) {
    piVar3 = (int *)(unaff_ESI + 0x14 + iVar1 * 8);
    do {
      if (*piVar3 == -1) goto LAB_00703b6e;
      piVar3 = piVar3 + -2;
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  iVar1 = FUN_006f5f30(*(undefined4 *)(unaff_ESI + 8),"invalid pattern capture");
LAB_00703b6e:
  *(int *)(unaff_ESI + 0x14 + iVar1 * 8) = param_1 - *(int *)(unaff_ESI + 0x10 + iVar1 * 8);
  iVar2 = FUN_00703c30();
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_ESI + 0x14 + iVar1 * 8) = 0xffffffff;
  }
  return;
}

