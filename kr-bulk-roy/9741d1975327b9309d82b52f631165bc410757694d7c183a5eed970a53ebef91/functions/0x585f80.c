
void FUN_00585f80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CMsgBoxWaitTimer::vftable;
  in_ECX[0x3f] = 0;
  if ((HANDLE)in_ECX[0x40] != (HANDLE)0x0) {
    WaitForSingleObject((HANDLE)in_ECX[0x40],0xffffffff);
  }
  *in_ECX = FoxUI::FXUIWindowSimple::vftable;
  FUN_00756590();
  return;
}

