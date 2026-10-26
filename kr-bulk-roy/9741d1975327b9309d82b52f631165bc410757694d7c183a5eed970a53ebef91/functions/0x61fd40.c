
void FUN_0061fd40(char param_1)

{
  short sVar1;
  byte bVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912592;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == '\0') {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 2;
      FUN_0054f850(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    if (DAT_00fb92c9 == '\x10') {
      ExceptionList = local_10;
      return;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 3;
      FUN_0054f850(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fb92c9 = 0x10;
    if (DAT_00fb92cb < 0x10) {
      DAT_00fb92c9 = DAT_00fb92cb;
    }
    if (DAT_00fb92c9 < DAT_00fb92ca) {
      DAT_00fb92c9 = DAT_00fb92ca;
    }
  }
  else {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    if (DAT_00fb92c9 == ' ') {
      ExceptionList = local_10;
      return;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 1;
      FUN_0054f850(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fb92c9 = 0x20;
    if (DAT_00fb92cb < 0x20) {
      DAT_00fb92c9 = DAT_00fb92cb;
    }
    if (DAT_00fb92c9 < DAT_00fb92ca) {
      DAT_00fb92c9 = DAT_00fb92ca;
    }
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 4;
    FUN_0054f850(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  bVar2 = DAT_00fb92c9;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 5;
    FUN_0054f850(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  sVar1 = DAT_00fb92ba;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 6;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8 = 0xffffffff;
  FUN_006dedf0((int)DAT_00fb92aa,(int)sVar1,bVar2);
  FUN_006e32a0();
  ExceptionList = local_10;
  return;
}

