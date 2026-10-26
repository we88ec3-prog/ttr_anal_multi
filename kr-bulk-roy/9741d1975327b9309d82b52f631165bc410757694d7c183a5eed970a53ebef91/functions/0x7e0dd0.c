
void FUN_007e0dd0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  float *pfVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934cb4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((((*(int *)(param_1 + 0xc + *(int *)(param_1 + 8) * 4) == 0) ||
       (*(int *)(param_1 + 0xc + *(int *)(param_1 + 4) * 4) == 0)) ||
      (*(float *)(param_1 + 0x30) <= 0.0)) || (1.0 <= *(float *)(param_1 + 0x30))) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    piVar7 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    iVar8 = *(int *)(*(int *)(param_1 + 0xc + *(int *)(param_1 + 4) * 4) + 0xc);
    if (iVar8 == 0) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 2;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      DAT_00fb79a4 = 0xff000000;
      uVar4 = DAT_00fb79a4;
    }
    else {
      FUN_007d7260();
      uVar4 = *(undefined4 *)(iVar8 + 8);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 1;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
    }
    DAT_00fb79a4 = uVar4;
    piVar5 = *(int **)(*(int *)(param_1 + 0xc + *(int *)(param_1 + 4) * 4) + 4);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))();
    }
    pfVar6 = *(float **)(*(int *)(param_1 + 0xc + *(int *)(param_1 + 4) * 4) + 8);
    if (pfVar6 == (float *)0x0) {
      (**(code **)(*piVar7 + 0xe4))(piVar7,0x8b,0xff808080);
    }
    else {
      fVar1 = *pfVar6;
      if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
        if (0.0 < *pfVar6) {
          local_1c = (uint)(longlong)ROUND(*pfVar6 * 255.0 + 0.5);
          uVar11 = local_1c;
        }
        else {
          uVar11 = 0;
        }
      }
      else {
        uVar11 = 0xff;
      }
      fVar1 = pfVar6[1];
      if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
        if (0.0 < pfVar6[1]) {
          local_1c = (uint)(longlong)ROUND(pfVar6[1] * 255.0 + 0.5);
          uVar10 = local_1c;
        }
        else {
          uVar10 = 0;
        }
      }
      else {
        uVar10 = 0xff;
      }
      if (1.0 < pfVar6[2] == (pfVar6[2] == 1.0)) {
        if (0.0 < pfVar6[2]) {
          local_1c = (uint)(longlong)ROUND(pfVar6[2] * 255.0 + 0.5);
          uVar9 = local_1c;
        }
        else {
          uVar9 = 0;
        }
      }
      else {
        uVar9 = 0xff;
      }
      if (1.0 < pfVar6[3] == (pfVar6[3] == 1.0)) {
        if (0.0 < pfVar6[3]) {
          local_1c = (uint)(longlong)ROUND(pfVar6[3] * 255.0 + 0.5);
        }
        else {
          local_1c = 0;
        }
      }
      else {
        local_1c = 0xff;
      }
      (**(code **)(*piVar7 + 0xe4))
                (piVar7,0x8b,((local_1c << 8 | uVar11) << 8 | uVar10) << 8 | uVar9);
      local_14 = 0;
      uVar11 = (int)pfVar6[10] - (int)pfVar6[9] >> 2;
      if (uVar11 != 0) {
        do {
          piVar7 = *(int **)((int)pfVar6[9] + local_14 * 4);
          if (*piVar7 == 3) {
LAB_007e112b:
            if ((DAT_00fb79e8 & 1) == 0) {
              local_8 = 5;
LAB_007e1142:
              DAT_00fb79e8 = DAT_00fb79e8 | 1;
              FUN_00798de0();
              _atexit((_func_4879 *)&LAB_00bcd2e0);
              local_8 = 0xffffffff;
            }
          }
          else {
            iVar8 = piVar7[0xd];
            iVar2 = piVar7[0xe];
            iVar3 = piVar7[0xf];
            if ((DAT_00fb79e8 & 1) == 0) {
              DAT_00fb79e8 = DAT_00fb79e8 | 1;
              local_8 = 3;
              FUN_00798de0();
              _atexit((_func_4879 *)&LAB_00bcd2e0);
              local_8 = 0xffffffff;
            }
            if ((DAT_00fb76e4 != 0) &&
               (iVar8 = FUN_00838860(iVar8,iVar2,iVar3,piVar7[0x13]), iVar8 == 0))
            goto LAB_007e112b;
            if ((DAT_00fb79e8 & 1) == 0) {
              local_8 = 4;
              goto LAB_007e1142;
            }
          }
          FUN_0079b4a0(&DAT_00fb76a8);
          local_14 = local_14 + 1;
        } while (local_14 < uVar11);
      }
    }
  }
  else {
    FUN_007e15e0();
    FUN_007e11c0();
    FUN_007e16e0(param_1);
  }
  piVar7 = *(int **)(*(int *)(param_1 + 0xc + *(int *)(param_1 + 4) * 4) + 0x10);
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 8))();
  }
  ExceptionList = local_10;
  return;
}

