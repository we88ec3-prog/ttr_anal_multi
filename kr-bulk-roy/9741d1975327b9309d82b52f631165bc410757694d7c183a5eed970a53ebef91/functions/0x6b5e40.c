
void FUN_006b5e40(void)

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
  FUN_0043c570(11000);
  FUN_0043c570(0x2f4e);
  FUN_0043c570(0x3336);
  FUN_0043c570(0x339a);
  FUN_0043c570(0x33fe);
  FUN_0043c570(0x3462);
  FUN_006b6490();
  FUN_004a6710();
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
  *(undefined4 *)(in_ECX + 0x14c) = uVar1;
  uVar1 = FUN_00763360(L"Rank_S");
  *(undefined4 *)(in_ECX + 0x148) = uVar1;
  uVar1 = FUN_00763360(L"Rank_A");
  *(undefined4 *)(in_ECX + 0x144) = uVar1;
  uVar1 = FUN_00763360(L"Rank_B");
  *(undefined4 *)(in_ECX + 0x140) = uVar1;
  uVar1 = FUN_00763360(L"Rank_C");
  *(undefined4 *)(in_ECX + 0x13c) = uVar1;
  uVar1 = FUN_00763360(L"Rank_D");
  *(undefined4 *)(in_ECX + 0x138) = uVar1;
  uVar1 = FUN_00763360(L"Rank_E");
  *(undefined4 *)(in_ECX + 0x134) = uVar1;
  uVar1 = FUN_00763360(L"Rank_F");
  *(undefined4 *)(in_ECX + 0x130) = uVar1;
  ExceptionList = local_10;
  return;
}

