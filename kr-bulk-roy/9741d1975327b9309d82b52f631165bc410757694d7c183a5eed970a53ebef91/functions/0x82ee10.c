
void ** FUN_0082ee10(uint *param_1)

{
  void **ppvVar1;
  void **ppvVar2;
  void **in_ECX;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921372;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ppvVar1 = (void **)param_1[1];
  ppvVar2 = ExceptionList;
  if ((in_ECX < ppvVar1) && (ppvVar2 = (void **)*param_1, ppvVar2 <= in_ECX)) {
    if (ppvVar1 == (void **)param_1[2]) {
      FUN_0082f020(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    ppvVar2 = (void **)((((int)in_ECX - (int)ppvVar2) / 0x38) * 7);
    uVar3 = param_1[1];
    local_8 = 0;
  }
  else {
    if (ppvVar1 == (void **)param_1[2]) {
      ppvVar2 = (void **)FUN_0082f020(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar3 = param_1[1];
    local_8 = 1;
  }
  if (uVar3 != 0) {
    ppvVar2 = (void **)FUN_0082f2d0();
  }
  param_1[1] = param_1[1] + 0x38;
  ExceptionList = local_10;
  return ppvVar2;
}

