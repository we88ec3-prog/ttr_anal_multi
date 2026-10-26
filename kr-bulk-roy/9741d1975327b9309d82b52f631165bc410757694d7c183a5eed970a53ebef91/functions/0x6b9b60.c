
void FUN_006b9b60(void)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  int local_218;
  undefined1 local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f48e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_0046b6f0(200,uVar1);
  local_218 = in_ECX + 0xa0;
  iVar3 = 800;
  do {
    FUN_0046b6f0(iVar3 + -500,uVar1);
    FUN_0046b6f0(iVar3);
    local_218 = local_218 + 4;
    iVar3 = iVar3 + 100;
  } while (iVar3 < 0x514);
  FUN_0046b6f0(0x514,uVar1);
  FUN_0046b6f0(0x578);
  FUN_006b7d70();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_218 = 0x2f;
  FUN_0082ef00(&local_218);
  iVar3 = 0;
  puVar4 = (undefined4 *)(in_ECX + 0xbc);
  do {
    FUN_0040aeb0(L"Num01_%d",iVar3);
    uVar2 = FUN_00763360(local_214);
    *puVar4 = uVar2;
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar3 < 10);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

