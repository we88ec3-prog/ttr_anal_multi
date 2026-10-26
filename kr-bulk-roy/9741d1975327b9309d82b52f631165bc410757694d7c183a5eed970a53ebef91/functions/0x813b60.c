
void FUN_00813b60(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined **local_c8 [19];
  uint local_7c;
  undefined4 local_6c;
  uint local_68;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a44b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_c8);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    local_c8[0] = TiXmlDocument::vftable;
    if (0xf < local_68) {
      FUN_0089120c(local_7c);
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = local_7c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_0072e360(uVar2);
    iVar3 = FUN_0072e360();
    while (iVar3 != 0) {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00402a70(&DAT_00c0d66c,4);
      local_8._0_1_ = 1;
      FUN_0072ecf0(&DAT_00bf2375);
      local_8._0_1_ = 3;
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      FUN_00813d60(param_1);
      iVar3 = FUN_0072e3c0();
      local_8 = (uint)local_8._1_3_ << 8;
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
    }
    local_8 = 0xffffffff;
    local_c8[0] = TiXmlDocument::vftable;
    if (0xf < local_68) {
      FUN_0089120c(local_7c);
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = local_7c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

