
void FUN_00770a80(void)

{
  char cVar1;
  uint uVar2;
  undefined **local_b0 [19];
  uint local_64;
  undefined4 local_54;
  uint local_50;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928713;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ed80(local_b0);
  local_8 = 0;
  FUN_0047f540();
  local_8._0_1_ = 1;
  cVar1 = FUN_0072f110(1);
  local_8 = (uint)local_8._1_3_ << 8;
  if (0xf < local_20) {
    FUN_0089120c(local_34,uVar2);
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = local_34 & 0xffffff00;
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64,uVar2);
    }
    local_50 = 0xf;
    local_54 = 0;
    local_64 = local_64 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_00770880(local_b0);
    local_8 = 0xffffffff;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64);
    }
    local_50 = 0xf;
    local_54 = 0;
    local_64 = local_64 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

