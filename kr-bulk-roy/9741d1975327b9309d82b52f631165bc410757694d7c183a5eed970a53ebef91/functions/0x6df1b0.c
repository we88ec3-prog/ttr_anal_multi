
undefined4 FUN_006df1b0(void)

{
  int iVar1;
  
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 != 0) {
      DAT_00fba7cc = FUN_006df3d0();
      return *(undefined4 *)(DAT_00fba7cc + 0x1360);
    }
    DAT_00fba7cc = 0;
  }
  return *(undefined4 *)(DAT_00fba7cc + 0x1360);
}

