
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::money_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,bool,class
   std::ios_base &,unsigned short,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const &)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::money_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,bool,class std::ios_base &,wchar_t,class
   std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class std::allocator<wchar_t> > const
   &)const 
   
   Library: Visual Studio 2010 Release */

void do_put(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,ushort *param_7)

{
  ushort uVar1;
  ushort uVar2;
  int in_ECX;
  uint uVar3;
  undefined1 auStack_70 [12];
  undefined4 uStack_64;
  undefined4 uStack_60;
  ushort *puStack_5c;
  uint uStack_58;
  undefined1 *local_44;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x88cc6f;
  local_34 = param_1;
  puStack_5c = (ushort *)0x0;
  uStack_60 = 0x30;
  local_3c = param_5;
  uStack_64 = 0x88cc90;
  uStack_58 = in_ECX + 8;
  uVar1 = _Maklocchr<>();
  if (7 < *(uint *)(param_7 + 10)) {
    param_7 = *(ushort **)param_7;
  }
  uVar3 = 0;
  puStack_5c = (ushort *)0x0;
  uStack_60 = 0x2d;
  local_38 = local_38 & 0xffffff00;
  uStack_64 = 0x88ccad;
  uStack_58 = in_ECX + 8;
  uVar2 = _Maklocchr<>();
  if (*param_7 == uVar2) {
    local_38 = CONCAT31(local_38._1_3_,1);
    param_7 = param_7 + 1;
  }
  uVar2 = *param_7;
  if (uVar1 <= uVar2) {
    do {
      if (uVar1 + 9 < (uint)uVar2) break;
      uVar3 = uVar3 + 1;
      uVar2 = param_7[uVar3];
    } while (uVar1 <= uVar2);
  }
  uStack_60 = 0x88cce2;
  puStack_5c = param_7;
  uStack_58 = uVar3;
  basic_string<>();
  local_8 = 0;
  if (uVar3 == 0) {
    puStack_5c = (ushort *)0x1;
    uStack_60 = 0x88ccf5;
    uStack_58 = (uint)uVar1;
    FID_conflict_append();
  }
  local_44 = auStack_70;
  basic_string<>(local_30);
  Putmfld(local_34,param_2,param_3,param_4,local_3c,param_6,local_38);
  uStack_58 = 0;
  puStack_5c = (ushort *)0x1;
  uStack_60 = 0x88cd2f;
  FID_conflict__Tidy();
  uStack_58 = 0x88cd37;
  FUN_0089dbbc();
  return;
}

