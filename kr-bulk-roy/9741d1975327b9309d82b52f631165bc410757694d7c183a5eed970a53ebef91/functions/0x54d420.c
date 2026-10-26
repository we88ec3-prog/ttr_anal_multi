
void FUN_0054d420(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_34 [4];
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093661a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_34;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  if (*(int *)(DAT_00fb76e8 + 0xa0) == *(int *)(DAT_00fb76e8 + 0xa4)) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    local_2c = *(undefined4 *)(param_1 + 0x38);
    FUN_0082ef00(&local_2c);
    if ((local_30 != DAT_00fab13c) && (*(int **)(local_30 + 0x10) != (int *)0x0)) {
      (**(code **)(**(int **)(local_30 + 0x10) + 0x50))(&local_28);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 2;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      iVar1 = DAT_00fb76e8;
      *(undefined4 *)(DAT_00fb76e8 + 0xc) = local_28;
      *(undefined4 *)(iVar1 + 0x10) = uStack_24;
      *(undefined4 *)(iVar1 + 0x14) = uStack_20;
      *(undefined4 *)(iVar1 + 0xcc) = 0;
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_34);
  return;
}

