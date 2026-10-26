
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053b990(undefined1 param_1,undefined1 param_2)

{
  wchar_t *unaff_ESI;
  undefined2 local_38;
  wchar_t local_36 [21];
  undefined1 local_c;
  undefined1 local_b;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_38 = 0x5f;
  _wcscpy_s(local_36,0x15,unaff_ESI);
  local_c = param_1;
  local_b = param_2;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_38,0x2e);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

