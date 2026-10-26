
void FUN_00780000(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c648;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbAnimatible::vftable;
  local_8 = 2;
  FUN_00783920(*(undefined4 *)(in_ECX[0xe] + 4));
  *(undefined4 *)(in_ECX[0xe] + 4) = in_ECX[0xe];
  *(undefined4 *)in_ECX[0xe] = in_ECX[0xe];
  *(undefined4 *)(in_ECX[0xe] + 8) = in_ECX[0xe];
  in_ECX[0xf] = 0;
  if (in_ECX[0x11] != 0) {
    FUN_0089120c(in_ECX[0x11],uVar1);
  }
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_00844d40(*(undefined4 *)in_ECX[0xe],(undefined4 *)in_ECX[0xe]);
  FUN_0089120c(in_ECX[0xe],uVar1);
  *in_ECX = gbBase::vftable;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2],uVar1);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = gbRefCount::vftable;
  ExceptionList = local_10;
  return;
}

