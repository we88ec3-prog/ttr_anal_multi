
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403ab0(void)

{
  int in_ECX;
  
  if ((_DAT_00f8d8a8 & 1) == 0) {
    _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
    FUN_005e93a0();
    _atexit((_func_4879 *)&DAT_00bccc40);
  }
  FUN_005e9420(&DAT_00f8d8b0,*(undefined4 *)(in_ECX + 0x248),*(undefined4 *)(in_ECX + 0x24c),0,0,0,0
               ,0,0,0);
  return;
}

