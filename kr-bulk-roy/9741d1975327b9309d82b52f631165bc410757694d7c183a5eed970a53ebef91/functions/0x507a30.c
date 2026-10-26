
undefined4 * FUN_00507a30(int param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009172fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1b30 & 1) == 0) {
    DAT_00fe1b30 = DAT_00fe1b30 | 1;
    local_8 = 0;
    FUN_0047faf0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bceab0);
  }
  uVar2 = param_2 & 0xffff;
  param_2 = CONCAT22((undefined2)param_1,(undefined2)param_2);
  FUN_0047fdf0(&param_2);
  if (param_1 == DAT_00fe1b48) {
    puVar1 = (undefined4 *)(&PTR_u______00d6a12c)[uVar2];
  }
  else {
    puVar1 = (undefined4 *)(param_1 + 0x10);
    if (7 < *(uint *)(param_1 + 0x24)) {
      ExceptionList = local_10;
      return (undefined4 *)*puVar1;
    }
  }
  ExceptionList = local_10;
  return puVar1;
}

