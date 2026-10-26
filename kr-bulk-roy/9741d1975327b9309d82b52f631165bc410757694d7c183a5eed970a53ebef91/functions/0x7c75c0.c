
void FUN_007c75c0(int *param_1,float *param_2,undefined4 param_3,int *param_4,int param_5,
                 int param_6)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float afStack_f4 [24];
  float afStack_94 [13];
  undefined1 auStack_60 [92];
  
  iVar1 = (**(code **)(*param_1 + 4))();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == -0x5eed0000) {
    afStack_f4[0] = 0.0;
    afStack_f4[10] = 1.4013e-45;
    afStack_f4[1] = 0.0;
    afStack_f4[2] = 0.0;
    afStack_f4[3] = 0.0;
    afStack_f4[4] = 0.0;
    afStack_f4[5] = 0.0;
    afStack_f4[6] = 1.0;
    afStack_f4[7] = 1.0;
    afStack_f4[8] = 1.0;
    afStack_f4[9] = 1.0;
    if (param_5 == 0) {
      uVar3 = FUN_0077ef30(param_3);
      FUN_0077e910(auStack_60,uVar3);
      FUN_0077ea00();
    }
    uVar7 = 0;
    if (param_1[0x37] - param_1[0x36] >> 2 != 0) {
      do {
        if (uVar7 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar3 = *(undefined4 *)(param_1[0x36] + uVar7 * 4);
        }
        else {
          uVar3 = 0;
        }
        FUN_007c75c0(uVar3,param_2,afStack_f4,param_4,0,param_6);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(param_1[0x37] - param_1[0x36] >> 2));
    }
    uVar7 = 0;
    iVar1 = (**(code **)(*param_1 + 0x34))();
    if (iVar1 != 0) {
      do {
        uVar3 = (**(code **)(*param_1 + 0x30))(uVar7,param_2,afStack_f4,param_4,0,param_6);
        FUN_007c75c0(uVar3);
        uVar7 = uVar7 + 1;
        uVar4 = (**(code **)(*param_1 + 0x34))();
      } while (uVar7 < uVar4);
    }
  }
  else {
    if (iVar1 == -0x5edf0000) {
      uVar7 = 0;
      if (param_1[0x1f] - param_1[0x1e] >> 2 != 0) {
        do {
          FUN_007c75c0(*(undefined4 *)(param_1[0x1e] + uVar7 * 4),param_2,param_3,param_4,param_5,0)
          ;
          uVar7 = uVar7 + 1;
        } while (uVar7 < (uint)(param_1[0x1f] - param_1[0x1e] >> 2));
      }
      uVar7 = 0;
      if (param_1[0x23] - param_1[0x22] >> 2 != 0) {
        do {
          FUN_007c75c0(*(undefined4 *)(param_1[0x22] + uVar7 * 4),param_2,param_3,param_4,param_5,0)
          ;
          uVar7 = uVar7 + 1;
        } while (uVar7 < (uint)(param_1[0x23] - param_1[0x22] >> 2));
      }
      iVar1 = *param_4;
      pfVar2 = (float *)(param_1 + 0x15);
      pfVar6 = afStack_f4;
      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
        *pfVar6 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar6 = pfVar6 + 1;
      }
      if (iVar1 == 0) {
        if (afStack_f4[3] <= afStack_f4[0]) {
          fStack_100 = afStack_f4[3];
        }
        else {
          fStack_100 = afStack_f4[0];
        }
        if (afStack_f4[4] <= afStack_f4[1]) {
          fStack_fc = afStack_f4[4];
        }
        else {
          fStack_fc = afStack_f4[1];
        }
        if (afStack_f4[5] <= afStack_f4[2]) {
          fStack_f8 = afStack_f4[5];
        }
        else {
          fStack_f8 = afStack_f4[2];
        }
        if (afStack_f4[3] < afStack_f4[0]) {
          afStack_f4[3] = afStack_f4[0];
        }
        if (afStack_f4[4] < afStack_f4[1]) {
          afStack_f4[4] = afStack_f4[1];
        }
        if (afStack_f4[5] < afStack_f4[2]) {
          afStack_f4[5] = afStack_f4[2];
        }
        if (*param_2 <= fStack_100) {
          fStack_100 = *param_2;
        }
        *param_2 = fStack_100;
        if (param_2[1] <= fStack_fc) {
          fStack_fc = param_2[1];
        }
        param_2[1] = fStack_fc;
        if (param_2[2] <= fStack_f8) {
          fStack_f8 = param_2[2];
        }
        param_2[2] = fStack_f8;
        if (afStack_f4[3] <= param_2[3]) {
          afStack_f4[3] = param_2[3];
        }
        param_2[3] = afStack_f4[3];
        if (afStack_f4[4] <= param_2[4]) {
          afStack_f4[4] = param_2[4];
        }
        param_2[4] = afStack_f4[4];
        if (afStack_f4[5] <= param_2[5]) {
          afStack_f4[5] = param_2[5];
        }
        param_2[5] = afStack_f4[5];
        return;
      }
      pfVar2 = afStack_f4;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_2 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        param_2 = param_2 + 1;
      }
      *param_4 = 0;
      return;
    }
    if (iVar1 == -0x5edc0000) {
      pfVar2 = (float *)(param_1 + 0x15);
      pfVar6 = afStack_f4;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar6 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar6 = pfVar6 + 1;
      }
      FUN_007cd220();
      pfVar2 = afStack_94;
      pfVar6 = afStack_f4 + 0xb;
      for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
        *pfVar6 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar6 = pfVar6 + 1;
      }
      if (param_6 != 0) {
        pfVar2 = (float *)FUN_007cd1c0(afStack_f4 + 0xb);
        afStack_f4[0] = *pfVar2;
        afStack_f4[1] = pfVar2[1];
        afStack_f4[2] = pfVar2[2];
        pfVar2 = (float *)FUN_007cd1c0(afStack_f4 + 0xb);
        afStack_f4[3] = *pfVar2;
        afStack_f4[4] = pfVar2[1];
        afStack_f4[5] = pfVar2[2];
      }
      if (*param_4 == 0) {
        if (afStack_f4[3] <= afStack_f4[0]) {
          fStack_10c = afStack_f4[3];
        }
        else {
          fStack_10c = afStack_f4[0];
        }
        if (afStack_f4[4] <= afStack_f4[1]) {
          fStack_108 = afStack_f4[4];
        }
        else {
          fStack_108 = afStack_f4[1];
        }
        if (afStack_f4[5] <= afStack_f4[2]) {
          fStack_104 = afStack_f4[5];
        }
        else {
          fStack_104 = afStack_f4[2];
        }
        if (afStack_f4[3] < afStack_f4[0]) {
          afStack_f4[3] = afStack_f4[0];
        }
        if (afStack_f4[4] < afStack_f4[1]) {
          afStack_f4[4] = afStack_f4[1];
        }
        if (afStack_f4[5] < afStack_f4[2]) {
          afStack_f4[5] = afStack_f4[2];
        }
        if (*param_2 <= fStack_10c) {
          fStack_10c = *param_2;
        }
        *param_2 = fStack_10c;
        if (param_2[1] <= fStack_108) {
          fStack_108 = param_2[1];
        }
        param_2[1] = fStack_108;
        if (param_2[2] <= fStack_104) {
          fStack_104 = param_2[2];
        }
        param_2[2] = fStack_104;
        if (afStack_f4[3] <= param_2[3]) {
          afStack_f4[3] = param_2[3];
        }
        param_2[3] = afStack_f4[3];
        if (afStack_f4[4] <= param_2[4]) {
          afStack_f4[4] = param_2[4];
        }
        param_2[4] = afStack_f4[4];
        if (afStack_f4[5] <= param_2[5]) {
          afStack_f4[5] = param_2[5];
        }
        param_2[5] = afStack_f4[5];
        return;
      }
      pfVar2 = afStack_f4;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_2 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        param_2 = param_2 + 1;
      }
      *param_4 = 0;
      return;
    }
  }
  return;
}

