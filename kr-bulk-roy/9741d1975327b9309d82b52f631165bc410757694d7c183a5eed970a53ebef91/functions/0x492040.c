
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_00492040(int param_1,undefined4 param_2)

{
  LPPOINT lpPoint;
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  float10 fVar9;
  float fStack_34;
  float fStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00949756;
  local_14 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 0xc010) != 0) {
    local_1c = *(float *)(param_1 + 0xc008);
    iVar6 = *(int *)(param_1 + 0xc004);
    lpPoint = (LPPOINT)(param_1 + 0xc004);
    GetCursorPos(lpPoint);
    ScreenToClient(*(HWND *)(param_1 + 8),lpPoint);
    if ((iVar6 != lpPoint->x) || (local_1c != *(float *)(param_1 + 0xc008))) {
      *(undefined4 *)(param_1 + 0xc00c) = 1;
    }
  }
  if (*(int *)(param_1 + 0xc00c) == 0) {
LAB_00492198:
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 3;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
  }
  else {
    uVar2 = DAT_00fc1a34 & 1;
    *(undefined4 *)(param_1 + 0xc00c) = 0;
    if (uVar2 == 0) {
      DAT_00fc1a34 = DAT_00fc1a34 | 1;
      local_c = 0;
      FUN_00737210(uVar5);
      _atexit(FUN_00bce000);
      local_c = 0xffffffff;
    }
    _DAT_00fc1a40 = *(undefined4 *)(param_1 + 0xc008);
    _DAT_00fc1a3c = *(undefined4 *)(param_1 + 0xc004);
    if ((DAT_00fb131c & 1) == 0) {
      DAT_00fb131c = DAT_00fb131c | 1;
      local_c = 1;
      FUN_00570ec0();
      _atexit((_func_4879 *)&LAB_00bccf50);
      local_c = 0xffffffff;
    }
    if (DAT_00fb132c != (int *)0x0) {
      (**(code **)(*DAT_00fb132c + 0x24))
                (*(undefined4 *)(param_1 + 0xc004),*(undefined4 *)(param_1 + 0xc008),0);
    }
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 2;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
      goto LAB_00492198;
    }
  }
  iVar6 = DAT_00fab1e4;
  DAT_00fab1e4 = 0;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 4;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  iVar3 = DAT_00f95cd0;
  if (DAT_00f95cd0 != 0) {
    if ((DAT_00fc1a34 & 1) == 0) {
      DAT_00fc1a34 = DAT_00fc1a34 | 1;
      local_c = 5;
      FUN_00737210(uVar5);
      _atexit(FUN_00bce000);
      local_c = 0xffffffff;
    }
    FUN_00737a30(iVar3);
    goto LAB_0049235a;
  }
  if (DAT_00fba7a4[0x1f] == 0) {
    if ((iVar6 != 0) && (iVar6 = FUN_00422f40(), *(int *)(iVar6 + 0x28) == 0)) {
      uVar8 = 0x66;
      FUN_0048a240(0x66);
      FUN_00737a30(uVar8);
      goto LAB_0049235a;
    }
    fStack_30 = 0.0;
    iVar6 = FUN_0048a240();
    if (*(int *)(iVar6 + 0x1c) == 0) goto LAB_0049235a;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    *(undefined4 *)(iVar6 + 0x24) = 1;
    FUN_008438c0(&fStack_30);
    if (fStack_34 == *(float *)(iVar6 + 0x10)) {
      *(undefined4 *)(iVar6 + 0x24) = 0;
      *(undefined4 *)(iVar6 + 0x20) = 0;
    }
    else {
      *(undefined4 *)(iVar6 + 0x20) = *(undefined4 *)((int)fStack_34 + 0x10);
    }
  }
  else {
    if ((DAT_00fc1a34 & 1) == 0) {
      DAT_00fc1a34 = DAT_00fc1a34 | 1;
      local_c = 6;
      FUN_00737210(uVar5);
      _atexit(FUN_00bce000);
      local_c = 0xffffffff;
    }
    fStack_34 = 1.4013e-43;
    if (DAT_00fc1a54 == 100) goto LAB_0049235a;
    DAT_00fc1a54 = 100;
    _DAT_00fc1a5c = 1;
    FUN_008438c0(&fStack_34);
    if (fStack_30 == DAT_00fc1a48) {
      _DAT_00fc1a5c = 0;
      _DAT_00fc1a58 = 0;
    }
    else {
      _DAT_00fc1a58 = *(undefined4 *)((int)fStack_30 + 0x10);
    }
  }
  FUN_00737450();
LAB_0049235a:
  if ((DAT_00fc125c & 1) == 0) {
    DAT_00fc125c = DAT_00fc125c | 1;
    local_c = 7;
    FUN_007b7260();
    _atexit((_func_4879 *)&LAB_00bce650);
    local_c = 0xffffffff;
  }
  FUN_007b77c0(param_2);
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  FUN_00738160(param_2);
  if (DAT_00fbab34 == 0) {
    FUN_0054d420(&DAT_00fbaaf8);
  }
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 8;
    FUN_0054e750();
    _atexit((_func_4879 *)&LAB_00bcd260);
    local_c = 0xffffffff;
  }
  if (DAT_00fb7620 != (int *)0x0) {
    (**(code **)(*DAT_00fb7620 + 0x10))(param_2);
  }
  if ((_DAT_00fd2cf4 & 1) == 0) {
    _DAT_00fd2cf4 = _DAT_00fd2cf4 | 1;
    DAT_00fd2cf8 = CSceneManager::vftable;
    DAT_00fd8ba4 = (int *)0x0;
    FUN_004b7dc0();
    _atexit((_func_4879 *)&LAB_00bcdcf0);
  }
  if (DAT_00fd8ba4 != (int *)0x0) {
    (**(code **)(*DAT_00fd8ba4 + 0x1c))(param_2);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 9;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  FUN_00797ec0();
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 10;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  FUN_00561680(param_2);
  if ((DAT_00fd9244 & 1) == 0) {
    DAT_00fd9244 = DAT_00fd9244 | 1;
    local_c = 0xb;
    FUN_00554410();
    _atexit((_func_4879 *)&LAB_00bcdfc0);
    local_c = 0xffffffff;
  }
  FUN_005544b0(param_2);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0xc;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  FUN_00799d20(&DAT_00fb76a8,param_2);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0xd;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  uStack_2c = FUN_004e0200(&DAT_00fab130,param_2);
  if ((DAT_00fd93f0 & 1) == 0) {
    DAT_00fd93f0 = DAT_00fd93f0 | 1;
    local_c = 0xe;
    FUN_007ab4e0();
    _atexit((_func_4879 *)&LAB_00bce6a0);
    local_c = 0xffffffff;
  }
  FUN_007ac230(&DAT_00fd92a0,param_2);
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_c = 0xf;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_c = 0xffffffff;
  }
  FUN_00550f70(&DAT_00fdf680,param_2);
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  FUN_0056f130(DAT_00fdf3c4);
  if ((DAT_00fd8ea8 & 1) == 0) {
    DAT_00fd8ea8 = DAT_00fd8ea8 | 1;
    local_c = 0x10;
    FUN_0055ac10();
    _atexit((_func_4879 *)&LAB_00bcdfe0);
    local_c = 0xffffffff;
  }
  puVar4 = DAT_00fd8eb0;
  for (puVar1 = (undefined4 *)*DAT_00fd8eb0; puVar1 != puVar4; puVar1 = (undefined4 *)*puVar1) {
    FUN_0055a180(puVar1[2] + 0x3c);
  }
  uVar8 = param_2;
  FUN_0048a010(param_2);
  FUN_0041e170(uVar8);
  if ((DAT_00fba7a4[0x1f] != 0) && (iVar6 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar6 != 0)) {
    piVar7 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
    uVar8 = (**(code **)(*piVar7 + 0x4c))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0x11;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    FUN_0079a6b0(&DAT_00fb76a8,uVar8);
    fStack_30 = (float)*(int *)(param_1 + 0xc004) - fStack_20;
    fStack_34 = (float)*(int *)(param_1 + 0xc008) - local_1c;
    fStack_28 = fStack_30;
    fStack_24 = fStack_34;
    D3DXVec2Normalize(&fStack_28,&fStack_28);
    fVar9 = (float10)FUN_008fedca();
    fStack_30 = (float)fVar9 + 1.5707964;
    if ((DAT_00fc1a34 & 1) == 0) {
      DAT_00fc1a34 = DAT_00fc1a34 | 1;
      local_c = 0x12;
      FUN_00737210();
      _atexit(FUN_00bce000);
      local_c = 0xffffffff;
    }
    _DAT_00fc1a68 = fStack_30;
  }
  if ((DAT_00fc1bf4 & 1) == 0) {
    DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
    local_c = 0x13;
    FUN_0057ef90();
    _atexit((_func_4879 *)&LAB_00bcdfb0);
    local_c = 0xffffffff;
  }
  FUN_0057fa40(&DAT_00fc1bf8,param_2);
  if ((DAT_00fb131c & 1) == 0) {
    DAT_00fb131c = DAT_00fb131c | 1;
    local_c = 0x14;
    FUN_00570ec0();
    _atexit((_func_4879 *)&LAB_00bccf50);
    local_c = 0xffffffff;
  }
  if (DAT_00fb132c != (int *)0x0) {
    (**(code **)(*DAT_00fb132c + 0x18))(param_2);
  }
  if ((_DAT_00fd9274 & 1) == 0) {
    _DAT_00fd9274 = _DAT_00fd9274 | 1;
    DAT_00fd9278 = 0;
    _DAT_00fd927c = 0;
    _DAT_00fd9280 = 0;
    _atexit((_func_4879 *)&LAB_00bce2d0);
  }
  FUN_006d8480(&DAT_00fd9278,param_2);
  if (*(int *)(param_1 + 0xbfe0) != 0) {
    FUN_006dcc70(param_2);
  }
  (**(code **)(**(int **)(*(int *)(param_1 + 0xbfdc) + 0x18) + 0x1c))(param_2);
  ExceptionList = pvStack_18;
  return fStack_30;
}

