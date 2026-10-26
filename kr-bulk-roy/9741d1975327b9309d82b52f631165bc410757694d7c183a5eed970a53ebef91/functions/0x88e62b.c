
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    class std::time_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> > >
   const & __cdecl std::use_facet<class std::time_get<char,class
   std::istreambuf_iterator<char,struct std::char_traits<char> > > >(class std::locale const &)
   
   Library: Visual Studio 2010 Release */

time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> * __cdecl
std::use_facet<std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>_>
          (locale *param_1)

{
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *ptVar1;
  uint uVar2;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *ptVar3;
  int iVar4;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x88e637;
  _Lockit::_Lockit(local_18,0);
  ptVar1 = DAT_00f8ca8c;
  local_8 = 0;
  local_14[0] = DAT_00f8ca8c;
  uVar2 = locale::id::operator_unsigned_int((id *)&DAT_00f8ca94);
  ptVar3 = (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)
           FUN_004311c0(uVar2);
  if ((ptVar3 == (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)0x0) &&
     (ptVar3 = ptVar1,
     ptVar1 == (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)0x0)) {
    iVar4 = ::Getcat(local_14,param_1);
    ptVar3 = local_14[0];
    if (iVar4 == -1) {
      bad_cast::bad_cast(local_24,"bad cast");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c85874);
    }
    DAT_00f8ca8c = local_14[0];
    FUN_00431db0();
    locale::facet::_Facet_Register((facet *)ptVar3);
  }
  local_8 = 0xffffffff;
  FUN_0087dd6f();
  return ptVar3;
}

