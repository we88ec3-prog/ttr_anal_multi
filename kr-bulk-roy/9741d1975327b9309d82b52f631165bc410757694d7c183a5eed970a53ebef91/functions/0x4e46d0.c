
undefined4 FUN_004e46d0(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  int in_ECX;
  undefined2 *puVar3;
  int iVar4;
  undefined1 local_70 [4];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  _RTL_CRITICAL_SECTION local_2c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917558;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(byte *)(param_1 + 2) < 10) {
    local_14 = (uint)*(byte *)(param_1 + 2) * 0x210 + *(int *)(in_ECX + 0x6924);
  }
  else {
    local_14 = 0;
  }
  iVar4 = local_14;
  FUN_004d4230(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (param_2 < 3) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 - 3 >> 2;
  }
  if (param_2 != 0) {
    puVar3 = (undefined2 *)(param_1 + 3);
    do {
      FUN_0041d460(*puVar3,*(undefined1 *)(puVar3 + 1));
      puVar3 = puVar3 + 2;
      param_2 = param_2 - 1;
      iVar4 = local_14;
    } while (param_2 != 0);
  }
  iVar2 = FUN_00404ba0();
  if ((*(byte *)(param_1 + 2) < 10) &&
     (param_1 = (uint)*(byte *)(param_1 + 2) * 0x210 + *(int *)(iVar2 + 0x6924), param_1 != 0)) {
    param_1 = param_1 + 0x1d4;
  }
  else {
    param_1 = 0;
  }
  FUN_004e1070(param_1);
  FUN_004d3610(*(undefined4 *)(*(int *)(param_1 + 0x14) + 4));
  *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_004d3610(*(undefined4 *)(*(int *)(param_1 + 0x14) + 4));
  *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  InitializeCriticalSectionAndSpinCount(&local_2c,4000);
  local_8 = 0;
  FUN_0041d5f0(iVar4 + 0xfc,local_70);
  bVar1 = *(byte *)((*(char *)(iVar4 + 0x1f6) != '\0') + 500 + iVar4);
  if ((bVar1 < 7) && (iVar4 = iVar4 + 0x110 + (uint)bVar1 * 0x1c, iVar4 != 0)) {
    FUN_0041d5f0(iVar4,local_70);
  }
  FUN_00825fa0(param_1,local_70);
  FUN_0081b6a0();
  ExceptionList = local_10;
  return 0;
}

