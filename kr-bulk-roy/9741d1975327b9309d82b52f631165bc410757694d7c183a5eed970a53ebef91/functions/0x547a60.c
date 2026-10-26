
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00547a60(void)

{
  uint uVar1;
  undefined4 in_ECX;
  bool bVar2;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009273e6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = CONCAT13((char)((uint)in_ECX >> 0x18),7);
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  if (DAT_00fb9015 == '\x01') {
    if ((DAT_00fb7a20 & 1) == 0) {
      DAT_00fb7a20 = DAT_00fb7a20 | 1;
      local_8 = 1;
      FUN_00548da0();
      _atexit(FUN_00bcd370);
    }
    if (DAT_00fb7ad0 != 0) {
      _DAT_00fb7ad4 = 3;
      _DAT_00fb7ad8 = 0;
    }
    if (DAT_00fb7ae0 != 0) {
      _DAT_00fb7ae4 = 3;
      _DAT_00fb7ae8 = 0;
    }
    if (DAT_00fb7af0 != 0) {
      _DAT_00fb7af4 = 3;
      _DAT_00fb7af8 = 0;
    }
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 2;
    FUN_006d0750(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb901b == '\x01') {
    FUN_00547960();
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 3;
    FUN_006d0750(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_8 = 0xffffffff;
  }
  bVar2 = DAT_00fb9019 == '\x01';
  if (bVar2) {
    local_14 = local_14 | 0x10000;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 4;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb902b == '\x01') {
    local_14 = local_14 | 0x40000;
  }
  else if (!bVar2) {
    ExceptionList = local_10;
    return 0;
  }
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_14,3);
  }
  ExceptionList = local_10;
  return 1;
}

