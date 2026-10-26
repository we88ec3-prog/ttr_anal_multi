
undefined4 FUN_006071b0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946c2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  FUN_008438c0(&param_1);
  if (((in_ECX != DAT_00f8d91c) && (*(int *)(in_ECX + 0x10) != 0)) &&
     (iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + 0x60), iVar1 != 0)) {
    *(undefined4 *)(unaff_ESI + 0x120) = *(undefined4 *)(iVar1 + 8);
    FUN_00607550();
    ExceptionList = local_10;
    return 1;
  }
  ExceptionList = local_10;
  return 0;
}

