
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cd210(int *param_1,int *param_2,LONG *param_3,LONG *param_4,int *param_5)

{
  int in_ECX;
  LONG *local_3a4;
  undefined4 uStack_3a0;
  undefined1 auStack_384 [4];
  float local_380;
  float local_37c;
  undefined4 local_378;
  undefined4 local_374;
  int local_370;
  int local_36c;
  tagRECT local_368;
  undefined1 local_358 [812];
  uint uStack_2c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_384;
  local_378 = 0;
  local_374 = 0;
  local_370 = *param_1 + 8;
  local_36c = param_1[1] + 4;
  local_368.left = *param_3;
  local_368.top = param_3[1];
  local_368.right = param_3[2];
  local_368.bottom = param_3[3];
  uStack_3a0 = 0x4cd282;
  InflateRect(&local_368,2,4);
  local_380 = (float)*param_2;
  local_37c = (float)param_2[1];
  if ((_DAT_00fe1bc4 & 1) == 0) {
    _DAT_00fe1bc4 = _DAT_00fe1bc4 | 1;
    _atexit((_func_4879 *)&DAT_00bcec00);
  }
  uStack_3a0 = *(undefined4 *)(in_ECX + 4);
  local_3a4 = param_4;
  FUN_007398a0(local_358);
  uStack_3a0 = 0x4cd2f7;
  (**(code **)(*param_5 + 0x104))();
  uStack_3a0 = 0x1c;
  local_3a4 = &local_368.top;
  (**(code **)(*param_5 + 0x14c))(param_5,4,10);
  __security_check_cookie(uStack_2c ^ (uint)&local_3a4);
  return;
}

