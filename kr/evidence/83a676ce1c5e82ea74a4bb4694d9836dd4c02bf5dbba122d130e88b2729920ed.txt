
void FUN_004c4ac0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_004add50();
  *unaff_ESI = Scene::CTutorial::vftable;
  DAT_00d6a674 = 0x5455544f;
  _memset(unaff_ESI + 0x17ab,0,0x5ea8);
  unaff_ESI[0x1843] = FUN_004c4f20;
  unaff_ESI[0x1844] = &DAT_00bf2375;
  return;
}

