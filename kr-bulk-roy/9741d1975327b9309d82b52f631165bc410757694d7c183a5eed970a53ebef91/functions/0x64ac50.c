
void FUN_0064ac50(int param_1)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00946364;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  _Dst = *(void **)(param_1 + 0x114);
  if (_Dst != *(void **)(param_1 + 0x118)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x118),0);
    *(void **)(param_1 + 0x118) = _Dst;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x108) + 0x28) >> 9 & 1) == 0) {
    FUN_0064a790(uVar1);
  }
  else {
    if ((DAT_00fb725c & 1) == 0) {
      DAT_00fb725c = DAT_00fb725c | 1;
      local_c = 0;
      FUN_004a79a0();
      _atexit((_func_4879 *)&DAT_00bccf80);
      local_c = 0xffffffff;
    }
    FUN_004462a0();
    local_c = 1;
    piVar4 = local_28;
    for (iVar2 = local_24 - (int)local_28 >> 2; iVar2 != 0; iVar2 = iVar2 + -1) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c._1_3_ = (undefined3)((uint)local_c >> 8);
        local_c._0_1_ = 2;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = CONCAT31(local_c._1_3_,1);
      }
      uVar1 = FUN_004a7810(*piVar4);
      iVar3 = FUN_004d43d0();
      if ((int)(uVar1 & 0xff) <= iVar3) {
        if (*(char *)(*piVar4 + 9) == '\0') {
          FUN_004a8680();
        }
        else {
          FUN_0044a480((undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x114));
        }
      }
      piVar4 = piVar4 + 1;
    }
    local_c = 0xffffffff;
    if (local_28 != (int *)0x0) {
      FUN_0089120c(local_28);
    }
  }
  FUN_0064a8e0(param_1);
  FUN_00749920(*(undefined4 *)(param_1 + 0x10c));
  (**(code **)(**(int **)(param_1 + 0x10c) + 200))();
  ExceptionList = local_14;
  return;
}

