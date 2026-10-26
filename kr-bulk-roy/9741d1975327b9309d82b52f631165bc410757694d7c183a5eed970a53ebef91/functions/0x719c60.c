
void FUN_00719c60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = MemoryStream::vftable;
  in_ECX[1] = MemoryStream::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

