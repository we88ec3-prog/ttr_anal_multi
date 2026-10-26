
void FUN_00675b10(int *param_1)

{
  short sVar1;
  void *_Dst;
  code *pcVar2;
  int *piVar3;
  byte bVar4;
  undefined4 *puVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  short *psVar9;
  undefined2 local_88 [8];
  undefined4 local_78;
  undefined2 *local_74;
  undefined4 *puStack_70;
  uint local_6c;
  int iStack_68;
  undefined2 local_64 [4];
  undefined4 local_5c;
  int *local_58;
  undefined **local_34 [3];
  int local_28 [3];
  int *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar6 = (int)param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00948662;
  local_10 = ExceptionList;
  if (*(int *)((int)param_1 + 0x1b4) == 0) {
    return;
  }
  ExceptionList = &local_10;
  if (*(char *)((int)param_1 + 0x1d5) == '\0') {
    *(undefined4 *)((int)param_1 + 0x17c) = 0;
  }
  else {
    *(undefined1 *)((int)param_1 + 0x1d5) = 0;
  }
  param_1 = (int *)(*(int *)((int)param_1 + 0x1b4) + 0x20);
  local_28[1] = 0;
  local_28[0] = FUN_00891268();
  if (local_28[0] == 0) {
    local_1c = (int *)0x0;
    std::exception::exception((exception *)local_34,(char **)&local_1c);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8();
  }
  *(int *)local_28[0] = local_28[0];
  *(int *)(local_28[0] + 4) = local_28[0];
  local_8 = 0;
  local_58 = local_28;
  local_5c = 0x675b9d;
  FUN_00678310();
  local_8 = 1;
  FUN_00677ed0();
  local_8 = 0xffffffff;
  FUN_0056fb00();
  iVar8 = *(int *)(iVar6 + 0x1c4);
  if (iVar8 == 0) {
    bVar4 = FUN_00538770();
  }
  else if (iVar8 == 1) {
    bVar4 = FUN_005387c0();
  }
  else {
    if (iVar8 != 2) goto LAB_00675c30;
    local_58 = (int *)0x675bf5;
    bVar4 = FUN_00538820();
  }
  *(byte *)(iVar6 + 0x1d4) = *(byte *)(iVar6 + 0x1d4) | bVar4;
LAB_00675c30:
  iVar8 = *(int *)(iVar6 + 0xf8);
  if (*(char *)(iVar8 + 0x141) != '\0') {
    FUN_006edb10();
  }
  if (*(int *)(iVar8 + 0x118) != 0) {
    iVar8 = *(int *)(iVar6 + 0xf8);
    if (*(char *)(iVar8 + 0x141) != '\0') {
      FUN_006edb10();
    }
    puVar5 = (undefined4 *)(iVar8 + 0x108);
    if (7 < *(uint *)(iVar8 + 0x11c)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 != (undefined4 *)0x0) {
      FUN_008935e3();
    }
    local_58 = (int *)0x675ca0;
    bVar4 = FUN_00538a40();
    *(byte *)(iVar6 + 0x1d4) = *(byte *)(iVar6 + 0x1d4) | bVar4;
  }
  iVar8 = *(int *)(iVar6 + 0xfc);
  if (*(char *)(iVar8 + 0x141) != '\0') {
    FUN_006edb10();
  }
  if (*(int *)(iVar8 + 0x118) != 0) {
    iVar8 = *(int *)(iVar6 + 0xfc);
    if (*(char *)(iVar8 + 0x141) != '\0') {
      FUN_006edb10();
    }
    puVar5 = (undefined4 *)(iVar8 + 0x108);
    if (7 < *(uint *)(iVar8 + 0x11c)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 != (undefined4 *)0x0) {
      FUN_008935e3();
    }
    local_58 = (int *)0x675d16;
    bVar4 = FUN_00538c50();
    *(byte *)(iVar6 + 0x1d4) = *(byte *)(iVar6 + 0x1d4) | bVar4;
  }
  iVar8 = *(int *)(iVar6 + 0xf4);
  if (*(char *)(iVar8 + 0x141) != '\0') {
    FUN_006edb10();
  }
  if (*(int *)(iVar8 + 0x118) != 0) {
    iVar8 = *(int *)(iVar6 + 0xf4);
    if (*(char *)(iVar8 + 0x141) != '\0') {
      FUN_006edb10();
    }
    local_1c = (int *)local_64;
    iStack_68 = 0xffffffff;
    puStack_70 = (undefined4 *)(iVar8 + 0x108);
    local_6c = 0;
    local_64[0] = 0;
    local_74 = (undefined2 *)0x675d88;
    FUN_004026e0();
    iStack_68 = iVar6 + 0x188;
    local_6c = (uint)param_1;
    puStack_70 = (undefined4 *)0x675d98;
    bVar4 = FUN_00538870();
    *(byte *)(iVar6 + 0x1d4) = *(byte *)(iVar6 + 0x1d4) | bVar4;
  }
  if (*(char *)(iVar6 + 0x1d4) == '\0') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 2;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    local_1c = (int *)&local_6c;
    puStack_70 = (undefined4 *)0x0;
    local_58 = (int *)0x7;
    local_5c = 0;
    local_74 = &DAT_00bed1fc;
    local_6c = local_6c & 0xffff0000;
    local_78 = 0x675e01;
    FUN_00402160();
    local_8 = 3;
    param_1 = (int *)0xdc;
    puStack_70 = (undefined4 *)0x675e14;
    iVar6 = FUN_005854b0();
    puStack_70 = &param_1;
    local_74 = (undefined2 *)0x675e24;
    FUN_005740f0();
    if (local_14 != *(int *)(iVar6 + 4)) {
      psVar9 = (short *)(local_14 + 0x10);
      if (7 < *(uint *)(local_14 + 0x24)) {
        psVar9 = *(short **)psVar9;
      }
      param_1 = (int *)local_88;
      local_74 = (undefined2 *)0x7;
      local_78 = 0;
      local_88[0] = 0;
      psVar7 = psVar9;
      do {
        sVar1 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar9,(int)psVar7 - (int)(psVar9 + 1) >> 1);
      local_8 = 0xffffffff;
      FUN_0058b270(0xca);
      ExceptionList = local_10;
      return;
    }
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0x138) + 0x28) >> 9 & 1) != 0) {
    FUN_00676040();
  }
  _Dst = *(void **)(iVar6 + 0x1a4);
  if (_Dst != *(void **)(iVar6 + 0x1a8)) {
    local_58 = (int *)0x675edb;
    FID_conflict__memcpy(_Dst,*(void **)(iVar6 + 0x1a8),0);
    *(void **)(iVar6 + 0x1a8) = _Dst;
  }
  local_1c = *(int **)(iVar6 + 0x188);
  param_1 = (int *)*local_1c;
  if (param_1 != local_1c) {
    do {
      piVar3 = param_1;
      if ((DAT_00fe1de0 & 1) == 0) {
        DAT_00fe1de0 = DAT_00fe1de0 | 1;
        local_8 = 4;
        FUN_00519060();
        _atexit(FUN_00bcef60);
        local_8 = 0xffffffff;
      }
      local_14 = piVar3[2];
      FUN_00519680();
      if ((local_18 != DAT_00fe1de8) && (local_18 != -0x10)) {
        if (*(int *)(local_18 + 0x24) != 0) {
          if ((DAT_00fab29c & 1) == 0) {
            DAT_00fab29c = DAT_00fab29c | 1;
            local_8 = 5;
            FUN_004ffe60();
            _atexit((_func_4879 *)&LAB_00bccf00);
            local_8 = 0xffffffff;
          }
          iVar8 = FUN_005000a0();
          if (iVar8 == 0) goto LAB_00675fad;
        }
        FUN_004a8680();
      }
LAB_00675fad:
      param_1 = (int *)*param_1;
    } while (param_1 != local_1c);
  }
  FUN_00675460();
  FUN_007598b0();
  (**(code **)(**(int **)(iVar6 + 0x13c) + 200))();
  ExceptionList = local_10;
  return;
}

