
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0054e750(void)

{
  undefined4 uVar1;
  undefined1 local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a894;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = &DAT_00fb7620;
  DAT_00fb7620 = 0;
  DAT_00fb7624 = CameraWorks::CCameraWorks_KeyFrame::vftable;
  _DAT_00fb7628 = IS3DX::CCameraWorks::vftable;
  DAT_00fb762c = 0;
  DAT_00fb7630 = 0;
  _DAT_00fb7634 = 0;
  _DAT_00fb763c = 0;
  _DAT_00fb7640 = 0;
  _DAT_00fb7644 = 0;
  _DAT_00fb7648 = 0;
  _DAT_00fb764c = 0;
  _DAT_00fb7650 = 0;
  _DAT_00fb7654 = 0;
  _DAT_00fb7658 = 0;
  _DAT_00fb765c = 0;
  _DAT_00fb7660 = 0;
  _DAT_00fb7664 = 0;
  _DAT_00fb7668 = 0;
  _DAT_00fb7678 = 0;
  _DAT_00fb767c = 0;
  _DAT_00fb7680 = 0;
  _DAT_00fb7688 = 0;
  _DAT_00fb768c = 0;
  _DAT_00fb7690 = 0;
  _DAT_00fb7694 = 0;
  _DAT_00fb7698 = 0x3f800000;
  _DAT_00fb769c = 0x43fa0000;
  DAT_00fb766c = CameraWorks::CCameraWorks_AttachSceneObj::vftable;
  _DAT_00fb7670 = 0;
  _DAT_00fb7674 = 0;
  _DAT_00fb7684 = 0x3fc90fdb;
  _DAT_00fb76a0 = 0x3f91361e;
  _DAT_00fb76a4 = 1;
  local_8 = 1;
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_006f4380(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce6d0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_00434130(&DAT_00fdf3c8);
  uVar1 = FUN_0054ea20(local_18);
  uVar1 = FUN_0054eb00(uVar1);
  uVar1 = FUN_0054eba0(uVar1);
  uVar1 = FUN_0054ec40(uVar1);
  uVar1 = FUN_0054ece0(uVar1);
  FUN_0054ed80(uVar1);
  ExceptionList = local_10;
  return &DAT_00fb7620;
}

