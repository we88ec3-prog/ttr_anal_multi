
void FUN_007d9030(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c9c6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CSpliteMotion::vftable;
  param_1[1] = IS3D::CSpliteMotion::vftable;
  local_8 = 5;
  if (param_1[0x30] != param_1[0x31]) {
    uVar2 = FUN_004fa270(param_1[0x30],uVar1);
    param_1[0x31] = uVar2;
  }
  if (param_1[2] != param_1[3]) {
    uVar2 = FUN_007da670(param_1[3]);
    FUN_007b2b40(param_1);
    param_1[3] = uVar2;
  }
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8._0_1_ = 6;
    FUN_007b5430();
    _atexit((_func_4879 *)&LAB_00bce660);
    local_8 = CONCAT31(local_8._1_3_,5);
  }
  FUN_007b5f30(param_1 + 1);
  if (param_1[0x45] != 0) {
    FUN_0089120c(param_1[0x45]);
  }
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  if (0xf < (uint)param_1[0x40]) {
    FUN_0089120c(param_1[0x3b]);
  }
  param_1[0x40] = 0xf;
  param_1[0x3f] = 0;
  *(undefined1 *)(param_1 + 0x3b) = 0;
  if (0xf < (uint)param_1[0x39]) {
    FUN_0089120c(param_1[0x34]);
  }
  param_1[0x39] = 0xf;
  param_1[0x38] = 0;
  *(undefined1 *)(param_1 + 0x34) = 0;
  if (param_1[0x30] != 0) {
    FUN_0089120c(param_1[0x30]);
  }
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  FUN_007ac410();
  if (param_1[2] != 0) {
    FUN_007b2b40(param_1);
    FUN_0089120c(param_1[2]);
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = IS3D::IMotion::vftable;
  ExceptionList = local_10;
  return;
}

