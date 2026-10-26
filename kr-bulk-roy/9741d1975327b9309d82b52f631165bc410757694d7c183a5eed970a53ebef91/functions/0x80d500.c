
void FUN_0080d500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = MoonSound::Sound::vftable;
  in_ECX[1] = MoonSound::Sound::vftable;
  if (in_ECX[0xe] != 0) {
    FUN_006edb10("Sound::_refCount != 0\n");
  }
  if (0xf < (uint)in_ECX[0xb]) {
    FUN_0089120c(in_ECX[6]);
  }
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  return;
}

