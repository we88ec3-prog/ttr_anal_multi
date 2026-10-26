
undefined2 *
FUN_007406c0(undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 in_ECX;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c9ae;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_004026e0(in_ECX,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0xe) = param_2;
  *(undefined4 *)(param_1 + 0x1a) = 7;
  *(undefined4 *)(param_1 + 0x18) = 0;
  param_1[0x10] = 0;
  FUN_004026e0(param_3,0,0xffffffff);
  local_8._0_1_ = 1;
  *(undefined4 *)(param_1 + 0x28) = 7;
  *(undefined4 *)(param_1 + 0x26) = 0;
  param_1[0x1e] = 0;
  FUN_004026e0(param_4,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)(param_1 + 0x36) = 7;
  *(undefined4 *)(param_1 + 0x34) = 0;
  param_1[0x2c] = 0;
  FUN_004026e0(param_5,0,0xffffffff);
  *unaff_FS_OFFSET = local_10;
  return param_1;
}

