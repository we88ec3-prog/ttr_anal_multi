
void FUN_006bcf90(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0093a7b6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FUI::CScenarioTalkBox::vftable;
  local_8 = 0;
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_006f4380(uVar2);
    _atexit((_func_4879 *)&LAB_00bce6d0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  iVar1 = DAT_00fdf3c8;
  *(undefined4 *)(*(int *)(DAT_00fdf3c8 + 8) + 8) = 0;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 0x10;
  DAT_00fe317c = 0;
  DAT_00fe3180 = 0;
  FUN_006f5790();
  local_8 = 0xffffffff;
  *param_1 = FoxUI::FXUIDummy::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

