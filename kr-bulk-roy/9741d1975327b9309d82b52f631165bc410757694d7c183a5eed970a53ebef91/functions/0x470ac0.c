
uint FUN_00470ac0(int param_1,uint param_2)

{
  uint in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009133ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0dd8 & 1) == 0) {
    DAT_00fc0dd8 = DAT_00fc0dd8 | 1;
    local_8 = 0;
    FUN_00484f20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd9f0);
  }
  FUN_00848020(&param_1);
  if ((in_ECX != DAT_00fc0df0) && (in_ECX != 0xfffffff0)) {
    param_2 = param_2 & 0xffff;
    FUN_004364c0(&param_2);
    ExceptionList = local_10;
    return (uint)(param_1 != *(int *)(in_ECX + 0x14));
  }
  ExceptionList = local_10;
  return in_ECX & 0xffffff00;
}

