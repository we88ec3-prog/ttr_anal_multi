
void FUN_00653a60(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f63e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0043c570(0x2b66);
  FUN_0043c570(0x2bca);
  FUN_0043c570(0x2c2e);
  FUN_0043c570(0x2c92);
  FUN_0043c570(0x2f4e);
  FUN_006ba750();
  FUN_0043c570(14000);
  FUN_00654210();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_14 = 0x36;
  FUN_0082ef00(&local_14);
  uVar1 = FUN_00763360(L"Rank_SS");
  *(undefined4 *)(in_ECX + 0x128) = uVar1;
  uVar1 = FUN_00763360(L"Rank_S");
  *(undefined4 *)(in_ECX + 0x124) = uVar1;
  uVar1 = FUN_00763360(L"Rank_A");
  *(undefined4 *)(in_ECX + 0x120) = uVar1;
  uVar1 = FUN_00763360(L"Rank_B");
  *(undefined4 *)(in_ECX + 0x11c) = uVar1;
  uVar1 = FUN_00763360(L"Rank_C");
  *(undefined4 *)(in_ECX + 0x118) = uVar1;
  uVar1 = FUN_00763360(L"Rank_D");
  *(undefined4 *)(in_ECX + 0x114) = uVar1;
  uVar1 = FUN_00763360(L"Rank_E");
  *(undefined4 *)(in_ECX + 0x110) = uVar1;
  uVar1 = FUN_00763360(L"Rank_F");
  *(undefined4 *)(in_ECX + 0x10c) = uVar1;
  ExceptionList = local_10;
  return;
}

