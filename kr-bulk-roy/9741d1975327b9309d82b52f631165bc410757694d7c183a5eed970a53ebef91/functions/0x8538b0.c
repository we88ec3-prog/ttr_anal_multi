
void FUN_008538b0(int param_1)

{
  int in_ECX;
  uint uStack_44;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090e0f9;
  local_10 = ExceptionList;
  uStack_44 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  local_18 = param_1;
  uStack_7 = 0;
  for (; in_ECX != 0; in_ECX = in_ECX + -1) {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_24 = 0;
    local_20 = 0;
    local_8 = 2;
    if (param_1 != 0) {
      local_1c = param_1;
      FUN_0062d9b0(&local_34);
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    param_1 = param_1 + 0x18;
  }
  ExceptionList = local_10;
  return;
}

