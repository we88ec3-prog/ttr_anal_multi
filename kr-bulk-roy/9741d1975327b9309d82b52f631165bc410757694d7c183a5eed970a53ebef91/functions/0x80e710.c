
void FUN_0080e710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = MoonSound::CStreamDriver::vftable;
  DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 10));
  *in_ECX = MoonSound::IMusicDriver::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

