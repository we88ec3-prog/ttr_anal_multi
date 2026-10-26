
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00739db0(float param_1,float param_2,undefined4 param_3)

{
  int *piVar1;
  int in_ECX;
  undefined4 in_stack_00000030;
  float in_stack_00000034;
  float in_stack_00000038;
  float in_stack_0000003c;
  float in_stack_00000040;
  int *piStack_3d4;
  int *local_3d0;
  undefined4 *puStack_3cc;
  undefined1 auStack_3b4 [8];
  int local_3ac;
  longlong local_3a8;
  undefined4 local_39c;
  undefined4 local_398;
  float local_394;
  float local_390;
  int local_388;
  int local_384;
  int local_380;
  int local_37c;
  undefined1 auStack_374 [12];
  undefined1 local_368 [812];
  uint uStack_3c;
  void *pvStack_34;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009194de;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_3b4;
  ExceptionList = &local_14;
  local_3ac = FUN_008fed10();
  param_1 = (float)local_3ac;
  local_3ac = FUN_008fed10();
  param_2 = (float)local_3ac;
  puStack_3cc = &param_1;
  local_3d0 = (int *)in_stack_00000030;
  piStack_3d4 = (int *)&stack0x0000001c;
  FUN_007392e0();
  param_1 = param_1 - local_394;
  param_2 = param_2 - local_390;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_c = 0;
    FUN_00736880();
    puStack_3cc = (undefined4 *)0x739e75;
    _atexit(FUN_00bce6f0);
    local_c = 0xffffffff;
  }
  piVar1 = DAT_00fcde2c;
  local_388 = FUN_008fed10();
  local_384 = FUN_008fed10();
  local_380 = FUN_008fed10();
  local_37c = FUN_008fed10();
  local_394 = (float)*(int *)(in_ECX + 0x20);
  local_37c = local_37c + local_384;
  local_380 = local_380 + local_388;
  local_390 = (float)*(int *)(in_ECX + 0x24);
  if (in_stack_00000034 < 1.0) {
    if (0.0 < in_stack_00000034) {
      local_3a8 = (longlong)ROUND(in_stack_00000034 * 255.0 + 0.5);
      local_39c = (undefined4)local_3a8;
    }
    else {
      local_39c = 0;
    }
  }
  else {
    local_39c = 0xff;
  }
  if (in_stack_00000038 < 1.0) {
    if (in_stack_00000038 < 0.0 == (in_stack_00000038 == 0.0)) {
      local_3a8 = (longlong)ROUND(in_stack_00000038 * 255.0 + 0.5);
      local_398 = (undefined4)local_3a8;
    }
    else {
      local_398 = 0;
    }
  }
  else {
    local_398 = 0xff;
  }
  if (in_stack_0000003c < 1.0) {
    if (in_stack_0000003c < 0.0 == (in_stack_0000003c == 0.0)) {
      local_3a8 = (longlong)ROUND(in_stack_0000003c * 255.0 + 0.5);
      local_3ac = (undefined4)local_3a8;
    }
    else {
      local_3ac = 0;
    }
  }
  else {
    local_3ac = 0xff;
  }
  if ((in_stack_00000040 < 1.0) && (0.0 < in_stack_00000040)) {
    local_3a8 = (longlong)ROUND(in_stack_00000040 * 255.0 + 0.5);
  }
  if ((_DAT_00fe1bc4 & 1) == 0) {
    _DAT_00fe1bc4 = _DAT_00fe1bc4 | 1;
    puStack_3cc = (undefined4 *)0x73a060;
    _atexit((_func_4879 *)&DAT_00bcec00);
  }
  puStack_3cc = (undefined4 *)local_394;
  local_3d0 = (int *)param_3;
  piStack_3d4 = &local_388;
  FUN_007396c0(local_368);
  puStack_3cc = (undefined4 *)0x0;
  local_3d0 = piVar1;
  piStack_3d4 = (int *)0x73a0af;
  (**(code **)(*piVar1 + 0x104))();
  piStack_3d4 = (int *)0x1c;
  (**(code **)(*piVar1 + 0x14c))(piVar1,4,2,auStack_374);
  ExceptionList = pvStack_34;
  __security_check_cookie(uStack_3c ^ (uint)&piStack_3d4);
  return;
}

