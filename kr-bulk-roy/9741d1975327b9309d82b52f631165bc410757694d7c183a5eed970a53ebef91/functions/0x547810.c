
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547810(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093665e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7a20 & 1) == 0) {
    DAT_00fb7a20 = DAT_00fb7a20 | 1;
    local_8 = 0;
    FUN_00548da0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcd370);
  }
  _DAT_00fb7b00 = 0;
  _DAT_00fb7b04 = 1;
  _DAT_00fb7b08 = 0;
  _DAT_00fb7b0c = 0;
  _DAT_00fb7a2c = 0;
  _DAT_00fb7a68 = 0;
  _DAT_00fb7b10 = 0;
  _DAT_00fb7b14 = 1;
  _DAT_00fb7b18 = 0;
  _DAT_00fb7b1c = 0;
  _DAT_00fb7a30 = 0;
  _DAT_00fb7a6c = 0;
  _DAT_00fb7b20 = 0;
  _DAT_00fb7b24 = 1;
  _DAT_00fb7b28 = 0;
  _DAT_00fb7b2c = 0;
  _DAT_00fb7a34 = 0;
  _DAT_00fb7a70 = 0;
  DAT_00fb7a74 = 1;
  ExceptionList = local_10;
  return;
}

