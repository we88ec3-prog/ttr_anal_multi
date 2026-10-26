
/* Library Function - Single Match
    public: static class std::_Locinfo & __cdecl std::_Locinfo::_Locinfo_Addcats(class std::_Locinfo
   *,int,char const *)
   
   Library: Visual Studio 2010 Release */

_Locinfo * __cdecl std::_Locinfo::_Locinfo_Addcats(_Locinfo *param_1,int param_2,char *param_3)

{
  _Locinfo *_Str1;
  int iVar1;
  char *pcVar2;
  undefined **local_10 [3];
  
  pcVar2 = param_3;
  if (param_3 == (char *)0x0) {
    param_3 = "bad locale name";
    exception::exception((exception *)local_10,&param_3);
    local_10[0] = runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_10,&DAT_00c857e0);
  }
  if ((*param_3 != '*') || (param_3[1] != '\0')) {
    if (param_2 == 0) {
      pcVar2 = (char *)0x0;
    }
    else if (param_2 != 0x3f) {
      iVar1 = 0;
      do {
        if ((param_2 & (1 << ((byte)iVar1 & 0x1f)) >> 1) != 0) {
          _setlocale(iVar1,pcVar2);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 6);
    }
    param_3 = _setlocale(0,pcVar2);
    if (param_3 != (char *)0x0) {
      _Str1 = *(_Locinfo **)(param_1 + 0x1c);
      if (_Str1 == (_Locinfo *)0x0) {
        _Str1 = param_1 + 0x20;
      }
      iVar1 = _strcmp((char *)_Str1,"*");
      pcVar2 = param_3;
      if (iVar1 == 0) {
        return param_1;
      }
      goto LAB_0087ea08;
    }
  }
  pcVar2 = "*";
LAB_0087ea08:
  FUN_00433ba0(pcVar2);
  return param_1;
}

