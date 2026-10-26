
void FUN_004a3e70(undefined4 param_1)

{
  undefined2 local_3c;
  undefined1 local_3a [42];
  undefined1 local_10;
  undefined4 local_f;
  undefined1 local_b;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_3c = 0x53;
  _memset(local_3a,0,0x2a);
  local_f = param_1;
  local_10 = 2;
  local_b = 0;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_3c,0x32);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

