
/* Library Function - Multiple Matches With Same Base Name
    public: bool __thiscall std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned
   short> >::equal(class std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned
   short> > const &)const 
    public: bool __thiscall std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t>
   >::equal(class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > const &)const 
   
   Library: Visual Studio 2010 Release */

undefined4 equal(int *param_1)

{
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\0') {
    Peek();
  }
  if ((char)param_1[1] == '\0') {
    Peek();
  }
  if (*in_ECX == 0) {
    if (*param_1 == 0) {
      return 1;
    }
  }
  else if (*param_1 != 0) {
    return 1;
  }
  return 0;
}

