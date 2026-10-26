
void FUN_00764000(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 auStack_c4 [3];
  char local_c1;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  uint local_b4;
  undefined4 local_a4;
  uint local_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009266c6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_c4;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff30;
  ExceptionList = &local_14;
  local_b8 = param_2;
  local_bc = param_4;
  FUN_0072ed80(local_98);
  local_c = 0;
  FUN_0047f540(param_3,uVar1);
  local_c._0_1_ = 1;
  local_c1 = FUN_0072f110(1);
  local_c = (uint)local_c._1_3_ << 8;
  if (0xf < local_a0) {
    FUN_0089120c(local_b4);
  }
  local_a0 = 0xf;
  local_a4 = 0;
  local_b4 = local_b4 & 0xffffff00;
  if (local_c1 == '\0') {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    uStack_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_00764520(local_c0,param_1,local_b8);
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    uStack_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_c4);
  return;
}

