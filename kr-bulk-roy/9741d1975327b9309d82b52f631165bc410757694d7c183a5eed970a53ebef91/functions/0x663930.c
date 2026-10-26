
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00663930(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092cdae;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(local_14);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_8 = 0xffffffff;
  iVar2 = *(int *)(param_1 + 0x15c);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x15c) + 200))();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  uVar3 = DAT_00fe1c50;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  FUN_004f6a30(uVar3);
  uVar3 = FUN_004ed610();
  local_8 = 2;
  FUN_00757800(uVar3);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  uVar3 = DAT_00fe1c58;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 3;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  FUN_004f7370(uVar3);
  FUN_00757710();
  FUN_00757f20();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  sVar1 = DAT_00fe1c54;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 4;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  if (sVar1 != 0) {
    local_34 = ((int)sVar1 - 1U) / 6;
    FUN_0082ef00(&local_34);
  }
  iVar2 = *(int *)(param_1 + 0x100);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x100) + 200))();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  sVar1 = DAT_00fe1c54;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 5;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar2 = (int)sVar1;
  if ((iVar2 != 0x25) && (iVar2 != 0)) {
    local_38 = 0xc - (iVar2 - 1U) % 6;
    FUN_0082ef00(&local_38);
  }
  iVar2 = *(int *)(param_1 + 0x104);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x104) + 200))();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  sVar1 = DAT_00fe1c54;
  if ((_DAT_00fc1ca8 & 1) == 0) {
    _DAT_00fc1ca8 = _DAT_00fc1ca8 | 1;
    DAT_00fc1cac = 0;
    DAT_00fc1cb0 = 0;
    _DAT_00fc1cb4 = 0;
    _atexit((_func_4879 *)&LAB_00bce5a0);
  }
  FUN_0082b710(sVar1);
  FUN_00757710();
  (**(code **)(**(int **)(param_1 + 0x108) + 200))();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_007597b0(0);
  FUN_00757f20();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_007597b0(0);
  FUN_00757f20();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_007597b0(0);
  FUN_00757f20();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_007597b0(0);
  FUN_00757f20();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_007597b0(0);
  FUN_00757f20();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_007597b0(0);
  FUN_00757f20();
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_007597b0(0);
  FUN_00757f20();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

