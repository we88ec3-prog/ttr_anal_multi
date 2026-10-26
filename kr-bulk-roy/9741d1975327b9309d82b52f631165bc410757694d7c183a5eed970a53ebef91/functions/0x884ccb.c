
/* WARNING: Removing unreachable block (ram,0x00884d15) */
/* WARNING: Removing unreachable block (ram,0x00884d09) */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::time_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   >::do_get_year(class std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned
   short> >,class std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short>
   >,class std::ios_base &,int &,struct tm *)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::time_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get_year(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,struct tm *)const 
   
   Library: Visual Studio 2010 Release */

void do_get_year(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint *in_stack_0000001c;
  int in_stack_00000020;
  
  uVar1 = Getint();
  *in_stack_0000001c = *in_stack_0000001c | uVar1;
  if ((*in_stack_0000001c & 2) == 0) {
    *(undefined4 *)(in_stack_00000020 + 0x14) = 0;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

