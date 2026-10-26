
void FUN_005c4490(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091ac56;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CFXUITextureMgr::vftable;
  local_8 = 0x10;
  if ((int *)in_ECX[0x9a] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x9a] + 0x1c))(1,uVar1);
    in_ECX[0x9a] = 0;
  }
  if ((int *)in_ECX[5] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[5] + 0x10))(1);
    in_ECX[5] = 0;
  }
  FUN_005c7230(in_ECX);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  FUN_005540c0(*(undefined4 *)in_ECX[0x11b],(undefined4 *)in_ECX[0x11b]);
  FUN_0089120c(in_ECX[0x11b]);
  if (in_ECX[0x115] != 0) {
    FUN_005c7ba0(in_ECX[0x116],local_1c);
    FUN_0089120c(in_ECX[0x115]);
  }
  in_ECX[0x115] = 0;
  in_ECX[0x116] = 0;
  in_ECX[0x117] = 0;
  local_8._0_1_ = 0xd;
  FUN_007631f0();
  local_8._0_1_ = 0xc;
  FUN_007631f0();
  local_8._0_1_ = 0xb;
  FUN_007631f0();
  local_8._0_1_ = 0x12;
  FUN_005540c0(*(undefined4 *)in_ECX[0x97],(undefined4 *)in_ECX[0x97]);
  FUN_0089120c(in_ECX[0x97]);
  local_8._0_1_ = 0x13;
  FUN_005540c0(*(undefined4 *)in_ECX[0x93],(undefined4 *)in_ECX[0x93]);
  FUN_0089120c(in_ECX[0x93]);
  local_8._0_1_ = 0x14;
  FUN_005540c0(*(undefined4 *)in_ECX[0x8f],(undefined4 *)in_ECX[0x8f]);
  FUN_0089120c(in_ECX[0x8f]);
  local_8._0_1_ = 0x15;
  FUN_005540c0(*(undefined4 *)in_ECX[0x8b],(undefined4 *)in_ECX[0x8b]);
  FUN_0089120c(in_ECX[0x8b]);
  local_8._0_1_ = 0x16;
  FUN_005540c0(*(undefined4 *)in_ECX[0x87],(undefined4 *)in_ECX[0x87]);
  FUN_0089120c(in_ECX[0x87]);
  local_8._0_1_ = 0x17;
  FUN_005540c0(*(undefined4 *)in_ECX[0x83],(undefined4 *)in_ECX[0x83]);
  FUN_0089120c(in_ECX[0x83]);
  local_8._0_1_ = 0x18;
  FUN_005540c0(*(undefined4 *)in_ECX[0x7f],(undefined4 *)in_ECX[0x7f]);
  FUN_0089120c(in_ECX[0x7f]);
  local_8._0_1_ = 0x19;
  FUN_005540c0(*(undefined4 *)in_ECX[0x7b],(undefined4 *)in_ECX[0x7b]);
  FUN_0089120c(in_ECX[0x7b]);
  local_8._0_1_ = 0x1a;
  FUN_005540c0(*(undefined4 *)in_ECX[0x77],(undefined4 *)in_ECX[0x77]);
  FUN_0089120c(in_ECX[0x77]);
  local_8._0_1_ = 1;
  _eh_vector_destructor_iterator_(in_ECX + 0x4a,0x18,4,FUN_00763c90);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_005c80f0();
  local_8 = 0x1b;
  FUN_00737010(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  FUN_0089120c(in_ECX[2]);
  ExceptionList = local_10;
  return;
}

