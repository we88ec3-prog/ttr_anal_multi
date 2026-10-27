
undefined4 FUN_007b8230(void)

{
  int iVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cb15;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_008380b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  iVar1 = FUN_007b8180();
  if (iVar1 != 0) {
    uVar2 = FUN_007dcfb0(iVar1);
    FUN_00837fd0();
    PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
    ExceptionList = local_10;
    return uVar2;
  }
  FUN_00837fd0();
  PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
  ExceptionList = local_10;
  return 0;
}

