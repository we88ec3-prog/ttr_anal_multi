
void FUN_00781b20(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a3fc;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbArchive::vftable;
  local_8 = 5;
  FUN_00781cc0(uVar1);
  if (in_ECX[0x1d] != 0) {
    FUN_0089120c(in_ECX[0x1d]);
  }
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0x641;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  if (in_ECX[0x1c] != 0) {
    FUN_00891d3d(in_ECX[0x1c]);
  }
  in_ECX[0x1c] = 0;
  if (0xf < (uint)in_ECX[0x12]) {
    FUN_0089120c(in_ECX[0xd]);
  }
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0xf;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_00844d40(*(undefined4 *)in_ECX[10],(undefined4 *)in_ECX[10]);
  FUN_0089120c(in_ECX[10]);
  if (in_ECX[5] != 0) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  if (in_ECX[1] != 0) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  ExceptionList = local_10;
  return;
}

