
/* Library Function - Single Match
    private: static class std::ostreambuf_iterator<char,struct std::char_traits<char> > __cdecl
   std::money_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::_Put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class
   std::_String_const_iterator<char,struct std::char_traits<char>,class std::allocator<char>
   >,unsigned int)
   
   Library: Visual Studio 2010 Release */

void __cdecl
std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::_Put
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4,int param_5
          )

{
  for (; param_5 != 0; param_5 = param_5 + -1) {
    FUN_006efb60(*param_4);
    param_4 = param_4 + 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

