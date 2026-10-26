
void FUN_0073b020(byte param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = ITextureDevice::vftable;
  in_ECX[2] = ITextureDevice::vftable;
  in_ECX[2] = IDXDefaultObject::vftable;
  in_ECX[1] = IDXManagedObject::vftable;
  *in_ECX = IBase::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

