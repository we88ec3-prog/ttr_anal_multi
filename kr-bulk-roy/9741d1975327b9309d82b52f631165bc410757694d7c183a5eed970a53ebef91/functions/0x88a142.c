
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   __thiscall std::locale::name(void)const 
   
   Library: Visual Studio 2010 Release */

undefined4 __thiscall std::locale::name(locale *this)

{
  int iVar1;
  undefined4 in_stack_00000004;
  
  iVar1 = *(int *)(*(int *)this + 0x18);
  if (iVar1 == 0) {
    iVar1 = *(int *)this + 0x1c;
  }
  FUN_00402b70(iVar1);
  return in_stack_00000004;
}

