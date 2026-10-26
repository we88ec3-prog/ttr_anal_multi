
void FUN_0079b060(int *param_1)

{
  int *piVar1;
  void *_Dst;
  void *_Src;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  float10 fVar8;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float fStack_110;
  uint local_10c;
  double local_108;
  undefined4 local_100;
  int *local_f8;
  float local_f4;
  undefined8 local_f0;
  float local_e8;
  int local_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined4 uStack_b8;
  undefined4 local_b4 [4];
  undefined4 local_a4;
  undefined4 local_94;
  float local_80 [5];
  float local_6c;
  float local_60;
  float local_3c [12];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_124;
  local_3c[0] = 0.0;
  local_3c[1] = 0.0;
  local_3c[2] = 0.0;
  local_3c[3] = 1.0;
  local_3c[7] = 1.0;
  local_3c[0xb] = 1.0;
  local_3c[4] = 0.0;
  local_3c[5] = 0.0;
  local_f8 = param_1;
  local_3c[6] = 0.0;
  pfVar4 = (float *)(*param_1 + 0x98);
  pfVar6 = local_80;
  for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar6 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar6 = pfVar6 + 1;
  }
  local_3c[8] = 0.0;
  local_3c[9] = 0.0;
  local_3c[10] = 0.0;
  _memset(local_b4,0,0x34);
  local_94 = 0x3f800000;
  local_a4 = 0x3f800000;
  local_b4[0] = 0x3f800000;
  FUN_00790b40();
  FUN_00780890();
  local_f0 = (double)CONCAT44(-local_6c,-local_80[2]);
  local_e8 = -local_60;
  FUN_00780b80(&local_f4);
  local_108 = (double)(local_f4 * 0.5);
  fVar8 = (float10)FUN_008ff0a0();
  local_124 = (float)((float10)0.0 * fVar8);
  local_3c[6] = (float)fVar8;
  local_3c[4] = local_124;
  local_3c[5] = local_124;
  fVar8 = (float10)FUN_008fef70();
  local_3c[7] = (float)fVar8;
  local_108 = 0.0;
  local_100 = 0x3f800000;
  FUN_00780610();
  local_124 = 0.0;
  do {
    iVar5 = (int)local_124 * 0x10;
    uVar7 = param_1[(int)local_124 * 4 + 0x34] - param_1[(int)local_124 * 4 + 0x33] >> 2;
    local_10c = 0;
    local_dc = iVar5;
    local_108._0_4_ = (undefined4 *)uVar7;
    if (uVar7 != 0) {
      do {
        piVar1 = *(int **)(*(int *)(iVar5 + 0xcc + (int)param_1) + local_10c * 4);
        local_120 = *(float *)((int)local_3c + iVar5);
        local_11c = *(float *)((int)local_3c + iVar5 + 4);
        local_118 = *(float *)((int)local_3c + iVar5 + 8);
        local_114 = *(float *)((int)local_3c + iVar5 + 0xc);
        iVar2 = (**(code **)(*piVar1 + 0x60))();
        if (iVar2 != 0) {
          if (local_124 == 0.0) {
            piVar3 = (int *)(**(code **)(*piVar1 + 0x3c))();
            iVar2 = (**(code **)(*piVar3 + 0x24))(local_b4);
            fStack_c4 = -*(float *)(iVar2 + 0xc);
            fStack_c0 = -*(float *)(iVar2 + 0x10);
            fStack_bc = -*(float *)(iVar2 + 0x14);
            uStack_b8 = *(undefined4 *)(iVar2 + 0x18);
            pfVar4 = (float *)FUN_0077e880(&local_120);
            if (&local_120 != pfVar4) {
              local_114 = pfVar4[3];
              local_120 = *pfVar4;
              local_11c = pfVar4[1];
              local_118 = pfVar4[2];
            }
          }
          else if (local_124 == 1.4013e-45) {
            piVar3 = (int *)(**(code **)(*piVar1 + 0x3c))();
            iVar5 = (**(code **)(*piVar3 + 0x24))(local_80);
            fStack_d4 = -*(float *)(iVar5 + 0xc);
            fStack_d0 = -*(float *)(iVar5 + 0x10);
            fStack_cc = -*(float *)(iVar5 + 0x14);
            uStack_c8 = *(undefined4 *)(iVar5 + 0x18);
            FUN_00780b80(&fStack_d8);
            fStack_110 = local_f4 - fStack_d8;
            local_f0 = (double)(fStack_110 * 0.5);
            fVar8 = (float10)FUN_008ff0a0();
            local_120 = (float)((float10)0.0 * fVar8);
            local_118 = (float)fVar8;
            local_11c = local_120;
            fStack_110 = local_120;
            fVar8 = (float10)FUN_008fef70();
            local_114 = (float)fVar8;
            iVar5 = local_dc;
            uVar7 = (uint)local_108._0_4_;
          }
        }
        pfVar4 = (float *)(piVar1 + 0x1d);
        if ((((local_114 != (float)piVar1[0x20]) || (local_120 != *pfVar4)) ||
            (local_11c != (float)piVar1[0x1e])) || (local_118 != (float)piVar1[0x1f])) {
          if (pfVar4 == &local_120) {
            piVar1[0x30] = 0;
          }
          else {
            piVar1[0x20] = (int)local_114;
            *pfVar4 = local_120;
            piVar1[0x1e] = (int)local_11c;
            piVar1[0x1f] = (int)local_118;
            piVar1[0x30] = 0;
          }
        }
        FUN_00780150(piVar1,piVar1[0xc]);
        local_10c = local_10c + 1;
        param_1 = local_f8;
      } while (local_10c < uVar7);
    }
    _Dst = *(void **)(iVar5 + 0xcc + (int)param_1);
    _Src = *(void **)(iVar5 + 0xd0 + (int)param_1);
    local_108 = (double)CONCAT44(local_108._4_4_,iVar5 + 0xd0 + (int)param_1);
    if (_Dst != _Src) {
      FID_conflict__memcpy(_Dst,_Src,0);
      *local_108._0_4_ = _Dst;
    }
    local_124 = (float)((int)local_124 + 1);
  } while ((uint)local_124 < 3);
  __security_check_cookie(local_c ^ (uint)&local_124);
  return;
}

