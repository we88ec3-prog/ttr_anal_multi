
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d7440(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x25c) != 0) {
    if ((_DAT_00f8d8a8 & 1) == 0) {
      _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
      FUN_005e93a0();
      _atexit((_func_4879 *)&DAT_00bccc40);
    }
    FUN_005e9420(&DAT_00f8d8b0,*(undefined4 *)(in_ECX + 0x250),*(undefined4 *)(in_ECX + 0x254));
    return;
  }
  if (*(int *)(in_ECX + 0x288) != 0) {
    FUN_004026e0(in_ECX + 0x278,0,0xffffffff);
    if ((_DAT_00f8d910 & 1) == 0) {
      _DAT_00f8d910 = _DAT_00f8d910 | 1;
      _atexit((_func_4879 *)&DAT_00bccc60);
    }
    FUN_006cb880();
  }
  return;
}

