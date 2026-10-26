
void FUN_004bc6a0(void)

{
  undefined4 *in_EAX;
  
  FUN_004add50();
  *in_EAX = Scene::CMissionField::vftable;
  in_EAX[0x2f55] = 0;
  in_EAX[0x2f56] = 0x41200000;
  DAT_00d6a674 = 0x4d495346;
  FUN_004bc6e0();
  return;
}

