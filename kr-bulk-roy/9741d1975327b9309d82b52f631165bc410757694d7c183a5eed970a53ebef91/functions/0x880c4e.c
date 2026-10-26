
/* Library Function - Multiple Matches With Same Base Name
    protected: void __thiscall std::time_put<unsigned short,class std::ostreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Init(class std::_Locinfo const &)
    protected: void __thiscall std::time_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Init(class std::_Locinfo const &)
   
   Library: Visual Studio 2010 Release */

void Init(_Locinfo *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  _Collvec _Var2;
  
  _Var2 = __Getcoll();
  *(_Collvec *)(in_ECX + 0xc) = _Var2;
  puVar1 = (undefined4 *)std::_Locinfo::_Gettnames(param_1);
  *(undefined4 *)(in_ECX + 8) = *puVar1;
  *puVar1 = 0;
  _free(param_1);
  return;
}

