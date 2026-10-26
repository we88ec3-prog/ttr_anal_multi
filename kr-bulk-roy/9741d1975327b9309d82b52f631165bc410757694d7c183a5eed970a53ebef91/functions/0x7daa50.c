
void FUN_007daa50(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c78f;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CMotion::vftable;
  param_1[1] = IS3D::CMotion::vftable;
  local_8 = 2;
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    FUN_007b5430(uVar1);
    _atexit((_func_4879 *)&LAB_00bce660);
    local_8 = CONCAT31(local_8._1_3_,2);
  }
  FUN_007b5f30(param_1 + 1);
  if (0xf < (uint)param_1[0x32]) {
    FUN_0089120c(param_1[0x2d]);
  }
  param_1[0x32] = 0xf;
  param_1[0x31] = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  FUN_007ac410();
  *param_1 = IS3D::IMotion::vftable;
  ExceptionList = local_10;
  return;
}

