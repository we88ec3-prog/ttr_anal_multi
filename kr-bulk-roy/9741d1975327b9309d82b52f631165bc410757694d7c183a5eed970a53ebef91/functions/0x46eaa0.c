
void FUN_0046eaa0(uint *param_1)

{
  uint uVar1;
  uint in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921372;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = param_1[1];
  if ((in_ECX < uVar1) && (*param_1 <= in_ECX)) {
    if (uVar1 == param_1[2]) {
      FUN_0046ebd0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar1 = param_1[1];
    local_8 = 0;
  }
  else {
    if (uVar1 == param_1[2]) {
      FUN_0046ebd0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar1 = param_1[1];
    local_8 = 1;
  }
  if (uVar1 != 0) {
    FUN_0046f6b0(uVar1);
  }
  param_1[1] = param_1[1] + 0x40;
  ExceptionList = local_10;
  return;
}

