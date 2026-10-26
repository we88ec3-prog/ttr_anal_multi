
void FUN_00508600(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = CSquareUserData::vftable;
  unaff_ESI[1] = CSquareUserData::vftable;
  if (unaff_ESI[2] != 0) {
    FUN_00508b90();
    FUN_0089120c(unaff_ESI[2]);
  }
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  DAT_00fe1aa0 = 0;
  unaff_ESI[1] = IDataTable::vftable;
  *unaff_ESI = CSingleton<CSquareUserData>::vftable;
  return;
}

