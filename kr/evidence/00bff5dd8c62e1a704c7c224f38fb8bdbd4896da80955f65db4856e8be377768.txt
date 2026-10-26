
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00547390(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933b18;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00544c40(param_1);
  local_8._1_3_ = 0;
  uVar1 = DAT_00fb7a20 & 1;
  *param_1 = CFormationController::vftable;
  param_1[0x2d] = 0;
  if (uVar1 == 0) {
    DAT_00fb7a20 = DAT_00fb7a20 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00548da0(uVar2);
    _atexit(FUN_00bcd370);
  }
  local_8._0_1_ = 0;
  _DAT_00fb7a94 = param_1[0x2d];
  _DAT_00fb7a2c = 0;
  _DAT_00fb7a30 = 0;
  _DAT_00fb7a34 = 0;
  DAT_00fba7ac = 3;
  iVar3 = FUN_00891268(0x18);
  local_8._0_1_ = 2;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0079c5b0();
  }
  local_8._0_1_ = 0;
  param_1[0x2e] = uVar4;
  iVar3 = FUN_00891268(0x40);
  local_8._0_1_ = 3;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0079cab0(iVar3,0);
  }
  local_8._0_1_ = 0;
  param_1[0x2f] = uVar4;
  puVar5 = (undefined4 *)FUN_00891268(0x40);
  local_8._0_1_ = 4;
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = IS3D::CCircleShadow::vftable;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0x3dcccccd;
    puVar5[6] = 0;
    puVar5[0xc] = 0xf;
    puVar5[0xb] = 0;
    *(undefined1 *)(puVar5 + 7) = 0;
    FUN_00402a70("shadow.dds",10);
    puVar5[0xe] = IS3D::IRenderable::vftable;
    local_8._0_1_ = 6;
    *puVar5 = IS3DX::CSurfaceMarker::vftable;
    puVar5[0xe] = IS3DX::CSurfaceMarker::vftable;
    puVar5[0xf] = 1;
    FUN_00402a70("shadow_sub.dds",0xe);
  }
  local_8._0_1_ = 0;
  param_1[0x30] = puVar5;
  puVar5 = (undefined4 *)FUN_00891268(0x40);
  local_8._0_1_ = 7;
  if (puVar5 == (undefined4 *)0x0) {
    param_1[0x31] = 0;
  }
  else {
    *puVar5 = IS3D::CCircleShadow::vftable;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0x3dcccccd;
    puVar5[6] = 0;
    puVar5[0xc] = 0xf;
    puVar5[0xb] = 0;
    *(undefined1 *)(puVar5 + 7) = 0;
    FUN_00402a70("shadow.dds",10);
    puVar5[0xe] = IS3D::IRenderable::vftable;
    local_8 = CONCAT31(local_8._1_3_,9);
    *puVar5 = IS3DX::CSurfaceMarker::vftable;
    puVar5[0xe] = IS3DX::CSurfaceMarker::vftable;
    puVar5[0xf] = 1;
    FUN_00402a70("shadow_sub.dds",0xe);
    param_1[0x31] = puVar5;
  }
  ExceptionList = local_10;
  return param_1;
}

