
void FUN_0080e2b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSound::vftable;
  if (in_ECX[10] != 0) {
    *(undefined4 *)(in_ECX[10] + 0xc) = 1;
  }
  DAT_00fba864 = DAT_00fba864 + -1;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = IBase::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

