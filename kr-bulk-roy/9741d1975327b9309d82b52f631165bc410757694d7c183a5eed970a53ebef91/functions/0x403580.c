
void FUN_00403580(void)

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
  in_ECX[0x92] = 0xffffffff;
  in_ECX[0x93] = 0xffffffff;
  in_ECX[0x96] = 0xffffffff;
  *(undefined1 *)(in_ECX + 0x56) = 1;
  *in_ECX = FUI::CAttendanceEventSlot::vftable;
  in_ECX[0x94] = 0;
  in_ECX[0x95] = 0;
  in_ECX[0x97] = 0;
  in_ECX[0x98] = 0;
  in_ECX[0x99] = 0;
  in_ECX[0x9f] = 7;
  in_ECX[0x9e] = 0;
  *(undefined2 *)(in_ECX + 0x9a) = 0;
  ExceptionList = local_10;
  return;
}

