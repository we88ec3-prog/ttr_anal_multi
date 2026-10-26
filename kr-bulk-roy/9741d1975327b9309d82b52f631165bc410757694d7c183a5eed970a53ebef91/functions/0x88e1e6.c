
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    public: static unsigned int __cdecl std::time_get<char,class
   std::istreambuf_iterator<char,struct std::char_traits<char> > >::_Getcat(class std::locale::facet
   const * *,class std::locale const *)
    public: static unsigned int __cdecl std::time_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   >::_Getcat(class std::locale::facet const * *,class std::locale const *)
    public: static unsigned int __cdecl std::time_get<wchar_t,class
   std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > >::_Getcat(class
   std::locale::facet const * *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

undefined4 Getcat(int *param_1,int *param_2)

{
  bool bVar1;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this;
  _Locinfo *p_Var2;
  int iVar3;
  
  bVar1 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    this = (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)
           FUN_00891268(0x1c);
    if (this == (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*param_2 + 0x18);
      if (iVar3 == 0) {
        iVar3 = *param_2 + 0x1c;
      }
      p_Var2 = (_Locinfo *)FUN_00431550(iVar3);
      bVar1 = true;
      iVar3 = std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::
              time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>(this,p_Var2,0);
    }
    *param_1 = iVar3;
    if (bVar1) {
      FUN_00431620();
    }
  }
  return 5;
}

