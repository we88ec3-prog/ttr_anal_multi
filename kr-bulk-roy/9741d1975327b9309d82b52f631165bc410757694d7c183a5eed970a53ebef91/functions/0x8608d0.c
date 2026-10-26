
void FUN_008608d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  uint in_stack_00000020;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00913c68;
  local_10 = ExceptionList;
  uStack_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_34;
  local_8 = 0;
  local_24 = 0;
  local_20 = 0xf;
  local_34[0] = 0;
  FUN_00403040(&param_3,0,0xffffffff);
  uVar1 = FUN_008730e0(param_2);
  *unaff_ESI = uVar1;
  if (0xf < in_stack_00000020) {
    uStack_1c = param_3;
    local_20 = 0x86093b;
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

