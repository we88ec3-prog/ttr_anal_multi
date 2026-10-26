
void FUN_004e5dc0(int param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009368d8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (*(char *)(param_1 + 2) == '\0') {
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 3;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
    }
    local_8 = 0xffffffff;
    local_50 = 0xd;
    FUN_005740f0(&local_50);
    if (local_54 == DAT_00fe5aec) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar3 = FUN_004068f0();
    local_8 = 4;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 5;
      local_8._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = CONCAT31(local_8._1_3_,4);
    }
    FUN_004d6b30(uVar3);
  }
  else {
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
    }
    local_8 = 0xffffffff;
    local_54 = 0xc;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5aec) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_004068f0(uVar2);
    local_8 = 1;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_004d6840(&DAT_00fb11e8);
    local_4c = local_30;
    local_38 = local_1c;
  }
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

