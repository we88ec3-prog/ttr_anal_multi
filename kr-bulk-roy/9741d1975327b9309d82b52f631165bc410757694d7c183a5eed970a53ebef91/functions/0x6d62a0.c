
void FUN_006d62a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CLoginModule::vftable;
  if (0xf < (uint)in_ECX[8]) {
    FUN_0089120c(in_ECX[3]);
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

