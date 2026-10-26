
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual __thiscall std::ctype<unsigned short>::~ctype<unsigned short>(void)
    protected: virtual __thiscall std::ctype<wchar_t>::~ctype<wchar_t>(void)
   
   Library: Visual Studio */

void ~ctype<>(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::ctype<unsigned_short>::vftable;
  if (in_ECX[5] != 0) {
    _free((void *)in_ECX[4]);
  }
  *in_ECX = std::locale::facet::vftable;
  return;
}

