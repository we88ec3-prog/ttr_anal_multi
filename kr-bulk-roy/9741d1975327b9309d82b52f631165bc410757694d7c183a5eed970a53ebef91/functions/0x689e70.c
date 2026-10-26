
void FUN_00689e70(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f51e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0046b6f0(100,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0046b6f0(200);
  FUN_0046b6f0(300);
  FUN_0046b6f0(400);
  iVar1 = *(int *)(in_ECX + 0x80);
  FUN_007444b0(0xbf6b);
  uVar2 = DAT_00f94394 & 1;
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  if (uVar2 == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_14 = 0x12;
  FUN_0082ef00(&local_14);
  uVar3 = FUN_00763360(L"Enchant01");
  *(undefined4 *)(in_ECX + 0xb4) = uVar3;
  uVar3 = FUN_00763360(L"Enchant02");
  *(undefined4 *)(in_ECX + 0xb8) = uVar3;
  uVar3 = FUN_00763360(L"Enchant03");
  *(undefined4 *)(in_ECX + 0xbc) = uVar3;
  uVar3 = FUN_00763360(L"Enchant04");
  *(undefined4 *)(in_ECX + 0xc0) = uVar3;
  uVar3 = FUN_00763360(L"Enchant05");
  *(undefined4 *)(in_ECX + 0xc4) = uVar3;
  uVar3 = FUN_00763360(L"Enchant06");
  *(undefined4 *)(in_ECX + 200) = uVar3;
  uVar3 = FUN_00763360(L"Enchant07");
  *(undefined4 *)(in_ECX + 0xcc) = uVar3;
  uVar3 = FUN_00763360(L"Enchant08");
  *(undefined4 *)(in_ECX + 0xd0) = uVar3;
  (**(code **)(**(int **)(in_ECX + 0x8c) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x88) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x84) + 0x94))(1);
  ExceptionList = local_10;
  return;
}

