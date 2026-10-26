
undefined4 FUN_0083b170(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *local_4c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009141b8;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  uVar2 = FUN_00864f70(param_2);
  local_c = 0;
  puVar3 = (undefined4 *)FUN_00863590(param_1,uVar2);
  *param_3 = *puVar3;
  local_c = 0xffffffff;
  if (local_4c != (int *)0x0) {
    (**(code **)(*local_4c + 8))(local_4c,uVar1);
  }
  ExceptionList = local_14;
  return 1;
}

