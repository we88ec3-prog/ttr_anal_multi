
undefined4 FUN_00582400(int param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009294be;
  local_10 = ExceptionList;
  if ((*(int *)(param_1 + 0x30) != 0) && (*(int *)(param_1 + 0x5c) != 0)) {
    ExceptionList = &local_10;
    FUN_00542210(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (*(int *)(param_1 + 0x5c) != 0) {
      *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
      if ((uint)(*(int *)(param_1 + 0x54) * 4) <= *(uint *)(param_1 + 0x58)) {
        *(undefined4 *)(param_1 + 0x58) = 0;
      }
      iVar1 = *(int *)(param_1 + 0x5c) + -1;
      *(int *)(param_1 + 0x5c) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x58) = 0;
      }
    }
    FUN_0056c620();
    if ((DAT_00fb72a4 & 1) == 0) {
      DAT_00fb72a4 = DAT_00fb72a4 | 1;
      local_8 = 0;
      FUN_0049f850();
      _atexit((_func_4879 *)&LAB_00bccfe0);
      local_8 = 0xffffffff;
    }
    FUN_004a03f0(&DAT_00fb72a8,*(undefined4 *)(param_1 + 0x34));
    ExceptionList = local_10;
    return 1;
  }
  return 0;
}

