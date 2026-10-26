
/* Library Function - Single Match
    struct _iobuf * __cdecl std::_Xfsopen(char const *,int,int)
   
   Library: Visual Studio 2010 Release */

_iobuf * __cdecl std::_Xfsopen(char *param_1,int param_2,int param_3)

{
  FILE *pFVar1;
  
  pFVar1 = __fsopen(param_1,(&PTR_DAT_00bd2e00)[param_2],param_3);
  return pFVar1;
}

