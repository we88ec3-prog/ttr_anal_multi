
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006f4140(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = Input::CLuaDevice::vftable;
  _DAT_00fba810 = 0;
  FUN_007b6d70();
  FUN_0089120c(in_ECX[1]);
  in_ECX[1] = 0;
  *in_ECX = Input::IInputDevice::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

