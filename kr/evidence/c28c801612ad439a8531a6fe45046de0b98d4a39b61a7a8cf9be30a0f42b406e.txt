
void FUN_004be3c0(void)

{
  undefined4 *in_EAX;
  
  FUN_004add50();
  *in_EAX = Scene::CDuelWaitRoom::vftable;
  in_EAX[0x2f55] = 0;
  in_EAX[0x2f56] = 0;
  in_EAX[0x2f57] = 0;
  in_EAX[0x2f58] = 0;
  DAT_00d6a674 = 0x44554557;
  FUN_004be400();
  return;
}

