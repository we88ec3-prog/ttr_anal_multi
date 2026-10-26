
/* Library Function - Single Match
    private: char __thiscall std::istreambuf_iterator<char,struct std::char_traits<char>
   >::_Peek(void)const 
   
   Library: Visual Studio 2010 Release */

char __thiscall
std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
          (istreambuf_iterator<char,std::char_traits<char>_> *this)

{
  int iVar1;
  
  if (*(int *)this != 0) {
    iVar1 = FUN_006de6b0();
    if (iVar1 != -1) {
      this[5] = SUB41(iVar1,0);
      goto LAB_0087e912;
    }
  }
  *(undefined4 *)this = 0;
LAB_0087e912:
  this[4] = (istreambuf_iterator<char,std::char_traits<char>_>)0x1;
  return (char)this[5];
}

