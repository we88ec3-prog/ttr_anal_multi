
undefined4 * FUN_0051bd70(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912e1f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  FUN_007e8a90(param_1 + 1,in_ECX);
  local_8 = 0;
  FUN_0051aca0(param_1 + 5,in_ECX + 0x10);
  local_8._0_1_ = 1;
  FUN_0051abd0(param_1 + 9,in_ECX + 0x20);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0051ab00(param_1 + 0xd,in_ECX + 0x30);
  param_1[0x11] = *(undefined4 *)(in_ECX + 0x40);
  ExceptionList = local_10;
  return param_1;
}

