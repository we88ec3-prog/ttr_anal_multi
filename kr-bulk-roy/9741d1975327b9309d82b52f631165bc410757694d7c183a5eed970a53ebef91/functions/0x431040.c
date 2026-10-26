
void FUN_00431040(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b85b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)(*(int *)(*(int *)(in_ECX + -0x60) + 4) + -0x60 + in_ECX) =
       std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  puVar1 = (undefined4 *)(in_ECX + -0x48);
  local_8 = 0;
  *puVar1 = std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
            vftable;
  FUN_00730a70(uVar2);
  FUN_00432810();
  *(undefined ***)(*(int *)(*(int *)(in_ECX + -0x60) + 4) + -0x18 + (int)puVar1) =
       std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::vftable;
  *(undefined ***)(*(int *)(*(int *)(in_ECX + -0x50) + 4) + -8 + (int)puVar1) =
       std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::vftable;
  *(undefined ***)(*(int *)(*(int *)(in_ECX + -0x60) + 4) + -0x18 + (int)puVar1) =
       std::basic_istream<wchar_t,std::char_traits<wchar_t>_>::vftable;
  ExceptionList = local_10;
  return;
}

