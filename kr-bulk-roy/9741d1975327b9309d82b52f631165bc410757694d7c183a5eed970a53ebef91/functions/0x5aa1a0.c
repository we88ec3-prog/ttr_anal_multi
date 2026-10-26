
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005aa1a0(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x3c) != 0) && ((*(uint *)(in_ECX + 0x28) & 0x40000) == 0)) {
    FUN_00746b80();
  }
  if ((_DAT_00f8d8a8 & 1) == 0) {
    _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
    FUN_005e93a0();
    _atexit((_func_4879 *)&DAT_00bccc40);
  }
  FUN_005e9d20(&DAT_00f8d8b0);
  return;
}

