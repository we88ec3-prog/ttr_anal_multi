
int FUN_008456c0(void)

{
  int iVar1;
  uint unaff_ESI;
  
  if (DAT_00f7afa0 == 0) {
    return 0;
  }
  if ((DAT_00f7af98 < unaff_ESI) || (DAT_00f7af98 < DAT_00f7af9c + unaff_ESI)) {
    if (DAT_00f7afa4 == '\0') {
      return 0;
    }
    FUN_00845670();
  }
  iVar1 = DAT_00f7af9c + DAT_00f7afa0;
  DAT_00f7af9c = DAT_00f7af9c + unaff_ESI;
  return iVar1;
}

