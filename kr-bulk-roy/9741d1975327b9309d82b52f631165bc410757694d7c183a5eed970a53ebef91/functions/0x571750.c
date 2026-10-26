
void FUN_00571750(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_58;
  int *local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091de7a;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = param_1;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(local_14);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_005c7190();
  if (iVar1 != 0) {
    local_58 = param_2;
    FUN_0082ef00(&local_58);
    if ((local_50 != *(int *)(iVar1 + 0xc)) && (*(int *)(local_50 + 0x10) != 0)) {
      FUN_00557de0();
      local_8 = 1;
      if ((DAT_00fcde40 & 1) == 0) {
        DAT_00fcde40 = DAT_00fcde40 | 1;
        local_8._0_1_ = 2;
        local_8._1_3_ = 0;
        FUN_00736880();
        _atexit(FUN_00bce6f0);
        local_8 = CONCAT31(local_8._1_3_,1);
      }
      FUN_00736f40(&local_50);
      if (local_50 == DAT_00fcde34) {
        iVar1 = 0;
      }
      else {
        (**(code **)(**(int **)(local_50 + 0x28) + 4))();
        iVar1 = *(int *)(local_50 + 0x28);
      }
      local_8 = 0xffffffff;
      *param_1 = iVar1;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      if (*param_1 == 0) {
        uVar2 = FUN_00557de0();
        local_8 = 3;
        if ((DAT_00fcde40 & 1) == 0) {
          DAT_00fcde40 = DAT_00fcde40 | 1;
          local_8._0_1_ = 4;
          local_8._1_3_ = 0;
          FUN_00736880();
          _atexit(FUN_00bce6f0);
          local_8 = CONCAT31(local_8._1_3_,3);
        }
        iVar1 = FUN_00736b00(uVar2);
        *local_54 = iVar1;
        if (7 < local_38) {
          FUN_0089120c(local_4c);
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

