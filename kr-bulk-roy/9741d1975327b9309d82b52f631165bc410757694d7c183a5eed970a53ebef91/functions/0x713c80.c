
void FUN_00713c80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = StdFile::vftable;
  if (in_ECX[2] != 0) {
    FUN_00891d3d(in_ECX[2]);
    in_ECX[2] = 0;
  }
  *in_ECX = File::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

