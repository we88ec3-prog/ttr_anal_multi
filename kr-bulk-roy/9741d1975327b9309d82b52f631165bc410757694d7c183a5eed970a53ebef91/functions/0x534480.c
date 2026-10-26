
void FUN_00534480(void)

{
  uint uVar1;
  undefined1 auStack_9c [4];
  undefined **local_98 [17];
  char local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092335b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff58;
  ExceptionList = &local_14;
  FUN_0072ed80(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    FUN_0072e360(uVar1);
    FUN_00538320(&DAT_00fe1bec);
  }
  local_98[0] = TiXmlDocument::vftable;
  local_c = 0xffffffff;
  if (0xf < local_38) {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}

