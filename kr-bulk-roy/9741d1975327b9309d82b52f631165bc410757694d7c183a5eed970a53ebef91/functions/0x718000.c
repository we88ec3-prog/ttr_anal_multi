
void FUN_00718000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = BinFile::vftable;
  in_ECX[1] = BinFile::vftable;
  in_ECX[2] = BinFile::vftable;
  in_ECX[3] = 0;
  return;
}

