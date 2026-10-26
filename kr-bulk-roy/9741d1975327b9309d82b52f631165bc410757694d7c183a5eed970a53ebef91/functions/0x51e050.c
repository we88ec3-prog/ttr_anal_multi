
void FUN_0051e050(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = ITEM::CPackageProvideProducts::vftable;
  if (in_ECX[2] != 0) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = ITEM::IProductProperty::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

