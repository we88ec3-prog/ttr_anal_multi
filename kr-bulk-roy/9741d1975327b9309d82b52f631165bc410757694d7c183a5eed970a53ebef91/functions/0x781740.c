
ios_base * FUN_00781740(byte param_1)

{
  uint uVar1;
  ios_base *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009152eb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)(in_ECX + *(int *)(*(int *)(in_ECX + -0x68) + 4) + -0x68) =
       std::istrstream::vftable;
  local_8 = 0;
  FUN_007810a0(uVar1);
  local_8 = 0xffffffff;
  *(undefined ***)(in_ECX + *(int *)(*(int *)(in_ECX + -0x68) + 4) + -0x68) =
       std::basic_istream<char,std::char_traits<char>_>::vftable;
  *(undefined ***)in_ECX = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c(in_ECX + -0x68);
  }
  ExceptionList = local_10;
  return in_ECX + -0x68;
}

