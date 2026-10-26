
void FUN_00434320(void)

{
  undefined4 *in_EAX;
  
  FUN_004b9e30();
  *in_EAX = Scene::CEternalTowerDecision::vftable;
  DAT_00d6a674 = 0x45545444;
  _memset(in_EAX + 0x1840,0,0x5ea8);
  return;
}

