
void FUN_00557e10(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  float10 fVar4;
  undefined1 auStack_74 [4];
  int *local_70;
  int local_6c [2];
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  uint local_54;
  undefined4 uStack_44;
  uint local_40;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00939bd8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  ExceptionList = &local_14;
  local_70 = param_1;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xffffff80);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_c = 0xffffffff;
  iVar1 = FUN_005c7190();
  if (iVar1 != 0) {
    local_64 = param_2;
    FUN_0082ef00(&local_64);
    if ((local_6c[0] != *(int *)(iVar1 + 0xc)) && (*(int *)(local_6c[0] + 0x10) != 0)) {
      FUN_00557de0();
      local_c = 1;
      if ((DAT_00fcde40 & 1) == 0) {
        DAT_00fcde40 = DAT_00fcde40 | 1;
        local_c._0_1_ = 2;
        local_c._1_3_ = 0;
        FUN_00736880();
        _atexit(FUN_00bce6f0);
        local_c = CONCAT31(local_c._1_3_,1);
      }
      FUN_00736f40(local_6c);
      if (local_6c[0] == DAT_00fcde34) {
        iVar1 = 0;
      }
      else {
        (**(code **)(**(int **)(local_6c[0] + 0x28) + 4))();
        iVar1 = *(int *)(local_6c[0] + 0x28);
      }
      local_c = 0xffffffff;
      *param_1 = iVar1;
      if (7 < local_40) {
        FUN_0089120c(local_54);
      }
      local_40 = 7;
      uStack_44 = 0;
      local_54 = local_54 & 0xffff0000;
      if (*param_1 == 0) {
        uVar2 = FUN_00557de0();
        local_c = 3;
        if ((DAT_00fcde40 & 1) == 0) {
          DAT_00fcde40 = DAT_00fcde40 | 1;
          local_c._0_1_ = 4;
          local_c._1_3_ = 0;
          FUN_00736880();
          _atexit(FUN_00bce6f0);
          local_c = CONCAT31(local_c._1_3_,3);
        }
        iVar1 = FUN_00736b00(uVar2);
        local_c = 0xffffffff;
        *local_70 = iVar1;
        if (7 < uStack_24) {
          FUN_0089120c(uStack_38);
        }
        uStack_24 = 7;
        uStack_28 = 0;
        uStack_38 = uStack_38 & 0xffff0000;
        param_1 = local_70;
      }
      iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      if (iVar1 != 0) {
        uStack_60 = *(undefined4 *)(iVar1 + 0xa0);
        uStack_5c = *(undefined4 *)(iVar1 + 0xa4);
        fStack_58 = *(float *)(iVar1 + 0xa8);
        if ((*(int *)(iVar1 + 0x15c) == 0) || (*(int *)(iVar1 + 0x370) == 0)) {
          local_70 = (int *)0x0;
        }
        else {
          fVar4 = (float10)FUN_007a7100();
          local_70 = (int *)(float)fVar4;
        }
        fStack_58 = (float)local_70 + 0.5 + fStack_58;
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_c = 5;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_c = 0xffffffff;
        }
        piVar3 = (int *)FUN_0079a6b0(&DAT_00fb76a8,&uStack_60);
        param_1[1] = *piVar3;
        param_1[2] = piVar3[1];
        param_1[1] = (int)((float)param_1[1] - 12.0);
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

