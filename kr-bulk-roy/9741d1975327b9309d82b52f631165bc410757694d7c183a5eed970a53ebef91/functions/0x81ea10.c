
void FUN_0081ea10(void)

{
  int iVar1;
  
  iVar1 = FUN_00714550("Table/Filter.txt");
  if (iVar1 != 0) {
    FUN_0081e800(&DAT_00fb75c8);
  }
  iVar1 = FUN_00714550("Table/MixFilter.txt");
  if (iVar1 != 0) {
    FUN_0081e800(&DAT_00fb75d8);
  }
  iVar1 = FUN_00714550("Table/StrictFilter.txt");
  if (iVar1 != 0) {
    FUN_0081e800(&DAT_00fb75e8);
  }
  iVar1 = FUN_00714550("Table/PoliticFilter.txt");
  if (iVar1 != 0) {
    FUN_0081e800(&DAT_00fb75f8);
  }
  return;
}

