
void FUN_006df6d0(void)

{
  int iVar1;
  
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 != 0) {
      DAT_00fba7cc = FUN_006df3d0();
      return;
    }
    DAT_00fba7cc = 0;
  }
  return;
}

