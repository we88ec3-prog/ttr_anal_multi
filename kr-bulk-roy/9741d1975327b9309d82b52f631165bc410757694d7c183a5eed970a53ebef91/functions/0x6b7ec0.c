
void FUN_006b7ec0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092124e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0046b6f0(0x44c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0046b6f0(0x4b0);
  FUN_0046b6f0(0x514);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_14 = 0;
  FUN_0082ef00(&local_14);
  uVar1 = FUN_00763360(L"MyNextEntry01");
  *(undefined4 *)(in_ECX + 0x8c) = uVar1;
  uVar1 = FUN_00763360(L"MyNextEntry02");
  *(undefined4 *)(in_ECX + 0x90) = uVar1;
  uVar1 = FUN_00763360(L"MyNextEntry03");
  *(undefined4 *)(in_ECX + 0x94) = uVar1;
  uVar1 = FUN_00763360(L"MyNextEntry04");
  *(undefined4 *)(in_ECX + 0x98) = uVar1;
  uVar1 = FUN_00763360(L"MyNextEntry05");
  *(undefined4 *)(in_ECX + 0x9c) = uVar1;
  uVar1 = FUN_00763360(L"MyNextEntry06");
  *(undefined4 *)(in_ECX + 0xa0) = uVar1;
  uVar1 = FUN_00763360(L"MyNextEntry07");
  *(undefined4 *)(in_ECX + 0xa4) = uVar1;
  uVar1 = FUN_00763360(L"MyNextEntry08");
  *(undefined4 *)(in_ECX + 0xa8) = uVar1;
  uVar1 = FUN_00763360(L"MyNextEntry09");
  *(undefined4 *)(in_ECX + 0xac) = uVar1;
  ExceptionList = local_10;
  return;
}

