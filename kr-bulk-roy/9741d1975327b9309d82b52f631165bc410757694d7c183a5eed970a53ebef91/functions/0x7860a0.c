
void FUN_007860a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbLinTrack<gbVec3<float>_>::vftable;
  if (in_ECX[5] != 0) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = gbTrack<gbVec3<float>_>::vftable;
  in_ECX[2] = gbORT::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

