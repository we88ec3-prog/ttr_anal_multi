
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00435f10(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  undefined1 local_28 [4];
  undefined2 local_24;
  undefined2 local_22;
  undefined1 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941b0e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_2c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 0x158) == '\0') {
    uVar1 = *(undefined1 *)(param_1 + 0x140);
    uVar2 = DAT_00f94390 & 1;
    *(undefined1 *)(param_1 + 0x158) = 1;
    local_28[1] = *(undefined1 *)(param_1 + 0x138);
    local_28[0] = *(undefined1 *)(param_1 + 0x13c);
    local_28[2] = 0;
    if (uVar2 == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar3);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    DAT_00f942d8 = 0;
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_24 = 0xfb;
    local_22 = local_28._0_2_;
    local_20 = uVar1;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_24,5);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_2c);
  return;
}

