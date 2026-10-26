
/* Library Function - Single Match
    public: bool __thiscall std::istreambuf_iterator<char,struct std::char_traits<char>
   >::equal(class std::istreambuf_iterator<char,struct std::char_traits<char> > const &)const 
   
   Library: Visual Studio 2010 Release */

bool __thiscall
std::istreambuf_iterator<char,std::char_traits<char>_>::equal
          (istreambuf_iterator<char,std::char_traits<char>_> *this,
          istreambuf_iterator<char,struct_std::char_traits<char>_> *param_1)

{
  if (this[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
    _Peek(this);
  }
  if (param_1[4] == (istreambuf_iterator<char,struct_std::char_traits<char>_>)0x0) {
    _Peek((istreambuf_iterator<char,std::char_traits<char>_> *)param_1);
  }
  if (*(int *)this == 0) {
    if (*(int *)param_1 == 0) {
      return true;
    }
  }
  else if (*(int *)param_1 != 0) {
    return true;
  }
  return false;
}

