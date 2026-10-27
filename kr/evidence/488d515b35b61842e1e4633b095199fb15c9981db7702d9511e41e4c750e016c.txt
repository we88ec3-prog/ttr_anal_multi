
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004df510(int param_1,float param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  byte *_Src;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  bool bVar10;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009444a4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(float *)(param_1 + 0x48) == param_2) {
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_8 = 0xc;
      FUN_006d8e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcdbb0);
    }
    local_8 = 0xffffffff;
    FUN_006d9430(param_2);
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_8 = 0xd;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_8 = 0xffffffff;
    }
    FUN_006d9580(&DAT_00fc0fc8,param_2);
    ExceptionList = local_10;
    return;
  }
  uVar5 = DAT_00fb75b0 & 1;
  *(float *)(param_1 + 0x48) = param_2;
  if (uVar5 == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  local_14 = param_2;
  FUN_004f7df0();
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  local_14 = param_2;
  FUN_0047fdf0(&local_14);
  if (local_18 != DAT_00fb74e4) {
    FUN_004f6e80();
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 2;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  local_18 = param_2;
  _Src = (byte *)FUN_004f7df0();
  if (0xf < *(uint *)(_Src + 0x14)) {
    _Src = *(byte **)_Src;
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 3;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  local_18 = param_2;
  FUN_0047fdf0(&local_18);
  if (local_14 != DAT_00fb74f4) {
    FUN_004f6e80();
  }
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_8 = 4;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_8 = 0xffffffff;
  }
  FUN_00552360(&DAT_00fdf680);
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_8 = 5;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    local_8 = 0xffffffff;
  }
  FUN_006d9430(param_2);
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_8 = 6;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    local_8 = 0xffffffff;
  }
  FUN_006d9580(&DAT_00fc0fc8,param_2);
  pbVar7 = (byte *)(param_1 + 0x4c);
  pbVar9 = _Src;
  do {
    bVar1 = *pbVar7;
    bVar10 = bVar1 < *pbVar9;
    if (bVar1 != *pbVar9) {
LAB_004df771:
      iVar8 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      goto LAB_004df775;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar7[1];
    bVar10 = bVar1 < pbVar9[1];
    if (bVar1 != pbVar9[1]) goto LAB_004df771;
    pbVar7 = pbVar7 + 2;
    pbVar9 = pbVar9 + 2;
  } while (bVar1 != 0);
  iVar8 = 0;
LAB_004df775:
  if (iVar8 != 0) {
    _strcpy_s((char *)(param_1 + 0x4c),0x40,(char *)_Src);
    FUN_007c1e00(1);
  }
  if ((*(int *)(DAT_00fba838 + 0x48) - *(int *)(DAT_00fba838 + 0x44) >> 2 != 0) &&
     (piVar2 = (int *)**(int **)(DAT_00fba838 + 0x44), piVar2 != (int *)0x0)) {
    iVar8 = piVar2[2];
    iVar3 = *piVar2;
    iVar4 = piVar2[1];
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 7;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    piVar6 = DAT_00fb76e8;
    DAT_00fb76e8[3] = iVar3;
    piVar6[4] = iVar4;
    piVar6[5] = iVar8;
    piVar6[0x33] = 0;
    local_18 = (float)piVar2[5];
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 8;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    piVar6 = DAT_00fb76e8;
    uVar5 = DAT_00fb79e8 & 1;
    DAT_00fb76e8[8] = (int)local_18;
    piVar6[0x33] = 0;
    local_18 = (float)piVar2[9];
    if (uVar5 == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 9;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    piVar6 = DAT_00fb76e8;
    if (*DAT_00fb76e8 != 0) {
      *(float *)(*DAT_00fb76e8 + 0x7c) = local_18;
    }
    uVar5 = DAT_00fb79e8 & 1;
    piVar6[0xc] = (int)local_18;
    local_14 = (float)piVar2[10];
    if (uVar5 == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 10;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    piVar6 = DAT_00fb76e8;
    iVar8 = *DAT_00fb76e8;
    DAT_00fb76e8[0xd] = (int)local_14;
    piVar6[0x33] = 0;
    if (iVar8 != 0) {
      local_18 = (float)piVar6[0x2f] * (local_14 / 1.3333334);
      *(float *)(iVar8 + 0x74) = local_18;
    }
    if (DAT_00fe1bd4 == 0) {
      local_18 = (float)piVar2[3];
      iVar8 = FUN_00434740();
      iVar8 = *(int *)(iVar8 + 0x40);
      *(float *)(iVar8 + 0x18) = local_18;
      *(undefined4 *)(iVar8 + 0xcc) = 0;
      local_18 = (float)piVar2[6];
      iVar8 = FUN_00434740();
      iVar8 = *(int *)(iVar8 + 0x40);
      *(float *)(iVar8 + 0x24) = local_18;
      *(undefined4 *)(iVar8 + 0xcc) = 0;
      DAT_00fe1bd4 = 1;
    }
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0xb;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  FUN_004f7df0();
  FUN_004df1a0(param_1);
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  FUN_0056cd10();
  ExceptionList = local_10;
  return;
}

