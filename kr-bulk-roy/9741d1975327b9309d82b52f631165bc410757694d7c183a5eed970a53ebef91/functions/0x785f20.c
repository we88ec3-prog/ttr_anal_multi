
void FUN_00785f20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbTrack<gbQuat>::vftable;
  in_ECX[2] = gbORT::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

