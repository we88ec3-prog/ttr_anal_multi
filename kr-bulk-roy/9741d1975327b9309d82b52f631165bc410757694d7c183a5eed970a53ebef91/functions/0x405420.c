
void FUN_00405420(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar1 = param_1;
  *(undefined4 *)(unaff_EDI + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(unaff_EDI + 8) = *(undefined1 *)(param_1 + 8);
  *(undefined1 *)(unaff_EDI + 9) = *(undefined1 *)(param_1 + 9);
  *(undefined1 *)(unaff_EDI + 10) = *(undefined1 *)(param_1 + 10);
  iVar2 = param_1 - unaff_EDI;
  *(undefined1 *)(unaff_EDI + 0xb) = *(undefined1 *)(param_1 + 0xb);
  iVar3 = unaff_EDI + 0xc;
  param_1 = 6;
  do {
    FUN_004026e0(iVar2 + iVar3,0,0xffffffff);
    iVar3 = iVar3 + 0x1c;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  FUN_004026e0(iVar1 + 0xb4,0,0xffffffff);
  FUN_004026e0(iVar1 + 0xd0,0,0xffffffff);
  return;
}

