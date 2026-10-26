
void FUN_0080cb50(void)

{
  undefined4 in_EAX;
  undefined4 in_ECX;
  undefined4 *unaff_ESI;
  
  unaff_ESI[2] = in_ECX;
  unaff_ESI[1] = in_EAX;
  *unaff_ESI = MoonSound::SoundChannel::vftable;
  unaff_ESI[3] = 1;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 1;
  unaff_ESI[9] = 0;
  *(int *)(unaff_ESI[1] + 0x38) = *(int *)(unaff_ESI[1] + 0x38) + 1;
  (**(code **)(*(int *)unaff_ESI[2] + 4))();
  return;
}

