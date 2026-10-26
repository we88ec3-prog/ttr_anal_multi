
/* Library Function - Single Match
    private: void __thiscall std::istreambuf_iterator<char,struct std::char_traits<char>
   >::_Inc(void)
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
          (istreambuf_iterator<char,std::char_traits<char>_> *this)

{
  int iVar1;
  
  if (*(int *)this != 0) {
    iVar1 = FUN_006de660();
    if (iVar1 != -1) {
      this[4] = (istreambuf_iterator<char,std::char_traits<char>_>)0x0;
      return;
    }
  }
  *(undefined4 *)this = 0;
  this[4] = (istreambuf_iterator<char,std::char_traits<char>_>)0x1;
  return;
}

