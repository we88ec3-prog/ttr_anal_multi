
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00630c20(int param_1)

{
  int *in_ECX;
  
  FUN_007445d0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xcb) {
    (**(code **)(*in_ECX + 0x54))();
    if ((_DAT_00fe2c70 & 1) == 0) {
      _DAT_00fe2c70 = _DAT_00fe2c70 | 1;
      DAT_00fe2c74 = 0;
      _atexit((_func_4879 *)&DAT_00bcf460);
    }
    FUN_004a6900();
    (**(code **)(*in_ECX + 0x50))(DAT_00fe2c74);
    return;
  }
  if (*(int *)(param_1 + 0x10) == 0xcc) {
    (**(code **)(*in_ECX + 0x54))();
  }
  return;
}

