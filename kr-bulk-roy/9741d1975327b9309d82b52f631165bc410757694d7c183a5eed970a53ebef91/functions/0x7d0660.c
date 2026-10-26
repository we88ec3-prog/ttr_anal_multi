
undefined4 * FUN_007d0660(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009188b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0077ecb0(param_1,param_2);
  local_8 = 0;
  *param_1 = IS3D::CSmartNode::vftable;
  param_1[0x3f] = 0xf;
  param_1[0x3e] = 0;
  *(undefined1 *)(param_1 + 0x3a) = 0;
  FUN_00403040(param_3,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

