
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007ba380(undefined4 param_1)

{
  float fVar1;
  DWORD DVar2;
  uint uVar3;
  DWORD DVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  undefined1 local_30 [28];
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00935138;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  uVar6 = 0;
  if (*(int *)(in_ECX + 0x3c) != 0) {
    FUN_008380b0(uVar3);
    local_c._0_1_ = 0;
    local_c._1_3_ = 0;
    uVar5 = *(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2;
    if (DAT_00fba83c == 0) {
      FUN_008380b0(uVar3);
      local_c._0_1_ = 1;
      if (uVar5 != 0) {
        do {
          FUN_007e42f0();
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5);
      }
      local_c._0_1_ = 0;
      FUN_00837fd0();
      PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c._0_1_ = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c._0_1_ = 0;
    }
    if (DAT_00fba840 == 0) {
      FUN_007c9190(local_30,400,300,800,600);
      if (*(int *)(in_ECX + 0x40) != 0) {
        FUN_008380b0(uVar3);
        local_c._0_1_ = 3;
        FUN_007e7240(local_30);
        local_c._0_1_ = 0;
        FUN_00837fd0();
        PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
      }
      FUN_008380b0();
      uVar3 = 0;
      local_c._0_1_ = 4;
      if (uVar5 != 0) {
        do {
          FUN_007e43d0(*(undefined4 *)(*(int *)(in_ECX + 0x7c) + uVar3 * 4),local_30);
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar5);
      }
      local_c._0_1_ = 0;
      FUN_00837fd0();
      PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c._0_1_ = 9;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c._0_1_ = 0;
    }
    FUN_00798090();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c._0_1_ = 10;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c._0_1_ = 0;
    }
    FUN_00799d20(&DAT_00fb76a8,param_1);
    FUN_008380b0();
    local_c = CONCAT31(local_c._1_3_,0xb);
    if ((_DAT_00fe7220 & 1) == 0) {
      _DAT_00fe7220 = _DAT_00fe7220 | 1;
      DAT_00fe721c = timeGetTime();
    }
    DVar4 = timeGetTime();
    DVar2 = DAT_00fe721c;
    if (DAT_00fe721c + 0x1e < DVar4) {
      fVar1 = (float)(int)(DVar4 - DAT_00fe721c);
      if ((int)(DVar4 - DAT_00fe721c) < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      uVar3 = 0;
      DVar2 = DVar4;
      if (uVar5 != 0) {
        do {
          FUN_007e4450(fVar1 * 0.001);
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar5);
      }
    }
    DAT_00fe721c = DVar2;
    local_c = local_c & 0xffffff00;
    FUN_00837fd0();
    PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
    if (DAT_00fba83c == 0) {
      FUN_008380b0();
      uVar3 = 0;
      local_c._0_1_ = 0xc;
      if (uVar5 != 0) {
        do {
          FUN_007e42f0();
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar5);
      }
      local_c = (uint)local_c._1_3_ << 8;
      FUN_00837fd0();
      PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
    }
    if ((*(int *)(in_ECX + 0x40) != 0) && (DAT_00fba83c == 0)) {
      FUN_007e7600();
    }
    FUN_007e0d40(param_1);
    FUN_00837fd0();
    PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
  }
  ExceptionList = local_14;
  return;
}

