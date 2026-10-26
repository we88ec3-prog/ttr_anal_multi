
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,bool)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,bool)const 
   
   Library: Visual Studio 2010 Release */

void do_put(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,ushort param_5,
           char param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *in_ECX;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  int *local_50;
  undefined1 local_4c [28];
  undefined4 local_30;
  uint local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x88c3ba;
  local_58 = (uint)param_5;
  local_54 = param_1;
  if ((*(uint *)(param_4 + 0x14) & 0x4000) == 0) {
    (**(code **)(*in_ECX + 0x1c))(param_1,param_2,param_3,param_4,local_58,param_6);
  }
  else {
    local_50 = in_ECX;
    uVar3 = FUN_004318d0(local_64);
    local_8 = 0;
    local_5c = use_facet<>(uVar3);
    FUN_004327c0();
    local_1c = 7;
    local_20 = 0;
    local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
    local_8 = 1;
    if (param_6 == '\0') {
      uVar3 = curr_symbol(local_4c);
      local_8._0_1_ = 3;
    }
    else {
      uVar3 = positive_sign(local_4c);
      local_8._0_1_ = 2;
    }
    FUN_0088b1fa(uVar3);
    local_8 = CONCAT31(local_8._1_3_,1);
    FID_conflict__Tidy(1,0);
    uVar1 = *(uint *)(param_4 + 0x20);
    if ((*(int *)(param_4 + 0x24) < 0) ||
       (((*(int *)(param_4 + 0x24) < 1 && (uVar1 == 0)) || (uVar1 <= local_20)))) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar1 - local_20;
    }
    if ((*(uint *)(param_4 + 0x14) & 0x1c0) != 0x40) {
      puVar5 = (undefined4 *)Rep(local_50,local_68,param_2,param_3,local_58,iVar4);
      param_2 = *puVar5;
      param_3 = puVar5[1];
      iVar4 = 0;
    }
    puVar5 = local_30;
    if (local_1c < 8) {
      puVar5 = &local_30;
    }
    puVar5 = (undefined4 *)Put(local_50,local_60,param_2,param_3,puVar5,local_20);
    uVar3 = *puVar5;
    uVar2 = puVar5[1];
    *(undefined4 *)(param_4 + 0x20) = 0;
    *(undefined4 *)(param_4 + 0x24) = 0;
    Rep(local_50,local_54,uVar3,uVar2,local_58,iVar4);
    FID_conflict__Tidy(1,0);
  }
  FUN_0089dbbc();
  return;
}

