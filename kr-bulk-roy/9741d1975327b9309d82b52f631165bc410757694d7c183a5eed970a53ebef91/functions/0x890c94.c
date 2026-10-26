
/* Library Function - Single Match
    __Getcoll
   
   Library: Visual Studio 2010 Release */

_Collvec __cdecl __Getcoll(void)

{
  uint uVar1;
  int iVar2;
  wchar_t *pwVar3;
  _Collvec _Var4;
  
  iVar2 = ____lc_handle_func();
  uVar1 = *(uint *)(iVar2 + 4);
  pwVar3 = (wchar_t *)____lc_collate_cp_func();
  _Var4._LocaleName = pwVar3;
  _Var4._Page = uVar1;
  return _Var4;
}

