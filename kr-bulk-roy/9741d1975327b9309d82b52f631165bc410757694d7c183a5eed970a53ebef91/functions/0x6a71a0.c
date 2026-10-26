
void FUN_006a71a0(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int unaff_EDI;
  undefined1 auStack_58 [4];
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  uint uStack_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c3f8;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)auStack_58);
  ExceptionList = &local_14;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 0;
    FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xffffffa0);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c = 0xffffffff;
  FUN_004f7370(DAT_00fc0bdc);
  FUN_00759ac0(0);
  FUN_007597b0(0);
  (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
  iVar1 = DAT_00fc0be0;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 2;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
  }
  FUN_004f6a30(iVar1);
  FUN_00759ac0(0);
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 200))();
  FUN_007598b0(0);
  iVar1 = DAT_00fc0c40 - (int)DAT_00fc0c3c >> 0x1f;
  iVar4 = (DAT_00fc0c40 - (int)DAT_00fc0c3c) / 0xc + iVar1;
  uVar3 = 0;
  piVar5 = DAT_00fc0c3c;
  if (iVar4 != iVar1) {
    do {
      if (*piVar5 == DAT_00fc0be8) break;
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 3;
    } while (uVar3 < (uint)(iVar4 - iVar1));
  }
  FUN_007598b0(1);
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  FUN_00412df0();
  local_c = 3;
  FUN_00759ac0(0);
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  iVar1 = DAT_00fc0c40 - (int)DAT_00fc0c3c >> 0x1f;
  iVar4 = (DAT_00fc0c40 - (int)DAT_00fc0c3c) / 0xc + iVar1;
  uVar3 = 0;
  if (iVar4 != iVar1) {
    piVar5 = DAT_00fc0c3c;
    do {
      if (*piVar5 == DAT_00fc0be8 + 1) break;
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 3;
    } while (uVar3 < (uint)(iVar4 - iVar1));
  }
  FUN_00412df0();
  local_c = 4;
  FUN_00759ac0(1);
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(**(int **)(unaff_EDI + 0xfc) + 200))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 5;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  FUN_00412df0();
  local_c = 6;
  FUN_00759ac0(0);
  local_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  uStack_54 = uStack_54 & 0xffff0000;
  uStack_40 = 7;
  uStack_44 = 0;
  (**(code **)(**(int **)(unaff_EDI + 0x104) + 200))();
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 7;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_c = 0xffffffff;
  }
  if (2 < DAT_00fc0be8) {
    if ((DAT_00fbad10 & 1) == 0) {
      DAT_00fbad10 = DAT_00fbad10 | 1;
      local_c = 8;
      FUN_004e8010();
      _atexit((_func_4879 *)&LAB_00bcd6b0);
      local_c = 0xffffffff;
    }
    if ((DAT_00fc0bd8 != 0) && (DAT_00fc0bd4 != 0)) {
      if (*(char *)(DAT_00fc0bd4 + 0x12) != '\0') {
        uVar2 = 1;
        goto LAB_006a75af;
      }
      if ((*(byte *)(DAT_00fc0bd4 + 0x14) & 1) != 0) {
        uVar2 = 1;
        goto LAB_006a75af;
      }
    }
  }
  uVar2 = 0;
LAB_006a75af:
  (**(code **)(**(int **)(unaff_EDI + 0x10c) + 0x90))(uVar2);
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    puStack_10 = (undefined1 *)0x9;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  iVar1 = DAT_00fc0be0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    puStack_10 = (undefined1 *)0xa;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  (**(code **)(**(int **)(unaff_EDI + 0x110) + 0x90))(iVar1 == DAT_00f93930);
  ExceptionList = local_1c;
  __security_check_cookie(uStack_24 ^ (uint)&stack0xffffffa0);
  return;
}

