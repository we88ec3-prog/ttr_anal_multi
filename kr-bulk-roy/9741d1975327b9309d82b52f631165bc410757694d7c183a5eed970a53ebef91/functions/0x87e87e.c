
/* Library Function - Single Match
    private: int __cdecl std::num_get<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >::_Hexdig(char,char,char,char)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::_Hexdig
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,char param_1,
          char param_2,char param_3,char param_4)

{
  int iVar1;
  char in_stack_00000014;
  
  if (param_3 <= param_2) {
    if ((int)param_2 <= param_3 + 9) {
      return (int)param_2 - (int)param_3;
    }
  }
  if (((param_2 < param_4) || (iVar1 = (int)param_4, iVar1 + 5 < (int)param_2)) &&
     ((param_2 < in_stack_00000014 || (iVar1 = (int)in_stack_00000014, iVar1 + 5 < (int)param_2))))
  {
    iVar1 = -1;
  }
  else {
    iVar1 = (param_2 - iVar1) + 10;
  }
  return iVar1;
}

