
/* Library Function - Single Match
    ____mb_cur_max_l_func
   
   Library: Visual Studio 2010 Release */

int __cdecl ____mb_cur_max_l_func(_locale_t param_1)

{
  int iVar1;
  
  if (param_1 == (_locale_t)0x0) {
    iVar1 = ____mb_cur_max_func();
    return iVar1;
  }
  return (int)param_1->locinfo->locale_name[3];
}

