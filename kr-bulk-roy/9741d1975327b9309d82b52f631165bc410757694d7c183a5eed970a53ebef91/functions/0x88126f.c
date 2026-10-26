
/* Library Function - Single Match
    protected: virtual int __thiscall std::collate<wchar_t>::do_compare(wchar_t const *,wchar_t
   const *,wchar_t const *,wchar_t const *)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall
std::collate<wchar_t>::do_compare
          (collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,
          wchar_t *param_4)

{
  int iVar1;
  
  iVar1 = __Wcscoll(param_1,param_2,param_3,param_4,(_Collvec *)(this + 8));
  return iVar1;
}

