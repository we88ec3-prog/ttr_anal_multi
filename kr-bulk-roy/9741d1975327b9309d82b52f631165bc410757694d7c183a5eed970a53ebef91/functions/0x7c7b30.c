
void FUN_007c7b30(float *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  uint uVar8;
  float local_28 [6];
  int local_10;
  undefined1 local_c [4];
  int local_8;
  
  pfVar7 = param_1;
  iVar2 = (**(code **)((int)*param_1 + 4))();
  uVar1 = param_2;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == -0x5eed0000) {
    uVar8 = 0;
    if ((int)pfVar7[0x37] - (int)pfVar7[0x36] >> 2 != 0) {
      do {
        if (uVar8 < (uint)((int)pfVar7[0x37] - (int)pfVar7[0x36] >> 2)) {
          uVar3 = *(undefined4 *)((int)pfVar7[0x36] + uVar8 * 4);
        }
        else {
          uVar3 = 0;
        }
        FUN_007c7b30(uVar3,uVar1);
        uVar8 = uVar8 + 1;
      } while (uVar8 < (uint)((int)pfVar7[0x37] - (int)pfVar7[0x36] >> 2));
    }
    uVar8 = 0;
    iVar2 = (**(code **)((int)*pfVar7 + 0x34))();
    if (iVar2 != 0) {
      do {
        uVar3 = (**(code **)((int)*pfVar7 + 0x30))(uVar8,uVar1);
        FUN_007c7b30(uVar3);
        uVar8 = uVar8 + 1;
        uVar4 = (**(code **)((int)*pfVar7 + 0x34))();
      } while (uVar8 < uVar4);
    }
  }
  else {
    if (iVar2 == -0x5edf0000) {
      local_28[0] = 0.0;
      local_28[1] = 0.0;
      local_28[2] = 0.0;
      uVar8 = 0;
      local_28[3] = 0.0;
      local_28[4] = 0.0;
      local_10 = 0;
      local_28[5] = 0.0;
      if ((int)pfVar7[0x1f] - (int)pfVar7[0x1e] >> 2 != 0) {
        do {
          FUN_007c7b30(*(undefined4 *)((int)pfVar7[0x1e] + uVar8 * 4),uVar1);
          uVar8 = uVar8 + 1;
        } while (uVar8 < (uint)((int)pfVar7[0x1f] - (int)pfVar7[0x1e] >> 2));
      }
      uVar8 = 0;
      if ((int)pfVar7[0x23] - (int)pfVar7[0x22] >> 2 != 0) {
        do {
          FUN_007c7b30(*(undefined4 *)((int)pfVar7[0x22] + uVar8 * 4),uVar1);
          uVar8 = uVar8 + 1;
        } while (uVar8 < (uint)((int)pfVar7[0x23] - (int)pfVar7[0x22] >> 2));
      }
      pfVar5 = local_28;
      pfVar7 = pfVar7 + 0x15;
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar7 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        pfVar7 = pfVar7 + 1;
      }
      return;
    }
    if (iVar2 == -0x5edc0000) {
      param_1 = pfVar7;
      FUN_007bb350();
      pfVar7 = param_1 + 0x15;
      pfVar5 = pfVar7;
      pfVar6 = local_28;
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar6 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        pfVar6 = pfVar6 + 1;
      }
      if (((local_10 == 3) && (param_1[0x1e] != 0.0)) && (*(int *)((int)param_1[0x1e] + 0x40) != 0))
      {
        FUN_008570d0(local_c,&local_8,&param_1);
        FUN_007846a0();
        local_28[3] = *param_1;
        local_28[5] = param_1[2];
        local_28[4] = param_1[1];
        local_28[1] = param_1[1];
        local_28[0] = *param_1;
        local_28[2] = param_1[2];
        local_10 = 0;
        if (local_8 != 0) {
          param_1 = param_1 + 2;
          do {
            if (param_1[-2] < local_28[0]) {
              local_28[0] = param_1[-2];
            }
            if (param_1[-1] < local_28[1]) {
              local_28[1] = param_1[-1];
            }
            if (*param_1 < local_28[2]) {
              local_28[2] = *param_1;
            }
            if (local_28[3] < param_1[-2]) {
              local_28[3] = param_1[-2];
            }
            if (local_28[4] < param_1[-1]) {
              local_28[4] = param_1[-1];
            }
            if (local_28[5] < *param_1) {
              local_28[5] = *param_1;
            }
            param_1 = param_1 + 3;
            local_8 = local_8 + -1;
          } while (local_8 != 0);
        }
        pfVar5 = local_28;
        for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
          *pfVar7 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          pfVar7 = pfVar7 + 1;
        }
        return;
      }
    }
  }
  return;
}

