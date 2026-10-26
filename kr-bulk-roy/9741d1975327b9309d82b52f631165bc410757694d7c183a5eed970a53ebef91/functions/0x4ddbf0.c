
void FUN_004ddbf0(int param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  undefined4 *puVar5;
  uint local_cc;
  int local_c8;
  uint local_c4;
  undefined4 local_b4;
  uint local_b0;
  uint local_a8;
  undefined4 local_98;
  uint local_94;
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929bf2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_cc;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff28;
  ExceptionList = &local_14;
  *(uint *)(in_ECX + 0x5eac) = (uint)*(byte *)(param_1 + 3);
  *(uint *)(in_ECX + 0x5eb0) = (uint)*(byte *)(param_1 + 4);
  if (*(char *)(param_1 + 2) == '\0') {
    if (param_2 < 5) {
      uVar4 = 0;
    }
    else {
      uVar4 = param_2 - 5 >> 2;
    }
    local_b0 = 7;
    local_b4 = 0;
    local_c4 = local_c4 & 0xffff0000;
    FUN_00402160(&DAT_00bed1fc,0);
    local_c._0_1_ = 0;
    local_c._1_3_ = 0;
    if (uVar4 != 0) {
      puVar5 = (undefined4 *)(param_1 + 5);
      local_cc = uVar4;
      do {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c._0_1_ = 1;
          FUN_004f3d80(uVar2);
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c._0_1_ = 0;
        }
        FUN_004f6a30(*puVar5);
        uVar3 = FUN_004ed610();
        local_c._0_1_ = 2;
        FUN_004041f0(uVar3,0,0xffffffff);
        local_c._0_1_ = 0;
        if (7 < local_94) {
          FUN_0089120c(local_a8);
        }
        puVar5 = puVar5 + 1;
        local_cc = local_cc - 1;
      } while (local_cc != 0);
    }
    FUN_007572f0(&DAT_00bed1fc);
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 4;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_c._0_1_ = 3;
    local_cc = 0x51;
    FUN_005740f0(&local_cc);
    if (local_c8 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar3 = FUN_004ed610();
    local_c._0_1_ = 5;
    FUN_007574a0(uVar3);
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c._0_1_ = 7;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    local_c._0_1_ = 6;
    FUN_007531a0(&DAT_00f94810,local_8c,local_54,0,0);
    local_c = CONCAT31(local_c._1_3_,5);
    FUN_00757640(local_8c);
    if (7 < local_94) {
      FUN_0089120c(local_a8);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8 = local_a8 & 0xffff0000;
    local_c = local_c & 0xffffff00;
    FUN_00757640(local_54);
    if (7 < local_b0) {
      FUN_0089120c(local_c4);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_cc);
  return;
}

