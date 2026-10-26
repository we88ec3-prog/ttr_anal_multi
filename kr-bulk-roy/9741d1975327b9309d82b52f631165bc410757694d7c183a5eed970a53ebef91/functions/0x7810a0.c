
void FUN_007810a0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a488;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = std::strstreambuf::vftable;
  local_8 = 0;
  if (((byte)in_ECX[0x12] & 9) == 1) {
    if ((code *)in_ECX[0x14] == (code *)0x0) {
      FUN_00891d3d(*(undefined4 *)in_ECX[4],uVar1);
    }
    else {
      (*(code *)in_ECX[0x14])(*(undefined4 *)in_ECX[4]);
    }
  }
  in_ECX[0x12] = in_ECX[0x12] & 0xfffffff6;
  in_ECX[0x11] = 0;
  local_8 = 0xffffffff;
  FUN_00730110();
  ExceptionList = local_10;
  return;
}

