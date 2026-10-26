
void FUN_0057fd00(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00916abe;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = Synopsis::CBookNode::vftable;
  uStack_7 = 0;
  if ((DAT_00fe1e1c & 1) == 0) {
    DAT_00fe1e1c = DAT_00fe1e1c | 1;
    local_8 = 2;
    uStack_7 = 0;
    FUN_007c30c0(uVar1);
    _atexit(FUN_00bcf1b0);
  }
  local_8 = 1;
  FUN_007c2a20();
  _local_8 = CONCAT31(uStack_7,3);
  FUN_0057ffd0(*(undefined4 *)param_1[0xb],(undefined4 *)param_1[0xb]);
  FUN_0089120c(param_1[0xb]);
  if (0xf < (uint)param_1[8]) {
    FUN_0089120c(param_1[3]);
  }
  param_1[8] = 0xf;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  ExceptionList = local_10;
  return;
}

