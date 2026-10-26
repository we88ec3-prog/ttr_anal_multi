
void FUN_006af2f0(void)

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
  FUN_006c0f40();
  FUN_0043c570(300);
  FUN_0043c570(0x578);
  FUN_0043c570(0x5dc);
  FUN_0043c570(0x6a4);
  FUN_0043c570(0x708);
  FUN_0043c570(0x898);
  FUN_0043c570(0x8fc);
  FUN_006afdc0();
  FUN_006afeb0();
  FUN_0043c570(0x14b4);
  FUN_0043c570(0x1518);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_14 = 0xc;
  FUN_0082ef00(&local_14);
  uVar1 = FUN_00763360(L"GvG_Result_Victory");
  *(undefined4 *)(in_ECX + 0xf4) = uVar1;
  uVar1 = FUN_00763360(L"GvG_Result_Defeat");
  *(undefined4 *)(in_ECX + 0xf8) = uVar1;
  uVar1 = FUN_00763360(L"GvG_Result_Draw");
  *(undefined4 *)(in_ECX + 0xfc) = uVar1;
  ExceptionList = local_10;
  return;
}

