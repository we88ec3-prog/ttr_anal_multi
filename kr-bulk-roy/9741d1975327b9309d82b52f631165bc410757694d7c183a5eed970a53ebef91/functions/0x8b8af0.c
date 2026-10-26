
void FUN_008b8af0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_18 = param_3;
  if ((param_2 != 0) && (local_18 = param_2, param_3 == 0)) {
    param_3 = param_2;
  }
  local_10 = param_5;
  if ((param_4 != 0) && (local_10 = param_4, param_5 == 0)) {
    param_5 = param_4;
  }
  if (local_18 < 0x40) {
    local_18 = 0x40;
  }
  if (param_3 < 0x40) {
    param_3 = 0x40;
  }
  if (local_10 == 0) {
    param_5 = 0x48;
    local_10 = 0x48;
  }
  local_1c = 0;
  local_14 = param_3;
  local_c = param_5;
  FUN_008b8a60(param_1,&local_1c);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

