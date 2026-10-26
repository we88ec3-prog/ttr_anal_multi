
void FUN_00563fa0(void)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  int in_ECX;
  undefined4 ****ppppuVar4;
  undefined1 auStack_4c [4];
  int local_48;
  undefined4 *local_44;
  int local_40;
  int local_3c;
  undefined4 ***local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936422;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_4c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  local_40 = in_ECX;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 0;
    FUN_004f3d80(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c = 0xffffffff;
  local_44 = *(undefined4 **)(in_ECX + 0x34);
  FUN_0047fdf0(&local_44);
  if (local_48 != DAT_00fb74e4) {
    FUN_004f6e80();
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 1;
    FUN_004f3d80(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
  }
  local_48 = *(int *)(in_ECX + 0x34);
  local_44 = (undefined4 *)FUN_004f7df0();
  if (0xf < (uint)local_44[5]) {
    local_44 = (undefined4 *)*local_44;
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 2;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
  }
  local_48 = *(int *)(in_ECX + 0x34);
  FUN_0047fdf0(&local_48);
  if (local_3c != DAT_00fb74f4) {
    FUN_004f6e80();
  }
  if (*(int *)(in_ECX + 0x54) == 0) {
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_c = 9;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_c = 0xffffffff;
    }
    FUN_006d9580(&DAT_00fc0fc8,*(undefined4 *)(in_ECX + 0x34));
  }
  else {
    local_24 = 0xf;
    local_28 = 0;
    local_38[0] = (undefined4 ***)((uint)local_38[0] & 0xffffff00);
    FUN_00402a70("Sound/",6);
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    FUN_00401ed0(in_ECX + 0x44,0,0xffffffff);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 4;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c._0_1_ = 3;
    }
    sVar1 = DAT_00fb90ea;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 5;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c._0_1_ = 3;
    }
    local_48 = DAT_00fb935c;
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_c._0_1_ = 6;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_c._0_1_ = 3;
    }
    ppppuVar4 = (undefined4 ****)local_38[0];
    if (local_24 < 0x10) {
      ppppuVar4 = local_38;
    }
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_c._0_1_ = 7;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_c._0_1_ = 3;
    }
    local_3c = (int)sVar1;
    FUN_008fed10();
    FUN_006daa70();
    uVar2 = FUN_008fed10();
    FUN_006d9b30(&DAT_00fc0fc8,ppppuVar4,1,uVar2);
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_c._0_1_ = 8;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_c._0_1_ = 3;
    }
    FUN_006d9580(&DAT_00fc0fc8,*(undefined4 *)(local_40 + 0x34));
    local_c = 0xffffffff;
    if (0xf < local_24) {
      FUN_0089120c(local_38[0]);
    }
    local_24 = 0xf;
    local_28 = 0;
    local_38[0] = (undefined4 ***)((uint)local_38[0] & 0xffffff00);
    in_ECX = local_40;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 10;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  *(undefined4 *)(in_ECX + 0x34) = DAT_00fab178;
  FUN_007c1e00(0);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0xb;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  FUN_00798370();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_4c);
  return;
}

