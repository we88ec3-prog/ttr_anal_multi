
undefined4 * FUN_00533200(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912d63;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fe1d98 = param_1;
  param_1[1] = IDataTable::vftable;
  local_8 = 1;
  *param_1 = CTownInfoTable::vftable;
  param_1[1] = CTownInfoTable::vftable;
  param_1[4] = 0;
  uVar2 = FUN_006db770(uVar1);
  param_1[3] = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(undefined4 *)(param_1[3] + 4) = param_1[3];
  *(undefined4 *)(param_1[3] + 8) = param_1[3];
  *(undefined1 *)(param_1[3] + 0x34) = 1;
  *(undefined1 *)(param_1[3] + 0x35) = 1;
  ExceptionList = local_10;
  return param_1;
}

