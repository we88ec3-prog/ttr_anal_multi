
/* Library Function - Multiple Matches With Same Base Name
    private: static class std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned
   short> > __cdecl std::money_put<unsigned short,class std::ostreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Put(class std::ostreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> >,class std::_String_const_iterator<unsigned
   short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short> >,unsigned
   int)
    private: static class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __cdecl std::money_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::_String_const_iterator<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >,unsigned int)
   
   Library: Visual Studio 2010 Release */

void Put(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,int param_5)

{
  for (; param_5 != 0; param_5 = param_5 + -1) {
    FID_conflict_operator_(*param_4);
    param_4 = param_4 + 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

