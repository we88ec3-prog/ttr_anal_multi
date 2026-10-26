
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0079d570(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int local_8;
  
  FUN_00515790(&param_1);
  if (local_8 != *(int *)(in_EAX + 4)) {
    iVar1 = *(int *)(local_8 + 0x10);
    param_1 = 0;
    if (*(uint *)(iVar1 + 0x4c) < 0x10) {
      iVar1 = iVar1 + 0x38;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x38);
    }
    if ((_DAT_00fc1690 & 1) == 0) {
      _DAT_00fc1690 = _DAT_00fc1690 | 1;
      _atexit((_func_4879 *)&DAT_00bce690);
    }
    iVar1 = FUN_007ac4c0(&DAT_00fc1694,iVar1);
    if (iVar1 != 0) {
      *(undefined4 *)(*(int *)(local_8 + 0x10) + 0x54) = param_1;
      return 1;
    }
  }
  return 0;
}

