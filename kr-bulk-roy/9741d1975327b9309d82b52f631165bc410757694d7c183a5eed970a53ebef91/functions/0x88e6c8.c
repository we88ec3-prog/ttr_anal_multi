
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::time_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get_time(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,struct
   tm *)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get_time
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this_00;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this_01;
  uint *in_stack_0000001c;
  undefined4 in_stack_00000020;
  
  uVar2 = _Getint(this,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                  (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                  (int)&stack0x00000010,0,(int *)0x17);
  puVar1 = in_stack_0000001c;
  *in_stack_0000001c = *in_stack_0000001c | uVar2;
  if (*in_stack_0000001c == 0) {
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
    if (param_4._1_1_ != ':') goto LAB_0088e731;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    uVar2 = _Getint(this_00,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                    (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                    (int)&stack0x00000010,0,(int *)0x3b);
    *puVar1 = *puVar1 | uVar2;
  }
  else {
LAB_0088e731:
    *puVar1 = *puVar1 | 2;
  }
  if (*puVar1 == 0) {
    if ((char)param_4 == '\0') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
    if (param_4._1_1_ == ':') {
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
      uVar2 = _Getint(this_01,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                      (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                      (int)&stack0x00000010,0,(int *)0x3b);
      *puVar1 = *puVar1 | uVar2;
      goto LAB_0088e771;
    }
  }
  *puVar1 = *puVar1 | 2;
LAB_0088e771:
  *param_2 = param_3;
  param_2[1] = param_4;
  return;
}

