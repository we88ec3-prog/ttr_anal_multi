
undefined4 FUN_004e7c10(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 in_ECX;
  int iVar3;
  undefined1 local_20 [4];
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009442bc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c = 0xffffffff;
  FUN_008438c0(local_20);
  if ((local_1c != DAT_00fb7594) && (*(int *)(*(int *)(local_1c + 0x10) + 0x1c) != 0)) {
    iVar1 = FUN_004e79c0(param_1,in_ECX);
    if ((*(int *)(iVar1 + 0x2c) == 0) && (*(int *)(iVar1 + 0x28) != 0)) {
      iVar3 = iVar1 + 8;
      iVar2 = iVar3;
      FUN_0049b2a0(iVar3);
      iVar2 = FUN_00736c70(iVar2);
      if (iVar2 == 0) {
        FUN_0049b2a0(iVar3);
        iVar2 = FUN_00736b00(iVar3);
      }
      *(int *)(iVar1 + 0x2c) = iVar2;
    }
    ExceptionList = local_14;
    return *(undefined4 *)(iVar1 + 0x2c);
  }
  ExceptionList = local_14;
  return 0;
}

