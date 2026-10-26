
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dc800(int param_1)

{
  int *in_ECX;
  
  FUN_00744ca0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xcb) {
    if (in_ECX[0x97] != 0) {
      if ((_DAT_00fe2c78 & 1) == 0) {
        _DAT_00fe2c78 = _DAT_00fe2c78 | 1;
        DAT_00fe2c7c = 0;
        _atexit((_func_4879 *)&DAT_00bcf440);
      }
      if (DAT_00fe2c7c != 0) {
        FUN_006c9cd0(DAT_00fe2c7c,0);
      }
      (**(code **)(*in_ECX + 0x50))(DAT_00fe2c7c);
      return;
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0xcc) {
    (**(code **)(*in_ECX + 0x54))();
  }
  return;
}

