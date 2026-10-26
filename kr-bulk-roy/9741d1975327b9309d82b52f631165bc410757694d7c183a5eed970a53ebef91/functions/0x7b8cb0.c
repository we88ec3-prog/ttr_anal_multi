
void FUN_007b8cb0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938160;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CField::vftable;
  local_8 = 0xc;
  FUN_007b9fe0(uVar2);
  iVar1 = in_ECX[0x15];
  if (iVar1 != 0) {
    FUN_007e0a30(iVar1);
    FUN_0089120c(iVar1);
    in_ECX[0x15] = 0;
  }
  iVar1 = in_ECX[0x1a];
  if (iVar1 != 0) {
    local_8 = CONCAT31(local_8._1_3_,0xd);
    FUN_0057ffd0(**(undefined4 **)(iVar1 + 0xc),*(undefined4 **)(iVar1 + 0xc));
    FUN_0089120c(*(undefined4 *)(iVar1 + 0xc));
    FUN_0089120c(iVar1);
    in_ECX[0x1a] = 0;
  }
  if (0xf < (uint)in_ECX[0x41]) {
    FUN_0089120c(in_ECX[0x3c]);
  }
  in_ECX[0x41] = 0xf;
  in_ECX[0x40] = 0;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_005540c0(*(undefined4 *)in_ECX[0x39],(undefined4 *)in_ECX[0x39]);
  FUN_0089120c(in_ECX[0x39]);
  if (in_ECX[0x32] != 0) {
    FUN_0089120c(in_ECX[0x32]);
  }
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  if (in_ECX[0x2d] != 0) {
    FUN_0089120c(in_ECX[0x2d]);
  }
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  if (in_ECX[0x29] != 0) {
    FUN_0089120c(in_ECX[0x29]);
  }
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  local_8 = CONCAT31(local_8._1_3_,0xf);
  FUN_0057ffd0(*(undefined4 *)in_ECX[0x26],(undefined4 *)in_ECX[0x26]);
  FUN_0089120c(in_ECX[0x26]);
  if (in_ECX[0x1f] != 0) {
    FUN_0089120c(in_ECX[0x1f]);
  }
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  local_8 = CONCAT31(local_8._1_3_,0x10);
  FUN_0057ffd0(*(undefined4 *)in_ECX[0x1c],(undefined4 *)in_ECX[0x1c]);
  FUN_0089120c(in_ECX[0x1c]);
  if (in_ECX[0x16] != 0) {
    FUN_00440a80();
    FUN_0089120c(in_ECX[0x16]);
  }
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  if (in_ECX[0x11] != 0) {
    FUN_0089120c(in_ECX[0x11]);
  }
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  if (0xf < (uint)in_ECX[0xd]) {
    FUN_0089120c(in_ECX[8]);
  }
  in_ECX[0xd] = 0xf;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  if (0xf < (uint)in_ECX[6]) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[6] = 0xf;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  *in_ECX = IS3D::CSteppable::vftable;
  ExceptionList = local_10;
  return;
}

