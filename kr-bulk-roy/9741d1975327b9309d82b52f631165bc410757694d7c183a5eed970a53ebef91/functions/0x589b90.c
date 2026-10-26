
/* WARNING: Removing unreachable block (ram,0x00589cef) */

void FUN_00589b90(void)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ad88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe2898 & 1) == 0) {
    DAT_00fe2898 = DAT_00fe2898 | 1;
    local_8 = 0;
    FUN_00773dd0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcf3e0);
  }
  local_8 = 0xffffffff;
  _wcscpy_s((wchar_t *)&DAT_00fe28a4,0x104,(wchar_t *)PTR_u_UI_HLSL_Global_hlsl_00d65bf8);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  FUN_00443d10();
  FUN_00443d10();
  FUN_00443d10();
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058d6e0(&DAT_00faaf80);
  FUN_00588770(in_ECX);
  FUN_005877f0(in_ECX);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 3;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058f1a0(&DAT_00faaf80);
  FUN_00589a20(0x3f800000,0x3f800000);
  ExceptionList = local_10;
  return;
}

