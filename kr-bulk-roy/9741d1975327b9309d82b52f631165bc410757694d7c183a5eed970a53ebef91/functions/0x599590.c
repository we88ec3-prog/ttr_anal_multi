
/* WARNING: Removing unreachable block (ram,0x0059994c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00599590(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912470;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005a3cc0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((_DAT_00f8d910 & 1) == 0) {
    _DAT_00f8d910 = _DAT_00f8d910 | 1;
    _atexit((_func_4879 *)&DAT_00bccc60);
  }
  FUN_006cb7f0(&DAT_00f8d914);
  if ((_DAT_00f8d8a8 & 1) == 0) {
    _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
    FUN_005e93a0();
    _atexit((_func_4879 *)&DAT_00bccc40);
  }
  FUN_005e99c0();
  if ((_DAT_00fc0db0 & 1) == 0) {
    _DAT_00fc0db0 = _DAT_00fc0db0 | 1;
    DAT_00fc0db4 = 0;
    DAT_00fc0db8 = 0;
    DAT_00fc0dbc = 0;
    DAT_00fc0dc0 = 0;
    _atexit((_func_4879 *)&DAT_00bcd9e0);
  }
  FUN_0060c5b0();
  if ((_DAT_00fe2c60 & 1) == 0) {
    _DAT_00fe2c60 = _DAT_00fe2c60 | 1;
    DAT_00fe2c64 = 0;
    _atexit((_func_4879 *)&DAT_00bcf430);
  }
  FUN_006beed0();
  if ((_DAT_00fe2c78 & 1) == 0) {
    _DAT_00fe2c78 = _DAT_00fe2c78 | 1;
    DAT_00fe2c7c = 0;
    _atexit((_func_4879 *)&DAT_00bcf440);
  }
  FUN_006ca790();
  if ((_DAT_00fe2c68 & 1) == 0) {
    _DAT_00fe2c68 = _DAT_00fe2c68 | 1;
    DAT_00fe2c6c = 0;
    _atexit((_func_4879 *)&DAT_00bcf450);
  }
  FUN_00464a70();
  if ((_DAT_00fbacd8 & 1) == 0) {
    _DAT_00fbacd8 = _DAT_00fbacd8 | 1;
    _DAT_00fbacdc = 0;
    _DAT_00fbace0 = 0;
    _atexit((_func_4879 *)&DAT_00bcd6c0);
  }
  FUN_00479f70();
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x65);
  FUN_004095e0(0x6d);
  FUN_004095e0(0x6c);
  FUN_004095e0(0x11);
  FUN_004095e0(0x12);
  FUN_004095e0(0x4b);
  FUN_004095e0(0x51);
  FUN_004095e0(0xeb);
  FUN_004095e0(0xec);
  FUN_004095e0(0xed);
  FUN_004095e0(0xef);
  FUN_004095e0(0xf0);
  FUN_004095e0(0xbc);
  FUN_004095e0(0xc1);
  FUN_004095e0(0xc6);
  FUN_004095e0(0xf1);
  FUN_004095e0(0xf4);
  FUN_004095e0(0xf8);
  FUN_004095e0(0xf9);
  FUN_004095e0(0xfa);
  FUN_004095e0(0xfb);
  FUN_004095e0(0x102);
  FUN_004095e0(0x103);
  FUN_004095e0(0x104);
  FUN_004095e0(0x105);
  FUN_004095e0(0x10f);
  FUN_004095e0(0x112);
  FUN_004095e0(0x111);
  FUN_004095e0(0x13);
  FUN_004095e0(0x6f);
  FUN_004095e0(0x34);
  FUN_004095e0(0x52);
  FUN_004095e0(0xda);
  FUN_004095e0(0xdb);
  FUN_004095e0(0xdc);
  FUN_004095e0(0xdd);
  FUN_004095e0(0xde);
  FUN_004095e0(0xe6);
  FUN_004095e0(0x120);
  FUN_004095e0(0x121);
  FUN_004095e0(0x122);
  FUN_004095e0(0x124);
  FUN_004095e0(0xa0);
  FUN_004095e0(0x11c);
  FUN_004095e0(299);
  FUN_004095e0(0x129);
  ExceptionList = local_10;
  return;
}

