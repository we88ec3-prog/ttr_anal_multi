
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: __thiscall std::time_get<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >::time_get<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >(class std::_Locinfo const &,unsigned int)
   
   Library: Visual Studio 2010 Release */

time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> * __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::
time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          _Locinfo *param_1,uint param_2)

{
  *(uint *)(this + 4) = param_2;
  *(undefined ***)this = vftable;
  Init(param_1);
  return this;
}

