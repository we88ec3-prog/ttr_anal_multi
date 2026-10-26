
/* Library Function - Single Match
    _localeconv
   
   Library: Visual Studio 2010 Release */

lconv * __cdecl _localeconv(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if ((p_Var1->ptlocinfo != (pthreadlocinfo)PTR_DAT_00d62878) &&
     ((p_Var1->_ownlocale & DAT_00d62630) == 0)) {
    ___updatetlocinfo();
  }
  return (lconv *)PTR_PTR_00d61ae8;
}

