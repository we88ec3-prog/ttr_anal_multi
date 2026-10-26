
void FUN_004a4350(wchar_t *param_1)

{
  undefined2 local_34;
  wchar_t local_32 [21];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_34 = 0x78;
  _wcscpy_s(local_32,0x15,param_1);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_34,0x2c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

