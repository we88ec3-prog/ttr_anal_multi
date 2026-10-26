
void FUN_0072e520(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907f03;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = TiXmlElement::vftable;
  local_8 = 1;
  FUN_0072e5d0(uVar1);
  if (0xf < (uint)in_ECX[0x22]) {
    FUN_0089120c(in_ECX[0x1d]);
  }
  in_ECX[0x22] = 0xf;
  in_ECX[0x21] = 0;
  *(undefined1 *)(in_ECX + 0x1d) = 0;
  if (0xf < (uint)in_ECX[0x1b]) {
    FUN_0089120c(in_ECX[0x16]);
  }
  in_ECX[0x1b] = 0xf;
  in_ECX[0x1a] = 0;
  *(undefined1 *)(in_ECX + 0x16) = 0;
  in_ECX[0x11] = TiXmlBase::vftable;
  local_8 = 0xffffffff;
  FUN_0072e040();
  ExceptionList = local_10;
  return;
}

