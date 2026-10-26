
void FUN_004bd590(void)

{
  undefined4 *in_EAX;
  
  FUN_004b9e30();
  *in_EAX = Scene::CDuelDecision::vftable;
  in_EAX[0x2fea] = 0;
  DAT_00d6a674 = 0x44554544;
  _memset(in_EAX + 0x1840,0,0x5ea8);
  return;
}

