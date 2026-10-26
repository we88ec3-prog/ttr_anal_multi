
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::money_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>
   > >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,bool,class std::ios_base &,int
   &,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &)const
   
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::money_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_get(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,bool,class
   std::ios_base &,int &,class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > &)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::money_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,bool,class std::ios_base &,int &,class
   std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class std::allocator<wchar_t> >
   &)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,undefined4 param_7,uint *param_8)

{
  uint *puVar1;
  bool bVar2;
  undefined1 local_30 [16];
  int local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_8;
  uStack_4 = 0x20;
  local_8 = 0x89067f;
  FUN_0088f683(local_30,&param_2,&param_4,param_6,param_7);
  local_8 = 0;
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (bVar2) {
    *puVar1 = *puVar1 | 1;
  }
  if (local_20 == 0) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    FUN_00403040(local_30,0,0xffffffff);
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

