
ios_base * FUN_00783810(byte param_1)

{
  ios_base *piVar1;
  uint uVar2;
  ios_base *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00918f9b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = in_ECX + -0x60;
  *(undefined ***)(in_ECX + *(int *)(*(int *)piVar1 + 4) + -0x60) =
       std::basic_ofstream<char,std::char_traits<char>_>::vftable;
  local_8 = 0;
  FUN_00782e40(uVar2);
  local_8 = 0xffffffff;
  *(undefined ***)(in_ECX + *(int *)(*(int *)(in_ECX + -0x60) + 4) + -0x60) =
       std::basic_ostream<char,std::char_traits<char>_>::vftable;
  *(undefined ***)in_ECX = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c(piVar1);
  }
  ExceptionList = local_10;
  return piVar1;
}

