
void FUN_0041c3e0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int *unaff_EDI;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000030;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092b510;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = local_34[0] & 0xffff0000;
  FUN_004026e0(&param_1,0,0xffffffff);
  local_8._0_1_ = 1;
  FUN_00757800(local_34);
  (**(code **)(*(int *)unaff_EDI[0x56] + 200))(uVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_20) {
    FUN_0089120c(local_34[0]);
  }
  FUN_0041c540(unaff_EDI,in_stack_00000024);
  FUN_0041c620(unaff_EDI,in_stack_00000020);
  FUN_007545b0();
  FUN_00749d00();
  FUN_00749d00();
  iVar2 = (((in_stack_00000030 - in_stack_00000028) / 2 - (unaff_EDI[4] - unaff_EDI[2]) / 2) -
          unaff_EDI[2]) + in_stack_00000028;
  unaff_EDI[2] = unaff_EDI[2] + iVar2;
  unaff_EDI[4] = unaff_EDI[4] + iVar2;
  iVar2 = ((unaff_EDI[3] - unaff_EDI[5]) + in_stack_0000002c) - unaff_EDI[3];
  unaff_EDI[3] = unaff_EDI[3] + iVar2;
  unaff_EDI[5] = unaff_EDI[5] + iVar2;
  FUN_00746f70();
  (**(code **)(*unaff_EDI + 200))();
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

