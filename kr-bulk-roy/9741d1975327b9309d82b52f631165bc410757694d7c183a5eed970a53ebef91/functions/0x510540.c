
void FUN_00510540(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = CBuffExplainTable::vftable;
  unaff_ESI[1] = CBuffExplainTable::vftable;
  if (unaff_ESI[2] != 0) {
    FUN_00510f60(unaff_ESI[3]);
    FUN_0089120c(unaff_ESI[2]);
  }
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  DAT_00fc0c6c = 0;
  unaff_ESI[1] = IDataTable::vftable;
  *unaff_ESI = CSingleton<CBuffExplainTable>::vftable;
  return;
}

