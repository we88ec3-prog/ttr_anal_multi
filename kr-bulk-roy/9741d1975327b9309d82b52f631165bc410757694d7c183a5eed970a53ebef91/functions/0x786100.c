
void FUN_00786100(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbTrack<gbVec3<float>_>::vftable;
  in_ECX[2] = gbORT::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

