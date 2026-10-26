
void FUN_0080ed80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = MoonSound::COGGLoader::vftable;
  if (in_ECX[7] != 0) {
    FUN_00891d3d(in_ECX[7]);
    in_ECX[7] = 0;
  }
  *in_ECX = MoonSound::SoundLoader::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

