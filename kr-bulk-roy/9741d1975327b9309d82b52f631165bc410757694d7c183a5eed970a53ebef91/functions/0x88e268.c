
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: class std::istreambuf_iterator<char,struct std::char_traits<char> > __thiscall
   std::time_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::_Getfmt(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,struct
   tm *,char const *)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::_Getfmt
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,uint param_4,undefined4 param_5,undefined4 param_6,
          undefined4 param_7,uint *param_8,undefined4 param_9,char *param_10)

{
  char cVar1;
  uint *puVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined1 local_20 [8];
  int local_18;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x88e274;
  uVar4 = FUN_004318d0(local_14);
  local_8 = 0;
  local_18 = FUN_006de510(uVar4);
  local_8 = 0xffffffff;
  FUN_004327c0();
  puVar2 = param_8;
  pcVar6 = param_10;
  do {
    cVar1 = *pcVar6;
    if (cVar1 == '\0') {
LAB_0088e33f:
      bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                        ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                         (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
      if (bVar3) {
        *puVar2 = *puVar2 | 1;
      }
      *param_2 = param_3;
      param_2[1] = param_4;
      return;
    }
    if (cVar1 == '%') {
      pcVar6 = pcVar6 + 1;
      puVar5 = (undefined4 *)
               (**(code **)(*(int *)this + 0x1c))
                         (local_20,param_3,param_4,param_5,param_6,param_7,puVar2,param_9,*pcVar6,0)
      ;
      param_3 = *puVar5;
      param_4 = puVar5[1];
    }
    else if (cVar1 == ' ') {
      while (bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                               ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                                (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5
                               ), !bVar3) {
        if ((char)param_4 == '\0') {
          istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
        }
        if ((*(byte *)(*(int *)(local_18 + 0x10) + (param_4 >> 8 & 0xff) * 2) & 0x48) == 0) break;
        istreambuf_iterator<char,std::char_traits<char>_>::_Inc
                  ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
      }
    }
    else {
      if ((char)param_4 == '\0') {
        istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                  ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
      }
      if (param_4._1_1_ != *pcVar6) {
        *puVar2 = *puVar2 | 2;
        goto LAB_0088e33f;
      }
      istreambuf_iterator<char,std::char_traits<char>_>::_Inc
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3);
    }
    pcVar6 = pcVar6 + 1;
  } while( true );
}

