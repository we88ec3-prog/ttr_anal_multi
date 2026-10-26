
void FUN_0073b160(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = Graphics::CTextureBase::vftable;
  in_ECX[1] = Graphics::CTextureBase::vftable;
  in_ECX[2] = Graphics::CTextureBase::vftable;
  if (7 < (uint)in_ECX[0xf]) {
    FUN_0089120c(in_ECX[10]);
  }
  in_ECX[0xf] = 7;
  in_ECX[0xe] = 0;
  *(undefined2 *)(in_ECX + 10) = 0;
  in_ECX[1] = ITextureDevice::vftable;
  in_ECX[2] = ITextureDevice::vftable;
  in_ECX[2] = IDXDefaultObject::vftable;
  in_ECX[1] = IDXManagedObject::vftable;
  *in_ECX = IBase::vftable;
  return;
}

