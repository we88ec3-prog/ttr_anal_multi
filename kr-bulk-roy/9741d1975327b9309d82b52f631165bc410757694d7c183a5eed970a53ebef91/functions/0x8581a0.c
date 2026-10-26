
void FUN_008581a0(int param_1)

{
  int in_ECX;
  uint uStack_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00908f69;
  local_10 = ExceptionList;
  uStack_40 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_40;
  ExceptionList = &local_10;
  local_18 = param_1;
  uStack_7 = 0;
  for (; in_ECX != 0; in_ECX = in_ECX + -1) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_20 = 0;
    local_8 = 2;
    if (param_1 != 0) {
      local_1c = param_1;
      FUN_0052f3b0(param_1,&local_30);
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    param_1 = param_1 + 0x14;
  }
  ExceptionList = local_10;
  return;
}

