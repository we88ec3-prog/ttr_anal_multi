
void FUN_00694de0(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919c68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00754880(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *in_ECX = FoxUI::FXUIContentButton::vftable;
  FUN_0077b520(in_ECX + 0x57);
  *(undefined1 *)(in_ECX + 0x56) = 1;
  *in_ECX = FUI::CUnionPartyListItem::vftable;
  in_ECX[0x94] = 0;
  in_ECX[0x95] = 0;
  in_ECX[0x96] = 0;
  in_ECX[0x97] = 0;
  in_ECX[0x98] = 0;
  in_ECX[0x99] = 0;
  in_ECX[0x9a] = 0;
  in_ECX[0x9b] = 0;
  in_ECX[0x9c] = 0;
  in_ECX[0x9d] = 0;
  in_ECX[0xa3] = 7;
  in_ECX[0xa2] = 0;
  *(undefined2 *)(in_ECX + 0x9e) = 0;
  *(undefined2 *)(in_ECX + 0xa5) = 0;
  in_ECX[0xa6] = 0;
  ExceptionList = local_10;
  return;
}

