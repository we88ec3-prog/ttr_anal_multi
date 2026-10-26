
undefined4 FUN_00862fb0(int param_1,undefined4 param_2)

{
  uint uVar1;
  int unaff_EDI;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906998;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0xffffffff;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  local_2c = unaff_EDI + 0x50;
  local_30 = 0;
  local_28 = 0;
  FUN_00863260(param_1 + 0x28,&local_34);
  FUN_008630f0(param_1,unaff_EDI,param_2);
  if (DAT_00fba940 != (int *)0x0) {
    (**(code **)(*DAT_00fba940 + 0x10c))(DAT_00fba940,uVar1);
    DAT_00fba940 = (int *)0x0;
  }
  ExceptionList = local_10;
  return 1;
}

