
void FUN_00422fb0(void)

{
  undefined4 *in_EAX;
  
  FUN_004add50();
  *in_EAX = Scene::CDailyDungeonField::vftable;
  in_EAX[0x2f55] = 0;
  in_EAX[0x2f56] = 0x41200000;
  DAT_00d6a674 = 0x44414446;
  FUN_00422ff0();
  return;
}

