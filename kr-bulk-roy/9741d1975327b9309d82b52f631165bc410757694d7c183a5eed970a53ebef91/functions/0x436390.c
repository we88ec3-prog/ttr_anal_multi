
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00436390(void)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_ESI;
  undefined1 auStack_34 [4];
  undefined1 local_30 [4];
  undefined2 local_2c;
  undefined2 local_2a;
  undefined1 local_28;
  undefined2 local_27;
  undefined4 local_25;
  undefined4 local_21;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941ace;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_34;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if (*(char *)(unaff_ESI + 0x158) == '\0') {
    uVar1 = *(undefined1 *)(unaff_ESI + 0x140);
    uVar2 = DAT_00f94390 & 1;
    *(undefined1 *)(unaff_ESI + 0x158) = 1;
    local_30[1] = *(undefined1 *)(unaff_ESI + 0x138);
    local_30[0] = *(undefined1 *)(unaff_ESI + 0x13c);
    local_30[2] = 0;
    if (uVar2 == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar3);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    DAT_00f942d8 = 1;
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_27 = *(undefined2 *)(unaff_ESI + 0x160);
    local_25 = *(undefined4 *)(unaff_ESI + 0x168);
    local_2c = 0x100;
    local_21 = *(undefined4 *)(unaff_ESI + 0x16c);
    local_2a = local_30._0_2_;
    local_28 = uVar1;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_2c,0xf);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_34);
  return;
}

