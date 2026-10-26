
undefined4 * FUN_00401500(undefined4 *param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090bfb1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  param_1[6] = 7;
  param_1[5] = 0;
  *(undefined2 *)(param_1 + 1) = 0;
  FUN_004026e0(in_ECX + 1,0,0xffffffff);
  local_8 = 0;
  param_1[0xd] = 7;
  param_1[0xc] = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  FUN_004026e0(in_ECX + 8,0,0xffffffff);
  local_8._0_1_ = 1;
  param_1[0x14] = 7;
  param_1[0x13] = 0;
  *(undefined2 *)(param_1 + 0xf) = 0;
  FUN_004026e0(in_ECX + 0xf,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined1 *)(param_1 + 0x16) = *(undefined1 *)(in_ECX + 0x16);
  *(undefined1 *)((int)param_1 + 0x59) = *(undefined1 *)((int)in_ECX + 0x59);
  FUN_00401690(param_1 + 0x17,in_ECX + 0x17);
  ExceptionList = local_10;
  return param_1;
}

