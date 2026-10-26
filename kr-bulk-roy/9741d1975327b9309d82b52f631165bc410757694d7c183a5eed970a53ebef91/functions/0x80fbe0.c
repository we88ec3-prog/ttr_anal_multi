
undefined4 FUN_0080fbe0(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = MoonSound::COpenALDriver::vftable;
    DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 10));
    FUN_007b6d70();
    FUN_0089120c(in_ECX[4]);
    in_ECX[4] = 0;
    FUN_0089120c();
  }
  return 0;
}

