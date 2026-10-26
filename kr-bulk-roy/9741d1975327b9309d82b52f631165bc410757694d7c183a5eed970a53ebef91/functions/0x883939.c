
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: class std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short>
   > __thiscall std::time_get<unsigned short,class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >::_Getfmt(class std::istreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> >,class std::istreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> >,class std::ios_base &,int &,struct tm *,char
   const *)const 
    protected: class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > __thiscall
   std::time_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   >::_Getfmt(class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >,class
   std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >,class std::ios_base &,int
   &,struct tm *,char const *)const 
   
   Library: Visual Studio 2010 Release */

void Getfmt(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,uint *param_7,undefined4 param_8,char *param_9)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *in_ECX;
  char *pcVar7;
  undefined1 local_20 [8];
  int *local_18;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x883945;
  uVar5 = FUN_004318d0(local_14);
  local_8 = 0;
  local_18 = (int *)use_facet<>(uVar5);
  local_8 = 0xffffffff;
  FUN_004327c0();
  pcVar7 = param_9;
  do {
    cVar3 = *pcVar7;
    if (cVar3 == '\0') {
LAB_00883a3e:
      puVar1 = param_7;
      cVar3 = equal(&param_4);
      if (cVar3 != '\0') {
        *puVar1 = *puVar1 | 1;
      }
      *param_1 = param_2;
      param_1[1] = CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3));
      return;
    }
    if (cVar3 == '%') {
      pcVar7 = pcVar7 + 1;
      puVar6 = (undefined4 *)
               (**(code **)(*in_ECX + 0x1c))
                         (local_20,param_2,
                          CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),
                          CONCAT22(param_4._2_2_,(undefined2)param_4),param_5,param_6,param_7,
                          param_8,*pcVar7,0);
      param_2 = *puVar6;
      uVar5 = puVar6[1];
      param_3._0_1_ = (char)uVar5;
      param_3._1_1_ = (undefined1)((uint)uVar5 >> 8);
      param_3._2_2_ = (short)((uint)uVar5 >> 0x10);
    }
    else if (cVar3 == ' ') {
      cVar3 = equal(&param_4);
      piVar2 = local_18;
      while (cVar3 == '\0') {
        if ((char)param_3 == '\0') {
          Peek();
        }
        cVar3 = (**(code **)(*piVar2 + 8))(0x48,CONCAT22((undefined2)param_4,param_3._2_2_));
        if (cVar3 == '\0') break;
        Inc();
        cVar3 = equal(&param_4);
      }
    }
    else {
      if ((char)param_3 == '\0') {
        Peek();
      }
      sVar4 = _Maklocchr<>(*pcVar7,0,in_ECX + 5);
      if (param_3._2_2_ != sVar4) {
        *param_7 = *param_7 | 2;
        goto LAB_00883a3e;
      }
      Inc();
    }
    pcVar7 = pcVar7 + 1;
  } while( true );
}

