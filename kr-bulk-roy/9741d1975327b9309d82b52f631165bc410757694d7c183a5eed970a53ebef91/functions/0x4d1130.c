
void FUN_004d1130(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009108e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CEventObject::vftable;
  in_ECX[0x3c] = CEventObject::vftable;
  local_8 = 0;
  if (in_ECX[0x109] != 0) {
    FUN_004c7db0(uVar1);
    in_ECX[0x109] = 0;
  }
  local_8 = 0xffffffff;
  FUN_004c7b90();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

