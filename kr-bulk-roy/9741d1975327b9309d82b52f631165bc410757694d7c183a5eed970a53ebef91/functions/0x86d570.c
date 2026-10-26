
void FUN_0086d570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbDxEffectScriptCommands::vftable;
  if (0xf < (uint)in_ECX[0xc]) {
    FUN_0089120c(in_ECX[7]);
  }
  in_ECX[0xc] = 0xf;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  if (in_ECX[3] != 0) {
    FUN_00440a80();
    FUN_0089120c(in_ECX[3]);
  }
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  return;
}

