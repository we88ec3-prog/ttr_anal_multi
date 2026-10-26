
void FUN_00717fc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = BinFile::vftable;
  in_ECX[1] = BinFile::vftable;
  in_ECX[2] = BinFile::vftable;
  in_ECX[3] = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

