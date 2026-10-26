
void FUN_0086c120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbDxEffectScriptCommandsMultiPass::vftable;
  if (in_ECX[0x10] != 0) {
    FUN_0089120c(in_ECX[0x10]);
  }
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  FUN_0086d570();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

