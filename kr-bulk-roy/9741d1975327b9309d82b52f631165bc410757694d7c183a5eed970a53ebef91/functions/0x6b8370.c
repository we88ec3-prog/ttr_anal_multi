
void FUN_006b8370(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 *puVar2;
  int iVar3;
  int local_21c;
  int local_218;
  undefined1 local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f4dc;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0046b6f0(60000,local_14);
  FUN_0046b6f0(61000);
  FUN_0046b6f0(0x332c);
  FUN_0046b6f0(0x3390);
  FUN_0046b6f0(0x3458);
  FUN_0046b6f0(0x34bc);
  FUN_0046b6f0(0x3584);
  FUN_0046b6f0(0x35e8);
  FUN_006b99c0();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar3 = DAT_00f943ac;
  local_218 = 0x2f;
  FUN_0082ef00(&local_218);
  if (local_21c == *(int *)(iVar3 + 8)) {
    local_218 = 0;
  }
  else {
    local_218 = *(int *)(local_21c + 0x10);
  }
  iVar3 = 0;
  puVar2 = (undefined4 *)(in_ECX + 0xd0);
  do {
    FUN_0040aeb0(L"Num01_%d",iVar3);
    uVar1 = FUN_00763360(local_214);
    *puVar2 = uVar1;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 10);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_21c = 0x2e;
  FUN_0082ef00(&local_21c);
  uVar1 = FUN_00763360(L"Num_3");
  *(undefined4 *)(in_ECX + 0x90) = uVar1;
  uVar1 = FUN_00763360(L"Num_2");
  *(undefined4 *)(in_ECX + 0x94) = uVar1;
  uVar1 = FUN_00763360(L"Num_1");
  *(undefined4 *)(in_ECX + 0x98) = uVar1;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

