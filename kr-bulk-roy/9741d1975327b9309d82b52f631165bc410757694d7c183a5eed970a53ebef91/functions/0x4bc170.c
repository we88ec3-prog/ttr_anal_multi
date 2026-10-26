
void FUN_004bc170(void)

{
  undefined4 *in_EAX;
  
  FUN_004b9e30();
  *in_EAX = Scene::CMissionDecision::vftable;
  in_EAX[0x2fea] = 0;
  in_EAX[0x2feb] = 0;
  in_EAX[0x2fec] = 0;
  in_EAX[0x2fed] = 0;
  in_EAX[0x2fee] = 0;
  in_EAX[0x2fef] = 0;
  *(undefined2 *)(in_EAX + 0x2ff0) = 0;
  DAT_00d6a674 = 0x4d495344;
  _memset(in_EAX + 0x1840,0,0x5ea8);
  in_EAX[0x18ae] = FUN_004bc460;
  in_EAX[0x18af] = &DAT_00bf2375;
  return;
}

