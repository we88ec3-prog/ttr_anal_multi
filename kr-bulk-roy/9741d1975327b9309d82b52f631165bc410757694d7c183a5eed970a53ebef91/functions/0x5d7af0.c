
void FUN_005d7af0(int param_1)

{
  int in_ECX;
  wchar_t local_210 [258];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (1 < param_1) {
    __itow_s(param_1,local_210,0x100,10);
    (**(code **)(**(int **)(in_ECX + 0x298) + 0x94))(1);
    FUN_00757710();
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 0x298) + 0x94))(0);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

