
void FUN_004c0610(void)

{
  undefined4 *in_EAX;
  
  FUN_004b9e30();
  *in_EAX = Scene::CGvGDuelDecision::vftable;
  DAT_00d6a674 = 0x47445545;
  _memset(in_EAX + 0x1840,0,0x5ea8);
  return;
}

