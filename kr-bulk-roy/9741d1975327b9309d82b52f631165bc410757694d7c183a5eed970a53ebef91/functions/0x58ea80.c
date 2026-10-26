
/* WARNING: Removing unreachable block (ram,0x0058eb06) */

void FUN_0058ea80(undefined4 param_1,char param_2)

{
  uint uVar1;
  undefined4 unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e268;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00402160(L"false",5);
  local_8 = 0;
  if (param_2 != '\0') {
    FUN_00402160(L"true",4);
  }
  FUN_0058ec10(unaff_ESI,param_1);
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

