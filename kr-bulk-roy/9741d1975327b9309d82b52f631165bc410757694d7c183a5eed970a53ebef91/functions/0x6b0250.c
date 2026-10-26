
void FUN_006b0250(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 local_21c [2];
  undefined1 local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f48e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00755e50(local_14);
  FUN_006069c0();
  FUN_006b0ac0();
  FUN_0043dd20();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_21c[0] = 0;
  FUN_0082ef00(local_21c);
  iVar1 = 0;
  puVar3 = (undefined4 *)(in_ECX + 0x120);
  do {
    iVar1 = iVar1 + 1;
    FUN_0040aeb0(L"BotCha%02d",iVar1);
    uVar2 = FUN_00763360(local_214);
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
  } while (iVar1 < 9);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

