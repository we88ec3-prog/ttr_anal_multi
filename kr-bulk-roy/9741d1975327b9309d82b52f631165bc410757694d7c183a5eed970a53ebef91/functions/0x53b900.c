
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053b900(undefined1 param_1,undefined1 param_2)

{
  wchar_t *unaff_ESI;
  undefined2 local_3c;
  wchar_t local_3a [21];
  undefined1 local_10;
  undefined4 local_f;
  undefined1 local_b;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_3c = 0x53;
  local_f = 0;
  _wcscpy_s(local_3a,0x15,unaff_ESI);
  local_10 = param_1;
  local_b = param_2;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_3c,0x32);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

