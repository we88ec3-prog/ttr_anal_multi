
/* Library Function - Single Match
    protected: virtual int __thiscall std::collate<char>::do_compare(char const *,char const *,char
   const *,char const *)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall
std::collate<char>::do_compare
          (collate<char> *this,char *param_1,char *param_2,char *param_3,char *param_4)

{
  int iVar1;
  
  iVar1 = __Strcoll(param_1,param_2,param_3,param_4,(_Collvec *)(this + 8));
  return iVar1;
}

