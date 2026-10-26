
void FUN_0080fce0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = MoonSound::COpenALSource::vftable;
  if (unaff_ESI[2] != 0) {
    alSourceStop(unaff_ESI[2]);
    alGetError();
    FUN_00810f60(unaff_ESI[2]);
  }
  FUN_0089120c();
  return;
}

