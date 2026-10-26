
void FUN_005582d0(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  int *piVar6;
  float10 fVar7;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a37e;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1[9] < 1) {
    param_1[9] = 0;
    if (param_1[7] != 0) {
      piVar2 = (int *)FUN_00542210(local_18);
      if ((int *)*piVar2 == (int *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)*piVar2;
      }
      uVar3 = (uint)piVar2[2] >> 2;
      if (*(uint *)(iVar4 + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(iVar4 + 8);
      }
      uVar1 = *(undefined4 *)(*(int *)(*(int *)(iVar4 + 4) + uVar3 * 4) + (piVar2[2] & 3U) * 4);
      if (param_1[7] != 0) {
        param_1[6] = param_1[6] + 1;
        if ((uint)(param_1[5] * 4) <= (uint)param_1[6]) {
          param_1[6] = 0;
        }
        iVar4 = param_1[7] + -1;
        param_1[7] = iVar4;
        if (iVar4 == 0) {
          param_1[6] = 0;
        }
      }
      FUN_00558200(uVar1);
    }
  }
  else {
    param_1[9] = param_1[9] + -1;
  }
  iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar4 != 0) {
    local_24 = *(undefined4 *)(iVar4 + 0xa0);
    local_20 = *(undefined4 *)(iVar4 + 0xa4);
    local_1c = *(float *)(iVar4 + 0xa8);
    if ((*(int *)(iVar4 + 0x15c) == 0) || (*(int *)(iVar4 + 0x370) == 0)) {
      local_28 = 0.0;
    }
    else {
      fVar7 = (float10)FUN_007a7100();
      local_28 = (float)fVar7;
    }
    local_1c = local_28 + 0.5 + local_1c;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    pfVar5 = (float *)FUN_0079a6b0(&DAT_00fb76a8,&local_24);
    local_28 = pfVar5[1];
    local_2c = *pfVar5 - 12.0;
  }
  piVar2 = *(int **)*param_1;
  if (piVar2 != (int *)*param_1) {
    do {
      iVar4 = piVar2[2];
      *(float *)(iVar4 + 4) = local_2c;
      *(float *)(iVar4 + 8) = local_28;
      iVar4 = piVar2[2];
      *(float *)(iVar4 + 0xc) = *(float *)(iVar4 + 0xc) + *(float *)(iVar4 + 0x14);
      *(float *)(iVar4 + 0x10) = *(float *)(iVar4 + 0x10) + *(float *)(iVar4 + 0x18);
      *(float *)(iVar4 + 0x14) = *(float *)(iVar4 + 0x1c) + *(float *)(iVar4 + 0x14);
      *(float *)(iVar4 + 0x18) = *(float *)(iVar4 + 0x20) + *(float *)(iVar4 + 0x18);
      if (*(int *)(iVar4 + 0x28) < *(int *)(iVar4 + 0x24)) {
        *(int *)(iVar4 + 0x28) = *(int *)(iVar4 + 0x28) + 1;
      }
      piVar6 = (int *)piVar2[2];
      if (piVar6[9] == piVar6[10] || piVar6[9] - piVar6[10] < 0) {
        if (piVar6 != (int *)0x0) {
          if ((int *)*piVar6 != (int *)0x0) {
            (**(code **)(*(int *)*piVar6 + 8))();
            *piVar6 = 0;
          }
          FUN_0089120c(piVar6);
        }
        piVar6 = (int *)*piVar2;
        if (piVar2 != (int *)*param_1) {
          *(int **)piVar2[1] = piVar6;
          *(int *)(*piVar2 + 4) = piVar2[1];
          FUN_0089120c(piVar2);
          param_1[1] = param_1[1] + -1;
        }
      }
      else {
        piVar6 = (int *)*piVar2;
      }
      piVar2 = piVar6;
    } while (piVar6 != (int *)*param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

