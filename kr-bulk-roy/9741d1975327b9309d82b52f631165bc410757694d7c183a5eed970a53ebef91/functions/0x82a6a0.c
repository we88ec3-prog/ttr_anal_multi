
void FUN_0082a6a0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined2 *unaff_ESI;
  int unaff_EDI;
  
  piVar3 = (int *)FUN_005740f0(&stack0x00000004);
  iVar2 = *piVar3;
  iVar1 = *(int *)(unaff_EDI + 4);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  if (iVar2 != iVar1) {
    *unaff_ESI = 0;
    FUN_004026e0(iVar2 + 0x10,0,0xffffffff);
    return;
  }
  *unaff_ESI = 0;
  FUN_00402160(&DAT_00bed1fc,0);
  return;
}

