
void FUN_00651bd0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092124e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_00652550();
  FUN_00652640();
  local_14 = (undefined4 *)(in_ECX + 0xf8);
  iVar3 = 0x2cf7;
  do {
    FUN_0043c570(iVar3 + -0xb);
    puVar1 = local_14;
    FUN_00615fc0(iVar3 + -1);
    (**(code **)(*(int *)*puVar1 + 0x198))(iVar3);
    iVar3 = iVar3 + 100;
    local_14 = puVar1 + 1;
  } while (iVar3 < 0x2e87);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_14 = (undefined4 *)0x2e;
  FUN_0082ef00(&local_14);
  uVar2 = FUN_00763360(L"Num_9");
  *(undefined4 *)(in_ECX + 0x118) = uVar2;
  uVar2 = FUN_00763360(L"Num_8");
  *(undefined4 *)(in_ECX + 0x11c) = uVar2;
  uVar2 = FUN_00763360(L"Num_7");
  *(undefined4 *)(in_ECX + 0x120) = uVar2;
  uVar2 = FUN_00763360(L"Num_6");
  *(undefined4 *)(in_ECX + 0x124) = uVar2;
  uVar2 = FUN_00763360(L"Num_5");
  *(undefined4 *)(in_ECX + 0x128) = uVar2;
  uVar2 = FUN_00763360(L"Num_4");
  *(undefined4 *)(in_ECX + 300) = uVar2;
  uVar2 = FUN_00763360(L"Num_3");
  *(undefined4 *)(in_ECX + 0x130) = uVar2;
  uVar2 = FUN_00763360(L"Num_2");
  *(undefined4 *)(in_ECX + 0x134) = uVar2;
  uVar2 = FUN_00763360(L"Num_1");
  *(undefined4 *)(in_ECX + 0x138) = uVar2;
  uVar2 = FUN_00763360(L"Num_0");
  *(undefined4 *)(in_ECX + 0x13c) = uVar2;
  ExceptionList = local_10;
  return;
}

