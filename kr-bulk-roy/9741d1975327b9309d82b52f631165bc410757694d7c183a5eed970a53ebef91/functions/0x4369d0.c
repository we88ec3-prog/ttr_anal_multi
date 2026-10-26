
void FUN_004369d0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_004add50();
  *unaff_ESI = Scene::CEternalTowerField::vftable;
  DAT_00d6a674 = 0x45544646;
  _memset(unaff_ESI + 0x17ab,0,0x5ea8);
  unaff_ESI[0x17d4] = &DAT_00bf2375;
  unaff_ESI[0x17c8] = &DAT_00bf2375;
  unaff_ESI[0x17d3] = &LAB_004c5930;
  unaff_ESI[0x17c7] = &LAB_00436c40;
  return;
}

