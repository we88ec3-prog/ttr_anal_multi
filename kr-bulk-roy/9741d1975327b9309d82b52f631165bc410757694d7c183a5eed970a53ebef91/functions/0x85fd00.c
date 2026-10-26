
undefined4 * FUN_0085fd00(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009111ef;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0077fd70(param_1);
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x15] = 0;
  param_1[0x1b] = 3;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1c] = 0;
  puVar1 = param_1 + 0x1e;
  *param_1 = gbSkeletal::vftable;
  *puVar1 = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  local_8 = 3;
  FUN_00860810(puVar1,local_14,*puVar1,param_1[0x1f]);
  param_1[0x1d] = 0;
  param_1[0x2a] = 1;
  ExceptionList = local_10;
  return param_1;
}

