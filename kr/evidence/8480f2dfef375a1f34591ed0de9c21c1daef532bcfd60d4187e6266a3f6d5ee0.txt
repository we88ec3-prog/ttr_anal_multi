
void FUN_004c46f0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_004add50();
  *unaff_ESI = Scene::CScenarioField::vftable;
  DAT_00d6a674 = 0x53434546;
  _memset(unaff_ESI + 0x17ab,0,0x5ea8);
  unaff_ESI[0x17d4] = &DAT_00bf2375;
  unaff_ESI[0x17c8] = &DAT_00bf2375;
  unaff_ESI[0x17d3] = &LAB_004c5930;
  unaff_ESI[0x17c7] = &LAB_00436c40;
  return;
}

