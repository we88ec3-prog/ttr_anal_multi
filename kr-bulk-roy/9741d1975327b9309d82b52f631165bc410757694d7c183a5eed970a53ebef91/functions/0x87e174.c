
/* Library Function - Single Match
    public: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __thiscall std::_Iostream_error_category::message(int)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall std::_Iostream_error_category::message(_Iostream_error_category *this,int param_1)

{
  int in_stack_00000008;
  char *pcVar1;
  
  if (in_stack_00000008 == 1) {
    pcVar1 = "iostream stream error";
  }
  else {
    pcVar1 = (char *)FUN_00898466();
  }
  FUN_00402b70(pcVar1);
  return param_1;
}

