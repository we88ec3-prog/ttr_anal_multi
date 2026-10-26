
undefined4 FUN_0069b060(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 in_ECX;
  int *piVar8;
  uint uVar9;
  ushort local_24;
  undefined1 local_20;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919d2e;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  cVar3 = FUN_0069adb0(in_ECX);
  if (cVar3 == '\0') {
    ExceptionList = local_10;
    return 0;
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  puVar5 = (uint *)FUN_0051d700(in_ECX);
  if (puVar5 == (uint *)0x0) {
    ExceptionList = local_10;
    return 0;
  }
  uVar4 = puVar5[2];
  if ((uVar4 - 1 < 0x2b) && (iVar6 = FUN_00520f40(), iVar6 != 0)) {
    uVar4 = *puVar5;
    local_11 = 0;
  }
  else {
    if ((uVar4 != 0x26) && (uVar4 != 0x27)) {
      ExceptionList = local_10;
      return 1;
    }
    piVar8 = (int *)puVar5[0x52];
    piVar1 = (int *)puVar5[0x53];
    if (piVar8 == piVar1) {
      ExceptionList = local_10;
      return 0;
    }
    iVar6 = FUN_006dd0e0();
    if (iVar6 == 0) {
      ExceptionList = local_10;
      return 0;
    }
    local_11 = local_20;
    for (iVar6 = (int)piVar1 - (int)piVar8 >> 2; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar2 = *piVar8;
      if (*(short *)(iVar2 + 8) == 0xd) {
        local_11 = *(undefined1 *)(iVar2 + 0xc);
      }
      else if (*(short *)(iVar2 + 8) == 0xe) {
        local_24 = *(ushort *)(iVar2 + 0xc);
      }
      piVar8 = piVar8 + 1;
    }
    uVar4 = (uint)local_24;
    uVar9 = uVar4;
    uVar7 = FUN_00474db0(uVar4);
    iVar6 = FUN_00826610(uVar7,uVar9);
    if (iVar6 != 0) {
      local_11 = 0;
    }
  }
  FUN_006dc180(uVar4,local_11,0);
  ExceptionList = local_10;
  return 1;
}

