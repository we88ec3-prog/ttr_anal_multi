
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::time_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   >::do_get_time(class std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned
   short> >,class std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short>
   >,class std::ios_base &,int &,struct tm *)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::time_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get_time(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,struct tm *)const 
   
   Library: Visual Studio 2010 Release */

void do_get_time(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  int in_ECX;
  uint *in_stack_0000001c;
  
  sVar1 = _Maklocchr<>(0x3a,0,in_ECX + 0x14);
  uVar2 = Getint();
  *in_stack_0000001c = *in_stack_0000001c | uVar2;
  if (*in_stack_0000001c == 0) {
    if ((char)param_3 == '\0') {
      Peek();
    }
    if (param_3._2_2_ != sVar1) goto LAB_008847b1;
    Inc();
    uVar2 = Getint();
    *in_stack_0000001c = *in_stack_0000001c | uVar2;
  }
  else {
LAB_008847b1:
    *in_stack_0000001c = *in_stack_0000001c | 2;
  }
  if (*in_stack_0000001c == 0) {
    if ((char)param_3 == '\0') {
      Peek();
    }
    if (param_3._2_2_ == sVar1) {
      Inc();
      uVar2 = Getint();
      *in_stack_0000001c = *in_stack_0000001c | uVar2;
      goto LAB_008847f6;
    }
  }
  *in_stack_0000001c = *in_stack_0000001c | 2;
LAB_008847f6:
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

