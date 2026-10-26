
void FUN_006d8c40(undefined4 param_1)

{
  int in_ECX;
  uint uStack_88;
  ULONG_PTR local_78;
  char *local_74;
  undefined4 local_70;
  undefined4 local_6c;
  char local_68;
  undefined1 local_67 [67];
  uint local_24;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00d61f20 ^ 0xc85918;
  uStack_88 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&uStack_88;
  ExceptionList = &local_14;
  local_68 = '\0';
  local_24 = uStack_88;
  _memset(local_67,0,0x3f);
  if (in_ECX == -1) {
    _sprintf_s(&local_68,0x40,"%s");
  }
  else {
    _sprintf_s(&local_68,0x40,"%s%d");
  }
  local_78 = 0x1000;
  local_74 = &local_68;
  local_70 = param_1;
  local_6c = 0;
  local_8 = 0;
  RaiseException(0x406d1388,0,4,&local_78);
  local_8 = 0xfffffffe;
  ExceptionList = local_14;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffffc);
  return;
}

