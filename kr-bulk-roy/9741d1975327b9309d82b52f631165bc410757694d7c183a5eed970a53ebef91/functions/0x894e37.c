
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setlocale
   
   Library: Visual Studio 2010 Release */

char * __cdecl _setlocale(int _Category,char *_Locale)

{
  int *piVar1;
  _ptiddata p_Var2;
  void *pvVar3;
  int iVar4;
  char *local_24;
  
  local_24 = (char *)0x0;
  if ((uint)_Category < 6) {
    p_Var2 = __getptd();
    ___updatetlocinfo();
    p_Var2->_ownlocale = p_Var2->_ownlocale | 0x10;
    pvVar3 = __calloc_crt(0xd8,1);
    if (pvVar3 != (void *)0x0) {
      __lock(0xc);
      __copytlocinfo_nolock();
      FUN_00894f69();
      local_24 = (char *)__setlocale_nolock(_Locale);
      if (local_24 == (char *)0x0) {
        ___removelocaleref(pvVar3);
        ___freetlocinfo(pvVar3);
      }
      else {
        if (_Locale != (char *)0x0) {
          iVar4 = _strcmp(_Locale,&DAT_00d62634);
          if (iVar4 != 0) {
            DAT_00f8cb10 = 1;
          }
        }
        __lock(0xc);
        __updatetlocinfoEx_nolock(&p_Var2->ptlocinfo,pvVar3);
        ___removelocaleref(pvVar3);
        if (((p_Var2->_ownlocale & 2) == 0) && (((byte)DAT_00d62630 & 1) == 0)) {
          __updatetlocinfoEx_nolock(&PTR_DAT_00d62878,p_Var2->ptlocinfo);
          PTR_PTR_00d61ae8 = *(undefined **)(PTR_DAT_00d62878 + 0xbc);
          PTR_DAT_00d61f28 = *(undefined **)(PTR_DAT_00d62878 + 200);
          _DAT_00d629d0 = *(undefined4 *)(PTR_DAT_00d62878 + 0xac);
        }
        FUN_00894f75();
      }
    }
    FUN_00894fa6();
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    local_24 = (char *)0x0;
  }
  return local_24;
}

