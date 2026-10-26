
void FUN_0084d0d0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e894;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = gbMesh::vftable;
  local_8 = 5;
  FUN_0084d940(uVar1);
  if ((undefined4 *)param_1[0x1a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x1a])(1);
    param_1[0x1a] = 0;
  }
  if (param_1[0x30] != 0) {
    FUN_0089120c(param_1[0x30]);
  }
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_0084bc50(param_1 + 0x1b);
  if (param_1[0x16] != 0) {
    FUN_0089120c(param_1[0x16]);
  }
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  if (param_1[0x12] != 0) {
    FUN_008510f0(param_1[0x13]);
    FUN_0089120c(param_1[0x12]);
  }
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  if (param_1[10] != 0) {
    FUN_0089120c(param_1[10]);
  }
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  *param_1 = gbBase::vftable;
  if (0xf < (uint)param_1[7]) {
    FUN_0089120c(param_1[2]);
  }
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *param_1 = gbRefCount::vftable;
  ExceptionList = local_10;
  return;
}

