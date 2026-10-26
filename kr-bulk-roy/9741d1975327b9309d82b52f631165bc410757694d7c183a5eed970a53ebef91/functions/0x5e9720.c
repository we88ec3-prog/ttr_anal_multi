
/* WARNING: Removing unreachable block (ram,0x005e9997) */

void FUN_005e9720(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00926e30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_005e9f00(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 8);
  FUN_005e9fe0();
  FUN_005a9f40(in_ECX + 0xc);
  FUN_005ea0c0();
  FUN_005a9f40(in_ECX + 0x10);
  FUN_005ea1a0();
  FUN_005a9f40(in_ECX + 0x14);
  FUN_005ea280();
  FUN_005a9f40(in_ECX + 0x18);
  FUN_005ea360();
  FUN_005a9f40(in_ECX);
  FUN_005ea440();
  FUN_005a9f40(in_ECX + 4);
  FUN_005ea520();
  FUN_005a9f40(in_ECX + 0x1c);
  FUN_005ea600();
  FUN_005a9f40(in_ECX + 0x20);
  FUN_005ea6e0();
  FUN_005a9f40(in_ECX + 0x2c);
  FUN_005ea7c0();
  FUN_005a9f40(in_ECX + 0x30);
  FUN_005ea8a0();
  FUN_005a9f40(in_ECX + 0x34);
  FUN_005ea980();
  FUN_005a9f40(in_ECX + 0x38);
  FUN_005eaa60();
  FUN_005a9f40(in_ECX + 0x3c);
  puVar2 = (undefined4 *)(in_ECX + 0x24);
  FUN_005eab40();
  FUN_005a9f40(puVar2);
  FUN_005eac20();
  FUN_005a9f40(in_ECX + 0x28);
  FUN_005ead00();
  FUN_005a9f40(in_ECX + 0x40);
  FUN_005eade0();
  FUN_005a9f40(in_ECX + 0x44);
  puVar3 = (undefined4 *)(in_ECX + 0x48);
  FUN_005eaec0();
  FUN_005a9f40(puVar3);
  FUN_005eafa0();
  FUN_005a9f40(in_ECX + 0x4c);
  FUN_005eb080();
  FUN_005a9f40(in_ECX + 0x50);
  FUN_005eb160();
  FUN_005a9f40(in_ECX + 0x54);
  FUN_005eb240();
  FUN_005a9f40(in_ECX + 0x58);
  puVar1 = (undefined4 *)(in_ECX + 0x5c);
  FUN_005eb320();
  FUN_005a9f40(puVar1);
  iVar4 = 0;
  do {
    (**(code **)(**(int **)(in_ECX + iVar4 * 4) + 0x94))(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 9);
  iVar4 = 9;
  do {
    (**(code **)(*(int *)*puVar2 + 0x94))(1);
    (**(code **)(*(int *)*puVar1 + 0x70))(*puVar2);
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 5;
  do {
    (**(code **)(*(int *)*puVar3 + 0x94))(1);
    (**(code **)(*(int *)*puVar1 + 0x70))(*puVar3);
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  (**(code **)(*(int *)*puVar1 + 0x94))(1);
  FUN_0040b670(0);
  ExceptionList = local_10;
  return;
}

