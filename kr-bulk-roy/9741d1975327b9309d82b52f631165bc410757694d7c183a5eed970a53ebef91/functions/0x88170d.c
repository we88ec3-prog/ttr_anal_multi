
/* Library Function - Multiple Matches With Different Base Names
    public: class std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   & __thiscall std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short>
   >::operator=(unsigned short)
    public: class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > & __thiscall
   std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >::operator=(wchar_t)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_operator_(undefined4 param_1)

{
  short sVar1;
  undefined1 *in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 0) && (sVar1 = sputc(param_1), sVar1 != -1)) {
    return;
  }
  *in_ECX = 1;
  return;
}

