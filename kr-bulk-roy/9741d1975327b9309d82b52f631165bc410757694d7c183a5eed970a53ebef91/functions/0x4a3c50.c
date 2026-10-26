
void FUN_004a3c50(undefined1 param_1,undefined1 param_2,undefined1 *param_3)

{
  undefined1 *in_ECX;
  undefined2 local_14;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = 0x6e;
  local_12 = param_1;
  local_11 = param_2;
  local_10 = *in_ECX;
  local_d = *param_3;
  local_f = in_ECX[4];
  local_e = in_ECX[8];
  local_c = param_3[4];
  local_b = param_3[8];
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_14,10);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

