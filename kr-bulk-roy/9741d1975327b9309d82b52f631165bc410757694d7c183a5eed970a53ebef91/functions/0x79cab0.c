
undefined4 * FUN_0079cab0(undefined4 *param_1,int param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918f73;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = IS3D::CCircleShadow::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x3dcccccd;
  param_1[6] = 0;
  param_1[0xc] = 0xf;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  FUN_00402a70("shadow.dds",10);
  param_1[0xe] = IS3D::IRenderable::vftable;
  local_8 = 1;
  *param_1 = IS3DX::CSurfaceMarker::vftable;
  param_1[0xe] = IS3DX::CSurfaceMarker::vftable;
  param_1[0xf] = param_2;
  if (param_2 == 0) {
    uVar2 = 0x11;
    pcVar1 = "shadow_leader.dds";
  }
  else {
    if (param_2 != 1) {
      ExceptionList = local_10;
      return param_1;
    }
    uVar2 = 0xe;
    pcVar1 = "shadow_sub.dds";
  }
  FUN_00402a70(pcVar1,uVar2);
  ExceptionList = local_10;
  return param_1;
}

