
void FUN_00585f00(void)

{
  undefined4 *in_ECX;
  
  FUN_007564e0();
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  *in_ECX = FUI::CMsgBoxWaitTimer::vftable;
  return;
}

