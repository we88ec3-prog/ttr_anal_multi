
void FUN_004c54e0(void)

{
  undefined4 *in_EAX;
  
  FUN_004add50();
  *in_EAX = Scene::CRaidField::vftable;
  in_EAX[0x2f55] = 0;
  in_EAX[0x2f56] = 0x41200000;
  DAT_00d6a674 = 0x52414946;
  FUN_004c5520();
  return;
}

