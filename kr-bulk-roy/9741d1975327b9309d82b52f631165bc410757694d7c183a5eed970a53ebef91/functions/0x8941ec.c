
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __get_current_locale
   
   Library: Visual Studio 2010 Release */

_locale_t __cdecl __get_current_locale(void)

{
  _ptiddata p_Var1;
  _locale_t plVar2;
  int *piVar3;
  
  p_Var1 = __getptd();
  plVar2 = __calloc_crt(8,1);
  if (plVar2 == (_locale_t)0x0) {
    piVar3 = __errno();
    *piVar3 = 0xc;
    plVar2 = (_locale_t)0x0;
  }
  else {
    ___updatetlocinfo();
    ___updatetmbcinfo();
    plVar2->locinfo = p_Var1->ptlocinfo;
    plVar2->mbcinfo = p_Var1->ptmbcinfo;
    __lock(0xc);
    ___addlocaleref(plVar2->locinfo);
    FUN_00894286();
    __lock(0xd);
    InterlockedIncrement(&plVar2->mbcinfo->refcount);
    FUN_00894292();
  }
  return plVar2;
}

