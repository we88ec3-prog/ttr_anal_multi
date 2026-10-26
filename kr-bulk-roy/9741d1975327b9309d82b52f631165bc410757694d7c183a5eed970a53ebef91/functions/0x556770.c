
void FUN_00556770(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int local_64;
  byte local_60;
  int local_5c;
  undefined4 local_58;
  uint local_44;
  uint local_3c;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_20;
  float local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ecf8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00f8d9a4 & 1;
  *param_1 = in_ECX;
  iVar2 = in_ECX[0x47];
  if (uVar1 == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(local_14);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  local_64 = iVar2;
  FUN_008438c0(&local_64);
  if ((local_5c != DAT_00f8d91c) && (iVar2 = *(int *)(local_5c + 0x10), iVar2 != 0)) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 1;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    local_5c = *(int *)(iVar2 + 0x20);
    iVar2 = FUN_005c7190();
    if (((iVar2 != 0) && (FUN_0082ef00(&local_5c), local_64 != *(int *)(iVar2 + 0xc))) &&
       (*(int *)(local_64 + 0x10) != 0)) {
      FUN_00557de0();
      local_8 = 2;
      if ((DAT_00fcde40 & 1) == 0) {
        DAT_00fcde40 = DAT_00fcde40 | 1;
        local_8._0_1_ = 3;
        local_8._1_3_ = 0;
        FUN_00736880();
        _atexit(FUN_00bce6f0);
        local_8 = CONCAT31(local_8._1_3_,2);
      }
      FUN_00736f40(&local_5c);
      iVar2 = local_5c;
      if (local_5c == DAT_00fcde34) {
        uVar3 = 0;
      }
      else {
        (**(code **)(**(int **)(local_5c + 0x28) + 4))();
        uVar3 = *(undefined4 *)(iVar2 + 0x28);
      }
      local_8 = 0xffffffff;
      param_1[1] = uVar3;
      if (7 < local_44) {
        FUN_0089120c(local_58);
      }
      if (param_1[1] == 0) {
        uVar3 = FUN_00557de0();
        local_8 = 4;
        FUN_0049b2a0(uVar3);
        uVar3 = FUN_00736b00(uVar3);
        local_8 = 0xffffffff;
        param_1[1] = uVar3;
        if (7 < local_28) {
          FUN_0089120c(local_3c);
        }
        local_28 = 7;
        local_2c = 0;
        local_3c = local_3c & 0xffff0000;
      }
    }
  }
  local_60 = FUN_0089289d();
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  uVar1 = DAT_00fb79e8 & 1;
  param_1[9] = (&DAT_00fb7c20)[local_60];
  if (uVar1 == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 5;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  uVar3 = (**(code **)(*in_ECX + 0x4c))();
  FUN_0079b910(&DAT_00fb76a8,uVar3);
  param_1[2] = local_20;
  param_1[3] = local_1c - 32.0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

