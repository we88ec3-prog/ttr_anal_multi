
void FUN_004a3f20(wchar_t *param_1)

{
  undefined2 local_38;
  undefined1 local_36;
  wchar_t local_35 [22];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_38 = 99;
  _wcscpy_s(local_35,0x15,param_1);
  local_36 = 0;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_38,0x2d);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

