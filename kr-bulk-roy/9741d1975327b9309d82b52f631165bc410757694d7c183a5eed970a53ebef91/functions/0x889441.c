
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_get<unsigned short,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_get(class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::istreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,int &,bool &)const 
    protected: virtual class std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_get(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,int &,bool &)const 
   
   Library: Visual Studio 2010 Release */

void do_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,int param_6,uint *param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined1 *local_68;
  undefined1 local_64 [4];
  int local_60;
  uint *local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_34 [4];
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uVar2 = param_8;
  iVar1 = param_6;
  uStack_4 = 0x60;
  local_8 = 0x88944d;
  local_54 = 0xffffffff;
  local_5c = param_7;
  if ((*(uint *)(param_6 + 0x14) & 0x4000) == 0) {
    local_60 = 0;
    uVar4 = FUN_004318d0(local_64);
    local_8 = 4;
    uVar4 = Getifld(local_58,local_34,&param_2,&param_4,*(undefined4 *)(iVar1 + 0x14),uVar4,
                    &local_60);
    uVar6 = __Stoulx(local_34,&local_68,uVar4);
    local_8 = 0xffffffff;
    FUN_004327c0();
    if (((local_68 != local_34) && (local_60 == 0)) && (uVar6 < 2)) {
      local_54 = uVar6;
    }
  }
  else {
    uVar4 = FUN_004318d0(&local_58);
    local_8 = 0;
    local_54 = use_facet<>(uVar4);
    local_8 = 0xffffffff;
    FUN_004327c0();
    local_3c = 7;
    local_40 = 0;
    local_50 = (undefined4 *)((uint)local_50._2_2_ << 0x10);
    FID_conflict_assign(1,0);
    local_8 = 1;
    uVar4 = curr_symbol(local_30);
    local_8._0_1_ = 2;
    FID_conflict_append(uVar4,0,0xffffffff);
    local_8._0_1_ = 1;
    FID_conflict__Tidy(1,0);
    FID_conflict_append(1,0);
    uVar4 = positive_sign(local_30);
    local_8._0_1_ = 3;
    FID_conflict_append(uVar4,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,1);
    FID_conflict__Tidy(1,0);
    puVar5 = local_50;
    if (local_3c < 8) {
      puVar5 = &local_50;
    }
    local_54 = _Getloctxt<>(&param_2,&param_4,2,puVar5);
    local_8 = 0xffffffff;
    FID_conflict__Tidy(1,0);
  }
  cVar3 = equal(&param_4);
  if (cVar3 != '\0') {
    *local_5c = *local_5c | 1;
  }
  if ((int)local_54 < 0) {
    *local_5c = *local_5c | 2;
  }
  else {
    *(bool *)uVar2 = local_54 != 0;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_0089dbbc();
  return;
}

