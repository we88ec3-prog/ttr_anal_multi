
/* Library Function - Multiple Matches With Same Base Name
    private: class std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   __cdecl std::num_put<unsigned short,class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >::_Putc(class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> >,char const *,unsigned int)const 
    private: class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > __cdecl
   std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   >::_Putc(class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >,char const
   *,unsigned int)const 
   
   Library: Visual Studio 2010 Release */

void Putc(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined1 *param_5,
         int param_6)

{
  undefined2 uVar1;
  
  if (param_6 != 0) {
    do {
      uVar1 = _Maklocchr<>(*param_5,0,param_1 + 8);
      FID_conflict_operator_(uVar1);
      param_6 = param_6 + -1;
      param_5 = param_5 + 1;
    } while (param_6 != 0);
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  return;
}

