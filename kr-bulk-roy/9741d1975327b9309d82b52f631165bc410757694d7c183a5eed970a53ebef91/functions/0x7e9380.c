
undefined1 * FUN_007e9380(undefined1 *param_1,undefined4 param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009147b3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00402bb0(param_2);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x1c) = *param_3;
  *(undefined4 *)(param_1 + 0x34) = 0xf;
  *(undefined4 *)(param_1 + 0x30) = 0;
  param_1[0x20] = 0;
  FUN_00403040(param_3 + 1,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_007e8a90(param_1 + 0x3c,param_3 + 8);
  ExceptionList = local_10;
  return param_1;
}

