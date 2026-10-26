
/* Library Function - Single Match
    public: static void __cdecl std::_Locinfo::_Locinfo_ctor(class std::_Locinfo *,int,char const *)
   
   Library: Visual Studio 2010 Release */

void __cdecl std::_Locinfo::_Locinfo_ctor(_Locinfo *param_1,int param_2,char *param_3)

{
  char *pcVar1;
  
  pcVar1 = _setlocale(0,(char *)0x0);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "";
  }
  FUN_00433ba0(pcVar1);
  _Locinfo_Addcats(param_1,param_2,param_3);
  return;
}

