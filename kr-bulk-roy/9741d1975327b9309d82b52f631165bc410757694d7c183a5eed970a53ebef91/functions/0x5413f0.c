
void FUN_005413f0(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  int *piVar7;
  DWORD DVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939438;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DVar4 = timeGetTime();
  uVar10 = 0;
  do {
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_8 = 0;
      FUN_0079cf40(uVar3);
      _atexit((_func_4879 *)&LAB_00bcdb80);
      local_8 = 0xffffffff;
    }
    FUN_0079d570(uVar10);
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_8 = 1;
      FUN_0079cf40(uVar3);
      _atexit((_func_4879 *)&LAB_00bcdb80);
      local_8 = 0xffffffff;
    }
    cVar1 = *(char *)((int)DAT_00fc0e94[1] + 0x19);
    puVar5 = (undefined4 *)DAT_00fc0e94[1];
    local_14 = DAT_00fc0e94;
    while (puVar9 = puVar5, cVar1 == '\0') {
      if ((uint)puVar9[3] < uVar10) {
        puVar5 = (undefined4 *)puVar9[2];
        puVar9 = local_14;
      }
      else {
        puVar5 = (undefined4 *)*puVar9;
      }
      cVar1 = *(char *)((int)puVar5 + 0x19);
      local_14 = puVar9;
    }
    if ((local_14 == DAT_00fc0e94) || (uVar10 < (uint)local_14[3])) {
      local_18 = DAT_00fc0e94;
      ppuVar6 = &local_18;
    }
    else {
      ppuVar6 = &local_14;
    }
    if ((*ppuVar6 != DAT_00fc0e94) && (iVar2 = *(int *)((*ppuVar6)[4] + 0x54), iVar2 != 0)) {
      piVar7 = (int *)(iVar2 + 0x3c);
      if (0xf < *(uint *)(iVar2 + 0x50)) {
        piVar7 = (int *)*piVar7;
      }
      FID_conflict__wprintf("(%s)ADDREF: %d\n",piVar7,*(int *)(iVar2 + 0x5c) + 1);
      *(int *)(iVar2 + 0x5c) = *(int *)(iVar2 + 0x5c) + 1;
    }
    uVar10 = uVar10 + 1;
  } while (uVar10 < 10);
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8 = 2;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    local_8 = 0xffffffff;
  }
  FUN_0079d570(0x65);
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8 = 3;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
  }
  cVar1 = *(char *)((int)DAT_00fc0e94[1] + 0x19);
  puVar5 = (undefined4 *)DAT_00fc0e94[1];
  local_18 = DAT_00fc0e94;
  while (puVar9 = puVar5, cVar1 == '\0') {
    if ((uint)puVar9[3] < 0x65) {
      puVar5 = (undefined4 *)puVar9[2];
      puVar9 = local_18;
    }
    else {
      puVar5 = (undefined4 *)*puVar9;
    }
    cVar1 = *(char *)((int)puVar5 + 0x19);
    local_18 = puVar9;
  }
  if ((local_18 == DAT_00fc0e94) || (0x65 < (uint)local_18[3])) {
    local_14 = DAT_00fc0e94;
    ppuVar6 = &local_14;
  }
  else {
    ppuVar6 = &local_18;
  }
  if ((*ppuVar6 != DAT_00fc0e94) && (iVar2 = *(int *)((*ppuVar6)[4] + 0x54), iVar2 != 0)) {
    piVar7 = (int *)(iVar2 + 0x3c);
    if (0xf < *(uint *)(iVar2 + 0x50)) {
      piVar7 = (int *)*piVar7;
    }
    FID_conflict__wprintf("(%s)ADDREF: %d\n",piVar7,*(int *)(iVar2 + 0x5c) + 1);
    *(int *)(iVar2 + 0x5c) = *(int *)(iVar2 + 0x5c) + 1;
  }
  DVar8 = timeGetTime();
  FUN_00893164("LoadAllAvatarBase: Time %d\n",DVar8 - DVar4);
  ExceptionList = local_10;
  return;
}

