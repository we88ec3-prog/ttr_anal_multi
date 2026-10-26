
undefined4 * FUN_008744c0(undefined4 *param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917d98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = 0;
  local_8 = 0;
  *param_1 = gbBase::vftable;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(param_2 + 8,0,0xffffffff);
  param_1[9] = 1;
  *param_1 = gbAniMeshController::vftable;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xb] = 1;
  param_1[10] = 0xa1240000;
  ExceptionList = local_10;
  return param_1;
}

