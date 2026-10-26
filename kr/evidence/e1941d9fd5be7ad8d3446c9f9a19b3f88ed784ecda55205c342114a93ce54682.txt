
void FUN_00544e80(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090af12;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CController::vftable;
  local_8 = 2;
  uStack_7 = 0;
  FUN_005540c0(*(undefined4 *)in_ECX[0x23],(undefined4 *)in_ECX[0x23]);
  FUN_0089120c(in_ECX[0x23],uVar1);
  local_8 = 3;
  FUN_0054f570(in_ECX + 0x12);
  _local_8 = CONCAT31(uStack_7,4);
  FUN_005540c0(*(undefined4 *)in_ECX[0x13],(undefined4 *)in_ECX[0x13]);
  FUN_0089120c(in_ECX[0x13]);
  if (in_ECX[0xc] != 0) {
    FUN_0089120c(in_ECX[0xc]);
  }
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  ExceptionList = local_10;
  return;
}

