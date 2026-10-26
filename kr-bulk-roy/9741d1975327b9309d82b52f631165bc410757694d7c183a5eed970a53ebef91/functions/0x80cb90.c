
void FUN_0080cb90(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = MoonSound::SoundChannel::vftable;
  if ((int *)unaff_ESI[2] != (int *)0x0) {
    (**(code **)(*(int *)unaff_ESI[2] + 8))();
    unaff_ESI[2] = 0;
  }
  iVar1 = unaff_ESI[1];
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x38) == 0) {
      FUN_006edb10("Sound::_refCount < 0\n");
      unaff_ESI[1] = 0;
      return;
    }
    *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) + -1;
    unaff_ESI[1] = 0;
  }
  return;
}

