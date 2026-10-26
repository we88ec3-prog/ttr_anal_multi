
void FUN_0077b5f0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009057f8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FoxUI::FXUISoundPath::vftable;
  local_8 = 0;
  if (7 < (uint)param_1[0x39]) {
    FUN_0089120c(param_1[0x34],uVar1);
  }
  param_1[0x39] = 7;
  param_1[0x38] = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  if (7 < (uint)param_1[0x32]) {
    FUN_0089120c(param_1[0x2d],uVar1);
  }
  param_1[0x32] = 7;
  param_1[0x31] = 0;
  *(undefined2 *)(param_1 + 0x2d) = 0;
  _eh_vector_destructor_iterator_(param_1 + 3,0x1c,6,FUN_004fa440);
  *param_1 = FoxUI::FXUIArchive::vftable;
  ExceptionList = local_10;
  return;
}

