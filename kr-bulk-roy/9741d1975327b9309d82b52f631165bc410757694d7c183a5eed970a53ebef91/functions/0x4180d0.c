
void FUN_004180d0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912f8e;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 0x1b4) - *(int *)(param_1 + 0x1b0) >> 2 <= in_ECX) {
    return;
  }
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x1b0) + in_ECX * 4);
  if (puVar1 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    iVar2 = FUN_0051d700(*puVar1);
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 8);
      if ((((0x2a < iVar2 - 1U) || (iVar3 = FUN_00520f40(), iVar3 == 0)) && (iVar2 != 0x26)) &&
         (iVar2 != 0x27)) {
        ExceptionList = local_10;
        return;
      }
      FUN_004054c0();
      FUN_0058b0a0(0xf43ba,*puVar1);
      ExceptionList = local_10;
      return;
    }
    ExceptionList = local_10;
    return;
  }
  return;
}

