
void FUN_0077e280(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915433;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUICharSetItem::vftable;
  local_8 = 1;
  FUN_00757640(in_ECX + 9);
  if (7 < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2],uVar1);
  }
  in_ECX[7] = 7;
  in_ECX[6] = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  *in_ECX = FoxUI::FXUIArchive::vftable;
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  ExceptionList = local_10;
  return;
}

