
/* WARNING: Removing unreachable block (ram,0x0088ebfb) */
/* WARNING: Removing unreachable block (ram,0x0088ebef) */
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::time_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get_year(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,struct
   tm *)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get_year
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint *in_stack_0000001c;
  int in_stack_00000020;
  
  uVar1 = _Getint(this,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                  (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                  (int)&stack0x00000010,0,(int *)0x7f3);
  *in_stack_0000001c = *in_stack_0000001c | uVar1;
  if ((*in_stack_0000001c & 2) == 0) {
    *(undefined4 *)(in_stack_00000020 + 0x14) = 0;
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  return;
}

