
/* WARNING: Removing unreachable block (ram,0x00827df6) */
/* WARNING: Removing unreachable block (ram,0x00827df2) */
/* WARNING: Removing unreachable block (ram,0x00827e0a) */

undefined2 * FUN_00827d50(undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091425b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0xffff;
  *(undefined4 *)(param_1 + 0xc) = 7;
  *(undefined4 *)(param_1 + 10) = 0;
  param_1[2] = 0;
  FUN_00402160(&DAT_00bed1fc,0);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x1a) = 7;
  *(undefined4 *)(param_1 + 0x18) = 0;
  param_1[0x10] = 0;
  FUN_00402160(&DAT_00bed1fc,0);
  *(undefined4 *)(param_1 + 0x28) = 7;
  *(undefined4 *)(param_1 + 0x26) = 0;
  param_1[0x1e] = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2e) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x36) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x3e) = 0;
  ExceptionList = local_10;
  return param_1;
}

