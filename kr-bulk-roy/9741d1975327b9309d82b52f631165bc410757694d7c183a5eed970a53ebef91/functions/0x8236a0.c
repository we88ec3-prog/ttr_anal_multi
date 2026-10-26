
void FUN_008236a0(void)

{
  int iVar1;
  undefined2 *unaff_ESI;
  int unaff_EDI;
  
  FUN_008438c0(&stack0x00000004);
  if (*(int *)(unaff_EDI + 4) == 0) {
    *(undefined4 *)(unaff_ESI + 10) = 7;
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *unaff_ESI = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    return;
  }
  iVar1 = iRam00000010 + 0x2c;
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  FUN_004026e0(iVar1,0,0xffffffff);
  return;
}

