
undefined4 * FUN_007e9420(undefined4 *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00934a39;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = IS3D::CSteppableObject::vftable;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  local_8 = 3;
  FUN_007e9520(param_1,param_2);
  ExceptionList = local_10;
  return param_1;
}

