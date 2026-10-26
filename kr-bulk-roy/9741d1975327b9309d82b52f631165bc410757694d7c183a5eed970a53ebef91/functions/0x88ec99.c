
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::time_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,struct
   tm *,char,char)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this,
          undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,uint *param_8,int param_9,undefined1 param_10)

{
  uint *puVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
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
  
  puVar1 = param_8;
  local_8 = 0;
  switch(param_10) {
  case 0x41:
  case 0x61:
    (**(code **)(*(int *)this + 0x10))
              (&local_10,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    param_3 = local_10;
    param_4 = local_c;
    goto LAB_0088ef00;
  case 0x42:
  case 0x62:
  case 0x68:
    (**(code **)(*(int *)this + 0x14))
              (&local_18,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    param_3 = local_18;
    param_4 = local_14;
    goto LAB_0088ef00;
  case 0x43:
    uVar5 = _Getint(this,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                    (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,0,
                    (int *)0x63);
    *puVar1 = *puVar1 | uVar5;
    if ((*puVar1 & 2) != 0) goto LAB_0088ef00;
    iVar6 = (local_8 + -0x13) * 100;
    goto LAB_0088ed74;
  case 0x44:
    pcVar8 = "%m / %d / %y";
    puVar3 = local_30;
    break;
  default:
    goto switchD_0088ecc2_caseD_45;
  case 0x48:
    piVar7 = (int *)0x17;
    goto LAB_0088edb8;
  case 0x49:
    piVar7 = (int *)0xb;
    goto LAB_0088edb8;
  case 0x4d:
    goto LAB_0088ee0e;
  case 0x52:
    pcVar8 = "%H : %M";
    puVar3 = local_48;
    break;
  case 0x53:
LAB_0088ee0e:
    piVar7 = (int *)0x3b;
    goto LAB_0088edb8;
  case 0x54:
  case 0x58:
    pcVar8 = "%H : %M : S";
    puVar3 = local_50;
    break;
  case 0x55:
  case 0x57:
    piVar7 = (int *)0x35;
    goto LAB_0088edb8;
  case 0x59:
    (**(code **)(*(int *)this + 0x18))
              (&local_20,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    param_3 = local_20;
    param_4 = local_1c;
    goto LAB_0088ef00;
  case 99:
    pcVar8 = "%b %d %H : %M : %S %Y";
    puVar3 = local_28;
    break;
  case 100:
  case 0x65:
    piVar7 = (int *)0x1f;
    goto LAB_0088ed88;
  case 0x6a:
    piVar7 = (int *)&DAT_0000016e;
LAB_0088ed88:
    iVar6 = 1;
    goto LAB_0088ed8a;
  case 0x6d:
    uVar5 = _Getint(this,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                    (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,1,
                    (int *)0xc);
    *puVar1 = *puVar1 | uVar5;
    if ((*puVar1 & 2) == 0) {
      *(int *)(param_9 + 0x10) = local_8 + -1;
    }
    goto LAB_0088ef00;
  case 0x6e:
  case 0x74:
    pcVar8 = " ";
    puVar3 = local_38;
    break;
  case 0x70:
    iVar6 = _Getloctxt<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>
                      ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                       (istreambuf_iterator<char,std::char_traits<char>_> *)&param_5,0,
                       ":AM:am:PM:pm");
    if (-1 < iVar6) {
      *(int *)(param_9 + 8) = *(int *)(param_9 + 8) + iVar6 * 0xc;
      goto LAB_0088ef00;
    }
    goto switchD_0088ecc2_caseD_45;
  case 0x72:
    pcVar8 = "%I : %M : %S %p";
    puVar3 = local_40;
    break;
  case 0x77:
    piVar7 = (int *)0x6;
LAB_0088edb8:
    iVar6 = 0;
LAB_0088ed8a:
    uVar5 = _Getint(this,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                    (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,
                    iVar6,piVar7);
    *puVar1 = *puVar1 | uVar5;
    goto LAB_0088ef00;
  case 0x78:
    pcVar8 = "%d / %m / %y";
    puVar3 = local_58;
    break;
  case 0x79:
    uVar5 = _Getint(this,(istreambuf_iterator<char,std::char_traits<char>_> *)this,
                    (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,0,
                    (int *)0x63);
    *puVar1 = *puVar1 | uVar5;
    if ((*puVar1 & 2) != 0) goto LAB_0088ef00;
    iVar6 = local_8;
    if (local_8 < 0x45) {
      iVar6 = local_8 + 100;
    }
LAB_0088ed74:
    *(int *)(param_9 + 0x14) = iVar6;
    goto LAB_0088ef00;
  }
  puVar4 = (undefined4 *)
           _Getfmt(this,puVar3,param_3,param_4,param_5,param_6,param_7,param_8,param_9,pcVar8);
  param_3 = *puVar4;
  param_4 = puVar4[1];
LAB_0088ef00:
  bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar2) {
    *puVar1 = *puVar1 | 1;
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  return;
switchD_0088ecc2_caseD_45:
  *puVar1 = *puVar1 | 2;
  goto LAB_0088ef00;
}

