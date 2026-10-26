
undefined4 * FUN_00854c30(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009112a8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00843940(param_1);
  local_8 = 0;
  *param_1 = gbStdMaterial::vftable;
  param_1[99] = 0;
  uVar2 = FUN_007b2620(uVar1);
  param_1[0x62] = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(undefined4 *)(param_1[0x62] + 4) = param_1[0x62];
  *(undefined4 *)(param_1[0x62] + 8) = param_1[0x62];
  *(undefined1 *)(param_1[0x62] + 0x38) = 1;
  *(undefined1 *)(param_1[0x62] + 0x39) = 1;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0x3f800000;
  param_1[0x69] = 0x3f800000;
  param_1[0x6a] = 0x3f800000;
  param_1[0x6b] = 0x3f800000;
  param_1[0x6c] = 0x3f800000;
  param_1[0x6d] = 0x3f800000;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0x3f800000;
  ExceptionList = local_10;
  return param_1;
}

