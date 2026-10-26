
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual __thiscall std::time_put<char,class std::ostreambuf_iterator<char,struct
   std::char_traits<char> > >::~time_put<char,class std::ostreambuf_iterator<char,struct
   std::char_traits<char> > >(void)
    protected: virtual __thiscall std::time_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   >::~time_put<unsigned short,class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >(void)
    protected: virtual __thiscall std::time_put<wchar_t,class
   std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > >::~time_put<wchar_t,class
   std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > >(void)
   
   Library: Visual Studio */

void ~time_put<>(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::vftable;
  _free((void *)in_ECX[2]);
  *in_ECX = std::locale::facet::vftable;
  return;
}

