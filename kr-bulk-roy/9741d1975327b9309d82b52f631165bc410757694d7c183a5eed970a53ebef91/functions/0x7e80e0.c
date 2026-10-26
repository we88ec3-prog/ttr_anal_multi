
void FUN_007e80e0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c392;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CDecalMgr::vftable;
  local_8 = 2;
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(1,uVar1);
    param_1[9] = 0;
  }
  local_8._0_1_ = 3;
  FUN_007e8940(*(undefined4 *)param_1[6],(undefined4 *)param_1[6]);
  FUN_0089120c(param_1[6]);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_007e8940(*(undefined4 *)param_1[2],(undefined4 *)param_1[2]);
  FUN_0089120c(param_1[2]);
  *param_1 = IS3D::IRenderable::vftable;
  ExceptionList = local_10;
  return;
}

