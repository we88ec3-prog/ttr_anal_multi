
void FUN_004bfed0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00fe1ab0;
  iVar1 = DAT_00fe1aac;
  if (DAT_00fe1aac != 0) {
    for (; iVar1 != iVar2; iVar1 = iVar1 + 0x58) {
      FUN_004c0590();
    }
    FUN_0089120c(DAT_00fe1aac);
  }
  DAT_00fe1aac = 0;
  DAT_00fe1ab0 = 0;
  DAT_00fe1ab4 = 0;
  return;
}

