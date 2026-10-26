
uint FUN_007caec0(undefined4 *param_1,int *param_2,undefined4 *param_3,float *param_4,
                 undefined4 param_5,int param_6)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int aiStack_114 [6];
  undefined4 uStack_fc;
  undefined4 auStack_f8 [4];
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  int iStack_e0;
  undefined4 auStack_dc [4];
  undefined4 uStack_cc;
  float *pfStack_c8;
  int iStack_c4;
  undefined4 *puStack_c0;
  uint uStack_bc;
  float *pfStack_b8;
  float *pfStack_b4;
  undefined4 uStack_b0;
  undefined4 *puStack_ac;
  uint uStack_9c;
  uint uStack_98;
  float fStack_94;
  uint uStack_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float afStack_60 [23];
  
  uVar6 = 0;
  local_64 = 1;
  if (param_3 == (undefined4 *)0x0) {
    param_3 = &local_8c;
  }
  local_68 = 0x3f800000;
  local_6c = 0x3f800000;
  local_70 = 0x3f800000;
  local_74 = 0x3f800000;
  local_78 = 0;
  local_7c = 0;
  local_80 = 0;
  local_84 = 0;
  local_88 = 0;
  local_8c = 0;
  puStack_ac = (undefined4 *)0x7caf4c;
  iVar2 = (**(code **)(*param_2 + 4))();
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == -0x5eed0000) {
    uStack_b0 = 0x7cb181;
    puStack_ac = param_3;
    uStack_b0 = FUN_0077ef30();
    pfStack_b4 = afStack_60;
    pfStack_b8 = (float *)0x7cb18c;
    FUN_0077e910();
    iVar2 = param_2[0x37] - param_2[0x36] >> 2;
    fStack_94 = 0.0;
    if (0 < iVar2) {
      do {
        if ((uint)fStack_94 < (uint)(param_2[0x37] - param_2[0x36] >> 2)) {
          uStack_bc = *(undefined4 *)(param_2[0x36] + (int)fStack_94 * 4);
        }
        else {
          uStack_bc = 0;
        }
        puStack_ac = (undefined4 *)param_6;
        uStack_b0 = param_5;
        pfStack_b4 = param_4;
        pfStack_b8 = afStack_60;
        puStack_c0 = param_1;
        iStack_c4 = 0x7cb1f2;
        uVar3 = FUN_007caec0();
        if (uVar6 < uVar3) {
          uVar6 = uVar3;
        }
        fStack_94 = (float)((int)fStack_94 + 1);
      } while ((int)fStack_94 < iVar2);
    }
    puStack_ac = (undefined4 *)0x7cb211;
    uStack_90 = (**(code **)(*param_2 + 0x34))();
    uVar3 = 0;
    if (uStack_90 != 0) {
      do {
        puStack_ac = (undefined4 *)param_6;
        uStack_b0 = param_5;
        pfStack_b4 = param_4;
        pfStack_b8 = afStack_60;
        puStack_c0 = (undefined4 *)0x7cb23e;
        uStack_bc = uVar3;
        uStack_bc = (**(code **)(*param_2 + 0x30))();
        puStack_c0 = param_1;
        iStack_c4 = 0x7cb248;
        uVar4 = FUN_007caec0();
        if (uVar6 < uVar4) {
          uVar6 = uVar4;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uStack_90);
    }
    return uVar6;
  }
  if (iVar2 == -0x5edf0000) {
    fStack_94 = 65535.0;
    uStack_9c = 0;
    uStack_90 = param_2[0x1f] - param_2[0x1e] >> 2;
    uStack_98 = 0;
    if (uStack_90 != 0) {
      do {
        uStack_bc = *(undefined4 *)(param_2[0x1e] + uStack_98 * 4);
        puStack_ac = (undefined4 *)param_6;
        uStack_b0 = param_5;
        pfStack_b4 = param_4;
        puStack_c0 = param_1;
        iStack_c4 = 0x7cb054;
        pfStack_b8 = (float *)param_3;
        uVar6 = FUN_007caec0();
        if (uStack_9c < uVar6) {
          uStack_9c = uVar6;
        }
        uStack_98 = uStack_98 + 1;
      } while (uStack_98 < uStack_90);
    }
    uStack_98 = 0;
    if (param_2[0x23] - param_2[0x22] >> 2 != 0) {
      do {
        uStack_bc = *(undefined4 *)(param_2[0x22] + uStack_98 * 4);
        puStack_ac = (undefined4 *)param_6;
        uStack_b0 = param_5;
        pfStack_b4 = param_4;
        puStack_c0 = param_1;
        iStack_c4 = 0x7cb0b1;
        pfStack_b8 = (float *)param_3;
        uVar6 = FUN_007caec0();
        if (uStack_9c < uVar6) {
          uStack_9c = uVar6;
        }
        uStack_98 = uStack_98 + 1;
      } while (uStack_98 < (uint)(param_2[0x23] - param_2[0x22] >> 2));
    }
    puStack_c0 = (undefined4 *)*param_1;
    uStack_bc = param_1[1];
    pfStack_b8 = (float *)param_1[2];
    pfStack_b4 = (float *)param_1[3];
    uStack_b0 = param_1[4];
    puStack_ac = (undefined4 *)param_1[5];
    iStack_c4 = param_6;
    pfStack_c8 = &fStack_94;
    uStack_cc = param_5;
    puVar7 = auStack_f8;
    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *param_3;
      param_3 = param_3 + 1;
      puVar7 = puVar7 + 1;
    }
    piVar5 = param_2 + 0x15;
    piVar8 = aiStack_114;
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar8 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar8 = piVar8 + 1;
    }
    uVar6 = FUN_007c9890();
    if (uStack_9c < uVar6) {
      uStack_9c = uVar6;
    }
    if (param_6 == 0) {
      if (*param_4 <= fStack_94) {
        return uStack_9c;
      }
    }
    else if (fStack_94 <= *param_4) {
      return uStack_9c;
    }
    *param_4 = fStack_94;
    return uStack_9c;
  }
  if (iVar2 == -0x5edc0000) {
    if (param_6 == 0) {
      fVar1 = 65535.0;
    }
    else {
      fVar1 = 0.0;
    }
    iStack_e0 = param_2[0x1e];
    puStack_ac = (undefined4 *)param_6;
    uStack_b0 = param_5;
    puVar7 = auStack_dc;
    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *param_3;
      param_3 = param_3 + 1;
      puVar7 = puVar7 + 1;
    }
    auStack_f8[0] = *param_1;
    auStack_f8[1] = param_1[1];
    auStack_f8[2] = param_1[2];
    auStack_f8[3] = param_1[3];
    uStack_e8 = param_1[4];
    uStack_e4 = param_1[5];
    uStack_fc = 0x7cafd5;
    uVar6 = FUN_007c8460();
    if (param_6 == 0) {
      if (*param_4 <= fVar1) {
        return uVar6;
      }
    }
    else if (fVar1 <= *param_4) {
      return uVar6;
    }
    *param_4 = fVar1;
    return uVar6;
  }
  return 0;
}

