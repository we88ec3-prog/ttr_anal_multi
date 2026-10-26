
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    private: static class std::locale::_Locimp * __cdecl std::locale::_Init(void)
   
   Library: Visual Studio 2010 Release */

_Locimp * __cdecl std::locale::_Init(void)

{
  _Locimp *p_Var1;
  _Locimp *p_Var2;
  _Lockit local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x87e029;
  p_Var2 = (_Locimp *)0x0;
  p_Var1 = DAT_00f8c840;
  if (DAT_00f8c840 == (_Locimp *)0x0) {
    _Lockit::_Lockit(local_14,0);
    local_8 = 0;
    p_Var1 = DAT_00f8c840;
    if (DAT_00f8c840 == (_Locimp *)0x0) {
      p_Var1 = (_Locimp *)FUN_00891268(0x20);
      if (p_Var1 != (_Locimp *)0x0) {
        p_Var2 = (_Locimp *)_Locimp::_Locimp(p_Var1,false);
      }
      _Setgloballocale(p_Var2);
      *(undefined4 *)(p_Var2 + 0x10) = 0x3f;
      FUN_00433ba0(&DAT_00c428d0);
      DAT_00f8c844 = p_Var2;
      FUN_00431db0();
      _DAT_00f8c85c = DAT_00f8c844;
      p_Var1 = p_Var2;
    }
    local_8 = 0xffffffff;
    FUN_0087dd6f();
  }
  return p_Var1;
}

