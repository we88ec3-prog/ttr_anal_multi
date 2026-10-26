
void FUN_004b7790(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00930934;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
  }
  local_8 = 0xffffffff;
  local_38 = 0x76;
  FUN_005740f0(&local_38);
  if (local_34 != DAT_00fe5aec) {
    uVar3 = FUN_0040aff0(uVar2);
    local_8 = 1;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_004d6b30(uVar3);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

