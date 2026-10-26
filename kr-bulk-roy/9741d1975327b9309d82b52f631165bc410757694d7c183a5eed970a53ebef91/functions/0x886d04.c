
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::time_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_get(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,int &,struct tm *,char,char)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::time_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,struct tm *,char,char)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,uint *param_7,int param_8,undefined1 param_9)

{
  uint *puVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int *in_ECX;
  char *pcVar7;
  undefined1 local_58 [8];
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  puVar1 = param_7;
  local_8 = 0;
  switch(param_9) {
  case 0x41:
  case 0x61:
    (**(code **)(*in_ECX + 0x10))(&local_10,param_2,param_3,param_4,param_5,param_6,param_7,param_8)
    ;
    param_2 = local_10;
    param_3 = local_c;
    goto LAB_00886f6b;
  case 0x42:
  case 0x62:
  case 0x68:
    (**(code **)(*in_ECX + 0x14))(&local_18,param_2,param_3,param_4,param_5,param_6,param_7,param_8)
    ;
    param_2 = local_18;
    param_3 = local_14;
    goto LAB_00886f6b;
  case 0x43:
    uVar5 = Getint();
    *puVar1 = *puVar1 | uVar5;
    if ((*puVar1 & 2) != 0) goto LAB_00886f6b;
    iVar6 = (local_8 + -0x13) * 100;
    goto LAB_00886ddf;
  case 0x44:
    pcVar7 = "%m / %d / %y";
    puVar3 = local_30;
    goto LAB_00886d90;
  default:
    goto switchD_00886d2d_caseD_45;
  case 0x48:
    break;
  case 0x49:
    break;
  case 0x4d:
    break;
  case 0x52:
    pcVar7 = "%H : %M";
    puVar3 = local_48;
    goto LAB_00886d90;
  case 0x53:
    break;
  case 0x54:
  case 0x58:
    pcVar7 = "%H : %M : S";
    puVar3 = local_50;
    goto LAB_00886d90;
  case 0x55:
  case 0x57:
    break;
  case 0x59:
    (**(code **)(*in_ECX + 0x18))(&local_20,param_2,param_3,param_4,param_5,param_6,param_7,param_8)
    ;
    param_2 = local_20;
    param_3 = local_1c;
    goto LAB_00886f6b;
  case 99:
    pcVar7 = "%b %d %H : %M : %S %Y";
    puVar3 = local_28;
    goto LAB_00886d90;
  case 100:
  case 0x65:
    break;
  case 0x6a:
    break;
  case 0x6d:
    uVar5 = Getint();
    *puVar1 = *puVar1 | uVar5;
    if ((*puVar1 & 2) == 0) {
      *(int *)(param_8 + 0x10) = local_8 + -1;
    }
    goto LAB_00886f6b;
  case 0x6e:
  case 0x74:
    pcVar7 = " ";
    puVar3 = local_38;
    goto LAB_00886d90;
  case 0x70:
    iVar6 = _Getloctxt<>(&param_2,&param_4,0,":AM:am:PM:pm");
    if (-1 < iVar6) {
      *(int *)(param_8 + 8) = *(int *)(param_8 + 8) + iVar6 * 0xc;
      goto LAB_00886f6b;
    }
    goto switchD_00886d2d_caseD_45;
  case 0x72:
    pcVar7 = "%I : %M : %S %p";
    puVar3 = local_40;
    goto LAB_00886d90;
  case 0x77:
    break;
  case 0x78:
    pcVar7 = "%d / %m / %y";
    puVar3 = local_58;
LAB_00886d90:
    puVar4 = (undefined4 *)
             Getfmt(puVar3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,pcVar7);
    param_2 = *puVar4;
    param_3 = puVar4[1];
    goto LAB_00886f6b;
  case 0x79:
    uVar5 = Getint();
    *puVar1 = *puVar1 | uVar5;
    if ((*puVar1 & 2) != 0) goto LAB_00886f6b;
    iVar6 = local_8;
    if (local_8 < 0x45) {
      iVar6 = local_8 + 100;
    }
LAB_00886ddf:
    *(int *)(param_8 + 0x14) = iVar6;
    goto LAB_00886f6b;
  }
  uVar5 = Getint();
  *puVar1 = *puVar1 | uVar5;
LAB_00886f6b:
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
switchD_00886d2d_caseD_45:
  *puVar1 = *puVar1 | 2;
  goto LAB_00886f6b;
}

