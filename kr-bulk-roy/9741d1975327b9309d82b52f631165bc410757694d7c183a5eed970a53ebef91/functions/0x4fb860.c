
void FUN_004fb860(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = CShopMgr::vftable;
  unaff_ESI[1] = CShopMgr::vftable;
  if (unaff_ESI[2] != 0) {
    FUN_004fcc10(unaff_ESI[3]);
    FUN_0089120c(unaff_ESI[2]);
  }
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  DAT_00fe1db4 = 0;
  unaff_ESI[1] = IDataTable::vftable;
  *unaff_ESI = CSingleton<CShopMgr>::vftable;
  return;
}

