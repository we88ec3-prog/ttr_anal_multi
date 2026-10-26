
void FUN_00602430(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 *puVar4;
  int unaff_EDI;
  undefined1 auStack_9c [20];
  undefined4 uStack_88;
  undefined2 *puStack_84;
  undefined1 auStack_80 [12];
  undefined4 uStack_74;
  int local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  undefined1 *local_40;
  int local_3c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093e79e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_50;
  ExceptionList = &local_14;
  local_3c = param_1;
  *(undefined2 *)(unaff_EDI + 0x158) = 0;
  FUN_00402160();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if ((in_ECX != 1) || (DAT_00f94300 + 0x16f8 == 0)) goto LAB_00602719;
  if (99 < param_1 - 1U) {
    FUN_006edb60();
    goto LAB_00602719;
  }
  puVar4 = (undefined1 *)(param_1 * 0x20 + DAT_00f94300 + 0x16f8);
  local_40 = puVar4;
  if (((*(int *)(puVar4 + 0xc) == 0) || (*(int *)(puVar4 + 8) == 0)) ||
     (puVar4 == (undefined1 *)0x0)) goto LAB_00602719;
  local_4c = *(undefined1 **)(puVar4 + 0x10);
  local_48 = *(undefined4 *)(puVar4 + 0x14);
  iVar1 = FUN_00409560();
  FUN_004dd400();
  if (local_50 == *(int *)(iVar1 + 4)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(local_50 + 0x18);
    if ((iVar1 != 0) && (*(char *)(iVar1 + 0x15) != '\0')) {
      FUN_004054c0();
      local_40 = auStack_80;
      puStack_84 = &DAT_00bed1fc;
      uStack_88 = 0x602574;
      FUN_00402250();
      puStack_84 = (undefined2 *)0xaf;
      local_c = 1;
      uStack_88 = 0x602586;
      FUN_005854b0();
      uStack_88 = 0x60258d;
      uVar2 = FUN_00585330();
      local_4c = auStack_9c;
      FUN_00402250(uVar2);
      local_c = 0xffffffff;
      FUN_0058b270(0xca);
      goto LAB_00602719;
    }
  }
  local_50 = *(int *)(puVar4 + 0xc);
  iVar3 = FUN_00404c10();
  FUN_008438c0();
  if (((local_4c != *(undefined1 **)(iVar3 + 4)) && (*(int *)(local_4c + 0x10) != 0)) &&
     (iVar3 = FUN_0051bf00(), iVar3 != 0)) {
    FUN_005854b0();
    FUN_00585330();
    FUN_005854b0();
    FUN_00585330();
    uStack_74 = 0x602641;
    FUN_00404b10();
    goto LAB_00602719;
  }
  if (iVar1 == 0) {
LAB_006026c9:
    FUN_0041f490();
  }
  else {
    *(bool *)(unaff_EDI + 0x159) = 0 < *(int *)(iVar1 + 0x30);
    *(bool *)(unaff_EDI + 0x158) = *(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 0x44) >> 3 != 0;
    local_4c = *(undefined1 **)(iVar1 + 0x30);
    if (local_4c == (undefined1 *)0x0) goto LAB_006026c9;
    FUN_00585620();
    FUN_00585330();
    FUN_00483f00();
    local_c = 2;
    FUN_00402800();
    local_c = 0xffffffff;
    FUN_004fa440();
  }
  if (*(int *)(local_40 + 8) < 2) {
    if (*(int *)(local_40 + 8) == 1) {
      FUN_00602930();
    }
  }
  else {
    uStack_74 = 0x6026ff;
    FUN_005f5dd0();
  }
LAB_00602719:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_50);
  return;
}

