
uint FUN_00445330(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  uint in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910dce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb93b8 & 1) == 0) {
    DAT_00fb93b8 = DAT_00fb93b8 | 1;
    local_8 = 0;
    FUN_00823720(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcd5a0);
  }
  param_1 = (undefined4 *)*param_1;
  FUN_008438c0(&param_1);
  if (in_ECX != DAT_00fb93c0) {
    piVar1 = (int *)(in_ECX + 0x10);
    iVar2 = *piVar1 + 8;
    in_ECX = 0;
    if (iVar2 != 0) {
      ExceptionList = local_10;
      return CONCAT31((int3)((uint)iVar2 >> 8),*(undefined1 *)(*piVar1 + 0xc));
    }
  }
  ExceptionList = local_10;
  return in_ECX & 0xffffff00;
}

