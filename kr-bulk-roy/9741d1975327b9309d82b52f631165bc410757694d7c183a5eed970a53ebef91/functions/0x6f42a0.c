
void FUN_006f42a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CIMM::vftable;
  if ((HMODULE)in_ECX[1] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)in_ECX[1]);
  }
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

