
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041fc60(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  FUN_007445d0();
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xcb) {
    FUN_0041fd50();
    (**(code **)(*in_ECX + 0x54))();
    FUN_004026e0(in_ECX + 0x56,0,0xffffffff);
    if ((_DAT_00f8d910 & 1) == 0) {
      _DAT_00f8d910 = _DAT_00f8d910 | 1;
      _atexit((_func_4879 *)&DAT_00bccc60);
    }
  }
  else {
    if (iVar1 == 0xcc) {
      (**(code **)(*in_ECX + 0x54))();
      return;
    }
    if (iVar1 != 200) {
      return;
    }
    FUN_0041fd50();
    (**(code **)(*in_ECX + 0x54))();
    FUN_004026e0(in_ECX + 0x56,0,0xffffffff);
    FUN_00403550();
  }
  FUN_006cb880();
  (**(code **)(*in_ECX + 0x50))();
  return;
}

