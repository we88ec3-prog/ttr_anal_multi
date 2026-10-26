
/* Library Function - Multiple Matches With Same Base Name
    private: class std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   __cdecl std::num_put<unsigned short,class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >::_Put(class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> >,unsigned short const *,unsigned int)const 
    private: class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > __cdecl
   std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   >::_Put(class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >,wchar_t const
   *,unsigned int)const 
   
   Library: Visual Studio 2010 Release */

void Put(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
        undefined2 *param_5,int param_6)

{
  for (; param_6 != 0; param_6 = param_6 + -1) {
    FID_conflict_operator_(*param_5);
    param_5 = param_5 + 1;
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  return;
}

