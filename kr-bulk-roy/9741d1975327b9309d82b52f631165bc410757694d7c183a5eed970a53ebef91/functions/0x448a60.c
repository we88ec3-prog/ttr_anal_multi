
void FUN_00448a60(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = FUI::CChallengeUITabInside::vftable;
  if (unaff_ESI[0x46] != 0) {
    FUN_0089120c(unaff_ESI[0x46]);
  }
  unaff_ESI[0x46] = 0;
  unaff_ESI[0x47] = 0;
  unaff_ESI[0x48] = 0;
  if (unaff_ESI[0x42] != 0) {
    FUN_0089120c(unaff_ESI[0x42]);
  }
  unaff_ESI[0x42] = 0;
  unaff_ESI[0x43] = 0;
  unaff_ESI[0x44] = 0;
  *unaff_ESI = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  return;
}

