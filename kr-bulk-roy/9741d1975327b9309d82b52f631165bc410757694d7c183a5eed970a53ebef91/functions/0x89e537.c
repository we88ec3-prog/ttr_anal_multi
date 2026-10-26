
/* Library Function - Single Match
    ____lc_collate_cp_func
   
   Library: Visual Studio 2010 Release */

UINT __cdecl ____lc_collate_cp_func(void)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  
  p_Var1 = __getptd();
  ptVar2 = p_Var1->ptlocinfo;
  if ((ptVar2 != (pthreadlocinfo)PTR_DAT_00d62878) && ((p_Var1->_ownlocale & DAT_00d62630) == 0)) {
    ptVar2 = ___updatetlocinfo();
  }
  return ptVar2->lc_collate_cp;
}

