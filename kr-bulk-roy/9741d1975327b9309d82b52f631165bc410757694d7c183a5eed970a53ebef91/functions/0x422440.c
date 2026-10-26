
void FUN_00422440(void)

{
  undefined4 *in_EAX;
  
  FUN_004b9e30();
  *in_EAX = Scene::CDailyDungeonDecision::vftable;
  DAT_00d6a674 = 0x44414444;
  _memset(in_EAX + 0x1840,0,0x5ea8);
  in_EAX[0x18ae] = FUN_004bc460;
  in_EAX[0x18af] = &DAT_00bf2375;
  return;
}

