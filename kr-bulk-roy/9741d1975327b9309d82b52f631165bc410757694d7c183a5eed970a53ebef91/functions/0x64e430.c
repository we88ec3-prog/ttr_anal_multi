
void FUN_0064e430(int param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  undefined1 auStack_3c [4];
  undefined4 auStack_38 [4];
  int iStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d820;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_3c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0;
    FUN_0054f850(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_c = 0xffffffff;
  if (*(char *)(param_1 + 0x110) != DAT_00fb934d) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 1;
      FUN_0054f850(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_c = 0xffffffff;
    bVar5 = DAT_00fb934d != '\0';
    *(bool *)(param_1 + 0x110) = bVar5;
    if (bVar5) {
      uVar2 = FUN_0064e8a0();
      *(undefined1 *)(param_1 + 0x110) = uVar2;
    }
    FUN_0064e6c0(*(undefined1 *)(param_1 + 0x110));
  }
  if ((*(uint *)(*(int *)(param_1 + 0xf8) + 0x28) >> 8 & 1) != 0) {
    (**(code **)(**(int **)(param_1 + 0xf0) + 0xcc))();
  }
  if ((*(uint *)(*(int *)(param_1 + 0xf4) + 0x28) >> 8 & 1) != 0) {
    FUN_0064f2c0();
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 2;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  uVar1 = DAT_00fab178;
  if ((DAT_00fc1710 & 1) == 0) {
    DAT_00fc1710 = DAT_00fc1710 | 1;
    local_c = 3;
    FUN_0082a2a0();
    _atexit((_func_4879 *)&LAB_00bce440);
    local_c = 0xffffffff;
  }
  FUN_0082a6a0(uVar1);
  local_c = 4;
  if (iStack_28 != 0) {
    if (*(uint *)(param_1 + 0x128) < 8) {
      iVar4 = param_1 + 0x114;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x114);
    }
    iVar4 = FUN_0044df20(0,iVar4,*(undefined4 *)(param_1 + 0x124));
    if (iVar4 != 0) {
      FUN_004026e0(auStack_38,0,0xffffffff);
      FUN_00757800(auStack_38);
    }
  }
  if (7 < uStack_24) {
    FUN_0089120c(auStack_38[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_3c);
  return;
}

