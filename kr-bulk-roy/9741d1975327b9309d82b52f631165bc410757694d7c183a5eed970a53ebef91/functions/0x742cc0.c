
undefined2 * FUN_00742cc0(undefined2 *param_1)

{
  int in_ECX;
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
  *(undefined4 *)(param_1 + 0xe) = *(undefined4 *)(in_ECX + 0x1c);
  *(undefined4 *)(param_1 + 0x1a) = 7;
  *(undefined4 *)(param_1 + 0x18) = 0;
  param_1[0x10] = 0;
  FUN_004026e0(in_ECX + 0x20,0,0xffffffff);
  local_8._0_1_ = 1;
  *(undefined4 *)(param_1 + 0x28) = 7;
  *(undefined4 *)(param_1 + 0x26) = 0;
  param_1[0x1e] = 0;
  FUN_004026e0(in_ECX + 0x3c,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)(param_1 + 0x36) = 7;
  *(undefined4 *)(param_1 + 0x34) = 0;
  param_1[0x2c] = 0;
  FUN_004026e0(in_ECX + 0x58,0,0xffffffff);
  *unaff_FS_OFFSET = local_10;
  return param_1;
}

