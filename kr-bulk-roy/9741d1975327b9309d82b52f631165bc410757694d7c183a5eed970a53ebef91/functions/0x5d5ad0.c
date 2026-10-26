
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d5ad0(int param_1)

{
  int *in_ECX;
  
  FUN_007445d0();
  if (*(int *)(param_1 + 0x10) == 0xcb) {
    FUN_005d5b80();
    (**(code **)(*in_ECX + 0x54))();
    FUN_004026e0(in_ECX + 0x37,0,0xffffffff);
    if ((_DAT_00f8d910 & 1) == 0) {
      _DAT_00f8d910 = _DAT_00f8d910 | 1;
      _atexit((_func_4879 *)&DAT_00bccc60);
    }
    FUN_006cb880();
    (**(code **)(*in_ECX + 0x50))();
    return;
  }
  if (*(int *)(param_1 + 0x10) == 0xcc) {
    (**(code **)(*in_ECX + 0x54))();
  }
  return;
}

